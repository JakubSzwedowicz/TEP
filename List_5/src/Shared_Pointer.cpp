//
// Author: jakubszwedowicz
// Date: 16.12.2021.
// e-mail: kuba.szwedowicz@gmail.com 
//

#include <algorithm>
#include "Shared_Pointer.hpp"
#include "Control_Block.hpp"


using namespace tep;

template
class tep::Shared_Ptr<int>;

template<class T>
Shared_Ptr<T>::Shared_Ptr()
        : m_control_block(nullptr), m_ptr(nullptr)
{

}

template<class T>
Shared_Ptr<T>::Shared_Ptr(T* a_ptr)
{
    m_ptr = a_ptr;
    m_control_block = new Control_Block();
    m_control_block->increment();
}

template<class T>
Shared_Ptr<T>::Shared_Ptr(const Shared_Ptr<T>& a_shared_ptr)
{
    m_ptr = a_shared_ptr.m_ptr;
    m_control_block = a_shared_ptr.m_control_block;
    m_control_block->increment();
}

template<class T>
Shared_Ptr<T>::Shared_Ptr(Shared_Ptr<T>&& a_shared_ptr)
        : m_ptr(std::exchange(a_shared_ptr.m_ptr, nullptr)),
        m_control_block(std::exchange(a_shared_ptr.m_control_block, nullptr))
{

}

template<class T>
Shared_Ptr<T>::~Shared_Ptr()
{
    dealocate_resources();
}

template<class T>
Shared_Ptr<T>& Shared_Ptr<T>::operator=(const Shared_Ptr<T>& a_other)
{
    m_control_block = a_other.m_control_block;
    m_control_block->increment();
    m_ptr = a_other.m_ptr;
    return *this;
}

template<class T>
Shared_Ptr<T>& Shared_Ptr<T>::operator=(Shared_Ptr&& a_other)
{
    m_control_block = std::exchange(a_other.m_control_block, nullptr);
    m_ptr = std::exchange(a_other.m_ptr, nullptr);
}

template<class T>
T& Shared_Ptr<T>::operator*()
{
    return *m_ptr;
}

template<class T>
T* Shared_Ptr<T>::operator->()
{
    return m_ptr;
}


template<class T>
void Shared_Ptr<T>::dealocate_resources()
{
    if (m_control_block != nullptr)
    {
        m_control_block->decrement();
        if (!m_control_block->is_valid())
        {
            delete m_control_block;
            delete m_ptr;
        }
    }
}

template<class T>
void Shared_Ptr<T>::reset(T* a_ptr)
{
    dealocate_resources();
    m_control_block = new Control_Block();
    m_control_block->increment();
    m_ptr = a_ptr;
}

