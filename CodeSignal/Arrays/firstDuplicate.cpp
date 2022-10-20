#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

int my_solution(vector<int> a)
{

    for (int i = 0; i < a.size(); i++)
    {
        int index = abs(a[i]) - 1;

        if (index < 0)
        {
            return abs(a[i]);
        }
        else
        {
            index = -index;
        }
    }

    return -1;
}

int solution(vector<int> a)
{

    int duplicate = -1;
    cout << a.size();

    // iterate through array and test for duplicates:
    for (int i = 0; i < a.size(); i++)
    {
        // hold current number and it's abs val:
        int currentNum = a[i];
        int absCurr = abs(currentNum) - 1;

        // check if the slot indexed by currentNum is positive,
        // if so, it hasn't been seen, so flip it:
        if (a[absCurr] > 0)
        {
            a[absCurr] = -a[absCurr];
        }
        // if it's negative, it's been seen, return it:
        else
        {
            return abs(a[i]);
        }
    }

    return duplicate;
}

int main()
{
    vector<int> a = {2, 1, 3, 5, 3, 2};
    solution(a);
}