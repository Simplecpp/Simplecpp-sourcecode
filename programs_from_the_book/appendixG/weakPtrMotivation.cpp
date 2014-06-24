#include <simplecpp>
#include <memory>

struct A{
  shared_ptr<A> aptr;
  A(){cout << "Creating A: "<< this << endl;}
  ~A(){cout << "Deleting A: "<< this << endl;}
};

int main(){
  shared_ptr<A> s1(new A), s2(new A);                     // Group 1
  s1->aptr = s2;
  s2->aptr = s1;
  cout 	<< s1.use_count() << " " << s2.use_count() << " " 
	<< s1->aptr.use_count() << " " << s2->aptr.use_count() 
	<< endl << endl;

  s2 = NULL;
  cout << s1.use_count() << " " << s2.use_count() << " " 
       << s1->aptr.use_count() << endl << endl;        

  s1 = NULL;                                             // Group 3
  cout << s1.use_count() << " " << s2.use_count() << endl << endl;
}
