#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);   // default -1
        stack<int> st;            // stack of indices

        // Traverse twice to simulate circular array
        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;  // actual index in nums
            while (!st.empty() && nums[idx] > nums[st.top()]) {
                ans[st.top()] = nums[idx];
                st.pop();
            }
            if (i < n) {   // push only first round
                st.push(idx);
            }
        }

        return ans;
    }
};
