set(QT_NO_STANDARD_PROJECT_SETUP ON)

find_package(Qt6 6.5 REQUIRED
    COMPONENTS
        Core
        Gui
        Qml
        Quick
)


qt_standard_project_setup()

qt_add_executable(appQmlInjectorCore
    main.cpp
    presentation/QmlPresenter.h
    presentation/QmlPresenter.cpp
    usecase/ExampleUsecase.h
    usecase/ExampleUsecase.cpp
)

qt_add_qml_module(appQmlInjectorCore
    URI QmlInjectorCore
    VERSION 1.0
    RESOURCE_PREFIX /
    RESOURCES
)

qt_target_qml_sources(appQmlInjectorCore
    QML_FILES
    qml/main.qml
    qml/BaseInjectorPage.qml
)

target_link_libraries(appQmlInjectorCore
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
        Qt6::Quick
        qmlinjector
        interfaces
        data
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appQmlInjectorCore PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appQmlInjectorCore
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appQmlInjectorCore
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appQmlInjectorCore
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
