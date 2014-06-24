#include <simplecpp>

main_program{ // Compute GCD of m,n, where m > n >0.
  int m,n;
  cout << "Enter the larger number (must be > 0): ";  cin >> m;
  cout << "Enter the smaller number (must be > 0): "; cin >> n;

  while(m % n != 0){
    int Remainder = m % n;  
    m = n;
    n = Remainder;
  }
  cout << "The GCD is: " << n << endl;
}
