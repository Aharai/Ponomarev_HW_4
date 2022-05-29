// Ponomarev_HW_4.cpp

#include <iostream>
#include <random>
#include <iterator>
#include <vector>
#include <list>
#include <math.h>
#include <algorithm>

using namespace std;

template<template<typename, typename> class TContainer, typename TItem, typename TIterator, typename T>
void generator(TContainer<TItem, TIterator>& c, const T& rangeStart, const T& rangeEnd)
{
    random_device rd;
    mt19937 mersenne(rd());
    uniform_real_distribution<double> urd(rangeStart, rangeEnd);
    generate(c.begin(), c.end(), [&]()
    {
            return urd(mersenne);
    });
}

template<template<typename, typename> class TContainer, typename TItem, typename TIterator>
void print(const TContainer<TItem, TIterator>& c)
{
    copy(c.begin(), c.end(), ostream_iterator<TItem> { cout, " " });
    cout << endl;
}

template<template<typename, typename> class TContainer, typename TItem, typename TIterator>
void insert_sorted(TContainer<TItem, TIterator>& c, const TItem& i)
{
    typename TContainer<TItem, TIterator>::iterator it = find_if(c.begin(), c.end(), [&](const TItem& current)
        {
            return current >= i;
        });
    c.insert(it, i);
}

void task_1()
{
    const size_t size = 10;
    int newIntValue = 5;
    double newDoubleValue = -3.5;

    vector<int> v(size);
    generator(v, -10, 10);
    sort(v.begin(), v.end());
    print(v);
    insert_sorted(v, newIntValue);
    print(v);

    cout << endl;

    list < double> first(size);
    generator(first, -10.0, 10.0);
    first.sort();
    print(first);
    insert_sorted(first, newDoubleValue);
    print(first);

    cout << endl;
}

void task_2()
{
    vector<double> a(100);

    double error = 0;
    generator(a, -1000.0, 1000.0);

    print(a);
    copy(a.begin(), a.end(), ostream_iterator<int> {cout, " "});

    cout << endl;

    for_each(a.begin(), a.end(), [&](const double& i)
    {
        error += pow(i - static_cast<int>(i), 2);
    });

    cout << endl;

    cout << "ERROR!" << error << endl;
}

int main()
{
    task_1();
    task_2();

    return 0;
}
