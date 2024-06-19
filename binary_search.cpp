#include <iostream>
#include <vector>

using namespace std;

int binary_search(const vector<int>& vec, int target)
{
    int left = 0;
    int right = vec.size() - 1;

    while(left <= right)
    {
        int mid = left + (right - left)/2;

        if(vec[mid] > target)
        {
            right = mid - 1;
        }else if(vec[mid] < target)
        {
            left = mid + 1;
        }else
        {
            return mid;
        }
    }

    return -1;
}

//1,2,3,5,6,7
int binary_search_insert(const vector<int>& vec, int target)
{
    int left = 0;
    int right = vec.size() - 1;

    while(left <= right)
    {
        int mid = left + (right - left) /2;
        if(vec[mid] > target)
        {
            right = mid - 1;
        }else if(vec[mid] < target)
        {
            left = mid + 1;
        }else
        {
            return mid;
        }
    }

    return left;
}

int main()
{
    vector<int> test{1,2,3,4,6};
    //cout<<binary_search(test, 4)<<endl;

    cout<<binary_search_insert(test, 5)<<endl;
    return 0;
}