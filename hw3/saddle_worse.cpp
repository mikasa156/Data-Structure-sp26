#include <vector>
#include <utility>
#include <iostream>

/** check if value is minimum in a row */
bool isMin(double val, std::vector<double>& vec) {
    for (const auto& item : vec) {
        if (val > item) return false;
    }
    return true;
}


// vec is not empty
auto findSaddle(std::vector<std::vector<double>> mat) {
    int n = mat.size(); // rows of matrix
    int m = mat[0].size(); // columns of matrix

    std::vector<std::pair<int, int>> saddle_points; // answers

    for (int j = 0; j < m; j++) {
        double j_max = mat[0][j]; // the max value in column j
        std::vector<int> Sj; // sets of i such that mat[i][j] is maximum in column j
        for (int i = 0; i < n; i++) { 
            /*
            * if current value is bigger than j_max, we update j_max
            * and add row i into 'Sj'
            */
            if (mat[i][j] > j_max) {
                j_max = mat[i][j];
                Sj.clear();
                Sj.push_back(i);
            }
            else if (mat[i][j] == j_max) { 
                Sj.push_back(i);
            }
        }
        for (const auto& r : Sj) {
            if (isMin(mat[r][j], mat[r])) {
                std::pair<int, int> p{r + 1, j + 1};
                saddle_points.push_back(p);
            }
        }
    }
    return saddle_points;
}

void printPoints(std::vector<std::pair<int, int>> points) {
    for (const auto& item : points) {
        std::cout << "(" << item.first << ", " << item.second << ") ";
    }
}


int main(){
    std::vector<std::vector<double>> mat {
        {0, 0, 0, 0, 0},
        {4, 4, 5, 6, 7},
        {1, 3, 3, 3, 4},
        {0, 0, 0, 0, 0}
    };

    std::vector<std::vector<double>> mat2 {
        {1, 2, 3, 4, 5},
        {1, 1, 2, 2, 2},
    };

    printPoints(findSaddle(mat));
    std::cout << std::endl;
    printPoints(findSaddle(mat2));
    return 0;
}

