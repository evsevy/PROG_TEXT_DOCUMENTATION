 // FILE:          enroll.cpp
   // TITLE:         Course Enrollments
   // SUBMITTED BY:  Ima Student
   //                All code is my own except where credited to others.
   // FOR COURSE:    CS 2020
   // DUE DATE:      March 30, 1999
   //
   // PURPOSE:
   // This program will keep track of enrollments in courses at a small
   // university. It will read, from the user, the course id number and
   // enrollment for each course offered. The data will then be sorted
   // from smallest to largest id number. The sorted list will then be
   // printed along with the total enrollments for all courses.
   //
   // OVERALL METHOD:
   // The list of general tasks is:
   // 1. Input course data from the user and store in parallel one-
   //    dimensional arrays.
   // 2. Sort the parallel arrays by id number. A bubble sort will
   //    be used.
   // 3. Print sorted course data stored in arrays.
   // 4. Print total enrollment at university.
   //
   // FUNCTIONS:
   //
   // getCourseData
   //    will read data from the user into arrays and, upon exit,
   //    return the total enrollment for all courses
   //
   // bubbleSort
   //    will sort the arrays of id numbers and enrollments from
   //    smallest to largest id numbers
   //
   // printCourseData
   //    will print the data contained in the arrays and, after
   //    that, the total enrollment
   //
   // swap
   //    is called by bubbleSort to exchange two array values
   //
   // INCLUDED FILES:
   //    iostream.h
   //    iomanip.h
   //
   // DATA FILES:
   //    none

   #include <iostream.h>
   #include <iomanip.h>

   int getCourseData( int nCourses, int courseids[], int enrollments[] );  ** note 1 **
   void printCourseData( int total, int nCourses, int courseids[], int enrollments[] );
   void bubbleSort( int n, int keys[], int values[] );
   void swap( int & item1, int & item2 );

   int main( )
   {  ** note 2 **
      const int nCourses = 3; // Program inefficient if nCourses is large!
      int courseids[ nCourses ], enrollments[ nCourses ];
      int total = getCourseData( nCourses, courseids, enrollments );
      bubbleSort( nCourses, courseids, enrollments );
      printCourseData( total, nCourses, courseids, enrollments );
      return 0; // Error level of 0 means normal termination
   }  ** note 2 **
   // name OF FUNCTION: getCourseData
   // CREDIT:
   // PURPOSE:
   //    The function will read, from the user, the course id and the
   //    enrollment in the course.  These values will be stored in a set of
   //    parallel arrays named "ids" and "totals".  The function will return
   //    the total enrollment.
   //
   // PARAMETERS:
   // name         type  value/reference   description
   // ---------------------------------------------------------------------
   // n            int   value             number of values in the array
   // ids[]        int   reference         the array of id numbers
   // totals[]     int   reference         the array of enrollment totals
   //                                      for each course
   //
   // RETURN VALUE:
   // name         type  description
   // ---------------------------------------------------------------------
   // grandtotal   int   the overall total enrollment for the university
   //
   // CALLS TO: none
   //
   // CALLED FROM: main
   //
   // METHOD: The following is pseudocode describing how the function works.
   // 1. Initialize the grand total to zero.  ** note 3 **
   // 2. Prompt user for data expected.
   // 3. Loop and execute n times.
   //    Use loop counter as subscript of arrays
   //    3.1 Prompt user for specific course data.
   //    3.2 Read in id.
   //    3.3 Read in enrollment.
   //    3.4 Add to enrollment to the grand total.
   // 4. Return the grand total.

   int getCourseData( int n, int ids[], int totals[] )
   {
      int grandTotal = 0;
      cout << endl  ** note 4 **
           << "For each of " << n << " courses," << endl
           << " enter the course id and the number of students in that course."
           << endl
           << " Enter these two values on one line, separated by a space."
           << endl
           << endl;
 
      for ( int i = 0; i < n; i++ )
      {
         cout << "Course " << i + 1 << " -- id and number of students: ";
         cin >> ids[i] >> totals[i];
         grandTotal += totals[i];
      }
      return grandTotal;
   }
   // name OF FUNCTION: printCourseData
   // CREDIT:
   // PURPOSE:
   //    The function will loop through parallel data arrays named "ids" and
   //    "totals", and will print out the course id and enrollment for each
   //    course.  Finally, it will print out the total enrollment.  Formatting
   //    is applied to make the output readable by humans.
   //
   // PARAMETERS:
   // name         type  value/reference   description
   // ---------------------------------------------------------------------
   // gTot         int   value             the overall total enrollment
   // n            int   value             number of values in the array
   // ids[]        int   reference         the array of id numbers
   // totals[]     int   reference         the array of enrollment totals
   //                                      for each course
   //
   // RETURN VALUE: none
   //
   // CALLS TO: none
   //
   // CALLED FROM: main
   //
   // METHOD: The following is pseudocode describing how the function works.
   // 1. Print titles for the columns of data.
   // 2. Print a separator.
   // 3. Loop and execute n times. Use the loop counter to index the arrays.
   //    3.1 Print the course id.
   //    3.2 Print the enrollment in that course.
   // 4. Print a separator.
   // 5. Print the enrollment for the entire university.

   void printCourseData( int gTot, int n, int ids[], int totals[] )
   {
      cout << endl
           << setw(10) << "Class id"
           << setw(12) << "Enrollment" << endl
           << "----------------------" << endl;
      for ( int i = 0; i < n; i++ )
      {  ** note 5 **
         cout << setw(10) << ids[i]
              << setw(12) << totals[i] << endl;
      }  ** note 5 **
      cout << "----------------------" << endl
           << setw(10) << "Total" << setw(12) << gTot    << endl;
   }
   // name OF FUNCTION: bubbleSort
   // CREDIT: Adapted from Robert Sedgewick, ALGORITHMS (1992), page 1010.
   // PURPOSE:
   //    This generic function will sort parallel data arrays, one containing
   //    keys, the other containing values associated 1-to-1 with those keys.
   //
   // PARAMETERS:
   // name         type  value/reference   description
   // ---------------------------------------------------------------------
   // n            int   value             number of values in the array
   // keys[]       int   reference         the array of keys
   // values[]     int   reference         the array of values for each course
   //
   // RETURN VALUE: none
   //
   // CALLS TO: swap
   //
   // CALLED FROM: main
   //
   // METHOD: The following is pseudocode describing how the function works
   // 1. Do the following n-1 times.
   //    1.1 Point to the first element of the array containing keys.
   //    1.2 Do the following n-1 times.
   //        1.2.1 Compare the element pointed to with the next element.
   //        1.2.2 If the compared elements are in the wrong order ...
   //              1.2.2.1 Swap the keys.
   //              1.2.2.2 Swap the values associated with those keys.
   //        1.2.3 Point to the next element.
   //
   // NOTE:
   //    This method is extremely inefficient except for small arrays.

   void bubbleSort( int n, int keys[], int values[] )   ** note 6 **
   {
      int last, next;
      for ( int i = 1; i < n; i++ )
      {
         last = n - i;
         for ( int j = 0; j < last; j++ )
         {
            next = j + 1;
            if ( keys[j] > keys[next] )
            {
               swap( keys[j], keys[next] );
               swap( values[j], values[next] );
            }
         }
      }
   }
   // name OF FUNCTION: swap
   // CREDIT:
   // PURPOSE:
   //    This utility function exchanges the values of its two parameters.
   //
   // PARAMETERS:
   // name         type  value/reference   description
   // ---------------------------------------------------------------------
   // item1        int   reference         item to be swapped with item2
   // item2        int   reference         item to be swapped with item1
   //
   // RETURN VALUE: none
   //
   // CALLS TO: none
   //
   // CALLED FROM: bubbleSort
   //
   // METHOD: The following is pseudocode describing how the function works.
   // 1. Save a reference to item1's content.
   // 2. Store in item1 a reference to item2's content.
   // 3. Using the saved reference, store in item2 a reference to
   //    item1's original content.

   void swap( int & item1, int & item2 )
   {
      int temp = item1;
      item1 = item2;
      item2 = temp;
   }
 
   // EXAMPLE INPUT AND OUTPUT  ** note 7 **
   //
   // For each of 3 courses,
   // enter the course id and the number of students in that course.
   // Enter these two values on one line, separated by a space.
   //
   // Course 1 -- id and number of students: 8402 21
   // Course 2 -- id and number of students: 3589 35
   // Course 3 -- id and number of students: 4521 59
   //
   // Class id    Enrollment
   // ----------------------
   //     3589            35
   //     4521            59
   //     8402            21
   // ----------------------
   // Total              1150