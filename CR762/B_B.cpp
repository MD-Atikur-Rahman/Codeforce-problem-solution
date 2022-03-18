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
        int a[n]; for(int &x:a)cin>>x;

        int ans=0,cnt;
        bool one=false,two=false;
        for(int x:a)
        {
            cnt=x/3;
            if(x%3==1)one=true;
            else if(x%3==2)two=true;
            ans=max(ans,cnt);
        }
        if(one)ans++;
        if(two)ans++;

        int mx=*max_element(a,a+n);
        int mn=*min_element(a,a+n);
        
        if(one && two)
        {
            if(mx%3==0)ans--;
            if(mx%3==1 && mn>1)ans--;
        }

        cout<<ans<<nl;
    }

    return 0;
}