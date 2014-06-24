#include <simplecpp>
int gcd            // return-type function-name 
  (int m, int n)   // parameter list: (parameter-type parameter-name ...)
{                  // beginning of function body
  while(m % n != 0){
    int Remainder = m % n;  
    m = n;
    n = Remainder;
  }
  return n;
}                 // end of function body

main_program{
  int a=36,b=24,c=99,d=47;
  cout << gcd(a,b) << endl; 
  cout << gcd(c,d) << endl; 
}


