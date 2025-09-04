class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temp)
    {
        vector<int> ans;
        int n = temp.size();
        for (int i = 0; i < n - 1; i++)
        {
            int index = -1;
            int day = i;
            for (int j = i + 1; j < n; j++)
            {
                if (temp[day] < temp[j])
                {
                    index = j;
                    break;
                }
            }
            if (index == -1)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(index - day);
            }
        }
        ans.push_back(0);
        return ans;
    }
};

// Optimal Approach
// ⏱️ Time Complexity: O(n)
// 🛰️ Space Complexity: O(n)
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temp)
    {
        int n = temp.size();
        vector<int> ans(n, 0); // pre-fill with 0 so last element is handled
        stack<int> s;          // stores indices

        for (int i = n - 1; i >= 0; i--)
        {
            // pop all smaller or equal temperatures
            while (!s.empty() && temp[s.top()] <= temp[i])
            {
                s.pop();
            }

            if (!s.empty())
            {
                ans[i] = s.top() - i; // next warmer day
            }

            s.push(i); // push current index
        }

        return ans;
    }
};
// Or
#include <vector> #include <stack> using namespace std;
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                int prev = st.top();
                st.pop();
                answer[prev] = i - prev;
            }
            st.push(i);
        }
        return answer;
    }
};