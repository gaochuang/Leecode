#include <iostream>
#include <limits.h>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) 
{
    int left = 0;
    int maxLen = INT_MIN;

    unordered_set<char> set;

    for(int right = 0; right < s.size(); right++)
    {
        auto c = s[right];
        while(set.find(c) != set.end())
        {
            set.erase(s[left]);
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
        set.insert(s[right]);
    }

    return maxLen;
}

int main()
{
    return 0;
}