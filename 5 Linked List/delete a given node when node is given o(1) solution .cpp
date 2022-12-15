/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    void insertNode(ListNode *&head, int val)
    {
        ListNode *newNode = new ListNode(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        ListNode *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    // function to get reference of the node to delete
    ListNode *getNode(ListNode *head, int val)
    {
        while (head->val != val)
            head = head->next;

        return head;
    }
    // delete function as per the question
    void deleteNode(ListNode *t)
    {
        t->val = t->next->val;
        t->next = t->next->next;
        return;
    }
};