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
        ll n,k,x; cin>>n>>k>>x;
        string s; cin>>s;

        ll cnt[n]={};
        bool b[n]={};
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]=='*')
            {
                b[i]=true;
                if(i+1<n && s[i+1]=='*')
                {
                    cnt[i]=cnt[i+1]+k;
                    cnt[i+1]=1;
                    b[i+1]=false;
                }
                else cnt[i]=k+1;
            }
            else cnt[i]=1;
        }
        for(int i=n-2; i>=0; i--)cnt[i]*=cnt[i+1];
        ll tm;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='a')
            {
                cout<<'a';
                continue;
            }
            if(b[i]==false)continue;
            if(i==n-1)
            {
                for(int j=1; j<x; j++)cout<<'b';
                continue;
            }
            if(cnt[i+1]>=x)continue;
            tm=x/cnt[i+1];
            
            if(x%cnt[i+1]==0)tm--;
            x-=tm*cnt[i+1];
            for(int j=0; j<tm; j++)cout<<'b';
        }
        cout<<nl;
    }

    return 0;
}