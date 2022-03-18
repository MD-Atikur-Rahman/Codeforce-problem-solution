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
    int n,k; cin>>n>>k;
    int a[n],b[n];
    for(int &x:a)cin>>x;
    for(int &x:b)cin>>x;

    int suma=0,sumb=0,ca=0,cb=0;

    bool vis[n];
    memset(vis,0,sizeof(vis));
    int in;
    for(int j=0; j<k; j++)
    {
        ca=cb=0;
    
        for(int i=0; i<n; i++)
        {
            if(vis[i])continue;
            if(a[i]>=ca && b[i]>=cb)
            {
                ca=a[i];
                cb=b[i];
                in=i;
            }
            else if(min(suma+ca,sumb+cb)<min(suma+a[i],sumb+b[i]))
            {
                ca=a[i];
                cb=b[i];
                in=i;
            }
        }
        suma+=ca;
        sumb+=cb;
        vis[in]=true;
    }

    cout<<min(suma,sumb)<<nl;
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