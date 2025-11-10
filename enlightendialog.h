#ifndef ENLIGHTENDIALOG_H
#define ENLIGHTENDIALOG_H

#include <QDialog>
#include <QSlider>
#include <QPushButton>
#include <QLabel>

class EnlightenDialog : public QDialog
{
    Q_OBJECT
public:
    explicit EnlightenDialog(QWidget *parent = nullptr);

    double light() const;

private:
    QSlider *slider;
    QPushButton *okButton;
    QPushButton *cancelButton;

signals:
};

#endif // ENLIGHTENDIALOG_H
