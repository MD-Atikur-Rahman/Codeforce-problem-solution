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
    int x,l,r; cin>>l>>r;
    int cnt[17],cnt1[17];
    memset(cnt,0,sizeof cnt);
    memset(cnt1,0,sizeof cnt1);

    for(int i=l; i<=r; i++)
    {
        x=i;
        for(int j=0; j<17; j++)
        {
            if(x&1)cnt[j]++;
            x>>=1;
        }
    }

    for(int i=l; i<=r; i++)
    {
        cin>>x;
        for(int j=0; j<17; j++)
        {
            if(x&1)cnt1[j]++;
            x>>=1;
        }
    }

    int ans=0;

    for(int i=0; i<17; i++)
    {
        if(cnt1[i]!=cnt[i])ans+=(1<<i);
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