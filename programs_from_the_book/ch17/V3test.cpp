#include <simplecpp>

struct V3{
  double x,y,z;
};

V3 sum(V3 const &a, V3 const &b){
  V3 v;
  v.x = a.x + b.x;
  v.y = a.y + b.y;
  v.z = a.z + b.z;
  return v;
}

V3 scale(V3 const &a, double factor){
  V3 v;
  v.x = a.x*factor;
  v.y = a.y*factor;
  v.z = a.z*factor;
  return v;
}

double length(V3 const &a){
  return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

int main(){
  V3 u,a,s;
  double t;
  cin >> u.x >> u.y >> u.z >> a.x >> a.y >> a.z >> t;
  s = sum(scale(u,t), scale(a,t*t/2));
  cout << length(s) << endl;
}
