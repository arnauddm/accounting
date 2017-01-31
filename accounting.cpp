#include "accounting.hpp"
#include "ui_accounting.h"

Accounting::Accounting(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Accounting)
{
    ui->setupUi(this);

    connect(this->ui->addLine, SIGNAL(clicked(bool)), this, SLOT(addLine()));
    connect(this->ui->deleteLine, SIGNAL(clicked(bool)), this, SLOT(delLine()));
    connect(this->ui->open, SIGNAL(clicked(bool)), this, SLOT(open()));
    connect(this->ui->save, SIGNAL(clicked(bool)), this, SLOT(save()));
    connect(this->ui->quit, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
    connect(this->ui->actionOpen, SIGNAL(triggered(bool)), this, SLOT(open()));
    connect(this->ui->actionSave, SIGNAL(triggered(bool)), this, SLOT(save()));
    connect(this->ui->actionAddLine, SIGNAL(triggered(bool)), this, SLOT(addLine()));
    connect(this->ui->actionDeleteLine, SIGNAL(triggered(bool)), this, SLOT(delLine()));


    this->init();
    this->labelTime = new QLabel();
    this->time = new QTimer();
    connect(this->time, SIGNAL(timeout()), this, SLOT(updateTime()));
    time->start(50);
    this->ui->mainToolBar->addWidget(this->labelTime);
}

Accounting::~Accounting()
{
    delete ui;
}

void Accounting::open() {
    QString url(QFileDialog::getOpenFileName());
    if(url.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Vous n'avez pas sélectionné de fichier");
    } else {
        QFile file(url);
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            //this->init();
            QString readed(file.readAll());
            QStringList fSplit(readed.split("\n"));

            for(unsigned int i(0) ; i < fSplit.size() ; i++) {
                QStringList sSplit(fSplit[i].split("•"));
                for(unsigned int j(0) ; j < sSplit.size() ; j++) {
                    this->addLine();
                    QTableWidgetItem *item = new QTableWidgetItem();
                    item->setText(sSplit[j]);
                    this->ui->table->setItem(i,j,item);
                }
            }
        } else {
            QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier sélectionné");
        }
    }

}

void Accounting::save() {
    QString url(QFileDialog::getSaveFileName());
    if(url.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Vous n'avez pas sélectionné le chemin de sauvegarde. La sauvegarde a échouée !");
    } else {
        QFile file(url);

        if(file.open(QIODevice::WriteOnly | QIODevice::Text)) {

            QTextStream flux(&file);
            QString data;

            for(unsigned int i(0) ; i < this->ui->table->rowCount() ; i++) {
                for(unsigned int j(0) ; j < this->ui->table->columnCount() ; j++) {
                    QTableWidgetItem *item = new QTableWidgetItem();
                    item = this->ui->table->itemAt(1,1);
                    data += item->text() + "•";
                }
                data += "\n";
            }

            flux << data;
            file.close();
        } else {
            QMessageBox::warning(this, "Erreur", "Une erreur est survenue lors de la sauvegarde");
        }
    }
}

void Accounting::addLine() {
    this->ui->table->setRowCount(this->ui->table->rowCount() + 1);
}

void Accounting::delLine() {
    deleteLineW *rl = new deleteLineW(this->ui->table->rowCount());
    connect(rl, SIGNAL(returnValue(uint)), this, SLOT(deleteLine(uint)));
    rl->show();
}

void Accounting::deleteLine(unsigned int line) {
    this->ui->table->removeRow(line);
}

void Accounting::init() {
    this->ui->table->clear();

    QHeaderView *headers = this->ui->table->horizontalHeader();
    headers->sectionResizeMode(QHeaderView::Stretch);

    this->ui->table->setColumnCount(4);
    this->ui->table->setHorizontalHeaderItem(0, new QTableWidgetItem("Catégorie"));
    this->ui->table->setHorizontalHeaderItem(1, new QTableWidgetItem("Ordre"));
    this->ui->table->setHorizontalHeaderItem(2, new QTableWidgetItem("Date"));
    this->ui->table->setHorizontalHeaderItem(3, new QTableWidgetItem("Montant"));
}

void Accounting::updateTime() {
    this->labelTime->setText("Il est : " + QTime::currentTime().toString("hh:mm:ss"));
}
