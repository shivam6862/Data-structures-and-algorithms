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

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head, *tail;
void create()
{
    struct node *head, *tail;
    struct node *newnode;
    head = 0;
    struct node *temp;
    int choice = 1;
    while (choice == 1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        int nn;
        cin >> nn;
        newnode->data = nn;
        newnode->prev = NULL;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
            tail = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
            tail = newnode;
        }
        cin >> choice;
    }
}
void insertatbeg()
{
    struct node *newnode;
    struct node *head;
    newnode = (struct node *)malloc(sizeof(struct node));
    int nn;
    cin >> nn;
    newnode->data = nn;
    newnode->prev = NULL;
    newnode->next = NULL;
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}
void insertatend()
{
    struct node *newnode;
    struct node *tail;
    newnode = (struct node *)malloc(sizeof(struct node));
    int nn;
    cin >> nn;
    newnode->data = nn;
    newnode->prev = NULL;
    newnode->next = NULL;
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}
void insertatposition()
{
    int i = 1;
    int pos;
    cin >> pos;
    struct node *newnode, *temp;
    struct node *head, *tail;
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    int nn;
    cin >> nn;
    newnode->data = nn;
    newnode->prev = NULL;
    newnode->next = NULL;
    // knowing that point is valid and not 1.
    // if it is insert after positon then change while(i<pos).
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->next->prev = newnode;
}

void deletefrombeg()
{
    struct node *head, *tail;
    struct node *temp;
    if (head == 0)
        cout << "list is empty" << endl;
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}
void deletefromend()
{
    struct node *head, *tail;
    struct node *temp;
    if (tail == 0)
        cout << "list is empty" << endl;
    else
    {
        temp = tail;
        tail->prev->next = NULL;
        tail = tail->prev;
        free(temp);
    }
}
void deletefrompos()
{
    struct node *head, *tail;
    int i = 1;
    int poss;
    cin >> poss;
    struct node *temp;
    temp = head;
    while (i < poss)
    {
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}
void reverseDLL()
{
    struct node *head, *tail;
    struct node *current, *nextnode;
    current = head;
    while (current != NULL)
    {
        nextnode = current->next;
        current->next = current->prev;
        current->prev = nextnode;
        current = nextnode;
    }
    current = head;
    head = tail;
    tail = current;
}
void display()
{
    struct node *head, *tail;
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    create();
    display();
    insertatbeg();
    cout << endl;
    display();
    insertatend();
    cout << endl;
    display();
    insertatposition();
    cout << endl;
    display();
    deletefrombeg();
    cout << endl;
    display();
    deletefromend();
    cout << endl;
    display();
    deletefrompos();
    cout << endl;
    display();
    reverseDLL();
    cout << endl;
    display();
}
// //////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head;
void createCLL()
{
    struct node *head;
    struct node *newnode;
    head = NULL;
    struct node *temp;
    int choice = 1;
    while (choice == 1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        int nn;
        cin >> nn;
        newnode->data = nn;
        newnode->next = NULL;
        if (head == 0)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        temp->next = head;
        cin >> choice;
    }
}
struct node *tail;
void create()
{
    struct node *tail;
    tail = NULL;
    int choice = 1;
    while (choice == 1)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        int nn;
        cin >> nn;
        newnode->data = nn;
        newnode->next = 0;
        if (tail == 0)
        {
            tail = newnode;
            tail->next = newnode;
        }
        else
        {
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }
        cin >> choice;
    }
}
void insertatbeg()
{
    struct node *head, *tail;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    int nn;
    cin >> nn;
    newnode->data = nn;
    newnode->next = 0;
    if (tail == 0)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
    }
}
void insertatend()
{
    struct node *head, *tail;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    int nn;
    cin >> nn;
    newnode->data = nn;
    newnode->next = 0;
    if (tail == 0)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}
void insertatposition()
{
    struct node *head, *tail;
    int i = 1;
    int pos;
    cin >> pos;
    struct node *newnode, *temp;
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    int nn;
    cin >> nn;
    newnode->data = nn;
    newnode->next = 0;
    temp = tail->next;
    // knowing that point is valid and not 1.
    // if it is insert after positon then change while(i<pos).
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void deletefrombeg()
{
    struct node *head, *tail;
    struct node *temp;
    temp = tail->next;
    if (tail == 0)
        cout << "list is empty" << endl;
    else if (temp->next == temp)
    {
        tail = 0;
        free(temp);
    }
    else
    {
        tail->next = temp->next;
        free(temp);
    }
}
void deletefromend()
{
    struct node *head, *tail;
    struct node *curr, *prev;
    curr = tail->next;
    if (tail == 0)
        cout << "list is empty" << endl;
    else if (curr->next == curr)
    {
        tail = 0;
        free(curr);
    }
    else
    {
        while (curr->next != tail->next)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = tail->next;
        tail = prev;
        free(curr);
    }
}
void deletefrompos()
{
    struct node *head, *tail;
    int i = 1;
    int poss;
    cin >> poss;
    struct node *curr, *nextnode;
    curr = tail->next;
    while (i < poss - 1)
    {
        curr = curr->next;
        i++;
    }
    nextnode = curr->next;
    curr->next = nextnode->next;
    free(nextnode);
}
void reverseCLL()
{
    struct node *tail;
    struct node *current, *prev, *nextnode;
    current = tail->next;
    nextnode = current->next;
    while (current != tail)
    {
        prev = current;
        current = nextnode;
        nextnode = current->next;
        current->next = prev;
    }
    nextnode->next = tail;
    tail = nextnode;
}
void display1()
{
    struct node *head, *tail;
    struct node *temp;
    temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp->next != head);
    cout << temp->data;
}
void display()
{
    struct node *head, *tail;
    struct node *temp;
    if (tail == 0)
        cout << "no input by user" << endl;
    else
    {
        temp = tail->next;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp->next != tail->next);
        cout << temp->data;
    }
}
int main()
{
    create();
    display();
    insertatbeg();
    cout << endl;
    display();
    insertatend();
    cout << endl;
    display();
    insertatposition();
    cout << endl;
    display();
    deletefrombeg();
    cout << endl;
    display();
    deletefromend();
    cout << endl;
    display();
    deletefrompos();
    cout << endl;
    display();
    reverseCLL();
    cout << endl;
    display();
}

// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *tail;
void create()
{
    struct node *head, *tail;
    struct node *newnode;
    head = 0;
    int choice = 1;
    while (choice == 1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        int nn;
        cin >> nn;
        newnode->data = nn;
        newnode->prev = NULL;
        newnode->next = NULL;
        if (head == 0)
        {
            head = newnode;
            tail = newnode;
            head->next = head;
            tail->next = tail;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            head->prev = newnode;
            tail = newnode;
        }
        cin >> choice;
    }
}
void insertatbeg()
{
    struct node *head, *tail;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    int nn;
    cin >> nn;
    newnode->data = nn;
    if (head == 0)
    {
        head = newnode;
        tail = newnode;
        newnode->prev = tail;
        newnode->next = head;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = tail;
        tail->next = newnode;
        head = newnode;
    }
}
void insertatend()
{
    struct node *head, *tail;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    int nn;
    cin >> nn;
    newnode->data = nn;
    if (head == 0)
    {
        head = newnode;
        tail = newnode;
        newnode->prev = tail;
        newnode->next = head;
    }
    else
    {
        /*newnode->next=head;
        head->prev=newnode;
        newnode->prev=tail;
        tail->next=newnode;
        head=newnode;(mistake)*/

        newnode->prev = tail;
        tail->next = newnode;
        newnode->next = head;
        head->prev = newnode;
        tail = newnode;
    }
}
void insertatposition()
{
    struct node *head, *tail;
    int i = 1;
    int pos;
    cin >> pos;
    struct node *newnode, *temp;
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    int nn;
    cin >> nn;
    newnode->data = nn;
    // knowing that point is valid and not 1.
    // if it is insert after positon then change while(i<pos).
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
}

void deletefrombeg()
{
    struct node *head, *tail;
    struct node *temp;
    temp = head;
    if (head == 0)
        cout << "list is empty" << endl;
    else if (head->next == head)
    {
        head = 0;
        tail = 0;
        free(temp);
    }
    else
    {
        head = head->next;
        head->prev = tail;
        tail->next = head;
        free(temp);
    }
}
void deletefromend()
{
    struct node *head, *tail;
    struct node *temp;
    temp = tail;
    if (head == 0)
        cout << "list is empty" << endl;
    else if (head->next == head)
    {
        head = 0;
        tail = 0;
        free(temp);
    }
    else
    {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        free(temp);
    }
}
void deletefrompos()
{
    struct node *head, *tail;
    int i = 1;
    int poss;
    cin >> poss;
    struct node *temp;
    temp = head;
    while (i < poss)
    {
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    if (temp->next == head)
    {
        tail = temp->prev;
        free(temp);
    }
    else
        free(temp);
}
void display()
{
    struct node *head, *tail;
    struct node *temp;
    temp = head;
    while (temp != tail)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data;
}
int main()
{
    create();
    display();
    insertatbeg();
    cout << endl;
    display();
    insertatend();
    cout << endl;
    display();
    insertatposition();
    cout << endl;
    display();
    deletefrombeg();
    cout << endl;
    display();
    deletefromend();
    cout << endl;
    display();
    deletefrompos();
    cout << endl;
    display();
}

// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void bubbleSort()
{
    int counts = 0;
    struct node *head, *tail;
    node *temp = head;
    node *last = tail;
    // Traverse the List
    while (temp != last)
    {
        node *min = temp;
        node *r = min->next;

        // Traverse the unsorted sublist
        while (min != last)
        {
            if (min->data > r->data)
            {
                counts++;
                // Swap Data
                int x = r->data;
                r->data = min->data;
                min->data = x;
                display();
                cout << " ";
            }
            min = r;
            r = r->next;
            // last=last->prev;
        }
        last = last->prev;
    }
    cout << counts;
}

node *KthReverseinDLL(node *head, int k)
{
    if (!head)
        return NULL;
    head->prev = NULL;
    int count = 0;
    node *current = head;
    node *temp, *newhead;
    while (current != NULL && count < k)
    {
        newhead = current;
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
        count++;
    }
    if (count >= k)
    {
        node *rest = KthReverseinDLL(current, k);
        head->next = rest;
        if (rest != NULL)
            rest->prev = head;
    }
    return newhead;
}

node *KthReverseinDLL(node *head, int k)
{
    if (!head)
        return head;

    node *st = head;
    node *globprev = NULL;
    node *ans = NULL;
    while (st)
    {
        int count = 1; // to count k nodes
        node *curr = st;
        node *prev = NULL;
        node *next = NULL;
        while (curr && count <= k)
        { // reversing k nodes
            next = curr->next;
            curr->prev = next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (!ans)
        {
            ans = prev; // to store ans i.e the new head
            ans->prev = NULL;
        }

        if (!globprev)
            globprev = st; // assigning the last node of the
                           // reversed k nodes
        else
        {
            globprev->next = prev;
            prev->prev = globprev; // connecting last node of last
                                   // k group to the first node of
                                   // present k group
            globprev = st;
        }

        st = curr; // advancing the pointer for the next k
                   // group
    }
    return ans;
}

// start here
class Node1
{
public:
    int data;
    Node1 *next, *prev;
};

Node1 *split(Node1 *head);

// Function to merge two linked lists
Node1 *merge(Node1 *first, Node1 *second)
{
    // If first linked list is empty
    if (!first)
        return second;

    // If second linked list is empty
    if (!second)
        return first;

    // Pick the smaller value
    if (first->data < second->data)
    {
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

// Function to do merge sort
Node1 *mergeSort(Node1 *head)
{
    if (!head || !head->next)
        return head;
    Node1 *second = split(head);

    // Recur for left and right halves
    head = mergeSort(head);
    second = mergeSort(second);

    // Merge the two sorted halves
    return merge(head, second);
}

// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(Node1 **head, int data)
{
    Node1 *temp = new Node1();
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (!(*head))
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

// A utility function to print a doubly linked list in
// both forward and backward directions
void print(Node1 *head)
{
    Node1 *temp = head;
    cout << "Forward Traversal using next pointer\n";
    while (head)
    {
        cout << head->data << " ";
        temp = head;
        head = head->next;
    }
    cout << "\nBackward Traversal using prev pointer\n";
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

// Utility function to swap two integers
void swap(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Split a doubly linked list (DLL) into 2 DLLs of
// half sizes
Node1 *split(Node1 *head)
{
    Node1 *fast = head, *slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node1 *temp = slow->next;
    slow->next = NULL;
    return temp;
}

// Driver program
int main(void)
{
    Node1 *head = NULL;
    insert(&head, 5);
    insert(&head, 20);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 30);
    insert(&head, 10);
    head = mergeSort(head);
    cout << "Linked List after sorting\n";
    print(head);
    return 0;
}

void check()
{
    struct node *head, *tail;
    int l = 0;
    int sum;
    cin >> sum;
    struct node *ptr1, *ptr2, *ptr3;
    ptr3 = head;
    while (ptr3 != tail)
    {
        ptr1 = ptr3->next;
        while (ptr1 != tail)
        {
            ptr2 = ptr1->next;
            while (ptr2 != tail)
            {
                int a = ptr1->data + ptr2->data + ptr3->data;
                if (a == sum)
                    l++;
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
        ptr3 = ptr3->next;
    }
    cout << l << " ";
    //<<sum;
}

void display()
{
    struct node *head, *tail;
    struct node *temp4;
    map<int, int> m;
    temp4 = head;
    while (temp4 != NULL)
    {
        m[temp4->data]++;
        // cout<<temp->data<<" ";
        temp4 = temp4->next;
    }
    int l = 0;
    int t = 0;
    int sum;
    cin >> sum;
    struct node *temp, *temp1;
    // temp=head;
    temp1 = head;
    while (temp1 != tail)
    {
        temp = temp1->next;
        l = 0;
        while (temp != tail)
        {
            // m[temp->data + temp1->data]++;
            if (m[temp->data] > 0)
                l++;
            if (m[temp1->data] > 0)
                l++;
            if (m[sum - (temp->data) - (temp1->data)] > 0)
                l++;
            // cout<<temp->data<<" ";
            temp = temp->next;
        }
        if (l == 3)
            t++;
        temp1 = temp1->next;
    }
    cout << t << endl
         << t;
}

void displaytwopointerapproch()
{
    struct node *head, *tail;
    int sum;
    cin >> sum;
    char t = 'f';
    struct node *temp, *start, *end, *temp1;
    end = tail;
    temp = head;
    temp1 = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    while (temp1 != tail)
    {
        start = temp1->next;
        while (end != head && start != tail && t == 'f')
        {
            if ((start->data + end->data + temp1->data) > sum)
                end = end->prev;
            else if ((start->data + end->data + temp1->data) < sum)
                start = start->next;
            else
                t = 't';
        }
        temp1 = temp1->next;
    }
    if (t == 't')
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

// A C++ program to sort a linked list using Quicksort
using namespace std;

/* a node of the doubly linked list */
class Node2
{
public:
    int data;
    Node2 *next;
    Node2 *prev;
};

/* A utility function to swap two elements */
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// A utility function to find
// last node of linked list
Node2 *lastNode(Node2 *root)
{
    struct node *head, *tail;
    while (root && root->next)
        root = root->next;
    return root;
}

/* Considers last element as pivot,
places the pivot element at its
correct position in sorted array,
and places all smaller (smaller than
pivot) to left of pivot and all greater
elements to right of pivot */
Node2 *partition(Node2 *l, Node2 *h)
{
    struct node *head, *tail;
    // set pivot as h element
    int x = h->data;

    // similar to i = l-1 for array implementation
    Node2 *i = l->prev;

    // Similar to "for (int j = l; j <= h- 1; j++)"
    for (Node2 *j = l; j != h; j = j->next)
    {
        if (j->data <= x)
        {
            // Similar to i++ for array
            i = (i == NULL) ? l : i->next;

            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL) ? l : i->next; // Similar to i++
    swap(&(i->data), &(h->data));
    return i;
}

/* A recursive implementation
of quicksort for linked list */
void _quickSort(Node2 *l, Node2 *h)
{
    struct node *head, *tail;
    if (h != NULL && l != h && l != h->next)
    {
        Node2 *p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}

// The main function to sort a linked list.
// It mainly calls _quickSort()
void quickSort(Node2 *head)
{
    // Find last node
    Node2 *h = lastNode(head);

    // Call the recursive QuickSort
    _quickSort(head, h);
}

// A utility function to print contents of arr
void printList(Node2 *head)
{
    struct node *head, *tail;
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

/* Function to insert a node at the
beginning of the Doubly Linked List */
void push(Node2 **head_ref, int new_data)
{
    Node2 *new_node = new Node2; /* allocate node */
    new_node->data = new_data;

    /* since we are adding at the
    beginning, prev is always NULL */
    new_node->prev = NULL;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* change prev of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Driver code */
int main()
{
    Node2 *a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);

    cout << "Linked List before sorting \n";
    printList(a);

    quickSort(a);

    cout << "Linked List after sorting \n";
    printList(a);

    return 0;
}

// FLATTEN THE LINKED LIST

class Node3
{
public:
    int data;
    Node3 *right, *down;
};

Node3 *head = NULL;

// An utility function to merge two sorted
// linked lists
Node3 *merge(Node3 *a, Node3 *b)
{

    // If first linked list is empty then second
    // is the answer
    if (a == NULL)
        return b;

    // If second linked list is empty then first
    // is the result
    if (b == NULL)
        return a;

    // Compare the data members of the two linked
    // lists and put the larger one in the result
    Node3 *result;

    if (a->data < b->data)
    {
        result = a;
        result->down = merge(a->down, b);
    }

    else
    {
        result = b;
        result->down = merge(a, b->down);
    }
    result->right = NULL;
    return result;
}

Node3 *flatten(Node3 *root)
{

    // Base Cases
    if (root == NULL || root->right == NULL)
        return root;

    // Recur for list on right
    root->right = flatten(root->right);

    // Now merge
    root = merge(root, root->right);

    // Return the root
    // it will be in turn merged with its left
    return root;
}

// // FLATTEN A MULTILEVEL LINKED LIST

// /* The main function that flattens
// a multilevel linked list */
// void flattenList(Node2 *head)
// {
//     /*Base case*/
//     if (head == NULL)
//     return;

//     Node2 *tmp;

//     /* Find tail node of first level linked list */
//     Node2 *tail = head;
//     while (tail->next != NULL)
//         tail = tail->next;

//     // One by one traverse through all nodes of first level
//     // linked list till we reach the tail node
//     Node2 *cur = head;
//     while (cur != tail)
//     {
//         // If current node has a child
//         if (cur->child)
//         {
//             // then append the child at the end of current list
//             tail->next = cur->child;

//             // and update the tail to new last node
//             tmp = cur->child;
//             while (tmp->next)
//                 tmp = tmp->next;
//             tail = tmp;
//         }

//         // Change current node
//         cur = cur->next;
//     }
// }

// //MULTILEVEL DOUBLE LINKED LIST

// class Solution {
//     Node3* flatten_rec(Node3* head){
//         struct node *head, *tail;
//         Node3* curr = head;
//         Node3* tail = head;
//         while(curr){
//             Node3* child = curr->child;
//             Node3* next = curr->next;
//             if(child){
//                 Node3* _tail = flatten_rec(child);
//                 _tail->next = next;
//                 if(next) next->prev = _tail;
//                 curr->next = child;
//                 curr->child = nullptr;
//                 child->prev = curr;
//                 curr = _tail;
//             }
//             else
//                 curr = next;
//             if(curr) tail = curr;
//         }
//         return tail;
//     }
// public:
//     Node3* flatten(Node3* head) {
//         if(head)
//         flatten_rec(head);
//         return head;
//     }
// };
