//
// Created by JakubSzwedowicz on 18.11.2021.
//

#include <iostream>
#include <algorithm>

#include "Tree_Static.hpp"

template
class Tree_Static<int>;

template<typename T>
Tree_Static<T>::Tree_Static()
        : m_root()
{}

template<typename T>
Tree_Static<T>::Tree_Static(const Node_Static<T>& a_node) : m_root(a_node)
{

}


template<typename T>
bool Tree_Static<T>::move_subtree(Tree_Static::Node_Static<T>* a_new_parent, Tree_Static::Node_Static<T>* a_new_child)
{
    if (are_trees_separate(a_new_parent, a_new_child) == false || a_new_child->m_parent == nullptr)
    {
        return false;
    }

    a_new_parent->m_children.push_back(*a_new_child);
    a_new_child->m_parent->erase_child(a_new_child);

    a_new_parent->m_children.back().m_parent = a_new_parent;
    return true;
}

template<typename T>
std::vector<Tree_Static<T>> Tree_Static<T>::split_trees(Node_Static<T>* a_node)
{
    std::vector<Tree_Static<T>> ret;
    ret.reserve(a_node->m_children.size());
    for (const auto& root: a_node->m_children)
    {
        ret.push_back(root);
    }
    a_node->m_children.clear();
    return ret;
}


template<typename T>
bool Tree_Static<T>::are_trees_separate(Node_Static<T>* const& a_first, Node_Static<T>* const& a_second)
{
    return a_first->get_root() != a_second->get_root();
}

template<typename T>
typename Tree_Static<T>::template Node_Static<T>* Tree_Static<T>::get_root()
{
    return &m_root;
}

template<typename T>
void Tree_Static<T>::print_tree() const
{
    m_root.print_data();
    m_root.print_all_below();
}

template<typename T>
void Tree_Static<T>::tree_test()
{
    Node_Static<T> root;

    root.add_new_default_child();
    root.add_new_default_child();

    root.get_child(0)->set_data(1);
    root.get_child(1)->set_data(2);

    root.get_child(0)->add_new_default_child();
    root.get_child(0)->add_new_default_child();

    root.get_child(0)->get_child(0)->set_data(11);
    root.get_child(0)->get_child(1)->set_data(12);

    root.get_child(1)->add_new_default_child();
    root.get_child(1)->add_new_default_child();

    root.get_child(1)->get_child(0)->set_data(21);
    root.get_child(1)->get_child(1)->set_data(22);

    root.print_data();
    root.print_all_below();

    root.get_child(0)->get_child(1)->print_all_above();


    std::cout << "MOVE TREE STATIC TEST " << std::endl;
    Tree_Static<int> tree1;
    tree1.m_root.add_new_default_child();
    tree1.m_root.get_child(0)->set_data(-1);
    tree1.m_root.get_child(0)->add_new_default_child();
    tree1.m_root.get_child(0)->get_child(0)->set_data(-3);

    tree1.m_root.add_new_default_child();
    tree1.m_root.get_child(1)->set_data(-2);
    tree1.m_root.get_child(1)->add_new_default_child();
    tree1.m_root.get_child(1)->get_child(0)->set_data(-4);

    std::cout << "Printing tree1 BEFORE move" << std::endl;
    tree1.print_tree();

    Tree_Static<int> tree2;
    tree2.m_root.add_new_default_child();
    tree2.m_root.get_child(0)->set_data(-10);

    std::cout << "Printing tree2 BEFORE move" << std::endl;
    tree2.print_tree();

    Tree_Static::move_subtree(tree2.m_root.get_child(0), tree1.m_root.get_child(0));
    std::cout << "Printing tree1 AFTER move" << std::endl;
    tree1.print_tree();
    std::cout << "Printing tree2 AFTER move" << std::endl;
    tree2.print_tree();
}

template<typename T>
void Tree_Static<T>::tree_test2()
{
    Tree_Static<int> tree;
    tree.m_root.set_data(0);

    tree.m_root.add_new_default_child();
    tree.m_root.add_new_default_child();
    tree.m_root.get_child(0)->set_data(2);
    tree.m_root.get_child(1)->set_data(3);

    tree.m_root.get_child(0)->add_new_default_child();
    tree.m_root.get_child(0)->add_new_default_child();
    tree.m_root.get_child(0)->get_child(0)->set_data(4);
    tree.m_root.get_child(0)->get_child(1)->set_data(5);

    tree.m_root.get_child(1)->add_new_default_child();
    tree.m_root.get_child(1)->get_child(0)->set_data(9);

    tree.m_root.get_child(0)->get_child(0)->add_new_default_child();
    tree.m_root.get_child(0)->get_child(0)->add_new_default_child();
    tree.m_root.get_child(0)->get_child(0)->get_child(0)->set_data(6);
    tree.m_root.get_child(0)->get_child(0)->get_child(1)->set_data(7);

    tree.m_root.get_child(0)->get_child(1)->add_new_default_child();
    tree.m_root.get_child(0)->get_child(1)->get_child(0)->set_data(8);

    tree.print_tree();

    auto trees = tree.split_trees(tree.m_root.get_child(0));
    for (auto& tree: trees)
    {
        std::cout << " SPLIT TREE " << std::endl;
        tree.print_tree();

    }

    std::cout << "ORIGINAL AFTER SPLIT " << std::endl;
    tree.print_tree();
}


template<typename T>
template<typename U>
Tree_Static<T>::Node_Static<U>::Node_Static()
        : Node_Static(nullptr)
{

}


template<typename T>
template<typename U>
bool Tree_Static<T>::Node_Static<U>::erase_child(Node_Static* const& a_child)
{
    auto it = std::find_if(m_children.begin(), m_children.end(), [&a_child](const auto& node)
    {
        return &node == a_child;
    });
    if (it == m_children.end())
    { return false; }
    m_children.erase(it);
    return true;
}

template<typename T>
template<typename U>
void Tree_Static<T>::Node_Static<U>::set_data(T a_data)
{
    m_data = a_data;
}

template<typename T>
template<typename U>
int Tree_Static<T>::Node_Static<U>::get_children_size()
{
    return m_children.size();
}

template<typename T>
template<typename U>
void Tree_Static<T>::Node_Static<U>::add_new_default_child()
{
    m_children.push_back(Node_Static(this));
}

template<typename T>
template<typename U>
typename Tree_Static<T>::template Node_Static<U>* Tree_Static<T>::Node_Static<U>::get_child(int a_child_in_vector)
{
    return (a_child_in_vector >= 0 && a_child_in_vector < m_children.size()) ?
           m_children.data() + a_child_in_vector : nullptr;
}

template<typename T>
template<typename U>
typename Tree_Static<T>::template Node_Static<U>* Tree_Static<T>::Node_Static<U>::get_root()
{
    Node_Static* node = this;
    while (node->m_parent)
    { node = node->m_parent; }
    return node;

}

template<typename T>
template<typename U>
void Tree_Static<T>::Node_Static<U>::print_data() const
{
    std::cout << " " << m_data << std::endl;
}

template<typename T>
template<typename U>
void Tree_Static<T>::Node_Static<U>::print_all_below() const
{
    std::for_each(m_children.cbegin(), m_children.cend(), [](const auto node)
    {
        node.print_data();
        node.print_all_below();
    });
}

template<typename T>
template<typename U>
void Tree_Static<T>::Node_Static<U>::print_all_above() const
{
    print_data();
    if (m_parent)
    {
        m_parent->print_all_above();
    }
}

template<typename T>
template<typename U>
Tree_Static<T>::Node_Static<U>::Node_Static(Tree_Static<T>::Node_Static<U>* const& a_parent)
        : m_data(T()), m_parent(a_parent)
{

}


//template<typename T>
//template<typename U>
//Tree_Static<T>::Node_Static<U>::Node_Static(const Tree_Static<T>::Node_Static<U>& a_parent)
//        : m_data(T()), m_parent(a_parent.m_parent)
//{
//            m_children.reserve(a_parent.m_children.size());
//            for(auto& node : a_parent.m_children){
//                m_children.push_back(node);
//            }
//
//}