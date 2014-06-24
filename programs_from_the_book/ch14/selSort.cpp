#include <simplecpp>

int argmax(float marks[], int L)
// marks = array containing the values
// L = length of marks array.  required > 0.
// returns maxIndex such that marks[maxIndex] is largest in marks[0..L-1]
{ 
  int maxIndex = 0;
  for(int j = 1; j < L; j++)
    if( marks[maxIndex] < marks[j]) // bigger element found?
      maxIndex = j;                 // update maxIndex.
  return maxIndex;
}

void SelSort(float data[], int n)
// will sort in NON-DECREASING order.  
{
  for(int i=n; i>1; i--){
    int maxIndex = argmax(data,i);  // Find index of max in data[0..i-1]
    float maxVal = data[maxIndex];  // Exchange elements at 
    data[maxIndex] = data[i-1];     //   index = maxindex 
    data[i-1] = maxVal;             //   and index = i-1.
  }
}

int main(){
  float a[7]={1, 3, 9, -5, 3, 10, 1};
  SelSort(a,7);
  for(int i=0; i<7; i++) cout << a[i] <<' ';
  cout << endl;
}
