#include <simplecpp>
main_program{
  float x;
  char response;

  do{
    cout << "Type the number whose square root you want: ";
    cin >> x;
    cout << "The square root is: " << sqrt(x) << endl;
    
    cout << "Type y to repeat: ";
    cin >> response;
    }
  while(response == 'y');
}
