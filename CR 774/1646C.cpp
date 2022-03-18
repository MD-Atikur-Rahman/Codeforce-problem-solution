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

ll fact[15];

void Engine()
{
    ll n; cin>>n;

    int ans=__builtin_popcountll(n);
    
    ll sum;
    for(int i=1; i<(1<<14); i++)
    {
        sum=0;
        for(int j=0; j<14; j++)
        {
            if(i&(1<<j))sum+=fact[j+1];
        }

        if(sum<=n)
        {
            ans=min(ans,__builtin_popcount(i)+__builtin_popcountll(n-sum));
        }
    }
    cout<<ans<<nl;
}

int main()
{
    FastIO

    fact[0]=1;
    for(ll i=1; i<15; i++)
    {
        fact[i]=fact[i-1]*i;
    }

    int tt=1;
    cin>>tt;
    for(int tc=1; tc<=tt; tc++)
    {
        //cout<<"Case "<<tc<<": ";
        Engine();
    }
    return 0;
}  