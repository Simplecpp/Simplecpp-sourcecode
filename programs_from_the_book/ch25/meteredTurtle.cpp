#include <simplecpp>

class mTurtleI : public Turtle{
  float distance;
public:
  mTurtleI(){
    distance = 0;    
  }
  void forward(float d){
    distance += abs(d);   // 
    Turtle::forward(d);
  }
  float distanceCovered(){
    return distance;
  }
};

main_program{
  initCanvas("Distance Counting turtle");
  mTurtleI mt;

  mt.forward(100);
  mt.left(90);
  mt.forward(100);
  mt.left(90);
  mt.Turtle::forward(50);
  cout << mt.distanceCovered() << endl;
  wait(5);
}  
