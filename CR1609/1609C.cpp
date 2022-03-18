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

bool isp(int n)
{
    if(n<2)return false;
    if(n==2)return true;
    for(int i=2; i*i<=n; i++)if(n%i==0)return false;
    return true;
}

int main()
{
    FastIO

    int tt; cin>>tt;
    while(tt--)
    {
        int n,e; cin>>n>>e;
        int a[n]; for(int &x:a)cin>>x;
        int lcnt[n]={},rcnt[n]={};

        for(int i=0; i<n; i++)
        {
            if(a[i]==1)
            {
                lcnt[i]=1;
            }
            else continue;
            if(i-e>=0)lcnt[i]+=lcnt[i-e];
        }

        for(int i=n-1; i>=0; i--)
        {
            if(a[i]==1)rcnt[i]=1;
            else continue;
            if(i+e<n)rcnt[i]+=rcnt[i+e];
        }
        ll ans=0;
        // for(int i=0; i<n; i++)cout<<lcnt[i]<<" ";
        // cout<<nl;
        // for(int i=0; i<n; i++)cout<<rcnt[i]<<" ";
        // cout<<nl;
        for(int i=0; i<n; i++)
        {
            if(isp(a[i]))
            {
                if(i+e<n && i-e>=0)
                {
                    ans+=(1ll*rcnt[i+e]*lcnt[i-e]);
                }
                if(i-e>=0)ans+=lcnt[i-e];
                if(i+e<n)ans+=rcnt[i+e];
            }
        }
        cout<<ans<<nl;
    }

    return 0;
}