#include <iostream>
#include<string>
#include <string>
#include <array>
#include <iterator>
#include <vector>
#include <map>
#include <unordered_map>
#include<set>
#include<stack>
#include <cctype>
#include <algorithm>
#include <fstream>
#include<queue>
#include<cmath>

using namespace std;

//CODE FOR QUICK SPRT START FROM HERE

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

//LAST ELEMENT AS PIVOT AND SMALLER THAN PIVOT IS IN LEFT SIDE ; AND LARGER IN RIGHT SIDE
int partition (int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1); //BECAUSE ONE ELEMENT IS TAKEN BY PIVOT 
	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		//pi is partitioning index, arr[p] is nowat right place 
		int pi = partition(arr, low, high);

		// Separately sort elements before partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArrayy(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

//CODE OF MERGE SORT START FORM HERE

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}

void mergeSort(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}

int main()
{
	int arr[] = {10, 7, 8, 9, 1, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array quickSort: \n";
	printArrayy(arr, n);
	
	cout << "Sorted array mergeSort: \n";
	int A[] = {9, 1, 4, 14, 4, 15, 6};
    n = 7;
    mergeSort(A, 0, 6);
    printArray(A, n);
}

//BACKTRACKING PROBLEM
//RAT IN A MAZE PROBLEM
using namespace std;
#define N 4
bool solveMazeUtil(int maze[N][N], int x, int y,int sol[N][N]);

// A utility function to print solution matrix sol[N][N]
void printSolution(int sol[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout<<" "<<sol[i][j]<<" ";
		cout<<endl;
	}
}

// A utility function to check if x, y is valid index for N*N maze
bool isSafe(int maze[N][N], int x, int y)
{
	// if (x, y outside maze) return false
	if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
		return true;
	return false;
}

// This function solves the Maze problem using Backtracking. It mainly uses solveMazeUtil() to solve the problem.
//  It returns false if no path is possible, otherwise return true and prints the path in the form of 1s. Please
// note that there may be more than one solutions, this function prints one of the feasible solutions.
bool solveMaze(int maze[N][N])
{
	int sol[N][N] = { { 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 } };
	if (solveMazeUtil(maze, 0, 0, sol) == false) {
		cout<<"Solution doesn't exist";
		return false;
	}
	printSolution(sol);
	return true;
}

// A recursive utility function to solve Maze problem
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
	// if (x, y is goal) return true
	if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
		sol[x][y] = 1;
		return true;
	}
	// Check if maze[x][y] is valid
	if (isSafe(maze, x, y)) {
		// Check if the current block is already part of solution path.
		if (sol[x][y] == 1)
			return false;
		// mark x, y as part of solution path
		sol[x][y] = 1;
        // Move forward in x direction 
		if (solveMazeUtil(maze, x + 1, y, sol))
			return true;
		// If moving in x direction doesn't give solution then Move down in y direction
		if (solveMazeUtil(maze, x, y + 1, sol))
			return true;
		// If none of the above movements work then BACKTRACK: unmark x, y as part of solution path
		sol[x][y] = 0;
		return false;
	}
	return false;
}

int main()
{
	int maze[N][N] = { { 1, 0, 0, 0 },
					{ 1, 1, 0, 1 },
					{ 0, 1, 0, 0 },
					{ 1, 1, 1, 1 } };
	solveMaze(maze);
	return 0;
}

//N-QUEEN PROBLEM METHOD ONE        ( TRY AT LAST  )
using namespace std;

class Solution {
  public:
    bool isSafe1(int row, int col, vector < string > board, int n) {
      // check upper element
      int duprow = row;
      int dupcol = col;

      while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row--;
        col--;
      }

      col = dupcol;
      row = duprow;
      while (col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        col--;
      }

      row = duprow;
      col = dupcol;
      while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true;
    }

  public:
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (isSafe1(row, col, board, n)) {
          board[row][col] = 'Q';
          solve(col + 1, board, ans, n);
          board[row][col] = '.';
        }
      }
    }

  public:
    vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      solve(0, board, ans, n);
      return ans;
    }
};
int main() {
  int n = 4; // we are taking 4*4 grid and 4 queens
  Solution obj;
  vector < vector < string >> ans = obj.solveNQueens(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
//SAME ABOVE PROBLEM IN OTHER METHOD
using namespace std;
class Solution {
  public:
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, vector < int > & leftrow, vector < int > & upperDiagonal, vector < int > & lowerDiagonal, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
          board[row][col] = 'Q';
          leftrow[row] = 1;
          lowerDiagonal[row + col] = 1;
          upperDiagonal[n - 1 + col - row] = 1;
          solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
          board[row][col] = '.';
          leftrow[row] = 0;
          lowerDiagonal[row + col] = 0;
          upperDiagonal[n - 1 + col - row] = 0;
        }
      }
    }

  public:
    vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      vector < int > leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
      solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
      return ans;
    }
};
int main() {
  int n = 4; // we are taking 4*4 grid and 4 queens
  Solution obj;
  vector < vector < string >> ans = obj.solveNQueens(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
  }
    cout << endl;
  }
  return 0;
}

//**********************************   NOTE :-  IF CALL THE RECURSIVE FUCTION AFTER SLIGHT CHANGE DURING CALL
// THE FUCTION THEN THHER WILL BE NO POPING IS REQUIRED     ----------     BUT IF YOUR CHANGE IS MADE BEFORE
// CALLING THE RECURSIVE FUNCTION THEN YOU HAVE TO POP BACK THE ELEMENT AGAIN FOR BACKTRACKING THE ELEMENT***

//PROBEM PRACTICE START FROM HERE 

//reverse the stack using recurrsion  (problem-1)
using namespace std;

void insertAtBottom(stack<int>&s,int n)
{
    if(s.empty()){
    s.push(n);
    return;
    }
    else
    {
        int b=s.top();
        s.pop();
        insertAtBottom(s,n);
        s.push(b);
    }
}

void reversestack(stack<int>&s)
{
    if(!s.empty()){
    int a=s.top();
    s.pop();
    reversestack(s);
    insertAtBottom(s,a);}
    return;
}

int main()
{
    stack<int>s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    int n=s.size();
    reversestack(s);
    for(int i=0;i<n;i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}

 //RETURN SUBSET SUM TO K (ALL SUBSET PART)   (problem-2)
using namespace std;

int n;
vector<vector<int>>ans(0,vector<int>(0,0));
vector<int>last(0,0);
void subset(vector<int>v,int sum,int i,vector<int>last)
{
    if(sum==0)
    {
        ans.push_back(last);
        for(auto it:last)
        cout<<it<<" ";
        cout<<endl;
        return;
    }
    if(i==n)
    return;
    subset(v,sum,i+1,last);
    last.push_back(v[i]);
    subset(v,sum-v[i],i+1,last);
}
int main()
{
    cin>>n;
    vector<int>v(n,0);
    for(int i=0;i<n;i++)
    cin>>v[i];
    int sum;cin>>sum;
    subset(v,sum,0,last);
    for(auto it1:ans)
    {
        for(auto it2:it1)
        cout<<it2<<" ";
        cout<<endl;
    }
}

//REACH THE DESTINATION          (problem-3)
using namespace std;
//METHOD-1
int reach(int a,int b,int c,int d)
{
    if(a==c && b==d)
    return 1;
    if(a>c || b>d)
    return 0;
    int x=reach(a+b,b,c,d);
    int y=reach(a,a+b,c,d);
    return x|y;
}

//METHOD-2
int reach1(int a,int b,int c,int d)
{
    if(a==c && b==d)
    return 1;
    if(a>c || b>d)
    return 0;
    int x=reach1(a,b,c-d,d);
    int y=reach1(a,a,c,d-c);
    return x|y;
}

int main()
{
    int a,b;cin>>a>>b;
    int c,d;cin>>c>>d;
    cout<<reach(a,b,c,d);
    cout<<reach1(a,b,c,d);
}

//BINARY STRING WITH NO CONSECTIVE 1'S       (problem-4)
using namespace std;

string s;
vector<string>ans1(0,"");
void consecutive(int n, string s)
{
    if(s.length()==n)
    {
        cout<<s<<" ";
        ans1.push_back(s);
        return;
    }
    if(s[s.length()-1]=='0')
    {
        consecutive(n,s+'0');
        consecutive(n,s+'1');
    }
    else if(s[s.length()-1]=='1')
    {
        consecutive(n,s+'0');
    }
    return;
}
int main()
{
    int n;cin>>n;
    s="0";
    consecutive(n,s);
    s='1';
    consecutive(n,s);
    cout<<ans1.size()<<endl;
    for(auto a:ans1)
    cout<<a<<" ";
}

//PRINT PERMUTATION STRING       (PROBLEM-7)
using namespace std;

string s;
vector<string>ans2(0,"");
void createstring(string s,int l,int r)
{
    if(l==r)
    {
        ans2.push_back(s);
        cout<<s<<" ";
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(s[l],s[i]);
            createstring(s,l+1,r);
            swap(s[l],s[i]);
        }
    }
}
int main()
{
    cin>>s;
    int n=s.length();
    createstring(s,0,n-1);
    cout<<endl;
    for(auto a:ans2)
    cout<<a<<" ";
}

//REPLACE 'O' WITH 'X'     "FLOOD FILL ALGO."    (PROBLEM-5)
using namespace std;

// Size of given matrix is M X N
// int N;
int M;
// A recursive function to replace previous value 'prevV' at '(x, y)'
// and all surrounding values of (x, y) with new value 'newV'.
void floodFillUtil(vector<vector<char>>&mat, int x, int y, char prevV, char newV)
{
	// Base cases
	if (x < 0 || x >= M || y < 0 || y >= N)
		return;
	if (mat[x][y] != prevV)
		return;

	// Replace the color at (x, y)
	mat[x][y] = newV;

	// Recur for north, east, south and west
	floodFillUtil(mat, x+1, y, prevV, newV);
	floodFillUtil(mat, x-1, y, prevV, newV);
	floodFillUtil(mat, x, y+1, prevV, newV);
	floodFillUtil(mat, x, y-1, prevV, newV);
}

// Returns size of maximum size subsquare matrix
// surrounded by 'X'
int replaceSurrounded(vector<vector<char>>&mat)
{
// Step 1: Replace all 'O' with '-'
for (int i=0; i<M; i++)
	for (int j=0; j<N; j++)
		if (mat[i][j] == 'O')
			mat[i][j] = '-';

// Call floodFill for all '-' lying on edges
for (int i=0; i<M; i++) // Left side
	if (mat[i][0] == '-')
		floodFillUtil(mat, i, 0, '-', 'O');
for (int i=0; i<M; i++) // Right side
	if (mat[i][N-1] == '-')
		floodFillUtil(mat, i, N-1, '-', 'O');
for (int i=0; i<N; i++) // Top side
	if (mat[0][i] == '-')
		floodFillUtil(mat, 0, i, '-', 'O');
for (int i=0; i<N; i++) // Bottom side
	if (mat[M-1][i] == '-')
		floodFillUtil(mat, M-1, i, '-', 'O');

// Step 3: Replace all '-' with 'X'
for (int i=0; i<M; i++)
	for (int j=0; j<N; j++)
		if (mat[i][j] == '-')
			mat[i][j] = 'X';
			return 0;
}

// Driver program to test above function
int main()
{
    // cin>>N;
    cin>>M;
    vector<vector<char>>mat(N,vector<char>(M,'0'));
    for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
    cin>>mat[i][j];
    
	replaceSurrounded(mat);
	
	for (int i=0; i<M; i++)
	{
	for (int j=0; j<N; j++)
		cout << mat[i][j] << " ";
	cout<<endl;
	}
	return 0;
}

//IP ADDRESS FINDER    (PROBLEM - 10)
using namespace std;

void getipaddress(vector<string>&temp, vector<string>&ips ,string &s ,int index)
{
    if(index==s.length() && temp.size()==4)
    {
        string validip=temp[0]+'.'+temp[1]+'.'+temp[2]+'.'+temp[3];
        ips.push_back(validip);
        return;
    }

    if(temp.size()>=5) return;   //THIS MAY BE SELF RETURN ALSO NOTE THIS AND THINK

    string tempstr="";
    for(int i=index;i<s.length() && temp.size()<4 ;i++)
    {
        if(s[i]-'0' >9)
        continue;
        tempstr+=s[i];
        int tempint=stoi(tempstr);    //string to integer convertor -> stoi();
        if(0<=tempint && tempint<=255)
        {
            temp.push_back(tempstr);
            getipaddress(temp,ips,s,i+1);
            temp.pop_back();
        }
        if(tempint<=0 || tempint>255)
        break;
    }
}

int main()
{
	string s = "255251135";

    vector<string>ips;
    vector<string>temp;
    getipaddress(temp,ips,s,0);
    
    if(ips.size()==0)
    cout<<"No IP address can be form "<<endl;
    else
    {
        for (string s : ips)
		      cout << s << endl;
    }
	return 0;
}

//SUDOKU SOLVER   (PROBLEM-9)
using namespace std;

bool isValid(vector < vector < char >> & board, int row, int col, char c) {
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == c)
      return false;

    if (board[row][i] == c)
      return false;

    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return false;
  }
  return true;
}

bool solve(vector < vector < char >> & board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      if (board[i][j] == '.') {
        for (char c = '1'; c <= '9'; c++) {
          if (isValid(board, i, j, c)) {
            board[i][j] = c;

            if (solve(board))
              return true;
            else
              board[i][j] = '.';
          }
        }
        return false;
      }
    }
  }  
  return true;
}
int main() {
    vector<vector<char>>board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };
   
    solve(board);
        	
    for(int i= 0; i< 9; i++){
        for(int j= 0; j< 9; j++)
            cout<<board[i][j]<<" ";
            cout<<"\n";
    }
    return 0;
}

//CLOSEST DISTANCE PAIR  BY   DIVIDE AND CONNCER APPROCH    (PROBLEM-6)                  (HARDEST)
using namespace std;

// A structure to represent a Point in 2D plane
class Point
{
	public:
	int x, y;
};

// Needed to sort array of points according to X coordinate
int compareX(const void* a, const void* b)
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->x - p2->x);
}

// Needed to sort array of points according to Y coordinate
int compareY(const void* a, const void* b)
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->y - p2->y);
}

// A utility function to find the distance between two points
float dist(Point p1, Point p2)
{
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +(p1.y - p2.y)*(p1.y - p2.y));
}

// A Brute Force method to return the smallest distance between two points in P[] of size n
float bruteForce(Point P[], int n)
{
	float min = FLT_MAX;
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			if (dist(P[i], P[j]) < min)
				min = dist(P[i], P[j]);
	return min;
}

// A utility function to find minimum of two float values
float min(float x, float y)
{
	return (x < y)? x : y;
}

// A utility function to find the distance between the closest points of strip of given size. All points in
// strip[] are sorted according to y coordinate. They all have an upper bound on minimum distance as d.Note that
// this method seems to be a O(n^2) method, but it's a O(n) method as the inner loop runs at most 6 times
float stripClosest(Point strip[], int size, float d)
{
	float min = d; // Initialize the minimum distance as d

	qsort(strip, size, sizeof(Point), compareY);

	// Pick all points one by one and try the next points till the difference
	// between y coordinates is smaller than d. This is a proven fact that this loop runs at most 6 times
	for (int i = 0; i < size; ++i)
		for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
			if (dist(strip[i],strip[j]) < min)
				min = dist(strip[i], strip[j]);
	return min;
}

// A recursive function to find the smallest distance. The array P contains all points sorted according to x coordinate
float closestUtil(Point P[], int n)
{
	// If there are 2 or 3 points, then use brute force
	if (n <= 3)
		return bruteForce(P, n);

	// Find the middle point
	int mid = n/2;
	Point midPoint = P[mid];

	// Consider the vertical line passing through the middle point calculate
	// the smallest distance dl on left of middle point and dr on right side
	float dl = closestUtil(P, mid);
	float dr = closestUtil(P + mid, n - mid);

	// Find the smaller of two distances
	float d = min(dl, dr);

	// Build an array strip[] that contains points close (closer than d) to the line passing through the middle point
  // where 99999 is the there must be n note:-
	Point strip[99999];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (abs(P[i].x - midPoint.x) < d)
			strip[j] = P[i], j++;

	// Find the closest points in strip. Return the minimum of d and closest distance is strip[]
	return min(d, stripClosest(strip, j, d) );
}

// The main function that finds the smallest distance This method mainly uses closestUtil()
float closest(Point P[], int n)
{
	qsort(P, n, sizeof(Point), compareX);

	// Use recursive function closestUtil() to find the smallest distance
	return closestUtil(P, n);
}

// Driver code
int main()
{
	Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
	int n = sizeof(P) / sizeof(P[0]);
	cout << "The smallest distance is " << closest(P, n);
	return 0;
}
