#include <iostream>
#include <vector>
#include <climits>
#include <utility>

using namespace std;

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    int grid[100][100];

    int globalMax = INT_MIN;

    // Input matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] > globalMax)
            {
                globalMax = grid[i][j];
            }
        }
    }

    // Starting position
    int row, col;
    cin >> row >> col;

    vector<int> path;
    vector< pair<int, int> > indexPath;

    int pathSum = 0;

    // 8 directions
    int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

    while (true)
    {
        path.push_back(grid[row][col]);
        indexPath.push_back(make_pair(row, col));

        pathSum = pathSum + grid[row][col];

        int bestValue = grid[row][col];
        int bestRow = row;
        int bestCol = col;

        // Check 8 neighbours
        for (int k = 0; k < 8; k++)
        {
            int newRow = row + dx[k];
            int newCol = col + dy[k];

            if (newRow >= 0 && newRow < rows &&
                newCol >= 0 && newCol < cols)
            {
                if (grid[newRow][newCol] > bestValue)
                {
                    bestValue = grid[newRow][newCol];
                    bestRow = newRow;
                    bestCol = newCol;
                }
            }
        }

        // Stop if no better neighbour exists
        if (bestValue <= grid[row][col])
        {
            break;
        }

        row = bestRow;
        col = bestCol;
    }

    cout << "Path: ";

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }

    cout << endl;

    cout << "Index Path: ";

    for (int i = 0; i < indexPath.size(); i++)
    {
        cout << "{" << indexPath[i].first
             << "," << indexPath[i].second << "} ";
    }

    cout << endl;

    cout << "Path Sum = " << pathSum << endl;
    cout << "Global Maximum = " << globalMax << endl;

    if (grid[row][col] == globalMax)
    {
        cout << "Global Maximum Reached" << endl;
    }
    else
    {
        cout << "Local Maximum = " << grid[row][col] << endl;
    }

    return 0;
}
