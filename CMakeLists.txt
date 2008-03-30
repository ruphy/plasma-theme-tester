project(PTT)

find_package(KDE4)
include(KDE4Defaults)

set(PTT_SRC
    main.cpp
    elementpainter.cpp
)

include_directories(${KDE4_INCLUDES})

kde4_add_executable(PTT ${PTT_SRC})
target_link_libraries(PTT ${KDE4_KDEUI_LIBS} plasma)

install(TARGETS PTT DESTINATION ${BIN_INSTALL_DIR})
# install(FILES PTT.desktop DESTINATION ${XDG_APPS_INSTALL_DIR})
install(FILES PTTui.rc  DESTINATION  ${DATA_INSTALL_DIR}/PTT)
