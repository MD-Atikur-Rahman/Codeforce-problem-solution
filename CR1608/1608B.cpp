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
        int n,a,b; cin>>n>>a>>b;
        if(abs(a-b)>1 || a+b>n-2)
        {
            cout<<-1<<nl;
            continue;
        }
        int l=1,r=n;
        vi ans;
        swap(a,b);

        if(a==0 && b==0)
        {
            for(int i=1; i<=n; i++)ans.pb(i);
        }

        else if(a==b)
        {
            ans.pb(2);
            ans.pb(1);
            l+=2;
            a--;

            while(a>0)
            {
                ans.pb(r);
                ans.pb(l);
                r--;
                l++;
                a--;
            }

            for(r; r>=l; r--)ans.pb(r);
        }
        
        else if(a>b)
        {
            ans.pb(2);
            ans.pb(1);
            l+=2;
            a--;

            while(a>0)
            {
                    ans.pb(r);
                    ans.pb(l);
                    r--;
                    l++;
                    a--;
            }

            for(l; l<=r; l++)ans.pb(l);
        }

        else
        {
            ans.pb(1);
            ans.pb(r);
            l++;
            r--;
            b--;

            while(b>0)
            {
                ans.pb(l);
                ans.pb(r);
                r--;
                l++;
                b--;
            }
            for(r; r>=l; r--)ans.pb(r);
        }

        print(ans);

    }

    return 0;
}