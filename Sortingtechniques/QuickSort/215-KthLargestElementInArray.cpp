//Optional Approach
//Time Complexity: O(n log n)
//Space Complexity: O(logn)
class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};


//Better Approach: QuickSelect
// Time Complexity: O(n) average, O(n²) worst case
// Space Complexity: O(1) extra (excluding recursion), recursion stack = O(log n) avg, O(n) worst
class Solution
{
public:
    int partition(vector<int> &arr, int low, int high)
    {
        int pivot = arr[low];
        int i = low;
        int j = high;

        while (i < j)
        {
            while (arr[i] <= pivot && i <= high - 1)
            {
                i++;
            }

            while (arr[j] > pivot && j >= low + 1)
            {
                j--;
            }
            if (i < j)
                swap(arr[i], arr[j]);
        }
        swap(arr[low], arr[j]);
        return j;
    }

    int quickSelect(vector<int> &arr, int low, int high, int k)
    {
        if (low <= high)
        {
            int pIndex = partition(arr, low, high);
            if (pIndex == k)
                return arr[pIndex];
            else if (pIndex > k)
                return quickSelect(arr, low, pIndex - 1, k);
            else
                return quickSelect(arr, pIndex + 1, high, k);
        }
        return -1;
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, n - k);
    }
};


//Optimal: Approach: Min Heap
//Tc: O(n log k)
//Sc: O(k)
// Parent ≤ Children (for min heap)
// To make it a Min Heap, we write:
// priority_queue<int, vector<int>, greater<int>> minHeap;
// Traverse each number in the array:
// Push it into the heap.
// If heap size becomes greater than k, remove the smallest element (pop from min heap).

// //example:
// nums = [3,2,1,5,6,4], k = 2
// Push 3 → heap = [3]
// Push 2 → heap = [2,3]
// Push 1 → heap = [1,3,2] → size > 2 → pop → heap = [2,3]
// Push 5 → heap = [2,3,5] → size > 2 → pop → heap = [3,5]
// Push 6 → heap = [3,5,6] → size > 2 → pop → heap = [5,6]
// Push 4 → heap = [4,6,5] → size > 2 → pop → heap = [5,6]
// Final heap = [5,6]
// minHeap.top() = 5 → Answer = 5 ✅

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
