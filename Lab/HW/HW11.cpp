/*
akil bhuiyan
prof. cong chen
cs211-HW11
*/

#include <iostream>
#include <string>
using namespace std;

string add(string a, string b);

int main()
{
    string a, b;
    while (true)
    {
        cout <<"Please enter 2 numbers that you would like to add or type \"done\" if you want to exit\n";
        cin >> a; //get a
        if (!a.compare("done"))//check if user wants to exit
        {
            return 1;
        }
        cin >> b; //get b
        cout << "The sum of those two numbers is: " << add(a, b) << endl;
    }
    return 0;
}

string add(string a, string b)//adds two large quantities
{
  
  //check which number is bigger in length and which is smaller
    string longer = (a.size() > b.size() ? a : b); //check if "a" is bigger and if so set "a" as the longest number to be working with
    string shorter = (a.size() > b.size() ? b : a); //check if "a" is bigger and if so set "b" as the shortest number to be working with
    int s = shorter.size();
    string sum = "";

    int cached = 0; //cached and cached 2 will be used as a way to "carry" numbers over in case the sum of 2 ints is bigger than 9
    int cached2 = 0; //cached will have the role of carrying the ones place, unless there is a need for carrying a number in the 1s and 10s place in which case cached 2 will take the place of the 1s and cached that of the 10s place

    //if a number is bigger than the other, to prevent out of bounds exceptions, we will add 0s to the left of the smaller number until they are the same length
    for(int i = 0; i < longer.size() - s; i++)
    {
        shorter = "0" + shorter;
    }

    for(int i = (shorter.size() - 1); i >= 0; i--)
    {

      //check if after adding the 2 digits plus whatever we carried over(cached) there would be a number carried over. If there is no number carried over, proceed with the sum and set the number being carried over as 0
        if (stoi(shorter.substr(i, 1)) + stoi(longer.substr(i, 1)) + cached < 10 && i != 0)
        {
            sum = to_string(stoi(shorter.substr(i, 1)) + stoi(longer.substr(i, 1)) + cached) + sum;
            cached = 0;
        }

        //Otherwise if there would be a number carried over, first, use cached2 as the one's place, and cached would become the 10s place that will be carried over in the next iteration
        else if(i != 0)
        {
            cached2 = cached; //make cached2 the 1s place digit
            cached = (stoi(shorter.substr(i, 1)) + stoi(longer.substr(i, 1)) + cached2) / 10;//make cache the 10s place number that we are carrying over
            sum = to_string(((stoi(shorter.substr(i, 1)) + stoi(longer.substr(i, 1)) + cached2) % 10)) + sum;
        }

        //if we have run through all the iterations and we are on the last one, then there is no need to check for numbers carried over, simply write them at the front of our number
        else
            sum = to_string(stoi(shorter.substr(i, 1)) + stoi(longer.substr(i, 1)) + cached) + sum;
    }

    return sum;
}