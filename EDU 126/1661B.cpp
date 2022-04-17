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
    int n,v; cin>>n;
    int a[n]; for(int &x:a)cin>>x;

    int ans[32768];
    memset(ans,-1,sizeof ans);
    ans[0]=0;

    queue<int> q;
    q.push(0);

    while(!q.empty())
    {
        v=q.front();
        q.pop();

        if(v-1>0 && ans[v-1]==-1)
        {
            ans[v-1]=ans[v]+1;
            q.push(v-1);
        }

        if(v%2==0 && ans[v>>1]==-1)
        {
            ans[v>>1]=ans[v]+1;
            q.push(v>>1);
        }

        v+=32768;

        if(v-1<32768 && ans[v-1]==-1)
        {
            ans[v-1]=ans[v-32768]+1;
            q.push(v-1);
        }

        if(v%2==0 && ans[v>>1]==-1)
        {
            ans[v>>1]=ans[v-32768]+1;
            q.push(v>>1);
        }
    }

    for(int i=0; i<n; i++)
    {
        cout<<ans[a[i]]<<" ";
    }
    cout<<nl;
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