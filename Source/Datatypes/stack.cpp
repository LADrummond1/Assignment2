// Chem 274B: Software Engineering Fundamentals for
//            Molecular Sciences  
// Creator: Dr.  Tony Drummond
// Date Created: 9/01/2022
// Last revisited: 9/20/2023
//    
// This file contains C++ Object-Oriented implementation of the Stack 
// Class. A Stack is Data structure with the LIFO (Last In First
// Out) policy.  This basic stack implementation currently works 
// only with keys of the C++ data type int.
// The API (include) file is mydatatypes.h

// mydatatypes.h Contains the C++ Class definitions for our
//               basic data structures and flag
#include "mydatatypes.h"
#include <iostream>

// function: stack::stack() default constructor 
//           initializes the pointer to stack_keys with NULL
//    input: no inputs
//   output: default constructor for the stack class
stack::stack(){
    stack_keys = nullptr;        // stack objects is initially
                                 // empty, the array is set to NULL
}

// function: stack::~stack() default destructor 
//           releases the memory allocated by the stack
//    input: no inputs
//   output: 0 if successfully deallocated the array
//           
stack::~stack(){
    delete [] stack_keys;   // delete the array of keys from stack
    stack_keys = nullptr;   // stack array is set back to NULL
};

// function: stack::setup 
//    input: n
//   output: - fills the stack object properties and allocates
//             the stack of size n
//           - returns: 
//             - STK_NO_ERR if successsfully allocated the array
//             - STK_ERR_NO_ALLOC = failure to allocate the stack array
// 
int stack::setup(int size){

    if (size >= 1){
        stack_keys = new (nothrow) int [size]; // Alloc stack array
        if (stack_keys != nullptr){
            t_stack = -1;             // top of stack = index 0
            ssize = size;             // Stack size is n
        }
        else return(STK_ERR_NO_ALLOC); 
    } 
    else return(STK_ERR_INVALID_SZ);   
    
    return(STK_NO_ERR);
}

// function push: attempts to push k onto the stack
//    input: an integer key k
//   output: returns error STK_ERR_INVALID_PTR = stack ptr is invalid
//           returns error STK_ERR_OVERFLOW stack is already full 
//           returns error STK_NO_ERROR = succesfully pushed key-->Stack
int stack::push(int k){

    if (stack_keys != nullptr){
        if (t_stack < ssize - 1){
            t_stack++;
            stack_keys[t_stack] = k;
        } else return(STK_ERR_OVERFLOW); 
    } 
    else return(STK_ERR_INVALID_PTR); 
    return (STK_NO_ERR);
}

// function: pop: pops top_element from the stack
//    input: No input
//   output: outputs the key from the top of stack 
//           returns error STK_ERR_INVALID_PTR = stack ptr is invalid
//           returns error STK_ERR_UNDERFLOW if array is empty
//           returns error -6 key not found in seq. array
//           returns STK_NO_ERR if successfull popped key from stack
int stack::pop(int *key){

    if (stack_keys != nullptr){
        if (t_stack == -1) 
            return (STK_ERR_UNDERFLOW);           

        *key = stack_keys[ t_stack ];
        t_stack--;                  // top_stack = top_stack - 1
    }
    else
        return(STK_ERR_INVALID_PTR); // array of keys has 
                                     // an invalid ptr 
    return (STK_NO_ERR);  // returns 0 if a key popped from the stack
}

// function status: prints the current status of the
//                  stack
//    input: no inputs
//   output: writes to standard output
//           returns error STK_ERR_INVALID_PTR = stack ptr is invalid
//           returns error -5 if stack is empty
//           returns 0 if successfully output stack information
int stack::status(){
    int i;
    
    if (stack_keys != nullptr) {
        cout<<"Stack has "<<t_stack+1<<" elements"<<endl;
        if (t_stack < 0)
            return(STK_ERR_UNDERFLOW);   // stack is empty
        
        if (t_stack > 0)
            for (i = 0; i< t_stack; i++)
                cout<<"Stack ["<<i<<"] = "<<stack_keys[i]<<endl;

        // printing top of the stack    
        cout << "Stack ["<<t_stack<<"] = "<<stack_keys[t_stack];
        cout << " <== Top of the stack"<<endl;
        } 
    else              // stack_keys has a nullpointer  
        return(STK_ERR_INVALID_PTR);      

    return(STK_NO_ERR);
}