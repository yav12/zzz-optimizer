cmake_minimum_required(VERSION 3.19)
project(zzz-optimizer LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

qt_add_executable(zzz-optimizer
    WIN32 MACOSX_BUNDLE
    main.cpp
    window.cpp
    window.h
    resources.qrc



    test.h test.cpp test.ui

    character.h character.cpp
    library.cpp
    navigation.cpp
    home.cpp
    calc.cpp
    reference.cpp
    calculator.h calculator.cpp
    wengine.h wengine.cpp


)

target_link_libraries(zzz-optimizer
    PRIVATE
        Qt::Core
        Qt::Widgets
)
target_link_libraries(zzz-optimizer PRIVATE Qt6::Widgets)
target_link_libraries(zzz-optimizer PRIVATE Qt6::Widgets)
target_link_libraries(zzz-optimizer PRIVATE Qt6::Widgets)
target_link_libraries(zzz-optimizer PRIVATE Qt6::Widgets)

include(GNUInstallDirs)

install(TARGETS zzz-optimizer
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET zzz-optimizer
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
