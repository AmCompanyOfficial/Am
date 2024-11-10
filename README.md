# Am
Am programing language

# **Am Programming Language Tutorial**

## Introduction

Am is a simple, highly functional programming language designed to be powerful and more capable than Python. It features intuitive syntax and additional capabilities to make coding faster and easier. In this tutorial, we’ll cover the basic structure of the Am language, its syntax, and how to use it for common tasks.

## Table of Contents

1. **Installation and Setup**
2. **Basic Syntax**
    - Variables
    - Data Types
    - Operators
3. **Control Flow**
    - Conditional Statements
    - Loops
4. **Functions**
5. **Classes**
6. **Working with External Languages**
7. **Examples**
8. **Conclusion**

---

## **1. Installation and Setup**

To get started with Am, follow these steps:

1. **Download and Install**  
   Download the latest version of the Am interpreter from the official repository (Link to GitHub repo).  
   
   After downloading, run the installer. The interpreter should be installed in your system.

2. **Set Up Your First File**  
   Create a new file with the `.am` extension, e.g., `test.am`.

---

## **2. Basic Syntax**

### **Variables**

In Am, variables are defined using the `=` operator. The variable name comes first, followed by the `=` symbol and the value you want to assign to it.

```am
x = 10
y = 20
```

### **Data Types**

Am supports basic data types such as integers, strings, and floats.

- **Integer**  
  An integer is a whole number:
  ```am
  num = 42
  ```

- **String**  
  Strings are enclosed in double quotes:
  ```am
  message = "Hello, Am!"
  ```

- **Float**  
  Floats represent numbers with decimal points:
  ```am
  pi = 3.14
  ```

### **Operators**

Am supports the common arithmetic operators:

- `+` for addition
- `-` for subtraction
- `*` for multiplication
- `/` for division
- `%` for modulus

Example:
```am
sum = x + y
result = sum * 2
```

---

## **3. Control Flow**

### **Conditional Statements**

Am uses `if` to execute a block of code if a condition is true.

```am
if x > y
    print: ("x is greater than y")
```

### **Loops**

#### **While Loop**

The `while` loop is used to repeatedly execute a block of code as long as a condition is true.

```am
while x < 10
    print: ("x is less than 10")
    x = x + 1
```

#### **For Loop**

The `for` loop allows you to iterate over a range of values.

```am
for i = 1 to 5
    print: (i)
```

---

## **4. Functions**

### **Defining Functions**

Functions in Am are defined using the `func` keyword.

```am
func greet(name)
    print: ("Hello, " + name)
```

### **Calling Functions**

Once a function is defined, you can call it like this:

```am
greet("Alice")
```

---

## **5. Classes**

Am supports object-oriented programming with `class` and `func` for methods.

```am
class Person
    func init(name, age)
        this.name = name
        this.age = age

    func display()
        print: ("Name: " + this.name + ", Age: " + this.age)

person = Person("John", 30)
person.display()
```

---

## **6. Working with External Languages**

Am also supports running code written in other programming languages such as Python, JavaScript, Ruby, and more. You can use the `language:` syntax to run code from another language.

```am
py: print("Hello from Python")
node: console.log("Hello from JavaScript")
```

The interpreter will detect the language and execute the code accordingly.

---

## **7. Examples**

Here are a few examples demonstrating common tasks:

### **Example 1: Simple Calculator**

```am
func add(a, b)
    return a + b

func subtract(a, b)
    return a - b

a = 10
b = 5
print: (add(a, b))  // 15
print: (subtract(a, b))  // 5
```

### **Example 2: Factorial Calculation**

```am
func factorial(n)
    if n == 0
        return 1
    else
        return n * factorial(n - 1)

result = factorial(5)
print: (result)  // 120
```

---

## **8. Conclusion**

Am is a versatile programming language that simplifies coding tasks while offering a lot of functionality. Whether you're building simple programs or handling complex logic, Am's clean syntax and powerful features will help you develop quickly and efficiently.


## **9. Use Cases of Am**
Am is a versatile language that can be used for a variety of tasks:

Web Development: Use Am to build web applications by integrating external languages like JavaScript, Ruby, or PHP.
Automation: Automate repetitive tasks using simple and readable code. Am can interact with other systems or APIs easily.
Data Analysis: Combine Am with Python or other data-processing languages to work on machine learning models, statistical analysis, and data transformation.
Game Development: With its clean syntax, Am can be used in game development to create scripts and handle logic or use it as part of a larger game engine.
Cross-Platform Applications: Build cross-platform apps that integrate with various languages and technologies.


---

### **How to Contribute**

Feel free to fork the repository and submit pull requests. We welcome contributions to improve the language and expand its features.

For bug reports, feature requests, or general feedback, please open an issue in the GitHub repository.

---

This tutorial gives you a solid foundation to start programming in Am. As you get more familiar with the language, you’ll be able to explore its more advanced features and capabilities.

Happy coding!
