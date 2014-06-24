#include <simplecpp>

main_program{
  int x; cin >> x;

  bool found = false;
  for(int i=2; i < x; i++){// if the loop is entered we know that
                           // x is not divisible by 2...i-1
    if(x % i == 0){ found = true; break;}
  }

  if(found) cout << "Composite.\n";
  else cout << "Prime.\n";
}
