#include <string>
#include "../Graph/Graph.h"
#include "../DijkstraAlgorithm/DijkstraAlgorithm.h"


int main() {
    std::vector<std::vector<int>> matrix;
    std::string filename = R"(../Boards/Board3.txt)";
    ReadFileToVector(&matrix, filename);

    std::vector<std::vector<int>> dst = shortest(matrix);
    std::vector<std::pair<int, int>> zerosPos = GetZerosPos(matrix);
    int start_x = zerosPos[0].first;
    int start_y = zerosPos[0].second;
    int end_x = zerosPos[1].first;
    int end_y = zerosPos[1].second;

    printRoute(dst, matrix, start_x, start_y, end_x, end_y);
    return 0;
}