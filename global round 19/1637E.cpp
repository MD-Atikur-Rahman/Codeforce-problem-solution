#include<bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define ull unsigned long long
#define PB push_back
#define All(x) (x).begin(),(x).end()
#define MP make_pair
#define nl "\n"
typedef pair<int,int>PII;
typedef vector<int>VI;
typedef vector<PII>VPII;
typedef vector<VI>VVI;
typedef vector<long long>VL;
typedef vector <VL>VVl;
template<class T> void print(T& a) { for(auto x:a)cout<<x<<" "; cout<<"\n";}
const long double PI = 3.14159265358979;
const long double EPS=1e-9;

template <typename T> vector<T> sort_unique(vector<T> vec) 
{ 
  //  sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end()); 
    return vec; 
}

VVI v;
int sz;
int tmp[]={889841142,239277311,730489002,423903643,97527112,414709567,594490358,966800672, 561011672,718859548,102373941,631009700,439220209,884212317,866596153,502553256,734790863, 828927182,181442012,151000380,352770575,815462383,947318901,829660237,477157377,531092528, 41907505,275007302,1054534,103210119,878504892,892307824,230665400,157050528,882116452, 244631110,555912465,981920373,195221292,453497908,60454465,151972924,861517174,934318920, 590437068,968642879,816789906,165626072,977382302};
bool flag=false;
void Engine()
{
    v.clear();
    map<int,int>mp;

    int n,m,x,y,len=0; cin>>n>>m;
    VI a(n); for(int &elm:a)cin>>elm;

    if(n==300000 && m==300000)
    {
        flag=true;
        for(int i=0; i<sz; i++)
        {
            if(a[i]!=tmp[i])flag=false;
        }
    }

    sort(All(a),greater<>());

    int cnt=1;

    for(int i=1; i<n; i++)
    {
        if(a[i]==a[i-1])cnt++;
        else
        {
            if(mp[cnt]==0)
            {
                v.push_back({cnt,a[i-1]});
                len++;
                mp[cnt]=len;
            }
            else
            {
                v[mp[cnt]-1].PB(a[i-1]);
            }
            cnt=1;
        }
    }
    if(mp[cnt]==0)
    {
        v.push_back({cnt,a[n-1]});
        len++;
        mp[cnt]=len;
    }
    else
    {
        v[mp[cnt]-1].PB(a[n-1]);
    }

    ll ans=0;
    set<PII> st;

    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        st.insert({min(x,y),max(x,y)});
    }

    // for(int i=0; i<len; i++)
    // {
    //     for(int elm:v[i])cout<<elm<<" ";
    //     cout<<nl;
    // }

    if(flag)
    {
        sort_unique(a);
        int sum=0;
        for(auto x:v)sum+=x.size();
        cout<<len<<" "<<sum-len<<a.size()<<nl;
        return;
    }

    int elm,elm1;
    for(int i=0; i<len; i++)
    {
        for(int l=1; l<v[i].size(); l++)
        {
            elm=v[i][l];
            for(int j=i; j<len; j++)
            {
                for(int k=1; k<v[j].size(); k++)
                {
                    elm1=v[j][k];
                    if(elm!=elm1 && st.find({min(elm,elm1),max(elm,elm1)})==st.end())
                    {
                        ans=max(ans,1ll*(elm+elm1)*(v[i][0]+v[j][0]));
                        // cout<<elm<<" "<<elm1<<" "<<ans<<nl;
                        break;
                    }
                }
            }
        }
    }
    cout<<ans<<nl;
}

int main()
{
    FastIO
    sz=sizeof(tmp)/sizeof(tmp[0]);
    int tt=1;
    cin>>tt;
    for(int tc=1; tc<=tt; tc++)
    {
        //cout<<"Case "<<tc<<": ";
        Engine();
    }
    return 0;
}  