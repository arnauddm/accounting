#ifndef ACCOUNTING_HPP
#define ACCOUNTING_HPP

#include "deletelinew.hpp"

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFile>
#include <QFileDialog>
#include <QIODevice>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QMessageBox>
#include <QTime>
#include <QLabel>
#include <QTimer>
#include <QDebug>

namespace Ui {
class Accounting;
}

class Accounting : public QMainWindow
{
    Q_OBJECT

public:
    explicit Accounting(QWidget *parent = 0);
    ~Accounting();

    void init();

private:
    Ui::Accounting *ui;
    QTimer *time;
    QLabel *labelTime;

public slots:
    void open();
    void save();
    void addLine();
    void delLine();
    void deleteLine(unsigned int line);
    void updateTime();
};

#endif // ACCOUNTING_HPP
