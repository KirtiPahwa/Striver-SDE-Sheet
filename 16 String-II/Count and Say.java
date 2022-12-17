class Solution {
    public String countAndSay(int n) {
        // base case
        if(n==1){
            return "1";
        }
        int cnt=1;
        String s=countAndSay(n-1);
        String ans="";
        for(int i=1;i<s.length();i++){
            if(s.charAt(i)==s.charAt(i-1)){
                cnt++;
            }else{
                ans+=cnt+""+s.charAt(i-1);
                cnt=1;
            }
        }
        ans+=cnt+""+s.charAt(s.length()-1);
        return ans;
    }
}