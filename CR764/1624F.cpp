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

    int l=1,r=n,m,cr=0,lst=0,cur;

    while(r-l>1)
    {
        m=l+r>>1;
        
        cout<<"+ "<<n-m<<nl;
        cout.flush();
        cin>>cur;

        if(cur==lst)r=m;
        else l=m;

        l=(l+n-m)%n;
        r=(r+n-m)%n;

        if(r==0)r=n;
        lst=cur;
    }

    cout<<"! "<<n*cur+l<<nl;
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