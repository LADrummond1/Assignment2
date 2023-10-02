// Chem 274B: Software Engineering Fundamentals for
//            Molecular Sciences 
// Creator: Dr.  Tony Drummond
// Date Created: 9/01/2022
// Last revisited: 9/20/2023
//
//  C++ functions that generate random key of strings

//  myrandom.h in ../../Include/myrandom.h contains the API
//                to random functions and other dependencies
#include "myrandom.h"

// function: get_randmmdd generates a random pair of month and day
//    input: <no inputs>
//   output: returns in month the randomly generated month
//           returns in day the randomly generated day
void get_randmmdd(int *month, int *day){
    *month = (rand()%12)+1; //generates a random month number
    if (*month == 2)        // month = february
        *day = (rand()%28)+1; //doesn't care for leap years ;?(
    else if ((*month == 4) || (*month == 6) || // 30-day months
             (*month == 9) || (*month == 11))
            *day = (rand()%30)+1;
    else *day = (rand()%31)+1; // 31-day months
}

// function: formatted_date generates a string with a formatted date
//    input: year: integer representing the date's year 
//           month: integer representing the date's month (1 - 12)
//           day: integer representing the date's day (1-31)
//   output: formatted string of the input date
string formatted_date(int year, int month, int day){
    stringstream datestr; // datestr is used to generate a
                          // a formatted date yyyy/mm/dd
    datestr.str("");      // clear the string stream
    datestr<<setfill('0') << setw(4)<<year;
    datestr<<setfill('0') << setw(2)<<month;
    datestr<<setfill('0') << setw(2)<<day;
    return(datestr.str());
}

// function: rand_dates generates n random dates for years  
//           between year1 and year2
//    input: rtype: random generation type can used a fixed
//           seed (GEN_FIXED_RSEED) or start with a random 
//           seed (GEN_NEW_RSEED)
//           year1: is the 1st year to consider for the random dates
//           year2: is the end year to consider for the random dates
//           n    : number of dates to generate
//           dates: array of strings where the dates should be 
//                  returned (should be allocated by the caller)
//   output: dates: is an array of 8-character strings containing dates
//            returns RAND_INVALID_PTR if array has not been allocated
//            returns RAND_ERR_SEEDTYPE if seed type is not valid
//            returns RAND_INVALID_RANGE if the year2 < year 1
//            returns RAND_NO_ERR if successfully creates random 
//                    array of strings
int rand_dates( int rtype, int year1, int year2, int n, string *dates ){
    int i, j, dpy;   // i and j iterators, dpy is dates per year;
    int day, month;  // day and month variables
    int idate;       // ith date in array dates[]

    if (dates == nullptr)
        return (RAND_INVALID_PTR);   // Error -1 invalid array
    
    if (rtype == GEN_FIXED_RSEED)   //rseed = FIXED_RSEED
        srand(FIXED_RSEED);
    else if (rtype == GEN_NEW_RSEED) // rseed = random value
        srand(time(NULL));
    else return (RAND_ERR_SEEDTYPE);               // Error -4 invalid RANDOM 
                                    // seed setup type
    if (year2 < year1)
        return(RAND_INVALID_RANGE);  // Invalid year range year2 < year1
    else if (year1 == year2)
        dpy = n;
    else dpy = n/(year2 - year1 + 1);// attempts to create an equal 
                                     // number of the dates per year
    idate = 0;
    for(i=year1; i<=year2; i++){
        for(j = 0; j<dpy; j++){
            get_randmmdd( &month, &day);
            dates[idate] = formatted_date(i, month, day);
            idate++;
        }
    }

    if (idate < n){     // there was not an even split of n/#years
        j = n - idate;  // j= the # extra dates to generate
        for(i=year1; i<(year1+j); i++){
            get_randmmdd( &month, &day );
            dates[idate] = formatted_date( i, month, day );
            idate++;
        }
    }

    return (RAND_NO_ERR);
}

// function: append_uids generates n unique IDs to the 
//           end of every string in an array of size n
//    input: strings : is an array of n strings
//           n: is the size of the strings 
//   output: the strings in the original have a unique tag at the end 
//            returns RAND_INVALID_PTR if array has not been allocated
//            returns RAND_INVALID_SZ if n < 1
//            returns RAND_NO_ERR if successfully creates random 
//                    array of strings
int append_uids( string *strings, int n ){
    int i, len;         // i is an iterator and len is length of
                        // the string to be appended at the end
    stringstream unique_key;

    if (strings == nullptr)
        return (RAND_INVALID_PTR);   // Invalid array of strings passed

    if ( n < 1 )
        return (RAND_INVALID_SZ);  // Invalid length of array

    len = floor(log10(n))+1; 

    for( i=0; i<n; i++){
        unique_key.str("");
        unique_key << strings[i] <<setfill('0') <<setw(len) <<hex <<i;
        strings[i] = unique_key.str();
    }
return (RAND_NO_ERR);
}