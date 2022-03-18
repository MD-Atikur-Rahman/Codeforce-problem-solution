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
const int MX=1e3+5;

int pr[MX],rnk[MX];

int findp(int v)
{
    if(v!=pr[v])pr[v]=findp(pr[v]);
    return pr[v];
}

int main()
{
    FastIO

    int n,d; cin>>n>>d;

    priority_queue<ii> pq,pq1;

    for(int i=1; i<=n; i++)
    {
        pr[i]=i;
        rnk[i]=1;
        pq.push({1,i});
    }

    int ans,into=0,mil=0;
    int a,b,pra,prb;
    while(d--)
    {
        into++;

        cin>>a>>b;
        
        pra=findp(a);
        prb=findp(b);
    
        if(pra!=prb)
        {
            mil++;
            if(rnk[prb]>rnk[pra])swap(pra,prb);
            pr[prb]=pra;
            rnk[pra]+=rnk[prb];
            pq.push({rnk[pra],pra});
        }

        int j=mil;
        ans=0;
        while(j<=into)
        {
            while(pr[pq.top().second]!=pq.top().second || rnk[pq.top().second]!=pq.top().first)
            {
               pq.pop();
            }
            ans+=pq.top().first;
            pq1.push(pq.top());
            pq.pop();
            j++;
        }
        while(!pq1.empty())
        {
            pq.push(pq1.top());
            pq1.pop();
        }
        cout<<ans-1<<nl;
    }

    return 0;
}