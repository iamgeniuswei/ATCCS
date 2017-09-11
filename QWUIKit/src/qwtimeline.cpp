#include "qwtimeline.h"
#include "qwtimelinewidget.h"
QWTimeLine::QWTimeLine(QWidget *parent) : QListWidget(parent)
{
    initializeUI();
}

void QWTimeLine::initializeUI()
{
    setFocusPolicy(Qt::NoFocus);
    this->setSpacing(0);
    
    connect(this,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),\
            this, SLOT(currentItemChangedSlot(QListWidgetItem*,QListWidgetItem*)));
    connect(this, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(itemClickedSlot(QListWidgetItem*)));
}

void QWTimeLine::addTimeLinePoint(const QString &text, POINT_TYPE type)
{
    QWTimeLineWidget *w = nullptr;
    QListWidgetItem *item = nullptr;
    try
    {
        w = new QWTimeLineWidget(this);
        item = new QListWidgetItem(this);
    }
    catch(std::exception &e)
    {
        return;
    }

    item->setSizeHint(QSize(200, 45));
    w->setText(text);
    w->setType(type);
    w->setIndex(_index++);
    switch (type)
    {
    case START:
        w->setIcon("atccs_timeline_start");
        break;
    case INTERMEDIATE:
        w->setIcon("atccs_timeline_intermediate");
        break;
    case END:
        w->setIcon("atccs_timeline_end");
        break;
    default:
        break;
    }
    setItemWidget(item, w);

}


void QWTimeLine::itemClickedSlot(QListWidgetItem *item)
{
    QWidget *widget = itemWidget(item);
    if(widget)
    {
        QWTimeLineWidget *w = qobject_cast<QWTimeLineWidget*>(widget);
        emit itemClicked(w->index());
    }
}

void QWTimeLine::currentItemChangedSlot(QListWidgetItem *current, QListWidgetItem *previous)
{
    QWidget *widget = itemWidget(previous);
    if(widget)
    {
        QWTimeLineWidget *w = qobject_cast<QWTimeLineWidget*>(widget);
        switch (w->type()) {
        case START:
            w->setIcon(QPixmap(":/img/start_point"));
            break;
        case INTERMEDIATE:
            w->setIcon(QPixmap(":/img/dot_normal"));
            break;
        case END:
            w->setIcon(QPixmap(":/img/end_point"));
            break;
        default:
            break;
        }
    }
    QWidget *widget_t = itemWidget(current);
    if(widget_t)
    {
        QWTimeLineWidget *w = qobject_cast<QWTimeLineWidget*>(widget_t);
        switch (w->type()) {
        case START:
            w->setIcon(QPixmap(":/img/start_selected"));
            break;
        case INTERMEDIATE:
            w->setIcon(QPixmap(":/img/inter_selected"));
            break;
        case END:
            w->setIcon(QPixmap(":/img/end_selected"));
            break;
        default:
            break;
        }
    }
    repaint();
}
