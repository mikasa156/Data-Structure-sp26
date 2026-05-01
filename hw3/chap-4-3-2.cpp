#include <iostream>
#include <vector>
#include <utility>

auto rowMin(const std::vector<std::vector<double>>& mat) {
    std::vector<double> mins;
    for (const auto& vec : mat) {
        double min = vec[0];
        for (const auto& x : vec) {
            if (x < min) {
                min = x;
            }
        }
        mins.push_back(min);
    }
    return mins;
}

auto columnMax(const std::vector<std::vector<double>>& mat) {
    std::vector<double> maxs;
    for (int j = 0; j < mat[0].size(); j++) {
        double max = mat[0][j];
        for (const auto& vec : mat) {
            if (vec[j] > max) {
                max = vec[j];
            }
        }
        maxs.push_back(max);
    }
    return maxs;
}


auto findSaddle(const std::vector<std::vector<double>>& mat) {

    std::vector<std::pair<int, int>> saddle_points;

    auto mins = rowMin(mat);
    auto maxs = columnMax(mat);

    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            if (mat[i][j] == mins[i] && mat[i][j] == maxs[j]) {
                std::pair<int, int> p {i + 1, j + 1};
                saddle_points.push_back(p);
            }
        }
    }

    return saddle_points;
}

void printPoints(std::vector<std::pair<int, int>> points) {
    for (const auto& point : points) {
        std::cout << "(" << point.first << ", " << point.second << ") ";
    }
    std::cout << std::endl;
}


int main() {
    std::vector<std::vector<double>> mat {
        {1, 1}, 
        {1, 1}
    };

    std::vector<std::vector<double>> mat2 {
        {1, 2, 2, 2, 2},
        {0, 2, 0, 0, 0},
        {1, 2, 3, 4, 5},
        {1, 1, 2, 2, 2}
    };

    printPoints(findSaddle(mat));
    printPoints(findSaddle(mat2));

    return 0;
}
