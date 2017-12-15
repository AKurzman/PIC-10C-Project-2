#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void calcfinal1();
    void calcfinal2();
    ~MainWindow();

private slots:
    void execute();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
