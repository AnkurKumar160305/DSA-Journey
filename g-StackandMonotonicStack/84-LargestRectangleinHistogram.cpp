class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            int minHeight=heights[i];
            for(int j=i;j<n;j++){
                minHeight=min(minHeight,heights[j]);
                int area=minHeight*(j-i+1);
                maxi=max(area,maxi);
            }
        }
        return maxi;
    }
};


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n=heights.size();
        int maxi=0;
        for(int i=0;i<=n;i++){
            int currHeight = (i == n) ? 0 : heights[i];
            while(!s.empty() && currHeight<heights[s.top()]){
                int h = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : (i - s.top() - 1);
                maxi = max(maxi, h * width);
            }
            s.push(i);
        }
        return maxi;
    }
};