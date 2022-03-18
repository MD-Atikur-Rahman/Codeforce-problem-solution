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

int dx[]={0,0,1,1};
int dy[]={0,1,0,1};
int fx[]={-1,-1,0,0};
int fy[]={-1,0,-1,0};

void Engine()
{
    int n,m,x,y,x1,y1,x2,y2; cin>>n>>m;
    bool flag[n][m];
    memset(flag,0,sizeof flag);
    int g[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)cin>>g[i][j];
    }
    queue<PII> q;
    vector<pair<PII,int>> ans;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<m-1; j++)
        {
            if(g[i][j]==g[i+1][j] && g[i][j]==g[i][j+1] && g[i][j]==g[i+1][j+1])
            {
                ans.push_back({{i+1,j+1},g[i][j]});
                for(int k=0; k<4; k++)
                {
                    x=i+dx[k];
                    y=j+dy[k];

                    if(flag[x][y]==false)q.push({x,y});
                    flag[x][y]=true;
                }
            }
        }
    }

    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<m; j++)cout<<flag[i][j]<<" ";
    //     cout<<nl;
    // }

    VPII v;
    bool ok;
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            x1=x+fx[i];
            y1=y+fy[i];

            if(x1<0 || x1>=n-1 || y1<0 || y1>=m-1)continue;
            v.clear();
            for(int j=0; j<4; j++)
            {
                x2=x1+dx[j];
                y2=y1+dy[j];

                if(flag[x2][y2]==false)v.push_back({x2,y2});
            }
            if(v.size()==0)continue;
            ok=true;
            for(PII el:v)
            {
                if(g[el.first][el.second]!=g[v[0].first][v[0].second])ok=false;
            }
            if(ok)
            {
                ans.push_back({{x1+1,y1+1},g[v[0].first][v[0].second]});
                for(PII el:v)
                {
                    flag[el.first][el.second]=true;
                    q.push(el);
                }
            }
        }
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<m; j++)cout<<flag[i][j]<<" ";
        //     cout<<nl;
        // }   
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(flag[i][j]==false)
            {
                cout<<-1<<nl;
                return;
            }
        }
    }

    reverse(All(ans));
    cout<<ans.size()<<nl;
    for(auto el:ans)cout<<el.first.first<<" "<<el.first.second<<" "<<el.second<<nl;

    // int final[n][m];

    // for(auto el:ans)
    // {
    //     x=el.first.first;
    //     y=el.first.second;

    //     for(int i=0; i<4; i++)
    //     {
    //         x1=x-1+dx[i];
    //         y1=y-1+dy[i];
    //         final[x1][y1]=el.second;
    //     }
    // }

    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<m; j++)cout<<final[i][j]<<" ";
    //     cout<<nl;
    // }

}

int main()
{
    FastIO
    int tt=1;
    //cin>>tt;
    for(int tc=1; tc<=tt; tc++)
    {
        //cout<<"Case "<<tc<<": ";
        Engine();
    }
    return 0;
}  