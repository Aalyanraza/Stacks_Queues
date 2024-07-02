# Stack and Queue Implementations in C++

This repository contains C++ implementations of Stack and Queue data structures using templates, along with solutions to various algorithmic problems.

![stack-vs-queue](https://github.com/Aalyanraza/Stacks_Queues/assets/114768774/b4f28a3a-ca80-4f51-9688-883eae520300)

## Stack Implementation

The Stack is implemented using a linked list:
- **Class Name:** `Stack`
- **Template Type:** Supports any data type `t`
- **Operations Supported:**
  - `isEmpty()`: Checks if the stack is empty.
  - `push(DataItem)`: Pushes an element onto the stack.
  - `pop()`: Pops and returns the top element from the stack.
  - `peek()`: Returns the top element without popping.
  - `clear()`: Clears all elements from the stack.

## Queue Implementation

The Queue is also implemented using a linked list:
- **Class Name:** `Queue`
- **Template Type:** Supports any data type `t`
- **Operations Supported:**
  - `enqueue(num)`: Adds an element to the queue.
  - `dequeue()`: Removes and returns the front element of the queue.
  - `peek()`: Returns the front element without dequeuing.
  - `is_empty()`: Checks if the queue is empty.
  - `clear()`: Clears all elements from the queue.

## Question 1: Lexicographically Maximum String

### Problem Statement

Given a string `str` and an integer `k`, find the lexicographically maximum string possible after removing `k` characters.

### Approach

- **Algorithm Used:** Stack-based approach to maintain the largest possible string.
- **Complexity:** O(length of string + k)
- **Explanation:** 
  - Traverse the string while maintaining a stack to store characters.
  - Remove characters from the stack if a larger character is encountered.
  - Ensure no leading zeroes in the resulting string.

### Example

```cpp
string largestString(string str, int k);
```
## Question 2: Smallest Positive Integer

### Problem Statement

Given a number as a string `number` and an integer `k`, find the smallest possible positive integer after removing `k` digits.

### Approach

- **Algorithm Used:** Stack-based approach to maintain the smallest possible number.
- **Complexity:** O(length of string + k)
- **Explanation:** 
  - Use a stack to build the smallest possible number:
    - Traverse the string while maintaining a stack to store digits.
    - Remove digits from the stack to ensure the smallest number is formed.
    - Ensure no leading zeroes in the resulting number.
  
### Example

```cpp
string solve(string number, int k);
```
## Question 3: Maximum Subsequence Sum

### Problem Statement

Given an array `nums` of integers and an integer `k`, find the maximum possible sum of any `k` consecutive elements in the array.

### Approach

- **Algorithm Used:** Sliding window approach with a queue to maintain the sum of `k` elements.
- **Complexity:** O(n), where n is the size of the array.
- **Explanation:** 
  - Use a sliding window of size `k` and a queue to maintain the sum of elements:
    - Initialize the queue with the sum of the first `k` elements.
    - Slide through the array and update the maximum sum accordingly.
    - Adjust the window by adding the next element and removing the previous first element of the window.

### Example

```cpp
int* maxSubsequence(int nums[], int size, int k);
```


