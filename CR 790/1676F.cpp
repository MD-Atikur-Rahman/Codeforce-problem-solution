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
    int n,k; cin>>n>>k;
    int a[n];
    map<int,int> mp;
    for(int& x:a)
    {
        cin>>x;
        mp[x]++;
    }

    sort(a,a+n);

    int lst=0;
    int l=-1,r=-1;
    for(int i=0; i<n; i++)
    {
        if(a[i]<=lst || mp[a[i]]<k)continue;
        lst=a[i];
        for(int j=a[i]+1; ; j++)
        {
            if(mp[j]<k)
            {
                if(j-lst>=r-l+1)
                {
                    l=lst;
                    r=j-1;
                }
                lst=j;
                break;
            }
        }
    }
    if(l<0)cout<<-1<<nl;
    else cout<<l<<" "<<r<<nl;
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