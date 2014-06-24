#include <simplecpp>

struct Person{
  string name;
  vector<int> friends;
};


int main(){
  Person persons[5];
  persons[0].name = "Harry";
  persons[1].name = "Hermione";
  persons[2].name = "Ron";
  persons[3].name = "Draco";
  persons[4].name = "Crabbe";

  persons[0].friends.push_back(1);   persons[1].friends.push_back(0); 
  persons[0].friends.push_back(2);   persons[2].friends.push_back(0); 

  for(unsigned i=0; i<persons[0].friends.size(); i++)
    cout << persons[persons[0].friends[i]].name << endl;

}
