//
// Created by JakubSzwedowicz on 18.11.2021.
//

#ifndef LIST_1_INODE_STATIC_HPP
#define LIST_1_INODE_STATIC_HPP

#include <iostream>
#include <vector>

template<typename T = int>
class INode_Base
{
public:
    inline INode_Base()
    {
        m_data = T();
        m_parent = nullptr;
    }

    virtual ~INode_Base() = default;

    inline void set_data(T a_data)
    { m_data = a_data; }

    virtual int get_children_size() = 0;

    virtual void add_new_default_child() = 0;

    virtual INode_Base* get_child(int a_child_in_vector) = 0;

    inline void print_data() const
    { std::cout << " " << m_data; };

    virtual void print_all_below() = 0;

private:
    INode_Base<T>* m_parent;
    T m_data;
};

#endif //LIST_1_INODE_STATIC_HPP
