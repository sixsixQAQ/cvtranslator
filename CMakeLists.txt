cmake_minimum_required(VERSION 3.20)
project(CVTranslator LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

## 设置Qt库安装路径
set(QT_PATH "E:/Qt/6.5.3/msvc2019_64")
set(CMAKE_PREFIX_PATH ${QT_PATH})

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets StateMachine)

add_executable(${PROJECT_NAME}
        main.cpp
        WorkWindow.cpp
        WorkWindow.h
        WorkWindow.ui
        "WinMouseEventPublisher.cpp"
        "WinMouseEventPublisher.h"
 "GlobalMouseEvent.h")
set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE FALSE)
target_link_libraries(${PROJECT_NAME} PUBLIC
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::StateMachine
)


## 自动调用windeployqt找齐运行所需的dll
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND "${QT_PATH}/bin/windeployqt.exe" --dir "${CMAKE_CURRENT_BINARY_DIR}" "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.exe"
)
