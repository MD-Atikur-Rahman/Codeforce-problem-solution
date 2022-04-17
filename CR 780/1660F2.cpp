#include<bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define ull unsigned long long
#define PB push_back
#define All(x) (x).begin(),(x).end()
#define MP make_pair
#define nl "\n"
typedef pair<int,int>PII;
typedef vector<int>VI;
typedef vector<PII>VPII;
typedef vector<VI>VVI;
typedef vector<long long>VL;
typedef vector <VL>VVl;
template<class T> void print(T& a) { for(auto x:a)cout<<x<<" "; cout<<"\n";}
const long double PI = 3.14159265358979;
const long double EPS=1e-9;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void Engine(int tc)
{
    int n; cin>>n; 
    string s; cin>>s;

    FenwickTree ftz(2*n+5),fto(2*n+5),ftt(2*n+5);

    int pos,neg,mod,dif;
    pos=neg=0;

    for(int i=0; i<n; i++)
    {
        if(s[i]=='-')neg++;
        else pos++;

        dif=neg-pos;
        mod=dif%3;
        mod+=3;
        mod%=3;

        if(mod==0)
        {
            ftz.add(dif+n+2,1);
        }
        else if(mod==1)
        {
            fto.add(dif+n+2,1);
        }
        else
        {
            ftt.add(dif+n+2,1);
        }
    }

    ll ans=ftz.sum(n+2,2*n+4);

    pos=neg=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='-')neg++;
        else pos++;

        dif=neg-pos;
        mod=dif%3;
        mod+=3;
        mod%=3;

        if(mod==0)
        {
            ftz.add(dif+n+2,-1);
            ans+=ftz.sum(dif+n+2,2*n+4);
        }
        else if(mod==1)
        {
            fto.add(dif+n+2,-1);
            ans+=fto.sum(dif+n+2,2*n+4);
        }
        else
        {
            ftt.add(dif+n+2,-1);
            ans+=ftt.sum(dif+n+2,2*n+4);
        }
    }

    cout<<ans<<nl;
}

int main()
{
    FastIO
    int tt=1;
    cin>>tt;
    for(int tc=1; tc<=tt; tc++)
    {
        Engine(tc);
    }
    return 0;
}  