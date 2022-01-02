// RapidJson_Demo_CMake.h

#ifndef RAPIDJSON_DEMO_CMAKE
#define RAPIDJSON_DEMO_CMAKE

#include <iostream>
#include <memory>

class Test : public std::enable_shared_from_this<Test>
{
public:
    Test()
    {

    }

    std::shared_ptr<Test> getThis()
    {
        return shared_from_this();
    }

    ~Test()
    {
        std::cout << "~Test()" << std::endl;
    }

    void tstFunc(std::shared_ptr<Test> pTst)
    {
        
    }

    void tstfunc2()
    {
        //tstFunc(shared_from_this());
    }



};


class Widget {
public:
    Widget() {
        std::cout << "Widget constructor run" << std::endl;
    }
    ~Widget() {
        std::cout << "Widget destructor run" << std::endl;
    }

    std::shared_ptr<Widget> GetSharedObject() {
        return std::shared_ptr<Widget>(this);
    }
};




// TODO: 在此处引用程序需要的其他标头。
#endif // !RAPIDJSON_DEMO_CMAKE
