# Am: A Dynamic, JIT-Compiled Language for AI

Welcome to **Am** (or `.am`), a powerful, multi-paradigm programming language built from the ground up in C++. AmLang is designed to be a highly expressive and performant tool, especially for artificial intelligence and deep learning tasks. It combines the flexibility of dynamic languages with the speed of JIT-compiled native code.

This repository is currently the single source of truth for the language's syntax and features.

## ✨ Key Features

  * **Multi-Paradigm:** Write in procedural, object-oriented, or functional styles.
  * **Dynamic Typing:** Variables are dynamically typed for maximum flexibility, just like in Python.
  * **Object-Oriented:** Full support for classes, inheritance (`extends`), and `new` object instantiation.
  * **Built-in AI Framework:** First-class support for Tensors, Neural Networks (NN), CNNs, RNNs, and Attention Layers.
  * **JIT Compilation with LLVM:** Hot code paths (like loops and frequent tensor operations) are automatically compiled to native machine code at runtime for massive performance gains.
  * **Modern Concurrency:** High-level `async`/`await` syntax, manual `thread` control, and `parallel for` loops.
  * **Metaprogramming & Reflection:** Inspect and manipulate the language's own structures at runtime with `reflect` and `meta` capabilities.
  * **Modular Design:** Organize your code into reusable modules with a simple `import` system.

## 🚀 Getting Started

To get the AmLang interpreter up and running on your local machine, follow these steps.

### Prerequisites

You will need a modern C++ compiler and the following libraries:

  * **CMake** (version 3.10+)
  * **Eigen3**
  * **LLVM** (version 12.0+)

### Build Instructions

1.  **Clone the repository:**

    ```bash
    git clone https://github.com/your-username/amlang.git
    cd amlang
    ```

2.  **Create a build directory:**

    ```bash
    mkdir build && cd build
    ```

3.  **Run CMake and build the project:**

    ```bash
    cmake ..
    make
    ```

4.  **Run the interpreter:**
    The executable will be in the `build` directory. You can run an `.am` script like this:

    ```bash
    ./am_interpreter /path/to/your/script.am
    ```

-----

## 📚 Language Syntax Reference

This section provides a complete guide to the AmLang syntax.

### 1\. Basics and Variables

  * **Variable Assignment:**

      * **Syntax:** `variable_name = value`
      * **Description:** Assigns a value (number, string, etc.) to a variable.
      * **Example:**
        ```am
        learning_rate = 0.001
        model_name = "MyFirstModel"
        ```

  * **Comments:**

      * **Syntax:** `# Your comment here`
      * **Description:** Any text after a `#` is ignored by the interpreter.
      * **Example:**
        ```am
        # Define model parameters
        epochs = 100
        ```

  * **Printing to Console:**

      * **Syntax:** `print: value1 value2 ...`
      * **Description:** Prints one or more values or variables to the standard output.
      * **Example:**
        ```am
        x = 42
        print: "The answer is:" x
        ```

### 2\. Control Flow

  * **If/Else Statements:**
      * **Syntax:**
        ```am
        if variable operator value {
            ... code ...
        } else {
            ... code ...
        }
        ```
      * **Description:** Executes a block of code based on a condition. The `else` block is optional. Supported operators are `==`, `>`, `<`.
      * **Example:**
        ```am
        if accuracy > 0.95 {
            print: "Model training successful!"
        }
        ```

### 3\. Loops

  * **While Loop:**

      * **Syntax:**
        ```am
        while variable operator value {
            ... code ...
        }
        ```
      * **Description:** Repeats a block of code as long as a condition is true.
      * **Example:**
        ```am
        # Note: Direct arithmetic on variables like counter = counter + 1
        # is not yet implemented and should be done via functions.
        ```

  * **For Loop:**

      * **Syntax:** `for variable = start_value to end_value { ... }`
      * **Description:** Creates a loop with a fixed number of iterations. "Hot" loops are automatically optimized by the JIT compiler.
      * **Example:**
        ```am
        for i = 0 to 5 {
            print: "Iteration" i
        }
        ```

### 4\. Functions

  * **Function Definition:**

      * **Syntax:** `func function_name { ... }`
      * **Description:** Defines a new function.
      * **Example:**
        ```am
        func show_status {
            print: "Status: OK"
        }
        ```

  * **Function Call:**

      * **Syntax:** `function_name()`
      * **Description:** Executes a previously defined function.
      * **Example:**
        ```am
        show_status()
        ```

### 5\. Object-Oriented Programming (OOP)

  * **Class Definition:**

      * **Syntax:** `class ClassName extends ParentClassName { ... }`
      * **Description:** Defines a new class. Inheritance via `extends` is optional.
      * **Example:**
        ```am
        class Optimizer {
            func step {
                print: "Performing optimization step."
            }
        }
        ```

  * **Object Instantiation:**

      * **Syntax:** `new object_name ClassName`
      * **Description:** Creates a new instance (object) of a specified class.
      * **Example:**
        ```am
        new my_optimizer Optimizer
        ```

### 6\. Data Structures

  * **List Append:**

      * **Syntax:** `list.append list_name value`
      * **Description:** Adds a new element to the end of a list. (List creation is currently handled internally).

  * **Dictionary Set:**

      * **Syntax:** `dict.set dict_name "key" value`
      * **Description:** Sets or updates a key-value pair in a dictionary. (Dictionary creation is currently handled internally).

### 7\. AI & Deep Learning

  * **Tensor Creation:**

      * **Syntax:** `tensor tensor_name rows cols`
      * **Description:** Creates a new tensor (matrix) with the given dimensions, filled with random values.
      * **Example:** `tensor weights 784 128`

  * **Tensor Operations:**

      * **Syntax:**
        ```am
        tensor_add t1 t2 result_t
        tensor.matmul t1 t2 result_t
        ```
      * **Description:** Performs element-wise addition or matrix multiplication. These operations are JIT-compiled on hot paths.

  * **Dataset Handling:**

      * **Syntax:**
        ```am
        dataset.load var_name rows cols "path/to/data.csv"
        dataset.normalize var_name
        ```
      * **Description:** Loads data from a CSV file and optionally normalizes it.

  * **Neural Network Management:**

      * **Syntax:**
        ```am
        nn.create net_name in_size hidden_size out_size
        nn.train net_name "data.csv" in_size out_size rows epochs lr
        nn.predict net_name val1 val2 ...
        nn.save net_name "model.bin"
        nn.load net_name "model.bin"
        ```

  * **Advanced Layer Creation:**

      * **Syntax:**
        ```am
        cnn.create cnn_layer_name kernel_size builder_name
        rnn.create rnn_layer_name in_size hidden_size out_size builder_name
        attn.create attn_layer_name dim builder_name
        ```
      * **Description:** Adds specialized layers to a `NetworkBuilder` to create complex, hybrid models.

### 8\. Concurrency & Parallelism

  * **Thread Management:**

      * **Syntax:**
        ```am
        thread create thread_name function_name
        thread join thread_name
        ```
      * **Description:** Creates a new thread to run a function and waits for its completion.

  * **Async Operations:**

      * **Syntax:**
        ```am
        async task_name function_name
        await task_name
        ```
      * **Description:** Executes a task asynchronously and waits for its result without blocking.

  * **Parallel For Loop:**

      * **Syntax:** `parallel for var_name start end function_name`
      * **Description:** Executes a function for each loop iteration in parallel across multiple threads.

  * **Mutex Synchronization:**

      * **Syntax:**
        ```am
        mutex lock mutex_name
        mutex unlock mutex_name
        ```
      * **Description:** Provides a locking mechanism to prevent race conditions in multithreaded code.

### 9\. Metaprogramming & Reflection

  * **Reflection:**

      * **Syntax:**
        ```am
        reflect type object_name
        reflect methods object_name
        reflect get object_name field_name target_var
        reflect set object_name field_name source_var
        ```
      * **Description:** Inspects objects at runtime to get their type, methods, and field values.

  * **Metaprogramming:**

      * **Syntax:**
        ```am
        meta eval "string_of_code"
        meta define_method ClassName method_name "string_of_code"
        meta source function_or_class_name
        ```
      * **Description:** Allows the program to execute code from strings, dynamically add methods to classes, and inspect the source code of functions and classes.

### 10\. Module Management

  * **Importing Modules:**
      * **Syntax:** `import module_name`
      * **Description:** Loads and executes an `.am` file, making its functions and classes available.

-----

## 💡 Example Script

Here is a complete script demonstrating some of AmLang's capabilities.

```am
#
# AmLang Demo Script
#

# --- 1. Define a function to be used in a parallel loop ---
func process_item {
    # In a real scenario, 'i' would be accessible within the function context
    print: "Processing item in parallel..."
}

# --- 2. Run a parallel for loop ---
print: "Starting parallel processing..."
parallel for i 0 5 process_item
print: "Parallel processing finished."

# --- 3. Define and train a simple Neural Network ---
print: "Creating a simple XOR model..."
nn.create xor_net 2 4 1

# Assume 'xor_data.csv' exists with 4 rows:
# 0,0,0
# 0,1,1
# 1,0,1
# 1,1,0
print: "Training the model..."
nn.train xor_net "xor_data.csv" 2 1 4 5000 0.1

# --- 4. Make predictions ---
print: "Making predictions..."
print: "Prediction for (1, 0):"
nn.predict xor_net 1 0

# --- 5. Save the trained model ---
print: "Saving model..."
nn.save xor_net "xor_model.bin"
print: "Script finished."

```

## 🗺️ Roadmap

  * [ ] Full implementation of the standard library (math, string manipulation, etc.).
  * [ ] Enhanced JIT compiler with more aggressive optimizations.
  * [ ] Complete the Python integration using `pybind11`.
  * [ ] Robust error handling with `try`/`catch` blocks.
  * [ ] More comprehensive documentation and tutorials.

## 🤝 Contributing

Contributions are welcome\! Please feel free to open an issue or submit a pull request.

1.  Fork the Project
2.  Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3.  Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4.  Push to the Branch (`git push origin feature/AmazingFeature`)
5.  Open a Pull Request

## 📜 License

This project is licensed under the MIT License. See the `LICENSE` file for details.
