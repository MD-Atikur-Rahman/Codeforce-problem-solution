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
    int cnt[26];
    memset(cnt,0,sizeof cnt);

    int n,k; cin>>n>>k;
    string s; cin>>s;

    for(char ch:s)
    {
        cnt[ch-'a']++;
    }

    int pc=0,sc=0;

    for(int i=0; i<26; i++)
    {
        pc+=cnt[i]/2;
        if(cnt[i]&1)sc++;
    }

    int d=pc/k;
    pc%=k;
    sc+=pc*2;

    int ans=d*2+(sc>=k? 1:0);
    cout<<ans<<nl;
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