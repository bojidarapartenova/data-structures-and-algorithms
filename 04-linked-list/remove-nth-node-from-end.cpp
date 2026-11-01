struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int size = 0;
        ListNode *curr = head;
        while (curr)
        {
            size++;
            curr = curr->next;
        }

        if (n > size)
        {
            return nullptr;
        }

        if (n == size)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int prevPos = size - n;
        ListNode *prev = head;
        for (int i = 1; i < prevPos; i++)
        {
            prev = prev->next;
        }

        ListNode *toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;

        return head;
    }
};