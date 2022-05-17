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
    int n,q; cin>>n>>q;
    ll sum=0;
    int a[n]; for(int &x:a){cin>>x; sum+=x;}
    
    int lx,lf=-1,lst[n];
    memset(lst,0,sizeof lst);

    int t,ind,x;
    for(int i=1; i<=q; i++)
    {
        cin>>t;
        if(t==2)
        {
            cin>>x;
            lf=i;
            lx=x;
            sum=1ll*n*x;
        }
        else
        {
            cin>>ind>>x;
            ind--;
            if(lst[ind]>lf)
            {
                sum-=a[ind];
            }
            else
            {
                sum-=lx;
            }
            sum+=x;
            a[ind]=x;
            lst[ind]=i;
        }
        cout<<sum<<nl;
    }
}

int main()
{
    FastIO
    int tt=1;
    // cin>>tt;
    for(int tc=1; tc<=tt; tc++)
    {
        Engine(tc);
    }
    return 0;
}  