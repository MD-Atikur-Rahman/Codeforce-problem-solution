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
    int n,k; cin>>n>>k;

    ll b[n]; for(ll &x:b)cin>>x;
    ll d,cnt,oe=0,opr=0,curv=0;

    queue<pair<ll,ll>> q;

    for(int i=n-1; i>=0; i--)
    {
        d=min(k,i+1);
        curv-=oe;

        if(!q.empty() && q.front().first-i>=k)
        {
            oe-=q.front().second;
            q.pop();
        }
        
        if(curv>=b[i])continue;

        cnt=(b[i]-curv+d-1)/d;
        opr+=cnt;
        oe+=cnt;
        curv+=cnt*d;
        q.push({i,cnt});
        
    }
    cout<<opr<<nl;
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