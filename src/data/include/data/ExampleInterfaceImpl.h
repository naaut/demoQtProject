#pragma once

#include <interfaces/IExampleInterface.h>

namespace data
{

class ExampleInterfaceImpl : public interfaces::IExampleInterface
{
public:
    // IExampleInterface interface
    [[nodiscard]] virtual int getSomeData() override;

};

} // namespace data
