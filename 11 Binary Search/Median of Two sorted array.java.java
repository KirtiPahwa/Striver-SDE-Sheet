class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {

        int m=nums1.length;
        int n=nums2.length;
        int leftSide=(int)Math.ceil((double)(m+n)/2);
        if(m>n){
            return findMedianSortedArrays(nums2,nums1);
        }
        int r=m;
        int l=0;
        double ans=0.0;
        while(l<=r){
            int mid=(l+r)>>1;  //cut1
            int p=leftSide-mid;  //cut2
            int l1=mid==0?Integer.MIN_VALUE:nums1[mid-1];
            int l2=p==0?Integer.MIN_VALUE:nums2[p-1];
            int r1=mid==m?Integer.MAX_VALUE:nums1[mid];
            int r2=p==n?Integer.MAX_VALUE:nums2[p];
            

            // check if its valid or not
            if(l1<=r2 &&  l2<=r1){
                //even
                if(((m+n)&1)==0){
                    ans=(((double)(Math.max(l1,l2)+Math.min(r1,r2)))/2);
                }else{
                    ans=Math.max(l1,l2);
                }    
                return ans;
            }else{
                if(l1>r2){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
        }
        return ans;

    }
}