#include "Graph.h"

void ReadFileToVector(std::vector<std::vector<int>> *vector, const std::string &filename) {
    std::string line;
    std::fstream myFile;
    myFile.open(filename);
    while(std::getline(myFile, line)){
        std::vector<int> row;
        for(char c : line){
            if(!isdigit(c))
                throw std::logic_error("Garbage in input file");
            row.push_back( c - '0' );
        }
        vector->push_back(row);
    }
}

std::vector<std::pair<int, int>> GetZerosPos(const std::vector<std::vector<int>> &vector) {
    std::vector<std::pair<int, int>> pos;
    for(int i = 0; i < vector.size(); ++i){
        for(int j = 0; j < vector[0].size(); ++j){
            if(vector[i][j] == 0)
                pos.push_back({i, j});
        }
    }
    return pos;
}
