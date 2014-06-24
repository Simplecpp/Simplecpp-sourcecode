#include <simplecpp>

const int QUEUESIZE = 100;
struct Queue{
  int elements[QUEUESIZE], nWaiting, front;
};

bool insert(Queue &q, int value){
  if(q.nWaiting >= QUEUESIZE) return false;  // queue is full
  q.elements[(q.front + q.nWaiting) % QUEUESIZE] = value;
  q.nWaiting++;
  return true;
}
bool remove(Queue &q, int &item){
  if(q.nWaiting == 0) return false; // queue is empty
  item = q.elements[q.front]; 
  q.front = (q.front + 1) % QUEUESIZE;
  q.nWaiting--;
  return true;
}

int main(){
  Queue q;
  q.front = 0;
  q.nWaiting = 0;
  while(true){
    char command; cin >> command;
    if(command == 'd'){
      int driver; 
      cin >> driver;
      if(!insert(q, driver)) cout << "Queue full.  Cannot register.\n";
    }
    else if(command == 'c'){
      int driver;
      if (!remove(q, driver)) cout << "No taxi available.\n";
      else cout << "Assigning: " << driver << endl;
    }
    else if(command == 'x') break;
  }
}
