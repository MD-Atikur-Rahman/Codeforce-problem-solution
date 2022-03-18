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
        ll n,tn; cin>>n;
        tn=n;
        bool flag=true;
        if(n&1)
        {
            n--;
            flag=false;
        }

        ll cnt=0;

        while(n>4)
        {
            if((n>>1)&1)
            {
                n>>=1;
                cnt+=n;
                n--;
            }
            else 
            {
                cnt++;
                n-=2;
            }
        }
        if(n==1 || n==2)cnt++;
        else if(n==3)cnt+=2;
        else if(n==4)cnt+=3;

        if(flag)cout<<cnt<<nl;
        else cout<<tn-cnt<<nl;
    }

    return 0;
}