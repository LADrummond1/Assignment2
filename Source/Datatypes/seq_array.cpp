// Chem 274B: Software Engineering Fundamentals for
//            Molecular Sciences 
// Creator: Dr.  Tony Drummond
// Date Created: 9/01/2022
// Last revisited: 9/20/2023
    
// This file contains C++ Object-Oriented implementation of the 
// Sequential_Array Class. A Sequential Array is Data structure 
// with a direct indexing policy.  This sequential array C++ 
// implementation currently works only with keys of the C++ 
// data type int.
// The API (include) file is mydatatypes.h

// mydatatypes.h Contains the C++ Class definitions for our
//               basic data structures and flag
#include "mydatatypes.h"
#include <iostream>

// function: seq_array::seq_array() default constructor 
//           initializes the pointer to keys with NULL
//    input: no inputs
//   output: default constructor for seq_array
seq_array::seq_array(){
    keys = nullptr;        // seq_array objects have no
                           // keys and the array is set to NULL
}

// function: seq_array::~seq_array() destructor 
//           deletes the array of keys
//    input: no inputs
//   output: memory is freed and keys is set to null ptr
seq_array::~seq_array(){
    delete [] keys;        // delete the array of keys
    keys = nullptr;        // seq_array is set back to NULL
}

// function: seq_array::setup 
//    input: n
//   output: Sets the Class object properties
//           if an array cannot be allocated returns the method 
//           returns SARR_ERR_INVALID_SZ if n < 1
//           returns SARR_ERR_NO_ALLOC if it fails to allocate the
//                   sequential array of keys
//           returns SARR_NO_ERR if setup was successfully completed
int seq_array::setup(int n){
    int i;
    
    if (n >= 1){
        keys = new (nothrow) int [n]; // Alloc space for n keys
        if (keys != nullptr){
            f_avail = 0;             // f_avail = index 0
            nkeys = 0;               // init nkeys = 0
            size = n;                // Arrays size is n
            for(i=0; i<size; i++)
                keys[i] = SENTINEL;  // sentinel => empty position
        }
        else return(SARR_ERR_NO_ALLOC);
    }
    else return (SARR_ERR_INVALID_SZ);  

    return(SARR_NO_ERR);
}

// function add: attempts to add a new key to a sequential array
//    input: an integer key k
//   output: returns error SARR_ERR_INVALID_PTR = array prtis invalid
//           returns error SARR_ERR_OVERFLOW if array is already full
//           returns SARR_NO_ERR is succesfully added key to the array
int seq_array::add(int k){
    int i, cont;

    if (keys != nullptr){
        if (nkeys < size){
            nkeys++;
            keys[f_avail] = k;
            i   = f_avail;
            cont = 1;
            while ((i < size) && (cont)){   // Search for the first
                if (keys[i] == SENTINEL){  // available pos in  
                    f_avail = i;           // array and update
                    cont = 0;              // f_avail
                } 
                else i++;
            }
        } else return(SARR_ERR_OVERFLOW);    
    } 
    else return(SARR_ERR_INVALID_PTR);        
    return (SARR_NO_ERR);
}

// function store: stores key the pos position of the array
//    input: an integer key k
//   output: returns error SARR_ERR_INVALID_PTR if array is invalid
//           returns error SARR_ERR_OUTBOUND_OP if pos > array.length 
//           returns SARR_NO_ERR is succesfully store key into the array
int seq_array::store(int pos, int k){
    int i, cont;

    if (keys != nullptr){
        if (pos <= size){
            if (keys[pos] == SENTINEL)  //if keys[pos] = empty, 
                nkeys++;                // k is a new key 
               
            keys[pos] = k;              // store k in pos
            if (pos == f_avail){        // update the f_avail
                i   = f_avail;    
                cont = 1;
                while ((i < size) && (cont)){ // find the first
                    if (keys[i] == SENTINEL){ // avail pos in keys 
                        f_avail = i;            
                        cont = 0;               
                    } 
                    else i++;
                }
            } 
        } else return(SARR_ERR_OUTBOUNDS_OP);
    } else return(SARR_ERR_INVALID_PTR);       

    return (SARR_NO_ERR);
}

// function: find: searches for key in the sequential array
//    input: an integer key k
//   output: if k is found, pos is the position where k is found
//          returns error SARR_ERR_INVALID_PTR if keys has invalid ptr
//          returns error SARR_ERR_UNDERFLOW if array is empty
//          returns error SARR_ERR_K_NOTFOUND key not found in seqarray
//          returns error SARR_NO_ERR if operation was successfull 
int seq_array::find(int k, int *pos){
    int i;

    *pos = -1;               // pos is init to an invalid index
    if (keys != nullptr){
        if (nkeys == 0)      // Array is empty
            return (SARR_ERR_UNDERFLOW);            

        i = 0;
        while ((keys[i] != k ) && (i < size)){
            i++;
        }

        if (i >= size)            
            return(SARR_ERR_K_NOTFOUND);
    }
    else
        return(SARR_ERR_INVALID_PTR);                  

    *pos = i;    // output the position where key was found
    return (SARR_NO_ERR);  // found key in array
}

// function: key: returns the value of A[pos]
//    input: pos is the subindex in the array A
//   output: k = A[pos], if an error occurs it return
//           k = SENTINEL
//          returns error SARR_ERR_INVALID_PTR if keys has invalid ptr
//          returns error SARR_ERR_OUTBOUNDS_OP Invalid array[pos]
//          returns error SARR_NO_ERR if operation was successfull 
int seq_array::key(int pos, int *k){

    *k = SENTINEL;            // in case of errors return SENTINEL
    if (keys != nullptr){           
        if (pos >= size)      // detect invalid position in the array
            return(SARR_ERR_OUTBOUNDS_OP);
        
        *k = keys[pos]; 
    }
    else return(SARR_ERR_INVALID_PTR);    
                             
    return (SARR_NO_ERR);  
}


// function: remove: attempts to delete a key from a sequential array
//                if the key is found the array position is filled
//                with a SENTINEL (cannot be physically removed)
//    input: an integer key k to be deleted from array
//   output: if found, the seq_array is updated to reflect the key del
//           returns error SARR_ERR_K_NOTFOUND key not found 
//           returns SARR_NO_ERR if successfully deleted the key
int seq_array::remove(int k){
    int i, err;
    
    err = find( k, &i );
    if (i >= 0){    // Key to be deleted was found 
        keys[i] = SENTINEL;
        nkeys--;    // update the counter of keys in the array
        if (i < f_avail) 
            f_avail = i;
    } else 
        return(SARR_ERR_K_NOTFOUND); 

    return (SARR_NO_ERR); // successfully deleted key from seq_array
}

// function: update: attempts to modify a key from a seq_array
//                   if the key is found the array position 
//                   is filled with the new key value
//    input: an integer value key k to be modified
//           an integer new value to be added to seq_array
//   output: if key is found, replaces new key in seq_array
//           returns error SARR_ERR_K_NOTFOUND key not found 
//           returns SARR_NO_ERR if successfully updated the key
int seq_array::update(int k, int newk){
    int i, err;

    err = find( k, &i );
    if (i >= 0)    // Key to be modified was found 
        keys[i] = newk;
    else 
        return(SARR_ERR_K_NOTFOUND); // returns error from find

    return (SARR_NO_ERR); // successfully delete key from seq_array
} 


// function copy: attempts to copy the seq_array keys to another
//                array (the length of keys is size )
//    input: output array where the copy will be placed
//   output: a copy of keys is placed in duplicate
//           returns error SARR_ERR_INVALID_PTR invalid ptr
//                   either duplicate or keys or both
//           returns error SARR_ERR_UNDERFLOW if array is empty
//           returns SARR_NO_ERR = successfully copied keys 
int seq_array::copy(int *duplicate){
    int i;

    if ((duplicate != nullptr) && (keys != nullptr)) {
        if (nkeys == 0) return(SARR_ERR_UNDERFLOW); 
        for (i=0; i<size;i++)
            duplicate[i] = keys[i];

    } else              
        return(SARR_ERR_INVALID_PTR);    

    return(SARR_NO_ERR);
}

// function status: prints the current status of the
//                  array (the length of keys is size )
//    input: char flag = 'f' full or 'k' only valid keys
//           in the array
//   output: writes to standard output
//           returns error SARR_ERR_INVALID_PTR = array ptr invalid
//           returns error SARR_ERR_UNDERFLOW if array is empty
//           returns error SARR_ERR_INVALID_SREQ invalid report type 
//                         requested
//           returns SARR_NO_ERR if successfully output array information
int seq_array::status(char flag){
    int i;
    
    if (keys != nullptr) {
        cout<<"n-elements in list = "<<nkeys<<endl;
        cout<<"first available slot in list = "<<f_avail<<endl;
        if (nkeys == 0) return(SARR_ERR_UNDERFLOW); 
        switch(flag){
            case 'f':
                for(i=0;i<size;i++){
                    cout<<"seq_array["<<i<<"] = ";
                    if (keys[i] != SENTINEL)
                        cout<<keys[i]<<endl;
                    else cout<<"[*]"<<endl; 
                }
                break;
            case 'v':
                i = 0;
                while (i<nkeys){
                    if (keys[i] != SENTINEL)
                    cout<<"seq_array["<<i<<"] = "<<keys[i]<<endl;
                    i++;
                }
                break;   
            default:
                return (SARR_ERR_INVALID_SREQ);
        }
    } else               
        return(SARR_ERR_INVALID_PTR);      

    return(SARR_NO_ERR);
}