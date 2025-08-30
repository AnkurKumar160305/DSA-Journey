//Brute force
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<=n-k;i++){
            int j=i;
            int maxi=nums[i];
            while(j<i+k){
                maxi=max(maxi,nums[j]);
                j++;
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};

//Doubt
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;  // stores indices
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // 1. Remove elements out of this window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // 2. Remove all smaller elements from back
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            // 3. Add current element index
            dq.push_back(i);

            // 4. Window ready → record max
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};
