//Brute force approach
//Time Complexity: O(n^2)
//Space Complexity: O(1)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> temp;
        int n=nums.size();
        for(int i=1;i<=n;i++){
            int found=0;
            for(int j=0;j<n;j++){
                if(nums[j]==i){
                    found=1;
                }
            }
            if(found==0){
                temp.push_back(i);
            }
        }
        return temp;
    }
};

//Better Approach
//Time Complexity: O(n)
//Space Complexity: O(n)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(n+1,0);

        for(int i=0;i<n;i++){
            temp[nums[i]]++;
        }

        vector<int> res;
        for(int i=1;i<=n;i++){
            if(temp[i]==0){
                res.push_back(i);
            }
        }
        return res;
    }
};


//Better Approach
//Time Complexity: O(n)
//Space Complexity: O(n)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> m(nums.begin(),nums.end());
        vector<int> res;

        for(int i=1;i<=n;i++){
            if(m.find(i)==m.end()){
                res.push_back(i);
            }
        }

        return res;
    }
};


//Optimal Approach
//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        // Step 1: Mark numbers as visited
        for(int i=0; i<n; i++) {
            int idx = abs(nums[i]) - 1;   // Map number → index
            if(nums[idx] > 0) {
                nums[idx] = -nums[idx];   // Mark visited by making it negative
            }
        }

        // Step 2: Collect missing numbers
        for(int i=0; i<n; i++) {
            if(nums[i] > 0) {             // Positive means index+1 never visited
                res.push_back(i+1);
            }
        }

        return res;
    }
};
