cmake_minimum_required(VERSION 3.17)
project(MediaPlayerApp)

set(CMAKE_CXX_STANDARD 14)
set(QT_VERSION 5)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set (CMAKE_INCLUDE_CURRENT_DIR ON)

set(REQUIRED_LIBS Core Gui Widgets Multimedia MultimediaWidgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Multimedia Qt5::MultimediaWidgets)
set(SOURCE source/main.cpp source/AudioWindow.cpp include/AudioWindow.h
                           source/ScrollArea.cpp include/ScrollArea.h
                            source/ScrollButton.cpp include/ScrollButton.h)

include_directories(include source)

add_executable(${PROJECT_NAME} ${SOURCE})

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

target_precompile_headers(${PROJECT_NAME} PUBLIC include/cmake_pch.h)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
