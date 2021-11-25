//
// Created by JakubSzwedowicz on 18.11.2021.
//

#ifndef LIST_1_TREE_BASE_HPP
#define LIST_1_TREE_BASE_HPP

#include <iostream>

#include "Node_Base.hpp"

template<class Node_Type, typename T = int>
class Tree_base
{
protected:
    using TNode_Ptr_Type = typename std::conditional<std::is_pointer<Node_Type>::value, Node_Type, Node_Type*>::type;
    using TNode_Type = Node_Type;

public:
    TNode_Ptr_Type get_root()
    { return (&m_root); }

    void print_tree() const
    {
        m_root.print_data();
        m_root.print_all_below();
    }

protected:
    TNode_Type m_root;
};

#endif //LIST_1_TREE_BASE_HPP
