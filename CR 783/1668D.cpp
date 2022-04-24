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

VL par,sum,pl,pr;

int findp(int v)
{
    if(par[v]==v)return v;
    par[v]=findp(par[v]);
    return par[v];
}

void Engine(int tc)
{
    int p,l,r,n,lpp,rpp; 
    cin>>n;

    par.clear();
    sum.clear();
    pl.clear();
    pr.clear();
    par.resize(n+1);
    sum.resize(n+1);
    pl.resize(n+1);
    pr.resize(n+1);

    for(int i=1; i<=n; i++)
    {
        cin>>sum[i];
        par[i]=i;
        pl[i]=i;
        pr[i]=i;
    }
    bool flag;
    for(int i=1; i<=n; i++)
    {
        if(findp(i)!=i || sum[i]<=0)continue;

        p=i;
        while(1)
        {
            flag=false;

            l=pl[p];
            r=pr[p];

            if(l>1 && r<n)
            {
                lpp=findp(l-1);
                rpp=findp(r+1);

                if(sum[lpp]>=sum[rpp] && sum[p]+sum[lpp]>0)
                {
                    flag=true;
                    pl[p]=pl[lpp];
                    sum[p]+=sum[lpp];
                    par[lpp]=p;
                }
                else if(sum[p]+sum[rpp]>0)
                {
                    flag=true;
                    pr[p]=pr[rpp];
                    sum[p]+=sum[rpp];
                    par[rpp]=p;
                    // cout<<p<<" "<<rpp<<" "<<findp(rpp)<<" "<<pl[p]<<" "<<pr[p]<<nl;
                }
            }


            else if(l>1)
            {
                lpp=findp(l-1);
                if(sum[p]+sum[lpp]>0)
                {
                    flag=true;
                    pl[p]=pl[lpp];
                    sum[p]+=sum[lpp];
                    par[lpp]=p;
                }
            }

            else if(r<n)
            {
                rpp=findp(r+1);
                if(sum[p]+sum[rpp]>0)
                {
                    flag=true;
                    pr[p]=pr[rpp];
                    sum[p]+=sum[rpp];
                    par[rpp]=p;
                    // cout<<p<<" "<<rpp<<" "<<findp(rpp)<<" "<<pl[p]<<" "<<pr[p]<<nl;
                }
            }
            // cout<<p<<" "<<sum[p]<<nl;

            if(flag==false)break;
        }

    }

    int ans=0;

    for(int i=1; i<=n; i++)
    {
        p=findp(i);
        if(p!=i)continue;

        if(sum[p]<0)ans-=(pr[p]-pl[p]+1);
        if(sum[p]>0)ans+=(pr[p]-pl[p]+1);
    }

    cout<<ans<<nl;
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