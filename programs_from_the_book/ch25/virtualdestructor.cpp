#include <simplecpp>

class A{
public:
  virtual ~A(){cout <<"~A.\n";}
};
class B: public A{
  int *z;
public:
  B(){z = new int;}
  ~B(){
    cout <<"~B.\n";
    delete z;
  }
};

int main(){
  A* aptr;
  aptr = new B;
  delete aptr;
}

  
