#include <simplecpp>
#include "V3.h"
#include "star.h"
void Star::init(double m, V3 r1, V3 v1){
  mass = m;
  r = r1;
  v=v1;
  image.reset(r.getx(),r.gety(),15);
  image.setColor(COLOR("red"));
  image.setFill(true);
  image.penDown();
}

void Star::vStep(double dT, V3 f){
    v = v + f*(dT/mass);
}

void Star::rStep(double dT){
    V3 d = v*dT;
    image.move(d.getx(),d.gety());
    r = r + d;
}

void Star::print(){
    cout << mass << " " << image.getOrigin().getX() << " "
	 << image.getOrigin().getY() << " ";
    cout << v << endl;
}

V3 Star::forceOf(Star &s){
  V3 R = s.r - r;
  return R * (mass * s.mass / pow(R.length(),3));
}
