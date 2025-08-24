// Best/Average TC: O(n log n)
// Worst TC: O(n²)
// Best/Average SC: O(log n)
// Worst SC: O(n)
class Solution {
public:
    int partition(vector<int> &arr,int low,int high){
        int pivot=arr[low];
        int i=low;
        int j=high;
        while(i<j){
            while(arr[i]<=pivot && i<=high-1){
                i++;
            }
            while(arr[j]>pivot && j>=low+1){
                j--;
            }
            if(i<j){
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[low],arr[j]);
        return j;
    }
    void qs(vector<int> &arr,int low,int high){
        if(low<high){
            int pIndex=partition(arr,low,high);
            qs(arr,low,pIndex-1);
            qs(arr,pIndex+1,high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        qs(nums,0,nums.size()-1);
        return nums;
    }
};