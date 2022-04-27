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

const int maxn=500005;
int fen[maxn];
int n;

void add(int pos,int val)
{
    for(int i=pos; i<=n; i+=i&-i)
    {
        fen[i]=max(fen[i],val);
    }
}

int get(int pos)
{
    int ret=INT32_MIN;
    for(pos; pos>0; pos-=pos&-pos)
    {
        ret=max(ret,fen[pos]);
    }
    return ret;
}


void Engine(int tc)
{
    cin>>n;
    int a[n+1];
    ll pre=0;
    vector<pair<ll,int>> v;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        pre+=a[i];
        v.push_back({pre,-i});
    }

    sort(All(v));

    int ord[n+1];
    for(int i=0; i<n; i++)
    {
        ord[-v[i].second]=i+1;
    }    

    for(int i=0; i<=n; i++)fen[i]=INT32_MIN;

    int dp[n+1];
    dp[0]=0,pre=0;

    for(int i=1; i<=n; i++)
    {
        pre+=a[i];
        dp[i]=dp[i-1]+(a[i]>0? 1:(a[i]==0? 0:-1));
        dp[i]=max(dp[i],get(ord[i])+i);
        if(pre>0)dp[i]=i;
        add(ord[i],dp[i]-i);
    }
    cout<<dp[n]<<nl;
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