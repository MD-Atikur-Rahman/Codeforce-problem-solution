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

    int a[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)cin>>a[i][j];
    }

    ll tmp,ans=0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            tmp=a[i][j];
            for(int k=1; ; k++)
            {
                if(i-k>=0)
                {
                    if(j-k>=0)tmp+=a[i-k][j-k];
                    if(j+k<m)tmp+=a[i-k][j+k];
                }
                if(i+k<n)
                {
                    if(j-k>=0)tmp+=a[i+k][j-k];
                    if(j+k<m)tmp+=a[i+k][j+k];
                }
                if(i-k<0 && i+k>=n)break;
                if(j-k<0 && j+k>=m)break;
            }
            ans=max(tmp,ans);
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