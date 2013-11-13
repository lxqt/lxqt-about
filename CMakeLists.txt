cmake_minimum_required( VERSION 2.6 )
project(lxqt-about)

set(H_FILES
)

set(MOC_FILES
)

set(CPP_FILES
    main.cpp
)


set(UI_FILES
)

set(QRC_FILES

)

cmake_minimum_required( VERSION 2.6 )

find_package(LXQT REQUIRED QUIET)
include(${LXQT_USE_FILE})

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)


if(NOT CMAKE_BUILD_TYPE)
    set( CMAKE_BUILD_TYPE Release )
endif (NOT CMAKE_BUILD_TYPE)

set(APP_SHARE_DIR share/lxqt/${PROJECT_NAME})

#************************************************


qt4_wrap_cpp(MOC_SOURCES ${MOC_FILES})
qt4_wrap_ui(UI_HEADERS ${UI_FILES})
qt4_add_resources(QRC_SOURCES ${QRC_FILES})
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
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES} ${LXQT_LIBRARIES})

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
install(FILES   ${CONFIG_FILES}    DESTINATION ${APP_SHARE_DIR})
install(FILES   ${DESKTOP_FILES}   DESTINATION share/applications)
