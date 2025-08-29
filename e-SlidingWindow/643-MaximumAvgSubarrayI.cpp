class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double avg=0.0;
        double maxi=0.0;
        for(int i=0;i<=n-k;i++){
            int sum=0;
            for(int j=i;j<i+k;j++){
                sum+=nums[j];
            }
            avg=sum/(double)(k);
            maxi=max(maxi,avg);
        }
        return maxi;
    }
};

//Optimal Sliding Window Approach
//Tc: O(n)
//Sc: O(1)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double sum=0.0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        double maxi=sum;
        for(int i=k;i<n;i++){
            sum+=nums[i]-nums[i-k];
            maxi=max(maxi,sum);
        }
        return maxi/k;
    }
};