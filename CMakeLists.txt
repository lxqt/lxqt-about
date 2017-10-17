cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)
project(lxqt-about)

option(UPDATE_TRANSLATIONS "Update source translation translations/*.ts files" OFF)

include(GNUInstallDirs)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
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

find_package(lxqt REQUIRED)

include(LXQtCompilerSettings NO_POLICY_SCOPE)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

## Patch Version
set(LXQT_ABOUT_PATCH_VERSION 0)

set(LXQT_ABOUT_VERSION ${LXQT_MAJOR_VERSION}.${LXQT_MINOR_VERSION}.${LXQT_ABOUT_PATCH_VERSION})
add_definitions("-DLXQT_ABOUT_VERSION=\"${LXQT_ABOUT_VERSION}\"")

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
    PULL_TRANSLATIONS
        ${PULL_TRANSLATIONS}
    CLEAN_TRANSLATIONS
        ${CLEAN_TRANSLATIONS}
    TRANSLATIONS_REPO
        ${TRANSLATIONS_REPO}
    TRANSLATIONS_REFSPEC
        ${TRANSLATIONS_REFSPEC}
)

lxqt_app_translation_loader(QM_LOADER ${PROJECT_NAME})

lxqt_translate_desktop(DESKTOP_FILES
    SOURCES
    resources/lxqt-about.desktop.in
)
#************************************************

include(translatorsinfo/CMakeLists.txt)
get_translatorsinfo_qrc(translatorsinfo_qrc)

add_executable(${PROJECT_NAME}
    ${CPP_FILES}
    ${QM_FILES}
    ${DESKTOP_FILES}
    ${translatorsinfo_qrc}
    ${QM_LOADER}

)

target_link_libraries(${PROJECT_NAME}
    lxqt
)

install(TARGETS
    ${PROJECT_NAME}
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    COMPONENT Runtime
)
install(FILES
    ${DESKTOP_FILES}
    DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/applications"
    COMPONENT Runtime
)
