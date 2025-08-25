//Better Approach
//Time Complexity: O(n log n)
//Space Complexity: O(n)
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<pair<int,int>> p;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-1;i+=2){
            p.push_back({nums[i],nums[i+1]});
        }
        int sum=0;
        for(auto i:p){
            sum+=min(i.first,i.second);
        }
        return sum;
    }
};


//Optimal Approach
//Time Complexity: O(n log n)
//Space Complexity: O(1)
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum=0;

        for(int i=0;i<n-1;i+=2){
            sum+=min(nums[i],nums[i+1]);
        }
        return sum;
    }
};