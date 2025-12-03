#include "sliderdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include<iostream>

SliderDialog::SliderDialog(QWidget *parent, QString windowTitle, QString sliderLabelText, double _min, double _max, double _step, double default_value)
    : QDialog{parent}
{
    setWindowTitle(windowTitle);
    resize(300, 150);

    this->_min = _min;
    this->_max = _max;
    this->_step = _step;

    slider = new QSlider(Qt::Horizontal);
    slider->setRange(_min, _max);
    slider->setValue(static_cast<int>(default_value));

    std::cout << "Creating slider: \n";
    std::cout << "min=" << _min << std::endl;
    std::cout << "max=" << _max << std::endl;
    std::cout << "step=" << _step << std::endl;
    std::cout << "default=" << default_value<< std::endl;

    this->createButtons(sliderLabelText);
}

inline void SliderDialog::createButtons(QString labelText)
{
    QLabel *label = new QLabel(labelText);

    okButton = new QPushButton(tr("OK"));
    cancelButton = new QPushButton(tr("Cancel"));

    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);

    QVBoxLayout *mainLayout = new QVBoxLayout;

    QHBoxLayout *sliderLayout = new QHBoxLayout;
    sliderLayout->addWidget(label);
    sliderLayout->addWidget(slider);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch();
    buttonsLayout->addWidget(okButton);
    buttonsLayout->addWidget(cancelButton);

    mainLayout->addLayout(sliderLayout);
    mainLayout->addLayout(buttonsLayout);

    setLayout(mainLayout);
}

double SliderDialog::get_value() const
{
    std::cout << "The slider value: " << slider->value() << std::endl;

    return slider->value();
}
