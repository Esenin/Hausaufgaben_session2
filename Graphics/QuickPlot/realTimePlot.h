#ifndef REALTIMEPLOT_H
#define REALTIMEPLOT_H

#include <QWidget>

namespace Ui {
class RealTimePlot;
}

class RealTimePlot : public QWidget
{
    Q_OBJECT
    
public:
    explicit RealTimePlot(QWidget *parent = 0);
    ~RealTimePlot();
    
private:
    Ui::RealTimePlot *ui;
};

#endif // REALTIMEPLOT_H
