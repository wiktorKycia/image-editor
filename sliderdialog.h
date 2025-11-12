#ifndef SLIDERDIALOG_H
#define SLIDERDIALOG_H

#include <QDialog>
#include <QSlider>
#include <QPushButton>
#include <QLabel>

class SliderDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SliderDialog(
        QWidget *parent = nullptr,
        QString windowTitle = tr("slider"),
        QString sliderLabelText = tr("set value"),
        double _max = 100.0,
        double _min = 0.0,
        double _step = 10.0);

    double get_value() const;

private:
    double _min, _max, _step;

    QSlider *slider;
    QPushButton *okButton;
    QPushButton *cancelButton;

    inline void createButtons(QString labelText);

signals:
};

#endif // SLIDERDIALOG_H
