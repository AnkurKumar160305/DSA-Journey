//BruteForce Approach
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            int found=0;
            for(int j=0;j<n;j++){
                if(i==nums[j]){
                    found=1;
                }
            }
            if(found==0){
                return i;
            }
        }
        return n;
    }
};



//Optimal approach
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int orgsum=n*(n+1)/2;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        return orgsum-sum;
    }
};


//Optimal
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xoor=n;
        for(int i=0;i<n;i++){
            xoor^=i^nums[i];
        }
        return xoor;
    }
};