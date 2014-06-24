#include <simplecpp>
#include <assert.h>
#include <fstream>
#include <sstream>

struct City;       // forward declaration, not definition.
struct Road{
  City*  toPtr;    // Where the road leads to
  double length;
  Road(City* ptr, double d){toPtr = ptr; length = d;}
};

struct City{
  vector<Road> roads;
  double arrivalT;                  // arrival time of first cyclist
  City(){arrivalT = HUGE_VAL;}    // not arrived yet.
  void arrive(){
    if(arrivalT > sim::getTime()){
      arrivalT = sim::getTime();
      for(unsigned int i=0; i<roads.size(); i++){
        sim::post(roads[i].length, [this,i](){roads[i].toPtr->arrive();});
      }
    }
  }
};

struct RoadNetwork{
  vector<City> cities;
  RoadNetwork(char* infilename) {
    ifstream infile(infilename);
    int n;
    infile >> n;
    cities.resize(n);
    double dist;
    int end1, end2;
    while(infile >> end1){
      infile >> end2 >> dist;
      cities[end1].roads.push_back(Road(&cities[end2],dist));
      cities[end2].roads.push_back(Road(&cities[end1],dist));
    }
  }
};

int main(int argc, char** argv){
  RoadNetwork G(argv[1]);         // create road network from file
  int origin;                     // city from which distances are needed
  stringstream(argv[2]) >> origin;

  // cause the fictitious cyclist to arrive.
  sim::post(0, [&G,origin](){G.cities[origin].arrive();});  
  sim::processAll();

  for(unsigned i=0; i<G.cities.size(); i++) 
    cout << G.cities[i].arrivalT << " ";  // arrivalD = distance from origin
  cout << endl;
}

