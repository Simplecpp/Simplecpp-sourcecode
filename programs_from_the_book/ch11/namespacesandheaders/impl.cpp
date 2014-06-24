#include "mySpace.h"

int mySpace::lcm(int m,int n){
  return m*n/gcd(m,n);
}
int mySpace::gcd(int m, int n){
  if(n == 0) return m;
  else return gcd(n, m % n);
}
