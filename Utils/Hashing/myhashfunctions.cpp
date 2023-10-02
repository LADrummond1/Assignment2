// Chem 274B: Software Engineering Fundamentals for
//            Molecular Sciences  
// Creator: Dr.  Tony Drummond
// Date Created: 9/01/2022
// Last revisited: 9/28/2023
//
// Chem 274B - Assignment2 - The hash_functions defined here
// will be used during Week 7 and also assignment #2.

#include "myhashfs.h"
// LIST OF FUNCTIONS AND AVAILABLE FUNCTIONALITIES:
// function: hash function h1: sums up the ascii characters in a string
// and then returns the modulo m of the sum.
// input: key is an input string
//        m is the divisor used to compute the modulo operation 
// output: returns h1(key) --> and index to a hash_table
int h1(string key, int m){
    int i, n;
    int intc;

    n = key.length();
    intc = 0;

    for(i=0; i<n; i++){     
        intc += int(key[i]);   // This returns the decimal ASCII
    }                          // code for the character in key[i]
    return (intc%m);
}

// function: hash function h2: manipulates the ascii characters in a
// string and then returns the modulo m of the sum.  
// input: key is an input string
//        m is the divisor used to compute the modulo operation 
// output: returns h2(key) --> and index to a hash_table 
int h2(string key, int m){
    int i, n;
    int intc;

    n = key.length();
    intc = 0;
    // By multiply n by 256 (=2^8) we left-shift the bits in a number 
    // 8-positions
    for(i=0; i<n; i++){     
        intc = intc * 256 + int(key[i]);  // shifts left the bits in 
                                          // int(key[i])
    }                          
    return (intc%m);
}

// function hash function h3: uses an exclusive-Or bit operator to 
// generate an integer number and then returns the mod m of the sum. 
// input: key is an input string
//        m is the divisor used to compute the modulo operation 
// output: returns h3(key) --> and index to a hash_table
int h3(string key, int m){
    int i, n;
    int intc;

    n = key.length();
    intc = int(key[0]);

    for(i=0; i<n; i++){     
        intc = intc ^ int(key[i]);   // x-OR the value in intc against
    }                                // int(key[i])
    return (intc%m);
}
