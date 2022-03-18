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
    ll x,d; cin>>x>>d;
    ll tmp=x/d;

    if(tmp%d!=0)
    {
        cout<<"NO\n";
        return;
    }

    int cnt=0;
    while(x%d==0)
    {
        x/=d;
        cnt++;
    }

    for(ll i=2; i*i<=x; i++)
    {
        if(x%i==0)
        {
            cout<<"YES\n";
            return;
        }
    }

    if(cnt>3)
    {
        for(ll i=2; i*i<=d; i++)
        {
            if(d%i==0)
            {
                cout<<"YES\n";
                return;
            }
        }
    }

    if(cnt==3)
    {
        for(ll i=2; i*i<=d; i++)
        {
            if(d%i==0 && ((i*x)%d!=0 || ((d/i)*x)%d!=0))
            {
                cout<<"YES\n";
                return;
            }
        }
    }

    cout<<"NO\n";
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