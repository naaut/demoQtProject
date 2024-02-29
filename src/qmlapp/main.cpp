#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "presentation/QmlPresenter.h"
#include "usecase/ExampleUsecase.h"

#include <qmlinjector/qmlinjector.h>
#include <qmlinjector/qmlinjectorbuilder.h>

#include <interfaces/IExampleInterface.h>
#include <data/ExampleInterfaceImpl.h>


#include "di/di.hpp"

namespace di = boost::di;

const char * const qmlPath = "qrc:/QmlInjectorCore/qml/main.qml";

int main(int argc, char *argv[])
{
    const auto injector = di::make_injector(
            di::bind<interfaces::IExampleInterface>.to<data::ExampleInterfaceImpl>(),
            di::bind<ExampleUsecase>.to<ExampleUsecase>()
        );

    QmlInjectorBuilder builder;

    builder.add<QmlPresenter>(
        [&injector](const QVariant &)
        {
            return injector.create<QmlPresenterUnq>();
        });

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<QmlInjector>("injector", 1, 0, "QmlInjector");

    engine.rootContext()->setContextObject(builder.build());
    engine.rootContext()->setContextProperty("$QmlEngine", &engine);

    app.setOrganizationName("sednev");
    app.setOrganizationDomain("net");

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(qmlPath);

    return app.exec();
}
