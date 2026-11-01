struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode *next;
};

SinglyLinkedListNode *reverse(SinglyLinkedListNode *llist)
{
    SinglyLinkedListNode *prev = nullptr;

    while (llist)
    {
        SinglyLinkedListNode *next = llist->next;
        llist->next = prev;
        prev = llist;
        llist = next;
    }
    return prev;
};