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
        if (!fin.is_open()) {
            throw std::runtime_error("Error: Failed to open CSV file '" + csvFile + "'. "
                                     "Please check the file path and ensure the file exists.");
        }
        std::string line;
        outVexNum = 0;
        int lineNum = 0;
        while (std::getline(fin, line)) {
            ++lineNum;
            std::vector<T> row;
            std::stringstream ss(line);
            std::string val;
            while (std::getline(ss, val, ',')) {
                try {
                    row.push_back(static_cast<T>(std::stod(val)));
                } catch (const std::exception&) {
                    throw std::runtime_error("Error: Invalid numeric value '" + val + "' "
                                             "at line " + std::to_string(lineNum) + " in file '" + csvFile + "'. "
                                             "Please check the CSV format.");
                }
            }
            matrix.push_back(row);
            ++outVexNum;
        }
        return matrix;
    }
}

#endif // DATA_STRUCTURE_SP26_GRAPHDETAIL_H
