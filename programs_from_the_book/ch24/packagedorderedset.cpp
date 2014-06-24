#include <simplecpp>

struct Node;

class Set{
  Node *proot;
public:
  Set(){proot=NULL;}
  void insert(int elt);
  bool find(int elt);
};

struct Node{
  Set left, right;
  int value;
  Node(int v){ value = v; }
};

bool Set::find(int elt){
  if(proot == NULL) return false;
  else{
    if(elt == proot->value) return true;
    else if(elt < proot->value) return proot->left.find(elt);
    else return proot->right.find(elt);
  }
}

void Set::insert(int elt){
  if(proot == NULL){proot = new Node(elt);}
  else{
    if(elt < proot->value) proot->left.insert(elt);
    else proot->right.insert(elt);
  }
}

int main(){
  Set myset;
  myset.insert(40);
  myset.insert(20);
  cout << "Finding 30: " << myset.find(30) << endl;
  myset.insert(60);
  myset.insert(30);
  cout << "Finding 30: " << myset.find(30) << endl;
}

