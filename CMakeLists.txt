cmake_minimum_required(VERSION 2.8.11)
project(lxqt-about)

option(UPDATE_TRANSLATIONS "Update source translation translations/*.ts files" OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CPP_FILES
    aboutdialog/lxqtaboutdialog.cpp
    aboutdialog/technicalinfo.cpp
    translatorsinfo/translatorsinfo.cpp
    main.cpp
)

set(UI_FILES
    aboutdialog/lxqtaboutdialog.ui
)

find_package(Qt5Widgets REQUIRED QUIET)
find_package(Qt5DBus REQUIRED QUIET)
find_package(Qt5X11Extras REQUIRED QUIET)
find_package(lxqt REQUIRED QUIET)
include(${LXQT_USE_FILE})

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${LXQT_INCLUDE_DIR}
)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(APP_SHARE_DIR share/lxqt/${PROJECT_NAME})

# Translations **********************************
include(LXQtTranslate)

lxqt_translate_ts(QM_FILES
    UPDATE_TRANSLATIONS ${UPDATE_TRANSLATIONS}
    SOURCES
        ${H_FILES}
        ${CPP_FILES}
        ${UI_FILES}
    INSTALL_DIR
        "${LXQT_TRANSLATIONS_DIR}/${PROJECT_NAME}"
)

lxqt_app_translation_loader(QM_LOADER ${PROJECT_NAME})

lxqt_translate_desktop(DESKTOP_FILES
    SOURCES
    resources/lxqt-about.desktop.in
)
#************************************************

include(translatorsinfo/CMakeLists.txt)
get_translatorsinfo_qrc(translatorsinfo_qrc)
qt5_add_resources(QRC_CXX_SOURCES ${translatorsinfo_qrc})
qt5_wrap_ui(UICS ${UI_FILES})

add_executable(${PROJECT_NAME}
    ${CPP_FILES}
    ${UICS}
    ${QM_FILES}
    ${DESKTOP_FILES}
    ${QRC_CXX_SOURCES}
    ${QM_LOADER}

)

target_link_libraries(${PROJECT_NAME}
    Qt5::Widgets
    Qt5::DBus
    Qt5::X11Extras
    ${LXQT_LIBRARIES}
)

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
