#include <iostream>

using namespace std;

int mySqrt(int x) 
{
        int left = 0;
        int right = x;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(mid > x/2)
            {
                right = mid - 1;
            }else if(mid < x/2)
            {
                left = mid + 1;
            }else
            {
                return mid;
            }
        }

        return -1;
}

int main()
{
    cout << mySqrt(8) << endl;
    return 0;
}