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

const int sz=1e5+2;

VVI vx(sz), vy(sz);

void Engine()
{
    int cl,n,m; cin>>n>>m;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>cl;
            vx[cl].push_back(i);
            vy[cl].push_back(j);
        }
    }

    ll sum=0,ts1,ts2;

    for(int i=1; i<sz; i++)
    {
        if(vx[i].empty())continue;

        sort(All(vx[i]));
        sort(All(vy[i]));
        
        ts1=vx[i][0];
        ts2=vy[i][0];

        for(int j=1; j<vx[i].size(); j++)
        {
            sum+=1ll*vx[i][j]*j-ts1;
            sum+=1ll*vy[i][j]*j-ts2;

            ts1+=vx[i][j];
            ts2+=vy[i][j];
        }
    }
    cout<<sum<<nl;
}

int main()
{
    FastIO
    int tt=1;
    //cin>>tt;
    for(int tc=1; tc<=tt; tc++)
    {
        //cout<<"Case "<<tc<<": ";
        Engine();
    }
    return 0;
}  