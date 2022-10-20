/*
 *
 * Note: Try to solve this task in-place (with O(1) additional memory),
 * since this is what you'll be asked to do during an interview
 *
 * You are given an n x n 2D matrix that represents an image.
 * Rotate the image by 90 degrees (clockwise).
 *
 * a = [[1, 2, 3],
 *      [4, 5, 6],
 *      [7, 8, 9]]
 *
 * solution(a) =
 *     [[7, 4, 1],
 *      [8, 5, 2],
 *      [9, 6, 3]]
 *
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

vector<vector<int>> solution(vector<vector<int>> a)
{   int n = a.size(); // Set n to Vector Length 
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            std::swap(a[i][j], a[j][i]);
        }
    }
    
    for(int i = 0; i < n; i++){
        reverse(a[i].begin(), a[i].end());
    }
    
    return a;
}

int main(){
    vector<int> a = [[1, 2 ,3],
                     [4, 5, 6],  
                     [7, 8, 9]];
}