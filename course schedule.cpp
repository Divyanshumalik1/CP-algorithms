#include <iostream>
#include <algorithm>
#include <vector>
#include "math.h"
#include <iomanip>
#include <queue>
#include <set>
#include <map>
#include <queue>
#include <string>
typedef long long ll;
using namespace std;

void DFS(int source, unordered_map<int, vector<int>>& Adjlist, set<int>& Visited, vector<int>& Res) {
    // If the node is not visited
    if (Visited.find(source) == Visited.end()) {
        Visited.insert(source);

        for (auto& neighbour : Adjlist[source]) {
            DFS(neighbour, Adjlist, Visited, Res);
        }

        // Add to result in postorder
        Res.push_back(source);
    }
}

vector<int> solve() {
    unordered_map<int, vector<int>> Adjlist;
    set<int> Visited;
    vector<int> Res;

    int n, m;
    cin >> n >> m;

    // Input edges
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        Adjlist[a].push_back(b);
    }

    // Ensure all nodes are in Adjlist (even if they have no outgoing edges)
    for (int i = 1; i <= n; i++) {
        if (Adjlist.find(i) == Adjlist.end()) {
            Adjlist[i] = {}; // Add node with no neighbors
        }
    }

    // Perform DFS for all nodes
    for (auto& it : Adjlist) {
        if (Visited.find(it.first) == Visited.end()) {
            DFS(it.first, Adjlist, Visited, Res);
        }
    }

    // Reverse the result for correct topological order
    std::reverse(Res.begin(), Res.end());

    return Res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int test = 1;
    // Uncomment if the problem has multiple test cases
    // cin >> test;

    while (test--) {
        vector<int> result = solve();

        // Output the result
        for (int node : result) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}
