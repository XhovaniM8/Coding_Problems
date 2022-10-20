/*
 *
 * Given a string s consisting of small English letters,
 * find and return the first instance of a non-repeating character in it.
 * If there is no such character, return '_'.
 *
 * For s = "abacabad", the output should be solution(s) = 'c'.
 * For s = "abacabaabacaba", the output should be solution(s) = '_'.
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

using std::cout;
using std::endl;
using std::string;
using std::vector;

char solution(string s)
{
    std::list<char> unique_char;
    int alphabet[27] = {0};
    int stringLength = s.length();

    for (auto i : s)
    {
        int char_index = i - 'a';
        if (++alphabet[char_index] == 1)
        {
            unique_char.push_back(i);
        }
    }

    for (auto i : unique_char)
    {
        int char_index = i - 'a';
        if (alphabet[char_index] == 1)
            return i;
    }

    return '_';
}

int main()
{
    string a = "abacabad";
    string b = "abacabaabacaba";
    
    cout << solution(a) << endl;
    if (solution(a) == 'c'){
        cout << "Correct" << endl;
    } else {
        cout << "Something is wrong" << endl;
    }

    cout << solution(b) << endl;
    if (solution(b) == '_'){
        cout << "Correct" << endl;
    } else {
        cout << "Something is wrong" << endl;
    }
}