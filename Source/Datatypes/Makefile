# Chem 274B: Software Engineering Fundamentals for
#            Molecular Sciences 
# 
# Creator:  Tony Drummond, PhD.  Faculty
# Date Created: September, 2022
# Date Updated: September 22, 2023
#
# Directory Path: Assignment2/Source/Datatypes
# This makefile creates objects and a library from OO Classes that
# implement Data structures. Here is an example of archiving object
# files (see DATA_OBJS) into a library object file (DATA_LIB)

# GNU C++ Compiler
CPP         = g++      # C++ Compuler

# compiler flags -g debug, -O2 optimized version -c create a library object
CPPFLAGS    = -O3 -c    

# The directory where the include files needed to create the library objects are
INC_DIR = ../../Include

# The directory where all object files are going to moved afer creation
LIB_DIR     = ../../Lib

# DATA_OBJS contains the current list of object files created after 
# compiling the C++ source files that declare and implement OO classes 
# for the data types: seq_array, stack and hashtables.
DATA_OBJS = seq_array.o stack.o hashtables.o

# DATA_LIB is the name of object library file that will contain all
# DATA_OBJS files
DATA_LIB = libmydatatypes.a 

# Notice that now we don't move the object files to LIB_DIR but
# use them to build a library object file.
seq_array.o:  $(INC_DIR)/mydatatypes.h
	$(CPP) $(CPPFLAGS) seq_array.cpp -I$(INC_DIR)

stack.o:  $(INC_DIR)/mydatatypes.h
	$(CPP) $(CPPFLAGS) stack.cpp -I$(INC_DIR)

hashtables.o: $(INC_DIR)/mydatatypes.h	
	$(CPP) $(CPPFLAGS) hashtables.cpp -I$(INC_DIR)

# The following target creates a static library (a collection of
# linkable object files).  We use the Linux command 'ar' to create
# the library by archiving previously created object files 
# (here we are archinving in the library all the DATA_OBJS listed
# above). After all the object files in DATA_OBJS have been archived
# in the library object file, they can be removed.
libmydatatypes.a: $(DATA_OBJS)
	ar ru $(DATA_LIB) $(DATA_OBJS) 
	mv $(DATA_LIB) $(LIB_DIR)
	rm $(DATA_OBJS)
    
all: $(DATA_LIB)

cleanall:
	cd $(LIB_DIR); rm $(DATA_LIB)