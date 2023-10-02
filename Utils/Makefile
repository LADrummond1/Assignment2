# Chem 274B: Software Engineering Fundamentals for
#            Molecular Sciences 
# University of California, Berkeley
#
# Creator:  Tony Drummond, PhD.  
# Date Created: September 15, 2022
#
# This is a global makefile, which meand that make commands
# at this level will make calls to other make files in its
# subdirectories.  

# Targets in this Makefile:
#	all: makes all linkable object files from C++ programs in
#        Assignment2/Utils/Hashing, Assignment2/Utils/Metrics and 
#		 Assignment2/Utils/Rangen and builds the library libmyhashfs.a
#		 libmymetrics.a and libmyrandom.a 
#      
#	cleanall: removes all linkable objects and libraries from 
#             Assignment2/Utils/Lib/

METRICS_DIR = Metrics/ 
RANGEN_DIR = Rangen/
HASHING_DIR = Hashing/
LIB_DIR    = Lib/

all:
	cd $(METRICS_DIR); make all
	cd $(RANGEN_DIR); make all
	cd $(HASHING_DIR); make all

cleanall:	
	cd $(METRICS_DIR); make cleanall
	cd $(RANGEN_DIR); make cleanall
	cd $(HASHING_DIR); make cleanall
