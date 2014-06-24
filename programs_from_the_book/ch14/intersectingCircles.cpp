#include <simplecpp>
int main(){
  int n=5;                      // number of circles.  5 chosen arbitrarily.
  float x[n], y[n];             // coordinates of center of each circle.
  float r[n];                   // radius of each circle.

  for(int i=0;i<n;i++)          // read in all data.
    cin >> x[i] >> y[i] >> r[i];
                                // Find intersections if any.
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(pow(x[i]-x[j],2)+pow(y[i]-y[j],2) <= pow(r[i]+r[j],2))
        // built in function pow(x,y) = x raised to power y.
        cout << "Circles " << i << " and " << j << " intersect." <<endl;
    }
  }
}
