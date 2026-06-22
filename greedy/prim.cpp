#include <iostream>
#include <vector>
#include <map>
#include <queue>

using edge = std::pair<char, int>;

struct comp {
    bool operator() (const edge& a, const edge& b) {
        return a.second > b.second; // Min-heap
    }
};

void prim(std::map<char, std::vector<edge>>& n, char ini) {
    std::priority_queue<edge, std::vector<edge>, comp> pq;
    std::map<char, bool> visited;

    visited[ini] = true;
    for (auto& i : n[ini]) {
        pq.push(i);
    }

    while (!pq.empty()) {
        edge top = pq.top();
        pq.pop();

        char dest = top.first;
        int weight = top.second;

        if (visited[dest]) continue;

        visited[dest] = true;
        std::cout << ini << " -> " << dest << "  weight = " << weight << "\n";

        ini = dest;

        for (auto& i : n[ini]) {
            if (!visited[i.first]) {
                pq.push(i);
            }
        }
    }
}

int main() {
    std::map<char, std::vector<edge>> n = {
        {'a', { {'b', 2}, {'c', 3} } }, 
        {'b', { {'c', 1}, {'d', 6} } }, 
        {'c', { {'d', 4}, {'e', 2} } }, 
        {'d', { {'e', 5} } },
        {'e', { } }
    };

    prim(n, 'a');
    return 0;
}