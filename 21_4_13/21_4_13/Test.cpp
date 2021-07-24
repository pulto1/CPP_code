class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> st;
        for (auto& str : tokens)
        {
            if (str == "+" || str == "-" || str == "*" || str == "/")
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();

                switch (str[0])
                {
                case '+':
                    st.push(left + right);
                    break;
                case '-':
                    st.push(left - right);
                    break;
                case '*':
                    st.push(left * right);
                    break;
                case '/':
                    st.push(left / right);
                    break;
                }
            }

            else
            {
                st.push(stoi(str));
            }
        }

        return st.top();
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> kMinHeap(nums.begin(), nums.begin() + k);

        for (size_t i = k; i < nums.size(); i++)
        {
            if (nums[i] > kMinHeap.top())
            {
                kMinHeap.pop();
                kMinHeap.push(nums[i]);
            }
        }

        return kMinHeap.top();
    }
};