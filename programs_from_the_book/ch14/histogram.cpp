#include <simplecpp>
int main(){
  int count[10]; // count[i] will store the number of marks in the range
  // i*10 through (i+1)*10 -1.
  for(int i=0; i<10; i++)
    count[i]=0;
  for(int i=0; i< 60; i++){
    float marks;
    cin >> marks;
    int index = marks/10;
    if(index >= 0 && index <= 9) count[index]++;
    else cout << "Marks are out of range." << endl;
  }
  for(int i=0; i<10; i++)
    cout << count[i] <<' ';
  cout << endl;
}
