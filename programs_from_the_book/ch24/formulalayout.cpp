#include <simplecpp>
#include <string>
#include <fstream>
#include <sstream>

struct Node{
  static const int h_bar = 10; // space for horizontal bar
  Node *L, *R;
  char op;
  string value;
  double width, height, ascent, descent;
  Node(string v);
  Node(char op1, Node* L1, Node* R1);
  Node(istream& infile);
  void setSizes();
  void draw(double clx, double y); // to actually draw
};

Node::Node(string v){                        // primitive constructor
  value = v;
  op = 'P';   // convention: 'P' in op denotes primitive formula.
  L = NULL;
  R = NULL;
}

Node::Node(char op1, Node* L1, Node* R1){  // recursive constructor
  value = "";
  op    = op1;
  L   = L1;
  R   = R1;
}

Node::Node(istream &infile){
  char c=infile.get();
  if((c >= '0' && c <= '9') ||     // is it a primitive formula?
     (c >= 'a' && c <= 'z') ||
     (c >= 'A' && c <= 'Z')){
    L=R=NULL; op='P'; value = c;
  }
  else if(c == '('){              // does it start a non-primitive formula?
    L = new Node(infile);            // recursively get the L formula
    op = infile.get();                 // get the operator
    R = new Node(infile);            // recursively get the R formula
    if(infile.get() != ')') 
      cout << "No matching parenthesis.\n";
  }
  else cout << "Error in input.\n";
}

void Node::setSizes(){
  switch (op){
  case 'P': 	              // Primitive formula
    width = textWidth(value); 
    height = textHeight(); ascent = descent = height/2;
    break;
  case '+':                  // case L+R
    L->setSizes(); 
    R->setSizes();
    width = L->width + textWidth(" + ") + R->width;
    descent = max(L->descent, R->descent);
    ascent = max(L->ascent, R->ascent);
    height = ascent + descent;
    break;
  case '/':                 // case L/R
    L->setSizes(); 
    R->setSizes();
    width = max(L->width, R->width);
    ascent = h_bar/2 + L->height;
    descent = h_bar/2 + R->height;
    height = ascent + descent;
    break;
  default: cout << "Invalid input.\n";
  }
}

void Node::draw(double xF, double yF){
  switch(op){
  case 'P': 
    Text(xF + width/2, yF + ascent, value).imprint();
    break;
  case '+':
    L->draw(xF, yF + ascent - L->ascent);
    R->draw(xF + L->width + textWidth(" + "), yF + ascent - R->ascent);
    Text(xF + L->width + textWidth(" + ")/2, yF + ascent, 
         string(" + ")).imprint();    // draw the '+' symbol
    break;
  case '/':
    L->draw(xF + width/2 - L->width/2, yF);
    R->draw(xF + width/2 - R->width/2, yF + L->height + h_bar);
    Line(xF, yF + ascent, xF + width, yF + ascent).imprint();  // horizontal bar
    break;
  default: cout << "Invalid input.\n";
  }
}


int main(){
  initCanvas("Formula drawing");

  Node e('+', new Node("1"), 
	 new Node('/', new Node("2"), 
		  new Node('+', new Node('/', new Node("451"),new Node("5")),
			   new Node("35"))));

  e.setSizes();
  e.draw(50,50);

  Node g(cin);
  g.setSizes();
  g.draw(250,50);

  getClick();
}
