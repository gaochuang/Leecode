#include <iostream>
#include <vector>

using namespace std;

int numOfSubarrays(vector<int>& arr, int k, int threshold)
{
    int ret  = 0;
    int left = 0;
    int sum = 0;

    for(int right = 0; right < arr.size(); right++)
    {
        sum += arr[right];
        if(right - left + 1 >= k)
        {
            if(sum / k >= threshold)
            {
                ret++;
            }
            sum -= arr[left];
            left++;
        }
    }

    return ret;
}

int main()
{
    vector<int> val{11,13,17,23,29,31,7,5,2,3};
    cout << "num: " << numOfSubarrays(val, 3, 5) << endl;
    return 0;
}