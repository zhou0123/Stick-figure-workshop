#include "city.h"
#include "ui_city.h"

City::City(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::City)
{
    ui->setupUi(this);
    selectItem = 1;
    width = 2;
    lastPoint =  QPoint(-1, -1);
    endPoint =  QPoint(-1, -1);
    dx1 = 50;
    dy1 = 100;
    dx2 = 700;
    dy2 = 100;
    resize(1200, 800);
    pix = QPixmap(400, 400);
    pix.fill(Qt::white);
    color = new QColor(0xff, 0xff, 0xff);
    pen = new QPen();
    eraser = new QPen();
    eraser->setColor(*color);
    output_window.resize(400, 400);
    output_window.move(dx2, dy2);
}

City::~City()
{
    delete color;
    delete pen;
    delete eraser;
    delete ui;
}
void City::paintEvent(QPaintEvent *)
{
      QPainter pp(&pix);    // 根据鼠标指针前后两个位置就行绘制直线
      QPen *cur;
      if(selectItem == 1)cur = pen;
      else cur = eraser;
      pen->setWidth(width);
      eraser->setWidth(width);
      pen->setColor(*color);
      pp.setPen(*cur);
      if(checkPoint(lastPoint)&&checkPoint(endPoint))pp.drawLine(lastPoint, endPoint);    // 让前一个坐标值等于后一个坐标值，这样就能实现画出连续的线
      lastPoint = endPoint;
      QPainter painter(this);
      painter.setRenderHint(QPainter::Antialiasing, true);
      painter.drawPixmap(dx1, dy1, pix);
}


bool City::checkPoint(QPoint cur){
    int x = cur.rx(), y = cur.ry();
    if(x >= 0 && x <= 400 && y >= 0 && y <= 400)
        return true;
    return false;
}

bool City::check(QPoint cur){
    int x = cur.rx(), y = cur.ry();
    if(x >= dx1 && x <= 400 + dx1 && y >= dy1 && y <= dy1 + 400)
        return true;
    return false;
}

void City::mouseMoveEvent(QMouseEvent *event)
{

    if(event->buttons()&Qt::LeftButton&&check(event->pos())) //鼠标左键按下的同时移动鼠标
    {
        endPoint = event->pos();
        endPoint.rx() -= dx1;
        endPoint.ry() -= dy1;
        update(); //进行绘制
    }
}


void City::mousePressEvent(QMouseEvent *event)
{
      if(event->button()==Qt::LeftButton&&check(event->pos())){//鼠标左键按下
          lastPoint = event->pos();
          lastPoint.rx() -= dx1;
          lastPoint.ry() -= dy1;
      }
}

void City::mouseReleaseEvent(QMouseEvent *event)
{
       if(event->button() == Qt::LeftButton&&check(event->pos())) //鼠标左键释放
       {
              endPoint = event->pos();
              endPoint.rx() -= dx1;
              endPoint.ry() -= dy1;
              update();
       }
}

void City::on_Generate_clicked()
{
    if(pix.save("./temp.jpg", "jpg", 100)!=1)exit(0);
    system("./run/run.exe city.h5 temp.jpg output.jpg");
    QPixmap *output = new QPixmap();
    if(output->load("output.jpg", "jpg")!=1)exit(0);
    output_window.setPixmap(*output);
    output_window.setWindowFlags(output_window.windowFlags() | Qt::WindowStaysOnTopHint);
    output_window.setParent(this);
    output_window.show();
    delete output;
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}


void City::on_Width2_clicked()
{
    width = 2;
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}

void City::on_Width5_clicked()
{
    width = 5;
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}

void City::on_Width10_clicked()
{
    width = 10;
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}

void City::on_Width20_clicked()
{
    width = 20;
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}

void City::on_Width40_clicked()
{
    width = 40;
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}

void City::on_Width80_clicked()
{
    width = 80;
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}

void City::on_Pen_clicked()
{
    selectItem = 1;
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}

void City::on_Eraser_clicked()
{
    selectItem = 0;
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}

void City::on_Building_clicked()
{
    delete(color);
    color = new QColor(128, 128, 105);
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}


void City::on_Bus_clicked()
{
    delete(color);
    color = new QColor(255, 255, 0);
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}


void City::on_Car_clicked()
{
    delete(color);
    color = new QColor(227, 207, 87);
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}


void City::on_Crosswalk_clicked()
{
    delete(color);
    color = new QColor(41, 36, 33);
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}


void City::on_Door_clicked()
{
    delete(color);
    color = new QColor(0, 255, 255);
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}


void City::on_Grass_clicked()
{
    delete(color);
    color = new QColor(0, 255, 0);
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}


void City::on_Sky_clicked()
{
    delete(color);
    color = new QColor(135, 206, 235);
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}


void City::on_Tree_clicked()
{
    delete(color);
    color = new QColor(50, 205, 50);
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}


void City::on_Mountain_clicked()
{
    delete(color);
    color = new QColor(176, 244, 230);
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}


void City::on_Person_clicked()
{
    delete(color);
    color = new QColor(163, 148, 128);
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}


void City::on_Plant_clicked()
{
    delete(color);
    color = new QColor(0, 201, 87);
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}


void City::on_River_clicked()
{
    delete(color);
    color = new QColor(0, 0, 255);
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}


void City::on_Road_clicked()
{
    delete(color);
    color = new QColor(125, 51, 36);
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}


void City::on_Sidewalk_clicked()
{
    delete(color);
    color = new QColor(227, 168, 105);
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}


void City::on_Streetlight_clicked()
{
    delete(color);
    color = new QColor(255, 153, 18);
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}


void City::on_Window_clicked()
{
    delete(color);
    color = new QColor(51, 161, 201);
    lastPoint =  QPoint(-1, -1);  endPoint =  QPoint(-1, -1);
}

