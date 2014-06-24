#include <simplecpp>
void swap2(int &a, int &b){
  int temp;
  temp = a;
  a = b;
  b = temp;
}
main_program{
  int x=5, y=6;
  swap2(x,y);
  cout << x << " " << y << endl;
}
