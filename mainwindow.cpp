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
    //ui->SceneView->setDragMode(QGraphicsView::ScrollHandDrag);
    ui->SceneView->setScene(scene);
    engine->setScene(scene);


    connect(scene, SIGNAL(changeSceneViewCenter(QPointF)), this, SLOT(changeSceneViewCenter(QPointF)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeSceneViewCenter(QPointF offset)
{
    //ui->SceneView->centerOn(offset);
    QPointF center = ui->SceneView->mapToScene(ui->SceneView->viewport()->rect().center());
    ui->SceneView->centerOn(center - offset);
}

