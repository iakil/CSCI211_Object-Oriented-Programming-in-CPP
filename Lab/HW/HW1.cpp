/*
akil bhuiyan
prof. cong chen
cs211-HW1
*/

#include <iostream>
using namespace std;

int main() 
{
  int temp = 0;
  /*the loop starts at 4 because 16 is the first perfect square in which there is at least 2 digits to check for and ends at 50 because after that, the last 2 digits of every square will repeat after 51 (i.e 50 * 50 = 2500, 51 * 51 = 2601, 52 * 52 = 2704 same last digits as 0^2 1^2 and 2^2 and so on)*/
  for(int i = 4; i < 51; i++)
  {
    temp = i * i;
    if(((temp / 10) % 2) != 0 && ((temp % 10) % 2)  != 0)//check if last 2 digits are odd
    {
      cout << "The first perfect square whose last two digits are odd is: " << temp << endl;
      break;
    }
  }
  cout << "there is no perfect square whose last 2 digits are odd";
  return 0;
}