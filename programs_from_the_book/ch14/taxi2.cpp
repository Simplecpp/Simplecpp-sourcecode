#include <simplecpp>
int main(){
  const int n = 100; // estimate of max waiting drivers.
  int driverID[n], nWaiting = 0, front = 0;

  while(true){ /* Invariants: nWaiting denotes the number of waiting drivers.  
		  0 <= nWaiting <= n.  IDs of waiting drivers are in driverID,
		  from driverID[front] to driverID[(front + nWaiting - 1) %n ].
		  0 <= front < n
	       */
    char command; cin >> command;
    if(command == 'd'){                           // driver arrives
      if(nWaiting >= n) cout << "Queue full.  Try later.\n";
      else{
	cin >> driverID[(front + nWaiting) % n];
	nWaiting++;
      }
    }
    else if(command == 'c'){                     // customer arrives
      if(nWaiting == 0) cout << "Nothing available.  Try later.\n";
      else{
	cout << "Assigning " << driverID[front] << endl;
	front = (front + 1) % n;
	nWaiting--;
      }
    }
    else if(command == 'x') break;
    else cout << "Illegal command.\n";
  }
}
