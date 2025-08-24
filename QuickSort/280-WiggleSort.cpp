//Optimal Approach: Wiggle Sort
// ✅ Time Complexity: O(n)
// ✅ Space Complexity: O(1)
// nums[0] <= nums[1] >= nums[2] <= nums[3] >= nums[4] <= ...
// Input: nums = [3, 5, 2, 1, 6, 4]
// Output: [3, 5, 1, 6, 2, 4]
// Explanation: Another acceptable output is [1, 6, 2, 5, 3, 4].

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if ((i % 2 == 0 && nums[i] > nums[i+1]) || (i % 2 == 1 && nums[i] < nums[i+1])) {
                swap(nums[i], nums[i+1]);
            }
        }
    }
};
