#include <iostream>
#include <vector>
#include <climits> // Para INT_MAX

void permutacional(int idx, std::vector<std::vector<int>>& tareas, int costoActual, 
                int& costoMinimo, std::vector<bool>& visited, std::vector<int>& temp, std::vector<int>& res) {
    
    if (costoActual >= costoMinimo) 
        return;
    if (idx >= tareas.size()) {
        if (costoActual < costoMinimo) {
            costoMinimo = costoActual;
            res = temp;
        }
        return;
    }


    for (int i = 0; i < tareas.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            temp.push_back(i); 
            permutacional(idx + 1, tareas, costoActual + tareas[idx][i], costoMinimo, visited, temp, res);   
            temp.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    std::vector<std::vector<int>> tareas = {
        {94, 1, 54, 68},
        {74, 10, 88, 82},
        {62, 88, 8, 76},
        {11, 74, 81, 21}
    };

    int n = tareas.size();
    int costoMinimo = INT_MAX;
    std::vector<bool> visited(n, false);
    std::vector<int> res, temp;

    permutacional(0, tareas, 0, costoMinimo, visited, temp, res);

    std::cout << "Costo minimo: " << costoMinimo << std::endl;
    for (int i = 0; i < res.size(); i++) {
        std::cout << "Trabajador " << i << " -> Tarea " << res[i] 
                  << " (Costo: " << tareas[i][res[i]] << ")" << std::endl;
    }

    return 0;
}