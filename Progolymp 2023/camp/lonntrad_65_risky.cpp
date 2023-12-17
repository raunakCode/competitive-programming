#include "bits/stdc++.h" 

using namespace std;
         
#define el "\n"
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define mp make_pair
#define F first
#define S second
         
typedef pair<int, int> pii;
typedef vector<int> vi;
         
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)
         
int n; 
int queryCnt = 0;
set<pii> edges;

char query(int a, int b, int c) {
	queryCnt++;
	assert(queryCnt <= 20000);
	cout << "? " << a << " " << b << " " << c << endl;
	char answer; cin >> answer;
	return answer;
}

void rec(vi nodes) {
	if (sz(nodes) == 1) return;
	else if (sz(nodes) == 2) {
		edges.insert(mp(min(nodes[0], nodes[1]), max(nodes[0], nodes[1])));
		return;
	}

	random_device rd;
	mt19937 g(rd());
	shuffle(all(nodes), g); // this allows it to get 65p, 10% of the time :P
	vi temp = {nodes[0], nodes[1], nodes[2]};

	rep(i, 0, sz(nodes)) {
		int cur = nodes[i];
		if (count(all(temp), cur) > 0) continue;
		if (query(cur, temp[0], temp[1]) == 'A' && query(cur, temp[0], temp[2]) == 'A') {
			temp[0] = cur;
		}
	}
	int median = temp[0];
	int bst = temp[1];
	rep(i, 0, sz(nodes)) {
		if (nodes[i] == bst || nodes[i] == median) continue;
		if (query(nodes[i], bst, median) == 'A') bst = nodes[i];
	}
	edges.insert(mp(min(median, bst), max(median, bst)));

	vi a, b;
	rep(i, 0, sz(nodes)) {
		if (query(median, bst, nodes[i]) == 'A') a.pb(nodes[i]);
		else b.pb(nodes[i]);
	}
	rec(a);
	rec(b);
}

void solve() {
	cin >> n;
	vi a(n);
	rep(i, 0, n) a[i] = i + 1;
	rec(a);
	assert(sz(edges) == n-1);
	cout << "!" << el;
	trav(edge, edges) {
		cout << edge.F << " " << edge.S << el;
	}
	cout.flush();
}

int main() {
   	faster
	solve();
}


