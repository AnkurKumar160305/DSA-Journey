class Solution {
public:
    int findMax(unordered_map<int,int> &m){
        int maxi=0;
        int ans=0;
        auto item=m.begin();
        for(auto i=m.begin();i!=m.end();i++){
            if(i->second>maxi){
                maxi=i->second;
                ans=i->first;
                item=i;
            }
        }
        m.erase(item);
        return ans;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i:nums){
            m[i]++;
        }
        vector<int> ans;
        while(k>0){
            ans.push_back(findMax(m));
            k--;
        }
        return ans;
    }
};

// Time Complexity: O(n + u log k) ≈ O(n log k) worst case
// Space Complexity: O(u)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i:nums){
            m[i]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        for(auto &i:m){
            minHeap.push({i.second,i.first});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

        vector<int> ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};



//Tc:O(n)
//Sc:O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i:nums){
            m[i]++;
        }

        vector<vector<int>> bucket(n+1);

        for(auto &[num,count] : m){
            bucket[count].push_back(num);
        }


        for(int i=n;i>0 && ans.size()<k;i--){
            for(int num:bucket[i]){
                ans.push_back(num);
                if(ans.size()==k) break;
            }
        }
        return ans;
    }
};