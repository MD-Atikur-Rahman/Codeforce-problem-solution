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
template<class T> void print(T& a) { for(auto x:a)cout<<x; cout<<"\n";}
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
const long double PI = 3.14159265358979;
const long double EPS=1e-9;


int main()
{
    FastIO

    int tt; cin>>tt;
    while(tt--)
    {
        ll n,s; cin>>n>>s;
        vi ans;
        ll a,b;
        bool flag=true;
        while(n>0)
        {   
            a=n%10l; n/=10l;
            b=s%10l; s/=10l;

            if(b>=a)
            {
                // cout<<a<<" "<<b<<nl;
                ans.pb(b-a);
                continue;
            }

            b+=10l*(s%10l);
            s/=10l;
            // cout<<a<<" "<<b<<nl;
            if(b<a || b-a>=10)
            {
                flag=false;
                break;
            }

            ans.pb(b-a);
        }
        if(flag==false)cout<<-1<<nl;
        else
        {
            reverse(All(ans));
            if(s>0)
            {
                cout<<s;
                for(int x:ans)cout<<x;
                cout<<nl;
                continue;   
            }
            int len=ans.size();
            int i=0;
            while(i<len)
            {
                if(ans[i]==0)i++;
                else break;
            }
            for(i; i<len; i++)cout<<ans[i];
            cout<<nl;
        }
    }

    return 0;
}