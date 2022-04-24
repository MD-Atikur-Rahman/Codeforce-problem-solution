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
    bool flag=false;
    int a[n];

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]==1)flag=true;
    }

    if(flag)
    {
        sort(a,a+n);
        for(int i=1; i<n; i++)
        {
            if(a[i]==a[i-1]+1)
            {
                cout<<"NO\n";
                return;
            }
        }
        cout<<"YES\n";
    }
    else
    {
        cout<<"YES"<<nl;
    }
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