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

struct FenwickTreeOneBasedIndexing {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTreeOneBasedIndexing(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTreeOneBasedIndexing(vector<int> a)
        : FenwickTreeOneBasedIndexing(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int idx) {
        int ret = 0;
        for (idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};

void Engine(int tc)
{
    int n,q; cin>>n>>q;
    FenwickTreeOneBasedIndexing bitr(n),bitc(n);
    int t,x1,y1,x2,y2;
    int cntr[n+1],cntc[n+1];
    memset(cntr,0,sizeof cntr);
    memset(cntc,0,sizeof cntc);
    while(q--)
    {
        cin>>t;
        if(t==1)
        {
            cin>>x1>>y1;
            cntr[x1]++;
            cntc[y1]++;
            if(cntr[x1]==1)bitr.add(x1,1);
            if(cntc[y1]==1)bitc.add(y1,1);
        }
        else if(t==2)
        {
            cin>>x1>>y1;
            cntr[x1]--;
            cntc[y1]--;
            if(cntr[x1]==0)bitr.add(x1,-1);
            if(cntc[y1]==0)bitc.add(y1,-1);
        }
        else
        {
            cin>>x1>>y1>>x2>>y2;
            if(bitr.sum(x1,x2)==x2-x1+1 || bitc.sum(y1,y2)==y2-y1+1)cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
}

int main()
{
    FastIO
    int tt=1;
    //cin>>tt;
    for(int tc=1; tc<=tt; tc++)
    {
        Engine(tc);
    }
    return 0;
}  