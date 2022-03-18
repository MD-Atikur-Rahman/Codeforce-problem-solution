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

int n,d;

int cnt(VI& v)
{
    int meu=1e9,gap=0;

    for(int i=1; i<n; i++)
    {
        meu=min(meu,v[i]-v[i-1]-1);
        gap=max(gap,v[i]-v[i-1]-1);
    }
    gap=(gap-1)/2;
    gap=max(gap,d-v[n-1]-1);

    return min(gap,meu);
}

void Engine(int tc)
{
    cin>>n>>d;
    
    VI a(n+1),b;
    b.push_back(0);
    
    int meu=d,minpos;
    
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(a[i]-a[i-1]-1<meu)
        {
            meu=a[i]-a[i-1]-1;
            minpos=i;
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(i!=minpos)b.push_back(a[i]);
    }

    meu=max(meu,cnt(b));

    if(minpos>1)
    {
        b[minpos-1]=a[minpos];
        meu=max(meu,cnt(b));
    }

    cout<<meu<<nl;
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