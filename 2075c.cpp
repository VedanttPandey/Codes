
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n , k;
    cin >> k >> n;
 
    vll a(n);
 
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];
        a[i] = min(k-1 , a[i]);
    }
 
 
    ll ans = 0ll;
 
    sort(a.begin() , a.end());
 
    vll suf(n+1 , 0);
    for(int i = 0 ; i < n ; i ++) suf[i] = a[i]; 
    for(int i = n-1 ; i >= 0 ; i --) suf[i] += suf[i+1];
 
    for(int i = 0 ; i < n ; i ++)
    {
        ll v = a[i];
        ll c = k - v;
 
        int j = lower_bound(a.begin() , a.end() , c) - a.begin();
        ll sum = suf[j];
        ll cnt = n - j;
 
        if(v >= c)
        {
            sum -= v;
            cnt--;
        }
        ans += sum - cnt*(c-1);
    }
 
 
    cout << ans << endl;
    
}
int main() {
	int t;cin>>t;
    while(t--){solve();}
}
