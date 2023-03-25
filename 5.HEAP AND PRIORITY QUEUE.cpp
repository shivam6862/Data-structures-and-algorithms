// create->arr->heap->arr convert and vice versa
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
#include <queue>

using namespace std;
class heap
{
public:
    int arr[100];
    int size = 0;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    // This is the method of creating the max-heap by taking each element single times
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            // This method creating the max-heap
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }
    // deletion is must be done on either a min-heap or a maxheap tree NOTE THIS IT IS VERY IMPORTANT

    // THIS CODE TELL US TO DELETE THE ROOT NODE ONLY
    void deletefromheap()
    {
        if (size == 0)
        {
            cout << "nothing to delete from heap" << endl;
            return;
        }
        // SWAPING THE NEW ELEMENT WITH FIRST ELEMENT
        arr[1] = arr[size];
        size--;
        // NOW PROPOGATE THE root node to the correct position

        // THIS CODE ALSO START WITH (1,2,3...)
        int i = 1;
        while (i < size)
        {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;
            if (leftindex < size && arr[i] < arr[leftindex])
            {
                swap(arr[i], arr[leftindex]);
                i = leftindex;
            }
            else if (rightindex < size && arr[i] < arr[rightindex])
            {
                swap(arr[i], arr[rightindex]);
                i = rightindex;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// CODE TO FORM THE MAX-HEAP
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[largest] < arr[left])
        largest = left;
    if (right <= n && arr[largest] < arr[right])
        largest = right;
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

// THIS CODE OF HEAPSORT IS PRE-ASSUME THAT THE TOP ELEMENT IS THE MAXIMUN ELEMENT IN THE HEAP
// OF MAY BE THE SMALLEST ELEMENT

// DEPENDENC OF HEAPSORT IS DECRESSING OR INCREASING DEPEND ON THE FIRST ELEMENT OF THE TYPE OF HEAPIFY YOU ARE CALLING

// NOTE THERE WILL BE NOT CHANGE IN HEAPSORT FUNCTION IT IS ONLY DEPEND ON HEAPIFY FUNCTION

// max-heap IS GIVIN A MINUMUM HEAPSORT RESULT AND MINHEAP GIVES MAXIMUM HEAPSORT RESULT     NOTE THIS

void heapsort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}

// CODE OF MIN-HEAP WITH '0' BASED INDEXING

/*void heapify(int arr[], int n, int i)
{
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[smallest]>arr[left])
    smallest=left;
    if(right<n && arr[smallest]>arr[right])
    smallest=right;
    if(smallest!=i)
    {
        swap(arr[smallest],arr[i]);
        heapify(arr,n,smallest);
    }
}*/

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.deletefromheap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    // CALL heaapify FUNCTION TO CONVERTING INTO MAX-HEAP WITH ONE BASED INDEXING (NEXT TWO LINE OF CODE).
    for (int i = n / 2; i > 0; i--)
        heapify(arr, n, i);

    // FOR '0' BASED INDEXING
    /* for(int i=n/2-1;i>=0;i--)
       heapify(arr,n,i);*/

    cout << "print the heapifyed array now" << endl;
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;

    /*for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);*/
    heapsort(arr, n);
    cout << "print the heapifyed array after sorting now" << endl;
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // PRIORITY QUEUE IS MAX-HEAP
    priority_queue<int> pq;
    pq.push(5);
    pq.push(4);
    pq.push(2);
    pq.push(3);
    pq.push(1);
    cout << "Element in the top " << pq.top() << endl;
    pq.pop();
    cout << "Element in the top " << pq.top() << endl;
    cout << pq.size() << endl;
    if (pq.empty())
        cout << "pq is empty " << endl;
    else
        cout << "pq is not empty " << endl;

    // MIN heap IS CREATING LIKE THIS
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(5);
    minheap.push(4);
    minheap.push(2);
    minheap.push(3);
    minheap.push(1);
    cout << "Element in the top of minheap " << minheap.top() << endl;
    minheap.pop();
    cout << "Element in the top of minheap " << minheap.top() << endl;
    cout << pq.size() << endl;
    // }

    // PROBLEM

    // finding kth largeat using heap sort
    // min-heap creating of first kth element creating by sorting
    int k = 5;
    heapsort(arr, k);
    for (int i = k; i <= n; i++)
    {
        if (arr[i] > arr[1])
        {
            arr[1] = arr[i];
            heapsort(arr, k);
        }
    }
    cout << arr[1];
}
// MINIMUM 'K' PRIODUCT
// Max-heap of first kth element CREATed BY SORTING
int main()
{
    int arr[6] = {0, 5, 2, 3, 8, 3};
    int n = 5;
    // CALL heaapify FUNCTION TO CONVERTING INTO MAX-HEAP WITH ONE BASED INDEXING (NEXT TWO LINE OF CODE).

    for (int i = n / 2; i > 0; i--)
        heapify(arr, n, i);

    heapsort(arr, 5); // minheap this is

    for (int i = n; i >= 1; i--)
        cout << arr[i] << " ";

    int k = 3; //?

    int pro = 1;
    for (int i = 1; i <= k; i++)
        pro = pro * arr[i];
    cout<< pro;
}

// STRING TRANFORMATION
int main()
{
    char arr[6] = {'0', 'e', 'd', 'c', 'b', 'a'};
    int n = 5;
    int k = 4;
    // CALL heaapify FUNCTION TO CONVERTING INTO MAX-HEAP WITH ONE BASED INDEXING (NEXT TWO LINE OF CODE).

    for (int i = k / 2; i > 0; i--)
        heapify(arr, k, i);

    // cout<<arr[1];

    for (int i = k + 1; i <= n; i++)
    {
        cout << arr[1] << " ";
        arr[1] = arr[i];
        for (int j = k / 2; j > 0; j--)
            heapify(arr, k, j);
        //<<arr[k]<<" ";
    }

    char v[5] = {'0', '0', '0', '0', '0'};
    int aa = 1;
    // cout<<"print the heapifyed array now"<<endl;
    for (int i = 1; i <= k; i++)
    {
        // cout<<arr[i]<<" ";
        v[aa] = arr[i];
        aa++;
    }
    // cout<<endl;

    for (int i = 5 / 2; i > 0; i--)
        heapify(v, 4, i);

    /*for(int i=1;i<=k;i++)
    cout<<v[i]<<" ";
    cout<<endl*/

    heapsort(v, 4);
    // cout<<endl;
    for (int i = k; i >= 1; i--)
        cout << v[i] << " ";
}

// CONERTING MAXHEAP TO MINHEAP
int main()
{
    int arr[6] = {0, 5, 2, 3, 8, 3};
    int n = 5;
    // CALL heaapify FUNCTION TO CONVERTING INTO MAX-HEAP WITH ONE BASED INDEXING (NEXT TWO LINE OF CODE).

    for (int i = n / 2; i > 0; i--)
        heapify(arr, n, i);

    heapsort(arr, 5);
    // cout<<endl;
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";

    cout << endl;

    for (int i = n / 2; i > 0; i--)
        heapify1(arr, n, i);

    heapsort1(arr, 5);
    // cout<<endl;
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
}

// RUNNING MEDIAN ( 6 )
int main()
{
    int arr[16] = {0, 6, 2, 1, 3, 7, 5, 5, 9, 3, 2, 6, 4, 1, 5, 8};
    int n = 15;
    // CALL heaapify FUNCTION TO CONVERTING INTO MAX-HEAP WITH ONE BASED INDEXING (NEXT TWO LINE OF CODE).

    int k = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = k / 2; j > 0; j--)
            heapify(arr, k, j);
        heapsort(arr, k);
        if (k % 2 == 0)
        {
            int sum = 0;
            int ss = (k / 2) + 1;
            int ll = (k / 2);
            cout << (arr[ss] + arr[ll]) / 2 << " ";
        }
        else
        {
            int ss = k + 1;
            cout << arr[ss / 2] << " ";
        }
        /*for(int i=1;i<=k;i++)
        cout<<arr[i]<<" ";
        cout<<endl;*/
        k++;
    }
}

// MINIMUM CHARCTER DELETION
int minCntCharDeletionsfrequency(string &str, int N)
{
    unordered_map<char, int> mp;
    priority_queue<int> pq;
    int cntChar = 0;
    for (int i = 0; i < N; i++)
    {
        mp[str[i]]++;
    }
    for (auto it : mp)
    {
        pq.push(it.second);
    }
    while (!pq.empty())
    {
        int frequent = pq.top();
        pq.pop();
        if (pq.empty())
        {
            return cntChar;
        }
        if (frequent == pq.top())
        {
            if (frequent > 1)
            {
                pq.push(frequent - 1);
            }
            cntChar++;
        }
    }
    return cntChar;
}
int main()
{
    string str = "abbbcccd";
    int N = str.length();
    cout << minCntCharDeletionsfrequency(str, N);
    return 0;
}
// K MOST FREQUENT WORD
int main()
{
    map<string, int> m;
    string s;
    string a = "";
    getline(cin, s);
    s = s + " ";
    int w;
    cin >> w;
    for (int i = 0; i < s.length(); i++)
    {
        if ((int)s[i] != 32)
        {
            a = a + s[i];
        }
        else
        {
            m[a]++;
            // cout<<a<<endl;
            a = "";
        }
    }

    vector<pair<int, string>> v;
    for (auto it : m)
    {
        v.push_back({it.second, it.first});
    }
    sort(v.rbegin(), v.rend());

    int gg = 0;
    int aa = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i - 1].first == v[i].first)
            gg++;
        else
        {
            gg = gg + 1;
            for (int j = 0; j < gg / 2; j++)
                swap(v[aa + j].second, v[aa + gg - j - 1].second);
            gg = 0;
            aa = i;
        }
    }
    gg = gg + 1;
    for (int j = 0; j < gg / 2; j++)
        swap(v[aa + j].second, v[aa + gg - j - 1].second);

    for (int i = 0; i < w; i++)
        cout << v[i].second << " ";
    cout << endl;
}
