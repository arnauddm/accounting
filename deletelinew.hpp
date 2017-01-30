#ifndef DELETELINEW_HPP
#define DELETELINEW_HPP

#include <QDialog>

namespace Ui {
class deleteLineW;
}

class deleteLineW : public QDialog
{
    Q_OBJECT

public:
    explicit deleteLineW(unsigned int limit, QWidget *parent = 0);
    ~deleteLineW();

public slots:
    void value();

private:
    Ui::deleteLineW *ui;

signals:
    void returnValue(unsigned int value);
};

#endif // DELETELINEW_HPP
