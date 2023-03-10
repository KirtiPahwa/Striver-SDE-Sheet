#include<bits/stdc++.h>
void dfs(vector<int>adj[],int node,int n,stack<int>&s,vector<int>&vis){
    vis[node]=1;
    for(auto x:adj[node]){
        if(vis[x]==0){
            dfs(adj,x,n,s,vis);
        }
    }
    s.push(node);
}
void dfs2(vector<int>transpose[],int node,int n,vector<int>&vis,vector<int>&temp){
    vis[node]=1;
    temp.push_back(node);
    for(auto x:transpose[node]){
        if(vis[x]==0){
            dfs2(transpose,x,n,vis,temp);
        }
    }
}
vector<vector<int>> getSCC(vector<int> adj[],vector<int> transpose[],int n){
    vector<int>vis(n,0);
    stack<int>s;
    for(int i=0;i<n;i++){
        vector<int>temp;
        if(vis[i]==0){
            dfs(adj,i,n,s,vis);
        }
    }
    for(int i=0;i<n;i++){
        vis[i]=0;
    }
    vector<vector<int>>output;
    while(!s.empty()){
        int top=s.top();
        s.pop();
        if(!vis[top]){
            vector<int>temp;
            dfs2(transpose,top,n,vis,temp);
            output.push_back(temp);
        }
    }
    return output;
    
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    
    vector<int>adj[n];
        vector<int>transpose[n];

    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        transpose[edges[i][1]].push_back(edges[i][0]);
    }
  return  getSCC(adj,transpose,n);
    
}