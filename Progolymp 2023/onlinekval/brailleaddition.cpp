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

char grid[3][1000];

char check( int p) {
    if (grid[0][p] == '*' && grid[0][p+1] == '.' &&  grid[1][p] == '.' &&  grid[1][p+1] == '.' &&  grid[2][p] == '.' &&  grid[2][p+1] == '.') {
        return '1';
    }
    else if (grid[0][p] == '*' && grid[0][p+1] == '.' &&  grid[1][p] == '*' &&  grid[1][p+1] == '.' &&  grid[2][p] == '.' &&  grid[2][p+1] == '.') {
        return '2';
    }
    else if (grid[0][p] == '*' && grid[0][p+1] == '*' &&  grid[1][p] == '.' &&  grid[1][p+1] == '.' &&  grid[2][p] == '.' &&  grid[2][p+1] == '.') {
        return '3';
    }
    else if (grid[0][p] == '*' && grid[0][p+1] == '*' &&  grid[1][p] == '.' &&  grid[1][p+1] == '*' &&  grid[2][p] == '.' &&  grid[2][p+1] == '.') {
        return '4';
    }
    else if (grid[0][p] == '*' && grid[0][p+1] == '.' &&  grid[1][p] == '.' &&  grid[1][p+1] == '*' &&  grid[2][p] == '.' &&  grid[2][p+1] == '.') {
        return '5';
    }
    else if (grid[0][p] == '*' && grid[0][p+1] == '*' &&  grid[1][p] == '*' &&  grid[1][p+1] == '.' &&  grid[2][p] == '.' &&  grid[2][p+1] == '.') {
        return '6';
    }
    else if (grid[0][p] == '*' && grid[0][p+1] == '*' &&  grid[1][p] == '*' &&  grid[1][p+1] == '*' &&  grid[2][p] == '.' &&  grid[2][p+1] == '.') {
        return '7';
    }
    else if (grid[0][p] == '*' && grid[0][p+1] == '.' &&  grid[1][p] == '*' &&  grid[1][p+1] == '*' &&  grid[2][p] == '.' &&  grid[2][p+1] == '.') {
        return '8';
    }
    else if (grid[0][p] == '.' && grid[0][p+1] == '*' &&  grid[1][p] == '*' &&  grid[1][p+1] == '.' &&  grid[2][p] == '.' &&  grid[2][p+1] == '.') {
        return '9';
    }
    else if (grid[0][p] == '.' && grid[0][p+1] == '*' &&  grid[1][p] == '*' &&  grid[1][p+1] == '*' &&  grid[2][p] == '.' &&  grid[2][p+1] == '.') {
        return '0';
    }
}

void solve() {
    int n; cin >> n;
    rep(i, 0, 3) {
        rep(j, 0, 2*n) {
            cin >> grid[i][j];
        }
    }
    string one = "";
    for(int i = 0; i < n; i++) {
        one += check(i*2);
    }
    int o = stoi(one);
    int m; cin >> m;
    rep(i, 0, 3) {
        rep(j, 0, 2*m) {
            cin >> grid[i][j];
        }
    }
    string two = "";
    for(int i = 0; i < m; i++) {
        two += check(i*2);
    }
    int t = stoi(two);
    int a = o+t;
    string q = "", w = "", e = "";
    string ans = to_string(a);
    for(int i = 0; i < ans.size(); i++) {
        if (ans[i] == '1') {
            q += "*. ";
            w += ".. ";
            e += ".. ";
        }
        else if (ans[i] == '2') {
            q += "*. ";
            w += "*. ";
            e += ".. ";
        }
        else if (ans[i] == '3') {
            q += "** ";
            w += ".. ";
            e += ".. ";
        }
        else if (ans[i] == '4') {
            q += "** ";
            w += ".* ";
            e += ".. ";
        }
        else if (ans[i] == '5') {
            q += "*. ";
            w += ".* ";
            e += ".. ";
        }
        else if (ans[i] == '6') {
            q += "** ";
            w += "*. ";
            e += ".. ";
        }
        else if (ans[i] == '7') {
            q += "** ";
            w += "** ";
            e += ".. ";
        }
        else if (ans[i] == '8') {
            q += "*. ";
            w += "** ";
            e += ".. ";
        }
        else if (ans[i] == '9') {
            q += ".* ";
            w += "*. ";
            e += ".. ";
        }
        else if (ans[i] == '0') {
            q += ".* ";
            w += "** ";
            e += ".. ";
        }
    }
    cout << q << el;
    cout << w << el;
    cout << e;
}
 
int main() {
    faster
    int tt = 1;
    while(tt--) {
        solve();
    }
}