#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void ReadFileToVector(std::vector<std::vector<int>> *vector, std::string const& filename);
std::vector<std::pair<int, int>> GetZerosPos(std::vector<std::vector<int>> const& vector);