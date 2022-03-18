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

ll sht,sht1,nh,nd,ch,cd,mh,md,k,w,a;

void Engine()
{
    cin>>ch>>cd>>mh>>md>>k>>w>>a;
    for(ll i=0; i<=k; i++)
    {
        nh=ch+(i*a);
        nd=cd+(k-i)*w;

        sht=(mh+nd-1)/nd;
        sht1=(nh+md-1)/md;

        if(sht<=sht1)
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
    return;
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