cmake_minimum_required(VERSION 3.16)

project(Music-cmake VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#查找Qt库
# 查找 Qt 模块时明确指定 Qt 版本
find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets Sql Core Gui Multimedia)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql Core Gui Multimedia)
file(GLOB UI_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/froms/*.ui)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_SOURCE_FILES)
set(QRC_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/sources/res.qrc)
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Music-cmake
        MANUAL_FINALIZATION
        ${SRC_SOURCE_FILES}
        ${UI_SOURCE_FILES}
        ${QRC_SOURCE_FILES}
        include/mainwindow.h
        include/musicsql.h
        include/musicplay.h
        include/songsinfo.h
        include/LoadFileQss.h
        include/musicplayerthread.h
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Music-cmake APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Music-cmake SHARED
          ${SRC_SOURCE_FILES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Music-cmake
          ${SRC_SOURCE_FILES}
        )
    endif()
endif()
#链接Qt库
target_include_directories(Music-cmake PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(Music-cmake PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt6::Core
    Qt6::Gui
    Qt6::Sql
    Qt6::Multimedia)

#将数据库文件从源目录复制到构建项目
set(DATA_DIR ${CMAKE_SOURCE_DIR}/data)
set(SQLITE_DB_FILE ${DATA_DIR}/music.db)
#如果数据库文件存在,复制到构建目录
if(EXISTS ${SQLITE_DB_FILE})
    configure_file(${SQLITE_DB_FILE} ${CMAKE_BINARY_DIR}/music.db COPYONLY)
else()
    message(WARNING "Database file not found!")
endif()

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Music-cmake)
endif()
set_target_properties(Music-cmake PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Music-cmake
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Music-cmake)
endif()
