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
        ll n; cin>>n;
        ll a[n];
        ll sum=0; 
        for(ll& x:a)
        {
            cin>>x;
            sum+=x;
        }

        ll d=n*(n+1)/2;

        if(sum%d || sum/d<n)
        {
            cout<<"NO\n";
            continue;
        }
        bool flag=true;
        sum/=d;
        vl ans;
        for(int i=0; i<n; i++)
        {
            if(i==0)
            {
                d=(a[i]-a[n-1])-sum;
                if(d%n!=0 || d/n>=0) flag=false;
                d/=(-n);
                ans.pb(d);
            }
            else
            {
                d=(a[i]-a[i-1])-sum;
                if(d%n!=0 || d/n>=0)flag=false;
                d/=(-n);
                ans.pb(d);
            }
        }
        if(flag)
        {
            cout<<"YES\n";
            print(ans);
        }
        else cout<<"NO\n";
    }
    return 0;
}