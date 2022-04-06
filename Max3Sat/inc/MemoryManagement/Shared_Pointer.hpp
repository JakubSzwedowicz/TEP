//
// Author: jakubszwedowicz
// Date: 16.12.2021.
// e-mail: kuba.szwedowicz@gmail.com 
//

#ifndef LIST_5_SHARED_POINTER_HPP
#define LIST_5_SHARED_POINTER_HPP


namespace  tep
{
    class Control_Block;

    template <class T>
    class Shared_Ptr
    {
    public:
        Shared_Ptr();
        explicit Shared_Ptr(T* a_ptr);
        Shared_Ptr(const Shared_Ptr& a_ptr);
        Shared_Ptr(Shared_Ptr&& a_ptr);
        ~Shared_Ptr();

        Shared_Ptr& operator=(const Shared_Ptr& a_other);
        Shared_Ptr& operator=(Shared_Ptr&& a_other);
        T& operator*();
        T* operator->();

        void reset(T* a_ptr);
    private:
        void dealocate_resources();
        Control_Block* m_control_block;
        T* m_ptr;
    };
}
#endif //LIST_5_SHARED_POINTER_HPP
