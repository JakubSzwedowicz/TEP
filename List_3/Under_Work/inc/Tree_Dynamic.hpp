//
// Created by JakubSzwedowicz on 18.11.2021.
//

#ifndef LIST_1_TREE_DYNAMIC_HPP
#define LIST_1_TREE_DYNAMIC_HPP

#include "Tree_Base.hpp"

namespace
{
    class Node_Dynamic : public Node_Base<Node_Dynamic*, int>
    {
    public:
        ~Node_Dynamic()
        {
            if (m_parent)
            {

            }
        }

    };
}

template<typename T = int>
class Tree_Dynamic : public Tree_base<Node_Dynamic, T>
{


};

#endif //LIST_1_TREE_DYNAMIC_HPP
