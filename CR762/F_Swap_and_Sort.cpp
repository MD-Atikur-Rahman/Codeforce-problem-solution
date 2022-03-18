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

    int n; cin>>n;
    int a[n+1]; for(int i=1; i<=n; i++)cin>>a[i];
    int opr[n+1][n+1];
    memset(opr,-1,sizeof(opr));
    vvi g(n+1);
    int u,v,m; cin>>m;

    for(int i=1; i<=m; i++)
    {
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
        opr[u][v]=i;
        opr[v][u]=i;
    }

    vi ans,path;
    bool flag=true;
    bool vis[n+1];
    int par[n+1];
    queue<int> q;
    int vrt;
    for(int i=1; i<=n; )
    {
        if(a[i]==i)
        {
            i++;
            continue;
        }
        for(int i=0; i<=n; i++)
        {
            vis[i]=false;
            par[i]=i;
        }
        while(!q.empty())q.pop();
        path.clear();
        vis[i]=true;
        q.push(i);

        while(!q.empty())
        {
            vrt=q.front();
            q.pop();

            for(int x:g[vrt])
            {
                if(vis[x])continue;
                vis[x]=true;
                par[x]=vrt;
                q.push(x);
            }
        }
        if(par[a[i]]==a[i])
        {
            flag=false;
            break;
        }

        int ind=a[i];
        while(1)
        {
            path.pb(ind);
            if(ind==par[ind])break;
            ind=par[ind];
        }

        for(int j=0; j<path.size()-1; j++)
        {
            ans.pb(opr[path[j]][path[j+1]]);
        }
        for(int j=path.size()-1; j>0; j--)
        {
            ans.pb(opr[path[j]][path[j-1]]);
        }
        swap(a[i],a[a[i]]);

       // if(a[i]==i)i++;
    }

    if(flag)
    {
        cout<<ans.size()<<nl;
        if(ans.size())print(ans);
    }
    else cout<<-1<<nl;

    return 0;
}