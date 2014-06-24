#include <simplecpp>
int main(){
  float marks[60]; // marks[i] stores the marks of roll number i+1.
  for(int i=0; i<60; i++){
    cout << "Marks for roll number " << i+1 << ": ";
    cin >> marks[i];
  }
  float maxSoFar = marks[0];
  for(int i=1; i<60; i++){   // i starts at 1 because we already took marks[0]
    maxSoFar = max(maxSoFar, marks[i]);
  }
  for(int i=0; i<60; i++)
    if(marks[i] == maxSoFar) 
      cout << "Roll number " << i+1 << " got maximum marks." << endl;
}
