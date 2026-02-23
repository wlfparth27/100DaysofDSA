#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* buildList(int size)
{
    if (size <= 0) return NULL;

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < size; i++)
    {
        int val;
        if (scanf("%d", &val) != 1) break;
        struct Node* newNode = createNode(val);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

struct Node* mergeLists(struct Node* l1, struct Node* l2)
{
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data <= l2->data)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL)
    {
        tail->next = l1;
    }
    else
    {
        tail->next = l2;
    }

    return dummy.next;
}

void printList(struct Node* head)
{
    while (head != NULL)
    {
        printf("%d%s", head->data, (head->next ? " " : ""));
        head = head->next;
    }
    printf("\n");
}

void freeList(struct Node* head)
{
    struct Node* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int n, m;

    if (scanf("%d", &n) != 1) return 0;
    struct Node* list1 = buildList(n);

    if (scanf("%d", &m) != 1) return 0;
    struct Node* list2 = buildList(m);

    struct Node* mergedHead = mergeLists(list1, list2);
    
    printList(mergedHead);
    freeList(mergedHead);

    return 0;
}