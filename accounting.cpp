#include "accounting.hpp"
#include "ui_accounting.h"

Accounting::Accounting(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Accounting)
{
    ui->setupUi(this);

    connect(this->ui->addLine, SIGNAL(clicked(bool)), this, SLOT(addLine()));
    connect(this->ui->deleteLine, SIGNAL(clicked(bool)), this, SLOT(deleteLine()));
    connect(this->ui->open, SIGNAL(clicked(bool)), this, SLOT(open()));
    connect(this->ui->save, SIGNAL(clicked(bool)), this, SLOT(save()));
    connect(this->ui->quit, SIGNAL(clicked(bool)), qApp, SLOT(deleteLater()));
}

Accounting::~Accounting()
{
    delete ui;
}

void Accounting::open() {

}

void Accounting::save() {

}

void Accounting::addLine() {
    this->ui->table->setRowCount(this->ui->table->rowCount() + 1);
}

void Accounting::deleteLine() {

}
