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

void Engine()
{
    int n; cin>>n;
    int a[n];
    int b[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i]>>b[i];
    }

    vector<vector<pair<ll,ll>>> v(n);
    v[0].push_back({a[0],0});
    v[0].push_back({a[0]+1,b[0]});
    
    ll mn;
    for(int i=1; i<n; i++)
    {
        mn=INT64_MAX;
        for(auto x:v[i-1])
        {
            if(x.first==a[i])continue;
            mn=min(mn,x.second);
        }
        v[i].push_back({a[i],mn});

        mn=INT64_MAX;
        for(auto x:v[i-1])
        {
            if(x.first==a[i]+1)continue;
            mn=min(mn,x.second);
        }
        v[i].push_back({a[i]+1,mn+b[i]});

        mn=INT64_MAX;
        for(auto x:v[i-1])
        {
            if(x.first==a[i]+2)continue;
            mn=min(mn,x.second);
        }
        v[i].push_back({a[i]+2,mn+b[i]+b[i]});
    }

    mn=INT64_MAX;
    for(auto x:v[n-1])mn=min(mn,x.second);
    cout<<mn<<nl;
}

int main()
{
    FastIO
    int tt=1;
    cin>>tt;
    for(int tc=1; tc<=tt; tc++)
    {
        //cout<<"Case "<<tc<<": ";
        Engine();
    }
    return 0;
}  