#include <simplecpp>
#include <map>
#include <string>

int main(){
  map<string, double> Population;

  Population["India"] = 1.21;  // population of India is 1.21 billion
  Population["China"] = 1.35;
  Population["Unites States"] = 0.31;
  Population["Indonesia"] = 0.24;
  Population["Brazil"] = 0.19;    

  cout << Population["India"] << " " << Population["Britain"] << endl;

  Population["Britain"]++;

  for(map<string,double>::iterator Pi = Population.begin();
      Pi != Population.end();
      ++Pi)
    cout << Pi->first <<": "<< Pi->second << endl;
  cout << endl;

  map<string,double>::iterator Pi = Population.begin();
  Pi++;
  Population.erase(Pi);

  for(map<string,double>::iterator Pi = Population.begin();
      Pi != Population.end();
      ++Pi)
    cout << Pi->first <<": "<< Pi->second << endl;


  string country;
  while(cin >> country){
    if (Population.count(country)>0)
      cout << Population[country] << endl;
    else cout << country << " not found.\n";
  }
}
