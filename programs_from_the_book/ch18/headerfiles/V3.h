#ifndef V3_H
#define V3_H
class V3{
private:
  double x, y, z;
 public:
  V3(double p=0, double q=0, double r=0);
  V3 operator+(V3 const &w) const;
  V3 operator*(double t) const;
  double length() const;
};
#endif
