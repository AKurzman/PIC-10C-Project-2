#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <vector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->hw1spin, SIGNAL(valueChanged(int)),ui->hw1slide,SLOT(setValue(int)));
    connect(ui->hw1slide, SIGNAL(valueChanged(int)),ui->hw1spin,SLOT(setValue(int)));
    connect(ui->hw2spin, SIGNAL(valueChanged(int)),ui->hw2slide,SLOT(setValue(int)));
    connect(ui->hw2slide, SIGNAL(valueChanged(int)),ui->hw2spin,SLOT(setValue(int)));
    connect(ui->hw3spin, SIGNAL(valueChanged(int)),ui->hw3slide,SLOT(setValue(int)));
    connect(ui->hw3slide, SIGNAL(valueChanged(int)),ui->hw3spin,SLOT(setValue(int)));
    connect(ui->hw4spin, SIGNAL(valueChanged(int)),ui->hw4slide,SLOT(setValue(int)));
    connect(ui->hw4slide, SIGNAL(valueChanged(int)),ui->hw4spin,SLOT(setValue(int)));
    connect(ui->hw5spin, SIGNAL(valueChanged(int)),ui->hw5slide,SLOT(setValue(int)));
    connect(ui->hw5slide, SIGNAL(valueChanged(int)),ui->hw5spin,SLOT(setValue(int)));
    connect(ui->hw6spin, SIGNAL(valueChanged(int)),ui->hw6slide,SLOT(setValue(int)));
    connect(ui->hw6slide, SIGNAL(valueChanged(int)),ui->hw6spin,SLOT(setValue(int)));
    connect(ui->hw7spin, SIGNAL(valueChanged(int)),ui->hw7slide,SLOT(setValue(int)));
    connect(ui->hw7slide, SIGNAL(valueChanged(int)),ui->hw7spin,SLOT(setValue(int)));
    connect(ui->hw8spin, SIGNAL(valueChanged(int)),ui->hw8slide,SLOT(setValue(int)));
    connect(ui->hw8slide, SIGNAL(valueChanged(int)),ui->hw8spin,SLOT(setValue(int)));

    connect(ui->mid1spin, SIGNAL(valueChanged(int)),ui->mid1slide,SLOT(setValue(int)));
    connect(ui->mid1slide, SIGNAL(valueChanged(int)),ui->mid1spin,SLOT(setValue(int)));
    connect(ui->mid2spin, SIGNAL(valueChanged(int)),ui->mid2slide,SLOT(setValue(int)));
    connect(ui->mid2slide, SIGNAL(valueChanged(int)),ui->mid2spin,SLOT(setValue(int)));
    connect(ui->finalspin, SIGNAL(valueChanged(int)),ui->finalslide,SLOT(setValue(int)));
    connect(ui->finalslide, SIGNAL(valueChanged(int)),ui->finalspin,SLOT(setValue(int)));

    connect(ui->quit, SIGNAL(pressed()), this, SLOT (close()));

    connect(ui->calcbutton,SIGNAL(pressed()),this,SLOT(execute()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::execute(){
    if (ui->scheme1->isChecked()){
        calcfinal1();
    }
    else if (ui->scheme2->isChecked()){
        calcfinal2();
    }
    else
        return;
}

void MainWindow::calcfinal1(){
    double score;
    std::vector<int>hwscores;
    double hw1=double(ui->hw1spin->value());
    double hw2=double(ui->hw2spin->value());
    double hw3=double(ui->hw3spin->value());
    double hw4=double(ui->hw4spin->value());
    double hw5=double(ui->hw5spin->value());
    double hw6=double(ui->hw6spin->value());
    double hw7=double(ui->hw7spin->value());
    double hw8=double(ui->hw8spin->value());
    double minhw=hw1;
    hwscores.push_back(hw1);
    hwscores.push_back(hw2);
    hwscores.push_back(hw3);
    hwscores.push_back(hw4);
    hwscores.push_back(hw5);
    hwscores.push_back(hw6);
    hwscores.push_back(hw7);
    hwscores.push_back(hw8);


    for (int i=0;i<8;++i){
        if (hwscores[i]<minhw){
            minhw=hwscores[i];
        }
    }
    double hwtotal=hw1+hw2+hw3+hw4+hw5+hw6+hw7+hw8-minhw;
    double hwperc=((hwtotal/7.0)/100.0)*25.0;

    double mid1 = double(ui->mid1spin->value());
    double mid2 = double(ui->mid2spin->value());

    double mid1p = (mid1/100.0)*20.0;
    double mid2p = (mid2/100.0)*20.0;
    double fing = double(ui->finalspin->value());
    double finp = (fing/100.0)*35.0;

    score = hwperc+mid1p+mid2p+finp;
    QString fscore(QString::number(score));
    ui->finscore->setText(fscore);
}

void MainWindow::calcfinal2(){
    double score;
    std::vector<int>hwscores;
    int hw1=ui->hw1spin->value();
    int hw2=ui->hw2spin->value();
    int hw3=ui->hw3spin->value();
    int hw4=ui->hw4spin->value();
    int hw5=ui->hw5spin->value();
    int hw6=ui->hw6spin->value();
    int hw7=ui->hw7spin->value();
    int hw8=ui->hw8spin->value();
    int minhw=hw1;
    hwscores.push_back(hw1);
    hwscores.push_back(hw2);
    hwscores.push_back(hw3);
    hwscores.push_back(hw4);
    hwscores.push_back(hw5);
    hwscores.push_back(hw6);
    hwscores.push_back(hw7);
    hwscores.push_back(hw8);


    for (int i=0;i<8;++i){
        if (hwscores[i]<minhw){
            minhw=hwscores[i];
        }
    }
    double hwtotal=hw1+hw2+hw3+hw4+hw5+hw6+hw7+hw8-minhw;
    double hwperc=((hwtotal/7.0)/100.0)*25;

    int mid1 = ui->mid1spin->value();
    int mid2 = ui->mid2spin->value();
    int bmid = mid1;
    if (mid2>bmid){
        bmid=mid2;
    }

    double midp = (bmid/100.0)*30.0;
    int fing = ui->finalspin->value();
    double finp = (fing/100.0)*45.0;

    score = hwperc+midp+finp;
    QString fscore(QString::number(score));
    ui->finscore->setText(fscore);
}
