#ifndef CITY_H
#define CITY_H

#include <QDialog>
#include <QPainter>
#include <QMouseEvent>
#include <QLabel>
#include <cstdlib>
namespace Ui {
class City;
}

class City : public QDialog
{
    Q_OBJECT

public:
    explicit City(QWidget *parent = nullptr);
    ~City();
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    bool check(QPoint);
    bool checkPoint(QPoint);
private slots:
    void on_Generate_clicked();

    void on_Width2_clicked();

    void on_Width5_clicked();

    void on_Width10_clicked();

    void on_Width20_clicked();

    void on_Width40_clicked();

    void on_Width80_clicked();

    void on_Pen_clicked();

    void on_Eraser_clicked();

    void on_Building_clicked();

    void on_Bus_clicked();

    void on_Car_clicked();

    void on_Crosswalk_clicked();

    void on_Door_clicked();

    void on_Grass_clicked();

    void on_Sky_clicked();

    void on_Tree_clicked();

    void on_Mountain_clicked();

    void on_Person_clicked();

    void on_Plant_clicked();

    void on_River_clicked();

    void on_Road_clicked();

    void on_Sidewalk_clicked();

    void on_Streetlight_clicked();

    void on_Window_clicked();

private:
    Ui::City *ui;
    QColor *color;
    QPixmap pix;
    QLabel output_window;
    QPoint lastPoint;
    QPoint endPoint;
    QPen *pen, *eraser;
    int dx1, dy1, dx2, dy2, width, selectItem, unset;
};

#endif // CITY_H
