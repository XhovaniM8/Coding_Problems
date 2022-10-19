#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;

/*  
*   Templates allow you to write a class or function that can be used with different data types.
*/

template<class T>
class Data 
{
    private: 

        T x;

    public:

        T getX() {
            return x;
        }

        void setX(T newx){
            x = newx;
        }
};

int main()
{
    Data<int> d;
    d.setX(10);

    cout << d.getX() << "\n"; 

    Data<std::string> d2;
    d2.setX("Yanks");

    cout << d2.getX() << "\n"; 

}

