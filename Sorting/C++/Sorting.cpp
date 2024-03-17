#include <iostream>
#include <functional>
#include <vector>
#include <chrono>

template <typename T>
void PrintList(const std::vector<T>& list)
{
    for (auto number : list)
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void BubbleSort(std::vector<T>& elements)
{
    for (size_t i = 0; i < elements.size(); ++i)
    {
        for (size_t j = 0; j < elements.size() - 1; ++j)
        {
            if (elements[j] > elements[j + 1])
            {
                std::swap(elements[j], elements[j + 1]);
            }
        }
    }
}

template <typename T>
void SortingTest(std::function<void(std::vector<T>&)> sortFn, const std::vector<T>& numbers, 
    bool printList = false)
{
    std::vector<int> numbersCopy = numbers;

    if (printList)
    {
        std::cout << "Unsorted list: ";
        PrintList(numbersCopy);
    }

    using namespace std::chrono;
    std::cout << "Sorting " << numbersCopy.size() << " elements. " << std::endl;

    steady_clock::time_point begin = steady_clock::now();
    sortFn(numbersCopy);
    steady_clock::time_point end = steady_clock::now();
    duration<double> timeSpan = duration_cast<duration<double>>(end - begin);

    std::cout << "Time taken: " << timeSpan.count() << " seconds" << std::endl;

    if (printList)
    {
        std::cout << "Sorted list: ";
        PrintList(numbersCopy);
    }
}

template <typename T>
std::vector<T> GenerateRandomNumbers(size_t count)
{
    std::vector<T> numbers;
    for (size_t i = 0; i < count; ++i)
    {
        numbers.push_back(rand());
    }

    return numbers;
}

int main()
{
    std::vector<int> numbers = GenerateRandomNumbers<int>(1000);

    std::cout << "Bubble Sort: " << std::endl;
    SortingTest<int>(BubbleSort<int>, numbers);

    return 0;
}