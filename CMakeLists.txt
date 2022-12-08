cmake_minimum_required(VERSION 3.5)

project(OpenDrip VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

find_package(Qt6 REQUIRED COMPONENTS Network)


set(PROJECT_SOURCES
        main.cpp
        opendrip.cpp
        opendrip.h
        opendrip.ui
        weatherinterface.h
        weatherinterface.cpp
        userrequest.h
        userrequest.cpp
        weatherData.h
        weatherData.cpp
        dataservice.h
        dataservice.cpp
        userinterfacing.h
        userinterfacing.cpp
        humidityservice.h
        humidityservice.cpp
        windspeedservice.h
        windspeedservice.cpp
        temperatureservice.h
        temperatureservice.cpp
        cloudcoverageservice.h
        cloudcoverageservice.cpp
        precipitationService.cpp
        precipitationService.h
        displayprecipitation.h
        displayprecipitation.cpp
        displayhumidity.h
        displayhumidity.cpp
        displayoutfit.h
        displayoutfit.cpp
        displaywindspeed.h
        displaywindspeed.cpp
        displayequipment.h
        displayequipment.cpp
        displaycloudcoverage.h
        displaycloudcoverage.cpp
        displaytemperature.h
        displaytemperature.cpp
        factory.h
        factory.cpp
        computation.h
        computation.cpp

        outfitService.cpp
        outfitService.h
        equipmentservice.h
        equipmentservice.cpp


        display4daysdatastate.h
        display4daysdatastate.cpp
        display24hoursdatastate.h
        display24hoursdatastate.cpp
        displaycurrentdatastate.h
        displaycurrentdatastate.cpp
        displaystate.h
        displaystate.cpp
        dataservicestate.h
        dataservicestate.cpp
        twentyfourhoursdataservicestate.h
        twentyfourhoursdataservicestate.cpp
        fourdaydataservicestate.h
        fourdaydataservicestate.cpp
        currentdataservicestate.h
        currentdataservicestate.cpp


)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(OpenDrip
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET OpenDrip APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(OpenDrip SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(OpenDrip
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(OpenDrip PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(OpenDrip PRIVATE Qt6::Network)

set_target_properties(OpenDrip PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS OpenDrip
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(OpenDrip)
endif()
