// using bfs
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return node;
        queue<Node *> q;
        unordered_map<Node *, Node *> vis;

        q.push(node);
        Node *newNode = new Node(node->val);
        vis[node] = newNode;
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            for (int i = 0; i < curr->neighbors.size(); i++)
            {
                if (vis.find(curr->neighbors[i]) == vis.end())
                {
                    q.push(curr->neighbors[i]);
                    Node *newNode = new Node(curr->neighbors[i]->val);
                    vis[curr->neighbors[i]] = newNode;
                }
                vis[curr]->neighbors.push_back(vis[curr->neighbors[i]]);
            }
        }
        return newNode;
    }
};

// using bfs

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *helper(Node *node, unordered_map<Node *, Node *> &vis)
    {
        Node *newNode = new Node(node->val);
        vis[node] = newNode;
        for (int i = 0; i < node->neighbors.size(); i++)
        {
            if (vis.find(node->neighbors[i]) == vis.end())
            {
                newNode->neighbors.push_back(helper(node->neighbors[i], vis));
            }
            else
            {
                newNode->neighbors.push_back(vis[node->neighbors[i]]);
            }
        }
        return newNode;
    }

    Node *cloneGraph(Node *node)
    {
        unordered_map<Node *, Node *> vis;
        if (!node)
            return node;
        return helper(node, vis);
    }
};