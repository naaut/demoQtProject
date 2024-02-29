#include "ExampleUsecase.h"

ExampleUsecase::ExampleUsecase(
    interfaces::IExampleInterfaceUnq dataProvider)
    : m_data(std::move(dataProvider))
{
    Q_ASSERT(m_data);
}

int ExampleUsecase::getAnswer() const
{
    return m_data->getSomeData();
}

