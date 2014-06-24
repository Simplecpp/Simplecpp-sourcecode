#include <simplecpp>

class matrix{
  vector<vector<double> > elements;
public:
  matrix(size_t m, size_t n) : elements(m, vector<double>(n)){}
  double &operator()(size_t i, size_t j){return elements[i][j];}
  size_t nrows(){return elements.size();}
  size_t ncols(){return elements[0].size();}
};

int main(){
  matrix D(10,10);         // 10 x 10 matrix

  for(size_t i=0; i<D.nrows(); i++){
    for(size_t j=0; j<D.ncols(); j++)
      D(i,j) = (i==j);     // access i,j th element
  }

  for(size_t i=0; i<D.nrows(); i++){
    for(size_t j=0; j<D.ncols(); j++)
      cout << D(i,j) <<' ';
    cout << endl;
  }
}
