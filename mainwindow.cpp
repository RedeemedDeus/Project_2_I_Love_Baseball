#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString fullpath = "MLB_Stadium_Map.png";

    QPixmap pixmap(fullpath);


    //get the dimensions and scaling of the image
    ui->label->setPixmap(fullpath);

    ui->label->setScaledContents( true );

    ui->label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    QPainter painter(&pixmap);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //get the path for the image
    QString fullpath = "MLB_Stadium_Map.png";

    QPixmap pixmap(fullpath);


    //get the dimensions and scaling of the image
    ui->label->setPixmap(fullpath);

    ui->label->setScaledContents( true );

    ui->label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    QPainter painter(&pixmap);

    //set pen and pen color
    QPen red ((QColor(255,0,0)),1);

    painter.setPen(red);

    //From here down it creates the shortest path to the current


    int final_distance = 0;

    vector<string> final_path;
    int initial_index;
    int final_index;


    //get from combo box what are the source and destination stadiums

    string ini_text = ui->comboBox_2->currentText().toStdString();
    string end_text = ui->comboBox->currentText().toStdString();


    if(ui->radioButton_2->isChecked())
    {
        ini_text = ui->comboBox_3->currentText().toStdString();
        end_text = ui->comboBox_4->currentText().toStdString();
    }
    else if(ui->radioButton_3->isChecked())
    {
        ini_text = ui->comboBox_5->currentText().toStdString();
        end_text = ui->comboBox_6->currentText().toStdString();
    }




    //convert the stadiums into index
    if(ini_text != end_text)
    {

        for(unsigned i = 0; i < MLB_S; i++)
        {
            if(MLB_stadiums.at(i).find(ini_text) != string::npos)
            {
                initial_index = i;
            }
        }

        for(unsigned i = 0; i < MLB_S; i++)
        {
            if(MLB_stadiums.at(i).find(end_text) != string::npos)
            {
                final_index = i;
            }
        }




        Dijkstra_MLB d(MLB_graph, initial_index, MLB_stadiums, final_index);



        final_distance = d.dijkstra(final_path);

        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;

        for(unsigned i = 0; i < final_path.size(); i++)
        {
            if(i + 1 >= final_path.size())
                break;

            for(int s = 0; s < MLB_S; s++)
            {
                if(cords_arr[s].getname().find(final_path.at(i)) != string::npos)
                {
                    x1 = cords_arr[s].getx();
                    y1 = cords_arr[s].gety();
                }
                else if(cords_arr[s].getname().find(final_path.at(i + 1)) != string::npos)
                {
                    x2 = cords_arr[s].getx();
                    y2 = cords_arr[s].gety();
                }
            }

            painter.drawLine(x1,y1,x2,y2);
        }

    }



    QString fd = QString::fromStdString(to_string(final_distance));
    ui->textBrowser->setText(fd);


    ui->label->setPixmap(pixmap);

}


void MainWindow::on_radioButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_radioButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_radioButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_custom_add_destination_clicked()
{
    if(custom_destinations.empty())
        custom_destinations.push_back(ui->comboBox_custom_source->currentText().toStdString());

    custom_destinations.push_back(ui->comboBox_custom_destinations->currentText().toStdString());
}

void MainWindow::on_pushButton_custom_display_trip_clicked()
{
    //get the path for the image
    QString fullpath = "MLB_Stadium_Map.png";

    QPixmap pixmap(fullpath);


    //get the dimensions and scaling of the image
    ui->label->setPixmap(fullpath);

    ui->label->setScaledContents( true );

    ui->label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    QPainter painter(&pixmap);

    //set pen and pen color
    QPen red ((QColor(255,0,0)),1);

    painter.setPen(red);

    //From here down it creates the shortest path to the current


    int final_distance = 0;

    vector<string> final_path;
    int initial_index;
    int final_index;


    //get from combo box what are the source and destination stadiums



    if(custom_destinations.size() >= 2)
    {

            int x1 = 0;
            int y1 = 0;
            int x2 = 0;
            int y2 = 0;

            for(unsigned z = 0; z < custom_destinations.size(); z++)
            {
                if((z + 1) >= custom_destinations.size())
                    break;

                string ini_text = custom_destinations.at(z);
                string end_text = custom_destinations.at(z + 1);




                //convert the stadiums into index
                if(ini_text != end_text)
                {

                    for(unsigned i = 0; i < MLB_S; i++)
                    {
                        if(MLB_stadiums.at(i).find(ini_text) != string::npos)
                        {
                            initial_index = i;
                        }
                    }

                    for(unsigned i = 0; i < MLB_S; i++)
                    {
                        if(MLB_stadiums.at(i).find(end_text) != string::npos)
                        {
                            final_index = i;
                        }
                    }


                Dijkstra_MLB d(MLB_graph, initial_index, MLB_stadiums, final_index);

                final_distance += d.dijkstra(final_path);



                for(unsigned i = 0; i < final_path.size(); i++)
                {
                    if(i + 1 >= final_path.size())
                        break;

                    for(int s = 0; s < MLB_S; s++)
                    {
                        if(cords_arr[s].getname().find(final_path.at(i))
                                != string::npos)
                        {
                            x1 = cords_arr[s].getx();
                            y1 = cords_arr[s].gety();
                        }
                        else if(cords_arr[s].getname().find(final_path.at(i + 1))
                                != string::npos)
                        {
                            x2 = cords_arr[s].getx();
                            y2 = cords_arr[s].gety();
                        }
                    }

                    painter.drawLine(x1,y1,x2,y2);
                }

                final_path.clear();

            }



        }

    }


    custom_destinations.clear();

    QString fd = QString::fromStdString(to_string(final_distance));
    ui->textBrowser_custom_total->setText(fd);


    ui->label->setPixmap(pixmap);


}



void MainWindow::on_pushButton_add_stadium_clicked()
{

    //get the path for the image
    QString fullpath = "MLB_Stadium_Map.png";

    QPixmap pixmap(fullpath);


    //get the dimensions and scaling of the image
    ui->label->setPixmap(fullpath);

    ui->label->setScaledContents( true );

    ui->label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    QPainter painter(&pixmap);

    //set pen and pen color
    QPen red ((QColor(255,0,0)),1);
    red.setWidth(6);

    painter.setPen(red);


    painter.drawPoint(ui->spinBox_xcord_add->value(), ui->spinBox_ycord_add->value());


    ui->label->setPixmap(pixmap);


    pixmap.save("MLB_Stadium_Map.png");

}
