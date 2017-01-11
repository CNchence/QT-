#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    int jiance(int i,int j,int team,int x,int y);
    void wheelEvent(QWheelEvent *event);
signals:
    void gameover();
public slots:
    void refresh();

private:
    Ui::MainWindow *ui;
    int a[48][48];
    int player;
    int renshu;
};

#endif // MAINWINDOW_H
