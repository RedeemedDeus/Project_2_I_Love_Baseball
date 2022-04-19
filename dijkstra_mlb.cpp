#include "dijkstra_mlb.h"


/**********************************************************
*
* Method Dijkstra_MLB: Class Dijkstra_MLB
*_________________________________________________________
* This method receives nothing - returns nothing
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*
* POST-CONDITIONS
* This function will construct a Dijkstra_MLB object with default
* values, source_index will be set to zero and the graph
* will have all zeroes
***********************************************************/
Dijkstra_MLB::Dijkstra_MLB()
{
    for(int r = 0; r < ROW; r++)
    {
        for(int c = 0; c < COL; c++)
            graph[r][c] = 0;
    }

    source_index = 0;
}


/**********************************************************
*
* Method Dijkstra_MLB: Class Dijkstra_MLB
*_________________________________________________________
* This method receives a 2D array and a int that represents a
* starting point - returns nothing
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* g: 2D array of ints that will become the graph for the algorithm
* i: the source index, starting point
*
* POST-CONDITIONS
* This function will construct a Dijkstra_MLB object with the
* given values. Will copy the 2D array to become the graph and
* the i will become the source_index, the starting point.
***********************************************************/
Dijkstra_MLB::Dijkstra_MLB(int g[][COL],    //2D array that will become the graph
                   int i,                   //source index, starting point
                   vector<string> c,        //cities_mlb
                   int d)                   //destination_mlb
{
    for(int r = 0; r < ROW; r++)
    {
        for(int c = 0; c < COL; c++)
            graph[r][c] = g[r][c];
    }

    source_index = i;

    cities = c;

    destination_index = d;
}

/**********************************************************
*
* Method Dijkstra_MLB: Class Dijkstra_MLB
*_________________________________________________________
* This method receives nothing - returns nothing
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*
* POST-CONDITIONS
* This function will apply the Dijkstra_MLB Algorithm to
* create a shortest path tree by using other functions
***********************************************************/
int Dijkstra_MLB::dijkstra( vector<string> &allstadiums )
{
    //path taken for all vertices, starting at seattle
    string paths[ROW];
    paths[0] = cities.at(source_index);

    int distance[ROW]; //final distance to the other vertices from the source

    bool visited[ROW]; //keeps track of the vertex visited so they are visited again

    for(int i = 0; i < ROW; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[source_index] = 0;

    for(int out = 0; out < ROW - 1; out++)
    {
        int min_index = findMin(distance, visited);

        visited[min_index] = true;

        for(int inner = 0; inner < ROW ; inner++)
        {
            if(!visited[inner] && graph[min_index][inner] != 0
             && distance[min_index] != INT_MAX
             && distance[min_index] + graph[min_index][inner] < distance[inner])
            {
                paths[inner] = cities[min_index];
                distance[inner] = distance[min_index] + graph[min_index][inner];
            }
        }
    }

    return print(distance, paths, allstadiums);
}

/**********************************************************
*
* Method findMin: Class Dijkstra_MLB
*_________________________________________________________
* This method one int array and one bool array - returns min_index
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* distance: the array that contains all distances to the current
* reacheable vertices
* visited: vertices that have already been visited
*
* POST-CONDITIONS
* This function will find the index for the vertex that has
* the smallest edge
***********************************************************/
int Dijkstra_MLB::findMin(int distance[],   //distances to the vertices
                      bool visited[])   //visited vertices
{
    int min = INT_MAX;
    int min_index;

    for(int i = 0; i < ROW; i++)
    {
        if(visited[i] == false && distance[i] <= min)
        {
            min = distance[i];
            min_index = i;
        }
    }

    return min_index;
}


/**********************************************************
*
* Method print: Class Dijkstra_MLB
*_________________________________________________________
* This method receives one int array and one string array - returns nothing
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* distance: final distance to all vertices in the graph
* paths: path to get to all vertices in the graph
*
* POST-CONDITIONS
* This function will construct a Dijkstra_MLB object with default
* values, source_index will be set to zero and the graph
* will have all zeroes
***********************************************************/
int Dijkstra_MLB::print(int distance[],    //distance to all vertices
                     string paths[],    //paths to get to all vertices
                     vector<string> &c)  //cities
{


    for(int i = 0; i < ROW; i++)
    {
        if(i = destination_index)
        {

            getpath(paths, i, c);

            c.push_back(cities.at(destination_index));

            return distance[i];

        }
    }
}

/**********************************************************
*
* Method getpath: Class Dijkstra_MLB
*_________________________________________________________
* This method receives one string array and one int - returns nothing
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* path: array of string that is the paths to all vertices in the graph
* source: source index
*
* POST-CONDITIONS
* This function will output the correct path to get to all vertices
* in the graph recursively
***********************************************************/
void Dijkstra_MLB::getpath(string path[],   //paths to all vertices
                       int source,          //source index
                       vector<string> &c)   //cities
{
    if(path[source] == cities.at(source_index))
    {
        c.push_back(cities.at(source_index));
        return;
    }

    getpath(path, getcityindex(path[source]), c);

    c.push_back(path[source]);

    return;
}

/**********************************************************
*
* Method getcityindex: Class Dijkstra_MLB
*_________________________________________________________
* This method receives a string - returns an int(city index)
*_________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* intial: string that stores the name of city
*
* POST-CONDITIONS
* This function will get the index corresponding to the name
* of the city
***********************************************************/
int Dijkstra_MLB::getcityindex(string initial)  //name of the city
{
    for(int i = 0; i < ROW; i++)
        if(cities[i] == initial)
            return i;
}


