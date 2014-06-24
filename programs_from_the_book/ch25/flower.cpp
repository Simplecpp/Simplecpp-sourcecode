#include <simplecpp>

class Flower{
public:
  void whoAmI(){ cout << name() << endl; }
  virtual string name(){ return "Flower"; }
};

class Rose: public Flower{
public:
  string name(){ return "Rose"; }
};

int main(){
  Flower a;
  Rose b;
  a.whoAmI();
  b.whoAmI();
}
