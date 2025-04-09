#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
bool check(vector<long long> arr, long long tar, long long k) {
    long long n = arr.size();
    long long times = tar / n; 
    long long rem = tar % n; 
    long long cost = 0; 
    for(int i = n-1; i >= n-rem; i--) {
        if(arr[i] - 1 < times + 1) {
            cost += (times + 1 - arr[i] + 1); 
        }
    }
    for(int i = n-rem-1; i >= 0; --i) {
        if(arr[i] - 1 < times) {
            cost += times - arr[i] + 1; 
        }
    }
    return cost <= k;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        long long k;
        cin >> n; 
        cin >> k; 
        vector<long long> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        if( check( arr , 1 , k ) ){
            long long l = 1;
            long long r = LLONG_MAX; 
            long long rs = 0;
            while (l < r) {
                long long mid = l + (r - l+1) / 2;
                if (check(arr, mid, k)) {
                    l = mid ;
                } else {
                    r = mid -1 ;
                }
            }
            cout << l+1 << '\n';
        }else {
            cout << 1 << endl ; 
        }
        
    }
    return 0;
}