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
const int SZ=1e6+2;
int cnt[SZ];

void Engine()
{
    int n,c,x,y,r; cin>>n>>c;
    for(int i=0; i<=c; i++)cnt[i]=0;
    bool flag=true;

    for(int i=0; i<n; i++)
    {
        cin>>x;
        cnt[x]++;
    }
    for(int i=1; i<=c; i++)cnt[i]+=cnt[i-1];

    for(r=1; r<=c; r++)
    {
        if(cnt[r]==cnt[r-1])
        {
            for(x=1; x*r<=c; x++)
            {
                if(cnt[x]>cnt[x-1] && cnt[x*r-1]<cnt[min(c,x*(r+1)-1)])flag=false;
            }
        }
    }

    if(flag)cout<<"Yes\n";
    else cout<<"No\n";
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