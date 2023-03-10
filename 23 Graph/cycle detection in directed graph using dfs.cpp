class Solution
{
public:
    bool dfs(int start, vector<bool> &vis, vector<int> adj[], vector<bool> &dfsvis)
    {
        vis[start] = 1;
        dfsvis[start] = 1;
        for (auto x : adj[start])
        {
            if (vis[x])
                return true;
            else if (!dfsvis[x])
            {
                if (dfs(x, vis, adj, dfsvis))
                    return true;
            }
        }
        vis[start] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> adj[numCourses];
        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> vis(numCourses, 0);
        vector<bool> dfsvis(numCourses, 0);

        for (int i = 0; i < numCourses; i++)
        {
            if (dfsvis[i] == 0)
            {
                if (dfs(i, vis, adj, dfsvis))
                    return false;
            }
        }
        return true;
    }
};