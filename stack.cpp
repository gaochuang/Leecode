#include <iostream>

using namespace std;

int sum(int a)
{

    std::cout << "a is " << a << std::endl;
    if(1 == a)
    {
        return 1;
    }


    return a + sum(a-1);
}

int main()
{
    int a = sum(10);

    cout << "sum is " << a << endl;
    return 0;
}
