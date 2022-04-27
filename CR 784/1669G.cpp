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
    char g[n][m];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)cin>>g[i][j];
    }
    
    int li,dc,sc;

    for(int j=0; j<m; j++)
    {
        li=0;
        dc=0;
        sc=0;
        for(int i=0; i<n; i++)
        {
            if(g[i][j]=='o')
            {
                for(int k=li; k<li+dc; k++)g[k][j]='.';
                for(int k=li+dc; k<li+dc+sc; k++)g[k][j]='*';
                li=i+1;
                dc=0;
                sc=0;
            }
            else if(g[i][j]=='.')dc++;
            else sc++;
        }
        for(int k=li; k<li+dc; k++)g[k][j]='.';
        for(int k=li+dc; k<li+dc+sc; k++)g[k][j]='*';
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)cout<<g[i][j];
        cout<<nl;
    }

    cout<<nl;
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