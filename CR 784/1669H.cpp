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
    int ind,n,k,x; cin>>n>>k;
    int cnt[31];
    memset(cnt,0,sizeof cnt);

    for(int i=0; i<n; i++)
    {
        cin>>x;
        ind=0;
        while(x>0)
        {
            if(x&1)cnt[ind]++;
            ind++;
            x>>=1;
        }
    }
    ll ans=0;
    for(int i=30; i>=0; i--)
    {
        if(k>=n-cnt[i])
        {
            k-=(n-cnt[i]);
            ans+=(1<<i);
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