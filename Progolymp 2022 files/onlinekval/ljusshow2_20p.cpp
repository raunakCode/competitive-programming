#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define popb pop_back
#define mp make_pair
#define sq(a) (a)*(a)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
const ll template_size_array = 1e6 + 16318;

using namespace std;

int main()
{
    faster
    int t; cin >> t;
    int n, m; cin >> n >> m;
    if (m == 1) {
        int colours[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> colours[i];
        }
        cout << "R" << endl;
        for(int j = 1; j <= n; j++) {
            if (colours[j] == 0) cout << "G";
            else cout << "B";
        }
        cout << endl << "R" << endl;
        for(int k = 0; k < n; k++) {
            cout << "G";
        }
    }
    else if (n == m) {
        string s = "";
        for(int i = 0; i < n; i++) {
            s += "G";
        }
        for(int o = 0; o < 3; o++) {
            cout << s << endl;
        }
        cout << s;
    }

    return 0;
}