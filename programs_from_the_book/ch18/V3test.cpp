#include <simplecpp>
struct V3{
  double x,y,z;
  V3(double p, double q, double r){     // constructor 1
    x = p;
    y = q;
    z = r;
  }
  V3(){                                 // constructor 2
    x = y = z = 0;
  }
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
  V3 operator+ (const V3 &b) const{               
    return V3(x + b.x, y+b.y, z+b.z);
  }
  V3 operator* (double t) const{
    return V3(x*t, y*t, z*t);
  }
};

int main(){
  V3 u,a,s;
  double t;
  cin >> u.x >> u.y >> u.z >> a.x >> a.y >> a.z >> t;
  s = u*t + a*t*t*0.5;
  cout << s.length() << endl;
}

