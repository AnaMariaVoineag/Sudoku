#include "InitClass.h"
#include <QQmlComponent>
#include <iostream>

InitClass::InitClass(QQmlApplicationEngine *engine) : QObject(), engine(engine)
{

}

void InitClass::howToPlayWindow()
{
    QQmlComponent component(this->engine);
    component.loadUrl(QUrl(QStringLiteral("qrc:/UI/screens/HowToPlayWindow.qml")));

    if(component.isReady())
    {
        component.create();
    } else {
        std::cout << "Error loading window: " << component.errorString().toStdString() << std::endl;
    }

}

void InitClass:: registerWindow()
{
    QQmlComponent component(this->engine);
    component.loadUrl(QUrl(QStringLiteral("qrc:/UI/screens/Register.qml")));

    if(component.isReady())
    {
        component.create();
    } else {
        std::cout << "Error loading window: " << component.errorString().toStdString() << std::endl;
    }

}

void InitClass::mainMenu()
{
    QQmlComponent component(this->engine);
    component.loadUrl(QUrl(QStringLiteral("qrc:/main.qml")));

    if(component.isReady())
    {
        component.create();
    } else {
        std::cout << "Error loading window: " << component.errorString().toStdString() << std::endl;
    }
}







