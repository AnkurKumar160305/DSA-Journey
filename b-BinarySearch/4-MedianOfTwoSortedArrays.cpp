//Brute force approach
//TC:O(n+m)
//SC:O(n+m)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> arr;
        int s1=0,s2=0;
        while(s1<n && s2<m){
            if(nums1[s1]<=nums2[s2]){
                arr.push_back(nums1[s1]);
                s1++;
            }else{
                arr.push_back(nums2[s2]);
                s2++;
            }
        }

        while(s1<n){
            arr.push_back(nums1[s1]);
            s1++;
        }
        while(s2<m){
            arr.push_back(nums2[s2]);
            s2++;
        }

        int size=arr.size();
        if(size%2==0){
            int index=(size/2)-1;
            return (arr[size/2]+arr[index])/2.0;
        }else{
            return arr[size/2];
        }
    }
};


//Better approach
//TC:O(n+m)
//SC:O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int i=0,j=0;
        int n=(n1+n2);
        int ind2=n/2;
        int ind1=ind2-1;
        int cnt=0;
        int index1=-1,index2=-1;
        while(i<n1 && j<n2){
            if(nums1[i]<=nums2[j]){
                if(cnt==ind1) index1=nums1[i];
                if(cnt==ind2) index2=nums1[i];
                cnt++;
                i++;
            }else{
                if(cnt==ind1) index1=nums2[j];
                if(cnt==ind2) index2=nums2[j];
                cnt++;
                j++;
            }
            if(index1!=-1 && index2!=-1) break;
        }
        while(i<n1){
            if(cnt==ind1) index1=nums1[i];
            if(cnt==ind2) index2=nums1[i];
            cnt++;
            i++;
            if(index1!=-1 && index2!=-1) break;
        }
        while(j<n2){
            if(cnt==ind1) index1=nums2[j];
            if(cnt==ind2) index2=nums2[j];
            cnt++;
            j++;
            if(index1!=-1 && index2!=-1) break;
        }
        if(n%2==1){
            return (double)index2;
        }else{
            return (double)(index1+index2)/2.0;
        }
    }
};

//Optimal approach
//TC:O(log(min(n,m)))
//SC:O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);
        }
        int low=0,high=n1;
        int left=(n1+n2+1)/2;
        int n=n1+n2;
        while(low<=high){
            int mid1=(low+high)/2;
            int mid2=left-mid1;
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;
            if(mid1<n1) r1=nums1[mid1];
            if(mid2<n2) r2=nums2[mid2];
            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2-1>=0) l2=nums2[mid2-1];
            if(l1<=r2 && l2<=r1){
                if(n%2==1){
                    return max(l1,l2);
                }else{
                    return (double)(max(l1,l2)+min(r1,r2))/2.0;
                }
            }else if(l1>r2){
                high=mid1-1;
            }else{
                low=mid1+1;
            }
        }
        return 0;
    }
};