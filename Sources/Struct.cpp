#include "Struct.h"

using namespace std;

int Islandcounts(std::vector<std::vector<int>> &grid)
{
    int rows = grid.size();
    if (rows == 0)
        return 0;
    int cols = grid[0].size();
    if (cols == 0)
        return 0;
    int res = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 1)
            {
                infect(grid, i, j, rows, cols);
                res++;
            }
        }
    }
    return res;
}

void infect(std::vector<std::vector<int>> &grid, int i, int j, int rows, int columns)
{
    if (i < 0 || i >= rows || j < 0 || j >= columns || grid[i][j] != 1)
        return;
    grid[i][j] = 2;
    infect(grid, i + 1, j, rows, columns);
    infect(grid, i - 1, j, rows, columns);
    infect(grid, i, j + 1, rows, columns);
    infect(grid, i, j - 1, rows, columns);
}
