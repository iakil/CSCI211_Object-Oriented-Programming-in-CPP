/*
akil bhuiyan
prof. cong chen
cs211-HW2
*/

#include<iostream>
#include<string>
#include<string.h>
using namespace std;

string add(string a, string b) 
{
/*
add function: which will add 2 string int value from last index to oth in order to achive big int addition.
*/
// "000" this will add 0 in the begining to maintain the same length for both string.
    string d, e;
    
    if (a.length()!=b.length())
    {
        if (a.length()>b.length())
        {
            long c = a.length()-b.length();
            for (long i =0; i<c; i++)
            {
                string x = "0";
                d+=x;
            }
        }
        else
        {
            long c = b.length()-a.length();
            for (long i =0; i<c; i++)
            {
                    string x = "0";
                    e+=x;
            }
        }
    }
    
     b =d+b;
     a=e+a;

     // "000" ^

  string catched_sum,print_sum;
  int num1, num2, index_num1, index_num2, sum, count ;

  num1 = a.length()-1;
  num2 = b.length()-1;
   count = 0;

  while(num1 >= 0 && num2 >= 0) // check if there is any value or null
  {
      index_num1 = 0;
      index_num2 = 0;

    if(num1 >= 0 ) 
    {
        index_num1 = a[num1]-'0'; // ascii chart same as -48 w/ (int) cast
    }

     if(num2 >= 0 ) 
     {
        index_num2 = b[num2]-'0';
    }
    sum = index_num1 +index_num2 +count; // if>10 hold value will be added
    count=0;

    if (sum >9) 
    {
        count = sum/10;
        sum = sum %10;
    }
    print_sum = '0' + sum;
    catched_sum = print_sum + catched_sum;
    num1 = num1-1;
    num2 = num2-1;
  }
  if(count > 0) {
    print_sum = '0'+  count;
    catched_sum = print_sum+ catched_sum;
  }  
    return catched_sum;
}//add


int main() {

  //  string first_big_int = "31111111111111111111119";
  //  string second_big_int = "1";

   string first_big_int = "2345566777844567";
   string second_big_int = "9999988777765768009998";


     cout << first_big_int << " + "<< second_big_int << " = " << add(first_big_int,second_big_int)<< endl; // 2 + 3 = 5

// cout <<first_big_int.length()<<endl<<second_big_int.length()<<endl;
// cout<<add(first_big_int,second_big_int).length()<<endl;
    }//main
