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
    int n,mx; cin>>n;
    int a[n]; for(int &x:a)cin>>x;
    mx=*max_element(a,a+n);

    ll dif,od,ev,ans=1e18;

    for(int i=mx; i<mx+2; i++)
    {
        od=0,ev=0;

        for(int j=0; j<n; j++)
        {
            dif=i-a[j];
            if(dif&1)od++;
            ev+=dif/2;
        }

        if(od>ev)ans=min(ans,od*2-1);
        else
        {
            ev-=od;
            od+=(ev/3)*2;
            ev%=3;
            od*=2;
            if(ev==1)od+=2;
            else if(ev==2)od+=3;
            ans=min(ans,od);
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