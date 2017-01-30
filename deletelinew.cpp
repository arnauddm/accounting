#include "deletelinew.hpp"
#include "ui_deletelinew.h"

deleteLineW::deleteLineW(unsigned int limit, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteLineW)
{
    ui->setupUi(this);

    this->ui->spinBox->setMinimum(1);
    this->ui->spinBox->setMaximum(limit);

    connect(this->ui->buttonBox, SIGNAL(accepted()), this, SLOT(value()));
}

deleteLineW::~deleteLineW()
{
    delete ui;
}

void deleteLineW::value() {
    emit returnValue(this->ui->spinBox->value());
}
