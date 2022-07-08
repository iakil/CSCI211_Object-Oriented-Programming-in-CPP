/*
akil bhuiyan
prof. cong chen
cs211-HW99
*/

#include <iostream>
#include <vector>
using namespace std;

typedef bool (*FUNC)(int, int);

vector<int> filter(vector <int> vec, FUNC f, int n);
bool above(int n, int m);
bool below(int n, int m);
bool divby(int n, int m);

int main() 
{
  vector<int> vec;
  srand(time(NULL));
  for(int i = 0; i < 10; i++)
  {
    vec.push_back(rand());
  }
  vector<int> vec1 = filter(vec, above, 5);
  vector<int> vec2 = filter(vec, below, 5);
  vector<int> vec3 = filter(vec, divby, 5);
}

vector<int> filter(vector<int> vec, FUNC f, int n)
{
  vector<int> tempvec;
  for(int i = 0; i < vec.size(); i++)
  {
    if(f(vec.at(i), n))
    {
      tempvec.push_back(vec.at(i));
    }
  }
  return tempvec;
}

bool above(int n, int m)
{
  return n > m;
}

bool below(int n, int m)
{
  return n < m;
}

bool divby(int n, int m)
{
  return n % m == 0;
}