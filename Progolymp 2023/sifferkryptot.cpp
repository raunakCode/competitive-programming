#include "bits/stdc++.h"
 
#define el "\n"
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sq(x) (x)*(x)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)
 
using namespace std;

vector<int> l;

set<vector<int>> u;

void create(vector<int> made, string toUse) {
    if (toUse.size() == 0) {
        u.insert(made);
        return;
    }
    vector<int> p;
    for(int i=0; i < made.size(); i++) {
        p.pb(made[i]);
    }
    string k = "";
    if (toUse.size() == 1) {
        string r = "";
        r += toUse[0];
        p.pb(l[stoi(r)]);
        create(p, k);
    }
    else if (toUse.size() > 1) {
        string a = "";
        string b = "";
        for(int i = 1; i < toUse.size(); i++) {
            if (i == 1) {
                a+=toUse[i];
                continue;
            }
            a += toUse[i];
            b += toUse[i];
        }
        string r = "";
        r += toUse[0];
        p.pb(l[stoi(r)]);
        create(p, a);
        r += toUse[1];
        p.pop_back();
        p.pb(l[stoi(r)]);
        create(p, b);
    }
}

void solve() {
    for(int i = 0; i <= 30; i++) {
        l.pb(i);
    }
    string s;
    cin >> s;
    vector<int> w;
    create(w, s);
    set<vector<int>> ans;
    int cnt = 0;
    trav(x, u) {
        bool flag = 1;
        for(int i = 0; i < x.size(); i++) {
            if (x[i] < 1 || x[i] > 29) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cnt++;
            ans.insert(x);
        }
    }
    set<vector<int>> ans2;  
    trav(x, ans) {
        string v = "";
        for(int i= 0; i < x.size(); i++) {
            string l  = to_string(x[i]);
            v += l;
        }
        if (v == s) ans2.insert(x);
    }
    cout << ans2.size() << el;
}
 
int main() {
    faster
    //cout << fixed << setprecision(10);
    int tt = 1;
    while(tt--) {
        solve();
    }
}