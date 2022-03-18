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

bool cmp(int a, int b)
{
    ll res1,res2;
    res1=a; res2=b;
    ll mlt1=1,mlt2=1;
    for(int i=0; ; i++)
    {
        mlt1*=10l;
        if(a/mlt1==0)break;
    }
    for(int i=0; ; i++)
    {
        mlt2*=10l;
        if(b/mlt2==0)break;
    }

    res1*=mlt2;
    res2*=mlt1;

    res1+=b;
    res2+=a;

    return res1>res2;
}

int main()
{
    FastIO

    int tt; cin>>tt;
    for(int tc=1; tc<=tt; tc++)
    {
        int n; cin>>n;
        int a[n]; for(int &x:a)cin>>x;
        sort(a,a+n,cmp);
        cout<<"Case "<<tc<<": ";
        for(int &x:a)cout<<x;
        cout<<nl;
    }

    return 0;
}