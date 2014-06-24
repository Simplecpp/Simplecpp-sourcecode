#include <simplecpp>
#include "sim.h"

int main(){
  Resource r;

  sim::post(15, [&](){
    r.acquire([](){sim::log() << "Got it! \n";});
  });

  r.acquire([&](){
    sim::post(20, [&](){ r.release(); });
  });
  sim::processAll();
}
