#include<bits/stdc++.h>
using namespace std;
#define nl '\n';

template <typename T, class F = function<T(const T &, const T &)>>
class SparseTable
{
public:
    int n;
    vector<vector<T>> mat;
    F func;

    SparseTable(const vector<T> &a, const F &f) : func(f)
    {
        n = static_cast<int>(a.size());
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++)
        {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++)
            {
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T get(int from, int to) const
    {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};
// vector <ll> b(n-1) ;
// SparseTable<long long> st(b, [&](long long i, long long j) { return __gcd(i, j); });
// st.get(i, j)

int main()
{
    int n; cin>>n;
    vector<long long> v(n);
    for(long long &elm:v)cin>>elm;

    SparseTable<long long> st(v,[&](long long i, long long j){return __gcd(i,j);});

    int l,r,m,in=0;
    bool flag;
    int ans[n];
    memset(ans,0,sizeof(ans));

    while(in<n)
    {
        l=in;
        r=n-1;
        flag=false;

        while(l<=r)
        {
            m=l+r>>1;

            if(st.get(in,m)==m-in+1)
            {
                flag=true;
                break;
            }
            else if(st.get(in,m)>m-in+1)l=m+1;
            else r=m-1;
        }

        if(flag)
        {
            ans[m]=1;
            in=m+1;
        }
        else in++;
    }

    for(int i=0; i<n; i++)
    {
        if(i>0)ans[i]+=ans[i-1];
        cout<<ans[i]<<" ";
    }
    cout<<nl;

    return 0;
}