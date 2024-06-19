#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val):val(val),next(nullptr){}
}

Class MyQueue
{
private:
    ListNode *m_pre, *m_rear;
    int m_size;
public:
    Myqueue();
    bool empty();
    void push(int num);
    int pop();
    int peek();
};

MyQueue::MyQueue():m_pre(nullptr),m_rear(nullptr),m_size(0)
{

}

bool MyQueue::empty()
{
    return (m_size == 0);
}

void MyQueue::push(int num)
{
    ListNode* newNode = new ListNode(val);
    if(empty())
    {
        m_pre = newNode;
        m_rear = newNode;
    }else
    {
        m_rear->next = newNode;
        m_rear = newNode;
    }
}

int MyQueue::peek()
{
    int val = peek();

    ListNode* tmp = front;

    front = front->next;

    delete tmp;

    m_size--;
    return val;

}

int MyQueue::pop()
{
    int val = peek();

    ListNode* tmp = front;

    front = front->next;

    delete tmp;

    m_size--;
    return val;
}

int main()
{

}
