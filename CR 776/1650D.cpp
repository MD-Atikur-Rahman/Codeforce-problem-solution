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
    int n,x; cin>>n;
    int pos[n+1],ans[n+1];

    for(int i=0; i<n; i++)
    {
        cin>>x;
        pos[x]=i+1;
    }

    for(int i=n; i>0; i--)
    {
        for(int j=n; j>i; j--)
        {
            pos[i]-=ans[j];
            if(pos[i]<=0)pos[i]+=j;
        }
        if(pos[i]>=i)ans[i]=pos[i]-i;
        else ans[i]=pos[i];
        // cout<<pos[i]<<" "<<ans[i]<<nl;
    }

    for(int i=1; i<=n; i++)cout<<ans[i]<<" ";
    cout<<nl;
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