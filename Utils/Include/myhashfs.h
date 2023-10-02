// Chem 274B: Software Engineering Fundamentals for
//            Molecular Sciences 
// Creator: Dr.  Tony Drummond
// Date Created: 9/01/2022
// Last revisited: 9/20/2023
//
//  myhashfs.h contains the necessary include files and 
//             API declarations thatsupport our C++ hash functions

// List of External Library API Files
#pragma once    // Ensures that this file is only included once
                // during compilation

#include <string>
using namespace std;

// LIST OF FUNCTIONS AND AVAILABLE FUNCTIONALITIES:
// function: hash function h1: sums up the ascii characters in a string
// and then returns the modulo m of the sum.
// input: key is an input string
//        m is the divisor used to compute the modulo operation 
// output: returns h1(key) --> and index to a hash_table
int h1(string key, int m);

// function: hash function h2: manipulates the ascii characters in a
// string and then returns the modulo m of the sum.  
// input: key is an input string
//        m is the divisor used to compute the modulo operation 
// output: returns h2(key) --> and index to a hash_table
int h2(string key, int m);

// function hash function h3: uses an exclusive-Or bit operator to 
// generate an integer number and then returns the mod m of the sum. 
// input: key is an input string
//        m is the divisor used to compute the modulo operation 
// output: returns h3(key) --> and index to a hash_table
int h3(string key, int m);
