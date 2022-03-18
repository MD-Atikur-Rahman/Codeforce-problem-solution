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

const ll MOD=1e9+7;

int main()
{
    FastIO

    ll n; cin>>n;
    ll s,d;
    set<ll> st; 
    st.insert(1);
    for(ll i=2; i*i<n; i++)
    {
        d=i;
        s=1+i;

        while(1)
        {
            d*=i;
            s+=d;
            if(s>=n)break;
            else st.insert(s);
        }
    }

    //cout<<st.size()<<nl;
    ll sum=0;

    for(ll x:st)
    {
        sum+=x;
        sum%=MOD;
    }
    cout<<sum<<nl;

    return 0;
}