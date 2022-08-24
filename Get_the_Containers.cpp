#include<bits/stdc++.h>

using namespace std;


#define MAX 992337203685477580
#define MIN -99233720368547750

typedef long long ll;
typedef vector<int > vi;
typedef vector<long long> vll;

ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    cin>>t;
    
    for(ll test = 1;test<=t;test++){

        ll n,m,mx=MIN,sum=0;
        cin>>n>>m;

        vll a(n,0);
        for(ll i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
            mx = max(mx,a[i]);
        }

        ll low = mx;
        ll high = sum;

        ll ans=0;

        while(low<=high){

            ll mid = (low+high)/2;

            ll c=0,x=0;
            for(ll i=0;i<n;i++){
                if(x+a[i]<=mid){
                    x+=a[i];
                }
                else{
                    c++;
                    x=a[i];
                }
            }
            if(x<=mid){
                c++;
            }
            if(c>m){
                low = mid+1;

            }
            else if(c<=m){
                high = mid-1;
                ans = mid;
            }
            
        }
        cout<<"Case "<<test<<": "<<ans<<'\n';
    } 
}
