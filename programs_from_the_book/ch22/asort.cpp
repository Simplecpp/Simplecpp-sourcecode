#include <simplecpp>
#include <algorithm>
int main(){
  int a[5]={10,8,11,3,4};

  sort(a,a+5);
  for(int i=0; i<5; i++) cout << a[i] << endl;

  sort(a,a+5,[](int i, int j){return i>j;});
  for(int i=0; i<5; i++) cout << a[i] << endl;
}

