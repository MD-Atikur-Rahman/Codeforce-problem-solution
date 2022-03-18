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

bool comp(pair<ii,int>a, pair<ii,int>b)
{
    return a.first.second<b.first.second;
}

int main()
{
    FastIO

    int tt; cin>>tt;
    while(tt--)
    {
        int n; cin>>n;
        ii a[n],b[n];
        int a1[n],b1[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i].first;
            a1[i]=a[i].first;
            a[i].second=i;
        }
        for(int i=0; i<n; i++)
        {
            cin>>b[i].first;
            b1[i]=b[i].first;
            b[i].second=i;
        }
        sort(a,a+n);
        sort(b,b+n);

        bool flag[n]={};

        flag[a[n-1].second]=true;
        flag[b[n-1].second]=true;

        int in1=n-2,in2=n-2;
        int mna=a1[b[n-1].second],mnb=b1[a[n-1].second];

        bool ok;
        while(in1>=0 || in2>=0)
        {
            ok=false;

            if(a[in1].first>mna)
            {
                flag[a[in1].second]=true;
                mna=min(mna,a[in1].first);
                mnb=min(mnb,b1[a[in1].second]);                
                in1--;
                ok=true;
            }
            if(b[in2].first>mnb)
            {
                flag[b[in2].second]=true;
                mna=min(mna,a1[b[in2].second]);
                mnb=min(mnb,b[in2].first);                
                in2--;
                ok=true;
            }
            if(!ok)break;
        }

        for(int i=0; i<n;i++)
        {
            if(flag[i])cout<<1;
            else cout<<0;
        }
        cout<<nl;
    }

    return 0;
}