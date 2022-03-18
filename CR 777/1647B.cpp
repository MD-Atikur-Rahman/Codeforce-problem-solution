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
    bool vis[n][m];
    memset(vis,0,sizeof(vis));
    char g[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)cin>>g[i][j];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(vis[i][j] || g[i][j]=='0')continue;

            int k=j;
            while(k+1<m && g[i][k+1]=='1')k++;
            int cnt=0;

            for(int l=i; l<n; l++)
            {
                cnt=0;
                for(int o=j; o<=k; o++)
                {
                    if(g[l][o]=='1')
                    {
                        vis[l][o]=true;
                        cnt++;
                    }
                }
                if(cnt==0)break;
                if(cnt!=k-j+1)
                {
                    cout<<"NO\n";
                    return;
                }
                if(j-1>=0 && g[l][j-1]=='1')
                {
                    cout<<"NO\n";
                    return;
                }
                if(k+1<m && g[l][k+1]=='1')
                {
                    cout<<"NO\n";
                    return;
                }
            }
        }
    }
    cout<<"YES\n";
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