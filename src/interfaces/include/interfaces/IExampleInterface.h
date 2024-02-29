#pragma once

#include <memory>

namespace interfaces
{

struct IExampleInterface
{
    virtual ~IExampleInterface() = default;
    [[nodiscard]] virtual int getSomeData() = 0;
};

using IExampleInterfaceUnq = std::unique_ptr<IExampleInterface>;

} // namespace interfaces
