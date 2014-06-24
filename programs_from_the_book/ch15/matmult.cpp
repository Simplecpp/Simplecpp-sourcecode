#include <simplecpp>

int main(){
  double a[3][2]={{1,2},{3,4},{5,6}}, b[2][4]={{1,2,3,4},{5,6,7,8}}, c[3][4];

  for(int i=0; i<3; i++)                      // compute c = a * b.
    for(int j=0; j<4; j++){
      c[i][j] = 0;
      for(int k=0; k<2; k++)
	c[i][j] += a[i][k]*b[k][j];
    }

  for(int i=0; i<3; i++){                     // print out c.
    for(int j=0; j<4; j++) cout << c[i][j] << " ";
    cout << endl;
  }
}
