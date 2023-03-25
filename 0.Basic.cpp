// codewithharry.com/videos/data-structures-and-algorithms-in-hindi-24
//  ****************************************PAIR**************************
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
int main()
{
    pair<int, string> p;
    // p=make_pair(2,"shivam");
    p = {3, "shivam"};
    // coping way
    pair<int, string> &p1 = p;
    p1.first = 4;
    cout << p.first << " " << p.second << endl;
    // array in pair
    pair<int, int> parr[3];
    parr[0] = {1, 2};
    parr[1] = {2, 3};
    parr[2] = {3, 4};
    swap(parr[0], parr[2]); // swaping the two pair
    for (int i = 0; i < 3; i++)
        cout << parr[i].first << " " << parr[i].second << endl;
    // user input
    pair<double, int> p3;
    cin >> p3.first >> p3.second;
    cout << p3.first << " " << p3.second << endl;
}

// *******************************************VECTOR************************/**
using namespace std;

void printvec(vector<int> &v) // pass by value "v" O(n)  and pass by reference is "&v"O(1)
{
    cout << "size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    v.push_back(3);
    cout << endl;
}
int main()
{
    vector<int> v; // initialization way    " same as array limit of number "
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        // printvec(v);
        v.push_back(x); // learn this input syntax
    }
    printvec(v);
    // another
    vector<int> v1(4, 5); // pre-initilization of vector 4 times 5....
    v1.push_back(9);
    v1.push_back(8); // o(1)

    printvec(v1);
    // anotner usefull function
    v1.pop_back(); // o(1)
    printvec(v1);
    // coping of vector
    vector<int> v2 = v1; // NOTE the comp. is O(n) [here also we can take &v2=v1 pass by reference]
    v2.push_back(45);
    printvec(v1);
    printvec(v1);
    printvec(v2);
}

// ******************************VECTOR OF PAIR**************************
using namespace std;

void printvec(vector<pair<int, int>> &v) // pass by value "v" O(n), reference is "&v"O(1)
{
    cout << "size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
    cout << endl;
}
int main()
{
    // pre input
    vector<pair<int, int>> v = {{1, 2}, {2, 3}, {3, 4}};
    printvec(v);
    // user define input
    vector<pair<int, int>> v1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        // v1.push_back(make_pair(x,y));
        v1.push_back({x, y});
    }
    printvec(v1);
}
// ****************************ARRAY OF VECTOR**************************
using namespace std;

void printvec(vector<int> &v) // pass by value "v" O(n), reference is "&v"O(1)
{
    cout << "size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    int N;
    cin >> N;
    vector<int> v[20]; // way I do not know 20 ans but N not
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    for (int i = 0; i < N; i++)
        printvec(v[i]);
    cout << v[2][0];
}

// *************************VECTOR OF VECTOR**************************
using namespace std;

void printvec(vector<int> &v) // pass by value "v" O(n), reference is "&v"O(1)
{
    cout << "size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    int N;
    cin >> N;
    vector<vector<int>> v;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        vector<int> temp;
        // v.push_back(vector<int> ());
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
            // v[i].push_back(x);
        }
        v.push_back(temp);
    }
    v[0].push_back(10);
    v.push_back(vector<int>());
    for (int i = 0; i < v.size(); i++)
        printvec(v[i]);
    cout << v[2][0];
}

// ***************************************ITERATOR*******************************
using namespace std;

int main()
{
    vector<int> v = {2, 3, 4, 5, 6, 7};
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    // SYNTAX to initili... the iterator
    vector<int>::iterator it = v.begin();
    cout << *it + 1 << endl;                  //(it++) used to move in next iterator
    for (it = v.begin(); it != v.end(); it++) //(it+1) used to move next location "not used in map ,sets"
        cout << (*it) << " ";                 // MAP and SET are not continus hence not(it +1)
    cout << endl;

    vector<pair<int, int>> vp = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    vector<pair<int, int>>::iterator it1;
    for (it1 = vp.begin(); it1 != vp.end(); it1++)
        cout << it1->first << " " << it1->second << endl;
    // cout<<(*it1).first<<" "<<(*it1).second<<endl;     (same thing (*).  and  ->  )
}

// ************************ITERATOR AND AUTO************************
using namespace std;

int main()
{
    vector<int> v = {2, 3, 4, 5, 6, 7};
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    // ANOTHER WAY OF WRITING THE VALUE OF ITERATOR......
    for (int value : v)
    {
        cout << value << " ";
    }
    cout << endl;
    // PASSS BY REFEERENCE OF THE GIVEN ITERATOR.......
    for (int &value : v)
    {
        value++;
    }
    for (int value : v)
    {
        cout << value << " ";
    }
    cout << endl;

    // VECTOR IN PAIR
    vector<pair<int, int>> vp = {{1, 2}, {2, 3}, {3, 4}};
    for (pair<int, int> &value1 : vp) // pair<int,int> OR auto
        cout << value1.first << " " << value1.second << endl;

    //*************USE OF AUTO KEYWORD********
    auto a = 1.0;
    cout << a << endl;

    for (auto it = v.begin(); it != v.end(); it++)
        cout << (*it) << " ";
    cout << endl;

    for (auto &value1 : vp) // pair<int,int> OR auto
        cout << value1.first << " " << value1.second << " ";
    cout << endl;
}

// ****************************************MAP**************************
using namespace std;

int main()
{
    /* SORTED MAP IN "RED BLACK TREES ". MAP GENERALLY STORE IN SMALLER TO LARGER ORDER
    MAP TAKES A 'KEY' AND 'VALUE'.
    MAP IS NOT CONTINIUS IN NATURE . IT HAVING A LINK WITH EACH OTHER
    IT+1 WRONG BUT IT++ RIGHT */

    map<int, string> m;
    m[1] = "abc";
    m[5] = "cde"; // TIME IS O(log(n))
    m[3] = "qwer";
    m[6]; // BY DEFULT A SPACE IS TAKEN
    m.insert({4, "dfghj"});
    m.insert(make_pair(2, "shivam"));
    m[5] = "ghjklf"; //"KEYS" ARE UNIQUE IN A MAP "REPLACICNG TAKES PLACE ALWAYS"

    /*  map<int,string> :: iterator it;
      for(it=m.begin();it!=m.end();it++)
      cout<<(*it).first<<" "<<it->second<<endl;*/

    m.erase(3);           // ERASE FUNCTION o(log(n)) is the time comp...
    auto it1 = m.find(4); // ERASING BY ITERATOR
    if (it1 != m.end())
        m.erase(it1);

    // m.clear();   " "
    for (auto &pr : m) // TIME IS O(log(n)    [ IF N VALUE IS THERE THEN TOTAL TIME IS N*log(N)]
        cout << pr.first << " " << pr.second << endl;

    auto it = m.find(2); // TIME IS O(log(n))
    if (it == m.end())
        cout << "NO VALUE" << endl;
    else
        cout << (*it).first << " " << it->second << endl;

    // IT DEPEND ALSO ON SIZE OF KEY IF KEY IS A STRING "   s.size* O(log(n))       "
}
// **************************UNORDERED MAP******************
// 1.	HASH TABLE USED
// 2.	REPLACE map WITH unordered_map
// 3.	Change Use header file
// 4.	Time is input is  O(1)
// 5.	Find and erase also O(1) time
// 6.	Pair<int,int>  not used ; set; vector;pair ; not used  not complie
// 7.

// ##############FINDING THE FREQUENCY OF WORD AND KEEPING THE WORD IN INCRESING ORDER #######

using namespace std;

int main()
{
    map<string, int> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        m[s]++;
    }
    for (auto pr : m)
        cout << pr.first << " " << pr.second << endl;
}

// ****************************************SET**************************

using namespace std;

void print(set<string> &s)
{
    for (string value : s)
        cout << value << "  ";
    cout << endl;
    /* for(auto it=s.begin();it!=s.end();it++)
     cout<<(*it)<<"  ";
     cout<<endl;*/
}
int main()
{
    set<string> s;
    s.insert("asdf"); // log(n)
    s.insert("qwrt");
    s.insert("asdfgh");
    s.insert("zxcvbn"); // UNIQUE ELEMENT STORE IN SET
    s.insert("qwrt");

    auto it = s.find("asdf"); // log(n)
    if (it != s.end())
        cout << (*it) << endl;

    auto it1 = s.find("asdfgh");
    if (it1 != s.end())
        s.erase(it1);

    s.erase("asdf");
    print(s);
}
// *****************************UNORDERED SET   AND MULTISET
// 1.	Set REPLACE  unordered_set
// 2.	WRITE HEADRE FILE

// REPLACE set to multiset
// same value multiple times
// IF DELETING THROUGH ITERATOR THEN SINGLE VALUE IS DELETED BUT IF
// DELETING THROUGH s.erase("asd");   THEN ALL PRESENT asd IS DELETED
// ALL log(n) OPERATION
// ******************SET AND MULTISET PROBLEM**************
int main()
{
    set<string> s; //	PRINTING THE NAME SINGLE TIME
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        s.insert(str);
    }
    for (auto val : s)
        cout << val << endl;
}

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        multiset<long long> bags;
        for (int i = 0; i < n; i++)
        {
            long long candyct;
            cin >> candyct;
            bags.insert(candyct);
        }
        long long total = 0;
        for (int i = 0; i < k; i++)
        {
            auto lastit = (--bags.end());
            long long candyct = *lastit;
            total += candyct;
            bags.erase(lastit);
            bags.insert(candyct / 2);
        }
        cout << total;
    }
}

// ####################################MAST PROGRAM####################################
using namespace std;

int main()
{ // map<set<int>,int> m; pair<int,int> p1,p2,p3; p1={3,2}; p2={2,3}; p3={4,5};cout<<(p1>p2)<<endl; cout<<(p3<p1)<<endl;
  // set<int>s1={1,2,3,4}; set<int>s2={2,3,4}; cout<<(s1>s2)<<endl;
    map<pair<string, string>, vector<int>> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string fn, ln;
        int ct;
        cin >> fn >> ln >> ct;
        for (int j = 0; j < ct; j++)
        {
            int x;
            cin >> x;
            m[{fn, ln}].push_back(x);
        }
    }
    for (auto &pr : m)
    {
        auto &fullname = pr.first;
        auto &list = pr.second;
        cout << fullname.first << " " << fullname.second << endl;
        cout << list.size() << endl;
        for (auto &element : list)
            cout << element << " ";
        cout << endl;
    }
}

// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// 1.	STACK – LIFO (LAST IN FIRST OUT)
// 2.	TOP IN
// 3.	Push
// 4.	Pop
// 5.	Top
// 6.	BOTTAL EXAMPLE

// 1.	QUEUE – FIFO( FIRST IN FIRST OUT)
// 2.	Push
// 3.	Pop
// 4.	Front
// 5.	ROAD EXAMPLE

using namespace std;

int main()
{
    //*********************************** STACK****************************

    stack<int> s;
    s.push(6);
    s.push(4);
    s.push(9);
    s.push(7);
    s.push(1);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    //*********************************** QUEUE****************************
    queue<string> q;
    q.push("shivam");
    q.push("ram");
    q.push("sita");
    q.push("rohan");
    q.push("sohan");
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

//****************** STACK BALANCED BRACKET MATCHING ************

using namespace std;

unordered_map<char, int> symbols = {{'[', -1}, {'(', -2}, {'{', -3}, {']', 1}, {')', 2}, {'}', 3}};
string isbalanced(string s)
{
    stack<char> st;
    for (char bracket : s)
    {
        if (symbols[bracket] < 0)
            st.push(bracket);
        else
        {
            if (st.empty())
                return "NO";
            char top = st.top();
            st.pop();
            if (symbols[top] + symbols[bracket] != 0)
                return "NO";
        }
    }
    if (st.empty())
        return "YES";
    return "NO";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << isbalanced(s) << endl;
    }
}
// ****************** STACK NEXT GREATER ELEMENT ************
using namespace std;

vector<int> NGE(vector<int> v)
{
    vector<int> nge(v.size());
    stack<int> st;
    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() && v[i] > v[st.top()])
        {
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        nge[st.top()] = -1;
        st.pop();
    }
    return nge;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> nge = NGE(v);
    for (int i = 0; i < n; i++)
        cout << v[i] << " " << (nge[i] == -1 ? -1 : v[nge[i]]) << endl;
}

// ************************************************* SORTING ****************************
using namespace std;

int main()
{
    // ARRAY SORTING
    int n;
    cin >> n;
    int a[500];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    // sort(a+3,a+n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    // TIME IS n(log(n)......
    // VECTOR SORTING
    int nn;
    cin >> nn;
    vector<int> v(nn);
    for (int i = 0; i < nn; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    // sort(v.begin()+2,v.end());
    for (int i = 0; i < nn; i++)
        cout << v[i] << " ";
    cout << endl;
}

// ******************************** SORTING ****************************
using namespace std;

/*bool should_i_swap(int a,int b)
{
    if(a>b)
    return true;
    return false;
}*/

bool should_i_swap(pair<int, int> a, pair<int, int> b)
{
    /*  if(a>b)
      return true;
      return false;*/

    if (a.first != b.first)
    {
        if (a.first > b.first)
            return true;
        return false;
    }
    if (a.second < b.second)
        return true;
    return false;
}
int main()
{
    int n;
    cin >> n;
    // vector<int>a(n);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    // cin>>a[i];

    /*  for(int i=0;i<n;i++)
      {
          for(int j=i+1;j<n;j++)
          {
              if(should_i_swap(a[i],a[j]))
              swap(a[i],a[j]);
          }
      }*/
    sort(a.begin(), a.end(), should_i_swap); // INBUILT SORTING IS OPPISITE IN NATURE
    for (int i = 0; i < n; i++)
        cout << a[i].first << " " << a[i].second << endl;
    // cout<<a[i]<<" ";
    cout << endl;
}

// ***********************************COMPARATOR FUNCTION*****************
using namespace std;

bool CMP(pair<int, int> a, pair<int, int> b)
{
    /*  if(a.first != b.first){
          if(a.first>b.first)
          return false;
          return true;
      }
      if(a.second<b.second)
      return false;
      return true;*/

    if (a.first != b.first)
        return (a.first < b.first);
    return (a.second > b.second);
}

/* bool cmp (int a,int b){ return a>b }*/

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second; // greater<pair<int,int>>()" in PLACE OF CMP INBUILT FUNCTION

    sort(a.begin(), a.end(), CMP); // INBUILT SORTING IS OPPISITE IN NATURE
    for (int i = 0; i < n; i++)    // SWAP KARNA HAI OT HAMKO FALSE RETURN KARO
        cout << a[i].first << " " << a[i].second << endl;
    cout << endl;
}

// ******************UPPER BOUND AND LOWER BOUND array and vector***********
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[1000000000];
    // vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    // sort(a.begin(),a.end());
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    // int *ptr=lower_bound(a,a+n,5);
    // int *ptr=upper_bound(a,a+n,5);    //time is log(n)
    int *ptr = upper_bound(a + 3, a + n, 5);
    // auto it=upper_bound(a.begin(),a.end(),5);
    // if(it==a.end())
    if (ptr == (a + n))
    {
        cout << "NOT FOUND";
        return 0;
    }
    cout << (*ptr) << endl;
    // cout<<(*it)<<endl;
}
// *************************UPPER BOUND AND LOWER BOUND in set*****************
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    auto it = s.lower_bound(5);
    cout << (*it) << endl;
}

// *************************INBUILT ALGORITHMS*****************
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    // MIN ELEMENT
    int min = *(min_element(v.begin(), v.end()));
    cout << min << endl;

    // MAX ELEMENT
    int max = *(max_element(v.begin(), v.end()));
    cout << max << endl;

    // SUM OF ELEMENT
    int sum = 0;
    // sum =accumulate(v.begin(),v.end(),0);
    cout << sum << endl;

    // COUNT OF EACH ONE ELEMENT
    int ct = count(v.begin() + 1, v.end(), 3);
    cout << ct << endl;
    // O(n) TIME IS
    // FINDING OF ANY ELEMENT
    auto it = find(v.begin(), v.end(), 4);
    if (it != v.end())
        cout << *it << endl;
    else
        cout << "element not found " << endl;
    // IN ARRAY v.begin() CHANGE TO v and v.end()CHANGE TO (v+n)
    // REVERSE OF SET
    reverse(v.begin(), v.end());
    for (auto val : v)
        cout << val << " ";
    cout << endl;

    // REVERSE OF STRING
    string s = "asdfgghjkl";
    reverse(s.begin() + 1, s.end());
    cout << s << endl;
}

// *************************INBUILT ALGORITHMS lambda function*****************
using namespace std;

bool ispos(int x)
{
    return x > 0;
}
int main()
{
    cout << [](int x)
    { return x + 2; }(2)
         << endl;
    cout << [](int x, int y)
    { return x + y; }(4, 7)
         << endl;
    auto sum = [](int x, int y)
    { return x + y; };
    cout << sum(2, 3);

    // ALL OF FUNCTION
    vector<int> v = {2, 34, 5, 6};
    cout << all_of(v.begin(), v.end(), [](int x)
                   { return x > 0; }); // true or false
    cout << all_of(v.begin(), v.end(), ispos);

    // ALL OF FUNCTION
    cout << any_of(v.begin(), v.end(), [](int x)
                   { return x > 0; }); // true or false
                                       // NONE OF FUNCTION
    cout << none_of(v.begin(), v.end(), [](int x)
                    { return x > 0; }); // true or false

    // APPLY TO ARRAY ALSO SAME CHANGE APPLIED
    // IF ODD AND EVEN CHANGE THE REPLACE THE RETURN STATEMENT BY x%2==0
}
// **********GENERATE PARENTHESIS RECURSION AND BACKTRACKING*********
using namespace std;

vector<string> valid;
void generate(string &s, int open, int close)
{
    if (open == 0 && close == 0)
    {
        valid.push_back(s);
        return;
    }
    if (open > 0)
    {
        s.push_back('(');
        generate(s, open - 1, close);
        s.pop_back();
    }
    if (close > 0)
    {
        if (open < close)
        {
            s.push_back(')');
            generate(s, open, close - 1);
            s.pop_back();
        }
    }
}
int main()
{
    int n;
    cin >> n;
    string s;
    generate(s, n, n);
    for (auto ele : valid)
        cout << ele << endl;
}

// **********GENERATE SUBSETS RECURSION AND BACKTRACKING*********
using namespace std;

vector<vector<int>> subsets;
void generate(vector<int> &subset, int i, vector<int> &nums)
{
    if (i == nums.size())
    {
        subsets.push_back(subset);
        return;
    }
    // ith element not in the subset
    generate(subset, i + 1, nums);

    // ith element in the subset
    subset.push_back(nums[i]);
    generate(subset, i + 1, nums);
    subset.pop_back();
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> empty;
    generate(empty, 0, nums);
    for (auto subset : subsets)
    {
        for (auto ele : subset)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}
// *******************************************BINARY SEARCH*****************************
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int find;
    cin >> find;
    int lo = 0;
    int hi = n - 1;
    int mid;
    while (hi - lo > 1)
    {
        int mid = (hi + lo) / 2; // TIME is log(n)  base 2
        if (v[mid] < find)
            lo = mid + 1;
        else
            hi = mid;
    }
    if (v[lo] == find)
        cout << lo << endl;
    else if (v[hi] == find)
        cout << hi << endl;
    else
        cout << "NOT FOUND" << endl;
}

// ***************BINARY SEARCH lower bound and upper bound**************
using namespace std;

int lower_bound(vector<int> &v, int element) // lower  to upper
{

    int lo = 0;
    int hi = v.size() - 1;
    int mid;
    while (hi - lo > 1)
    {
        int mid = (hi + lo) / 2; // TIME is log(n)  base 2
        if (v[mid] < element)    //  <  t0    <=
            lo = mid + 1;
        else
            hi = mid;
    }
    if (v[lo] >= element) //>=   to    >
        return lo;
    if (v[hi] >= element) //>=     to     >
        return hi;
    return -1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int element;
    cin >> element;
    int lb = lower_bound(v, element); // lower     to    upper
    cout << lb << " " << (lb != -1 ? v[lb] : -1) << endl;
}

// ********************BINARY SEARCH square root and nth root **********************
using namespace std;

double eps = 1e-7;
double multiply(double mid, int n)
{
    double ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans *= mid;
    }
    return ans;
}
int main()
{
    double x;
    cin >> x;
    int n;
    cin >> n;
    double lo = 1, hi = x, mid;
    while (hi - lo > eps)
    {
        mid = (hi + lo) / 2;
        //  if((mid*mid)<x)
        if (multiply(mid, n) < x) // TIME IS log(n*(10^d)for square root and n*(lod(n*(10^d))) for mu;tiply
            lo = mid;
        else
            hi = mid;
    }
    cout << lo << "\n"
         << hi << endl;
    cout << pow(x, (1.0 / n)) << endl;
}

// *************BINARY SEARCH tree cutting and max length and min wood ********
using namespace std;

int n;
long long m;
long long trees[10000000];
bool iswoodsuff(int h)
{
    long long wood = 0;
    for (int i = 0; i < n; i++)
    {
        if (trees[i] >= h)
            wood += (trees[i] - h);
    }
    return wood >= m;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> trees[i];
    }
    long long lo = 0, hi = 1e9, mid;
    // tttttffffff
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (iswoodsuff(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    if (iswoodsuff(hi))
        cout << hi << endl;
    else
        cout << lo << endl; // TIME IS     O(n*log(n))
}

// *************BINARY SEARCH cows min distance placing  ********

using namespace std;

int n, cows;
int positions[1000000];

bool canplacecows(int mindist)
{
    int lastpos = -1;
    int cows_ct = cows;
    for (int i = 0; i < n; i++)
    {
        if (positions[i] - lastpos >= mindist || lastpos == -1)
        {
            cows_ct--;
            lastpos = positions[i];
        }
        if (cows_ct == 0)
            break;
    }
    if (cows_ct == 0)
        return true;
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> cows;
        for (int i = 0; i < n; i++)
            cin >> positions[i];
    }
    sort(positions, positions + n); // n*log(n)
    // TTTTTTTTTTTFFFFFFFFF
    int lo = 0, hi = 1e9, mid;
    while (hi - lo > 1)
    {
        int mid = (lo + hi) / 2;
        if (canplacecows(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    //  log(10^9)*n
    if (canplacecows(hi))
        cout << hi << endl;
    else
        cout << lo << endl;
}
