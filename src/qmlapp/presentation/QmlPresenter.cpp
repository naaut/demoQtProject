#include "QmlPresenter.h"

QmlPresenter::QmlPresenter(ExampleUsecaseUnq usecase)
	: QObject()
    , m_usecase(std::move(usecase))
{
    Q_ASSERT(m_usecase);
}

int QmlPresenter::getAnswer() const
{
    return m_usecase->getAnswer();
}

