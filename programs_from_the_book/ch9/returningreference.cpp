#include <simplecpp>

int &f(int &x, int &y){
  if(x > y) return x;
  else return y;
}
main_program{
  int p=5, q=4;
  f(p,q) = 2;                  // function call appears on the left!
  cout << p <<' '<< q << endl;
  cout << f(p,q) << endl;
}
