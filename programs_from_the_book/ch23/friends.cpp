#include <simplecpp>

struct Person{
  string name;
  vector<Person*> friends;
};

void makefriends(Person &p, Person &q){ // add an undirected edge in the graph
  p.friends.push_back(&q);  
  q.friends.push_back(&p);
}



int main(){
  Person wizard[5];
  wizard[0].name = "Harry";
  wizard[1].name = "Hermione";
  wizard[2].name = "Ron";
  wizard[3].name = "Draco";
  wizard[4].name = "Crabbe";

  makefriends(wizard[0], wizard[1]);
  makefriends(wizard[2], wizard[1]);
  makefriends(wizard[0], wizard[2]);
  makefriends(wizard[3], wizard[4]);

  for(unsigned i=0; i<wizard[0].friends.size(); i++)
    cout << wizard[0].friends[i]->name << endl;

}
