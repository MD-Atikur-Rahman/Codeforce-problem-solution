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
    ll a[n]; for(ll &x:a)cin>>x;

    ll d,cnt,lst,ans=LLONG_MAX;

    for(int i=0; i<n; i++)
    {
        cnt=0;
        lst=0;

        for(int j=i-1; j>=0; j--)
        {
            d=lst/a[j]+1;
            cnt+=d;
            lst=d*a[j];
        }

        lst=0;

        for(int j=i+1; j<n; j++)
        {
            d=lst/a[j]+1;
            cnt+=d;
            lst=d*a[j];
        }

        ans=min(ans,cnt);
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