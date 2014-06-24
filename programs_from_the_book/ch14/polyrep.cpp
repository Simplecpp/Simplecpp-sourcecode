#include <simplecpp>

void addp(float a[], float b[], float c[], int n){
// a, b: addends, c: result, n: length of the arrays.
  for(int i=0; i<n; i++)  c[i] = a[i] + b[i];
}

void prodp(float a[], float b[], float d[], int n){
// a,b must have n elements, product d must have 2n-1.
  for(int i=0; i<2*n-1; i++) d[i] = 0;
  for(int j=0; j<n; j++)
    for(int k=0; k<n; k++) 
       d[j+k] += a[j]*b[k];
}

int main(){
  float a[5], b[5], c[5], d[9];
  for(int i=0; i<5; i++) cin >> a[i] >> b[i];
  //  for(int i=0; i<5; i++) cin >> a[i];
  //  for(int i=0; i<5; i++) cin >> b[i];

  addp(a,b,c,5);
  prodp(a,b,d,5);

  for(int i=0; i<5; i++) cout << c[i] <<' ';
  cout << endl;
  for(int i=0; i<9; i++) cout << d[i] <<' ';
  cout << endl;
}
