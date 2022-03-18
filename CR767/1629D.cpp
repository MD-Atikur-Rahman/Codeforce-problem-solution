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
    int n; cin>>n;
    vector<string> v(n);
    bool flag=false;
    map<string,int> mp;
    for(string &x:v)
    {
        cin>>x;
        if(x.length()==1)flag=true;
        if(x.length()==2)mp[x]++;
        if(x.length()==3)mp[x.substr(1)]++;
    }

    for(string x:v)
    {
        if(x.length()==1)continue;
        if(x.length()==3)
        {
            mp[x.substr(1)]--;
            continue;
        }
        reverse(All(x));
        if(mp[x]>0)flag=true;
        reverse(All(x));
        mp[x]--;
    }

    for(string x:v)
    {
        if(x.length()>1)mp[x]++;
    }
    string s;
    for(string x:v)
    {
        if(x.length()==1)continue;
        if(x.length()==2)
        {
            mp[x]--;
            continue;
        }
        s=x;
        reverse(All(s));
        if(mp[s]>0)flag=true;
        s=x.substr(0,2);
        reverse(All(s));
        if(mp[s]>0)flag=true;
        mp[x]--;
    }

    if(flag)cout<<"YES\n";
    else cout<<"NO\n";
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