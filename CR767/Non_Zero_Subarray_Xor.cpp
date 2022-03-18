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

vector<int> pre({ 0 });
void fun(int x, int y)
{
    bool ex[(1 << x)];
 
    ex[0] = 1;
 
    for (int i = 1; i < (1 << x); i++) {
 
        if (ex[i ^ y])
            continue;
 
        pre.push_back(i);
        ex[i] = 1;
    }
 
    if (pre.size() == 1) {
        cout << "-1";
        return;
    }
 
}

void Engine()
{
    int n; 
    cin>>n;

    for (int i = 1; i <= n; i++)
        cout << (pre[i] ^ pre[i - 1]) << " ";
    
    cout<<nl;
}

int main()
{
    FastIO
    int x=20;
    fun(x,0);
    int tt=1;
    cin>>tt;
    while(tt--)
    {
        Engine();
    }
    return 0;
}  