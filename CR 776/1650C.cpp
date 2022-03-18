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
    int n,m; cin>>n>>m;
    vector<pair<int,PII>> v(m);

    for(int i=0; i<m; i++)
    {
        cin>>v[i].second.first>>v[i].first;
        v[i].second.second=i+1;
    }

    sort(All(v));

    vector<PII> vv(2*n);
    ll ans=0;
    for(int i=0; i<2*n; i++)
    {
        ans+=v[i].first;
        vv[i]=v[i].second;
    }

    sort(All(vv));

    cout<<ans<<nl;

    int i=0,j=2*n-1;

    while(i<j)
    {
        cout<<vv[i].second<<" "<<vv[j].second<<nl;
        i++;
        j--;
    }
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