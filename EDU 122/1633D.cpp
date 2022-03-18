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

int n,k,sum;
int d[1001],b[10001],c[10001];

void Engine()
{
    sum=0;
    cin>>n>>k;
    
    k=min(k,n*12);
    ll ans[k+1];
    memset(ans,0,sizeof ans);

    for(int i=0; i<n; i++)
    {
        cin>>b[i];
      //  cout<<d[b[i]]<<" ";
    }
    for(int i=0; i<n; i++)cin>>c[i];

    for(int i=0; i<n; i++)
    {
        for(int j=k; j>=d[b[i]]; j--)
        {
            ans[j]=max(ans[j],c[i]+ans[j-d[b[i]]]);
        }
    }

    cout<<ans[k]<<nl;
}

int main()
{
    FastIO

    memset(d,127,sizeof d);
    d[0]=d[1]=0;
    int val;

    for(int i=1; i<=1000; i++)
    {
        for(int j=1; j<=i; j++)
        {
            val=i/j;
            if(i+val<=1000)
            {
                d[i+val]=min(d[i+val],d[i]+1);
                // cout<<i<<" "<<d[i]<<" "<<i+val<<" "<<d[i+val]<<nl;
            }
        }
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