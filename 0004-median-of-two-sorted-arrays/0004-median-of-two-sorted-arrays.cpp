class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int m=nums1.size();
        int n=nums2.size();
        vector<int> result;
        int i=0;int j=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                result.push_back(nums1[i]);
                i++;
            }else{
                result.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            result.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            result.push_back(nums2[j]);
            j++;
        }
        int total = m+n;
        if(total % 2 == 1){
            return result[total/2];
        }else{
            int mid1=total/2 -1;
            int mid2=total/2;
            return (result[mid1]+ result[mid2]) /2.0;
        }
    }
};