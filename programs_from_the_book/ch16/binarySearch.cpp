#include <simplecpp>

bool Bsearch(int x, int A[], int start, int size){
// x : target value to search
// range to search: A[start..start+size-1]
// precondition: size > 0;
// 
  if(size == 1) return (A[start] == x);
  int half = size/2;                 // 0 < half < size, because size>1.
  if(x < A[start+half]) 
    return Bsearch(x, A, start, half);           // recurse on first half
  else 
    return Bsearch(x, A, start+half, size-half); // recurse on second half.
}

int main(){
  const int size=10;
  int A[size]={-1, 2, 2, 3, 10, 15, 15, 25, 28, 30};
  for(int i=0; i<size; i++) cout << A[i] << " ";
  cout << endl;

  for(int x=-10; x<=40; x++)
    cout << x << ": " << Bsearch(x, A, 0, size) <<endl;
}
