#include <iostream>

using namespace std;

struct ListNode
{
    ListNode* next;
    int val;
    ListNode(int x):val(x), next(nullptr){};
};

class Stack 
{
private:
   ListNode* m_stackTop;
   int m_size;
public:
   Stack();
   Stack(int val);
   void push(int value);
   int size();
   void pop();
   int top();
   bool isEmpty();
};

Stack::Stack()
{
    m_stackTop = nullptr;
    m_size =0;
}

int Stack::size()
{
    return m_size;
}

bool Stack::isEmpty()
{
    return (this->size() == 0);
}

void Stack::push(int val)
{
    auto node = new ListNode(val);
    node->next = m_stackTop;
    m_stackTop = node;
    m_size++;
}

void Stack::pop()
{
    if(isEmpty())
    {
        std::cout << "stack is empty"<<std::endl;
        return;
    }
    auto tmp = m_stackTop;
    m_stackTop = m_stackTop->next;
    m_size--;
    delete tmp;
}

int Stack::top()
{
    if(isEmpty())
    {
        std::cout << "stack is empty"<<std::endl;
        return -1;
    }

    return m_stackTop->val;
}

int main()
{
    auto stack = new Stack();
    std::cout<<stack->size()<<std::endl;
    stack->push(1);
    stack->push(2);
    std::cout<<stack->size()<<std::endl;

    std::cout<<stack->top()<<std::endl;

    stack->pop();
       std::cout<<stack->top()<<std::endl;


    return 0;
}
