import java.util.* ;
import java.io.*; 
public class Solution {
public static boolean canPlace(int dis,int []arr,int n,int c){
    int cows=c;
    int placed=arr[0];
    c--;
    for(int i=1;i<n;i++){
        if(arr[i]-placed>=dis)    {
            c--;
            placed=arr[i];
        } 
        } 
         if(c<=0)return true;  
    return false;
}

    public static int chessTournament(int[] arr, int n,  int c) 
	{
        Arrays.sort(arr);
        int l=1;
        int h=arr[n-1]-arr[0];
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(canPlace(mid,arr,n,c)==true){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return h;
    }

}