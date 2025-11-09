#include "mainwindow.h"
#include "portablepixmap.h"
#include<QVBoxLayout>
#include<QStatusBar>
#include<QActionGroup>
#include<QMenuBar>
#include<QContextMenuEvent>
#include<QFileDialog>
#include<QPalette>
#include<QImageReader>
#include<QImage>
#include<QMessageBox>
#include<QPixmap>
#include<string>
#include<iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), imageLabel(new QLabel), scrollArea(new QScrollArea)
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    infoLabel = new QLabel(tr("<i>Choose a menu option, or right-click to "
                              "invoke a context menu</i>"));

    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);
    infoLabel->setScaledContents(false);

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(5,5,5,5);
    layout->addWidget(topFiller);
    layout->addWidget(infoLabel);
    layout->addWidget(bottomFiller);
    widget->setLayout(layout);

    createActions();
    createMenus();

    QString message = tr("A context menu is avaiable by right-cliking");
    statusBar()->showMessage(message);

    setWindowTitle(tr("PPM editor"));
    setMinimumSize(160, 160);
    resize(1080, 720);
}

MainWindow::~MainWindow() {}

void MainWindow::createActions()
{
    openAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen), tr("&Open"), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open file"));
    connect(openAct, &QAction::triggered, this, &MainWindow::open);

    alignmentGroup = new QActionGroup(this);
    alignmentGroup->addAction(openAct);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
}

void MainWindow::open()
{
    infoLabel->setText(tr("Invoked <b>File|open</b>"));
    std::string fileName = QFileDialog::getOpenFileName(this, tr("Open image"), "~", tr("Image Files (*.ppm)")).toUtf8().constData();
    // można też .toStdString();

    PortablePixMap ppm;
    ppm.readFile(fileName);

    // QImage image(QString::fromStdString(fileName));
    // if(image.isNull())
    // {
    //     QMessageBox::warning(this, tr("Open Image"), tr("The Image could not be loaded."));
    //     return;
    // }
    displayImage(ppm.toQImage());
}

void MainWindow::displayImage(const QImage &img)
{
    infoLabel->setPixmap(QPixmap::fromImage(image));
    std::cout << "displayed" << std::endl;
    // infoLabel->setText("");
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(openAct);
    menu.exec(event->globalPos());
}
