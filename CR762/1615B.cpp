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
int cnt[32][MX];

int main()
{
    FastIO
    
    int v;
    for(int i=1; i<MX; i++)
    {
        v=i;

        for(int j=0; j<31; j++)
        {
            if((1<<j)&v)cnt[j][i]++;
        }
    }

    for(int i=0; i<32; i++)
    {
        for(int j=1; j<MX; j++)cnt[i][j]+=cnt[i][j-1];
    }

    int tt; cin>>tt;
    while(tt--)
    {
        int l, r; cin>>l>>r;
        int mxc=0;

        for(int i=0; i<32; i++)
        {
            mxc=max(mxc,cnt[i][r]-cnt[i][l-1]);
        }   
        cout<<r-l+1-mxc<<nl;
    }

    return 0;
}