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
        int n,h,x;
        cin>>n>>h;

        multiset<int> mst;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            mst.insert(x);
        }

        if(n%h)
        {
            cout<<"False\n";
            continue;
        }
        bool flag=true;

        int lc,cnt=0;
        while(!mst.empty())
        {
            if(cnt==0)
            {
                lc=*mst.begin();
                mst.erase(mst.find(lc));
                cnt=1;
            }
            else
            {
                if(mst.find(lc+1)==mst.end())
                {
                    flag=false; break;
                }
                lc++;
                cnt++;
                mst.erase(mst.find(lc));
            }
            if(cnt==h)cnt=0;
        }

        if(flag)cout<<"True"<<nl;
        else cout<<"False"<<nl;
    }

    return 0;
}