#include <simplecpp>
#include "V3.h"
int main(){
  V3 a(1,2,3),b(1,1,0);
  cout << (a+b).length() << endl;
}
