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

long long count_inversion(vector<int>& v,int l,int r)
{
    if(l>=r)return 0;
    int m=l+r>>1;
    long long res=count_inversion(v,l,m)+count_inversion(v,m+1,r);
    vector<int> tem;
    int i=l,j=m+1;
 
    while(i<=m || j<=r)
    {
        if(i<=m && j<=r)
        {
            if(v[i]>v[j])
            {
                res+=m-i+1;
                tem.push_back(v[j]);
                j++;
            }
            else
            {
                tem.push_back(v[i]);
                i++;
            }
        }
 
        else if(i<=m)
        {
            tem.push_back(v[i]);
            i++;
        }
        else 
        {
            tem.push_back(v[j]);
            j++;
        }
    }
    for(int i=l; i<=r; i++)v[i]=tem[i-l];
 
    return res;
}

int main()
{
    FastIO

    int tt; cin>>tt;
    while(tt--)
    {
        int n; cin>>n;
        vi v(n); for(int &x:v)cin>>x;
        set<int> s;
        for(int x:v)s.insert(x);

        if(s.size()!=n)
        {
            cout<<"YES"<<nl;
            continue;
        }

        ll cnt=count_inversion(v,0,n-1);
        cout<<(cnt&1? "NO":"YES")<<nl;
    }    

    return 0;
}