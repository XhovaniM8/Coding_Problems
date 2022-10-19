#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
        string binary_a = std::bitset<4>(a).to_string(); //to binary
        string binary_b = std::bitset<4>(b).to_string(); //to binary
        string calculation = binary_a + binary_b;

        return calculation;
    }  
};

int main(){
    Solution s;

    cout << s.addBinary("11", "1") << endl;
}