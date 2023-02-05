#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "../Graph/Graph.h"


struct cell
{
    int x;
    int y;
    int distance;
    cell(int x, int y, int distance){
        this->x = x;
        this->y = y;
        this->distance = distance;
    }
};

bool operator<(cell const& a, cell const&b);
bool isInsideGrid(int i, int j, int width, int height);
std::vector<std::vector<int>> shortest(std::vector<std::vector<int>> &matrix);
void printRoute(std::vector<std::vector<int>> &distMatrix, std::vector<std::vector<int>> &grid, int &start_x, int &start_y, int &end_x, int &end_y);
std::pair<int, int> findMinVertex(std::vector<std::vector<int>> &distMatrix, int &pos_x, int &pos_y);