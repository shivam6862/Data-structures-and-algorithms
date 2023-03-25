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
#include <cmath>

using namespace std;

/*1048575 == binary (11111111111)

00000
01011
10011
11110
 1st ,2nd, and, or,xor
AND -> &
OR  ->  |
XOR ->  ^
R.S ->  >> (dividing by 2)
LS ->    << (multiplying by 2)
EX:-   3<<2
3=11 (binary form)
(SEE THE DIRECTION OF THE ARROW)
3<<2 ==   1100
3>>1  ==1
NOTE :-  1<<N == POW(2,N)

*NOTE THE PATTERN OF POSITIVE AND NEGATIVE NUMBER*/
int main()
{
    printbinary(156);
    printbinary(-156);
    cout << endl;
    printbinary(567);
    printbinary(-567);
    cout << endl;
    printbinary(678);
    printbinary(-678);
    cout << endl;
}

// (FIRST ONE KA PHALA SARA SIMILAR THE OPPOSITE TO THE ORGINAL)
/*00010011100
  11101100100

01000110111
10111001001

01010100110
10101011010*/
// #######################FIRST CLASS##########################
using namespace std;
void printbinary(int num)
{
    // cout<<((num>>1)&1)<<endl;
    for (int i = 10; i >= 0; --i)
    {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}
int main()
{

    // 0th bits = least siginificant bit (LSB);nth bit(in n bit no.)=most significant bit (MSB)
    // SET =1 ; UNSET =0
    // IF YOU WANT TO GET   ith  BITS SET THEN DO    1<<i
    //  (000010000)-(1)==  (000001111)==  (2 ka power -1)
    //

    printbinary(9);
    int a = 9;
    int i = 3;
    if ((a & (1 << i)) != 0)
        cout << "set bits" << endl;
    else
        cout << "not set bit" << endl;
    // BIT SET you have to do
    printbinary(a | (1 << 1)); // first 1 as a number and second 1 as a ith num you want to make 1

    // INVERTING THE BINARY
    printbinary(~a);
    printbinary(~(1 << 3)); // 3 is ith place

    // BITS UNSETING
    printbinary(a & (~(1 << 3))); // 3 is ith place

    // TOGGLE
    printbinary(a ^ (1 << 2)); // toggle the number 0f “a”  in 2nd position
    printbinary(a ^ (1 << 3));

    // COUNTING SET BITS
    int c = 0;
    for (int i = 31; i >= 0; --i)
    {
        if ((a & (1 << i)) != 0)
            c++;
    }
    cout << c << endl;

    // INBUILT COUNTING
    // cout<<__builtin_popcount(a)<<endl;// USED FOR INTEGER ONLY
    //  cout<<__builtin_popcountll(1LL<<35)<<endl;// USED FOR long long number ONLY
}

// #######################SECOND CLASS#######################
using namespace std;

void printbinary(int num)
{
    for (int i = 10; i >= 0; --i)
    {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}
int main()
{
    // FINDING ODD OR EVEN OF A NUMBER
    for (int i = 0; i <= 8; i++)
    {
        printbinary(i);
        if (i & 1)
            cout << "ODD" << endl;
        else
            cout << "EVEN" << endl;
    }

    // DIVIDINDG BY 2 AND MULTIPLING BY 2
    int n = 10;
    cout << (n >> 1) << endl; //(divide)
    cout << (n << 1) << endl;

    // UPPER CASE LOWER CASE CONVERSATION
    for (char c = 'A'; c <= 'C'; ++c)
    {
        cout << c << " ";
        printbinary(int(c));
    }
    for (char c = 'a'; c <= 'c'; ++c)
    {
        cout << c << " ";
        printbinary(int(c));
    }

    char A = 'A';
    char a = A | (1 << 5);
    cout << a << endl;                     //(small)
    cout << char(a & (~(1 << 5))) << endl; //(capital)
    printbinary('_');
    cout << char(1 << 5) << endl;

    // CONVERSATIO
    // 3N DIRECT FORMULA
    cout << char('C' | ' ') << endl; // UPPERCASE TO LOWER CASE
    cout << char('c' & '_') << endl; // LOWERCASE TO UPPERCASE   “_” ascii  95 ;

    // CLEARING (LSB) LEAST SIGNI. BITS
    /*  1111100000
        0000011111
        0000100000
        REVERSE (FIRST -1), (USE THIS ~)*/
    printbinary(2345);
    int a = 2345;
    int i = 4;
    int b = (a & (~((1 << (i + 1)) - 1)));
    printbinary(b);

    // CLEARING (MSD) MOST SIGNT. BITS
    /* 0000011111
       0000100000 -1*/
    i = 3;
    int c = (a & ((1 << (i + 1)) - 1));
    printbinary(c);

    // POWER OF 2
    int nn = 128;
    if (nn & (nn - 1))
        cout << "NOT POWER OF TWO" << endl;
    else
        cout << "POWER OF 2" << endl;
}

// #######################Third ^ use  CLASS####################
using namespace std;
void printbinary(int num)
{
    for (int i = 10; i >= 0; --i)
    {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}
int main()
{
    // XOR
    /* 1 0->1
       0 1_>1
       0 0->0
       1 1->0
       101  101  = 000
       101  000  = 101
       x^x =0
       x^0= x*/
    // SWAP OF NUMBER
    int a = 4, b = 6;
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
    cout << a << " " << b << endl;

    // FINDING ODD NUMBER IN THE SET OF ARRAY
    int n;
    cin >> n;
    int x, ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        ans = ans ^ x; // O(n) time complexity but O(1) space
    }
    cout << ans << endl;
}

// #####################Third BIT MASKING####################
//  NUMBER OF COMMAN DAYS CAN TWO WORKER CAN WORKS TOGTHER
int main()
{
    int n;
    int p1 = -1, p2 = -1;
    cin >> n;
    vector<int> masks(n, 0);
    for (int i = 0; i < n; i++)
    {
        int numworkers;
        cin >> numworkers;
        int mask = 0;
        for (int j = 0; j < numworkers; j++)
        {
            int day;
            cin >> day;
            mask = (mask | (1 << day));
        }
        masks[i] = mask;
    }
    int maxdays = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int intersection = (masks[i] & masks[j]);
            int commonday = 0;
            for (int kk = 31; kk >= 0; --kk)
            {
                if ((intersection & (1 << kk)) != 0)
                    commonday++;
            }
            maxdays = max(maxdays, commonday);
        }
    }
    cout << maxdays;
}

// ############FOURTH SUBSET GENERATION################
//  SUBSET GENERATION
using namespace std;
vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    int subset_ct = (1 << n);
    vector<vector<int>> subsets;
    for (int mask = 0; mask < subset_ct; ++mask)
    {
        vector<int> subset;
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) != 0)
            {
                subset.push_back(nums[i]);
            }
        }
        subsets.push_back(subset); // TIME IS O(N* POW(2,N))
    }
    return subsets;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    auto all_subsets = subsets(v);
    for (auto subset : all_subsets)
    {
        for (int ele : subset)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}

// ############FIVE LCM AND HCF################
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, (a % b));
}
int main()
{
    int a, b;
    // NOTE
    //  (a*b)/(GCD)=(LCM)
    //  (a/b)==(a/gcd(a,b)/(b/gcd(a,b) minimum fraction
    cout << gcd(12, 4) << endl;
    cout << gcd(18, 12) << endl;
    cout << gcd(12, 18) << endl;
    cout << "LCM " << (12 * 18) / gcd(12, 18) << endl;
    // cout<<__gcd(12,18)<<endl;
}
// ############SIX  binary exponentiation################
using namespace std;
const int m = 1e9 + 7;
int ber(int a, int b)
{
    if (b == 0)
        return 1;
    long long res = ber(a, b / 2);
    if (b & 1)
    {
        // return (a*(res*res));
        return (a * (res * res) % m) % m;
    }
    else
        return (res * res) % m; // return (res*res);
}
int main()
{
    // pow is giving double datatype answer
    int a = 2, b = 100;
    cout << ber(a, b) << endl;
}

// ############SIX  binary exponentiation iterator############
using namespace std;
const int m = 1e9 + 7;
int be(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans * 1LL * a); // ans=(ans*1LL*a)%m;
        a = (a * 1LL * a);         // a=(a*1LL*a)%m;
        b >>= 1;
    }
    return ans;
}
int main()
{
    cout << be(2, 10) << endl;
}
// ############SEVEN  binary exponentiation############
//  CASE WHEN A<=10^18      AND      M<=10^18
using namespace std;
const long long int m = 1e18 + 7; // m<=10^18   it create overflow

long long bm(long long a, long long b)
{
    long long ans = 0;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return ans;
}
long long be(long long a, long long b)
{
    // if a<=10^18 then use   (((a%m)^b)%m)

    long long ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = bm(ans, a);
        a = bm(a, a);
        b >>= 1;
    }
    return ans;
}

int main()
{
    cout << be(22, 100) << endl;
}

// #########SEVEN  binary exponentiation formula###########
using namespace std;
/*fia(n)= n*{ (1-(1/p)) ........}  "p" is the all prime factor of "n" each time one
    ***** prime factor is a prime number and dividing that number *****
     EX:-
     fia(5)= 5*(1-(1/5)=4
     fia(6)= 6*(1-(1/2))*(1-(1/3)) =2
     fia() gives  the "number" of co-prime of the number

     SPECIAL CASE WHEN " n " is a prime number
     fia(n) = n*(1-(1/n)) = (n-1)

     EULAR THEORAM
     (a^b)%n = (a^(b%(fia(n))) %n)
     SPECIAL CASE WHEN " n " IS PREIME NUMBER
     (a^b)%n = (a^(b%(n-1)) %n)
*/
const int m = 10e9 + 7;
int be(int a, long long b, int m)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return ans;
}
int main()
{
    // 50^64^32
    cout << be(50, be(64, 32, m - 1), m);
}
// ##########EIGHT NUMBER SUM AND COUNTING  #########

int main()
{
    int n;
    cin >> n;
    int ct = 0;
    int sum = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        { // cout<<i<<" "<<n/i<<endl;
            ct += 1;
            sum += i;
            if (n / i != i)
            {
                sum += n / i;
                ct += 1;
            }
        }
    }
    cout << ct << " " << sum << endl; // TIME IS O(sqrt(n))
}
// #################NINE PRIME FACTOR####################
//  EX:-36    -----    2,2,3,3.
int main()
{
    int n;
    cin >> n;
    vector<int> prime_factors;
    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            prime_factors.push_back(i);
            n /= i;
        }
    }
    for (int prime : prime_factors)
        cout << prime << " ";
}
// #################NINE PRIME FACTOR####################

// SMALLER TIME COMPLICITY USING
int main()
{
    int n;
    cin >> n;
    vector<int> prime_factors;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            prime_factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        prime_factors.push_back(n);
    for (int prime : prime_factors)
        cout << prime << " "; // TIME IS O(sqrt(n))
}

/*
    NUMBER OF DIVISOR  x= (p1^n1)*(p2^n2)*............(pt^nt)
    ct=(n1+1)*(n2+1)*...........(nt+1)
    sum= (p1^(n1+1)-1)/(p1-1) * (p2^(n2+1)-1)/(p2-1) * .........*(pt^(nt+1)-1)/(pt+1)
    */

// #################TEN SIEVE####################
using namespace std;
const int n = 1e7 + 10;
vector<bool> isprime(n, 1);
int main()
{
    /*
    N(1/2 + 1/3 + 1/4 + 1/5 ........)  ==  n*log(n)       { when loop run to all number }
    N(1/2 + 1/3 + 1/5 +1/7 + 1/11 + .........   + 1/(PRIME NUMBER ))  == n(log (log (n)))     { when loop run to prime number only
    */
    isprime[0] = isprime[1] = false;
    for (int i = 2; i < n; i++)
    {
        if (isprime[i] == true)
        {
            for (int j = 2 * i; j < n; j += i)
            {
                isprime[j] = false;
            }
        }
    }
    // n*log(log(n))

    int q;
    cin >> q;
    while (q--)
    {
        int num;
        cin >> num;
        if (isprime[num])
            cout << "PRIME" << endl;
        else
            cout << "NOT PRIME" << endl;
    }
}

// #################TEN SIEVE####################
//  EX :-
using namespace std;
const int n = 1e7 + 10;
vector<bool> isprime(n, 1);
vector<int> lp(n, 0), hp(n);

int main()
{
    isprime[0] = isprime[1] = false;
    for (int i = 2; i < n; i++)
    {
        if (isprime[i] == true)
        {
            lp[i] = hp[i] = i;
            for (int j = 2 * i; j < n; j += i)
            {
                isprime[j] = false;
                hp[j] = i;
                if (lp[j] == 0)
                    lp[j] = i;
            }
        }
    }
    //  for(int i=2;i<100;i++)
    //  cout<<lp[i]<<" "<<hp[i]<<endl;

    int num;
    cin >> num;
    // vector<int>primefactors;
    map<int, int> primefactors;
    while (num > 1)
    {
        int primefactor = hp[num];
        while (num % primefactor == 0)
        {
            num /= primefactor;
            primefactors[primefactor]++; //.push_back(primefactor);
        }
    }
    for (auto factor : primefactors)
    {
        cout << factor.first << " " << factor.second << endl;
    }
}
// #############TEN SIEVE divisor upto n number#############
const int n = 1e5 + 10;
vector<int> divisors[n];
int sum[n];
int main()
{
    for (int i = 2; i < n; i++)
    {
        for (int j = i; j < n; j += i)
        {
            divisors[j].push_back(i);
            sum[j] += i;
        }
    }

    for (int i = 1; i < 10; i++)
    {
        cout << i << "->";
        for (int div : divisors[i])
        {
            cout << div << " ";
        }
        cout << endl;
    }
}
// #############TEN SIEVE inverse #############
using namespace std;
const int m = 1e5 + 7;
int be(int a, int b, int m)
{
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            result = (result * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return result;
}
int main()
{
    //(a/b)%m == (a*b^-1)%m  == ( (a%m)* (b^-1)%m) %m
    // IF  (a*b)%m=1  then b is a MI 0f a
    // 1<b<m-1
    // loop b=1 to m-1    (a*b)%m =1 ;o(n)  ;
    // MMI defined if a and m are co-prime mean gcd is equal to one  [NOTE]
    // a^(m-1) == 1 mod)(m) if we divide a^(m-1) then remender will be 1
    // m  is a prime ; a is not bmultiple of m

    // m=3
    //(a^(m-2))%m = (a^(-1))
    int a;
    cin >> a;
    cout << be(a, m - 2, m); // this is a formula to find the (a/b)%m
}
// #############Eleven SIEVE  #############
using namespace std;
const int m = 1e5 + 7;
int be(int a, int b, int m)
{
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            result = (result * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return result;
}
const int n = 1e5 + 10;
int fact[n];
int main()
{
    fact[0] = 1;
    for (int i = 1; i < n; i++)
    {
        fact[i] = (fact[i - 1] * 1LL * i) % m;
    }
    int q;
    cin >> q;
    int r;
    while (q--)
    {
        int n, k;
        cin >> n >> k;
        int ans = fact[n];
        int den = (fact[n - r] * 1LL * fact[r]) % m;
        ans = ans * 1LL * be(den, m - 2, m);
        cout << ans << endl;
    }
}
// #############Eleven SIEVE  worke in progress #############
using namespace std;

const int m = 1e5 + 7;
const int n = 1e5 + 7;
int fact[n];
int be(int a, int b, int m)
{
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            result = (result * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    fact[0] = 1;
    for (int i = 1; i < n; i++)
    {
        fact[i] = (fact[i - 1] * 1LL * i) % m;
    }
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int ans = fact[n];
        ans = (ans * 1LL * fact[k]) % m;
        int den = (fact[k - n] * 1LL * (fact[n])) % m;
        ans = (ans * 1LL * be(den, m - 2, m)) % m;
        cout << ans << endl;
        cout << be(6, m - 2, m);
    }
}

//*******************************************************************************************************************

// ################FINDING MULTIPLIE OF TWO NUMBER ########
using namespace std;
const int N = 10e5 + 10;

long long int hsh[N];
long long int multiples_ct[N];

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, (a % b));
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        hsh[x]++;
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            multiples_ct[i] += hsh[j];
        }
    }
    int qq;
    cin >> qq;
    while (qq--)
    {
        int p, q;
        cin >> p >> q;
        long long int lcm = p * 1LL * q / gcd(p, q);
        long long int ans = multiples_ct[p] + multiples_ct[q];
        if (lcm < N)
            ans = ans - multiples_ct[lcm];
        cout << ans << endl;
    }
}

// ################### best best ################
using namespace std;
const int N = 100000;
int a[100000];
int hp[100000];
int canremove[100000];
int hsh[100000];

vector<int> distinctPF(int x)
{
    vector<int> ans;
    while (x > 1)
    {
        int pf = hp[x];
        while (x % pf == 0)
        {
            x = x / pf;
        }
        ans.push_back(pf);
    }
    return ans;
}
int main()
{
    for (int i = 2; i < N; i++)
    {
        if (hp[i] == 0)
        {
            for (int j = i; j < N; j += i)
            {
                hp[j] = i;
            }
        }
    }
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        //  cin>>a[i];
        int x;
        cin >> x;
        hsh[x] = 1;
    }
    for (int i = 2; i < N; i++)
    {
        if (hsh[i])
        {
            for (int j = i; j < N; j *= i)
            {
                canremove[j] = 1;
            }
        }
    }
    while (q--)
    {
        int x;
        cin >> x;
        vector<int> pf = distinctPF(x);
        bool ispossible = false;
        for (int i = 0; i < pf.size(); i++)
        {
            for (int j = i; j < pf.size(); j++)
            {
                int product = pf[i] * pf[j];
                if (i == j && x % product != 0)
                    continue;
                int toremove = x / product;
                if (canremove[toremove] == 1 || toremove == 1)
                {
                    ispossible = true;
                    break;
                }
            }
            if (ispossible)
                break;
        }
        cout << (ispossible ? "yes \n" : "no\n");
    }
}

// ######## BITS EACH TERM GET MAX MULTIP..######
using namespace std;

int main()
{
    int c;
    cin >> c;
    int bit_ct = (int)log2(c) + 1;
    int a = 0, b = 0;
    vector<int> set_bits;
    for (int i = 0; i < bit_ct; i++)
    {
        if (c & (1 << i))
            set_bits.push_back(i);
        else
        {
            a |= (1 << i);
            b |= (1 << i);
        }
    }
    long long ans = -1;
    int sz = (1 << set_bits.size());
    for (int mask = 0; mask < sz; mask++)
    {
        int a_copy = a, b_copy = b;
        for (int j = 0; j < set_bits.size(); j++)
        {
            if (mask & (1 << j))
            {
                a_copy |= (1 << set_bits[j]);
            }
            else
            {
                b_copy |= (1 << set_bits[j]);
            }
        }
        ans = max(ans, a_copy * 1LL * b_copy);
    }
    cout << ans << endl;
}

// ######## INCLUSION EXCLUSION MONK######

/*2
5
helen
irena
arthos
pentos
tulu
3
alen
bira
cult
e 3
i 1
a 2
ae 1
ei 1
ai 1
o 2
aei 1
ao 1
eo 1
u 1
1
i 1
a 2
u 1
e 1
ae 1
ai 1
0

=====
Used: 0 ms, 0 KB */
using namespace std;

bool isvowel(char ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

vector<string> subsets(string s)
{
    int sz = 1 << s.size();
    vector<string> ans;
    for (int mask = 0; mask < sz; ++mask)
    {
        string subset;
        for (int bit = 0; bit < s.size(); bit++)
        {
            if (mask & (1 << bit))
                subset.push_back(s[bit]);
        }
        if (subset.size())
            ans.push_back(subset);
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str[10];
        for (int i = 0; i < n; i++)
            cin >> str[i];

        unordered_map<string, int> hsh;
        for (int i = 0; i < n; i++)
        {
            set<char> distinct_vw;
            for (char ch : str[i])
            {
                if (isvowel(ch))
                {
                    distinct_vw.insert(ch);
                }
            }
            string vowel_str;
            for (char ch : distinct_vw)
                vowel_str.push_back(ch);

            vector<string> all_subsets = subsets(vowel_str);
            for (string vowel_subset : all_subsets)
                hsh[vowel_subset]++;
        }
        long long int ans = 0;
        // for(auto pr:hsh)
        //   cout<<pr.first<<" "<<pr.second<<endl;
        for (auto &pr : hsh)
        {
            if (pr.second < 3)
                continue;
            long long int ct = pr.second;
            long long int ways = (ct * (ct - 1) * (ct - 2)) / 6;
            if (pr.first.size() % 2 == 0)
                ans -= ways;
            else
                ans += ways;
        }
        cout << ans << "\n";
    }
}
