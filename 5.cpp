#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::min(); // Для хранения минимального значения

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> graph(n + 1); // Граф в виде списка смежности
    for (int i = 0; i < m; ++i) {
        int A, B;
        long long d;
        cin >> A >> B >> d;
        graph[A].emplace_back(B, d); // Добавляем ребро A -> B с длиной d
    }

    int S;
    cin >> S;

    vector<long long> dist(n + 1, INF); // Вектор для хранения максимальных расстояний
    dist[S] = 0; // Расстояние до стартовой вершины равно 0

    // Топологическая сортировка
    vector<int> indegree(n + 1, 0);
    for (int u = 1; u <= n; ++u) {
        for (auto& edge : graph[u]) {
            indegree[edge.first]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        for (auto& edge : graph[u]) {
            int v = edge.first;
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Обновление максимальных расстояний
    for (int u : topo_order) {
        if (dist[u] != INF) { // Если до u можно добраться
            for (auto& edge : graph[u]) {
                int v = edge.first;
                long long weight = edge.second;
                dist[v] = max(dist[v], dist[u] + weight);
            }
        }
    }

    // Вывод результата
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INF) {
            cout << -1 << " ";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
