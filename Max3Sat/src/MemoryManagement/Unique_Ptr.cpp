//
// Author: jakubszwedowicz
// Date: 17.01.2022.
// e-mail: kuba.szwedowicz@gmail.com 
//
#include "Unique_Ptr.hpp"
#include "Max3Sat.hpp"
#include "Population_Overseer.hpp"

template class tep::Unique_Ptr<Problem>;
template class tep::Unique_Ptr<Population_Overseer>;

using namespace tep;

template<typename T>
Unique_Ptr<T>::Unique_Ptr() noexcept
        : m_ptr(nullptr)
{}

template<typename T>
Unique_Ptr<T>::Unique_Ptr(T* a_ptr) noexcept
        : m_ptr(a_ptr)
{}

template<typename T>
Unique_Ptr<T>::Unique_Ptr(Unique_Ptr&& a_ptr) noexcept
        : m_ptr(std::exchange(a_ptr.m_ptr, nullptr))
{}


template<typename T>
Unique_Ptr<T>::~Unique_Ptr() noexcept
{
    reset(nullptr);
}

template<typename T>
void Unique_Ptr<T>::reset(T* a_ptr) noexcept
{
    delete std::exchange(m_ptr, a_ptr);
}

template<typename T>
T* Unique_Ptr<T>::release() noexcept
{
    return std::exchange(m_ptr, nullptr);
}

template<typename T>
void Unique_Ptr<T>::swap(Unique_Ptr& a_other) noexcept
{
    std::swap(m_ptr, a_other.m_ptr);
}

template<typename T>
T* Unique_Ptr<T>::operator->() const noexcept
{
    return m_ptr;
}

template<typename T>
T& Unique_Ptr<T>::operator*() const noexcept
{
    return *m_ptr;
}


