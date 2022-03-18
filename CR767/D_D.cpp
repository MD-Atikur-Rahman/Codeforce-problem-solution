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
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
const long double PI = 3.14159265358979;
const long double EPS=1e-9;

const int SZ=1e6+5;
int n; 
VL apple;
ll ans=0;

vector<VPII> g;
ll cnt;

ll dfs(int p, int v)
{
    
    for(PII& x:g[v])
    {
        if(x.first==p)continue;
        cnt=dfs(v,x.first);
        cnt-=x.second;
        cnt-=x.second;

        if(cnt>0)apple[v]+=cnt;
    }
    ans=max(ans,apple[v]);
    return apple[v];
}

void Engine()
{
    cin>>n;
    g.resize(n+1);
    apple.resize(n+1);
    for(int i=1; i<=n; i++)cin>>apple[i];
    int u,v,w;
    for(int i=1; i<n; i++)
    {
        cin>>u>>v>>w;
        g[u].PB({v,w});
        g[v].PB({u,w});
    }

    dfs(0,1);
    cout<<ans<<nl;
}

int main()
{
    FastIO
    int tt=1;
    //cin>>tt;
    while(tt--)
    {
        Engine();
    }
    return 0;
}  