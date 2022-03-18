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

void Engine()
{
    string s; cin>>s;
    int zc=0,oc=0;

    for(char ch:s)
    {
        if(ch=='0')zc++;
        else oc++;
    }

    if(oc==0 || zc==0)
    {
        cout<<0<<nl;
        return;
    }

    if(oc==zc)
    {
        cout<<oc-1<<nl;
    }
    else
    {
        cout<<min(oc,zc)<<nl;
        return;
    }
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