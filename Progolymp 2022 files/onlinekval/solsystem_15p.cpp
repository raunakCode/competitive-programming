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
    int n; cin >> n;
    int tulls[n][2];
    for(int i = 0; i < n; i++) {
        cin >> tulls[i][0];
        cin >> tulls[i][1];
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        int ans = 0;
        int a, b; cin >> a >> b;
        if (a < b) {
          for(int j = 0; j < n; j++) {
            if (a >= tulls[j][0] && a <= tulls[j][1] && tulls[j][1] < b) {
                ans++;
                }
            if (a < tulls[j][0] && tulls[j][0] <= b && tulls[j][1] >= b) {
                ans++;
            }
          }
        }
        else if (b < a) {
            for(int j = 0; j < n; j++) {
            // if a in tull and b not in tull
            if (b < tulls[j][0] && a >= tulls[j][0] && tulls[j][1] >= a) {
                ans++;
                }
            // if b in tull and a not in tull
            if (a > tulls[j][1] && tulls[j][1] >= b && tulls[j][0] <= b) {
                ans++;
            }
          }
        }

        cout << ans << endl;
    }

    return 0;
}
