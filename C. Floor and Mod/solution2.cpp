#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

void solve(){
	ll x, y;
	cin >> x >> y;
	ll rs = 0;
	for(ll i = 1; i*i <= x; i++){
	    rs += max(  min(y,x/i-1) - i , 0LL );
	}
	cout << rs << endl;
	return;
}

int main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}