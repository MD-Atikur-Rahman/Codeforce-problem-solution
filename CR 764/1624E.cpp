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

struct info
{
    int id,l;
};


void Engine(int tc)
{
    int n,m; cin>>n>>m;
    vector<string> vs(n);
    string s,ts;
    for(string &x:vs)cin>>x;
    cin>>s;

    map<string,info> mp; 

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m-1; j++)
        {
            ts=vs[i].substr(j,2);
            mp[ts].id=i+1;
            mp[ts].l=j+1;
            
            if(j<m-2)
            {
                ts=vs[i].substr(j,3);
                mp[ts].id=i+1;
                mp[ts].l=j+1;
            }
        }
    }
    pair<int,PII> dp[m];
    memset(dp,0,sizeof(dp));

    for(int i=m-2; i>=0; i--)
    {
        ts=s.substr(i,2);
        if(mp[ts].id!=0)
        {
            if(i+2>=m || dp[i+2].first!=0)
            {
                dp[i].first=mp[ts].id;
                dp[i].second.first=2;
                dp[i].second.second=mp[ts].l;
                continue;
            }
        }
        if(i<m-2)
        {
            ts=s.substr(i,3);
            if(mp[ts].id!=0)
            {
                if(i+3>=m || dp[i+3].first!=0)
                {
                    dp[i].first=mp[ts].id;
                    dp[i].second.first=3;
                    dp[i].second.second=mp[ts].l;
                }
            }
        }
    }

    if(dp[0].first==0)
    {
        cout<<-1<<nl;
        return;
    }

    int i=0,cnt=0;

    while(i<m)
    {
        cnt++;
        i+=dp[i].second.first;
    }

    cout<<cnt<<nl;

    i=0;
    while(i<m)
    {
        cout<<dp[i].second.second<<" "<<dp[i].second.second+dp[i].second.first-1<<" "<<dp[i].first<<nl;
        i+=dp[i].second.first;
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