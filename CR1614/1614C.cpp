#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
#define All(x) (x).begin(),(x).end()
#define mp make_pair
#define nl "\n"
typedef pair<int,int>ii;
typedef vector<int>vi;
typedef vector<ii>vii;
typedef vector<vi>vvi;
typedef vector<long long>vl;
typedef vector <vl>vvl;
typedef tree<pair<int,int>, null_type,less<pair<int, int>>, rb_tree_tag,
    tree_order_statistics_node_update> indexed_multiset;
template<class T> void print(T& a) { for(auto x:a)cout<<x<<" "; cout<<"\n";}
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
const long double PI = 3.14159265358979;
const long double EPS=1e-9;

const int MX=2e5+5;
const ll MOD=1e9+7;

ll bexp(ll n, ll p)
{
    ll res=1;
    while(p)
    {
        if(p&1)res=res*n%MOD;
        p>>=1;
        n=n*n%MOD;
    }
    return res;
}

bool comp(pair<ii,int> a, pair<ii,int> b)
{
    if(a.first.first==b.first.first)return a.first.second>b.first.second;
    return a.first.first<b.first.first;
}


int main()
{
    FastIO

    int tt; cin>>tt;
    while(tt--)
    {
        int n,m; cin>>n>>m;
        pair<ii,int> a[m];
        for(int i=0; i<m; i++)
        {
            cin>>a[i].first.first>>a[i].first.second>>a[i].second;
        }
        // for(int i=0; i<m; i++)
        // {
        //     cout<<a[i].first.first<<" "<<a[i].first.second<<" "<<a[i].second<<nl;
        // }

        sort(a,a+m,comp);

        ll ans=0;
        int cnt[30]={};

        int pas=0;
        for(int i=0; i<m; i++)
        {
            if(a[i].first.second<=pas)continue;
            pas=a[i].first.second;
          //  cout<<a[i].second<<nl;
            for(int j=0; j<30; j++)
            {
                if((1<<j)&a[i].second)cnt[j]++;
               // cout<<cnt[j]<<" ";
            }
            //cout<<nl;
        }
        //cout<<nl;
        ll ss,sp;

        
        for(int i=0; i<30; i++)
        {
            if(cnt[i]==0)continue;
            ss=n-cnt[i];
            sp=bexp(2, ss);
            ss=bexp(2,cnt[i]-1)*sp%MOD*bexp(2,i)%MOD;
            ans+=ss;

        }
        cout<<ans<<nl;
    }   

    return 0;
}