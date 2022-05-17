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
    vector<string> v(n);
    
    for(string &s:v)
    {
        cin>>s;
    }

    ll md,ans=LLONG_MAX;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            md=0;
            for(int k=0; k<m; k++)
            {
                if(v[i][k]>=v[j][k])md+=(v[i][k]-v[j][k]);
                else md+=(v[j][k]-v[i][k]);
            }
            ans=min(ans,md);
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