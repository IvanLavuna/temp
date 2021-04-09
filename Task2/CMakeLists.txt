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
set(SOURCE source/main.cpp
        source/IndexedButton.cpp include/IndexedButton.h
           source/MainMenuWidget.cpp     include/MainMenuWidget.h
           source/MainWindow.cpp         include/MainWindow.h
           source/VideoWindowWidget.cpp  include/VideoWindowWidget.h
        source/AudioWindow.cpp include/AudioWindow.h
        source/AudioBar.cpp include/AudioBar.h
           source/AudioManagerWidget.cpp include/AudioManagerWidget.h
           source/AudioDataWidget.cpp    include/AudioDataWidget.h
           source/SearcherWidget.cpp     include/SearcherWidget.h
           source/AudioEngine.cpp        include/AudioEngine.h
           source/AudioFile.cpp          include/AudioFile.h)


include_directories(include source)

add_executable(${PROJECT_NAME} ${SOURCE})

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

target_precompile_headers(${PROJECT_NAME} PUBLIC include/cmake_pch.h)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} -ltag -lz )
