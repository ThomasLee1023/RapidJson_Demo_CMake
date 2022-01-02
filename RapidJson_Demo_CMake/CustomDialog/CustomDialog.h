

#ifndef CUSTOM_DIALOG_H
#define CUSTOM_DIALOG_H

#include <QDialog>

class QLCDNumber;
class QTimer;
class QTableView;
class CustomizedModel;
class CustomizedDelegate;

class CustomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomDialog(QWidget *parent = nullptr);

    virtual void keyPressEvent(QKeyEvent* event) override;
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseMoveEvent(QMouseEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;

private slots:
        void onTimeout();

private:
    bool m_LeftPress = false;
    QPoint m_Point;

    QLCDNumber* m_pLcd = nullptr;
    QTimer* pTimer = nullptr;

    QTableView* m_pTableView = nullptr;
    CustomizedModel* m_pModel = nullptr;
    CustomizedDelegate* m_pDelegate = nullptr;
};


#endif // !CUSTOM_DIALOG_H
