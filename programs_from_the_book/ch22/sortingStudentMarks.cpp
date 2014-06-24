#include <simplecpp>
#include <algorithm>

struct student{
  int rollno;
  float physics, math, chemistry;
  bool operator<(const student& rhs) const{ // used by the sort function
    return rollno < rhs.rollno;             // note the two const keywords
  }
};

void print(vector<student> &svec){
  for(unsigned i=0; i<svec.size(); i++)
    cout << svec[i].rollno << ") "<< svec[i].physics <<' '
	 << svec[i].math <<' '<< svec[i].chemistry << endl;
}

bool compareMarksFunction(const student& a, const student& b){
  return a.math < b.math;
}

struct compareRollnoStruct{
  bool operator() (const student& a, const student& b){
    return a.chemistry < b.chemistry;
  }
};

int main(){
  vector<student> svec;

  student s;
  while(cin >> s.rollno){
    cin >> s.physics >> s.math >> s.chemistry;
    svec.push_back(s);
  }

 sort(svec.begin(), svec.end());         // will use operator<
 print(svec);

 sort(svec.begin(), svec.end(), 
      [](const student& a, const student& b){ return a.physics < b.physics;});
 print(svec);

 sort(svec.begin(), svec.end(), compareMarksFunction);
 print(svec);

 sort(svec.begin(), svec.end(), compareRollnoStruct());
 print(svec);

}
