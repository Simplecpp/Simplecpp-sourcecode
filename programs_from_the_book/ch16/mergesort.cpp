#include <simplecpp>

void merge(int U[], int uLength, int V[], int vLength, int S[]){
// arrays U,V of length uLength and vLength respectively contain the 
// sequences that are sorted in non-decreasing order.  The result of
// merging is to be placed in the array S.  The length of S is not 
// specified explicitly, but it is assumed (precondition) to be 
// uLength + vLength.

  for(int uFront=0, vFront=0, sBack=0; sBack<uLength+vLength; sBack++){
  // INVARIANT: sBack = uFront + vFront.  Keys U[0..uFront-1] will
  // have been moved to S, and and also keys V[0..vFront-1].  S will
  // contain these keys in S[0..sBack-1], in non-decreasing order.

    if(uFront<uLength && vFront<vLength){  // if both queues non-empty
      if(U[uFront] < V[vFront]){              // if U has smaller
        S[sBack] = U[uFront];                 // move to S
        uFront++;                             // advance U
      }
      else{                                   // if V has smaller
        S[sBack] = V[vFront];                 // move to S
        vFront++;                             // advance V
      }
    }
    else if(uFront < uLength) {           // else if only U is not empty
      S[sBack] = U[uFront];                   // move to S
      uFront++;                               // advance U
    }
    else {                                // else if only V is not empty
      S[sBack] = V[vFront];                   // move to S
      vFront++;                               // advance V
    }
  }
}

void mergesort(int S[], int n){
  if(n>1){
    int U[n/2], V[n-n/2];
    for(int i=0; i<n/2; i++) U[i] = S[i];
    for(int i=n/2; i<n; i++) V[i-n/2] = S[i];

    mergesort(U, n/2);
    mergesort(V, n - n/2);
    merge(U, n/2, V, n-n/2, S);
  }
}

int main(){
  int S[10]={10,8,9,15,7,6,5,9,8,4};
  mergesort(S,10);
  for(int i=0; i<10; i++) cout << S[i] << endl;
}
