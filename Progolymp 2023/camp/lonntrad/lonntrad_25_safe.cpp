#include "bits/stdc++.h" 
         
using namespace std;

#define el "\n"
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
         
typedef vector<int> vi;
         
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define trav(a, x) for (auto &a : x)
         
void solve() {
    int n; cin >> n;
    vi a(n);
    REP(i, 1, n) a[i-1] = i;
    auto query = [&](int a, int b, int c) {
        cout << "? " << a << " " << b << " " << c << endl;
        char answer; cin >> answer;
        return answer;
    };
    auto comp = [&](int a, int b) {
        char c = query(a, b, 1);
        return (c == 'A');
    };
    sort(all(a), comp);
    
    vi par(n + 1, -1);
    per(i, 1, n) {
        int C = a[i];
        int bst = 1;
        per(j, 0, i) {
            int b = a[j];
            if (b == bst) continue;
            if (query(bst, b, C) == 'B') bst = b; 
        }
        par[C] = bst;
    }
    cout << "!" << el;
    REP(i, 1, n) {
        if (par[i] != -1) cout << i << " " << par[i] << el;
    }
    cout.flush();
}

int main() {
    faster
    int test = 1; // cin >> test;
    REP(tc, 1, test) {
        solve();
    }
}


