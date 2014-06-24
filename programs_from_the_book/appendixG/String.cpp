#include <simplecpp>
#include <vector>
#include <memory>

int length(const char* s){
  int L;
  for(L=0; s[L] != '\0'; L++){};
  return L;
}
int length(const shared_ptr<char> s){ return length(s.get());}

//void scopy(shared_ptr<char> d, const char* source, int dstart=0)
void scopy(char *destination, const char* source, int dstart=0)
  // precondition: '\0' must occur in source.  destination must be long 
  // enough to hold the entire mystring + '\0'.
{
  //  char *destination = d.get();
  int i;
  for(i=0; source[i] != '\0'; i++)
    destination[dstart+i]=source[i];
  destination[dstart+i]=source[i];    // copy the '\0' itself
}

class String{
  shared_ptr<char> ptr; 
public:
  String& operator=(const char* rhs){
    ptr = shared_ptr<char>(new char[length(rhs) + 1]);
    scopy(ptr.get(),rhs);
    return *this;
  }
  String operator+(const String &rhs) const {
    String res;
    res.ptr = shared_ptr<char>(new char[size() + rhs.size() + 1]);
    scopy(res.ptr.get(), ptr.get());
    scopy(res.ptr.get(), rhs.ptr.get(), length(ptr));
    return res;
  }
  void print() const {
    if(ptr != NULL) cout << ptr << endl;
    else cout << "NULL" << endl;
  }
  int size() const {return length(ptr.get());}
  char& operator[](int i) const {return ptr.get()[i];}
  int use_count() const {return ptr.use_count();}
};

int main(){
  String a;
  a = "PQR";
  cout <<"a use count: "<<a.use_count()<<endl;  a.print();

  String b(a);
  cout <<"ab use counts: "<<a.use_count()<<b.use_count()<<endl;    
  a.print(); b.print();

  a = "ABC";
  cout <<"ab use counts: "<<a.use_count()<<b.use_count()<<endl;
  a.print(); b.print();

  b = a;
  cout <<"ab use counts: "<<a.use_count()<<b.use_count()<<endl;    
  a.print(); b.print();

}
