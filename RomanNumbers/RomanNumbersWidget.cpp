#include "RomanNumbersWidget.h"
#include "ui_RomanNumbersWidget.h"
#include "RomanNumbers.h"

#include <QMessageBox>

RomanNumbersWidget::RomanNumbersWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RomanNumbersWidget)
{
    ui->setupUi(this);
    connect(ui->inputSpinBox, &QSpinBox::editingFinished,
            this, &RomanNumbersWidget::on_pushButton_clicked);
}

RomanNumbersWidget::~RomanNumbersWidget()
{
    delete ui;
}

void RomanNumbersWidget::on_pushButton_clicked()
{
    try {
        ui->resultLineEdit->setText(
                    RomanNumbers::toString(ui->inputSpinBox->value()));
    } catch (...) {
        QMessageBox::critical(this, tr("Error"),
                              tr("Input number between 1 and %1")
                              .arg(RomanNumbers::maxValue));
    }
}
