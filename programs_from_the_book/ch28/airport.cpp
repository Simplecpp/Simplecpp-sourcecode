#include "airport.h"

const int RW1X1=100, RW1Y1=100, RW1X2=900, RW1Y2=300;
const int RW2X1=100, RW2Y1=300, RW2X2=900, RW2Y2=100;
const int RWXm=500, RWYm=200;

const int TWX1=950, TWY1=500, TWX2=50, TWY2=500;

const int TWYT = 600;  // level of the terminals
const int tRW = 30, tVT = 6, tMT = 5, tBT = 5;

void configure_taxiways_and_runways(vector<taxiway*> &taxiways){
  taxiways[0] = new taxiway(RW1X1,RW1Y1,RW1X2,RW1Y2,tRW); // landing runway
  taxiways[1] = new taxiway(RW1X2,RW1Y2,TWX1,TWY1,tVT);   // right taxiway

  float twXdisp = ((float)TWX2-TWX1)/(nGates+1);
  float twYdisp = ((float)TWY2-TWY1)/(nGates+1);

  for(int i=0; i<= nGates; ++i){              // main taxiway: 11 segments
    taxiways[2+i] = new taxiway(int(TWX1+i*twXdisp), int(TWY1+i*twYdisp),
				int(TWX1+(i+1)*twXdisp), 
				int(TWY1+(i+1)*twYdisp), tMT);
  }
  taxiways[3+nGates] = new taxiway(TWX2,TWY2,RW2X1,RW2Y1,tVT); // left taxiway
  taxiways[4+nGates] = new taxiway(RW2X1,RW2Y1,RW2X2,RW2Y2,tRW);
                                                             // takeoff runway
  
  for(int i=0; i<nGates; ++i){                 // branch to gate
    taxiways[5+nGates+i] = new taxiway(int(TWX1+(i+1)*twXdisp), 
				       int(TWY1+(i+1)*twYdisp),
				       int(TWX1+(i+1)*twXdisp), TWYT, tBT);
  }
  for(int i=0; i< nGates; ++i){             // branch from gate
    taxiways[5+2*nGates+i] = new taxiway(int(TWX1+(i+1)*twXdisp), TWYT,
					 int(TWX1+(i+1)*twXdisp), 
					 int(TWY1+(i+1)*twYdisp), tBT);
  }
  taxiways[5+3*nGates] = new taxiway(0,0,0,0,0);  // halfRW
}

void post_plane_arrivals(vector<taxiway*> &taxiways, ifstream &planeDataFile){
  int arrivalT, serviceT;
  int id = 1;                 // identifier for each plane
  while(planeDataFile >> arrivalT){
    planeDataFile >> serviceT;
    new plane(id++, arrivalT, serviceT, taxiways);
  }
}

int main(int argc, char** argv){
  vector<taxiway*> taxiways(nSegments);  // including halfRW
  initCanvas("Airport Simulator",1000,1000);

  configure_taxiways_and_runways(taxiways);
  ifstream planeDataFile(argv[1]);
  post_plane_arrivals(taxiways, planeDataFile);
  sim::processAll();
  getClick();
}
