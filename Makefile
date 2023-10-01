# Chem 274B: Software Engineering Fundamentals for
#            Molecular Sciences 
# University of California, Berkeley
# September 2023
#
# Creator:  Tony Drummond, PhD.  
# Date Created: September 20, 2022

# This is the global build Makefile template. Students can customize
# this makefile to include your global build information.

UTILS_DIR = Utils/           
DATATYPES_SRC_DIR = Source/Datatypes
TST_DIR = Tests/
SCHEDULER_DIR = Applications/Scheduler

all:
	cd $(UTILS_DIR); make all
	cd $(DATATYPES_SRC_DIR); make all
	cd $(TST_DIR); make all
	cd $(SCHEDULER_DIR); make all

cleanall:	
	cd $(UTILS_DIR); make cleanall
	cd $(DATATYPES_SRC_DIR); make cleanall
	cd $(TST_DIR); make cleanall
