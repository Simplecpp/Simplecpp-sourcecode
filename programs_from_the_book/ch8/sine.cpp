#include <simplecpp>
main_program{
  double x;  cin >> x;

  double epsilon = 1.0E-20, sum = x, term = x;

  for(int k=2; abs(term) > epsilon; k++){  
               // Plan: term = t_{k-1}, sum = sum of k-1 terms
    term *= -x * x /((2*k-2)*(2*k-1));
    sum += term;
  }

  cout << sum << endl;
}
