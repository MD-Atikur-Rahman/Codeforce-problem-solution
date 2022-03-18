#include<bits/stdc++.h>
using namespace std;
#define nl '\n';

int main()
{
    int tt; cin>>tt;
    while(tt--)
    {
        int a,b; cin>>a>>b;
        int val,ans=b-a;

        if((a|b)==b)ans=1;

        for(int i=28; i>=0; i--)
        {
            if(b&(1<<i))
            {
                if(a&(1<<i))
                {
                    a-=(1<<i);
                }
                else
                {
                    val=(1<<i)-a+1;
                    ans=min(ans,val);
                }
                b-=(1<<i);
            }
            else
            {
                if(a&(1<<i))
                {
                    val=a-b+1;
                    ans=min(ans,val);
                    break;
                }
            }
        }
        cout<<ans<<nl;
    }
    return 0;
}