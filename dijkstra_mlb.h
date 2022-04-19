#ifndef DIJKSTRA_MLB_H
#define DIJKSTRA_MLB_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <climits>

using namespace std;




class Dijkstra_MLB
{
public:
    static const int ROW = 25;
    static const int COL = 25;

    /******************************
    ** CONSTRUCTOR & DESTRUCTOR **
    ******************************/
    Dijkstra_MLB();                                                //constructor
    Dijkstra_MLB(int g[][COL], int i, vector<string> c, int d);    //constructor


    /***************
     ** MUTATORS **
    ***************/
    int dijkstra(vector<string> &allstadiums);


    /***************
    ** ACCESSORS **
    ***************/
    int findMin(int distance[], bool visited[]);
    int print(int distance[], string paths[], vector<string> &c);
    void getpath(string path[], int source, vector<string> &c);
    int getcityindex(string initial);



private:
    int graph[ROW][COL];    //original graph
    int source_index;       //original source index
    int destination_index;  //destination_mlb

    //index of the cities
    vector<string> cities;

};

#endif // DIJKSTRA_MLB_H

/****************************************************************
* Dijkstra Class
* This class represents a Dijkstra class, it manages two
* attributes, graph and source index.
***************************************************************/

/******************************
** CONSTRUCTOR & DESTRUCTOR **
******************************/

/****************************************************************
* Dijkstra ();
* Constructor; Initialize class sets initial index to zero and graph to zero
* Parameters: none
* Return: none
***************************************************************/

/****************************************************************
* Dijkstra(int g[][COL], int i);
* Constructor; Initialize class attributes copies all elements from g to
* graph and makes the source_index equal to i
* Parameters: none
* Return: none
***************************************************************/

/**************
** MUTATORS **
**************/

/*******************************************************************
* void dijkstra();
*
* Mutator; This method will create and output a shortest path
* tree from the graph
*------------------------------------------------------------------
* Parameter: none
*------------------------------------------------------------------
* Return: none
*******************************************************************/

/***************
** ACCESSORS **
***************/

/****************************************************************
* int findMin(int distance[], bool visited[]);
*
* Accessor; This method will return the index of the smalles edge
* --------------------------------------------------------------
* Parameters: int distance[], bool visited[]
* --------------------------------------------------------------
* Return: min_index (int)
***************************************************************/

/****************************************************************
* void print(int distance[], string paths[]);
*
* Accessor; This method will print the Dijkstra's Algorithm
* shortest path graph
* --------------------------------------------------------------
* Parameters: int distance[], string paths[]
* --------------------------------------------------------------
* Return: nothing
***************************************************************/

/****************************************************************
* void getpath(string path[], int source);
*
* Accessor; This method will get the correct path required
* to reach each of the verices
* --------------------------------------------------------------
* Parameters: string path[], int source
* --------------------------------------------------------------
* Return: none
***************************************************************/

/****************************************************************
* int getcityindex(string initial);
*
* Accessor; This method will get the name of the city corresponding
* to the given index
* --------------------------------------------------------------
* Parameters: string initial;
* --------------------------------------------------------------
* Return: index (int)
***************************************************************/





