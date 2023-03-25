#include <iostream>
#include <string>
#include <string>
#include <array>
#include <iterator>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <cctype>
#include <algorithm>
#include <fstream>

using namespace std;
struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = new Node;
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

Node *findMid1(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void reverse(Node *head)
{
    // Initialize current, previous and next pointers
    Node *current = head;
    Node *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
}

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        //  m[ptr->data]++;
        // printf("Element: %d\n", ptr->data);
        cout << ptr->data;
        ptr = ptr->next;
    }
}

struct Node *selectionSortwithabsolutesortd(struct Node *head)
{
    struct Node *prev = head;
    struct Node *curr = head->next;
    while (curr != NULL)
    {
        if (curr->data < prev->data)
        {
            prev->next = curr->next;
            curr->next = head;
            head = curr;
            curr = prev;
        }
        else
        {
            prev = curr;
        }
        curr = curr->next;
    }
    return head;
}

void selectionSort(struct Node *head)
{
    struct Node *temp = head;

    // Traverse the List
    while (temp != NULL)
    {
        struct Node *min = temp;
        struct Node *r = temp->next;

        // Traverse the unsorted sublist
        while (r != NULL)
        {
            if (min->data < r->data)
                min = r;

            r = r->next;
        }

        // Swap Data
        int x = temp->data;
        temp->data = min->data;
        min->data = x;

        temp = temp->next;
    }
}

int main()
{
    struct Node *head;
    struct Node *head1;
    struct Node *head2;
    struct Node *head3;
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);

    // linkedListTraversal(head);
    // sortList(&head);
    // head=selectionSort(head);
    // selectionSort(head);
    // cout<<endl;

    Node *mid = findMid1(head);
    // cout<<endl<<endl;
    // linkedListTraversal(head1);
    // cout<<endl;
    // linkedListTraversal(head2);
    // linkedListTraversal(head);
    /*string s="";
    for (auto i = m.rbegin(); i != m.rend(); i++) {
    {
        for(int j=0;j<i->second;j++){
            cout<<i->first;
        }
    }*/
}

/********************************************************************/
struct node
{
    int data;
    struct node *next;
};
node *findMid(node *head)
{
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node *merge(node *left, node *right)
{

    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    node *ans = new node;
    ans->data = -1;
    node *temp = ans;

    // merge 2 sorted Linked List
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;
}

node *mergeSort(node *head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // break linked list into 2 halvs, after finding mid
    node *mid = findMid(head);

    node *left = head;
    node *right = mid->next;
    mid->next = NULL;

    // recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // merge both left and right halves
    node *result = merge(left, right);

    return result;
}

class Solution
{
    struct Node
    {
        int data;
        struct Node *next;
    };

private:
    Node *reverse(Node *head)
    {

        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void insertAtTail(struct Node *&head, struct Node *&tail, int val)
    {

        Node *temp = new Node;
        temp->data = val;
        // empty list
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    struct Node *add(struct Node *first, struct Node *second)
    {
        int carry = 0;

        Node *ansHead = NULL;
        Node *ansTail = NULL;

        while (first != NULL || second != NULL || carry != 0)
        {

            int val1 = 0;
            if (first != NULL)
                val1 = first->data;

            int val2 = 0;
            if (second != NULL)
                val2 = second->data;

            int sum = carry + val1 + val2;

            int digit = sum % 10;

            // create node and add in answer Linked List
            insertAtTail(ansHead, ansTail, digit);

            carry = sum / 10;
            if (first != NULL)
                first = first->next;

            if (second != NULL)
                second = second->next;
        }
        return ansHead;
    }

public:
    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        // step 1 -  reverse input LL
        first = reverse(first);
        second = reverse(second);

        // step2 - add 2 LL
        Node *ans = add(first, second);

        // step 3
        ans = reverse(ans);

        return ans;
    }
};

/****************************************************************
    Following is the Linked List node structure

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

Node *kReverse(Node *head, int k)
{
    // base call
    if (head == NULL)
    {
        return NULL;
    }

    // step1: reverse first k nodes
    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step2: Recursion dekhlega aage ka
    if (next != NULL)
    {
        head->next = kReverse(next, k);
    }

    // step3: return head of reversed list
    return prev;
}

int getCount(Node *head)
{
    int count = 0;        // Initialize count
    Node *current = head; // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

int finder1(Node *head)
{
    Node *mid = findMid1(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;
    // right = reverse(right);
    linkedListTraversal(left);
    cout << endl;
    linkedListTraversal(right);
    cout << endl;
    struct Node *head5;
    push(&head5, 0);
    Node *curr = head5;
    while (left || right)
    {
        if (left)
        {
            curr->next = left;
            curr = curr->next;
            left = left->next;
        }
        // Then add the element from the second list
        if (right)
        {
            curr->next = right;
            curr = curr->next;
            right = right->next;
        }
    }
    *head5 = *head5->next;
    cout << endl;
    linkedListTraversal(head5);
}

void linkedListTraversalsumbetweentwozero(struct Node *ptr)
{
    ptr = ptr->next;
    int sum = 0;
    while (ptr != NULL)
    {
        // printf("Element: %d\n", ptr->data);
        if (ptr->data != 0)
            sum = sum + ptr->data;
        else
        {
            //  push(&head7, sum);sum=0;
        }
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int linkedListTraversal1(struct Node *ptr)
{
    int countt = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        countt++;
    }
    // cout<<countt<<endl;
    return countt;
}
void linkedListTraversal2(struct Node *ptr)
{
    int count = 0;
    while (ptr != NULL)
    {
        //  m[ptr->data]++;
        // printf("Element: %d\n", ptr->data);
        // cout<<ptr->data;
        ptr = ptr->next;
        count++;
    }
    if (count == 0)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
