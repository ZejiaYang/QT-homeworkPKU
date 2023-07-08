#ifndef ENDING_H
#define ENDING_H

#include <QWidget>
#include <QLabel>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
namespace Ui {
class Ending;
}

class Ending : public QWidget
{
    Q_OBJECT
public:
    explicit Ending(QWidget *parent = nullptr);
    int pass;
    ~Ending();
private slots:
    void on_exitButton_clicked();
    void on_pushButton_clicked();
private:
    Ui::Ending *ui;
    QLabel* Intro1;
    QLabel* Intro2;
};

#endif // ENDING_H
