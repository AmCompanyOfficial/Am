#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <map>
#include <vector>
#include <stdexcept>
#include <type_traits>
#include <cstdlib>

class AmInterpreter {
private:
    std::map<std::string, int> variables;
    std::map<std::string, std::vector<std::string>> functions;
    std::map<std::string, std::string> importedModules;

public:
    // فرآیند وارد کردن کتابخانه‌ها
    void processGeneralImport(const std::string& line) {
        std::regex importRegex(R"((\w+)\.import (\w+);)");
        std::smatch match;
        if (std::regex_match(line, match, importRegex)) {
            std::string language = match[1];
            std::string moduleName = match[2];
            std::string command;

            if (language == "py") {
                command = "pip install " + moduleName;
            } else if (language == "npm") {
                command = "npm install " + moduleName;
            } else if (language == "ruby") {
                command = "gem install " + moduleName;
            } else if (language == "go") {
                command = "go get " + moduleName;
            } else if (language == "rust") {
                command = "cargo install " + moduleName;
            } else if (language == "sol") {
                command = "npm install -g " + moduleName;
            } else if (language == "mvn") {
                command = "mvn dependency:get -Dartifact=" + moduleName;
            } else if (language == "php") {
                command = "composer require " + moduleName;
            } else if (language == "cs") {
                command = "dotnet add package " + moduleName;
            } else if (language == "r") {
                command = "R -e \"install.packages('" + moduleName + "')\"";
            } else {
                std::cerr << "Unsupported language for import: " << language << std::endl;
                return;
            }

            int result = system(command.c_str());
            if (result == 0) {
                std::cout << "Library " << moduleName << " for " << language << " installed and loaded." << std::endl;
            } else {
                std::cerr << "Error installing library " << moduleName << " for " << language << std::endl;
            }
        }
    }

    // اجرای کد خارجی در زبان‌های مختلف
    void runExternalCode(const std::string& language, const std::string& code) {
        std::string command;
        if (language == "python") {
            command = "python -c \"" + code + "\"";
        } else if (language == "node") {
            command = "node -e \"" + code + "\"";
        } else if (language == "ruby") {
            command = "ruby -e \"" + code + "\"";
        } else if (language == "go") {
            command = "go run -e \"" + code + "\"";
        } else if (language == "rust") {
            command = "rustc -e \"" + code + "\"";  // اجرای کد rust
        } else if (language == "sol") {
            command = "solc --bin --abi " + code; // اجرا کردن کد Solidity
        } else if (language == "php") {
            command = "php -r \"" + code + "\"";
        } else if (language == "cs") {
            command = "dotnet script -e \"" + code + "\""; // اجرای کد C# با استفاده از dotnet
        } else if (language == "r") {
            command = "R -e \"" + code + "\"";  // اجرای کد R
        } else {
            std::cerr << "Unsupported language for external code execution: " << language << std::endl;
            return;
        }
        
        int result = system(command.c_str());
        if (result != 0) {
            std::cerr << "Error executing code in " << language << std::endl;
        }
    }

    // پردازش خط کد
    void parseLine(const std::string& line) {
        // چک کردن اینکه دستور print وجود دارد یا خیر
        if (line.find("print:") == 0) {
            execute({ "print:" , line.substr(7, line.size() - 8) });
            return;
        }

        std::istringstream stream(line);
        std::string token;
        std::vector<std::string> tokens;

        while (stream >> token) {
            tokens.push_back(token);
        }

        if (!tokens.empty()) {
            std::string language = "Am";
            if (tokens[0].find(":") != std::string::npos) {
                size_t pos = tokens[0].find(":");
                language = tokens[0].substr(0, pos);
                tokens[0] = tokens[0].substr(pos + 1);
            }

            if (language != "Am") {
                runExternalCode(language, line);
            } else {
                execute(tokens);
            }
        }
    }

    void run(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            parseLine(line);
        }
    }

    void execute(const std::vector<std::string>& tokens) {
        if (tokens[1] == "=") {
            try {
                int value = std::stoi(tokens[2]);
                variables[tokens[0]] = value;
                std::cout << "Variable " << tokens[0] << " set to " << value << std::endl;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid number format: " << tokens[2] << std::endl;
            }
        } 
        else if (tokens[0] == "print:" && tokens.size() > 1) {
            std::string message;
            for (size_t i = 1; i < tokens.size(); ++i) {
                message += tokens[i] + " ";
            }
            if (message.front() == '"' && message.back() == '"') {
                message = message.substr(1, message.length() - 2);
            }
            std::cout << message << std::endl;
        }
        else if (tokens[0] == "if") {
            std::string var = tokens[1];
            int value = std::stoi(tokens[3]);
            if (variables[var] == value) {
                std::cout << "Condition met for if statement." << std::endl;
            }
        } 
        else if (tokens[0] == "while") {
            std::string var = tokens[1];
            int limit = std::stoi(tokens[3]);
            while (variables[var] < limit) {
                std::cout << "Loop iteration, " << var << ": " << variables[var] << std::endl;
                variables[var]++;
            }
        }
        else if (tokens[0] == "for") {
            std::string var = tokens[1];
            int start = std::stoi(tokens[3]);
            int end = std::stoi(tokens[5]);
            for (variables[var] = start; variables[var] < end; variables[var]++) {
                std::cout << "Loop iteration, " << var << ": " << variables[var] << std::endl;
            }
        }
        else if (tokens[0] == "class") {
            std::string className = tokens[1];
            std::cout << "Class " << className << " defined." << std::endl;
        }
        else if (tokens[0] == "func") {
            defineFunction(tokens[1], {tokens.begin() + 2, tokens.end()});
        }
    }

    void defineFunction(const std::string& name, const std::vector<std::string>& body) {
        functions[name] = body;
        std::cout << "Function " << name << " defined." << std::endl;
    }

    void callFunction(const std::string& name) {
        if (functions.find(name) != functions.end()) {
            std::cout << "Calling function " << name << std::endl;
            for (const auto& line : functions[name]) {
                std::cout << line << std::endl;
            }
        }
    }
};

// تابع main برای اجرای برنامه
int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }
    
    AmInterpreter interpreter;
    interpreter.run(argv[1]);
    return 0;
}
