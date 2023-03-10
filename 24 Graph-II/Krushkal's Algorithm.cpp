#include <bits/stdc++.h>
class Edge
{
public:
    int weight;
    int src;
    int dest;
};
int getParent(int v, int *parent)
{
    if (parent[v] == v)
    {
        return v;
    }
    return getParent(parent[v], parent);
}
bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}
int kruskalMST(int n, int m, vector<vector<int>> &graph)
{
    Edge *edges = new Edge[m];
    Edge *output = new Edge[n - 1];
    int k = 0;

    for (auto x : graph)
    {
        edges[k].src = x[0];
        edges[k].dest = x[1];
        edges[k++].weight = x[2];
    }
    sort(edges, edges + m, compare);
    int *parent = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;
    while (count < n - 1)
    {
        Edge currEdge = edges[i];
        int srcParent = getParent(currEdge.src, parent);
        int destParent = getParent(currEdge.dest, parent);

        if (srcParent != destParent)
        {
            output[count++] = currEdge;
            parent[srcParent] = destParent;
        }
        i++;
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans += output[i].weight;
    }
    delete parent;
    delete edges;
    delete output;
    return ans;
}

// or union by rank and path compression for detecting the cycle

#include <bits/stdc++.h>
// dsu
class DSNode
{
public:
    int data;
    DSNode *parent;
    int rank;
};

class DisjointSet
{
private:
    map<int, DSNode *> hash;
    DSNode *searchInSetHelper(DSNode *node)
    {
        if (node == node->parent)
        {
            return node;
        }
        node->parent = searchInSetHelper(node->parent);
        return node->parent;
    }

public:
    void initialiseSet(int data)
    {
        DSNode *node = new DSNode();
        node->data = data;
        node->parent = node;
        node->rank = 0;
        hash[data] = node;
    }
    int searchInSet(int data)
    {
        return searchInSetHelper(hash[data])->data;
    }
    void setUnion(int data1, int data2)
    {
        DSNode *node1 = hash[data1];
        DSNode *node2 = hash[data2];
        DSNode *parent1 = searchInSetHelper(node1);
        DSNode *parent2 = searchInSetHelper(node2);
        if (parent1->data == parent2->data)
        {
            return;
        }
        else if (parent1->rank >= parent2->rank)
        {
            if (parent1->rank == parent2->rank)
            {
                parent1->rank++;
            }
            parent2->parent = parent1;
        }
        else
        {
            parent1->parent = parent2;
        }
    }
};

// main
class Edge
{
public:
    int weight;
    int src;
    int dest;
};
int getParent(int v, int *parent)
{
    if (parent[v] == v)
    {
        return v;
    }
    return getParent(parent[v], parent);
}
bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}
int kruskalMST(int n, int m, vector<vector<int>> &graph)
{
    //     disjoint set
    DisjointSet ds;
    for (int i = 1; i <= n; i++)
    {
        ds.initialiseSet(i);
    }

    Edge *edges = new Edge[m];
    Edge *output = new Edge[n - 1];
    int k = 0;

    for (auto x : graph)
    {
        edges[k].src = x[0];
        edges[k].dest = x[1];
        edges[k++].weight = x[2];
    }
    sort(edges, edges + m, compare);
    int count = 0;
    int i = 0;
    while (count < n - 1)
    {
        Edge currEdge = edges[i];
        int srcParent = ds.searchInSet(currEdge.src);
        int destParent = ds.searchInSet(currEdge.dest);
        if (srcParent != destParent)
        {
            output[count++] = currEdge;
            ds.setUnion(srcParent, destParent);
        }
        i++;
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans += output[i].weight;
    }
    delete edges;
    delete output;
    return ans;
}