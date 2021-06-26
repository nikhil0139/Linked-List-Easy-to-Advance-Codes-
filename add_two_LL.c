#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createLL_1(Node *head1)
{
    int num, A[100];
    struct node *last = NULL;
    struct node *temp = NULL;

    printf("Enter the number of elements in the linked list : ");
    scanf("%d", &num);
    printf("Enter the values : ");

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &A[i]);

        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = A[i];
        temp->next = NULL;

        if (head1 == NULL)
        {
            head1 = last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }
    return head1;
}

Node *reverse_1(Node *root)
{

    Node *prev = NULL;
    Node *curr = root;
    Node *temp;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

Node *newNode(int key)
{
    Node *root = (Node *)malloc(sizeof(Node));
    root->data = key;
    root->next = NULL;
    return root;
}

Node *addTwoLL(Node *first, Node *second)
{
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;

    Node *prev = NULL;
    Node *result = NULL;
    Node *temp = NULL;

    int sum, carry = 0;

    while (first != NULL || second != NULL)
    {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);

        carry = (sum >= 10) ? 1 : 0;

        sum = sum % 10;

        temp = newNode(sum);

        if (result == NULL)
        {
            result = temp;
        }
        else
        {
            prev->next = temp;
        }
        prev = temp;

        if (first != NULL)
            first = first->next;

        if (second != NULL)
            second = second->next;
    }

    if (carry > 0)
    {
        temp->next = newNode(carry);
    }
    return result;
}

void print(Node *root)
{
    while (root != NULL)
    {
        printf("%d ", root->data);
        root = root->next;
    }
    printf("\n");
}

void main()
{

    Node *first = NULL;
    Node *second = NULL;
    Node *res = NULL;

    first = createLL_1(first);

    second = createLL_1(second);

    first = reverse_1(first);

    second = reverse_1(second);

    res = addTwoLL(first, second);

    res = reverse_1(res);

    printf("The sum of two linked list is : ");

    print(res);
}
