#include <iostream>
#include <stack>

class CQueue 
{
private:
    std::stack<int> s1;
    std::stack<int> s2;

public:
    CQueue() 
    {
        ;
    }
    
    void appendTail(int value) 
    {
        while (s2.size() != 0)
        {
            s1.push(s2.top());
            s2.pop();
        }

        s1.push(value);
        
    }
    
    int deleteHead() 
    {
        while (s1.size() != 0)
        {
            s2.push(s1.top());
            s1.pop();
        }

        int retVal;
        if (s2.size() > 0)
        {
            retVal = s2.top();
            s2.pop();
        }
        else
        {
            retVal = -1;
        }


        return retVal;
    }
};

int main()
{
    CQueue* obj = new CQueue();
    obj->appendTail(2);
    int param_2 = obj->deleteHead();
    std::cout << param_2;
    param_2 = obj->deleteHead();
    std::cout << param_2;

    return 0;
}