#include <simplecpp>

class Formula{
protected:
  double width, height, ascent, descent;
public:
  virtual void setSizes()=0;
  virtual void draw(double x, double y)=0;
  double getWidth(){return width;}
  double getHeight(){return height;}
  double getDescent(){return descent;}
  double getAscent(){return ascent;}
};

class Formula2: public Formula{
protected:
  Formula *L, *R;
};

class Sum: public Formula2{
public:
  Sum(Formula* l, Formula* r){ L =l; R=r;}
  void setSizes(){
    L->setSizes();
    R->setSizes();
    width = L->getWidth() + textWidth(" + ") + R->getWidth();
    descent = max(L->getDescent(), R->getDescent());
    ascent = max(L->getAscent(), R->getAscent());
    height = ascent + descent;
  }
  void draw(double x, double y){
    L->draw(x, y + ascent - L->getAscent());
    R->draw(x + L->getWidth() + textWidth(" + "), 
	      y + ascent - R->getAscent());
    Text(x + L->getWidth() + textWidth(" + ")/2, y + ascent,
	 string(" + ")).imprint(); // draw the '+' symbol
  }
};

class Ratio: public Formula2{
  static const int h_bar = 10;
public:
  Ratio(Formula* l, Formula* r){ L = l; R = r;}
  void setSizes(){
    L->setSizes();
    R->setSizes();
    width = max(L->getWidth(), R->getWidth());
    ascent = h_bar/2 + L->getHeight();
    descent = h_bar/2 + R->getHeight();
    height = ascent + descent;
  }
  void draw(double x, double y){
    L->draw(x + width/2 - L->getWidth()/2, y);
    R->draw(x + width/2 - R->getWidth()/2, y + L->getHeight() + h_bar);
    Line(x, y + ascent, x + width, y + ascent).imprint(); // horizontal bar
  }
};

class Literal : public Formula{
  string value;
public:
  Literal(string v){value=v;}
  void setSizes(){
    width = textWidth(value);
    height = textHeight(); ascent = descent = height/2;
  }
  void draw(double x, double y){
    Text(x+width/2,y+height/2,value).imprint();
  }
};

class Exp : public Formula2{
public:
  Exp(Formula* l, Formula* r){ L = l; R = r;}
  void setSizes(){
    L->setSizes();
    R->setSizes();
    width = L->getWidth() + R->getWidth();
    descent = L->getDescent();
    ascent = L->getAscent() + R->getHeight() - textHeight()/2;
    height = ascent + descent;
  }
  void draw(double x, double y){
    L->draw(x, y + R->getHeight() - textHeight()/2);
    R->draw(x + L->getWidth(), y);
  }
};

int main(){
  initCanvas("Formula drawing");

  Ratio f(new Sum(new Exp(new Literal("x"), new Literal("2")), 
		  new Literal("y")),
	  new Sum(new Literal("x"),
		  new Exp(new Literal("y"), new Literal("23"))));

  f.setSizes();
  f.draw(200,300);

  getClick();

}
