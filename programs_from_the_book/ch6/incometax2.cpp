#include <simplecpp>

main_program{
  float income; 
  float tax;    

  cout << "What is your income? ";
  cin >> income;

  if(income <= 180000) tax = 0;       // new first if
  else if(income <= 500000)           // new second if
    tax = (income - 180000)* 0.1;
  else if(income <= 800000)           // new third if
    tax = 32000+(income - 500000)* 0.2;
  else 
    tax = 92000+(income - 800000)* 0.3;


  cout << "Tax is: " << tax << endl;
}
