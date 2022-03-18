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
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
const long double PI = 3.14159265358979;
const long double EPS=1e-9;

void Engine()
{
    int n; cin>>n;
    int k[n]; for(int &x:k)cin>>x;
    int h[n]; for(int &x:h)cin>>x;

    int lw,d,hg=-1; 
    ll ans=0;
    for(int i=n-1; i>=0; i--)
    {
        if(hg!=-1 && k[i]<lw)
        {
            d=hg-lw+1;
            ans+=(1ll*d*(d+1))>>1;
            hg=-1;
        }
        if(hg==-1)
        {
            hg=k[i];
            lw=k[i]-h[i]+1;
        }
        else lw=min(lw,k[i]-h[i]+1);
           
    }
    d=hg-lw+1;
    ans+=(1ll*d*(d+1))>>1;
    cout<<ans<<nl;
}

int main()
{
    FastIO
    int tt=1;
    cin>>tt;
    while(tt--)
    {
        Engine();
    }
    return 0;
}  