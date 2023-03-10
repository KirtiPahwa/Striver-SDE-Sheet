#include <bits/stdc++.h> 
void dfs(int i,vector<bool>&vis,vector<int>adj[],stack<int>&s)
{
    vis[i]=1;
    for(auto x:adj[i]){
        if(!vis[x]){
            dfs(x,vis,adj,s);
        }
    }
    s.push(i);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
     vector<int>adj[v];
        for(int i=0;i<e;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
    vector<bool>vis(v,0);
    stack<int>s;
    for(int i=0;i<v;i++){
        if(!vis[i])
        dfs(i,vis,adj,s);
    }
    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
   
    return ans;
}