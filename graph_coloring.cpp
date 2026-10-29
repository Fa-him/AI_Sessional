#include <iostream>
using namespace std;

int main()
{
    int n, m;

    // Number of nodes and edges
    cin >> n >> m;

    int graph[100][100] = {0};

    // Input edges
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int numberOfColors;
    cin >> numberOfColors;

    char colors[20];

    // Input available colors
    for (int i = 0; i < numberOfColors; i++)
    {
        cin >> colors[i];
    }

    char nodeColor[100];

    // Initially no node has a color
    for (int i = 1; i <= n; i++)
    {
        nodeColor[i] = 'N';
    }

    // Color every node
    for (int node = 1; node <= n; node++)
    {
        bool colorFound = false;

        // Try each available color
        for (int c = 0; c < numberOfColors; c++)
        {
            bool canUse = true;

            // Check connected nodes
            for (int other = 1; other <= n; other++)
            {
                if (graph[node][other] == 1 &&
                    nodeColor[other] == colors[c])
                {
                    canUse = false;
                    break;
                }
            }

            // Assign color
            if (canUse == true)
            {
                nodeColor[node] = colors[c];
                colorFound = true;
                break;
            }
        }

        // No available color
        if (colorFound == false)
        {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    }

    // Count colors used
    int usedColors = 0;

    for (int c = 0; c < numberOfColors; c++)
    {
        bool used = false;

        for (int i = 1; i <= n; i++)
        {
            if (nodeColor[i] == colors[c])
            {
                used = true;
                break;
            }
        }

        if (used == true)
        {
            usedColors++;
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
