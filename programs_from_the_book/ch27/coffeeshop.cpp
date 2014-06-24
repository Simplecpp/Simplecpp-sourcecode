#include <simplecpp>

int main(){
  const int duration=180;                   // minutes open
  double arrivalP = 0.1, eatMin=3, eatMax=9;
  int id = 0;
  Resource server;
  std::srand(100);

  for(int t=0; t<duration; t++){
    if(randuv(0,1) <= arrivalP){            // with probability arrivalP 
      id++;
      int serviceT = randuv(eatMin, eatMax);
      sim::post(t, [=,&server](){
	sim::log() <<" "<< id << " arrives, service time "<< serviceT <<endl;
	server.acquire([=,&server](){
	  sim::log() << " Customer: " << id << " being served.\n";
	  sim::post(serviceT, [=,&server](){
	    sim::log() << " Customer: " << id << " finishes.\n";
	    server.release();
	  });
	});
      });
    }		    
  }
  sim::processAll();
}
