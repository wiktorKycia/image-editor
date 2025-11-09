#include<QLabel>

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>

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

private:
    void createActions();
    void createMenus();
    void displayImage(const QImage &img);

    QMenu *fileMenu;
    QMenu *colorsMenu;
    QActionGroup *alignmentGroup;
    QAction *openAct;

    QLabel *infoLabel;

    QImage image;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
};
#endif // MAINWINDOW_H
