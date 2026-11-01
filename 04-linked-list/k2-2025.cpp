struct Node
{
    int data = 0;
    Node *next = nullptr;
};

Node *positiveStalinSort(Node *head)
{
    while (head && head->data < 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    if (!head)
    {
        return nullptr;
    }

    Node *prev = head;
    Node *curr = head->next;

    while (curr)
    {
        if (curr->data < 0 || curr->data < prev->data)
        {
            Node *temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete temp;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

//(2)→(7)→(3)→(4)→(9)→(1)→(8), x=6

Node *partition(Node *head, int x)
{
    if (!head)
    {
        return nullptr;
    }

    Node *head1 = nullptr;
    Node *tail1 = nullptr;
    Node *head2 = nullptr;
    Node *tail2 = nullptr;

    Node *curr = head;
    while (curr)
    {
        if (curr->data < x)
        {
            if (!head1)
            {
                head1 = curr;
            }
            else
            {
                head1->next = curr;
            }

            tail1 = curr;
        }
    }
}