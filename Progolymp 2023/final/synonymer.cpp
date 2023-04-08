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
#define trav(a, x) for (auto &a : x)

void solve() {
    int n, m;
    cin >> n;
    map<string, vector<string>> dict;
    map<string, bool> exist;
    for(int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        exist[a] = 1;
        dict[a].pb(b);
        dict[b].pb(a);
    }
    vector<string> words;

    cin >> m;
    for(int i = 0; i < m; i++) {
        string s; cin >> s;
        words.pb(s);
    }
    for(int i = 0; i < m; i++) {
        string change = "...";
        if (exist[words[i]] == 0) continue;
        bool found = 0;
        trav(x, dict[words[i]]) {
            trav(y, dict[x]) {
                if (y != words[i]) {
                    change = y;
                    found = 1;
                    break;
                }
            }
            if (found == 1) break;
        }
        if (found) {
            words[i] = change;
        }
    }
    for(int i = 0; i < words.size()-1; i++) {
        cout << words[i] << " ";
    }
    cout << words[words.size()-1];
} 

int main() {
    faster
    solve();
}