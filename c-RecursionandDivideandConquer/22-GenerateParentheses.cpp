//Doubt
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> arr;
        int n=nums.size();
        int p = 1 << n;  // total number of subsets = 2^n

        for(int i=0;i<p;i++){
            vector<int> subset;
            for(int j=0;j<n;j++){
                if(i & (1<<j)){  //checks if the j-th bit in the number i is set (1) or not (0).
                    subset.push_back(nums[j]);
                }
            }
            arr.push_back(subset);
        }
        return arr;
    }
};