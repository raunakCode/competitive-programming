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
    int r, c, red = 0, blue = 0, green = 0, rg = 0, bg = 0, rb = 0;
    cin >> r >> c;
    ll cnt = 0;
    string up, right, down, left;
    cin >> up >> right >> down >> left;
    for(int i = 0; i < r; i++) {
        string s = "";
        s += left[i];
        if(left[i] != right[i]) {
            s += right[i];
            if (s.find('B') != string::npos && s.find('G') != string::npos) bg++;
            else if (s.find('B') != string::npos && s.find('R') != string::npos) rb++;
            else rg++;
        }
        else if(left[i] == right[i]) {
            if (s.find('B') != string::npos) blue++;
            else if (s.find('G') != string::npos) green++;
            else red++;
        }
    }
    for(int j = 0; j < c; j++) {
        string k = "";
        k += up[j];
        if(up[j] != down[j]) {
            k += down[j];
            if (k.find('B') != string::npos && k.find('G') != string::npos) cnt += red + rb + rg;
            else if (k.find('B') != string::npos && k.find('R') != string::npos) cnt += green + bg + rg;
            else if (k.find('R') !=  string::npos && k.find('G') != string::npos) cnt += blue + bg + rb;
        }
        else if (up[j] == down[j]) {
            if (k == "R") cnt += bg;
            else if (k == "G") cnt += rb;
            else if (k == "B") cnt += rg;
        }
    }

    cout << cnt;

    return 0;
}