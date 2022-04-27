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
    int a[n]; for(int &x:a)cin>>x;

    int cnt=0;

    for(int i=0; i+1<n; i++)if(a[i]==a[i+1])cnt++;

    if(cnt<=1)
    {
        cout<<0<<nl;
        return;
    }
    cnt=0;
    for(int i=0; i+1<n; i++)
    {
        cnt++;
        if(a[i]==a[i+1])break;
    }

    for(int i=n-1; i>0; i--)
    {
        cnt++;
        if(a[i]==a[i-1])break;
    }

    cnt=n-cnt;
    if(cnt>1)cnt--;
    cout<<cnt<<nl;
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