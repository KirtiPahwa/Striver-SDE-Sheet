
class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pr = new PriorityQueue<>();
        for (int i = 0; i < nums.length; i++) {
            pr.add(nums[i]);
            if (pr.size() > k) {
                int a = pr.remove();
            }

        }
        return pr.remove();
    }
}



// Or optimised


class Solution {
    public int quickSort(int l,int r,int arr[]){
        int p=arr[r];
        int i=l-1;
        for(int j=l;j<r;j++){
            if(arr[j]<p){
                i++;
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        int temp=arr[i+1];
        arr[i+1]=arr[r];
        arr[r]=temp;
        return i+1;
    }
    public int helper(int []arr,int k,int l,int r){
        if(l>r){
            return -1;
        }
        int p= quickSort(l,r,arr);
        if(p==k-1){
            return arr[p];
        }else if(p<k-1){
            return helper(arr,k,p+1,r);
        }else{
            return helper(arr,k,l,p-1);
        }
    }

    public int findKthLargest(int[] nums, int k) {
        int n=nums.length;
       return helper(nums,n-k+1,0,n-1);
    }
}
