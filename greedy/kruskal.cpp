#include <iostream>
#include <vector>
#include <map>
#include <queue>

using edge = std::pair<char, int>;

struct comp {
    bool operator() (const edge& a, const edge& b) {
        return a.second > b.second;
    }
};

void kruskal(std::map<char, std::vector<edge>>& n) {
    std::priority_queue<edge, std::vector<edge>, comp> pq;
    std::map<char, bool> visited;

    for (auto& i : n) {
        for (auto& j : i.second) {
            pq.push(j);
        }
    }

    std::vector<char> res;
    int totalWeight = 0;

    while (!pq.empty()) {
        edge top = pq.top();
        pq.pop();

        char dest = top.first;
        int weight = top.second;

        if (visited[dest]) continue;

        visited[dest] = true;
        res.push_back(dest);
        totalWeight += weight;

        std::cout << "  node = " << dest << "  weight = " << weight << "\n";
    }

    std::cout << "Total weight: " << totalWeight << "\n";
    for (auto& i : res) std::cout << i << "  ";
    std::cout << "\n";
}

int main() {
    std::map<char, std::vector<edge>> n = {
        {'a', { {'b', 2}, {'c', 3} } },
        {'b', { {'c', 1}, {'d', 6} } },
        {'c', { {'d', 4}, {'e', 2} } },
        {'d', { {'e', 5} } },
        {'e', { } }
    };

    kruskal(n);
    return 0;
}