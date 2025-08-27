class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;

        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[i];
                if(sum==k){
                    count++;
                }
            }
        }
        return count;
    }
};


//Optimal approach using Hashing and Prefix Sum
//TC:O(n)
//SC:O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0]=1;
        int prefixSum=0;
        int count = 0;

        for(int num:nums){
            prefixSum+=num;
            if(m.find(prefixSum-k)!=m.end()){
                count+=m[prefixSum-k];
            }
            m[prefixSum]++;
        }
        return count;
    }
};