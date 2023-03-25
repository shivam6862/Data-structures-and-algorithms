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
    struct node *left, *right;
};
struct node *create()
{
    struct node *newnode, *note;
    newnode = (struct node *)malloc(sizeof(struct node));
    int x;
    cin >> x;
    if (x == -1)
        return 0;
    note = newnode;
    newnode->data = x;
    newnode->left = create();
    newnode->right = create();
    return note;
}
struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left and right children to NULL
    n->right = NULL;                                // Setting the left and right children to NULL
    return n;                                       // Finally returning the created node
}
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
int ll = 0;
map<int, int> m;
void Kthsmallestelement(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        m[1]++;
        if (m[1] == ll)
            cout << root->data;
        inOrder(root->right);
    }
}
vector<int> vv;
void inOrderr(struct node *root)
{
    stack<node *> s;
    node *curr = root;
    while (!s.empty() || curr != NULL)
    {
        if (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = s.top();
            s.pop();
            cout << curr->data << " ";
            vv.push_back(curr->data);
            curr = curr->right;
        }
    }
}
// MORRIS TRANVERSAL
vector<int> inorderrr;
vector<int> getinoder(struct node *root)
{
    struct node *curr = root;
    while (curr != NULL)
    {
        // checkimng that we are present in the left most node or not
        if (curr->left == NULL)
        {
            inorderrr.push_back(curr->data);
            curr = curr->right;
        }
        else
        { // if not reached then move the (curr->left) to prev
            struct node *prev = curr->left;
            // then go to the right most tree node
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            // and after reaching the right most portion if it is nullptr pointing then ,, make the threading
            if (prev->right == NULL)
            {
                prev->right = curr;
                // replace to here for preorder traversal
                curr = curr->left;
            }
            else
            {
                // if we again reaching the threading point then remove the threading ,, push ,,, move pointer
                prev->right = NULL;
                inorderrr.push_back(curr->data); // this line
                curr = curr->right;
            }
        }
    }
    return inorderrr;
}
// FINDING THAT TREE IS BINARY OR NOT
int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
// SEARCHING IN ABINARY TREE
struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}
struct node *searchIter(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}
// INSERATING IN A BINARY TREE
void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot insert %d, already in BST", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *newO = createNode(key);
    if (key < prev->data)
    {
        prev->left = newO;
    }
    else
    {
        prev->right = newO;
    }
}
struct node *inOrderPredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *inordersuccessor(struct node *root, int p)
{
    struct node *successor = NULL;
    while (root != NULL)
    {
        if (p >= root->data)
            root = root->right;
        else
        {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}
struct node *inOrderPredecessorr(struct node *root, int p)
{
    struct node *Predecessorr = NULL;
    while (root != NULL)
    {
        if (p <= root->data)
            root = root->left;
        else
        {
            Predecessorr = root;
            root = root->right;
        }
    }
    return Predecessorr;
}
struct node *deleteNode(struct node *root, int value)
{

    struct node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    // searching for the node to be deleted
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    // deletion strategy when the node is found
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}
int main()
{

    struct node *root;
    root = 0;
    root = create();
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4
    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    cout << deleteNode(p, 6)->data << endl;
    inOrder(p);
    // insert(p, 16);
    // printf("%d", p->right->right->data);
    cout << endl
         << endl
         << isBST(root);
    cout << endl
         << endl
         << inordersuccessor(root, 42)->data;
    cout << endl
         << endl
         << inOrderPredecessorr(root, 35)->data;
    return 0;
}
// FINDING KTH SMALLEST USING MORRIS TRAVERSL
int yy = 0;
int ksmall = -999;
int getinoder1(struct node *root)
{
    int count = 0;
    struct node *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            count++;
            if (count == yy)
                ksmall = curr->data;
            curr = curr->right;
        }
        else
        {
            struct node *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                count++;
                if (count == yy)
                    ksmall = curr->data;
                curr = curr->right;
            }
        }
    }
    return ksmall; // cin>>yy;
}
// converting BT to BST
map<int, int> m;
void binartreetoBST(struct node *root)
{
    vector<int>v;
    if (root != NULL)
    {
        binartreetoBST(root->left);
        root->data = v[m[1]];
        m[1]++;
        // printf("%d ", root->data);
        binartreetoBST(root->right);
    }
}

// THINK AS MUCH YOU CAN
//  C++ implementation of above approach
using namespace std;

/* Link list node */
class LNode
{
public:
    int data;
    LNode *next;
};

/* A Binary Tree node */
class TNode
{
public:
    int data;
    TNode *left;
    TNode *right;
};

TNode *newNode(int data);
int countLNodes(LNode *head);
TNode *sortedListToBSTRecur(LNode **head_ref, int n);

/* This function counts the number of
nodes in Linked List and then calls
sortedListToBSTRecur() to construct BST */
TNode *sortedListToBST(LNode *head)
{
    /*Count the number of nodes in Linked List */
    int n = countLNodes(head);

    /* Construct BST */
    return sortedListToBSTRecur(&head, n);
}

/* The main function that constructs
balanced BST and returns root of it.
head_ref --> Pointer to pointer to
head node of linked list n --> No.
of nodes in Linked List */
TNode *sortedListToBSTRecur(LNode **head_ref, int n)
{
    /* Base Case */
    if (n <= 0)
        return NULL;

    /* Recursively construct the left subtree */
    TNode *left = sortedListToBSTRecur(head_ref, n / 2);

    /* Allocate memory for root, and
    link the above constructed left
    subtree with root */
    TNode *root = newNode((*head_ref)->data);
    root->left = left;

    /* Change head pointer of Linked List
    for parent recursive calls */
    *head_ref = (*head_ref)->next;

    /* Recursively construct the right
        subtree and link it with root
        The number of nodes in right subtree
        is total nodes - nodes in
        left subtree - 1 (for root) which is n-n/2-1*/
    root->right = sortedListToBSTRecur(head_ref, n - n / 2 - 1);

    return root;
}

/* UTILITY FUNCTIONS */

/* A utility function that returns
count of nodes in a given Linked List */
int countLNodes(LNode *head)
{
    int count = 0;
    LNode *temp = head;
    while (temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

/* Function to insert a node
at the beginning of the linked list */
void push(LNode **head_ref, int new_data)
{
    /* allocate node */
    LNode *new_node = new LNode();

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(LNode *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
TNode *newNode(int data)
{
    TNode *node = new TNode();
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/* A utility function to
print preorder traversal of BST */
void preOrder(TNode *node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

/* Driver code*/
int main()
{
    /* Start with the empty list */
    LNode *head = NULL;

    /* Let us create a sorted linked list to test the functions
    Created linked list will be 1->2->3->4->5->6->7 */
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << "Given Linked List ";
    printList(head);

    /* Convert List to BST */
    TNode *root = sortedListToBST(head);
    cout << "\nPreOrder Traversal of constructed BST ";
    preOrder(root);

    return 0;
}
// SPECIAL QUESTION LEAARN THE FROMULA total number of bst
using namespace std;
int fact(int num)
{
    int fact = 1;

    while (num > 1)
    {
        fact *= num;
        num -= 1;
    }
    return fact;
}
int catalan(int n)
{
    return fact(2 * n) / (fact(n) * fact(n + 1));
}
int main()
{
    int n = 5;
    // THIS THING YOU MAKE IN ALINKED LIST THEN MAKE THE COCEPT AS AS BELOW
    int arr[] = {1, 2, 3, 4, 5};
    int i, k;
    for (k = 0; k < n; k++)
    {
        int s = 0;
        for (i = 0; i < n; i++)
        {
            if (arr[i] < arr[k])
                s += 1;
        }
        int catalan_leftBST = catalan(s);
        int catalan_rightBST = catalan(n - s - 1);
        int totalBST = catalan_rightBST * catalan_leftBST;
        cout << totalBST << " ";
    }
}
// same as above problem
//  Returns value of Binomial Coefficient C(n, k)
unsigned long int binomialCoeff(unsigned int n,
                                unsigned int k)
{
    unsigned long int res = 1;
    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;
    // Calculate value of [n*(n-1)*---*(n-k+1)] /
    // [k*(k-1)*---*1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
// A Binomial coefficient based function to find nth catalan
unsigned long int catalan(unsigned int n)
{
    // Calculate value of 2nCn
    unsigned long int c = binomialCoeff(2 * n, n);
    // return 2nCn/(n+1)
    return c / (n + 1);
}
int main()
{
    for (int i = 0; i < 10; i++)
        cout << catalan(i) << " ";
    return 0;
}

// USING TWO POINTER APPORCH
//  Function to find a pair with given sum
bool existsPair(struct node *root, int x)
{
    // Iterators for BST
    stack<node *> it1, it2;
    // Initializing forward iterator
    node *c = root;
    while (c != NULL)
        it1.push(c), c = c->left;

    // Initializing backward iterator
    c = root;
    while (c != NULL)
        it2.push(c), c = c->right;

    // Two pointer technique
    while (it1.top() != it2.top())
    {

        // Variables to store values at
        // it1 and it2
        int v1 = it1.top()->data, v2 = it2.top()->data;

        // Base case
        if (v1 + v2 == x)
            return true;

        // Moving forward pointer
        if (v1 + v2 < x)
        {
            c = it1.top()->right;
            it1.pop();
            while (c != NULL)
                it1.push(c), c = c->left;
        }
        // Moving backward pointer
        else
        {
            c = it2.top()->left;
            it2.pop();
            while (c != NULL)
                it2.push(c), c = c->right;
        }
    }
    // Case when no pair is found
    return false;
}
