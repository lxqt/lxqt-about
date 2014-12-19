cmake_minimum_required(VERSION 2.8.11)
project(lxqt-about)

set(CPP_FILES
    main.cpp
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
include(LXQtTranslateDesktop)
lxqt_translate_desktop(DESKTOP_FILES
    SOURCES
    resources/lxqt-about.desktop.in
)
#************************************************


add_executable(${PROJECT_NAME}
    ${CPP_FILES}
    ${QM_FILES}
    ${DESKTOP_FILES}
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
