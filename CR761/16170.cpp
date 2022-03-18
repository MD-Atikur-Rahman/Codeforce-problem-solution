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
const long double PI = 3.14159265358979;
const long double EPS=1e-9;


int main()
{
    FastIO

    int tt; cin>>tt;
    while(tt--)
    {
        string s,t; cin>>s>>t;
        sort(All(s));

        bool b[26]={};

        for(char x:s)b[x-'a']=true;
        bool flag=true;
        for(int i=0; i<3; i++)
        {
            if(b[i]==false)flag=false;
        }

        if(t=="abc" && flag)
        {
            int in2=0,in1=s.length();
            for(int i=0; i<s.length(); i++)
            {
                if(s[i]=='b')
                {
                    in1=i; break;
                }
            }
            for(int i=s.length()-1; i>=0; i--)
            {
                if(s[i]=='c')
                {
                    in2=i;
                    break;
                }
            }
            while(in1<in2)
            {
                swap(s[in1],s[in2]);
                in1++;
                in2--;
            }
        }

        cout<<s<<nl;
    }

    return 0;
}