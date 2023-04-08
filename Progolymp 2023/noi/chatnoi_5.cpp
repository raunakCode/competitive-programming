#include "bits/stdc++.h"

using namespace std;

#define el "\n"
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define trav(a, x) for (auto &a : x)

int n, k;
vector<string> words;
map<vector<string>, int> r;

void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        words.pb(s);
    }
    for(int i = 0; i+k < n; i++) {
        vector<string> s;
        for(int j = i; j <= i+k; j++) {
            s.pb(words[j]);
        }
        r[s]++;
    }
    int q; cin >> q;
    while(q--) {
        vector<string> ans;   
        int m; cin >> m;
        vector<string> seq;
        for(int i = 0; i < k; i++) {
            string w; cin >> w;
            seq.pb(w);
        }
        int mx = 0;
        for(int i = 0; i < n; i++) {
            vector<string> l = seq;
            l.pb(words[i]);
            if (r[l] >= mx) {
                mx = r[l];
                ans = l;
            }
        }
        cout << ans.back() << el;
    }
} 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
}