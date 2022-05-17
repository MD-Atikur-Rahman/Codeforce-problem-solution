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
    ll n,x; cin>>n>>x;
    ll a[n]; for(ll &x:a)cin>>x;
    ll mn, mx;
    mn=*min_element(a,a+n);
    mx=*max_element(a,a+n);

    ll ans=0,cnt;

    for(int i=1; i<n; i++)ans+=abs(a[i]-a[i-1]);
    if(x<mn)
    {
        cnt=min(a[0]-1,a[n-1]-1);
        for(int i=1; i<n; i++)
        {

            cnt=min(cnt,a[i-1]+a[i]-2-abs(a[i]-a[i-1]));
        }
        ans+=cnt;
    }
    else
    {
        cnt=min(a[0]-1,a[n-1]-1);
        cnt=min(cnt,mn+mn-2);
        ans+=cnt;

        if(x>mx)
        {
            cnt=min(x-a[0],x-a[n-1]);
            cnt=min(cnt,x-mx+x-mx);
            ans+=cnt;
        }
    }

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