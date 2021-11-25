//
// Created by JakubSzwedowicz on 18.11.2021.
//

#ifndef LIST_1_ITREE_BASE_HPP
#define LIST_1_ITREE_BASE_HPP

#include <iostream>

#include "INode_Base.hpp"

template<typename T = int>
class ITree_base
{
public:
    ITree_base();

    virtual ~ITree_base() = 0;

    INode_Base<T>* get_root()
    { return (&m_root); }

    void print_tree() const
    {
        m_root.print_data();
        m_root.print_all_below();
    };

private:
    INode_Base<T> m_root;
};

#endif //LIST_1_ITREE_BASE_HPP
