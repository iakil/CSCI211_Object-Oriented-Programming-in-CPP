/*
akil bhuiyan
prof. cong chen
cs211-HW-13
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> vec[3];
    cout << "Enter a number of rings : \n";
    int x;
    cin >> x;
    vec[1].push_back(x + 1);
    vec[2].push_back(x + 1);

    for (int i = x + 1; i >= 1; --i)
    {
        vec[0].push_back(i);
    }

    int from = 0, d = 1, to = 2, candidate = 1, move = 1;

    if (x % 2 == 1)
    {
        d = 2;
        to = 1;
    }

    while (vec[1].size() < x + 1)
    {
        cout << "# " << move++ << " : ring # " << candidate << " move from " << char(from + 65) << " --> " << char(to + 65) << endl; // char 'A' ascii 65

        vec[to].push_back(vec[from].back());
        vec[from].pop_back();

        if (vec[(to + 1) % 3].back() < vec[(to + 2) % 3].back())
        {

            from = (to + 1) % 3;
            candidate = vec[from].back();
        }
        else
        {
            from = (to + 2) % 3;
            candidate = vec[from].back();
        }

        if (vec[(from + to) % 3].back() > vec[from].back())
        {
            to = (from + to) % 3;
        }
        else
        {
            to = (from + d) % 3;
        }

    } // while

    return 0;
}