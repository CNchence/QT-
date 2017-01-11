#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = 1;
    renshu =2;
    int i,j;
    for(i=0;i<47;i++)
    {
        for(j=0;j<47;j++)
        {
            a[i][j] = 0;
        }
    }
    connect(this,SIGNAL(gameover()),this,SLOT(refresh()));

}

MainWindow::~MainWindow()
{
    delete ui;


}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);
    int i,j;
    for (i = 0; i < 48; i++)
    {
        p.drawLine(20, 20 + i * 40, 1900, 20 + i * 40);
        p.drawLine(20 + i * 40, 20, 20 + i * 40, 1900);
    }
    QBrush brush;
       brush.setStyle(Qt::SolidPattern);
       for (i = 0; i < 47; i++)
       {
           for (j = 0; j < 47; j++)
           {
               if (a[i][j] == 1)
               {
                   brush.setColor(Qt::black);
                   p.setBrush(brush);
                   p.drawEllipse(QPoint((i + 1) * 40, (j + 1) * 40), 15, 15);
               }
               else if (a[i][j] == 2)
               {
                   brush.setColor(Qt::white);
                   p.setBrush(brush);
                   p.drawEllipse(QPoint((i + 1) * 40, (j + 1) * 40), 15, 15);
               }
               else if (a[i][j] == 3)
               {
                   brush.setColor(Qt::red);
                   p.setBrush(brush);
                   p.drawEllipse(QPoint((i + 1) * 40, (j + 1) * 40), 15, 15);
               }
               else if (a[i][j] == 4)
               {
                   brush.setColor(Qt::blue);
                   p.setBrush(brush);
                   p.drawEllipse(QPoint((i + 1) * 40, (j + 1) * 40), 15, 15);
               }
               else if (a[i][j] == 5)
               {
                   brush.setColor(Qt::yellow);
                   p.setBrush(brush);
                   p.drawEllipse(QPoint((i + 1) * 40, (j + 1) * 40), 15, 15);
               }

           }
       }
}



void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int x, y,j1,j2,j3,j4;
      if(e->x() >= 20 && e->x() < 1900 && e->y() >= 20 && e->y() < 1900)
      {
          x = (e->x() - 20) / 40;
          y = (e->y() - 20) / 40;
          if (a[x][y] == 0)
          {
              a[x][y] = player++;
              if(player == renshu+1)
                  player =1;
          }

          j1 = jiance(1,0,a[x][y],x,y);        //检测x
          j2 = jiance(0,1,a[x][y],x,y);        //检测y
          j3 = jiance(1,1,a[x][y],x,y);        //检测45度
          j4 = jiance(1,-1,a[x][y],x,y);       //检测135度
          if(j1 ==4||j2==4||j3==4||j4==4)
          {
              this->update();
              //setEnabled(false);
              if(a[x][y] == 1)
              {
                    QMessageBox::information(this, "Win", "Black Win!", QMessageBox::Ok);
              }
              if(a[x][y] == 2)
              {
                    QMessageBox::information(this, "Win", "White Win!", QMessageBox::Ok);
              }
              if(a[x][y] == 3)
              {
                    QMessageBox::information(this, "Win", "Red Win!", QMessageBox::Ok);
              }
              if(a[x][y] == 4)
              {
                    QMessageBox::information(this, "Win", "Blue Win!", QMessageBox::Ok);
              }
              if(a[x][y] == 5)
              {
                    QMessageBox::information(this, "Win", "Yellow Win!", QMessageBox::Ok);
              }
              emit gameover();

          }

      }
      this->update();
}

int MainWindow::jiance(int i, int j,int team,int x,int y)
{

    int jieguo= 0;
    int nextteam;
    int footx = i;
    int footy = j;
    int huanxiang =0;
    while(1)                                  //x向检测
    {
        if(huanxiang ==0)
        {
            nextteam = a[x+footx][y+footy];
        }
        else if(huanxiang ==1)
        {
            nextteam = a[x-footx][y-footy];
        }
        else break;

        if(nextteam == team)
        {
            jieguo++;
            footx += i;
            footy += j;

        }
        else
        {
            footx = i;
            footy = j;
            huanxiang++;
        }

    }
    return jieguo;



}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    int numDegrees = event->delta() / 8;//滚动的角度，*8就是鼠标滚动的距离
    int numSteps = numDegrees / 15;//滚动的步数，*15就是鼠标滚动的角度
    if (event->orientation() == Qt::Horizontal)
    {
      qDebug()<<"horiz";

    }
    else
    {
      qDebug()<<"llll"<<numSteps<<"   "<<numDegrees;
    }
    event->accept();      //接收该事件


}

void MainWindow::refresh()
{
    int i = 0;
    int j = 0;
    player = 1;
    for(i=0;i<47;i++)
    {
        for(j=0;j<47;j++)
        {
            a[i][j] = 0;
        }
    }
    this->update();
}
























