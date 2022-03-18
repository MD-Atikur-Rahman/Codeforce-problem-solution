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
        int n,m; cin>>m>>n;
        int fmax[n]={},smax[n]={},ind[n]={};
        int x;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>x;
                if(x>fmax[j])
                {
                    smax[j]=fmax[j];
                    fmax[j]=x;
                    ind[j]=i;
                }
                else if(x>smax[j])smax[j]=x;
            }
        }

        set<int>s ;
        for(int x:ind)s.insert(x);

        if(s.size()>n-1)
        {
            cout<<min(*min_element(fmax,fmax+n),*max_element(smax,smax+n))<<nl;
        }
        else cout<<*min_element(fmax,fmax+n)<<nl;
    }

    return 0;
}   