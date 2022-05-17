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

const int MX=2e5+5;
int u,v,x,y,n,tsk,ans=0;
vector<vector<int>> adj;
bool vis[MX];
bool kaj[MX];

int dfs(int nd)
{
    int temp,res=-1;
    if(kaj[nd] || nd==y)res=0;

    vis[nd]=true;
    bool isy=false;
    if(nd==y)isy=true;

    for(int el:adj[nd])
    {
        if(vis[el])continue;
        temp=dfs(el);
        if(temp==-2)
        {
            res=max(0,res);
            isy=true;
        }
        else if(temp!=-1)
        {
            if(res==-1)res=0;
            res+=temp+2;
        }
    }
    // cout<<nd<<" "<<res<<nl;
    if(isy==true)
    {
        ans++;
        ans+=res;
        res=-2;
    }
    // cout<<nd<<" "<<res<<" "<<ans<<nl;
    return res;
}

void Engine(int tc)
{
    cin>>n>>tsk;
    cin>>x>>y;

    adj.clear();
    adj.resize(n+1);
    ans=0;

    for(int i=0; i<=n; i++)
    {
        vis[i]=false;
        kaj[i]=false;
    }

    for(int i=0; i<tsk; i++)
    {
        cin>>v;
        kaj[v]=true;
    }

    for(int i=1; i<n; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for(int i=0; i<=n; i++)
    // {
    //     cout<<kaj[i]<<" ";
    // }
    // cout<<nl;

    dfs(x);
    ans--;
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