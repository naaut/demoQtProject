#pragma once

#include <usecase/ExampleUsecase.h>

#include <QtCore/QObject>

// Presenters should only provide data to QML
// there should be no business logic here.

class QmlPresenter : public QObject
{
	Q_OBJECT
    Q_PROPERTY(int answer READ getAnswer CONSTANT FINAL)

public:
    explicit QmlPresenter(ExampleUsecaseUnq usecase);

    int getAnswer() const;

private:
    ExampleUsecaseUnq m_usecase;
};

using QmlPresenterUnq = std::unique_ptr<QmlPresenter>;
