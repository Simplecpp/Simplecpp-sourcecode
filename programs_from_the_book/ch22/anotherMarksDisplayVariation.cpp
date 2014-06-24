#include <simplecpp>
#include <fstream>
#include <sstream>
#include <map>

struct Marks{
  double science, math, sanskrit;
};

int main(){
  ifstream infile("students.txt");
  map<string,Marks> mark_map;

  Marks m;
  string name;

  while(getline(infile,name,',')){
    string s;
    getline(infile,s,','); 
    stringstream (s) >> m.math;
    getline(infile,s,','); 
    stringstream (s) >> m.science;
    infile >> m.sanskrit;   // read directly, not comma terminated
    getline(infile,s);      // discard the end of the line character

    mark_map[name] = m;     // store the structure into the map
  }

  while(getline(cin,name)){
    if(mark_map.count(name)>0)
      cout << mark_map[name].math << " " << mark_map[name].science
           << " " << mark_map[name].sanskrit  << endl;
    else
      cout << "Invalid name.\n";
  }
}
