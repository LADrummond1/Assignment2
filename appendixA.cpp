#include <iostream>
using namespace std;

#include <fstream>

struct process_table{
   string pID;                // Unique IDs for the processes 
   string pname;              // Names of the processes
   int prtime;                // Runtime requests for CPU 
   int status;                // Current status for the processes
   int ndepend;               // Number of dependencies per process
   string *dependencies;      // Array of ndepend dependencies/process

};

void delete_dependency(int *ndepend, string *dependencies, string pid)
{
   int i, k;

   i = 0;
   string temp;
   cout<<"calling delete with ndepend = "<<*ndepend<<" pdi = "<<pid<<endl;
   if (dependencies != nullptr){
      if (*ndepend > 0){
         while(i < *ndepend)
            if (dependencies[i] == pid){
               *ndepend-=1;
               // if the new list is not empty and delete pid is not 
               // the last pid in the dependencies, shift pids in dependecies
               // to delete pid
               if ((*ndepend > 0) && (i < *ndepend)) 
                  for(k = i; k < *ndepend; k++)
                     dependencies[k] = dependencies[k+1];
            }
            else i++;
         if (*ndepend == 0)
            dependencies = nullptr;
      }
   }
}

int build_proc_table(){
   int i, j, k, n;
   
   ifstream ifile;              // read only file (from <fstream>)
   int nprocs, ts, start;       // from first line we read nprocs
                                // and from last line in the file, we
                                // read the timestep(ts) & start time 
   
   process_table t1[20];        // declaring and allocating the
                                // process table t1

   ifile.open("scheduler_test2.txt");    // opening the input file (read only)

   if (!ifile) {                // Check for errors opening the file
      cout << "Unable to open file simple.txt";
      return(-1);   // call system to stop
   }
   
   while (!ifile.eof())
    {
       ifile >> nprocs;             // Read first line of the input file
       n = nprocs;
       for(i = 0; i < nprocs; i++){ // Read the nprocs informations
            ifile >>t1[i].pID;
            ifile >>t1[i].pname;
            ifile >>t1[i].prtime;
            ifile >> t1[i].ndepend;
            // if the process has dependecies allocate a string array
            // to store the lists of pIDs (dependencies)
            if (t1[i].ndepend > 0){ 
		         t1[i].dependencies = new (nothrow) string[t1[i].ndepend];
               if (t1[i].dependencies != nullptr)
		            for( j=0; j < t1[i].ndepend; j++)
			            ifile >>t1[i].dependencies[j];
            }
            else if (t1[i].ndepend == 0)
               t1[i].dependencies = nullptr;
            else
               return (-50);  // invalid record entry for t1[i]
       } 
       ifile >> start >> ts;  // Reading last line of input file 
                              // the time_step and system start time            
    }
}
