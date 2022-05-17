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

vector<ll> bit;
int n;

ll sum(int idx) {
    ll ret = 0;
    for (idx; idx > 0; idx -= idx & -idx)
        ret += bit[idx];
    return ret;
}

ll sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

void add(int idx, int delta) {
    for (idx; idx <= n; idx += idx & -idx)
        bit[idx] += delta;
}


void Engine(int tc)
{
    cin>>n;
    bit.clear();
    bit.resize(n+1);
    int val;
    ll ans=0;
    for(int i=1; i<=n; i++)
    {
        cin>>val;
        ans+=sum(n)-sum(val-1);
        add(val,1);
        // cout<<ans<<nl;
        // for(int i=0; i<=n; i++)cout<<bit[i]<<" ";
        // cout<<nl;
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