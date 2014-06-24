int gcd(int m, int n=2){       // return-type function-name 
                             //    (argument-type argument-name..){
  int mdash,ndash;           // body begins

  while(m % n != 0){
    mdash = n; 
    ndash = m % n;
    m = mdash;
    n = ndash;
  }
  return n;                 // body ends
}
