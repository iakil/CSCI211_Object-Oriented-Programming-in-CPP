/*
akil bhuiyan
prof. cong chen
cs211-HW16
*/

#include <iostream>
using namespace std;

class Rat
{
  public:
    int n;
    int d;
    Rat(int num, int den)
    {
      n = num;
      d = den;
      for(int i = 1; i < 11; i++)
      {
        if(((n % i) == 0) && ((d % i) == 0))
        {
          n /= i;
          d /= i;
        }
      }
    }
    Rat operator+(Rat right)
    {
      return simplify((n * right.d + right.n * d), (d * right.d));
    }
    Rat operator-(Rat right)
    {
      return simplify((n * right.d - right.n * d), (d * right.d));
    }
    Rat operator*(Rat right)
    {
      return simplify((n * right.n), (d * right.d));
    }
    Rat operator/(Rat right)
    {
      return simplify((n * right.d), (d * right.n));
    }
  private:
    Rat simplify(int num, int den)
    {
      int numerator = num;
      int denominator = den;
      for(int i = 1; i < 11; i++)
      {
        if(((numerator % i) == 0) && ((denominator % i) == 0))
        {
          numerator /= i;
          denominator /= i;
        }
      }
      return Rat(numerator, denominator);
    }
};

ostream& operator<<(ostream& os, Rat val)
{ 
  if(val.n > val.d)
  {
    os << (val.n / val.d) << " and " << val.n - (val.d * (val.n / val.d)) << " / " << val.d;
  }
  else
  {
    os << val.n << " / " << val.d;
  }
  return os;
}

int main() 
{
  Rat rat1 = Rat(6,4);
  Rat rat2 = Rat(3,5);
  Rat rat3 = rat1 + rat2;
  Rat rat4 = rat1 - rat2;
  Rat rat5 = rat1 * rat2;
  Rat rat6 = rat1 / rat2;
  cout << rat1 << endl;
  cout << rat2 << endl;
  cout << rat3 << endl;
  cout << rat4 << endl;
  cout << rat5 << endl;
  cout << rat6 << endl;
}