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

struct btt
{
    btt* left=nullptr;
    btt* right=nullptr;
};


void Engine(int tc)
{
    int mx,mn,x,l,r; cin>>l>>r;
    int n=r-l+1;

    btt *root=new btt();
    btt *temp, *temp1;

    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        temp=root;
        for(int j=16; j>=0; j--)
        {
            if((1<<j)&a[i])
            {
                if(temp->right==nullptr)temp->right=new btt();
                temp=temp->right;
            }

            else
            {
                if(temp->left==nullptr)temp->left=new btt();
                temp=temp->left;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        x=a[i]^l;
        mn=0;
        mx=0;

        temp1=temp=root;

        for(int j=16; j>=0; j--)
        {
            if(x&(1<<j))
            {
                if(temp->right==nullptr)
                {
                    mn+=(1<<j);
                    temp=temp->left;
                }
                else temp=temp->right;

                if(temp1->left==nullptr)temp1=temp1->right;
                else 
                {
                    mx+=(1<<j);
                    temp1=temp1->left;
                }
            }
            else
            {
                if(temp->left==nullptr)
                {
                    mn+=(1<<j);
                    temp=temp->right;
                }
                else temp=temp->left;

                if(temp1->right==nullptr) temp1=temp1->left;
                else 
                {
                    mx+=(1<<j);
                    temp1=temp1->right;
                }
            }
        }
        if(mn==l && mx==r)
        {
            cout<<x<<nl;
            return;
        }
    }
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