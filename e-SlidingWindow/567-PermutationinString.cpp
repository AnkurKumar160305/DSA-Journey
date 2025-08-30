// Time Complexity: O(len1 + len2)
// Space Complexity: O(26) ≈ O(1) (constant space)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26,0),freq2(26,0);
        int len1=s1.size();
        int len2=s2.size();

        if (len1 > len2) return false; 

        for(int i=0;i<len1;i++){
            freq1[s1[i]-'a']++;
        }

        for(int i=0;i<len1;i++){
            freq2[s2[i]-'a']++;
        }

        if(freq1==freq2) return true;

        for(int i=len1;i<len2;i++){
            freq2[s2[i]-'a']++;
            freq2[s2[i-len1]-'a']--;

            if(freq1==freq2) return true;   
        }

        return false;
    }
};