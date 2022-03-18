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
        int a[n+1];
        a[0]=0;
        for(int i=1; i<=n; i++)cin>>a[i];
        bool vis[n+1]={};
        vi v;
        for(int i=1; i<=n; i++)
        {
            if(a[i]<=n)
            {
                if(vis[a[i]]==false)vis[a[i]]=true;
                else v.pb(a[i]);
            }
            else v.pb(a[i]);
        }

        sort(All(v));

        bool flag=true;
        int j=1;

        for(int i=0; i<v.size(); i++)
        {
            while(j<=n && vis[j]==true)j++;
            if(v[i]<j || v[i]-j<=j)flag=false;
            vis[j]=true;
        }
        if(flag)cout<<v.size()<<nl;
        else cout<<-1<<nl;
    }

    return 0;
}