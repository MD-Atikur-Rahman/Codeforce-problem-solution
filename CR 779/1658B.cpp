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

const ll MOD=998244353;

ll fact[1005];

void making()
{
    fact[0]=fact[1]=1;

    for(ll i=2; i<1005; i++)
    {
        fact[i]=fact[i-1]*i%MOD;
    }
}

void Engine(int tc)
{
    int n; cin>>n;
    if(n&1)
    {
        cout<<0<<nl;
        return;
    }

    cout<<fact[n/2]*fact[n/2]%MOD<<nl;
}

int main()
{
    FastIO

    making();

    int tt=1;
    cin>>tt;
    for(int tc=1; tc<=tt; tc++)
    {
        Engine(tc);
    }
    return 0;
}  