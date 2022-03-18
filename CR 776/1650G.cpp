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

const ll MOD=1e9+7;

void Engine(int tc)
{
    int u,v,n,m,s,t; cin>>n>>m>>s>>t;
    VVI g(n+1);

    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll len[n+1],cnt[n+1],cnt1[n+1];

    for(int i=1; i<=n; i++)
    {
        len[i]=-1;
        cnt[i]=0;
        cnt1[i]=0;
    }

    
    queue<int> q,q1;
    q.push(s);
    len[s]=0;
    cnt[s]=1;
    
    while(!q.empty())
    {
        while(!q.empty())
        {
            v=q.front();
            q.pop();
            q1.push(v);

            for(int x:g[v])
            {
                if(len[x]==len[v])
                {
                    cnt1[x]+=cnt[v];
                    cnt1[x]%=MOD;
                }
            }
        }
        while(!q1.empty())
        {
            v=q1.front();
            q1.pop();

            for(int x:g[v])
            {
                if(len[x]==-1 || len[x]==len[v]+1)
                {
                    if(len[x]==-1)q.push(x);
                    len[x]=len[v]+1;
                    cnt[x]+=cnt[v];
                    cnt1[x]+=cnt1[v];
                    cnt[x]%=MOD;
                    cnt1[x]%=MOD;
                }
            }
        }
    }

    // for(int i=1; i<=n; i++)
    // {
    //     cout<<i<<" "<<len[i]<<" "<<cnt[i]<<" "<<cnt1[i]<<nl;
    // }

    cout<<(cnt[t]+cnt1[t])%MOD<<nl;
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