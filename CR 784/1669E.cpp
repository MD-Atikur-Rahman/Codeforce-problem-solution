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
    vector<string> v(n);

    int fcnt[11],lcnt[11];
    int dcnt[11][11];

    memset(fcnt, 0, sizeof fcnt);
    memset(lcnt, 0, sizeof lcnt);
    memset(dcnt, 0, sizeof dcnt);

    ll ans=0;

    for(string &x:v)
    {
        cin>>x;

        ans+=fcnt[x[0]-'a'];
        ans+=lcnt[x[1]-'a'];
        ans-=dcnt[x[0]-'a'][x[1]-'a'];
        ans-=dcnt[x[0]-'a'][x[1]-'a'];

        fcnt[x[0]-'a']++;
        lcnt[x[1]-'a']++;
        dcnt[x[0]-'a'][x[1]-'a']++;
        // cout<<ans<<nl;
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