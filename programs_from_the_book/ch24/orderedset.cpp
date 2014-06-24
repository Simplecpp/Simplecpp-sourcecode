#include <simplecpp>

struct Node{
  Node *left, *right;
  int value;
};

bool find(Node* &pRoot, int elt){
// determines whether elt is present in the tree root pointed to by proot.
  if(pRoot == NULL) return false;
  if(elt == pRoot->value) return true;
  if(elt < pRoot->value) return find(pRoot->left, elt);
  return find(pRoot->right, elt);
}

void insert(Node* &pRoot, int elt){
// insert elt into the tree root pointed to by proot.
  if(pRoot == NULL){
    pRoot = new Node;
    pRoot->left = pRoot->right = NULL;
    pRoot->value = elt;
  }
  else{
    if(elt == pRoot->value) return;
    if(elt < pRoot->value) insert(pRoot->left, elt);
    else insert(pRoot->right, elt);
  }
}

int main(){
  Node* myset=NULL;
  insert(myset,40);
  insert(myset,20);
  cout << "Finding 30: " << find(myset,30) << endl;
  insert(myset,60);
  insert(myset,30);
  cout << "Finding 30: " << find(myset,30) << endl;
}
