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
    int tmp,d,a,b,c; cin>>a>>b>>c;
    
    d=b-a;
    tmp=b+d;

    if(tmp%c==0 && tmp>=c)
    {
        cout<<"YES\n";
        return;
    }

    d=c-a;
    if(d%2==0 && (a+(d/2))%b==0 && (a+(d/2))>=b)
    {
        cout<<"YES\n";
        return;
    }

    d=c-b;
    d*=2;
    tmp=c-d;

    if(tmp%a==0 && tmp>=a)
    {
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
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