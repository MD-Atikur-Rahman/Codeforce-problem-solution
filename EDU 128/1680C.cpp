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

void Engine(int tc)
{
    string s; cin>>s;
    int n=s.length();
    int cnt[n]; memset(cnt,0,sizeof cnt);
    for(int i=0; i<n; i++)
    {
        if(s[i]=='1')cnt[i]=1;
        if(i>0)cnt[i]+=cnt[i-1];
    }
    
    int j,cn,mdl,l=-1,r=n;
    bool flag=false;
    while(l<r)
    {
        mdl=l+r+1>>1;
        if(mdl==r)break;

        flag=false;
        j=0;
        for(int i=0; i<n; i++)
        {
            if(j<i)j=i;
            while(j<n)
            {
                if(j-i+1-(cnt[j]-(i==0? 0:cnt[i-1]))>mdl)break;
                j++;
            }
            if(i>0)cn=cnt[i-1];
            else cn=0;
            if(j<n)
            {
                cn+=cnt[n-1];
                if(j>0)cn-=cnt[j-1];
            }
            if(cn<=mdl)
            {
                flag=true; break;
            }
        }
        if(flag)r=mdl;
        else l=mdl;
    }
    cout<<r<<nl;
}

int main()
{
    FastIO
    int tt=1;
    cin>>tt;
    for(int tc=1; tc<=tt; tc++)
    {
        Engine(tc);
    }
    return 0;
}  