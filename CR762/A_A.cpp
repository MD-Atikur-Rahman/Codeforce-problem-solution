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

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


int main()
{
    FastIO

    int tt; cin>>tt;
    while(tt--)
    {
        ll n,k; cin>>n>>k;
        k++;
        ll a[n]; 
        for(ll &x:a)
        {
            cin>>x;
            x=binpow(10,x);
        }

        ll cnt=0,cnt1,s=0;

        for(int i=0; i<n; i++)
        {
            if(i==n-1)
            {
                s+=(k-cnt)*a[i];
            }
            else
            {
                cnt1=(a[i+1]-s-1)/a[i];
                cnt1=min(cnt1,k-cnt);
                s+=cnt1*a[i];
                cnt+=cnt1;
            }
           // cout<<s<<" "<<cnt<<nl;
        }
        cout<<s<<nl;
    }

    return 0;
}