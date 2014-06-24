#include <simplecpp>

int Virahanka(int n){
  if(n == 1) return 1; // V_1
  if(n == 2) return 2; // V_2
  return Virahanka(n-1) + Virahanka(n-2); // V_{n-1} + V_{n-2}
}

main_program{
  int n;
  cin >> n;
  cout << Virahanka(n) << endl;
}
