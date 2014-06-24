#include <simplecpp>

main_program{  // Fit line to set of points clicked by the user.
  cout << "Number of points: ";
  int n; cin >> n;   // number of points to which the line is to be fit.

  initCanvas("Fitting a line to data",500,500);

  double p=0, q=0, r=0, s=0;
  Circle pt(0,0,0);  // Will be used to show point clicked by user
  repeat(n){
    int cPos = getClick();
    double x = cPos/65536;
    double y = cPos % 65536;
    pt.reset(x,y,5); // Centered at the click position
    pt.imprint();    // Because we will move pt for subsequent points.

    p += x*x;
    q += x;
    r += x*y;
    s += y;
  }
  double m = (n*r - q*s)/(n*p - q*q);
  double c = (p*s - q*r)/(n*p - q*q);
  Line l(0,c, 500, 500*m+c);
  wait(10);
}
