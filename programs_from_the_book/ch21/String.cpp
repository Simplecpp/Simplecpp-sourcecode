#include <simplecpp>
#include <vector>

int length(const char *s){
  int L;
  for(L=0; s[L] != '\0'; L++){};
  return L;
}
void scopy(char destination[], const char source[], int dstart=0)
  // precondition: '\0' must occur in source.  destination must be long 
  // enough to hold the entire mystring + '\0'.
{
  int i;
  for(i=0; source[i] != '\0'; i++)
    destination[dstart+i]=source[i];
  destination[dstart+i]=source[i];    // copy the '\0' itself
}

class String{
  char* ptr; // will point to address in heap where actual text is stored.
  void * operator new(unsigned int sz);  // disallows "new String"

public:
  String(){ ptr = NULL; }
  String(const String &rhs){
    ptr = new char[length(rhs.ptr)+1];
    scopy(ptr,rhs.ptr);
  }
  String& operator=(const char* rhs){
    delete [] ptr;
    ptr = new char[length(rhs) + 1];
    scopy(ptr,rhs);
    return *this;
  }
  String& operator=(const String &rhs){
    delete [] ptr;
    ptr = new char[length(rhs.ptr) + 1];
    scopy(ptr,rhs.ptr);
    return *this;
  }
  String operator+(const String &rhs) const {
    String res;
    res.ptr = new char[length(ptr) + length(rhs.ptr) + 1];
    scopy(res.ptr, ptr);
    scopy(res.ptr, rhs.ptr, length(ptr));
    return res;
  }
  void print() const {
    if(ptr != NULL) cout << ptr << endl;
    else cout << "NULL" << endl;
  }
  int size()const {return length(ptr);}
  char& operator[](int i) const {return ptr[i];}

};

String lcase(const String &arg){
  String res = arg;
  for(int i=0; i<res.size(); i++)
    if(res[i] >= 'A' && res[i] <= 'Z') res[i] += 'a' - 'A';
  return res;
}

int main(){
  String a,b;
  a = "PQR";
  b = a;
  String c = a + b;  // should concatenate a, b.
  c.print();         // should print on screen

  String d[2];       // array of 2 strings
  d[0] = "Xyz";
  d[1] = lcase(d[0] + c);
  d[1].print();
  d[1][2] = d[0][1];
  d[1].print();
}
