#include <bits/stdc++.h>
using namespace std;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define ll long long
#define ull unsigned long long
#define PB push_back
#define All(x) (x).begin(), (x).end()
#define MP make_pair
#define nl "\n"
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef vector<VL> VVl;
template <class T>
void print(T &a)
{
    for (auto x : a)
        cout << x << " ";
    cout << "\n";
}
const long double PI = 3.14159265358979;
const long double EPS = 1e-9;

void Engine()
{
    int n, len, k;
    cin >> n >> len >> k;
    int pos[n + 1];
    for (int i = 0; i < n; i++)
        cin >> pos[i];
    int tm[n];
    for (int &x : tm)
        cin >> x;
    pos[n] = len;

    int mn, dp[n][k + 1];
    dp[0][0] = pos[1] * tm[0];
    int ans=INT32_MAX;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= min(k, i); j++)
        {
            dp[i][j] = INT32_MAX;
            if(i==j)dp[i][j]=pos[i+1]*tm[0];
            for (int q = 0; q <= j; q++)
            {
                mn = pos[i + 1] - pos[i - q];
                mn *= tm[i - q];
                if (j - q > i - q - 1)
                    continue;
                if (i - q > 0)
                    mn += dp[i - q - 1][j - q];
                dp[i][j] = min(dp[i][j], mn);
            }
        }
    }
    for(int i=0; i<=k; i++)
    {
        ans=min(ans,dp[n-1][i]);
    }
    cout<<ans<<nl;
}

int main()
{
    FastIO int tt = 1;
    // cin>>tt;
    while (tt--)
    {
        Engine();
    }
    return 0;
}