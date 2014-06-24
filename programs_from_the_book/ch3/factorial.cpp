#include <simplecpp>

main_program{
  int n, fac=1, i=1;
  cin >> n;
  
  repeat(n){
    fac = fac * i;    	// sequence accumulation
    i = i + 1;	      	// sequence generation
  }
  cout << fac << endl;
}
