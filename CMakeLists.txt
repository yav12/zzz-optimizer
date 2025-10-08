cmake_minimum_required(VERSION 3.19)
project(zzz-optimizer LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(zzz-optimizer
    WIN32 MACOSX_BUNDLE
    main.cpp
    window.cpp
    window.h
    window.ui
    resources.qrc
    disc.h disc.cpp
    discrender.h discrender.cpp discrender.ui
)

target_link_libraries(zzz-optimizer
    PRIVATE
        Qt::Core
        Qt::Widgets
)

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
