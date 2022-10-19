#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

int solution(vector<int> inputArray) {

    int maxProduct = -2147483647;
    
    if (inputArray.size() == 1){
        return 0;
    }
    
    for (int i = 0; i < inputArray.size(); ++i){
        maxProduct = std::max(maxProduct, inputArray[i] * inputArray[i - 1]);
    }
    
    return maxProduct;
}


int main() {
    
    vector<int> arr = {3, 6, -2, -5, 7, 3};
    solution(arr);

}