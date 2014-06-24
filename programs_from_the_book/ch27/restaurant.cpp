#include <simplecpp>

int main(){
  const int nTables=5;                   // number of tables 
  const int duration=180;                   // minutes open
  double arrivalP=0.1, eatMin=21, eatMax=40;
  int nOccupied = 0 ;                       // number of tables occupied
  int id = 0;
  std::srand(100);

  for(int t=0; t<duration; t++){
    if(randuv(0,1) <= arrivalP){            // with probability arrivalP 
      id++;
      sim::post(t, [=,&nOccupied](){
	if(nOccupied >= nTables)           // if no table available
	  sim::log()<< " Customer " << id << " disappointed.\n";
	else{                               // if a table is available
	  ++nOccupied;
	  int eatTime = randuv(eatMin, eatMax);
	  sim::log()<<"  Customer " << id << " will eat for "<<eatTime<<"\n";
	  sim::post(eatTime, [=,&nOccupied](){
	    sim::log()<< " Customer " << id << " finishes.\n";
	    --nOccupied;
	  });
	}
      });
    }
  }
  sim::processAll();
}
