#include <simplecpp>

class verb{
protected:
  string root;
public:
  string getRoot(){return root;}
  virtual string past_tense() = 0;
};

class regular : public verb{
public:
  regular(string rt){
    root = rt;
  }
  string past_tense(){return root + "ed";}
};

class irregular : public verb{
  string pt;
public:
  irregular(string rt, string p){
    root = rt;
    pt = p;
  }
  string past_tense(){return pt;}
};

int main(){
  vector<verb*> V;
  V.push_back(new regular("watch"));
  V.push_back(new regular("play"));
  V.push_back(new irregular("go","went"));
  V.push_back(new irregular("be","was"));

  string request;
  while(cin >> request){
    size_t i;
    for(i=0; i<V.size(); i++)
      if (V[i]->getRoot() == request){
	cout << V[i]->past_tense() << endl;
	break;
      }
    if(i == V.size()) cout << "Not found.\n";
  }
}
