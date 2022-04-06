//
// Author: jakubszwedowicz
// Date: 17.01.2022.
// e-mail: kuba.szwedowicz@gmail.com 
//

#ifndef LIST_5_UNIQUE_PTR_HPP
#define LIST_5_UNIQUE_PTR_HPP
#include <memory>
namespace tep
{
    template<typename T>
    class Unique_Ptr
    {
    public:
        // CTOR
        Unique_Ptr() noexcept;
        Unique_Ptr(T* a_ptr) noexcept;
        Unique_Ptr(const Unique_Ptr&) = delete;
        Unique_Ptr(Unique_Ptr&& a_ptr) noexcept;
        ~Unique_Ptr() noexcept;

        // OPERATORS
        Unique_Ptr& operator=(const Unique_Ptr&) = delete;
        Unique_Ptr& operator=(Unique_Ptr&&) = delete;
        T* operator->() const noexcept;
        T& operator*() const noexcept;

        // FUNCTIONS
        void reset(const T& a_ptr) noexcept;
        T& release() noexcept;
        void swap(const Unique_Ptr&) noexcept;

    private:
        T m_ptr;
    };
}
#endif //LIST_5_UNIQUE_PTR_HPP
