#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getBingoNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY mat
 *  2. INTEGER_ARRAY arr
 */

int getBingoNumber(vector<vector<int>> mat) {
    
    int BingoNumber;
    
    int n = 0;
    int m = 0;
    
    cout << "Input 'n' for the row size" << "\n";
    cin >> n; 
    
    cout << "Input 'm' for the column size" << "\n";
    cin >> m; 
    
    mat.resize(n, vector<int>(m)); // Resizes vector so that it contains elements n x m.
    
    cout << "The Vector Elements are : ";
    for (int i = 0; i < mat.size(); i++){
        cout << i << ' '; // I don't know why << doesn't here
    }
    
    return BingoNumber; // Returning Int
}

int main(){

    getBingoNumber();

}
