#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_set>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;
    
    while (tc--) {
        int n;
        cin >> n;
        
        vector<string> grid(n); 
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }

        vector<bool> rows(n);
        vector<bool> cols(n);
        bool fl = true;
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == '0') {
                    cols[j] = true;
                    rows[i] = true;
                } else {
                    if(rows[i] && cols[j]) {
                        fl = false;
                        break;
                    }else if( rows[i] ){
                        rows[i] = false ; 
                    }else if( cols[j] ){
                        cols[j] = false ; 
                    }
                }
            }
        }
        
        cout << (fl ? "YES" : "NO") << endl;
    }
    
    return 0;
}
