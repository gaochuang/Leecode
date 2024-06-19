#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortedSquares(vector<int>& nums)
{
    int first = 0;
    int last = nums.size() - 1;
    vector<int> result;
    while(first <= last)
    {
        if(nums[first]*nums[first] < nums[last]*nums[last])
        {
            result.push_back(nums[last]*nums[last]);
            last--;
        }else
        {
            result.push_back(nums[first]*nums[first]);
            first++;
        }
    }

    reverse(result.begin(), result.end());

    return result; 
}

int main()
{
    vector<int> test{-4,-1,0,3,10};
    auto ret = sortedSquares(test);
    for(auto i : ret)
    {
        std::cout << i << " ";
    }
    return 0;
}
