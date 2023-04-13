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

int KMP(const string &s, const string &m)
{
    if (s.length() < 1 || m.length() < 1 || s.length() < m.length())
        return -1;
    size_t *nextArr = new size_t[m.length()];
    getNextArray(nextArr, m);
    size_t s_index = 0, m_index = 0;
    while (s_index < s.length() && m_index < m.length())
    {
        if (s[s_index] == m[m_index])
        {
            s_index++;
            m_index++;
        }
        else if (m_index == 0) // nextArr[m_index]==-1
            s_index++;
        else
            m_index = nextArr[m_index];
    }
    delete[] nextArr;
    return m_index == m.length() ? s_index - m_index : -1;
}

void getNextArray(size_t *nextArr, const string &m)
{
    if (m.length() == 1)
    {
        nextArr[0] = -1;
        return;
    }
    nextArr[0] = -1;
    nextArr[1] = 0;
    size_t index = 2;
    size_t cn = 0;
    while (index < m.length())
    {
        if (m[index - 1] == m[cn])
            nextArr[index++] = ++cn;
        else if (cn > 0)
            cn = nextArr[cn];
        else
            nextArr[index++] = 0;
    }
    return;
}
