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
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define trav(a, x) for (auto &a : x)

int n, q;

void solve() {
    cin >> n >> q;
    vector<int> st;
    st.pb(1);
    int fixes = 0;
    string answer = "";
    rep(i, 0, n) answer += '(';
    rep(i, 1, n) {
        if (st.size() == 0) {
            st.pb(i+1);
            continue;
        }
        cout << "? " << st.back() << " " << i+1 << endl;
        int response; cin >> response;
        if (response == 1) {
            st.pop_back();
            answer[i] = ')';
            fixes++;
        }
        else {
            st.pb(i+1);
        }
    }
    rep(i, 0, n/2-fixes) {
        answer[st[i]-1] = ')';
    }
    cout << "! " << answer << endl;
}

int main() {
    faster
    solve();
}