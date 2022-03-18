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

int main()
{
    FastIO

    int tt; cin>>tt;
    while(tt--)
    {
        ll n,k; cin>>n>>k;
        ll ans=0;
        ll a[n]; for(ll &x:a)
        {
            cin>>x;
        }

        sort(a,a+n);
        reverse(a,a+n);
        
        for(int i=2*k; i<n; i++)ans+=a[i];

        for(int i=0; i<2*k; )
        {
            int j=i+1,cnt=1;
            for(j; j<2*k; j++)
            {
                if(a[i]==a[j])cnt++;
                else break;
            }
            if(cnt>k)ans+=cnt-k;
            i=j;
        }

        cout<<ans<<nl;
    }

    return 0;
}