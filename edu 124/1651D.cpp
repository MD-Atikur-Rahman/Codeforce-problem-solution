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
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
// const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
// const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
// const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
// const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

void Engine(int tc)
{
    int n,x,y; cin>>n;
    map<PII,int> ind;
    PII ar[n],ans[n];

    for(int i=0; i<n; i++)
    {
        cin>>ar[i].first>>ar[i].second;
        ind[ar[i]]=i+1;
        ans[i]=MP(1e7,1e7);
    }

    queue<PII> q;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<4; j++)
        {
            x=ar[i].first+fx[j];
            y=ar[i].second+fy[j];

            if(ind[MP(x,y)]==0)
            {
                q.push(ar[i]);
                ans[i]=MP(x,y);
                break;
            }
        }
    }
    int x1,y1,idx;
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;

        // cout<<x<<" "<<y<<nl;

        q.pop();

        for(int i=0 ; i<4; i++)
        {
            x1=x+fx[i];
            y1=y+fy[i];

            if(ind[MP(x1,y1)]!=0)
            {
                // cout<<x1<<" "<<y1<<nl;
                idx=ind[MP(x1,y1)]-1;
                if(ans[idx].first!=10000000)continue;
                ans[idx]=ans[ind[MP(x,y)]-1];
                q.push(MP(x1,y1));
            }
        }
    }
    cout<<nl;
    for(int i=0; i<n; i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<nl;
    }
}

int main()
{
    FastIO
    int tt=1;
    //cin>>tt;
    for(int tc=1; tc<=tt; tc++)
    {
        Engine(tc);
    }
    return 0;
}  