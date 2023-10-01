// Chem 274B: Software Engineering Fundamentals for
//            Molecular Sciences 
// Creator: Dr.  Tony Drummond
// Date Created: 9/01/2022
// Last revisited: 9/20/2023
//         This file contains a C++ hash table class implementation.
//
// mydatatypes.h Contains the C++ Class declaration and defines
//               corresponding error flags.
#include "mydatatypes.h"
#include <string>

// Default constructor: sets the htable to null pointer
// this function has no inputs nor outputs
hash_table::hash_table(){   
    htable = nullptr;
} 

// Destructor: releases the memory allocated for the hash table.
// This function has no inputs nor outputs
hash_table::~hash_table(){       
        delete [] htable;        // delete the array of keys
        htable = nullptr;
}

// setup: allocates the table_size slots of memory for the hash_table
// input: table_size is the capacity of the hash_table
// output: Initialized the hash_table object with a hash_table
//         and sets other key properties of the hash_table
//         returns HTB_NO_ERR if succesffully allocated the hash_table
//         returns HTB_ERR_NO_ALLOC fail to allocate mem for hash_table
//         returns HTB_ERR_INVALID_SZ if the input table_size is invalid 
int hash_table::setup( int table_size ){
    int i;

    if (table_size > 1) {
        htable = new (nothrow) string [table_size];
        if (htable != nullptr){
            capacity = table_size;
            numkeys  = 0;
            collisions = 0;
            for (i = 0; i < table_size; i++)
                htable[i] = "";
        }
        else return (HTB_ERR_NO_ALLOC); 
                          
    }
    else return(HTB_ERR_INVALID_SZ); // Invalid hash_table size 

    return(HTB_NO_ERR);
}  

// insert_key: attempts to insert a key in the hash table, it
//             uses linear probing to resolve collisions
// input: key to insert
//        hash function used to index keys onto the hash_table
//        the hash function takes to arguments the key and k for mod k
// output: returns HTB_NO_ERR if succesffully insert a key onto the
//                  hash table
//         returns HTB_ERR_INVALID_PTR = invalid hash_table pointer
//         returns HTB_ERR_INVALID_POS if hash_function returns a
//                 position in the array that is invalid 
//         returns HTB_ERR_NOPOS_FOUND if the hash function cannot 
//                 find a position for the key (different from 
//                 overflow)
//         returns HTB_ERR_OVERFLOW if trying to add a key when the
//                 table is already full   
int hash_table::insert_key( string key, int (func)(string, int) ){
int pos, hpos, i;       // pos, hpos are positions in htable

    if (htable != nullptr){
        if (numkeys < capacity){   // check for overflow 
            i = 0;
            hpos = func(key, capacity); // linear probing h(x)+ 0
            pos  = hpos;                // for first time
            if ((pos < 0) || (pos > capacity))
                return(HTB_ERR_INVALID_POS);
            if (htable[hpos] != "")
                collisions++;
            while(i < capacity){
                if ((htable[pos] == "") ||      // slot is available
                    (htable[pos] == DELETED_STR_KEY)){
                        htable[pos] = key;
                        numkeys++;
                        return(HTB_NO_ERR); // successfully inserted key 
                    }
                else {        // Collision occured, using linear 
                    i++;      // probing to resolve the collision
                    pos = (hpos+i)%capacity; // linear probing: 
                                             // mod(h(x)+i)capacity
                }
            }                
        }
        else return(HTB_ERR_OVERFLOW);    // htable is already full
    }
    else return(HTB_ERR_INVALID_PTR); 

    return(HTB_ERR_NOPOS_FOUND);   // Could not find a place for key
}


// search_key: looks for a key in the hash_table if found it returns
//             its index (location in hash table)
// input: key to search for
//        hash function used to index keys onto the hash_table
// output: key_pos is the position of the key in the hash_table 
//         if the key is found, otherwise key_pos = SENTINEL
//         (a small negative value)
//         returns HTB_NO_ERR if succesffully found key in the table
//         returns HTB_ERR_INVALID_PTR if htable is an invalid pointer 
//         returns -5 if htable is empty
int hash_table::search_key( string key, int *key_pos, 
                            int (func)( string, int ) ){
int i;              // i is an iterator
int hpos, pos;      // hpos and pos store positions in the hash_table

    if (htable != nullptr){
        if (numkeys > 0){
            i = 0;
            hpos = func(key, capacity);
            pos  = hpos;   //linear probing h(x)+ 0 for first time
            while(i < capacity){
                if (htable[pos] == key){  // found key
                        *key_pos = pos;
                        return (HTB_NO_ERR);
                }
                else if (htable[pos] == ""){ // empty unused slot
                    *key_pos = SENTINEL;
                    return (HTB_ERR_KEY_NOT_FOUND);   // key was not found
                }
                else{
                    // Linear probing to find next possible slot
                    // for the key (mod(h(x)+i)capacity)
                    i++;                    
                    pos = (hpos+i)%capacity;                     
                }
            }                
        }
        else return (HTB_ERR_UNDERFLOW);    // htable is empty
    }
    else return (HTB_ERR_INVALID_PTR); 
    
    return(HTB_ERR_KEY_NOT_FOUND); // key was not found
}

// delete_key: attempts to delete a key from the hash table
// input: key to delete
//        hash function used to index keys onto the hash_table
// output: returns HTB_NO_ERR succesffully deleted a key 
//         returns the value returned by the search method
//         returns HTB_ERR_KEY_NOT_FOUND key to delete was not found
int hash_table::delete_key( string key, int (func)( string, int ) ){
    int pos;
    int err;

        err = hash_table::search_key(key, &pos, func);
        if (err == 0){
            if (pos >= 0){  // key was found in hash_table
                htable[pos] = DELETED_STR_KEY;
                numkeys--;
            }
            else return (HTB_ERR_KEY_NOT_FOUND); // key was not found
        }
        else return( err ); // returns error from search_key
    
    return (HTB_NO_ERR); // succesfully deleted key from hash_table
}

// num_collisions: sends back the number of collisions
// input: no inputs
// output: totcol is the number of collisions
//         returns HTB_NO_ERR if reading of collisions was successful 
//         returns -11 if the input table_size is invalid
int hash_table::num_collisions(int *totcol){
    if (htable != nullptr){
        *totcol = collisions;
    }
    else return(HTB_ERR_INVALID_PTR); 

    return (HTB_NO_ERR);  // succesfully read the number of collisions
    
}
