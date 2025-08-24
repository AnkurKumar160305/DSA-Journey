//Better approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }

        for(auto i:m){
            if(i.second>n/2){
                return i.first;
            }
        }

        return 0;
    }
};

//Optimal approach
// TC: O(n)
// SC: O(1)
// Boyer–Moore Majority Vote Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int num=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                num=nums[i];
            }
            if(num==nums[i]){
                count++;
            }else{
                count--;
            }
        }
        return num;
    }
};