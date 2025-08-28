//Brute Force Solution: Using Hashmap and Sort
// TC = O(N * K log K)
// SC = O(N * K)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> ans;

        for(string s:strs){
            string key=s;
            sort(key.begin(),key.end());
            ans[key].push_back(s);
        }
        vector<vector<string>> res;
        for(auto &i:ans){
            res.push_back(i.second);
        }
        return res;
    }
};


//Optimized Solution: Using Counting Sort
// Total: O(n * k)
// Space: O(n * k)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> ans;

        for(string s:strs){
            vector<int> freq(26,0);
            for(char c:s){
                freq[c-'a']++;
            }
            string key="";
            for(int i=0;i<26;i++){
                key+=to_string(freq[i]);
            }
            ans[key].push_back(s);
        }
        
        vector<vector<string>> res;
        for(auto &i:ans){
            res.push_back(i.second);
        }
        return res;
    }
};