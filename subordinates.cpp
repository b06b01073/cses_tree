#include<bits/stdc++.h>
using namespace std;

vector<int> ans;
vector<vector<int>> children;

int dfs(int u) {
    for(auto& child: children[u]) {
        ans[u] += dfs(child);
    }

    return ans[u] + 1;
}
 
int main() {
    int n;
    cin >> n;

    ans.resize(n + 1);
    children.resize(n + 1);

    for(int i = 0; i < n - 1; i++) {
        int a;
        cin >> a;

        children[a].push_back(i + 2);
    }

    dfs(1);

    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}