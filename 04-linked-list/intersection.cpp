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
    int listLen(ListNode *head)
    {
        int len = 0;
        ListNode *curr = head;

        while (curr)
        {
            len++;
            curr = curr->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lenA = listLen(headA);
        int lenB = listLen(headB);

        ListNode *pA = headA;
        ListNode *pB = headB;

        if (lenA > lenB)
        {
            int diff = lenA - lenB;

            while (diff > 0)
            {
                pA = pA->next;
                diff--;
            }
        }
        else if (lenA < lenB)
        {
            int diff = lenB - lenA;

            while (diff > 0)
            {
                pB = pB->next;
                diff--;
            }
        }

        while (pA && pB)
        {
            if (pA == pB)
            {
                return pA;
            }

            pA = pA->next;
            pB = pB->next;
        }

        return nullptr;
    }
};