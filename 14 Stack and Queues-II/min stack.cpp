class MinStack
{
public:
    stack<long long> s;
    long long minEle;
    MinStack()
    {
        minEle = 0;
    }

    void push(int val)
    {
        long long valu = (long long)val;
        if (s.empty())
        {
            s.push(valu);
            minEle = val;
        }
        else if (val < minEle)
        {
            s.push(2 * valu - minEle);
            minEle = valu;
        }
        else
        {
            s.push(valu);
        }
    }

    void pop()
    {
        if (s.top() < minEle)
        {
            minEle = 2 * minEle - s.top();
        }
        s.pop();
    }

    int top()
    {
        if (s.top() < minEle)
        {
            return minEle;
        }
        return s.top();
    }

    int getMin()
    {
        return minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */