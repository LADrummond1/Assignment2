// Chem 274B: Software Engineering Fundamentals for
//            Molecular Sciences  
// Creator: Dr.  Tony Drummond
// Date Created: 8/20/2022
// Last revisited: 9/20/2023
//
//  mydatatypes.h contains the necessary include files and 
//             C++ Class declarations for stack, seq_array, and 
//             hash_table
//
#pragma once    // Ensures that this file is only included once
                // during compilation
#include <climits>
#include <array>
using namespace std;

// LIST OF FLAGS AND SYMBOLS:
#define SENTINEL INT_MIN    // A value used to mark deleted elements


// Data Structures: Classes, properties and methods
class seq_array          // Sequential 1D array Class declaration
{
    public:    // sequential array operations
        seq_array();            // Default constructor 
        ~seq_array();           // destructor delete array of keys
        int setup(int size);    // Setup initializer 
        int add(int k);         // adds a key to keys (in pos f_avail)
        int store(int pos, int k); // stores a key in pos, A[pos] = k
        int find(int k, int *pos);  // searches a key in the array
                                    // and returns its position
        int key(int i, int *val);   // returns the value of A[i]
        int remove(int k);      // removes a key from the array
        int update(int k, int newk); // replaces a key value 
                                     // with newk
        int copy(int *duplicate); // makes a copy of the 
                                  // array to C++ another array
        int status(char flag);   // Prints out the status of
                                 // the array
    private:
        int *keys;          // Array of nkeys keys
        int f_avail;        // f_avail first available pos in array
        int nkeys;          // number of keys in the array
        int size;           // total length of the array

};
// LIST OF ERRORS RETURNED BY SEQ_ARRAY CLASS METHODS
#define SARR_NO_ERR     0   // A seq_array method was sucessfully completed
#define SARR_ERR_INVALID_PTR -2   // Invalid seq_array pointer
#define SARR_ERR_NO_ALLOC -3   // Fail to allocate memory for seq_array
#define SARR_ERR_OVERFLOW -4   // Overflow - seq_array is full
#define SARR_ERR_UNDERFLOW -5  // Attempting to operate on empty seq_array
#define SARR_ERR_INVALID_SZ -6   // Invalid seq_array array size
#define SARR_ERR_K_NOTFOUND -7  // key was not found in the array
#define SARR_ERR_OUTBOUNDS_OP -8  // Attempt to access kth-element of  
                                  // the array and k > n-1 or k < 0
#define SARR_ERR_INVALID_SREQ -9 // Invalid status request code


class stack          // Stack Class declaration
{
    public:    
        stack();              // Default constructor 
        ~stack();             // Destructor
        int setup(int size);  // Setup and initializer
        int push(int k);      // pushes key onto the stack
        int pop(int *k);      // pops key from the stack
                              // and returns the key
        int status();         // Prints out the status of
                              // the stack
    private:
        int *stack_keys;      // stack_keys of size ssize
        int t_stack;          // top of the stack
        int ssize;            // total length of the array
};
// LIST OF ERRORS RETURNED BY STACK CLASS METHODS
#define STK_NO_ERR     0   // A stack method was sucessfully completed
#define STK_ERR_INVALID_PTR -2   // Invalid stack array pointer
#define STK_ERR_NO_ALLOC -3   // Could not allocate memory for a stack
#define STK_ERR_OVERFLOW -4   // Overflow - stack is full
#define STK_ERR_UNDERFLOW -5  // Attempting to pop from an empty stack
#define STK_ERR_INVALID_SZ -6   // Invalida stack array size

class hash_table   // Hash table Class declaration
{
    public:
        hash_table();         // Default constructor
        ~hash_table();        // Destructor
        int setup(int table_size );
        int delete_key( string key, int (func)(string, int));
        int insert_key( string key, int (func)(string, int));
        int search_key( string key, int *pos, int (func)(string, int ));
        int num_collisions(int *ncol);
    private:
        string *htable;    // hash table of size capacity
        int capacity;         // hash table capacity (m)
        int numkeys;          // number of keys in the hash table
        int collisions;      // counts the number of collisions
};
// LIST OF ERRORS RETURNED BY STACK CLASS METHODS
#define HTB_NO_ERR     0   // A stack method was sucessfully completed
#define HTB_ERR_INVALID_PTR -2   // Invalid stack array pointer
#define HTB_ERR_NO_ALLOC -3   // Could not allocate memory for a stack
#define HTB_ERR_OVERFLOW -4   // Overflow - stack is full
#define HTB_ERR_UNDERFLOW -5  // Attempting to pop from an empty stack
#define HTB_ERR_INVALID_SZ -6   // Invalida stack array size
#define HTB_ERR_INVALID_POS -7  // The position returned by the 
                                // hash_function is not valid 
#define HTB_ERR_NOPOS_FOUND -8   // No position found for the key
#define HTB_ERR_KEY_NOT_FOUND -9 // Key sought is not in the hash_table
#define DELETED_STR_KEY "DELETEDSTR" // A string value that marks 
                                     // deleted string elements 

