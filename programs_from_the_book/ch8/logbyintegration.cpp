#include <simplecpp>
main_program{
  double x; cin >> x;       // will calculate ln(x)
  int n; cin >> n;          // number of rectangles to use
  double w = (x-1)/n;       // width of each rectangle
  double area = 0;          // will contain ln(x) at the end.
  for(int i=0; i < n; i++)
     area = area + w /(1+i*w);
  cout << "Natural log, from integral: "<< area << endl;
  cout << "Natural log, built-in command: "<< log(x) << endl;
}
