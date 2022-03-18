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
    //FastIO

    int tt; cin>>tt;
    while(tt--)
    {
        int g,n; cin>>n;

        bool b[n+1]={};
        vi ans;

        for(int i=1; i+2<=n; i++)
        {
            cout<<"? "<<i<<" "<<i+1<<" "<<i+2<<nl;
            cout.flush();
            cin>>g;
            if(g==1)b[i]=true;
        }

        int in1,in2;

        for(int i=1; i+2<n; i++)
        {
            if(b[i]!=b[i+1])
            {
                if(b[i]==true)
                {
                    in1=i;
                    in2=i+3;
                }
                else
                {
                    in1=i+3;
                    in2=i;
                }
                ans.pb(in2);
                break;
            }
        }

        for(int i=1; i<=n; i++)
        {
            if(i==in1 || i==in2)continue;

            cout<<"? "<<i<<" "<<in1<<" "<<in2<<nl;
            cout.flush();
            cin>>g;
            if(g==0)ans.pb(i);
        }

        cout<<"! "<<ans.size()<<" ";
        print(ans);
        cout.flush();
    }

    return 0;
}