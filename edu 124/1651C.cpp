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
    int n; cin>>n;
    ll a,b,c,d;
    a=b=c=d=1e9;
    ll ar1[n],ar2[n];
    for(ll &x:ar1)cin>>x;
    for(ll &x:ar2)cin>>x;

    for(int i=0; i<n; i++)
    {
        a=min(a,abs(ar1[0]-ar2[i]));
        b=min(b,abs(ar1[n-1]-ar2[i]));
        c=min(c,abs(ar2[0]-ar1[i]));
        d=min(d,abs(ar2[n-1]-ar1[i]));
    }

    ll ans=a+b+c+d;

    ans=min(ans,abs(ar1[0]-ar2[0])+abs(ar1[n-1]-ar2[n-1]));
    ans=min(ans,abs(ar1[0]-ar2[n-1])+abs(ar1[n-1]-ar2[0]));

    ans=min(ans,abs(ar1[0]-ar2[0])+b+d);
    ans=min(ans,abs(ar1[0]-ar2[n-1])+b+c);
    ans=min(ans,abs(ar1[n-1]-ar2[0])+a+d);
    ans=min(ans,abs(ar1[n-1]-ar2[n-1])+a+c);

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