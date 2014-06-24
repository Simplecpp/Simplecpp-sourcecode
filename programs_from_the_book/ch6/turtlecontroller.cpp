#include <simplecpp>

main_program{
  char command;
  turtleSim();
  
  repeat(100){
    cin >> command;
    if (command == 'f') forward(100);
    else if (command == 'r') right(90);
    else if (command == 'l') left(90);
    else cout << "Not a proper command, " << command << endl;
  }
}
