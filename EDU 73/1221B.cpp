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

/*----------------------Graph Moves----------------*/
// const int fx[]={+1,-1,+0,+0};
// const int fy[]={+0,+0,+1,-1};
// const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
// const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

void Engine()
{
    int n; cin>>n;
    char g[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)g[i][j]='.';
    }

    queue<PII> q;
    int x,y,x1,y1;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(g[i][j]!='.')continue;
            g[i][j]='W';
            q.push({i,j});

            while(!q.empty())
            {
                x=q.front().first;
                y=q.front().second;
                q.pop();

                for(int k=0; k<8; k++)
                {
                    x1=x+fx[k];
                    y1=y+fy[k];

                    if(x1<0 || x1>=n || y1>=n || y1<0 || g[x1][y1]!='.')continue;

                    if(g[x][y]=='W')g[x1][y1]='B';
                    else g[x1][y1]='W';

                    q.push({x1,y1});
                }
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)cout<<g[i][j];
        cout<<nl;
    }
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