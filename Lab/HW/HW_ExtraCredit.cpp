/*
akil bhuiyan
prof. cong chen
cs211-HW_ExtraCredit
*/

#include <iostream>

using namespace std;

int countZeros(string num);

int main() 
{
  string num;
  cout << "Please enter a number: \n";
  cin >> num;
  cout << "There are " << countZeros(num) << " number 0s in that number\n";
}

int countZeros(string num)
{
  //check for end of the string
  return (num.length() > 0 ? (num.at(0) == '0') + countZeros(num.substr(1)) : 0);

  /*if(num.length() > 0)
    return (num.at(0) == '0') + countZeros(num.substr(1));
  return 0;*/
}