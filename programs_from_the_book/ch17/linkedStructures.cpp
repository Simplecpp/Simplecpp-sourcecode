#include <simplecpp>

struct Student{
  int rollno;
  Student* bestFriend;
};

int main(){
  Student s1, s2, s3;
  s1.rollno = 1;
  s2.rollno = 2;
  s3.rollno = 3;
  s1.bestFriend = &s2;
  s2.bestFriend = &s3;
  s3.bestFriend = &s2;

  cout << s1.bestFriend->rollno << endl;
  cout << s1.bestFriend->bestFriend->rollno << endl;
}
