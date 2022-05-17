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
VVI adj;
int n,ans;
string s;

PII dfs(int v)
{
    int blc=0,wht=0;
    if(s[v-1]=='B')blc++;
    else wht++;

    PII bw;

    for(int x:adj[v])
    {
        bw=dfs(x);
        blc+=bw.first;
        wht+=bw.second;
    }
    if(blc==wht)ans++;
    return MP(blc,wht);
}

void Engine(int tc)
{
    cin>>n;
    adj.clear();
    adj.resize(n+1);
    ans=0;

    int pr;

    for(int i=2; i<=n; i++)
    {
        cin>>pr;
        adj[pr].PB(i);
    }
    cin>>s;

    dfs(1);
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