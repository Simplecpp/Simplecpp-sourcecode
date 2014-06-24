#include <simplecpp>

main_program{
  float income; // in rupees.
  float tax;    // in rupees.

  cout << "What is your income in rupees? ";
  cin >> income;

  if(income <= 180000) tax = 0;                 // first if statement
  if((income >  180000) && (income <= 500000))  // second if statement
    tax = (income - 180000)* 0.1;
  if((income >  500000) && (income <= 800000))  // third if statement
    tax = 32000+(income - 500000)* 0.2;
  if(income > 800000)                           // fourth if statement
    tax = 92000+(income - 800000)* 0.3;

  cout << "Tax is: " << tax << endl;
}
