#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QLabel>
#include "portablepixmap.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool loadFile(const QString &);

protected:
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU

private slots:
    void open();
    void save();
    void negative();
    void enlighten();
    void darken();
    void contrast();
    void decontrast();

private:
    PortablePixMap ppm;

    void createActions();
    void createMenus();
    void displayImage(const QImage &img);

    QMenu *fileMenu;

    QAction *openAct;
    QAction *saveAct;


    QMenu *colorsMenu;
    QActionGroup *colorGroup;
    QAction *negativeAct;
    QAction *enlightenAct;
    QAction *darkenAct;
    QAction *contrastAct;
    QAction *decontrastAct;

    QLabel *infoLabel;

    QImage image;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
};
#endif // MAINWINDOW_H
