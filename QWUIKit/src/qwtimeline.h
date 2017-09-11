#ifndef QWTIMELINE_H
#define QWTIMELINE_H

#include <QListWidget>

class QWTimeLine : public QListWidget
{
    Q_OBJECT
public:
    enum POINT_TYPE
    {
        START,
        INTERMEDIATE,
        END
    };

public:
    explicit QWTimeLine(QWidget *parent = nullptr);
    void initializeUI();
    void addTimeLinePoint(const QString& text, POINT_TYPE type);

signals:
    void itemClicked(unsigned int index);

public slots:
    void itemClickedSlot(QListWidgetItem *item);
    void currentItemChangedSlot(QListWidgetItem * current, QListWidgetItem * previous);
private:
    unsigned int _index = 0;

};

#endif // QWTIMELINE_H
