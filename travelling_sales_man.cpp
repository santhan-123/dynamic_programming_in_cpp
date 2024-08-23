#include<bits/stdc++.h>
using namespace std;

const int V = 4; // Define the maximum number of nodes (adjust as needed)

// Function to find the minimum weight Hamiltonian Cycle using backtracking
void tspBacktrack(int graph[][V], vector<bool>& v, int currPos,
                  int n, int count, int cost, int& ans) {
    if (count == n && graph[currPos][0]) {
        ans = min(ans, cost + graph[currPos][0]);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!v[i] && graph[currPos][i]) {
            v[i] = true;
            tspBacktrack(graph, v, i, n, count + 1,
                         cost + graph[currPos][i], ans);
            v[i] = false;
        }
    }
}

int tsp(int graph[][V], int n) {
    vector<bool> v(n, false);
    v[0] = true;
    int ans = INT_MAX;
    tspBacktrack(graph, v, 0, n, 1, 0, ans);
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int graph[n][V];
    cout << "Enter the adjacency matrix of size " << n << "x" << V << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int minCycle = tsp(graph, n);

    cout << "Minimum weight Hamiltonian Cycle: " << minCycle << endl;

    return 0;
}
