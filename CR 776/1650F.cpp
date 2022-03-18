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

struct training
{
    int task,id,perc,time;
};

void Engine(int tc)
{
    int n,m; cin>>n>>m;

    int deadline[n+1];
    for(int i=1; i<=n; i++)cin>>deadline[i];

    training trn[m+1];
    for(int i=1; i<=m; i++)
    {
        cin>>trn[i].task>>trn[i].time>>trn[i].perc;
        trn[i].id=i;
    }

    sort(trn+1,trn+m+1,[&](training a, training b){return a.task<b.task;});

    int dp[m+1][101];
    for(int i=0; i<m+1; i++)
    {
        for(int j=0; j<101; j++)
        {
            if(j==0)dp[i][j]=0;
            else dp[i][j]=deadline[n]+1;
        }
    }

    int cur_task=0,sum=0,lst=0,cur_prc;
    VI ans;

    for(int i=1; i<m+1; i++)
    {
        if(trn[i].task>cur_task+1)
        {
            cout<<-1<<nl;
            return;
        }

        if(trn[i].task==cur_task+1)
        {
            if(cur_task>0)
            {
                if(dp[i-1][100]+sum>deadline[cur_task])
                {
                    cout<<-1<<nl;
                    return;
                }

                sum+=dp[i-1][100];
                cur_prc=100;

                for(int j=i-1; j>lst; j--)
                {
                    if(cur_prc<=0)break;
                    if(dp[j][cur_prc]!=dp[j-1][cur_prc])
                    {
                        ans.push_back(trn[j].id);
                        cur_prc-=trn[j].perc;
                    }
                }
                for(int j=1; j<101; j++)dp[i-1][j]=deadline[n]+1;
            }

            cur_task++;
            lst=i-1;
        }

        for(int j=1; j<101; j++)
        {
            dp[i][j]=min(dp[i-1][j],trn[i].time+((j-trn[i].perc)>0 ? dp[i-1][j-trn[i].perc]:0));
        }
    }

    if(dp[m][100]+sum>deadline[cur_task] || cur_task!=n)
    {
        cout<<-1<<nl;
        return;
    }

    cur_prc=100;

    for(int j=m; j>lst; j--)
    {
        if(cur_prc<=0)break;
        if(dp[j][cur_prc]!=dp[j-1][cur_prc])
        {
            ans.push_back(trn[j].id);
            cur_prc-=trn[j].perc;
        }
    }

    cout<<ans.size()<<nl;
    print(ans);
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