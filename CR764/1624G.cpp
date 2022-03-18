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

void Engine(int tc)
{
    int u,v,w,n,m; cin>>n>>m;
    vector<VPII> g(n+1);

    for(int i=0; i<m; i++)
    {
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    int mask=0;
    for(int i=0; i<31; i++)
    {
        mask+=(1<<i);
    }
    
    int cnt;
    queue<int> q;
    bool vis[n+1];
    for(int i=30; i>=0; i--)
    {
        cnt=1;
        mask-=(1<<i);
        q.push(1);
        
        memset(vis,0,sizeof vis);
        vis[1]=true;

        while(!q.empty())
        {
            v=q.front();
            q.pop();

            for(PII x:g[v])
            {
                if(x.second-(mask&x.second)==0 && vis[x.first]==false)
                {
                    q.push(x.first);
                    vis[x.first]=true;
                    cnt++;
                }
            }
        }

        if(cnt<n)mask+=(1<<i);
    }
    cout<<mask<<nl;
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