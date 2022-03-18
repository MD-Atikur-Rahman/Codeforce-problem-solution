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

const ll MOD=998244353;


int main()
{
    FastIO

    int tt; cin>>tt;
    while(tt--)
    {
        int n; cin>>n;
        int a[n]; for(int &x:a)cin>>x;
        ll s,dp[n]={}; 
        pair<ll,ll> b[n+1]={};

        for(int i=0; i<n; i++)
        {
            if(a[i]==0)
            {
                dp[i]=1;
                dp[i]+=b[0].second;
                dp[i]%=MOD;
                b[0].second+=dp[i];
                b[0].second%=MOD;
            }

            else if(a[i]==1)
            {
                dp[i]=b[1].second+b[0].second;
                dp[i]++;
                dp[i]+=b[1].first;
                dp[i]%=MOD;
                b[1].second=b[1].second+b[1].second+b[0].second;
                b[1].second%=MOD;
                b[1].first=b[1].first+b[1].first+1;
                b[1].first%=MOD;
            }
            
            else
            {
                dp[i]=b[a[i]].first+b[a[i]].second+b[a[i]-1].second+b[a[i]-2].second;
                dp[i]%=MOD;
                b[a[i]].first+=b[a[i]].first+b[a[i]-2].second;
                b[a[i]].first%=MOD;
                b[a[i]].second+=b[a[i]].second+b[a[i]-1].second;
                b[a[i]].second%=MOD;
            }
        }

        ll ans=0;
        for(ll x:dp)
        {
            ans+=x;
            ans%=MOD;
        }
        if(ans<0)ans+=MOD;
        cout<<ans<<nl;
    }

    return 0;
}