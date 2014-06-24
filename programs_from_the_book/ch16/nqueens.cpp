#include <simplecpp>

bool capture(int Q[], int n)
// Returns true if queens stored in Q[0..n-1] capture each other.
{
  for(int j=1; j<n; j++){                  // check for all pairs j != k
    for(int k=0; k<j; k++){
      if((Q[j] == Q[k]) ||                 // in same row
         (abs(j-k) == abs(Q[j] - Q[k])))   // in same diagonal
	return true;                      
    }
  }
  return false;
}

void search(int Q[], int k, int n){
// Search the set of queen configurations in which first k queens are in
// rows Q[0],...,Q[k-1].
// Of these print those configurations in which queens do not capture
// each other.
// n = total number of queens.
  if(k == n){
    if (!capture(Q, k)){
      for(int j=0; j<k; j++) cout << Q[j];
      cout << endl;
    }
  }
  else{
    for(int j=0; j<n; j++){
      Q[k] = j;
      search(Q, k+1, n);
    }
  }
}

int main(){
  const int n=8;
  int Q[n];
  search(Q,0,n);
}
