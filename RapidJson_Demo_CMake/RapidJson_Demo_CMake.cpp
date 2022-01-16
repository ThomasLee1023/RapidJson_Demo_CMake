// RapidJson_Demo_CMake.cpp: 定义应用程序的入口点。
//
// 2021/11/18 23:06 周四

#include "RapidJson_Demo_CMake.h"


#include <stdio.h>
#include <string>
#include <iostream>

#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/stringbuffer.h"

#include <QString>
//#include <QtGUI/QPen>

#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "./CustomDialog/CustomDialog.h"


// 解决Qt 中文乱码
#pragma execution_character_set("utf-8")

using namespace std;
using namespace rapidjson;


void* Malloc_New()
{
    auto add = malloc(10);
    return add;
}

#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>

#include <QScatterSeries>

using namespace QT_CHARTS_NAMESPACE;

#include "./CustomLineChart/CustomLineChart.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    auto buff = Malloc_New();
    // placement new
    auto type = new (buff) int (1023);
    delete type;
    type = nullptr;


#if 0
    std::shared_ptr<Widget> p(new Widget());
    std::shared_ptr<Widget> q = p->GetSharedObject();

    std::cout << p.use_count() << std::endl;
    std::cout << q.use_count() << std::endl;
#endif

    std::shared_ptr<Test> pTst = make_shared<Test>();
    std::cout << pTst.use_count() << std::endl;

    std::shared_ptr<Test> pTst2 = pTst->getThis();

    
    std::cout << pTst2.use_count() << std::endl;

    pTst->tstfunc2();

    QWidget widget;
    widget.resize(QSize(600, 600));
    widget.setWindowTitle("CMake Qt 测试");

    // 使用调色板设置背景色
    QPalette wid_palette;
    wid_palette.setColor(QPalette::Background, QColor(128, 128, 128));
    widget.setAutoFillBackground(true);
    widget.setPalette(wid_palette); // 设置背景色


    QLabel* pLabel = new QLabel("密码：", &widget);
    QLineEdit* pLineEdit = new QLineEdit(&widget);

    // 设置无右键菜单
    pLineEdit->setContextMenuPolicy(Qt::NoContextMenu);
    // 设置无输入时的提示信息
    pLineEdit->setPlaceholderText("请输入密码");
    // 设置密码效果
    pLineEdit->setEchoMode(QLineEdit::Password);
    // 设置最大输入长度
    pLineEdit->setMaxLength(16);

    QHBoxLayout* pHLayout = new QHBoxLayout();
    pHLayout->addWidget(pLabel);
    pHLayout->addWidget(pLineEdit);

    QLineEdit* pLineEdit1 = new QLineEdit(&widget);

    pHLayout->addWidget(pLineEdit1);
    // 设置Tab切换焦点顺序
    widget.setTabOrder(pLineEdit1, pLineEdit);


    CustomLineChart cusLineChart(&widget);

    QChartView *chartView = new QChartView(cusLineChart.createLineChart());

    //QChart::ChartTheme theme = QChart::ChartTheme::ChartThemeBlueIcy;
    //chartView->chart()->setTheme(theme);

    QBrush brush;
    brush.setColor(QColor(0, 0, 0));
    chartView->chart()->setBackgroundBrush(brush);

    chartView->chart()->setBackgroundVisible(false);

    chartView->setRenderHint(QPainter::Antialiasing); // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑



    QVBoxLayout* pvLayout = new QVBoxLayout();
    pvLayout->addLayout(pHLayout);
    pvLayout->addWidget(chartView);

    widget.setLayout(pvLayout);


    //widget.setSizePolicy(Qt::ClickFocus);

    widget.show();



    CustomDialog* pDlg = new CustomDialog(&widget);
    // CustomDialog* pDlg = new CustomDialog();
    pDlg->setWindowTitle("无边框对话框");
    pDlg->setWindowFlags(Qt::FramelessWindowHint);

    pDlg->setWindowFlags(pDlg->windowFlags() | Qt::Tool);

    //pDlg->exec();
    pDlg->show();

    pDlg->hide(); // 先隐藏掉

    app.exec();

    QString sValue = "Hello QString";
    auto ba = sValue.toLatin1();
    printf(ba.data());

    printf("Lu//a\"\n");

    Document document;

    Document::AllocatorType& allocator = document.GetAllocator();
#if 0
    Value contact(kArrayType);
    Value contact2(kArrayType);
    Value root(kArrayType);
    contact.PushBack("Lu//a\"", allocator).PushBack("Mio", allocator).PushBack("", allocator);
    contact2.PushBack("Lu// a", allocator).PushBack("Mio", allocator).PushBack("", allocator);
    root.PushBack(contact, allocator);
    root.PushBack(contact2, allocator);
#endif
    // 初始化DOM
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);

    writer.StartObject();
    {
        writer.String("Key111");
        writer.String("Value");


        writer.String("JsonArray");
        writer.StartArray();
        writer.String("A");
        writer.String("B");
        writer.String("C");
        writer.EndArray();

    }
    writer.EndObject();

    //root.Accept(writer);
    string reststring = buffer.GetString();
    cout << reststring << endl;

    string filePath = "./JsonDemo.Json";
    FILE* file = fopen(filePath.c_str(), "wb");
    if (file)
    {
        fputs(buffer.GetString(), file);
        fclose(file);
    }
    else {
        return -1;
    }


    const char * strJson = "{\"key1\":\"value1\",\"key2\":\"value2\",\"key3\":100}";

    Document doc2;
    doc2.Parse(strJson);

    Value::ConstMemberIterator it = doc2.FindMember("key1");
    if (it == doc2.MemberEnd())
    {
        printf("key1 not found");
        return -1;
    }

    it = doc2.FindMember("key4");
    if (it == doc2.MemberEnd())
    {
        printf("key4 not found");
        return -1;
    }

    Value& v1 = doc2["key1"];

    Type valueType = v1.GetType();
    if (valueType == kStringType)
    {
        string value = v1.GetString();
    }

    return 0;
}
