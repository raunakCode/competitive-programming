#include "bits/stdc++.h" 
         
using namespace std;
         
#define el "\n"
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
         
typedef vector<int> vi;
typedef vector<vi> vvi;
         
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define trav(a, x) for (auto &a : x)
         

const int inf = 2e9;

int n, queryCnt = 0;
vi par;
vvi graph;

char query(int a, int b, int c) {
	queryCnt++;
	assert(queryCnt <= 20000);
	cout << "? " << a << " " << b << " " << c << endl;
	char answer; cin >> answer;
	return answer;
}

int makeSubtrees(int node, int p, vi &subtree, set<int> &allowed) {
	int sum = 1; // have to include yourself
	trav(child, graph[node]) {
		if (allowed.find(child) == allowed.end()) continue;
		if (child == p) continue;
		sum += makeSubtrees(child, node, subtree, allowed);
	}
	subtree[node] = sum;
	return sum;
}

void makeNewAllowed(int node, int p, set<int> &allowed, set<int> &newAllowed) {
	newAllowed.insert(node);
	trav(child, graph[node]) {
		if (allowed.find(child) == allowed.end()) continue;
		if (child == p) continue;
		makeNewAllowed(child, node, allowed, newAllowed);
	}
}

int rec(int node, set<int> allowed) {
	int root = *allowed.begin();
	if (sz(allowed) == 1) return root;

	// make subtrees
	vi subtree(n+1);
	int _ = makeSubtrees(root, root, subtree, allowed);

	// find best edge
	int mn = inf;
	int mid = 0;
	trav(x, allowed) {
		int goodness = abs(subtree[x] - sz(allowed)/2);
		if (goodness < mn) {
			mn = goodness;
			mid = x;
		}
	}

	// now we have found middle node (and edge to parent) with subtrees
	// get arbitrary neighbour (y) of middle node to act as other half representative
	int x = mid, y;
	trav(child, graph[mid]) {
		if (allowed.find(child) != allowed.end()) {
			y = child;
			break;
		}
	}
	// filter nodes into 2 halves
	set<int> newAllowed;
	if (query(x, y, node) == 'A') {
		// x is closer to node
		makeNewAllowed(x, y, allowed, newAllowed);
	}
	else makeNewAllowed(y, x, allowed, newAllowed);

	// recurse on good half
	return rec(node, newAllowed);
}

void solve() {
	cin >> n;
	graph.resize(n+1);
	par.resize(n + 1, -1);

	auto cmp = [&](int a, int b) {
        	char c = query(a, b, 1);
        	return (c == 'A');
    	};

	vi a(n);
	rep(i, 0, n) a[i] = i + 1;
	stable_sort(all(a), cmp);

	set<int> inGraph;
	par[a[1]] = 1;
	graph[1].pb(a[1]);
	graph[a[1]].pb(1);
	inGraph.insert(1);
	inGraph.insert(a[1]);

	rep(i, 2, n) {
		set<int> allowed;
		trav(x, inGraph) allowed.insert(x);
		par[a[i]] = rec(a[i], allowed);
		graph[a[i]].pb(par[a[i]]);
		graph[par[a[i]]].pb(a[i]);
		inGraph.insert(a[i]);
	}
	
	cout << "!" << el;
	REP(i, 1, n) {
		if (par[i] != -1) cout << i << " " << par[i] << el;
	}
	cout.flush();
}

int main() {
   	faster
	solve();
}


