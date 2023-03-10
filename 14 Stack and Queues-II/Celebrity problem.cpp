#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
    stack<int>s;
    for(int i=0;i<n;i++){
        s.push(i);
    }
    while(s.size()>1){
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        bool ca=true;
        bool cb=true;
        if(knows(a,b)){
            ca=false;
        }
        if (knows(b, a)) {
          cb = false;
        }
        if (ca && cb){

        }else if(ca){
            s.push(a);
        }else{
            s.push(b);        
                    }
    }
    if(s.size()==1){
        int ans=s.top();
        for(int i=0;i<n;i++){
            if(i!=ans && !knows(i,ans)){
                return -1;
            }
        }
        for(int i=0;i<n;i++){
            if(i!=ans && knows(ans,i)){
                return -1;
            }
        }
        return ans;
    }else{
        return -1;
    }
}