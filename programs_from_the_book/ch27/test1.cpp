#include <simplecpp>

int main(){
  int count=0;
  sim::post(15, [&](){sim::log() << "A. count "<< count++ <<endl;});
  sim::post(5, [&](){sim::log() << "B. count "<< count++ <<endl;});
  sim::post(10, [&](){
    sim::log() << "C. count "<< count++ <<endl;
    sim::post(100, [&](){sim::log() << "D. count: "<<
			    count++ << endl;});
  });
  sim::processAll();
}
