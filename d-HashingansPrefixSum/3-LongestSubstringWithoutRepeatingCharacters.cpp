class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(256,-1);
        int maxi=0;
        int l=0,r=0;
        int n=s.length();

        while(r<n){
            if(v[s[r]]>=l){
                    l=v[s[r]]+1;
            }
            v[s[r]]=r;
            maxi=max(maxi,r-l+1);
            r++;
        }

        return maxi;

    }
};