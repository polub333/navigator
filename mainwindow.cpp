#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    engine = new Engine();
    Scene* scene = new Scene();
    scene->setSceneRect(0, 0, 1000, 1000);
    ui->SceneView->setMouseTracking(true);
    ui->SceneView->setDragMode(QGraphicsView::ScrollHandDrag);
    ui->SceneView->setScene(scene);
    engine->setScene(scene);

    engine->createNode("Zhukovsky", 200, 200);
    engine->createNode("Moscow", 300, 300);
    engine->createNode("Ramenskoe", 200, 250);
    engine->createNode("Peno", 160, 190);


    engine->createPath(0, 1, highway);
    engine->createPath(0, 2, railway);
    engine->createPath(0, 3, road);
    engine->createPath(2, 3, road);
    engine->createPath(1, 2, gravel);

    engine->draw();

}

MainWindow::~MainWindow()
{
    delete ui;
}


