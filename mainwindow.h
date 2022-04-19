#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>

using namespace std;

#include "Coordinates.h"
#include "dijkstra_mlb.h"

#include <QMainWindow>
#include <QLabel>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPixmap>
#include <QComboBox>
#include <QString>
#include <QRadioButton>
#include <QStackedWidget>

#include <QSpinBox>
#include <QBuffer>
#include <QImage>

#include <vector>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    const static int MLB_S = 25;
    const static int AL_S = 15;
    const static int NL_S = 15;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_pushButton_custom_add_destination_clicked();

    void on_pushButton_custom_display_trip_clicked();

    void on_pushButton_add_stadium_clicked();

private:
    Ui::MainWindow *ui;


    vector<string> custom_destinations;

    Coordinates cords_arr[MLB_S] {Coordinates("PETCO Park", 94, 349),
    Coordinates("Dodger Stadium - Angel Stadium", 75, 322),
    Coordinates("AT&T Park - O.co Coliseum", 34, 236),
    Coordinates("Safeco Field", 91, 61),Coordinates("Chase Field", 174, 354),
    Coordinates("Coors Field", 296, 246),Coordinates("Minute Maid Park", 439, 453),
    Coordinates("Rangers Ballpark", 416, 392),Coordinates("Kauffman Stadium", 455, 266),
    Coordinates("Target Field", 466, 154),Coordinates("Busch Stadium", 512, 275),
    Coordinates("Wringley Field - US. Cellular Field", 545, 208),
    Coordinates("Miller Park", 542, 183),Coordinates("Marlins Park", 702, 506),
    Coordinates("Tropicana Field", 666, 468),Coordinates("Turner Field", 618, 361),
    Coordinates("Great American Ballpark", 605, 254), Coordinates("PNC Park", 669, 220),
    Coordinates("Progressive Field", 634, 211),Coordinates("Comerica Park", 608, 193),
    Coordinates("Rogers Center", 667, 153),
    Coordinates("Camden Yards - Nationals Park", 712, 241),
    Coordinates("Citizens Bank Park", 732, 214),
    Coordinates("Yankee Stadium - Citi Field", 751, 195),
    Coordinates("Fenway Park", 780, 161) };


    vector<string> MLB_stadiums {"PETCO Park",  //0
                                "Dodger Stadium - Angel Stadium",   //1
                                "AT&T Park - O.co Coliseum", //2
                                "Safeco Field", //3
                                "Chase Field", //4
                                "Coors Field", //5
                                "Minute Maid Park", //6
                                "Rangers Ballpark", //7
                                "Kauffman Stadium",//8
                                "Target Field", //9
                                "Busch Stadium", //10
                                "Wringley Field - US. Cellular Field",//11
                                "Miller Park", //12
                                "Marlins Park", //13
                                "Tropicana Field", //14
                                "Turner Field", //15
                                "Great American Ballpark",  //16
                                "PNC Park", //17
                                "Progressive Field",    //18
                                "Comerica Park",    //19
                                "Rogers Center",    //20
                                "Camden Yards - Nationals Park", //21
                                "Citizens Bank Park",   //22
                                "Yankee Stadium - Citi Field", //23
                                "Fenway Park"}; //24

    int MLB_graph[MLB_S][MLB_S]
{ {0,110,0,0,300, 830, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //PETCO Park
{110,0,340,0,0,0,0,0,0,1500,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //Dodger Stadium - Angel Stadium
{0,340,0,680,650,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},  //AT&T Park - O.co Coliseum
{0,0,680,0,0,0,0,0,0,1390,0,0,0,0,0,0,0,0,0,0,2070,0,0,0,0}, //Safeco Field
{300,0,650,0,0,580,1115,870,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //Chase Field
{830,0,0,0,580,0,0,650,560,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //Coors Field
{0,0,0,0,1115,0,0,230,0,0,680,0,0,965,790,0,0,0,0,0,0,0,0,0,0}, //Minute Maid Park
{0,0,0,0,870,650,230,0,460,0,0,0,0,0,0,740,0,0,0,0,0,0,0,0,0}, //Rangers Ballpark
{0,0,0,0,0,560,0,460,0,0,235,415,0,0,0,0,0,0,0,0,0,0,0,0,0}, //Kauffman Stadium
{0,1500,0,1390,0,0,0,0,0,0,465,0,300,0,0,0,0,0,0,0,0,0,0,0,0}, //Target Field
{0,0,0,0,0,0,680,0,235,465,0,0,0,0,0,0,310,0,0,0,0,0,0,0,0},  //Busch Stadium
{0,0,0,0,0,0,0,0,415,0,0,0,80,0,0,0,250,0,0,240,0,0,0,0,0},  //Wringley Field - US. Cellular Field
{0,0,0,0,0,0,0,0,0,300,0,80,0,0,0,0,0,0,0,0,430,0,0,0,0}, //Miller Park
{0,0,0,0,0,0,965,0,0,0,0,0,0,0,210,600,0,0,0,0,0,930,0,0,1255}, //Marlins Park
{0,0,0,0,0,0,790,0,0,0,0,0,0,210,0,0,790,0,0,0,0,0,0,0,0}, //Tropicana Field
{0,0,0,0,0,0,0,740,0,0,0,0,0,600,0,0,375,0,0,0,0,560,0,0,0}, //Turner Field
{0,0,0,0,0,0,0,0,0,0,310,250,0,0,790,375,0,260,225,0,0,0,0,0,0}, //Great American Ballpark
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,260,0,115,0,225,195,0,315,0}, //PNC Park
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,225,115,0,90,0,0,0,0,0}, //Progressive Field
{0,0,0,0,0,0,0,0,0,0,0,240,0,0,0,0,0,0,90,0,210,0,0,0,0}, //Comerica Park
{0,0,0,2070,0,0,0,0,0,0,0,0,430,0,0,0,0,225,0,210,0,0,0,0,430}, //Rogers Center
{0,0,0,0,0,0,0,0,0,0,0,0,0,930,0,560,0,195,0,0,0,0,90,0,0}, //Camden Yards - Nationals Park
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,90,0,80,0}, //Citizens Bank Park
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,315,0,0,0,0,80,0,195}, //Yankee Stadium - Citi Field
{0,0,0,0,0,0,0,0,0,0,0,0,0,1255,0,0,0,0,0,0,430,0,0,195,0} }; //Fenway Park


//    vector<string> AL_stadiums {"Angel Stadium",    //0
//                               "O.co Coliseum",     //1
//                               "Safeco Field",      //2
//                               "Minute Maid Park",  //3
//                               "Rangers Ballpark",  //4
//                               "Kauffman Stadium",  //5
//                               "Target Field",      //6
//                               "US. Cellular Field",//7
//                               "Comerica Park",     //8
//                               "Progressive Field", //9
//                               "Tropicana Field",   //10
//                               "Camden Yards",      //11
//                               "Yankee Stadium",    //12
//                               "Rogers Center",     //13
//                               "Fenway Park"};      //14

//    int AL_graph[AL_S][AL_S]
//{   {0,340,0,0,0,0,1500,0,0,0,0,0,0,0,0},    //Angel Stadium
//    {340,0,680,0,0,0,0,0,0,0,0,0,0,0,0},    //O.co Coliseum
//    {0,680,0,0,0,0,1390,0,0,0,0,0,0,2070,0},    //Safeco Field
//    {0,0,0,0,230,0,0,0,0,0,790,0,0,0,0},    //Minute Maid Park
//    {0,0,0,230,0,460,0,0,0,0,0,0,0,0,0},    //Rangers Ballpark
//    {0,0,0,0,460,0,0,415,0,0,0,0,0,0,0},    //Kauffman Stadium
//    {1500,0,1390,0,0,0,0,0,0,0,0,0,0,0,0},    //Target Field
//    {0,0,0,0,0,415,0,0,240,0,0,0,0,0,0},    //US. Cellular Field
//    {0,0,0,0,0,0,0,240,0,90,0,0,0,210,0},    //Comerica Park
//    {0,0,0,0,0,0,0,0,90,0,0,0,0,0,0},    //Progressive Field
//    {0,0,0,790,0,0,0,0,0,0,0,0,0,0,0},    //Tropicana Field
//    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //Camden Yards
//    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //Yankee Stadium
//    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //Rogers Center
//    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};   //Fenway Park


//    vector<string> NL_stadiums {"PETCO Park",       //0
//                               "Dodger Stadium",    //1
//                               "AT&T Park",         //2
//                               "Chase Field",       //3
//                               "Coors Field",       //4
//                               "Busch Stadium",     //5
//                               "Wringley Field",    //6
//                               "Miller Park",       //7
//                               "Great American Ballpark",//8
//                               "PNC Park",          //9
//                               "Marlins Park",      //10
//                               "Turner Field",      //11
//                               "Nationals Park",    //12
//                               "Citizens Bank Park",//13
//                               "Citi Field"};       //14

//    int NL_graph[NL_S][NL_S]
//    {   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //PETCO Park"
//        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //Dodger Stadium
//        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //AT&T Park
//        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //Chase Field
//        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //Coors Field
//        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //Busch Stadium
//        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //Wringley Field
//        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //Miller Park
//        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //Great American Ballpark
//        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //PNC Park
//        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //Marlins Park
//        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //Turner Field
//        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //Nationals Park
//        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //Citizens Bank Park
//        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};   //Citi Field



};
#endif // MAINWINDOW_H
