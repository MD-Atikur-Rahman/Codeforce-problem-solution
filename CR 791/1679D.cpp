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
const int SZ=2e5+5;
int a[SZ];
VVI adj(SZ);
int cnt[SZ];
bool flag,vis[SZ];
int l,r,mdl;
ll n,m,k;
void dfs(int v)
{
    vis[v]=true;
    int mx=0;
    for(int x:adj[v])
    {
        if(vis[x])flag=true;
        else if(cnt[x]>0)mx=max(mx,cnt[x]);
        else if(a[x]<=mdl)
        {
            dfs(x);
            mx=max(mx,cnt[x]);
        }
    }
    cnt[v]=1+mx;
    if(cnt[v]>=k)flag=true;
    vis[v]=false;
}

void Engine(int tc)
{
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++)cin>>a[i];

    int u,v;
    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
        adj[u].PB(v);
    }

    l=0,r=1e9+5;
    int ans=-1;
    while(l<r)
    {
        mdl=l+r+1>>1;
        if(mdl==r)break;
        flag=false;
        
        for(int i=1; i<=n; i++)
        {
            vis[i]=false;
            cnt[i]=0;
        }

        for(int i=1; i<=n; i++)
        {
            if(a[i]<=mdl && cnt[i]==0)
            {
                dfs(i);
            }
        }

        if(flag)
        {
            ans=mdl;
            r=mdl;
        }
        else l=mdl;
    }
    cout<<ans<<nl;
}

int main()
{
    FastIO
    int tt=1;
    //cin>>tt;
    for(int tc=1; tc<=tt; tc++)
    {
        Engine(tc);
    }
    return 0;
}  