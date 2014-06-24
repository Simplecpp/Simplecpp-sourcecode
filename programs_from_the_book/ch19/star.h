class Star {
private:
  Circle image;
  double mass;
  V3 r,v;  // position, velocity 
public:
  Star(){};
  void init(double m, V3 position, V3 velocity);
  void vStep(double dT, V3 f);
  void rStep(double dT);
  void print();
  V3 forceOf(Star &s);
};

