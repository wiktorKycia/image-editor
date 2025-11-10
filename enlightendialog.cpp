#include "enlightendialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

EnlightenDialog::EnlightenDialog(QWidget *parent)
    : QDialog{parent}
{
    setWindowTitle(tr("Adjust lightness"));
    resize(300, 150);

    slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100);
    slider->setValue(10);

    QLabel *label = new QLabel(tr("Light factor:"));

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


double EnlightenDialog::light() const
{
    return slider->value() / 10.0;
}
