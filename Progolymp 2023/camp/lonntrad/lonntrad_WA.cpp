#include "bits/stdc++.h"

using namespace std;

#define el "\n"
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define sq(x) (x)*(x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define trav(a, x) for (auto &a : x)

int root;

bool cmp(int a, int b) {
    cout << a << " " << b << " " << root << el;
    cout << flush;
    char res; cin >> res;
    if (res == 'A') {
        if (a > b) return true;
        return false;
    }
    else if (res == 'B') {
        if (b > a) return true;
        return false;
    }
}

void solve() {
    int n; cin >> n;
    root = 1;
    vector<int> v;
    REP(i, 1, n) v.pb(i);
    sort(all(v), cmp);
    root = v[v.size()-1];
    vector<int> k;
    REP(i, 1, n) {
        k.pb(i);
    }
    sort(all(k), cmp);
    cout << "!" << el;
    rep(i, 0, k.size()-1) {
        cout << k[i] << " " << k[i+1] << el;
    }
    cout << flush;
}

int main() {
    faster
    solve();
}
