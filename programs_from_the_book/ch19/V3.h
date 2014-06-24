class V3{
  double x, y, z;
 public:
  V3(double x=0, double y=0, double z=0);
  V3 operator+(V3 const &w) const;
  V3 operator-(V3 const &w) const;
  V3 operator*(double t);
  double getx();   // accessor functions
  double gety();
  double getz();
  friend ostream & operator<<(ostream & ost, V3 v);
  double length();
};

ostream & operator<<(ostream & ost, V3 v);
