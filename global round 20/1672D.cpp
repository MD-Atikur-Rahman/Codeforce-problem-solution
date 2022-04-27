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
    int n; cin>>n;
    int a[n],b[n],cnt[n+1];
    memset(cnt,0,sizeof cnt);

    for(int &x:a)cin>>x;
    for(int &x:b)cin>>x;

    int j=n-1;
    for(int i=n-1; i>=0; i--)
    {
        if(j>=0 && a[i]==b[j])
        {
            while(j>=0 && b[j]==a[i])
            {
                cnt[a[i]]++;
                j--;
            }
            cnt[a[i]]--;
        }
        else
        {
            if(cnt[a[i]]>0)cnt[a[i]]--;
            else
            {
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
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
