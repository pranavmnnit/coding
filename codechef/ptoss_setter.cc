#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9

// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define whole(a)                    a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                   memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair

// Some common useful functions
#define maX(a,b)                    ( (a) > (b) ? (a) : (b))
#define miN(a,b)                    ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)               ( (n >> b) & 1)
#define DREP(a)			    sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)		    (lower_bound(all(arr),ind)-arr.begin())

using namespace std;

#if DEBUG && !ONLINE_JUDGE

    #define debug(args...)     (Debugger()) , args

    class Debugger
    {
        public:
        Debugger(const std::string& _separator = ", ") :
        first(true), separator(_separator){}

        template<typename ObjectType>
        Debugger& operator , (const ObjectType& v)
        {
            if(!first)
                std:cerr << separator;
            std::cerr << v;
            first = false;
            return *this;
        }
        ~Debugger() {  std:cerr << endl;}

        private:
        bool first;
        std::string separator;
    };

    template <typename T1, typename T2>
    inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
    {
        return os << "(" << p.first << ", " << p.second << ")";
    }

    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
    {
        bool first = true;
        os << "[";
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << ", ";
            os << v[i];
            first = false;
        }
        return os << "]";
    }

    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            if(!first)
                os << ", ";
            os << *ii;
            first = false;
        }
        return os << "]";
    }

    template<typename T1, typename T2>
    inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            if(!first)
                os << ", ";
            os << *ii ;
            first = false;
        }
        return os << "]";
    }

#else
    #define debug(args...)                  // Just strip off all debug tokens
#endif

typedef long long LL;

typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<LL, LL> PLL;

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<vector<int> > VVI;
typedef vector<VL> VVL;


int ni()
{
    int _num; s(_num);
    return _num;
}

/*-------------------------Main code begins now ------------------------------*/
int testnum;

const int MAXL = 32 * 200000 + 10;
int border[MAXL + MAXL], kmps[MAXL];
char temp1[MAXL], temp2[MAXL];
int L1, L2;
int prefix[MAXL];
const int MOD = 1000000007;

void weak_kmp(char *pattern, int len)
{
    int j=border[0]=-1,i=0;
    while(i<len)
    {
        while(j>=0 && pattern[j]!=pattern[i])
            j=border[j];
        i++;j++;
        border[i]=j;
    }
}

void strong_kmp(char *pattern, int len)
{
    weak_kmp(pattern, len);
    // At this stage, border[i] denotes the length of the longest border of
    // prefix of length i
    
    kmps[0] = 0;
    for(int i = 1; i < len; i++)
    {
        if( pattern[i] != pattern[border[i]])
            kmps[i] = 1 + border[i];
        else
            kmps[i] = kmps[border[i]];
    }
}

int decode(char ch)
{
    if( islower(ch)) return ch-'a';
    return 26 + ch- 'A';
}
    
int add(int a, int b, int c)
{
    int ret = a + b;
    while(ret >= MOD) ret -= MOD;
    ret += c;
    while(ret >= MOD) ret -= MOD;
    return ret;
}

void solve()
{
    // First check if seq1 is contained inside seq2 or not

    forall(i, 0, 1 + L2)
        if( border[i] == L1) // Seq2 contains seq1 ending at position i
        {
            printf("0\n");
            return;
        }

    // seq 1 is not contained inside seq2. Now let's find the longest prefix of seq1
    // that is suffix of seq2
    int already_seen = border[L2];

    prefix[0] = 0;
    for(int i = 1; i <= L1; i++)
    {
        int new_match_len = kmps[i-1];
        prefix[i] = add(prefix[i-1], prefix[i-1] + 2, MOD- prefix[new_match_len]);
    }

    int ans = (prefix[L1] - prefix[already_seen] + MOD) % MOD;
    printf("%d\n", ans);
}

// Coded sequence is in temp1 and desired length of uncoded sequence is L to be
// stored in out
void recover(int L, char *out)
{
    int N = strlen(temp1);
    for(int i = 0, cov = 0;i < N; i++, cov += 5)
    {
       int a = decode(temp1[i]); 
       int j = cov + 4;
       for(int k = 0; k < 5; k++)
           out[j--] = '0' + ( (a>>k) & 1);
    }
    out[L] = '\n';
}

bool input()
{
    s(L1);    ss(temp1);
    // Decode this sequence and store in temp2
    recover(L1, temp2); 
    // Find out kmp information for temp2 and store it in kmps array
    strong_kmp(temp2, L1);

    temp2[L1] = '$';
    s(L2);    ss(temp1);
    recover(L2, 1 + temp2 + L1);
    L2 += L1 + 1;
    weak_kmp(temp2, L2);
    return true;
}


int main()
{
    int T;
    s(T);
    for(testnum=1;testnum<=T;testnum++)
    {
        if(!input()) break;
        solve();
    }
}

