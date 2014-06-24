#include <simplecpp>

struct V3{
  double x,y,z;
  double length(){             // member function length
      return sqrt(x*x + y*y + z*z);
  }
  V3 sum(V3 b){                // member function sum
    V3 v;
    v.x = x + b.x;  v.y = y + b.y;  v.z = z + b.z;
    return v;
  }
  V3 scale(double t){         // member function scale
    V3 v;
    v.x = x*t;  v.y = y*t;  v.z = z*t;
    return v;
  }
  void joker(double q){       // member function, included for fun.
    x = q;
    cout << length() << endl;
  }
};

int main(){
  V3 p = {1.0, 2.0, 3.0};
  cout << p.length() << endl;
  p.joker(5);
  cout << p.x << endl;
}
