#include <bits/stdc++.h>
#define endl "\n"
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sq(x) (x)*(x)
#define pb push_back
#define popb pop_back
#define mp make_pair
typedef long long ll;
const ll template_size_array = 1e6 + 16318;

using namespace std;

int main()
{
    faster
    //cout << fixed << setprecision(0);

    int n; cin >> n;
    char column[10] = {'A','B','C','D','E','F','G','H','I','J'};
    char grid[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    string ordning = "";
    string colours = "";
    bool yes = false;

    while(yes == false) {
       bool k = false;
       bool y = false;
       char colour = '_';
       string row = "", col = "";
       bool e = false;
       for(int i = 0; i < n; i++) {
           if (e == true) {break;}
           e = false;
           char first = 'Z';
           for(int j = 0; j < n; j++) {
               if (grid[i][j] == 'S' || grid[i][j] == 'V') {
                   first = grid[i][j];
                   break;
               }
           }
           if (first != 'Z' && first != '_') {
               int cnt = 0;
               for(int j = 0; j < n; j++) {
                   if (grid[i][j] == first || grid[i][j] == '_') {
                       cnt++;
                   }
                   if (cnt == n) {
                       colour = first;
                       k = true;
                       row = to_string(i+1);
                       for(int r = 0; r < n; r++) {
                           grid[i][r] = '_';
                       }
                       cnt = 0;
                       e = true;
                       break;
                   }
               }
           }

       }
       if (k == false || colour == '_') {
           e = false;
           for(int j = 0; j < n; j++) {
               if (e == true) {break;}
               e = false;
               char first = 'Z';
               for(int i = 0; i < n; i++) {
                   if (grid[i][j] == 'S' || grid[i][j] == 'V') {
                       first = grid[i][j];
                       break;
                   }
               }
               if (first != 'Z' && first != '_') {
                 int cnt = 0;
                   for(int i = 0; i < n; i++) {
                       if (grid[i][j] == first || grid[i][j] == '_') {
                           cnt++;
                       }
                       if (cnt == n) {
                           colour = first;
                           y = true;
                           col += column[j];
                           for(int r = 0; r < n; r++) {
                               grid[r][j] = '_';
                           }
                           cnt = 0;
                           e = true;
                           break;
                       }
                   }
               }
           }
       }
       if (colour == '_') break;
       if (row == "" && col != "") {
           ordning += col;
           colours += colour;
       }
       else if (row != "" && col == "") {
           ordning += row;
           colours += colour;
       }
    }
    reverse(ordning.begin(), ordning.end());
    reverse(colours.begin(), colours.end());
    cout << ordning << endl;
    cout << colours << endl;
}
