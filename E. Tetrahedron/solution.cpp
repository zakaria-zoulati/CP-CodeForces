#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>

using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;

vector<vector<ll>> multMat(vector<vector<ll>> A, vector<vector<ll>> B) {
    vector<vector<ll>> R(4, vector<ll>(4, 0));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                R[i][j] = (R[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return R;
}

vector<vector<ll>> matE(vector<vector<ll>> mat, int n) {
    if (n == 1) {
        return mat;
    }
    vector<vector<ll>> half = matE(mat, n / 2);
    vector<vector<ll>> R = multMat(half, half);
    if (n % 2 == 1) {
        R = multMat(R, mat);
    }
    return R;
}

int main() {
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<ll>> base(4, vector<ll>(4, 0));
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (i == j) continue;
                base[i][j] = 1;
            }
        }

        vector<vector<ll>> R = matE(base, n);
        cout << R[0][0] << endl;
    }
    return 0;
}
