#include <simplecpp>

int gcd(int m, int n)
// finds GCD(m,n) for positive integers m,n
{
  if(m % n == 0) return n;
  else return gcd(n,m % n);
}

main_program{
  cout << gcd(24,36) << endl;
}
