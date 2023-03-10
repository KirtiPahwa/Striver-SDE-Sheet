#include <iostream>
#include <map>
using namespace std;
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

int main()
{
    DisjointSet ds;
    ds.initialiseSet(0);
    ds.initialiseSet(1);
    ds.initialiseSet(2);
    ds.initialiseSet(3);
    ds.initialiseSet(4);
    ds.initialiseSet(5);
    ds.initialiseSet(6);
    ds.setUnion(0, 1);
    ds.setUnion(1, 2);
    ds.setUnion(3, 4);
    ds.setUnion(2, 4);
    ds.setUnion(5, 6);
    ds.setUnion(4, 6);
    cout << ds.searchInSet(0) << endl;
    cout << ds.searchInSet(1) << endl;
    cout << ds.searchInSet(2) << endl;
    cout << ds.searchInSet(3) << endl;
    cout << ds.searchInSet(4) << endl;
    cout << ds.searchInSet(5) << endl;
    cout << ds.searchInSet(6) << endl;

    return 0;
}