#include <iostream>
#include <string>
#include <stack>

using namespace std;

string process(string s)
{
    string ret = s;
    int slow  = 0;

    for(int fast = 0; fast < ret.length(); fast++)
    {
        if(s[fast] != '#')
        {
            ret[slow++] = s[fast];
        }else
        {
            if(slow > 0)
            {
                slow--;
            }
        }
    }

    return ret.substr(0, slow);
}
bool backspaceCompare(string s, string t)
{
    return process(s) == process(t);
}

int main()
{
 
 cout << backspaceCompare("a#c", "b") << endl;

 return 0;
}
