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
    int n,m; cin>>n>>m;
    if(abs(n-m)<=1)
    {
        cout<<n+m-2<<nl;
        return;
    }

    if(n==1 || m==1)
    {
        cout<<-1<<nl;
        return;
    }

    if(n<m)swap(n,m);

    int ans=m+m-1;
    n-=(m+1);

    ans+=(n/2)*4;
    if(n&1)ans+=3;

    cout<<ans<<nl;
    return;
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