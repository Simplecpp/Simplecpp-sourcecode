int gcd(int m, int n);         // declaration of function gcd.

int lcm(int m, int n){
  return m*n/gcd(m,n);
}
