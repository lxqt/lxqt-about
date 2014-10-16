cmake_minimum_required(VERSION 2.6)
project(lxqt-about)

set(CPP_FILES
    main.cpp
)

set(H_FILES "")
set(MOC_FILES "")
set(UI_FILES "")
set(QRC_FILES "")

find_package(Qt5Widgets REQUIRED QUIET)
find_package(Qt5DBus REQUIRED QUIET)
find_package(Qt5X11Extras REQUIRED QUIET)
find_package(lxqt-qt5 REQUIRED QUIET)
include(${LXQT_USE_FILE})

qt5_wrap_cpp(MOC_SOURCES ${MOC_FILES})
qt5_wrap_ui(UI_HEADERS ${UI_FILES})
qt5_add_resources(QRC_SOURCES ${QRC_FILES})

set(QTX_LIBRARIES ${Qt5Widgets_LIBRARIES} ${Qt5DBus_LIBRARIES} ${Qt5X11Extras_LIBRARIES})

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${QT_QTCORE_INCLUDE_DIR} ${QT_QTGUI_INCLUDE_DIR}
    ${LXQT_INCLUDE_DIR}
)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(APP_SHARE_DIR share/lxqt/${PROJECT_NAME})

#************************************************


# Translations **********************************
lxqt_translate_desktop(DESKTOP_FILES
    SOURCES
    resources/lxqt-about.desktop.in
)
#************************************************


add_executable(${PROJECT_NAME}
    ${CPP_FILES}
    ${UI_FILES}
    ${RESOURCES}
    ${QRC_SOURCES}
    ${QM_FILES}
    ${MOC_SOURCES}
    ${DESKTOP_FILES}
)
#add_dependencies(${PROJECT_NAME} ${LXQT_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${QTX_LIBRARIES} ${LXQT_LIBRARIES})

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
install(FILES ${CONFIG_FILES} DESTINATION ${APP_SHARE_DIR})
install(FILES ${DESKTOP_FILES} DESTINATION share/applications)

# building tarball with CPack -------------------------------------------------
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_VERSION_MAJOR ${LXQT_MAJOR_VERSION})
set(CPACK_PACKAGE_VERSION_MINOR ${LXQT_MINOR_VERSION})
set(CPACK_PACKAGE_VERSION_PATCH ${LXQT_PATCH_VERSION})
set(CPACK_GENERATOR TBZ2)
set(CPACK_SOURCE_GENERATOR TBZ2)
set(CPACK_SOURCE_IGNORE_FILES /build/;.gitignore;.*~;.git;.kdev4;temp)
include(CPack)
