/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

// class Solution {
//     public Node copyRandomList(Node head) {

//     }

// }

/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */
public
class Solution
{
public
    Node copyRandomList(Node head)
    {
        Map<Node, Node> nodeMap = pass1(head);
        return pass2(head, nodeMap);
    }

    // Create a HashMap containing the nodes and their corresponding clones...
private
    Map pass1(Node head)
    {
        Map<Node, Node> nodeMap = new HashMap<Node, Node>();
        Node node = head;
        while (node != null)
        {
            nodeMap.put(node, createClone(node));
            node = node.next;
        }

        return nodeMap;
    }

    // Fix the original nodes with the actually cloned nodes...
private
    Node pass2(Node head, Map<Node, Node> nodeMap)
    {
        Node node = head;
        Node cloneHead = nodeMap.get(node);
        Node currentNode = null;
        while (node != null)
        {
            currentNode = nodeMap.get(node);
            correctTheReferences(currentNode, nodeMap);
            node = node.next;
        }

        return cloneHead;
    }

    // Real corrections happen here...
private
    void correctTheReferences(Node currentNode, Map<Node, Node> nodeMap)
    {
        if (currentNode != null)
        {
            currentNode.next = nodeMap.get(currentNode.next);
            currentNode.random = nodeMap.get(currentNode.random);
        }
    }

    // Create a deep clone of the node... (we can correct the references later.)
private
    Node createClone(Node node)
    {
        Node clone = new Node(node.val);
        clone.next = node.next;
        clone.random = node.random;

        return clone;
    }
}