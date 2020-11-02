#include "RomanNumbersWidget.h"
#include "ui_RomanNumbersWidget.h"
#include "RomanNumbers.h"

#include <QMessageBox>
#include <QtGlobal>

RomanNumbersWidget::RomanNumbersWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RomanNumbersWidget)
{
    ui->setupUi(this);
    connect(ui->inputSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
            this, &RomanNumbersWidget::toString);
    connect(ui->resultLineEdit, &QLineEdit::returnPressed,
            this, &RomanNumbersWidget::toInt);
}

RomanNumbersWidget::~RomanNumbersWidget()
{
    delete ui;
}

void RomanNumbersWidget::toString(int value)
{
    try {
        ui->resultLineEdit->setText(RomanNumbers::toString(value).data());
    } catch (...) {
        QMessageBox::critical(this, tr("Error"),
                              tr("Input number between 1 and %1")
                              .arg(RomanNumbers::maxValue));
    }
}

void RomanNumbersWidget::toInt()
{
    try {
        ui->inputSpinBox->setValue(
                    RomanNumbers::toUInt(ui->resultLineEdit->text().toLatin1().data()));
    } catch (...) {
        QMessageBox::critical(this, tr("Error"),
                              tr("Invalid input. Input number between 1 and %1")
                              .arg(RomanNumbers::maxValue));
    }
}
