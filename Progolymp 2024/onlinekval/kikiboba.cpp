#include "bits/stdc++.h" 
         
using namespace std;

#define faster ios_base::sync_with_stdio(0); cin.tie(0);

#define all(x) (x).begin(), (x).end()

void solve() {
    string s; cin >> s;
    int b = count(all(s), 'b');
    int k = count(all(s), 'k');
    if (b > k) cout << "boba";
    else if (k > b) cout << "kiki";
    else if (b > 0 && b == k) cout << "boki";
    else cout << "none";
}

int main() {
        faster
	solve();
}

