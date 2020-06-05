#include<stack>
#include<iostream>
using namespace std;
class MinStack
{
private:
    stack<int>s;
    stack<int>m;
public:
    MinStack();
    void push(int x);
    void pop();
    int top();
    int getMin();
};

MinStack::MinStack() {
    while(!s.empty())
    {
        s.pop();
    }
    while(!m.empty())
    {
        m.pop();
    }
    
}

void MinStack::push(int x) {
    s.push(x);
    if(m.empty())
    {
        m.push(x);
    }
    else
    {
        if(m.top()>=x)
        {
            m.push(x);
        }
    }
}

void MinStack::pop() {
    if(s.empty())
        return;
    else
    {
        if(s.top()==m.top())
        {
            m.pop();
        }
        s.pop();
    }
    
}

int MinStack::top() {
    if(s.empty())
    {
        return -1;
    }
    else
        return s.top();
}

int MinStack::getMin() {
    if(m.empty())
        return  -1;
    else
        return m.top();
}

