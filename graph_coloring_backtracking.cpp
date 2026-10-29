#include <iostream>
using namespace std;

int n, m, numberOfColors;
int graph[101][101] = {0};
char colors[20], nodeColor[101];

bool solve(int node)
{
    if (node > n)
        return true;

    for (int c = 0; c < numberOfColors; c++)
    {
        bool canUse = true;

        for (int i = 1; i <= n; i++)
        {
            if (graph[node][i] == 1 &&
                    (i == node || nodeColor[i] == colors[c]))
            {
                canUse = false;
                break;
            }
        }

        if (canUse)
        {
            nodeColor[node] = colors[c];

            if (solve(node + 1))
                return true;

            nodeColor[node] = 'N';
        }
    }

    return false;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cin >> numberOfColors;

    for (int i = 0; i < numberOfColors; i++)
        cin >> colors[i];

    for (int i = 1; i <= n; i++)
        nodeColor[i] = 'N';

    if (solve(1) == false)
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    int usedColors = 0;

    for (int c = 0; c < numberOfColors; c++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (nodeColor[i] == colors[c])
            {
                usedColors++;
                break;
            }
        }
    }

    cout << "Colors Used -> " << usedColors << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << "Color of Node " << i
             << " -> " << nodeColor[i] << endl;
    }

    return 0;
}
