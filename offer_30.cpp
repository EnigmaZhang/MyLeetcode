#include <iostream>
#include <stack>

class MinStack 
{
public:
    MinStack() 
    {

    }

    void push(int x) 
    {
        numStack.push(x);
        if (minStack.size() != 0)
        {
            if (x < minStack.top())
            {
                minStack.push(x);
            }
            else
            {
                minStack.push(minStack.top());
            }
        }
        else
        {
            minStack.push(x);
        }
    }

    void pop() 
    {
        numStack.pop();
        minStack.pop();
    }

    int top() 
    {
        return numStack.top();
    }

    int min() 
    {
        return minStack.top();
    }
private:
    std::stack<int> numStack;
    std::stack<int> minStack;
};

int main()
{
    MinStack solution = MinStack();

    solution.push(-2);
    solution.push(0);
    solution.push(-3);
    std::cout << solution.min() << std::endl;
    solution.pop();
    std::cout << solution.top() << std::endl;
    std::cout << solution.min() << std::endl;
    return 0;
}