#include <simplecpp>

main_program{
  float nextmark, sum=0;
  int count=0;

  cin >> nextmark;         // right copy of box A

  while(nextmark >= 0){    // box C 
    sum = sum + nextmark;  // Box B
    count = count + 1;     // Box B

    cin >> nextmark;       // left copy of box A
  }

  cout << "The average is: " << sum/count << endl;
}
