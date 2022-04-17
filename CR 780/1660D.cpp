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
    int n,x,y,mxcnt=0,cnt=0,mncnt=0; cin>>n;
    
    x=n;
    y=0;

    int a[n]; for(int &x:a)cin>>x;

    int lstz=0;
    
    for(int i=0; i<n; i++)
    {
        if(a[i]==0)
        {
            lstz=i+1;
            cnt=0;
            mncnt=0;
        }

        if(a[i]==-2 || a[i]==2)cnt++;
        if(a[i]==-2 || a[i]==-1)mncnt++;

        if(cnt>mxcnt && mncnt%2==0)
        {
            mxcnt=cnt;
            x=lstz;
            y=n-i-1;
        }
    }

    lstz=n+1;
    cnt=0;
    mncnt=0;

    for(int i=n-1; i>=0; i--)
    {
        if(a[i]==0)
        {
            lstz=i+1;
            cnt=0;
            mncnt=0;
        }

        if(a[i]==-2 || a[i]==2)cnt++;
        if(a[i]==-2 || a[i]==-1)mncnt++;

        if(cnt>mxcnt && mncnt%2==0)
        {
            mxcnt=cnt;
            x=i;
            y=n+1-lstz;
        }
    }

    cout<<x<<" "<<y<<nl;
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