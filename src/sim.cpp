#include "sim.h"

namespace simplecpp{
#ifdef __linux__
double sim::time = 0;
priority_queue< sim::ETpair, vector<sim::ETpair>, sim::compareETpair> sim::pq;
#endif
}
