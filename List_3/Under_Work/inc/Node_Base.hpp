//
// Created by JakubSzwedowicz on 18.11.2021.
//

#ifndef LIST_1_INODE_STATIC_HPP
#define LIST_1_INODE_STATIC_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template<class Node_Type, typename T = int>
class Node_Base
{
protected:
    using TNode_Ptr_Type = std::conditional_t<std::is_pointer<Node_Type>::value, Node_Type, Node_Type*>;
    using TNode_Type = Node_Type;
    using TData = T;

public:
    inline Node_Base() : m_data(TData()), m_parent(nullptr)
    {};

    Node_Base(Node_Base&& a_other) : m_parent(std::exchange(a_other.m_parent, nullptr)), m_data(std::move(a_other.m_data))
    , m_children(std::move(a_other.m_children))
    {}

    ~Node_Base() = default;

    inline void set_data(const TData& a_data)
    { m_data = a_data; }

    inline int get_children_size() const
    { return m_children.size(); }

    virtual void add_new_default_child() = 0;

    TNode_Ptr_Type get_child(int a_child_in_vector)
    { return m_children.size() <= a_child_in_vector ? m_children[a_child_in_vector] : nullptr; }

    inline void print_data() const
    { std::cout << " " << m_data; };

    void print_all_below() const
    {
        std::for_each(m_children.cbegin(), m_children.cend(), [](const auto* it)
        {
            it->print_data();
            it->print_all_below();
        });
    };

    void print_all_above() const
    {
        if (m_parent)
        {
            m_parent->print_data();
            m_parent->print_all_above();
        }
    }

protected:
    TData m_data;

    std::vector<TNode_Type> m_children;

    TNode_Ptr_Type m_parent;

private:
    explicit Node_Base(const TNode_Ptr_Type& a_parent) : Node_Base()
    { m_parent = a_parent; }
};

#endif //LIST_1_INODE_STATIC_HPP
