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

void Engine()
{
    int n; cin>>n;
    VI pos,pos1;
    int i=3;

    pos.push_back(1);
    pos.push_back(2);

    int mx,res[16];
    bool flag;
    while(i<=n)
    {
        pos.push_back(i);
        if(i<n)pos.push_back(i+1);
        else
        {
            if(pos[0]!=1 && pos[1]!=1)pos.push_back(1);
            else if(pos[0]!=2 && pos[1]!=2)pos.push_back(2);
            else pos.push_back(3);
        }

        mx=-1;
        for(int j=7; j<16; j++)
        {
            if(__builtin_popcount(j)==3)
            {
                cout<<"?";
                for(int k=0; k<4; k++)
                {
                    if((1<<k)&j)cout<<" "<<pos[k];
                }
                cout<<nl;
                cout.flush();
                cin>>res[j];
                mx=max(mx,res[j]);
            }
        }
        flag=false;
        // cout<<mx<<nl;
        for(int j=7; j<16; j++)
        {
            if(__builtin_popcount(j)!=3 || res[j]!=mx)continue;
            for(int k=j+1; k<16; k++)
            {
                if(__builtin_popcount(k)!=3 || res[k]!=mx)continue;
                
                flag=true;

                for(int l=0; l<4; l++)
                {
                    if(((1<<l)&j) && ((1<<l)&k))pos1.push_back(pos[l]);
                }

                break;
            }
            if(flag)break;
        }

        pos.clear();
        pos=pos1;
        pos1.clear();

        i+=2;
    }

    cout<<"! "<<pos[0]<<" "<<pos[1]<<nl;
    cout.flush();
}

int main()
{
    // FastIO
    int tt=1;
    cin>>tt;
    for(int tc=1; tc<=tt; tc++)
    {
        //cout<<"Case "<<tc<<": ";
        Engine();
    }
    return 0;
}  