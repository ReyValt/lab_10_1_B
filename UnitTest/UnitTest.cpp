#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_10_1_B/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:
        TEST_METHOD(TestCreate)
        {
            const int N = 3;
            Student* students = new Student[N];

            students[0].major = ���������_�����;
            students[1].major = �����������;
            students[2].major = Գ����_��_�����������;

            Assert::AreEqual(0, static_cast<int>(students[0].major));
            Assert::AreEqual(1, static_cast<int>(students[1].major));
            Assert::AreEqual(3, static_cast<int>(students[2].major));

            delete[] students;
        }

        TEST_METHOD(TestCountPhysics)
        {
            const int N = 3;
            Student p[N] = {
                { "������", 1, ���������_�����, 4, 5, 4 },
                { "������", 2, �����������, 3, 4, 5 },
                { "�������", 3, Գ����_��_�����������, 5, 5, 5 }
            };
            int count = CountPhysics(p, N);
            Assert::AreEqual(2, count);
        }
        TEST_METHOD(TestCalculateAverages)
        {
            const int N = 3;
            Student p[N] = {
                { "������", 1, ���������_�����, 4, 5, 4 },
                { "������", 2, �����������, 3, 4, 5 },
                { "�������", 3, Գ����_��_�����������, 5, 5, 5 }
            };

            std::stringstream buffer;
            std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

            CalculateAverages(p, N);

            std::string output = buffer.str();
            Assert::IsTrue(output.find("������� ��� � ����������: 4.66667") != std::string::npos);

            std::cout.rdbuf(old);
        }

    };
}