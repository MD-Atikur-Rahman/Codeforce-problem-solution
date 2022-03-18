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
    int n,m; cin>>n>>m;
    vector<pair<PII,PII>>ans;
    char g[n][m],g1[n][m];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>g[i][j];
            g1[i][j]='0';
        }
    }

    for(int i=n-1; i>=0; i--)
    {
        for(int j=m-1; j>=0; j--)
        {
            if(g[i][j]==g1[i][j])continue;
            if(j==0 && i==0)
            {
                cout<<-1<<nl;
                return;
            }
            if(j==0)ans.push_back({{i,j+1},{i+1,j+1}});
            else ans.push_back({{i+1,j},{i+1,j+1}});
        }
    }
    cout<<ans.size()<<nl;
    for(auto x:ans)
    {
        cout<<x.first.first<<" "<<x.first.second<<" "<<x.second.first<<" "<<x.second.second<<nl;
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