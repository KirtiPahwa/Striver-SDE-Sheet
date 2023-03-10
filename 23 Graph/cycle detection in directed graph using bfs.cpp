class Solution
{
public:
    bool canFinish(int v, vector<vector<int>> &edges)
    {
        int e = edges.size();
        vector<int> adj[v];
        vector<int> indeg(v, 0);
        for (int i = 0; i < e; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            indeg[edges[i][1]]++;
        }
        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for (auto x : adj[node])
            {
                indeg[x]--;
                if (indeg[x] == 0)
                {
                    q.push(x);
                }
            }
        }
        if (ans.size() == v)
            return true;
        return false;
    }
};