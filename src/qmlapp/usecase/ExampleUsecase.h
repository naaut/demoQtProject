#pragma once

#include <interfaces/IExampleInterface.h>

#include <QtCore/QObject>

#include <memory>

// In usecases, all the business logic needs to be accumulated,
// as it may be the most frequently changed part of the application.

class ExampleUsecase : public QObject
{
    Q_OBJECT

public:
    explicit ExampleUsecase(
        interfaces::IExampleInterfaceUnq dataProvider);

    int getAnswer() const;

private:
    interfaces::IExampleInterfaceUnq m_data;
};

using ExampleUsecaseUnq = std::unique_ptr<ExampleUsecase>;
