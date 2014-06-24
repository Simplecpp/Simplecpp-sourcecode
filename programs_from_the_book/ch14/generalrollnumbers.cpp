#include <simplecpp>
int main(){
  int rollno[60];
  double marks[60];
  
  for(int i=0; i<60; i++) cin >> rollno[i] >> marks[i];
  
  while(true){
    int r; cin >> r;  // roll number whose marks are requested
    if(r == -1) break;
    int i;
    for(i = 0; i<60; i++){
      if(rollno[i] == r){ cout << marks[i] << endl; break;}
    }
    if(i >= 60) cout << "Invalid roll number.\n";
  }
}
