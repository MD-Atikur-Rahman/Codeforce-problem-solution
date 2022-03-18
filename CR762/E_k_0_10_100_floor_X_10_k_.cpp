#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
#define All(x) (x).begin(),(x).end()
#define mp make_pair
#define nl "\n"
typedef pair<int,int>ii;
typedef vector<int>vi;
typedef vector<ii>vii;
typedef vector<vi>vvi;
typedef vector<long long>vl;
typedef vector <vl>vvl;
typedef tree<pair<int,int>, null_type,less<pair<int, int>>, rb_tree_tag,
    tree_order_statistics_node_update> indexed_multiset;
template<class T> void print(T& a) { for(auto x:a)cout<<x<<" "; cout<<"\n";}
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T>
int SIZE(T(&t))
{
    return t.size();
}
template <typename T, size_t N>
int SIZE(T (&t)[N])
{
    return N;
}
string to_string(char t)
{
    return "'" + string({t}) + "'";
}
string to_string(bool t)
{
    return t ? "true" : "false";
}
string to_string(const string &t, int x1 = 0, int x2 = 1e9)
{
    string ret = "";
    for (int i = min(x1, SIZE(t)), _i = min(x2, SIZE(t) - 1); i <= _i; ++i)
    {
        ret += t[i];
    }
    return '"' + ret + '"';
}
string to_string(const char *t)
{
    string ret(t);
    return to_string(ret);
}
template <size_t N>
string to_string(const bitset<N> &t, int x1 = 0, int x2 = 1e9)
{
    string ret = "";
    for (int i = min(x1, SIZE(t)); i <= min(x2, SIZE(t) - 1); ++i)
    {
        ret += t[i] + '0';
    }
    return to_string(ret);
}
template <typename T, typename... Coords>
string to_string(const T(&t), int x1 = 0, int x2 = 1e9, Coords... C);
template <typename T, typename S>
string to_string(const pair<T, S> &t)
{
    return "(" + to_string(t.first) + ", " + to_string(t.second) + ")";
}
template <typename T, typename... Coords>
string to_string(const T(&t), int x1, int x2, Coords... C)
{
    string ret = "[";
    x1 = min(x1, SIZE(t));
    auto e = begin(t);
    advance(e, x1);
    for (int i = x1, _i = min(x2, SIZE(t) - 1); i <= _i; ++i)
    {
        ret += to_string(*e, C...) + (i != _i ? ", " : "");
        e = next(e);
    }
    return ret + "]";
}
template <int Index, typename... Ts>
struct print_tuple
{
    string operator()(const tuple<Ts...> &t)
    {
        string ret = print_tuple<Index - 1, Ts...>{}(t);
        ret += (Index ? ", " : "");
        return ret + to_string(get<Index>(t));
    }
};
template <typename... Ts>
struct print_tuple<0, Ts...>
{
    string operator()(const tuple<Ts...> &t)
    {
        return to_string(get<0>(t));
    }
};
template <typename... Ts>
string to_string(const tuple<Ts...> &t)
{
    const auto Size = tuple_size<tuple<Ts...>>::value;
    return print_tuple<Size - 1, Ts...>{}(t);
}
void dbgr() { ; }
template <typename Heads, typename... Tails>
void dbgr(Heads H, Tails... T)
{
    cerr << to_string(H) << " | ";
    dbgr(T...);
}
void dbgs() { ; }
template <typename Heads, typename... Tails>
void dbgs(Heads H, Tails... T)
{
    cerr << H << " ";
    dbgs(T...);
}
//#undef LOCAL
#ifdef LOCAL
#define dbgv(...) cerr << to_string(__VA_ARGS__) << endl;
#define dbga(...)                         \
    cerr << "[" << #__VA_ARGS__ << "]: "; \
    dbgv(__VA_ARGS__);
#define dbgr(...)      \
    dbgr(__VA_ARGS__); \
    cerr << endl;
#define dbg(...)                          \
    cerr << "[" << #__VA_ARGS__ << "]: "; \
    dbgr(__VA_ARGS__);
#else
#define dbgv(...) 42
#define dbga(...) 42
#define dbgr(...) 42
#define dbg(...) 42
#endif
const long double PI = 3.14159265358979;
const long double EPS=1e-9;


int main()
{
    FastIO

    int a; cin>>a;
    vi v(5);
    for(int x:v)x=a;

    dbg(v);

    return 0;
}