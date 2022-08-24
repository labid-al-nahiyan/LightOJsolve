#include<bits/stdc++.h>

using namespace std;


#define MAX 922337203685477580
#define MIN -92233720368547750

typedef long long ll;
typedef vector<int > vi;
typedef vector<long long> vll;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    cin>>t;
    
    for(ll l = 1;l<=t;l++){
        ll n,k,mx = MIN, sum = 0;
        cin>>n>>k;
        k++;
        vll a(n+1,0);
        for(ll i=0;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
            mx = max(mx,a[i]);
        }
        
        
        ll low = max(mx,ll(ceil(double(sum)/k)));
        ll high = sum, ans;

        while(low<high){
            ll mid = (low +high)/2;

            ll step = 0,x=0;
            for(ll i=0;i<=n;i++){
                if(x+a[i]<=mid){
                    x+=a[i];
                }
                else{
                    step++;
                    x=a[i];
                }
            }

            if(x<mid){
                step++;

            }


            if(step>k){
                low = mid+1;

            }
            else if(step<=k){
                high = mid;
                ans = mid;
            }
            

        }

        vll b;
        ll x =0,s=0;
        
        
        for(ll i=0;i<=n;i++){
                if(x+a[i]<=ans){
                    x+=a[i];
                }
                else{
                    s++;
                    b.push_back(x);
                    x=a[i];
                }

                if(n-i+1 == k-s){
                    b.push_back(x);
                    for(ll j=i+1;j<=n;j++){
                        b.push_back(a[j]);
                    }
                    break;
                }
        }
        
        
        cout<<"Case "<<l<<": "<<ans<<'\n';

        for(auto i:b){
            cout<<i<<"\n";
        }
       
        

    }    
}
