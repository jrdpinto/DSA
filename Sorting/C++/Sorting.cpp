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

template<typename T>
void SelectionSort(std::vector<T>& elements) 
{
    size_t length = elements.size();
    for (int i = 0; i < length - 1; ++i)
    {
        int minIndex = i;

        for (int j = i + 1; j < length; ++j) 
        {
            if (elements[j] < elements[minIndex]) 
            {
                minIndex = j;
            }
        }

        if (minIndex != i) 
        {
            std::swap(elements[i], elements[minIndex]);
        }
    }
}

template<typename T>
void InsertionSort(std::vector<T>& arr) 
{
    for (int i = 1; i < arr.size(); ++i) 
    {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

template<typename T>
std::vector<T> Merge(std::vector<T>& left, std::vector<T>& right)
{
    std::vector<T> merged;

    size_t i = 0, j = 0;
    while(i < left.size() && j < right.size())
    {
        T leftValue = left[i];
        T rightValue = right[j];
        if (leftValue < rightValue)
        {
            merged.push_back(leftValue);
            ++i;
        }
        else
        {
            merged.push_back(rightValue);
            ++j;
        }
    }

    if (i < left.size())
    {
        merged.insert(merged.end(), left.begin()+i, left.end());
    }
    else if (j < right.size())
    {
        merged.insert(merged.end(), right.begin()+j, right.end());
    }

    return merged;
}

template<typename T>
std::vector<T> MergeSort(std::vector<T>& arr)
{
    size_t size = arr.size();
    if (size < 2)
    {
        return arr;
    }

    size_t middle = size/2.f;
    auto middleIt = arr.begin()+middle;
    std::vector<T> left(arr.begin(), middleIt);
    std::vector<T> right(middleIt, arr.end());

    left = MergeSort(left);
    right = MergeSort(right);

    return Merge(left, right);
}

template <typename T>
void SortingTest(std::function<void(std::vector<T>&)> sortFn, const std::vector<T>& numbers, 
    bool printList = false)
{
    std::vector<T> numbersCopy = numbers;

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
typename std::enable_if<std::is_arithmetic<T>::value, std::vector<T>>::type GenerateRandomNumbers(size_t count)
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
    std::vector<int> numbers = GenerateRandomNumbers<int>(10000);

    std::cout << "Bubble Sort: " << std::endl;
    SortingTest<int>(BubbleSort<int>, numbers);
    std::cout << std::endl;

    std::cout << "Selection Sort: " << std::endl;
    SortingTest<int>(SelectionSort<int>, numbers);
    std::cout << std::endl;

    std::cout << "Insertion Sort: " << std::endl;
    SortingTest<int>(InsertionSort<int>, numbers);
    std::cout << std::endl;

    std::cout << "Merge Sort: " << std::endl;
    SortingTest<int>(MergeSort<int>, numbers);
    std::cout << std::endl;

    return 0;
}