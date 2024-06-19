#include <deque>
#include <iostream>

using namespace std;

int main()
{
    deque<int> que;

    que.push_front(1);
    que.push_front(2);
    que.push_front(3);

    cout<<que.front()<<endl;
     
    return 0;
}