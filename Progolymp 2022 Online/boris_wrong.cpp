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
    int times[n][4];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> times[i][j];
        }
    }
    int timeLimit = abs(times[0][0] - times[1][0]);
    int timeTaken = abs(times[0][2] - times[1][2]) + abs(times[0][3] - times[1][3]);
    if (timeTaken > timeLimit) {
        cout << max(times[0][1],times[1][1]);
    }
    else if (timeTaken <= timeLimit) {
        cout << times[0][1] + times[1][1];
    }

    return 0;
}