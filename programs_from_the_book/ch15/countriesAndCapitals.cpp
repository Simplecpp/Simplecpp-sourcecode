#include <simplecpp>

char compare(char a[], char b[])
// returns '<' if a is smaller, '=' if equal, '>' if b is smaller.
{
  int i = 0;
  while(true){                 // Invariant: a[0..i-1] == b[0..i-1]
    if(a[i] == '\0' && b[i] == '\0') return '=';
    if(a[i] == '\0') return '<';
    if(b[i] == '\0') return '>';
    if(a[i]<b[i]) return '<';
    if(a[i]>b[i]) return '>';
    i++;
  }
}


int main(){
  const int wordLength = 20;
  char countries[6][wordLength] = {"India","China","Sri Lanka","Nepal", 
                           "Bangladesh","Pakistan"};
  char capitals[6][wordLength] = {"New Delhi","Beijing","Colombo","Kathmandu", 
                           "Dhaka","Islamabad"};
  char country[wordLength];
  cout << "Country: ";
  cin.getline(country,wordLength);

  int i;
  for(i=0; i<6; i++){
    if(compare(country,countries[i]) == '='){
            // only one index applied to array countries
      cout << capitals[i] << endl;
      break;
    }
  }
  if(i == 6) cout << "Dont know the capital.\n";
}
