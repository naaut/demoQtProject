#include <data/ExampleInterfaceImpl.h>

#include <QtTest/QtTest>

#include <memory>

using namespace data;
using ExampleInterfaceImplUnq = std::unique_ptr<ExampleInterfaceImpl>;


class ExampleDataTest : public QObject
{
	Q_OBJECT

public:
    ExampleInterfaceImplUnq getDataProvider();

private slots:
    void TestDataProvider();
};

ExampleInterfaceImplUnq ExampleDataTest::getDataProvider()
{
    return std::make_unique<ExampleInterfaceImpl>(ExampleInterfaceImpl());
}

void ExampleDataTest::TestDataProvider()
{
    auto dataProvider = getDataProvider();
    QVERIFY(dataProvider);
    QCOMPARE(dataProvider->getSomeData(), 42);

}

QTEST_MAIN(ExampleDataTest)

#include "test_ExampleInterfaceImpl.moc"
