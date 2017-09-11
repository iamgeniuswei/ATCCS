#ifndef QWTIMELINEWIDGET_H
#define QWTIMELINEWIDGET_H

#include <QWidget>
class QLabel;
class QHBoxLayout;
class QWTimeLineWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QWTimeLineWidget(QWidget *parent = nullptr);
    void initializeUI();
    void setText(const QString& text);
    void setIcon(const QString& objectName);
    void setIcon(const QPixmap& pixmap);

    unsigned int type() const;
    void setType(unsigned int type);

    unsigned int index() const;

    void setIndex(unsigned int index);

signals:

public slots:

private:
    QLabel *_textTag;
    QLabel *_iconTag;
    QHBoxLayout *_mainLayout;
    unsigned int _type = 0;
    unsigned int _index = 0;
};

#endif // QWTIMELINEWIDGET_H
