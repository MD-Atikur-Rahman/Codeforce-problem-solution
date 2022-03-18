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


int main()
{
    FastIO

    int tt; cin>>tt;
    while(tt--)
    {
        int n; cin>>n; 
        ll a[n]; for(ll &x:a)cin>>x;
        ll ods[n];memset(ods,0,sizeof(ods));
        ll evs[n];memset(ods,0,sizeof(ods));
        ll odm[n],evm[n];

        for(int i=0; i<n; i++)odm[i]=evm[i]=LONG_LONG_MAX;

        evs[0]=a[0];
        evm[0]=a[0];

        ll ans1,ans=LONG_LONG_MAX;
        ll odc=0,evc=1;
        for(int i=1; i<n; i++)
        {
            evs[i]=evs[i-1];
            evm[i]=evm[i-1];
            ods[i]=ods[i-1];
            odm[i]=odm[i-1];

            if(i&1)
            {
                ods[i]+=a[i];
                odm[i]=min(odm[i],a[i]);
            }
            else
            {
                evs[i]+=a[i];
                evm[i]=min(evm[i],a[i]);
            }
            if(i&1)odc++;
            else evc++;

            ans1=ods[i]+odm[i]*(n-odc)+evs[i]+evm[i]*(n-evc);
           // cout<<odc<<" "<<evc<<" "<<evm[i]<<" "<<odm[i]<<" "<<ans1<<nl;
            //cout<<ods[i]<<" "<<evs[i]<<nl;
            ans=min(ans,ans1);
        }

        cout<<ans<<nl;
    }

    return 0;
}