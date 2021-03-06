﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QWidget>
#include <QVBoxLayout>
#include <QImage>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QMessageBox>
#include <QIcon>
#include <QtGui>
#include <QTextCodec>
#include <QCursor>
#include <QMatrix>
#include <QPoint>
#include <QMouseEvent>
#include <QRect>
#include <QDebug>
#include <QLabel>
#include <QMatrix>
#include <QRgb>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMenu *FileMenu;
    QMenu *ImageMenu;
    QMenu *ImageModeMenu;
    QMatrix matrix;

    //图像菜单action
    QAction *GreyImageAction;
    QAction *RGBImageAction;

    //文件菜单action
    QAction *OpenFileAction;
    QAction *SaveFileAction;
    QAction *QuitAction;
    QAction *EnlargeAction;
    QAction *ShrinkAction;

    QWidget *imageShowWidget;
    QVBoxLayout *mainLayout;
    QImage *img;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPoint *mousePos;


    QLabel *imageLabel;
    int ButtonId = -1;
    const int EnlargeBtn = 0;
    const int ShrinkBtn = 1;



    void MenuCreate();//创建导航菜单
    QImage* GreyModeImage(QImage* origin);//改为灰度图像
    void DisplayImage();//显示图片

protected:
    void mousePressEvent(QMouseEvent *event);


private slots:
    void OpenImage();//打开图片
    void ImageInZoom();//图片放大
    void ImageReduce();//图片缩小
    void SaveImage();//保存图片
    void ShowGreyImage();//显示灰度图

};

#endif // MAINWINDOW_H
