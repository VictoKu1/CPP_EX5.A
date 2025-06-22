# Binary Tree with Iterators

## Table of Contents

- [Task](#task)
  - [Required Methods](#required-methods)
  - [Details](#details)
  - [Part A Requirements](#part-a-requirements)
  - [Part B Requirements](#part-b-requirements)
  - [Academic Integrity](#academic-integrity)
- [Solution](#solution)
  - [Overview](#overview)
  - [Architecture](#architecture)
  - [Key Features](#key-features)
    - [Generic Template Design](#1-generic-template-design)
    - [Tree Construction Methods](#2-tree-construction-methods)
    - [Iterator System](#3-iterator-system)
    - [Standard Library Integration](#4-standard-library-integration)
    - [Output Operator](#5-output-operator)
  - [Implementation Details](#implementation-details)
    - [Memory Management](#memory-management)
    - [Error Handling](#error-handling)
    - [Performance Considerations](#performance-considerations)
  - [Usage Examples](#usage-examples)
    - [Basic Tree Construction](#basic-tree-construction)
    - [Traversal Examples](#traversal-examples)
    - [String Tree Example](#string-tree-example)
  - [Testing and Quality Assurance](#testing-and-quality-assurance)
  - [Build Commands](#build-commands)
  - [Technical Specifications](#technical-specifications)

---

## Task {#task}

In a previous course, you learned (or were supposed to learn) about binary trees and the three ways to traverse them: preorder, inorder, and postorder. In this assignment, the goal is to implement a binary tree with iterators that can traverse it in all three orders.

**Class name**: `BinaryTree`

**Required methods** (see [Demo.cpp](Demo.cpp) for details): {#required-methods}

* `add_root` - Takes one input and places it at the root of the tree. If there's already something at the root, it gets replaced.
* `add_left` - Takes two inputs: the first input indicates something that already exists in the tree. The second input indicates a new item to add as its left child (if it already has a left child - replace its content).
* `add_right` - Same as above, but the addition is as the right child.
* `begin_preorder()`, `end_preorder()` - Return iterators for preorder traversal (parent - left - right).
* `begin_inorder()`, `end_inorder()` - Return iterators for inorder traversal (left - parent - right).
* `begin_postorder()`, `end_postorder()` - Return iterators for postorder traversal (left - right - parent).
* Output operator - Prints the tree in a reasonable format of your choice.

**Details**: {#details}
* The tree is not necessarily sorted in ascending order, nor is it necessarily balanced. The order of data in the tree is according to how they are inserted. See the demo program.
* In the `add_left`, `add_right` functions, if the first input doesn't exist in the tree - throw an exception. If it exists twice or more - choose one of the two options and add there (in automatic tests, don't insert such cases, so the result is unambiguous).

**Part A**: Write: {#part-a-requirements}
* A header file including all required functions (without implementation). Note: The headers need to be correct according to what was learned in lectures - it's recommended to review the material before starting to write.
* Comprehensive tests for all required functions.
* The following commands must work without errors:
  ```
  make demo && ./demo
  make test && ./test
  ```

**Part B**: In addition to this:
* The commands `make tidy`, `make valgrind` must work without errors.
* Write some creative main program that demonstrates the iterators and operators you wrote.
* In the main program, demonstrate the iterators using algorithms from the standard library (learned in week 11). The algorithms are your choice - be creative.

Do not change the given files, only add new files.

Solve the assignment independently. {#academic-integrity}

* You may consult with other students or search for information on the internet;
* You may not copy entire code segments from other students or from the internet.
* You must report any help you received, from other students or from the internet, in accordance with the [Department's Academic Integrity Guidelines](https://www.ariel.ac.il/wp/cs/wp-content/uploads/sites/88/2020/08/Guidelines-for-Academic-Integrity.pdf).

## Solution {#solution}

### Overview {#overview}

This project implements a generic binary tree data structure in C++ with support for three different traversal orders using iterators. The implementation provides a flexible and efficient way to build and traverse binary trees with any data type that supports comparison operations.

### Architecture {#architecture}

The solution consists of several key components:

1. **BinaryTree Template Class**: A generic template class that can work with any data type
2. **Node Structure**: Internal node representation with left/right pointers and data
3. **Iterator System**: Three different iterator types for different traversal orders
4. **Memory Management**: Proper cleanup and memory handling
5. **Exception Handling**: Robust error handling for invalid operations

### Key Features {#key-features}

#### 1. Generic Template Design {#1-generic-template-design}
The `BinaryTree<T>` class is implemented as a template, allowing it to work with any data type:
- Integers: `BinaryTree<int>`
- Strings: `BinaryTree<string>`
- Custom objects: `BinaryTree<MyClass>`

#### 2. Tree Construction Methods {#2-tree-construction-methods}
- **`add_root(T value)`**: Sets or replaces the root node
- **`add_left(T parent, T child)`**: Adds a left child to an existing node
- **`add_right(T parent, T child)`**: Adds a right child to an existing node

All methods return a reference to the tree, enabling method chaining for convenient tree construction.

#### 3. Iterator System {#3-iterator-system}
The implementation provides three different traversal orders:

**Preorder Traversal** (Parent → Left → Right):
```cpp
for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it) {
    cout << *it << " ";
}
```

**Inorder Traversal** (Left → Parent → Right):
```cpp
for (auto it = tree.begin_inorder(); it != tree.end_inorder(); ++it) {
    cout << *it << " ";
}
```

**Postorder Traversal** (Left → Right → Parent):
```cpp
for (auto it = tree.begin_postorder(); it != tree.end_postorder(); ++it) {
    cout << *it << " ";
}
```

#### 4. Standard Library Integration {#4-standard-library-integration}
The tree supports range-based for loops using the default inorder traversal:
```cpp
for (const auto& element : tree) {
    cout << element << " ";
}
```

#### 5. Output Operator {#5-output-operator}
The tree can be printed using the standard output operator, displaying the tree structure in a readable format.

### Implementation Details {#implementation-details}

#### Memory Management {#memory-management}
- Uses dynamic memory allocation for nodes
- Implements proper destructor to prevent memory leaks
- Maintains a map for efficient node lookup by value

#### Error Handling {#error-handling}
- Throws `invalid_argument` exceptions for invalid operations
- Handles cases where parent nodes don't exist
- Provides clear error messages for debugging

#### Performance Considerations {#performance-considerations}
- O(1) average case for add operations using hash map lookup
- O(n) traversal time for all iterator types
- Efficient memory usage with minimal overhead

### Usage Examples {#usage-examples}

#### Basic Tree Construction {#basic-tree-construction}
```cpp
BinaryTree<int> tree;
tree.add_root(1)
    .add_left(1, 2)
    .add_right(1, 3)
    .add_left(2, 4)
    .add_right(2, 5);
```

#### Traversal Examples {#traversal-examples}
```cpp
// Preorder: 1 2 4 5 3
for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it) {
    cout << *it << " ";
}

// Inorder: 4 2 5 1 3
for (auto it = tree.begin_inorder(); it != tree.end_inorder(); ++it) {
    cout << *it << " ";
}

// Postorder: 4 5 2 3 1
for (auto it = tree.begin_postorder(); it != tree.end_postorder(); ++it) {
    cout << *it << " ";
}
```

#### String Tree Example {#string-tree-example}
```cpp
BinaryTree<string> stringTree;
stringTree.add_root("root")
    .add_left("root", "left")
    .add_right("root", "right");

for (const string& element : stringTree) {
    cout << element << " ";
}
```

### Testing and Quality Assurance {#testing-and-quality-assurance}

The implementation includes comprehensive testing:

1. **Unit Tests**: Individual method testing with various scenarios
2. **Integration Tests**: End-to-end functionality testing
3. **Memory Leak Detection**: Using Valgrind for memory management validation
4. **Code Quality**: Clang-tidy for static analysis and code style enforcement

### Build Commands {#build-commands}

- `make demo` - Build and run the demonstration program
- `make test` - Build and run the test suite
- `make tidy` - Run static analysis with clang-tidy
- `make valgrind` - Check for memory leaks using Valgrind
- `make clean` - Clean build artifacts

### Technical Specifications {#technical-specifications}

- **Language**: C++17/20
- **Compiler**: Clang++ with strict warning flags
- **Memory Model**: RAII with smart memory management
- **Exception Safety**: Strong exception guarantee for all operations
- **Thread Safety**: Not thread-safe (single-threaded design)

This implementation provides a robust, efficient, and user-friendly binary tree data structure that meets all the requirements while maintaining high code quality and comprehensive testing coverage. 