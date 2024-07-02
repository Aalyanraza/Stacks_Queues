# Stacks and Queues Implementation

This repository contains implementations of Stacks and Queues in C++.
![stack-vs-queue](https://github.com/Aalyanraza/Stacks_Queues/assets/114768774/d214ff25-99cf-4dfc-befe-b62968297ce6)

## Overview

This project provides basic implementations of two fundamental data structures:

- **Stack**: A Last In First Out (LIFO) data structure where elements are added and removed from the top.
  
- **Queue**: A First In First Out (FIFO) data structure where elements are added at the rear and removed from the front.

## Contents

### Stack Implementation

#### Functions

- **push(item)**: Adds `item` to the top of the stack.
  
- **pop()**: Removes and returns the top element of the stack.
  
- **top()**: Returns the top element of the stack without removing it.
  
- **isEmpty()**: Checks if the stack is empty.

### Queue Implementation

#### Functions

- **enqueue(item)**: Adds `item` to the rear of the queue.
  
- **dequeue()**: Removes and returns the front element of the queue.
  
- **front()**: Returns the front element of the queue without removing it.
  
- **rear()**: Returns the rear element of the queue without removing it.
  
- **isEmpty()**: Checks if the queue is empty.

## Getting Started

To use these implementations, clone the repository and compile the code using a C++ compiler that supports C++11 or higher.

## Usage

1. Compile the code.
2. Execute the compiled program.
3. Review the example usage to understand how to interact with stacks and queues.

## Example

```cpp
// Example usage of Stack
#include <iostream>
#include "Stack.h" // Assuming Stack.h contains the stack implementation

int main() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    while (!stack.isEmpty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    return 0;
}

// Example usage of Queue
#include <iostream>
#include "Queue.h" // Assuming Queue.h contains the queue implementation

int main() {
    Queue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    while (!queue.isEmpty()) {
        std::cout << queue.front() << " ";
        queue.dequeue();
    }
    return 0;
}
