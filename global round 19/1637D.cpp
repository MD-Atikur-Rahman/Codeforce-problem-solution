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

bool dp[102][10002];
int a[102],b[102];

void Engine()
{
    memset(dp,0,sizeof dp);
    int n,sum=0,ans=0; cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        sum+=a[i];
        ans+=a[i]*a[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>b[i];
        sum+=b[i];
        ans+=b[i]*b[i];
    }
    ans*=n-2;

    dp[0][a[0]]=true;
    dp[0][b[0]]=true;

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<10002; j++)
        {
            if(dp[i-1][j]==true)
            {
                dp[i][j+a[i]]=dp[i][j+b[i]]=true;
            }
        }
    }

    int mn=1e9;

    for(int j=1; j<10002; j++)
    {
        if(dp[n-1][j])
        {
            mn=min(mn,j*j+(sum-j)*(sum-j));
        }
    }
    cout<<ans+mn<<nl;
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