#include <simplecpp>
#include <string>
#include <memory>

class Exp;
typedef shared_ptr<Exp> spE;

class Exp{
  spE lhs, rhs;
  string value;
  char op;
public:
  Exp(string s): value(s), op('P') {cout << "Created "<< s<< endl;}
  Exp(char o, spE l, spE r): lhs(l), rhs(r), op(o) {
    cout << "Created exp with op "<< o << endl;
  }
  ~Exp(){
    if(op == 'P') cout <<"Deleting "<<value<<endl;
    else cout <<"Deleting exp with op "<< op << endl;
  }
};
spE literal(string s){return spE(new Exp(s));}
spE formula(char o, spE l, spE r){return spE(new Exp(o,l,r));}

int main(){
  spE e1 = literal("100");                    cout <<"e1 created.\n";
  spE e2 = formula('+', e1, literal("200"));  cout <<"e2 created.\n";
  spE e3 = formula('*', e2, e1);              cout <<"e3 created.\n";
  e2 = literal("300");                        cout <<"e2 modified.\n";
  e3 = e1;                                    cout <<"e3 modified.\n";
}
