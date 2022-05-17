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
    int a[n]; for(int &x:a)cin>>x;
    int f[n],tf[n]; 
    memset(f,0,sizeof f);
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)if(a[j]<a[i])f[i]++;
    }
    ll ans=0;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)if(a[j]>a[i])f[j]--;
        for(int j=0; j<i; j++)tf[j]=f[j]+(j>0? tf[j-1]:0);
        for(int j=0; j+1<i; j++)
        {
            if(a[j]<a[i])ans+=tf[i-1]-tf[j];
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