#include "MGraph.h"
#include "ALGraph.h"
#include <vector>

int main() {
    std::vector<std::vector<int>> matrix = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}
    };

    DirectedMGraph<int> dm(3, matrix);
    dm.print();

    UndirectedMGraph<int> um(3, matrix);
    um.print();

    DirectedALGraph<int> dal(3, matrix);
    dal.print();

    UndirectedALGraph<int> ual(3, matrix);
    ual.print();

    return 0;
}
