#include <simplecpp>

bool lastCaptures(int Q[], int k)
// checks whether the queen in column k captures those in columns 0..k-1
{
  for(int j=0; j<k; j++){
    if((Q[j] == Q[k]) ||                // in same row
       (abs(j-k) == abs(Q[j] - Q[k])))  // in same diagonal
      return true;                
  }
  return false;
}

void search(int Q[], int k, int n){
  if(k == n){
    for(int j=0; j<k; j++) 
      cout << Q[j];
    cout << endl;
  }
  else{
    for(int j=0; j<n; j++){
      Q[k] = j;
      if(!lastCaptures(Q, k)) search(Q, k+1, n);
    }
  }
}

int main(){
  const int n=8;
  int Q[n];
  search(Q,0,n);
}
