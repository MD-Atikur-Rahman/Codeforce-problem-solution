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

const int SZ=5e5+5;
int p[SZ];

void Engine()
{

    for(int i=0; i<SZ; i++)p[i]=i;

    int tp,x,y,q; cin>>q;

    VI ans;
    vector<pair<int,PII>> chng;

    while(q--)
    {
        cin>>tp>>x;

        if(tp==1)ans.push_back(x);
        else
        {
            cin>>y;
            chng.push_back({ans.size(),{x,y}});
        }
    }

    while(chng.size() && chng.back().first==ans.size())
    {
        p[chng.back().second.first]=p[chng.back().second.second];
        chng.pop_back();    
    }
    
    for(int i=ans.size()-1; i>=0; i--)
    {
        ans[i]=p[ans[i]];
        while(chng.size() && chng.back().first==i)
        {
            p[chng.back().second.first]=p[chng.back().second.second];
            chng.pop_back();    
        }        
    }

    print(ans);
}

int main()
{
   // FastIO
    int tt=1;
    //cin>>tt;
    while(tt--)
    {
        Engine();
    }
    return 0;
}  