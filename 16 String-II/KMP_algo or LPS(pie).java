class Solution {
    public int kmp_algo(char s[],char p[]){
        int m=s.length;
        int n=p.length;
        int lps[]=new int[n];

        // creating longest prefix string
        int i=0;
        int len=0;
        lps[i++]=0;
        while(i<n){
            if(p[i]==p[len]){
                lps[i]=++len;
                i++;
            }else{
                if(len==0){
                    i++;
                }else{
                    len=lps[len-1];
                }
            }
        }

        // searching index for the first occurence of pattern matching in the string
         i=0;
        int j=0;
        while(i<m){
            if(s[i]==p[j]){
                i++;
                j++;
                if(j==n){
                return i-n;
            }
            }else{
                if(j!=0){
                j=lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return -1;
    }
    public int strStr(String haystack, String needle) {
        return kmp_algo(haystack.toCharArray(),needle.toCharArray());
    }
}