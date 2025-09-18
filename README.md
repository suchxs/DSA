<div align="center">
  <h1> A Man can be destroyed but not defeated 🌸 </h1>
  <h3> All Files are Coded in C but have a cpp file extension, because I code in Visual Studio</h3>
  <img src="./images/iwannacry.gif" alt="fuckthissub" width="600">
</div>

# Table of Contents

## Section 1
1. **Abstract Data Type (ADT)**

2. **ADT List**
   - Differentiate a List from an ADT List.
   - List Operations: Initialize, insert, delete, member, locate, and other operations
   - Implementations of ADT List:
     1. **Array Implementation (4 versions)**
        - **Version 1**: List is a structure containing an array and variable count  
          *Note*: count represents the actual number of elements in the array  
          - If MAX is the size of the array, count <= MAX
        - **Version 2**: List is a pointer to a structure containing an array and variable count
        - **Version 3**: List is a structure containing a pointer to the 1st element of a dynamic array, and variable count
        - **Version 4**: List is a pointer to a structure containing a pointer to the 1st element of a dynamic array, and variable count
     2. **Linked List Implementation (Singly Link)**
     3. **Cursor-based Implementation**
   - Time Complexity of the List operations in different implementations: O(1), O(N), and O(N\*N)

3. **ADT Stack and Implementations**
   - What is an ADT Stack?
   - Stack Operations: Top, Pop, Push, and other utility functions such as initStack, isEmpty, and isFull
   - Implementations
     1. **Array Implementation (4 versions)**
     2. **Linked List Implementation**
     3. **Cursor-based Implementation**
   - Time Complexity: O(1) and O(N)

4. **ADT Queue and Implementations**
   - What is an ADT Queue?
   - Queue Operations: Front, Dequeue, Enqueue, and other utility functions such as initQueue, isEmpty, and isFull
   - Implementations
     1. **Linked List Implementation**
        - **Queue is a pointer to a dynamically allocated node**
        - **Queue is a structure containing front and rear pointers to dynamically allocated node/s**
     2. **Circular Array Implementation**
        - **Solution 1**: Add a counter
        - **Solution 2**: Queue is full if there are MAX-1 elements  
          *Note*: where MAX is the size of the array
   - Time Complexity: O(1) and O(N)

**Caution**: The Stack and the Queue **CANNOT be traversed**! (See definition of stack and queue)

## Section 2
- To be Added
## Section 3
- To be Added


## Credit
- [Zeus Elderfield](https://github.com/elderfieldzeus) - Most of the Resources
- [University of Waterloo](https://ece.uwaterloo.ca/~dwharder/aads/Lecture_materials/) - My Previous DSA lecture Notes and ppts
- [Stanford University Data Structures](https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1262/) - Supplemental Ppts and Notes
- [MIT Introduction to Algorithms](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/) - Really Good Additional pdfs
- University of San Carlos (Ms Christine Pena && Ms Janie Sabado) ppt and activities
---
