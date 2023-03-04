/*
 * File: PerfectNumbers.cpp
 * ------------------------
 * Name: [TODO: enter name here]
 * This program tests the isPerfect function by generating all the
 * perfect numbers up to some user-specified upper bound.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "simpio.h"
#include "console.h"
using namespace std;

/* Function prototypes */

bool isPerfect(int n);

/* Main program */

int main() {
   int bound;
   cout << "Enter upper bound: ";
   cin >> bound;
   cout << "The perfect numbers between 1 and " << bound;
   cout << " are:" << endl;
   for (int i = 1; i <= bound; i++) {
      if (isPerfect(i)) {
         cout << i << endl;
      }
   }
   return 0;
}

/*
 * Function: isPerfect
 * Usage: if (isPerfect(n)) . . .
 * ------------------------------
 * This function returns true if n is a perfect number.
 */

bool isPerfect(int n) {
    int sum = 0;
    for(int i = 1; i < n; i++)  // i < n 则n=1时不会被运算
        if(n%i == 0)
            sum += i;
    if (sum == n)              //判断是否符合要求并返回true or false
        return true;
    else return false;
}
/*
March 17th, cloudy, sad to do so much homework of 10 courses.
*/
