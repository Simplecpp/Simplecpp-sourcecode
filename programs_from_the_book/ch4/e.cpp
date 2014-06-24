#include <simplecpp>
/***************************************************
   Program to calculate e.
   Calculates 1/0! + 1/1! + ... + 1/n!, for input n.  n >= 0.

   Abhiram Ranade, 24/2/13
***************************************************/
main_program{  
  int n; cin >> n;     // the last term to be added is 1/n!

  int i=1;             // counts iterations of the loop
  double term = 1.0;   // for holding terms of the series
  double result = 1.0; // Will contain the final answer

  repeat(n){ // Plan: When entering for the tth time, t = 1,2,..,n
             // i = t, term = 1/(t-1)!, result = 1/0!+...+1/(t-1)!
    result = result + term/i;
    term = term/i;
    i = i + 1;
  }
  cout << result << endl;
}
