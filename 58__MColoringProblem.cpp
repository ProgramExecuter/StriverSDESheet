bool isOK(bool graph[101][101], int curr, int n, vector<int> &colors, int currColor)
{
    for(int i=0; i<n; ++i)
    {
        // If this is neighbour && its color is same as current color
        // return FALSE, we cannot fill this color
        if(i != curr  &&  graph[curr][i]  &&  colors[i] == currColor)
            return false;
    }
    return true;
}
bool colorGraph(bool graph[101][101], int curr, int m, int n, vector<int> &colors)
{
    // If we complete coloring of all vertices
    if(curr == n)
        return true;
    
    for(int i = 1; i <= m; ++i)
    {
        // If it is ok to fill this color
        if(isOK(graph, curr, n, colors, i))
        {
            colors[curr] = i;

            if(colorGraph(graph, curr+1, m, n, colors))
                return true;
            
            colors[curr] = 0;
        }
    }
    return false;
}
// MAIN FUNCTION
bool graphColoring(bool graph[101][101], int m, int V)
{
    // Vertices's color
    vector<int> colors(V, 0);

    return colorGraph(graph, 0, m, V, colors);
}