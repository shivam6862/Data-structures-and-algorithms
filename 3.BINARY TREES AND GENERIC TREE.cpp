#include <iostream>
#include<string>
#include <string>
#include <array>
#include <iterator>
#include <vector>
#include <map>
#include <unordered_map>
#include<set>
#include<queue>
#include<stack>
#include <cctype>
#include <algorithm>
#include <fstream>

using namespace std;

struct node{
    int data;
    struct node *left, *right;
};
//1 2 4 -1 7 9 -1 -1 -1 -1 3 5 -1 -1 6 -1 -1 9
struct node *create()
{
    struct node *newnode,*note;
    newnode =(struct node *)malloc(sizeof(struct node));
    int x;cin>>x;
    if(x==-1)
    return NULL;
    note=newnode;
    newnode->data=x;
    newnode->left=create();
    newnode->right=create();
    return note;
}
void preorder (struct node *root)
{
    if(root==0)
    return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder (struct node *root)
{
    if(root==0)
    return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void inorder (struct node *root)
{
    if(root==0)
    return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void printLevelOrder(node* root)
{
    if (root == NULL)
        return;
    // Create an empty queue for level order traversal
    queue<node*> q;
    // Enqueue Root and initialize height
    q.push(root);
    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        node* curr = q.front();
        cout << curr->data << " ";
        q.pop();
        // Enqueue left child 
        if (curr->left != NULL)
            q.push(curr->left);
        //Enqueue right child 
        if (curr->right != NULL)
            q.push(curr->right);
    }
}
int counting(node *root)
{
    int leftcount , rightcount;
    if(root==0)
    return 0;
    
    if(root->data>0)
    leftcount = counting(root->left);
    rightcount = counting(root->right);
    return leftcount + rightcount+1;
}
int maxvalue(node *root)
{
    int leftmax , rightmax;
    if(root==0)
    return 0;

    leftmax = max(root->data,maxvalue(root->left));
    rightmax = max(root->data,maxvalue(root->right));
    return max(leftmax,rightmax);
}
int searchvalue(node *root,int num)
{
    int leftsearch , rightsearch;
    if(root==0)
    return 0;
    if(root->data==num)
    return 1;
    else
    return searchvalue(root->left,num) | searchvalue(root->right,num);
}
int Heightcountingg(node *root)
{
    int leftcount , rightcount;
    if(root==0)
    return 0;
    
    if(root->data>0)
    leftcount = Heightcountingg(root->left);
    rightcount = Heightcountingg(root->right);
    return 1+max(leftcount, rightcount);
}
int main()
{
    struct node *root;
    root=0;
    root=create();
    cout<<"preorder :- ";
    preorder(root);
    cout<<endl;
    cout<<"postorder :- ";
    postorder(root);
    cout<<endl;
    cout<<"Inorder :- ";
    inorder(root);
    cout<<endl;
    cout<<"Level order :- ";
    printLevelOrder(root);
    cout<<endl<<"counting of the node is : "<<counting(root)<<endl;
    cout<<"maxvalue of the node is : "<<maxvalue(root)<<endl;
    int num;cin>>num;
    int ll=searchvalue(root,num);
    if(ll==1)
    cout<<"Searching a number in the node is : "<<"found"<<endl;
    else
    cout<<"Searching a number in the node is : "<<"not found"<<endl;
    cout<<"Height of a binary tree : "<<Heightcountingg(root)-1<<endl;
   
}

//GENERIC TREES 

struct Node1{
    int data;
    vector<Node1*> children;
};
Node1 *newnode(int val)
{
    Node1 *node =new Node1;
    node->data=val;
    return node;
}
Node1 *create(vector<int>arr, int n)
{
    Node1 *root=NULL;
    stack<Node1*>st;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==-1){
        st.pop();}
        else
        {
            Node1 *t=newnode(arr[i]);
            if(st.size()==0)
            root=t;
            else
            {
                st.top()->children.push_back(t);
            }
            st.push(t);
        }
    }
    return root;
}
void display(Node1 *curr)
{
    string str=to_string(curr->data)+" -> ";
    for(Node1 *child : curr->children)
    {
        str+=" ,"+to_string(child->data);
    }
    str+=".";
    cout<<str<<endl;
    for(Node1 *child :curr->children)
    display(child);
}

void LevelOrderTraversal(Node1 * root)
{
    if (root==NULL)
        return;
    // Standard level order traversal code
    // using queue
    queue<Node1 *> q;  // Create a queue
    q.push(root); // Enqueue root
    while (!q.empty())
    {
        int n = q.size();
 
        // If this node has children
        while (n > 0)
        {
            // Dequeue an item from queue and print it
            Node1 * p = q.front();
            q.pop();
            cout << p->data << " ";
            // Enqueue all children of the dequeued item
            for (int i=0; i<p->children.size(); i++)
                q.push(p->children[i]);
            n--;
        }
        cout << endl; // Print new line between two levels
    }
}
//https://takeuforward.org/data-structure/strivers-tree-series-tree-data-structure/
int main()
{
    vector<int>v;
    v.assign({10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1});
    Node1 *root=create(v,v.size());
    display(root);
    cout<<endl<<endl;
    LevelOrderTraversal(root);
}
//PROBLEM
void maxpathsum(node *root, int *maxi, int curr_sum)
{
/*dependencies of recurrsion is shown by of write hat part with curr_sum
but    not changing dependencies is shown by pointer maxi that is (*maxi)
and each times faching the element pointer is used */
    if(root==0)
    return ;
    curr_sum=curr_sum+root->data;
    if(root->left == NULL && root->right==NULL)
    {
        *maxi=max(curr_sum,*maxi);
    }
    maxpathsum(root->left,maxi,curr_sum);
    maxpathsum(root->right,maxi,curr_sum);
}
//SAME ABOVE PROBLEM IN OTHER WAYS
int maxpathsum(node *root)
{
    int sum=-9999999;
    if(root==0)
    return 0;
    if(root->left!=NULL){
        if(sum>maxpathsum(root->left))
        sum=sum;
        else
        sum=maxpathsum(root->left);}
    if(root->right!=NULL)
    {
        if(sum>maxpathsum(root->right))
        sum=sum;
        else
        sum=maxpathsum(root->right);}
        if(sum==-9999999)
        sum=0;
    return sum+root->data;
}
//ANAGRAM FIDING IN THE DIAGNOL ELEMENT
map<int,int>m;int maxslope=0;
void maxpathsum(node *root, int d, map<int,int>&m)
{
    if(root==0)
    return ;
    if(maxslope>d)
    maxslope=maxslope;
    else
    maxslope=d;
    if(m[root->data]>0)
    m[root->data]=m[root->data]-d;
    else
    m[root->data]=d;
    maxpathsum(root->left,d+1,m);
    maxpathsum(root->right,d,m);
}
int main()
{
    struct node *root;struct node *root1;
    root=0;
    root=create();
    root1=create();
    //cout<<1;
    maxpathsum(root,0,m);
    maxpathsum(root1,0,m);
    //cout<<2;
    char tt='t';
    for(auto &pr :m){
        if(pr.second!=0)
        tt='f';
    }
    if(tt=='t')
    cout<<"anagram found"<<endl;
    else
    cout<<"anagram not found"<<endl;
    //cout<<pr.first<<" "<<pr.second<<endl;

}
//SAME PROBLEM WITH OTHER METHOD
vector <vector <int>> result;
void diagonalPrint(node* root)
{
    if(root == NULL)
        return;
    queue <node*> q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        vector <int> answer;
        while(size--)
        {
            node* temp = q.front();
            q.pop();
            // traversing each component;
            while(temp)
            {
                answer.push_back(temp->data);
                if(temp->left)
                    q.push(temp->left);
 
                temp = temp->right;
            }
        }
        result.push_back(answer);
    }
}
vector <vector <int>> result1;
void diagonalPrintt(node* root)
{
    if(root == NULL)
        return;
    queue <node*> q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        vector <int> answer;
        while(size--)
        {
            node* temp = q.front();
            q.pop();
            // traversing each component;
            while(temp)
            {
                answer.push_back(temp->data);
 
                if(temp->left)
                    q.push(temp->left);
 
                temp = temp->right;
            }
        }
        result1.push_back(answer);
    }
}
int main()
{
    struct node *root;struct node *root1;
    root=0;
    root=create();
    root1=create();
    diagonalPrint(root);
    diagonalPrintt(root1);
    char ttt='t';
    for(int i=0 ; i<result.size() ; i++)
    {
        sort(result[i].begin(),result[i].end());
        sort(result1[i].begin(),result1[i].end());
        for(int j=0 ; j<result[i].size() ; j++){
            if(result[i][j]!=result1[i][j])
            ttt='f';
        }
    }
    if(ttt=='t')
    cout<<"anagram found"<<endl;
    else
    cout<<"anagram not found"<<endl;
}

//COUNTING ELEMENT IN ALL SUB-GENERIC TREE
map<int,int>m;
int subtreesum(Node1 *node)
{
    int sum=0;
    
    for(Node1 *child :node->children){
        int csum=subtreesum(child);
        sum=sum+csum;}
        sum=sum+1;
        m[node->data]=sum;
        return sum;
}
//COUNTING ELEMENT IN ALL SUB-BINARY TREE
map<int,int>m;int maxslope=0;
void postorder (struct node *root)
{
    if(root==0)
    return ;
    postorder(root->left);
    postorder(root->right);
    if(root->left!=NULL && root->right!=NULL)
    m[root->data]=1+m[(root->left->data)]+m[root->right->data];
    if(root->left!=NULL && root->right==NULL)
    m[root->data]=1+m[(root->left->data)];
    if(root->left==NULL && root->right!=NULL)
    m[root->data]=1+m[root->right->data];
    if(root->left==NULL && root->right==NULL)
    m[root->data]=1;
}
//COUNTING SUM OF ELEMENT IN ALL SUB GENERIC TREES 
int msum=0;int msumnode=0;
map<int,int>m;
int subtreesum(Node1 *node)
{
    int sum=0;
    
    for(Node1 *child :node->children){
        int csum=subtreesum(child);
        sum=sum+csum;}
        sum=sum+node->data;
        if(sum>msum)
        {
            msumnode=node->data;
            msum=sum;
        }
        return sum;
}
//COUNTING THE SPECIAL NODE INA GENERIC TREE
map<int,int>m,mm;
void subtreesum(Node1 *node)
{
    m[node->data]++;
    for(Node1 *child :node->children){
        subtreesum(child);
    }
    char t='t';
    for(auto it: m)
    {
        if(it.second>1)
        t='f'; 
        //cout<<it.first<<"->"<<it.second<<" ";
    }
    if(t=='t'){
    mm[1]++;}
    m[node->data]--;
}//cout<<mm[1];


//LOWEST COMMAN ANASTER
map<int,node*>m;
void preorder(struct node *root,int aa)
{
    if(root==0)
    return ;
    if(root->data==aa)
    m[1]= root;
    //cout<<root->data<<" ";
    preorder(root->left,aa);
    preorder(root->right,aa);
}
node *loestcommananester(node *root, node *p, node *q)
{
    if(root==NULL || root==p || root ==q)
    return root;
    node *left=loestcommananester(root->left,p,q);
    node *right=loestcommananester(root->right,p,q);
    if(left==NULL)
    return right;
    else if(right==NULL)
    return left;
    else
    return root;
}
int main()
{
    struct node *root,*pp,*qq,*rr;
    root=0;
    root=create();
    int p,q,r;cin>>p>>q>>r;
    preorder(root,p);pp=m[1];
    preorder(root,q);qq=m[1];
    preorder(root,r);rr=m[1];
    //cout<<loestcommananester(root,pp,qq)->data;
    cout<<loestcommananester(root,rr,loestcommananester(root,pp,qq))->data;
}

//BINARY TREE FROM A PARENT ARRAY
using namespace std;
struct node2{
    int data;
    struct node2 *left, *right;
    node2() {}
    node2(int x) { data = x; }
};
node2* createTree(int parent[], int n)
{
    vector<node2*> ref;
    node2* root = new node2();
    for (int i = 0; i < n; i++) {
        node2* temp = new node2(i);
        ref.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        if (parent[i] == -1) {
            root = ref[i];
        }
        else {
            if (ref[parent[i]]->left == NULL)
                ref[parent[i]]->left = ref[i];
            else
                ref[parent[i]]->right = ref[i];
        }
    }
    return root;
}
void inorder(node2* root)
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int main()
{
    int parent[] = { -1, 0, 0, 1, 1, 3, 5 };
    int n = sizeof parent / sizeof parent[0];
    node2* root1 = createTree(parent, n);
    cout << "Inorder Traversal of constructed tree\n";
    inorder(root1);cout<<endl;
}



//not understood
// C++ program to construct a Binary Tree from parent array
using namespace std;

// A tree node
struct Node3
{
	int key;
	struct Node3 *left, *right;
};

// Utility function to create new Node
Node3 *newNode(int key)
{
	Node3 *temp = new Node3;
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}

// Creates a node with key as 'i'. If i is root, then it changes
// root. If parent of i is not created, then it creates parent first
void createNode(int parent[], int i, Node3 *created[], Node3 **root)
{
	// If this node is already created
	if (created[i] != NULL)
		return;

	// Create a new node and set created[i]
	created[i] = newNode(i);

	// If 'i' is root, change root pointer and return
	if (parent[i] == -1)
	{
		*root = created[i];
		return;
	}

	// If parent is not created, then create parent first
	if (created[parent[i]] == NULL)
		createNode(parent, parent[i], created, root);

	// Find parent pointer
	Node3 *p = created[parent[i]];

	// If this is first child of parent
	if (p->left == NULL)
		p->left = created[i];
	else // If second child
		p->right = created[i];
}

// Creates tree from parent[0..n-1] and returns root of the created tree
Node3 *createTree(int parent[], int n)
{
	// Create an array created[] to keep track
	// of created nodes, initialize all entries
	// as NULL
	Node3 *created[n];
	for (int i=0; i<n; i++)
		created[i] = NULL;

	Node3 *root = NULL;
	for (int i=0; i<n; i++)
		createNode(parent, i, created, &root);

	return root;
}

//For adding new line in a program
inline void newLine(){
	cout << "\n";
}

// Utility function to do inorder traversal
void inorder(Node3 *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

// Driver method
int main()
{
	int parent[] = {-1, 0, 0, 1, 1, 3, 5};
	int n = sizeof parent / sizeof parent[0];
	Node3 *root = createTree(parent, n);
	cout << "Inorder Traversal of constructed tree\n";
	inorder(root);
	newLine();
}
