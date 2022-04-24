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
    ll n,m; cin>>n>>m;
    ll a[n]; for(ll &x:a)cin>>x;

    sort(a,a+n,greater<ll>());
    ll cnt=a[0]+a[0]+1;

    for(int i=2; i<n; i+=2)
    {
        if(i==n-1)cnt+=a[i-1]+2;
        else cnt+=a[i]+a[i-1]+2;
    }
    if(n%2ll==0)cnt++;
    if(cnt<=m)cout<<"YES\n";
    else cout<<"NO\n";
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