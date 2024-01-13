#include "Game.h"
#include "Grid.h"
#include "Music.h"
#include <QIcon>
#include <QQmlContext>


Game::Game(int argc, char *argv[]) : QGuiApplication(argc, argv),
    engine(new QQmlApplicationEngine), objectClass(engine)
{
    setWindowIcon(QIcon(":/UI/assets/icon.png"));

    Music *mp3Player = new Music();

    qmlRegisterSingletonType(QStringLiteral("qrc:/UI/screens/AppStyle.qml"),"AppStyle",1,0,"AppStyle");
    qmlRegisterSingletonType(QStringLiteral("qrc:/UI/screens/FontStyle.qml"),"AppStyle",1,0,"FontStyle");

    qmlRegisterType<Grid>("SudokuGrid", 1, 0, "SudokuGrid");

    const QUrl url(u"qrc:/main.qml"_qs);
    QObject::connect(
        engine,
        &QQmlApplicationEngine::objectCreated,
        this,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine->load(url);

    QQmlContext *rootContext = engine->rootContext();

    rootContext->setContextProperty("classA", &objectClass);
    rootContext->setContextProperty("classB", mp3Player);



}

Game::~Game()
{
    delete engine;

}

int Game::run()
{
    return exec();
}
