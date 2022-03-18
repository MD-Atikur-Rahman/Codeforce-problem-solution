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

    int n,q; cin>>n>>q;
    bool b[n]={};
    string s; cin>>s;
    int cnt=0;

    for(int i=2; i<n; i++)
    {
        if(s[i-2]=='a' && s[i-1]=='b' && s[i]=='c')
        {
            cnt++;
            b[i-2]=true;
        }
    }

    int pos;
    char c;
    //cout<<cnt<<nl;

    while(q--)
    {
        cin>>pos>>c;

        pos--;

        if(s[pos]=='a' && b[pos]==true)cnt--,b[pos]=false;
        else if(s[pos]=='b' && pos>0 && b[pos-1]==true)cnt--,b[pos-1]=false;
        else if(s[pos]=='c' && pos>1 && b[pos-2]==true)cnt--,b[pos-2]=false;

        s[pos]=c;

        if(s[pos]=='a' && pos+2<n && s[pos+1]=='b' && s[pos+2]=='c' && b[pos]==false)cnt++,b[pos]=true;
        else if(s[pos]=='b' && pos+1<n && pos>0 && s[pos+1]=='c' && s[pos-1]=='a' && b[pos-1]==false)cnt++,b[pos-1]=true;
        else if(s[pos]=='c' && pos>1 && s[pos-1]=='b' && s[pos-2]=='a' && b[pos-2]==false)cnt++,b[pos-2]=true;
        
        cout<<cnt<<nl;
    }

    return 0;
}