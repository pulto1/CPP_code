class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        size_t pushi = 0;
        size_t popi = 0;
        stack<int> st;

        while (pushi < pushV.size())
        {
            st.push(pushV[pushi]);

            while (!st.empty() && st.top() == popV[popi])
            {
                ++popi;
                st.pop();
            }

            pushi++;
        }

        if (popi == popV.size())
            return true;
        else
            return false;
    }
};

MinStack {
public:
    /** initialize your data structure here. */
    MinStack()
    {}

    void push(int val)
    {
        _st.push(val);
        if (_minST.empty() || val <= _minST.top())
        {
            _minST.push(val);
        }
    }

    void pop()
    {
        if (_st.top() == _minST.top())
            _minST.pop();

        _st.pop();
    }

    int top()
    {
        return _st.top();
    }

    int getMin()
    {
        return _minST.top();
    }

private:
    stack<int> _st;
    stack<int> _minST;
};