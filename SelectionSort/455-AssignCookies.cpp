//Optimized Approach
//Time Complexity: O(n log n + m log m)
//Space Complexity: O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n=s.size();
        int m=g.size();
        int i=0;
        int j=0;
        int cnt=0;
        while(i<n && j<m){
            if(s[i]>=g[j]){
                cnt++;
                i++;
                j++;
            }else{
                i++;
            }
        }
        return cnt;
    }
};