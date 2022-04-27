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
    int ht,m,l=0,h=n*2000+n;
    int onerow;
    
    while(l<h)
    {
        m=(l+h+1)>>1;
        if(m==h)break;

        cout<<"? "<<m<<nl;
        cout.flush();
        cin>>ht;

        if(ht!=1)l=m;
        else h=m;
    }
    onerow=h;

    int ans=h;

    for(int i=2; i<=n; i++)
    {
        m=onerow-i+1;
        if(m%i)
        {
            m+=i;
            m-=(m%i);
        }

        m/=i;
        cout<<"? "<<m<<nl;
        cout.flush();
        cin>>ht;

        if(ht==i) ans=min(ans,i*m);
    }
    cout<<"! "<<ans<<nl;
    cout.flush();
}

int main()
{
    // FastIO
    int tt=1;
    //cin>>tt;
    for(int tc=1; tc<=tt; tc++)
    {
        Engine(tc);
    }
    return 0;
}  