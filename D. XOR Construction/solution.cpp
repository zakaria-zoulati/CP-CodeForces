#include <iostream>
#include <vector>
using namespace std;

struct Trie {
    Trie* child[2] = {nullptr, nullptr};
    bool end = false;
    
    void insert(int n) {
        Trie* node = this;
        for (int i = 20; i >= 0; --i) {
            int bit = (n >> i) & 1;
            if (!node->child[bit]) node->child[bit] = new Trie();
            node = node->child[bit];
        }
        node->end = true;
    }
    
    bool check(int i, int n) {
        Trie* node = this;
        int curr = 0;
        for (int b = 20; b >= 0; --b) {
            int ibit = (i >> b) & 1;
            if (node->child[1 - ibit]) {
                curr = curr + ((1 - ibit) << b);  
                node = node->child[1 - ibit];
            } else {
                curr = curr + (ibit << b);       
                node = node->child[ibit];
            }
            if ((curr ^ i) >= n && node->end) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
    }
    
    Trie* trie = new Trie();
    int path = 0;
    vector<int> paths(n);
    paths[n - 1] = 0;
    
    for (int i = n - 2; i >= 0; --i) {
        path ^= a[i];
        paths[i] = path;
        trie->insert(path);
    }
    
    for (int i = 0; i < n; ++i) {
        if (trie->check(i, n)) {
            vector<int> b(n);
            b[n - 1] = i;
            for (int j = n - 2; j >= 0; --j) {
                b[j] = b[j + 1] ^ a[j];
            }
            for (int j = 0; j < n; ++j) {
                cout << b[j] << " ";
            }
            cout << '\n';
            break;
        }
    }
    
    return 0;
}