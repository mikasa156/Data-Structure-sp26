#include "../Graph/MGraph.h"
#include "../Graph/ALGraph.h"

int main() {
    std::vector<std::vector<int>> mat = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0},
    };

    UndirectedALGraph<int> al_graph(4, mat);
    al_graph.print();
    UndirectedMGraph<int> m_graph = al_graph.toMatrix();
    m_graph.print();

    return 0;

}
