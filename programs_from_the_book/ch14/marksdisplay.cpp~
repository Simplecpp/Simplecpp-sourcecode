#include <simplecpp>
int main(){
  float marks[60]; // marks[i] stores the marks of roll number i+1.
  for(int i=0; i<60; i++){
    cout << "Marks for roll number " << i+1 << ": ";
    cin >> marks[i];
  }
  while(true){
    cout << "Roll number: ";
    int rollNo;
    cin >> rollNo;

    if(rollNo == -1) break;

    cout << "Marks: " << marks[rollNo-1] << endl;
  }
}
