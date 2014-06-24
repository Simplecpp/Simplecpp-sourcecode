#include <simplecpp>
#include <functional>

double f(double x){
  return x*x -2;
}

double g(double x){
  return sin(x) - 0.3;
}

double bisection(double xL, double xR, double epsilon, 
                 std::function<double(double)> pf)
// precondition: f(xL),f(xR) have different signs. ( >0 and <=0).
{
  bool xL_is_positive = pf(xL) > 0; 
  // Invariant: x_L_is_positive gives the sign of f(x_L).
  // Invariant: f(xL),f(xR) have different signs.

  while(xR-xL >= epsilon){
    double xM = (xL+xR)/2;
    bool xM_is_positive = pf(xM) > 0;
    if(xL_is_positive == xM_is_positive)
      xL = xM;  // maintains both invariants
    else
      xR = xM;  // maintains both invariants
  }
  return xL;
}

int main(){
  double y = bisection(1, 2, 0.0001, f);  // Alternate syntax: &f
  cout << "Sqrt(2): " << y << " check square: " << y*y << endl;

  double z = bisection(0, PI/2, 0.0001, g);
    cout << "Sin inverse of 0.3: " << z << " check sin: " << sin(z) << endl;
}
