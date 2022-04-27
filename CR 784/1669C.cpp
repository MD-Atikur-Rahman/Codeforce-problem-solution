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
    int n,x; cin>>n;
    VI v1,v2;

    for(int i=0; i<n; i++)
    {
        cin>>x;
        x%=2;
        if(i&1)v1.push_back(x);
        else v2.push_back(x);
    }

    sort(All(v1));
    sort(All(v2));

    if(v1.front()!=v1.back() || v2.front()!=v2.back())
    {
        cout<<"NO\n";
    }
    else cout<<"YES\n";
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