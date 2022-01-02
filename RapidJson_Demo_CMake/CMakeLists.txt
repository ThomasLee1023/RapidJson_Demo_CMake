# CMakeList.txt: RapidJson_Demo_CMake 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

set( HEADER
    RapidJson_Demo_CMake.h
    ./CustomDialog/CustomDialog.h
    ./delegate/CustomizedDelegate.h
    ./model/CustomizedModel.h
	./CustomLineChart/CustomLineChart.h)
set( SOURCECODE
    RapidJson_Demo_CMake.cpp
    ./CustomDialog/CustomDialog.cpp
    ./delegate/CustomizedDelegate.cpp
    ./model/CustomizedModel.cpp
	./CustomLineChart/CustomLineChart.cpp)



set(CMAKE_AUTOMOC ON)

if(CMAKE_BUILD_TYPE=Debug)
    set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/Bin/Debug) #设置exe生成路径
else()
    set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/Bin/Release)
endif()


add_executable (RapidJson_Demo_CMake ${SOURCECODE} ${HEADER})

# 将源代码添加到此项目的可执行文件。
#add_executable (RapidJson_Demo_CMake "RapidJson_Demo_CMake.cpp" "RapidJson_Demo_CMake.h")

# 添加头文件包含路径
include_directories("../../../Third_Part_Source/rapidjson-master/include")

find_package(Qt5 COMPONENTS Core Widgets Charts)

target_link_libraries(RapidJson_Demo_CMake Qt5::Core Qt5::Widgets Qt5::Charts)

# TODO: 如有需要，请添加测试并安装目标。
