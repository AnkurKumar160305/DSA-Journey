//Better version of the code
//Tc: O(m^2)
//Sc: O(m)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> v;
        int s=newInterval[0];
        int e=newInterval[1];
        int m=intervals.size();
        for(int i=0;i<m;i++){
            v.push_back(intervals[i]);
        }
        v.push_back({s,e});
        sort(v.begin(), v.end());

        int i=0;
        while(i<v.size()-1){
            if(v[i+1][0]<=v[i][1]){
                v[i][1]=max(v[i][1],v[i+1][1]);
                v.erase(v.begin()+i+1);
            }else{
                i++;
            }
        }

        return v;
    }
};


// Optimized version of the code
// Sorting: O(n log n)
// Merging: O(n)
// Overall TC: O(n log n)
// SC: O(n) (result vector)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Step 1: copy old intervals + add new one
        vector<vector<int>> v = intervals;
        v.push_back(newInterval);

        // Step 2: sort by start time
        sort(v.begin(), v.end());

        // Step 3: merge intervals
        vector<vector<int>> ans;
        ans.push_back(v[0]);  // start with the first interval

        for (int i = 1; i < v.size(); i++) {
            // compare current interval with the last interval in ans
            if (v[i][0] <= ans.back()[1]) {
                // overlap → merge
                ans.back()[1] = max(ans.back()[1], v[i][1]);
            } else {
                // no overlap → push as new interval
                ans.push_back(v[i]);
            }
        }

        return ans;
    }
};
