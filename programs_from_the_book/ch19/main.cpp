#include <simplecpp>
#include "V3.h"
#include "star.h"
#include <fstream>
#include <assert.h>

void read_star_data(Star stars[], int n){
  float mass, vx, vy, vz,  x,y,z;
  for(int i=0; i<n; i++){
    cin >> mass >> x >> y >> z >> vx >> vy >> vz;
    stars[i].init(mass, V3(x,y,z), V3(vx,vy,vz));
  }
  assert(cin);  // quick check that input was valid
}

void calculate_net_force(int n, Star stars[], V3 forces[]){
  for(int i=0; i<n; i++) forces[i]=V3(0,0,0);

  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      V3 f = stars[i].forceOf(stars[j]);
      forces[i] = forces[i] + f;
      forces[j] = forces[j] - f;
    }
  }
}

int main(){
  initCanvas("N body problem",800,800);

  double T, delta; cin >> T >> delta;
  int n; cin >> n;
  Star stars[n];
  read_star_data(stars, n);

  V3   forces[n];

  calculate_net_force(n,stars,forces);
  for(int i=0; i<n; i++) stars[i].vStep(delta/2, forces[i]);

  for(float t=0; t<T; t+=delta){
    for(int i=0; i<n; i++) stars[i].rStep(delta);
    calculate_net_force(n,stars,forces);
    for(int i=0; i<n; i++) stars[i].vStep(delta, forces[i]);
  }
  getClick();
}
