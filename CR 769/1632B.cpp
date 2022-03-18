#include<bits/stdc++.h>
using namespace std;
#define nl '\n';

int main()
{
    int tt; cin>>tt;
    while(tt--)
    {
        int n,p=1; cin>>n;
        while(p<n)p<<=1;
        p>>=1;

        for(int i=n-1; i>=p; i--)cout<<i<<" ";
        cout<<0<<" ";
        for(int i=1; i<p; i++)cout<<i<<" ";
        cout<<nl;
    }
    return 0;
}