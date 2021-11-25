//
// Created by JakubSzwedowicz on 18.11.2021.
//

#ifndef LIST_1_TREE_STATIC_HPP
#define LIST_1_TREE_STATIC_HPP

#include "Node_Base.hpp"
#include "Tree_Base.hpp"

namespace
{
    class Node_Static : public Node_Base<Node_Static, int>
    {
    public:
        Node_Static() : Node_Base<Node_Static>() {};
        Node_Static(Node_Static&& a_node) : Node_Base<Node_Static>(std::move(a_node)) {}
        ~Node_Static()
        {}

    private:
    public:
        void add_new_default_child() override
        {

        }

    private:
        Node_Static separate()
        {
            if(m_parent)
            {
                auto node_iter = std::find(
                        m_parent->m_children.begin()
                        , m_parent->m_children.end()
                        , [this](auto& it) {return this == &it;});
                Node_Static ret(std::move(*node_iter));
                m_parent->m_children.erase(node_iter);
                ret.m_parent = nullptr;
                return ret;
            }
            return *this;
        }
    };
}

template<typename T = int>
class Tree_Static : public Tree_base<Node_Static, T>
{

};


#endif //LIST_1_TREE_STATIC_HPP
