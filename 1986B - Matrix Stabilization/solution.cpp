#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void manipulate(int n, int m, vector<vector<int>>& arr) {
  bool stabilized = false;
  while (!stabilized) {
    stabilized = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int max_val = 0;
        if (i > 0) max_val = max(max_val, arr[i - 1][j]);
        if (i < n - 1) max_val = max(max_val, arr[i + 1][j]);
        if (j > 0) max_val = max(max_val, arr[i][j - 1]);
        if (j < m - 1) max_val = max(max_val, arr[i][j + 1]);
        if (arr[i][j] > max_val) {
          arr[i][j] = max_val;
          stabilized = false;
          break;
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int c = 0; c < t; c++) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> arr[i][j];
      }
    }

    manipulate(n, m, arr);

    // Print the stabilized matrix
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << arr[i][j] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
