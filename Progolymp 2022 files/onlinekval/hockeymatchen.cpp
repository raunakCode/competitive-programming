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
    int saves1, scores1, shots1; cin >> saves1 >> scores1 >> shots1;
    int saves2, scores2, shots2; cin >> saves2 >> scores2 >> shots2;
    if (shots1 == 0) {
        scores1 = 0;
        saves2 = 0;
    }
    if (shots2 == 0) {
        scores2 = 0;
        saves1 = 0;
    }
    if (saves1 == -1) {
        if (scores2 != -1 && shots2 != -1) {
            saves1 = shots2 - scores2;
        }
    }
    if (saves2 == -1) {
        if (scores1 != -1 && shots1 != -1) {
            saves2 = shots1 - scores1;
        }
    }
    if (scores1 == -1) {
        if (saves2 != -1 && shots1 != -1) {
            scores1 = shots1 - saves2;
        }
    }
    if (scores2 == -1) {
        if (saves1 != -1 && shots2 != -1) {
            scores2 = shots2 - saves1;
        }
    }
    if (shots1 == -1) {
        if (scores1 != -1 && saves2 != -1) {
            shots1 = scores1 + saves2;
        }
    }
    if (shots2 == -1) {
        if (scores2 != -1 && saves1 != -1) {
            shots2 = scores2 + saves1;
        }
    }
    cout << saves1 << " " << scores1 << " " << shots1 << endl;
    cout << saves2 << " " << scores2 << " " << shots2 << endl;
    return 0;
}