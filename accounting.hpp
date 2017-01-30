#ifndef ACCOUNTING_HPP
#define ACCOUNTING_HPP

#include <QMainWindow>

namespace Ui {
class Accounting;
}

class Accounting : public QMainWindow
{
    Q_OBJECT

public:
    explicit Accounting(QWidget *parent = 0);
    ~Accounting();

private:
    Ui::Accounting *ui;

public slots:
    void open();
    void save();
    void addLine();
    void deleteLine();
};

#endif // ACCOUNTING_HPP
