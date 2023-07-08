#ifndef VISITOR_H
#define VISITOR_H

#include <QWidget>

namespace Ui {
class Visitor;
}

class Visitor : public QWidget
{
    Q_OBJECT

public:
    explicit Visitor(QWidget *parent = 0);
    ~Visitor();
    int pass;
public slots:
    void set_style();
    void close_visitor();
private:
    Ui::Visitor *ui;
};

#endif // VISITOR_H
