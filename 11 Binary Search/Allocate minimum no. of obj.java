import java.util.* ;
import java.io.*; 

public class Solution {
    public static boolean isPossible(int k,int n,int []arr,long mid){
        if(n<k)return false;
        int stud=1;
        long sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>mid){
                stud++;
                sum=arr[i];
                if(sum>mid)return false;
            }
            if(stud>k){
            return false;
            }
        }
        return true;
    }
    public static long ayushGivesNinjatest(int n, int m, int[] arr) {
        
        long l=0;
        long r=0;
      for(int i=0;i<m;i++){
          l=Math.max(arr[i],l);
          r+=arr[i];
      }
        long ans=-1;
        
        while(l<=r){
            long mid=(l+r)/2;
            if(isPossible(n,m,arr,mid)==true){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
        
    }
}