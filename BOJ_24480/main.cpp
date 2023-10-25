#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n, m, r;
map<int, vi> adj;

vb visit;
vi ans;
int now;

void dfs(int x) {
	ans[x] = now;
	visit[x] = true;
	++now;

	for (const auto& y : adj[x]) {
		if (visit[y]) {
			continue;
		}

		dfs(y);
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> m >> r;
	for (auto i = 1; i <= n; ++i) {
		adj[i] = vi{};
	}

	while (0 < (m--)) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (auto&& [k, v] : adj) {
		sort(v.begin(), v.end(), greater<>());
	}

	visit = vb(n + 1, false);
	ans = vi(n + 1, 0);
	now = 1;
	dfs(r);

	for (auto i = 1; i <= n; ++i) {
		cout << ans[i] << '\n';
	}

	return 0;
}