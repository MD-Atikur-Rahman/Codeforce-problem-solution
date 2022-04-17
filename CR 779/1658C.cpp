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
    int n,one=-1,ls=1; cin>>n;

    int a[n]; 
    bool flag=true;

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]==1)one=i;
    }

    if(one==-1)
    {
        cout<<"NO"<<nl;
        return;
    }

    for(int i=1; i<n; i++)
    {
        if(a[(one+i)%n]==1 || a[(one+i)%n]>ls+1)flag=false;
        ls=a[(one+i)%n];
    }   

    cout<<(flag? "YES":"NO")<<nl;
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