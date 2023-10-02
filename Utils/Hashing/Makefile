# Chem 274B: Software Engineering Fundamentals for
#            Molecular Sciences 
# 
# Creator:  Tony Drummond, PhD.  Faculty
# Date Created: September, 2022
# Date Updated: September 22, 2023
#
# Directory Path: Assignment2/Utils/Hashing
#
# This makefile creates an object file containing hash functions
# After compiling all source program files, it creates a
# hash-function library (libmyhashfs.a), which is relocated to 
# Assignment2/Utils/Lib after its successful creation.

# GNU C++ Compiler
CPP         = g++      

# compiler flags -g debug, -O3 optimized version -c create a library object file
CPPFLAGS    = -O3 -c    

# The directory where the include files needed to create the library objects are
INC_DIR = ../Include

# The directory where all object files are going to moved afer creation
LIB_DIR = ../Lib

# The next line contains the list of timing utility object files created 
# with this Makefile (i.e. they are the targets this makefile builds)
HASHING_OBJS = myhashfunctions.o
HASHING_LIB = libmyhashfs.a

myhashfunctions.o: 
	$(CPP) $(CPPFLAGS) myhashfunctions.cpp -I$(INC_DIR)

libmyhashfs.a: $(HASHING_OBJS)
	ar -ru $(HASHING_LIB) $(HASHING_OBJS) 
	mv $(HASHING_LIB) $(LIB_DIR)
	rm $(HASHING_OBJS)

all: $(HASHING_LIB)

cleanall:
	cd $(LIB_DIR); rm $(HASHING_LIB)

