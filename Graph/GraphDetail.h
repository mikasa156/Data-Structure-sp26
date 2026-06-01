#ifndef DATA_STRUCTURE_SP26_GRAPHDETAIL_H
#define DATA_STRUCTURE_SP26_GRAPHDETAIL_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

namespace graph_detail {
    template<typename T>
    std::vector<std::vector<T>> loadMatrixFromCsv(const std::string& csvFile, int& outVexNum) {
        std::vector<std::vector<T>> matrix;
        std::ifstream fin(csvFile);
        std::string line;
        outVexNum = 0;
        while (std::getline(fin, line)) {
            std::vector<T> row;
            std::stringstream ss(line);
            std::string val;
            while (std::getline(ss, val, ',')) {
                row.push_back(static_cast<T>(std::stod(val)));
            }
            matrix.push_back(row);
            ++outVexNum;
        }
        return matrix;
    }
}

#endif // DATA_STRUCTURE_SP26_GRAPHDETAIL_H
