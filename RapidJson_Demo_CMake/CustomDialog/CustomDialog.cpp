////////////////////////////////////////////////////////////
// 功能：对话框移动跟踪
//
// 
////////////////////////////////////////////////////////////


#include "CustomDialog.h"

#include <QLCDNumber>
#include <QTimer>
#include <QDateTime>

#include <QKeyEvent>
#include <QTableView>

#include <QVBoxLayout>

#include "../model/CustomizedModel.h"
#include "../delegate/CustomizedDelegate.h"

CustomDialog::CustomDialog(QWidget* parent)
    : QDialog(parent)
{

    resize(600, 600);

    m_pLcd = new QLCDNumber(this);

    m_pLcd->setDigitCount(23);
    m_pLcd->setMode(QLCDNumber::Dec); // 十进制显示
    m_pLcd->setSegmentStyle(QLCDNumber::Flat); // 设置显示外观
    m_pLcd->setStyleSheet("border: 1px solid green; color: green;background: silver;");

    // 设置半透明背景
    m_pLcd->setAttribute(Qt::WA_TranslucentBackground, true);

    //m_pLcd->setFrameStyle(QFrame::Panel | QFrame::Raised);

    QDateTime dateTime = QDateTime::currentDateTime();
    m_pLcd->display(dateTime.toString("yyyy-MM-dd hh:mm:ss.zzz"));

    pTimer = new QTimer(this);
    pTimer->setInterval(1000);

    connect(pTimer, SIGNAL(timeout()), this, SLOT(onTimeout()));

    pTimer->start();


    m_pTableView = new QTableView(this);
    m_pTableView->resize(300, 300);
    m_pModel = new CustomizedModel(this);

    QStringList headerList;
    headerList << "No." << "ID" << "Name" << "Age" << "Sex" << "Show";
    m_pModel->setHorizontalHeaderLabels(headerList);

    m_pDelegate = new CustomizedDelegate(this);

    m_pTableView->setModel(m_pModel);
    m_pTableView->setItemDelegate(m_pDelegate);

    m_pTableView->setColumnWidth(1, 200);

    QVBoxLayout* pVLayout = new QVBoxLayout();
    pVLayout->addWidget(m_pLcd);
    pVLayout->addWidget(m_pTableView);

    setLayout(pVLayout);


}


void CustomDialog::keyPressEvent(QKeyEvent* event)
{
    switch (event->key())
    {
        //case Qt::Key_Escape: break;
        //case Qt::Key_Space: break;
    default: break;
    }
}

void CustomDialog::mousePressEvent(QMouseEvent* event)
{
    switch (event->button())
    {
    case Qt::LeftButton:
    {
        m_LeftPress = true;
        m_Point = event->pos();
        break;
    }
    //case Qt::Key_Space: break;
    default: break;
    }
}

void CustomDialog::mouseMoveEvent(QMouseEvent* event)
{
    if (m_LeftPress)
    {
        move(event->pos() - m_Point + pos());
    }
}

void CustomDialog::mouseReleaseEvent(QMouseEvent* event)
{
    m_LeftPress = false;
}

void CustomDialog::onTimeout()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    m_pLcd->display(dateTime.toString("yyyy-MM-dd hh:mm:ss.zzz"));
}
