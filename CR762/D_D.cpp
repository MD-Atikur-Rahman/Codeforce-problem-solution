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

int n, m, k,ans;
int grid[1005][1005],destination[1005][1005];

int fun(int i, int j)
{
    if(grid[i][j]==2)
    {
        if(i==n)ans=j;
        
    }
}


int main()
{
    FastIO

    memset(destination,-1,sizeof(destination)); 

    cin>>n>>m>>k;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)cin>>grid[i][j];
    }

    int c; 
    for(int i=0; i<k; i++)
    {
        fun(1,c);
        cout<<ans<<" ";
    }
    cout<<nl;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)cout<<destination[i][j]<<" ";
        cout<<nl;
    }

    return 0;
}