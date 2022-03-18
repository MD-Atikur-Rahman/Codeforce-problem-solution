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
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
const long double PI = 3.14159265358979;
const long double EPS=1e-9;

void Engine()
{
    int n,x; cin>>n>>x;
    string s; cin>>s;
    int sum,cnt=0,ans=0,car=0;

    bool flag=true;

    for(char ch:s)
    {
        if(ch=='0')cnt++;
        else
        {
            ans+=(cnt/x);
            sum=cnt%x;
            sum+=car+1;
            if(sum>=x && flag)
            {
                ans++;
                flag=false;
            }
            car=cnt%x;
            cnt=0;
        }
    }

    ans+=(cnt/x);
    sum=cnt%x;
    sum+=car+1;
    if(sum>=x && flag)
    {
        ans++;
        flag=false;
    }

    cout<<ans<<nl;
}

int main()
{
    FastIO
    int tt=1;
    cin>>tt;
    while(tt--)
    {
        Engine();
    }
    return 0;
}  