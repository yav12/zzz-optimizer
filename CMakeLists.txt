cmake_minimum_required(VERSION 3.16)

project(zzz-optimizer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        window.cpp
        window.h
        window.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(zzz-optimizer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET zzz-optimizer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(zzz-optimizer SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(zzz-optimizer
            ${PROJECT_SOURCES}
            disc.h disc.cpp
            discrender.h discrender.cpp discrender.ui
            assets/discs/AstralVoice.png assets/discs/BranchBladeSong.png assets/discs/ChaosJazz.png assets/discs/ChaoticMetal.png assets/discs/DawnsBloom.png assets/discs/FangedMetal.png assets/discs/FreedomBlues.png assets/discs/HormonePunk.png assets/discs/InfernoMetal.png assets/discs/KingoftheSummit.png assets/discs/MoonlightLullaby.png assets/discs/PhaethonsMelody.png assets/discs/PolarMetal.png assets/discs/ProtoPunk.png assets/discs/PufferElectro.png assets/discs/ShadowHarmony.png assets/discs/ShockstarDisco.png assets/discs/SoulRock.png assets/discs/SwingJazz.png assets/discs/ThunderMetal.png assets/discs/WoodpeckerElectro.png assets/discs/YunkuiTales.png assets/wengines/anomaly/(MagneticStorm)Alpha.png assets/wengines/anomaly/(MagneticStorm)Bravo.png assets/wengines/anomaly/(MagneticStorm)Charlie.png assets/wengines/anomaly/Electro-LipGloss.png assets/wengines/anomaly/FlamemakerShaker.png assets/wengines/anomaly/FlightofFancy.png assets/wengines/anomaly/FusionCompiler.png assets/wengines/anomaly/HailstormShrine.png assets/wengines/anomaly/PracticedPerfection.png assets/wengines/anomaly/RainforestGourmet.png assets/wengines/anomaly/RoaringRide.png assets/wengines/anomaly/SharpenedStinger.png assets/wengines/anomaly/Timeweaver.png assets/wengines/anomaly/WeepingGemini.png assets/wengines/attack/(Lunar)Decrescent.png assets/wengines/attack/(Lunar)Noviluna.png assets/wengines/attack/(Lunar)Pleniluna.png assets/wengines/attack/BellicoseBlaze.png assets/wengines/attack/CannonRotor.png assets/wengines/attack/CordisGermina.png assets/wengines/attack/DeepSeaVisitor.png assets/wengines/attack/DrillRig-RedAxis.png assets/wengines/attack/GildedBlossom.png assets/wengines/attack/HeartstringNocturne.png assets/wengines/attack/Housekeeper.png assets/wengines/attack/MarcatoDesire.png assets/wengines/attack/MyriadEclipse.png assets/wengines/attack/RiotSuppressorMarkVI.png assets/wengines/attack/SeveredInnocence.png assets/wengines/attack/StarlightEngine.png assets/wengines/attack/StarlightEngineReplica.png assets/wengines/attack/SteelCushion.png assets/wengines/attack/StreetSuperstar.png assets/wengines/attack/TheBrimstone.png assets/wengines/attack/ZanshinHerbCase.png assets/wengines/defense/(Identity)Base.png assets/wengines/defense/(Identity)Inflection.png assets/wengines/defense/BigCylinder.png assets/wengines/defense/BunnyBand.png assets/wengines/defense/OriginalTransmorpher.png assets/wengines/defense/Peacekeeper-Specialized.png assets/wengines/defense/ReelProjector.png assets/wengines/defense/SpringEmbrace.png assets/wengines/defense/TremorTrigramVessel.png assets/wengines/defense/TusksofFury.png assets/wengines/rupture/(Cinder)Cobalt.png assets/wengines/rupture/PuzzleSphere.png assets/wengines/rupture/QingmingBirdcage.png assets/wengines/rupture/RadiowaveJourney.png assets/wengines/stun/(Vortex)Arrow.png assets/wengines/stun/(Vortex)Hatchet.png assets/wengines/stun/(Vortex)Revolver.png assets/wengines/stun/BlazingLaurel.png assets/wengines/stun/BoxCutter.png assets/wengines/stun/DemaraBatteryMarkII.png assets/wengines/stun/HellfireGears.png assets/wengines/stun/Ice-JadeTeapot.png assets/wengines/stun/PreciousFossilizedCore.png assets/wengines/stun/RoaringFur-nace.png assets/wengines/stun/SixShooter.png assets/wengines/stun/SpectralGaze.png assets/wengines/stun/SteamOven.png assets/wengines/stun/TheRestrained.png assets/wengines/support/(Reverb)MarkI.png assets/wengines/support/(Reverb)MarkII.png assets/wengines/support/(Reverb)MarkIII.png assets/wengines/support/BashfulDemon.png assets/wengines/support/ElegantVanity.png assets/wengines/support/KaboomtheCannon.png assets/wengines/support/Metanukimorphosis.png assets/wengines/support/SliceofTime.png assets/wengines/support/TheVault.png assets/wengines/support/UnfetteredGameBall.png assets/wengines/support/WeepingCradle.png
        )
    endif()
endif()

target_link_libraries(zzz-optimizer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.zzz-optimizer)
endif()
set_target_properties(zzz-optimizer PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS zzz-optimizer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(zzz-optimizer)
endif()
