cmake_minimum_required(VERSION 3.19)
set(CMAKE_TOOLCHAIN_FILE "/home/kwame/Documents/GitHub/vcpkg/scripts/buildsystems/vcpkg.cmake")
project(zzz-optimizer LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
find_package(PcapPlusPlus CONFIG REQUIRED)
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

    navigation.cpp
    home.cpp

    test.h test.cpp test.ui

    data/wengine.h data/wengine.cpp
    data/character.h data/character.cpp
    data/disc.h data/disc.cpp

    calculations/calc.h calculations/calc.cpp

    content/reference.cpp content/reference.h
    content/calculator.h content/calculator.cpp
    content/library.cpp

    selectors/charselector.h selectors/charselector.cpp
    selectors/discselector.h selectors/discselector.cpp
    selectors/wengineselector.h selectors/wengineselector.cpp

    import/scanner.h import/scanner.cpp

)

target_link_libraries(zzz-optimizer
    PRIVATE
        Qt::Core
        Qt::Widgets
        PCAP::PCAP
        PcapPlusPlus::Pcap++
        PcapPlusPlus::Common++
        PcapPlusPlus::Packet++
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
