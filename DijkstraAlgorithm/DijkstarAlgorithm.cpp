#include "DijkstraAlgorithm.h"

bool operator<(const cell& a, const cell& b)
{
    if (a.distance == b.distance)
    {
        if (a.x != b.x)
            return (a.x < b.x);
        else
            return (a.y < b.y);
    }
    return (a.distance < b.distance);
}

// Utility method to check whether a point is
// inside the grid or not
bool isInsideGrid(int i, int j, int width, int height)
{
    return (i >= 0 && i < height && j >= 0 && j < width);
}

std::vector<std::vector<int>> shortest(std::vector<std::vector<int>> &matrix)
{
    int height = matrix.size();
    int width = matrix[0].size();
    //int dis[height][width];

    std::vector<std::vector<int>> dis;
    std::vector<std::pair<int, int>> zerosPos = GetZerosPos(matrix);
    int start_x = zerosPos[0].first;
    int start_y = zerosPos[0].second;

    // initializing distance array by INT_MAX
    for (int i = 0; i < height; i++){
        std::vector<int> v;
        for (int j = 0; j < width; j++) {
            v.push_back(INT_MAX);
        }
        dis.push_back(v);
    }

    // direction arrays for simplification of getting
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    // bo ma metodę find
    std::set<cell> st;

    // Początkowa pozycja
    st.insert(cell(start_x, start_y, 0));
    // Dystans punktu startowego
    dis[start_x][start_y] = 0;

    while (!st.empty())
    {
        // get the cell with minimum distance and delete
        // it from the set
        cell k = *st.begin();
        st.erase(st.begin());

        // looping through all neighbours
        for (int i = 0; i < 4; i++)
        {
            int x = k.x + dx[i];
            int y = k.y + dy[i];

            if (!isInsideGrid(x, y, width, height))
                continue;

            if (dis[x][y] > dis[k.x][k.y] + matrix[x][y])
            {
                // Jeżeli wierzchołek jest już w secie
                if (dis[x][y] != INT_MAX)
                    st.erase(st.find(cell(x, y, dis[x][y])));

                dis[x][y] = dis[k.x][k.y] + matrix[x][y];
                st.insert(cell(x, y, dis[x][y]));
            }
        }
    }

    // distance map
    /*for (int i = 0; i < height; i++, cout << endl) {
        for (int j = 0; j < width; j++) {
            cout << dis[i][j] << " ";
        }
    }*/
    return dis;
}

void printRoute(std::vector<std::vector<int>> &distMatrix, std::vector<std::vector<int>> &grid,  int &start_x, int &start_y, int &end_x, int &end_y) {
    std::vector<std::pair<int, int>> route;
    std::pair<int, int> nextPos;
    int i = end_x;
    int j = end_y;
    route.push_back({i, j});
    while(!(i == start_x && j == start_y)){
        nextPos = findMinVertex(distMatrix, i, j);
        i = nextPos.first;
        j = nextPos.second;
        route.push_back({i, j});
    }
    reverse(route.begin(), route.end());
    int k = 0;
    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[0].size(); ++j){
            std::pair<int, int> p = {i, j};
            if(find(route.begin(), route.end(), p) != route.end())
                std::cout << grid[i][j];
            else
                std::cout << ' ';
        }
        std::cout << std::endl;
    }
}

std::pair<int, int> findMinVertex(std::vector<std::vector<int>> &distMatrix, int &pos_x, int &pos_y) {
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    std::pair<int, int> pos;
    int minVertex = INT_MAX;
    for (int i = 0; i < 4; i++) {
        int x = pos_x + dx[i];
        int y = pos_y + dy[i];
        if (isInsideGrid(x, y, distMatrix[0].size(), distMatrix.size())){
            if (distMatrix[x][y] < minVertex) {
                minVertex = distMatrix[x][y];
                pos = {x, y};
            }
        }
    }
    return pos;
}
