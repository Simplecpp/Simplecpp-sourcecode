#include <simplecpp>

int main(){
  initCanvas("Pentagon and Star");
  double pentaV[5][2], starV[5][2];

  for(int i=0; i<5; i++){
    pentaV[i][0] = 100 * cos(2*PI/5*i);
    pentaV[i][1] = 100 * sin(2*PI/5*i);
    starV[i][0] = 100 * cos(4*PI/5*i);
    starV[i][1] = 100 * sin(4*PI/5*i);
  }

  Polygon penta(200,200,pentaV,5);
  Polygon star(200,400,starV,5);

  for(int i=0; i<100; i++){
    penta.left(5);
    star.right(5);
    wait(0.1);
  }

  getClick();
}
