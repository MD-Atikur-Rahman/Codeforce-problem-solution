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

int fun(int val)
{
    int tmp=1;
    while(tmp<val)tmp<<=1;
    return tmp-val;
}

void Engine()
{
    int x,n; cin>>n;
    int cnt[n+1];
    memset(cnt,0,sizeof(cnt));
    for(int i=0; i<n; i++)
    {
        cin>>x;
        cnt[x]++;
    }
    
    int sum2,sum1=1;
    int i=0,j,cnt1=0,cnt2;
    bool flag;
    int ans=INT32_MAX;

    // for(int i=0; i<=n; i++)cout<<cnt[i]<<" ";
    // cout<<nl;
    while(1)
    {
        sum2=1;
        j=n;
        cnt2=0;
        while(1)
        {
            flag=true;
            while(i<=n)
            {
                if(cnt1+cnt[i]>sum1)
                {
                    if(i==1)flag=false;
                    break;
                }
                cnt1+=cnt[i];
                i++;
            }

            while(j>i)
            {
                if(cnt2+cnt[j]>sum2)break;
                cnt2+=cnt[j];
                j--;
            }

            if(flag)ans=min(ans,sum1+sum2-cnt1-cnt2+fun(n-cnt1-cnt2));

            // cout<<sum1<<" "<<sum2<<" "<<ans<<nl;
            // cout<<cnt1<<" "<<cnt2<<nl;
            // cout<<i<<" "<<j<<nl;
            if(sum1+sum2>n)break;
            sum2<<=1;
        }
        if(sum1>n)break;
        sum1<<=1;
    }
    cout<<ans<<nl;
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