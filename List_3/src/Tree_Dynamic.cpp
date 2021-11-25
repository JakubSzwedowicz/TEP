//
// Created by JakubSzwedowicz on 18.11.2021.
//

#include <iostream>
#include <algorithm>
#include "Tree_Dynamic.hpp"

template
class Tree_Dynamic<int>;

template<typename T>
Tree_Dynamic<T>::Tree_Dynamic()
        : m_root(new Tree_Dynamic<T>::Node_Dynamic<T>(nullptr))
{

}

template<typename T>
Tree_Dynamic<T>::~Tree_Dynamic()
{
    delete m_root;
}


template<typename T>
bool
Tree_Dynamic<T>::move_subtree(Tree_Dynamic::Node_Dynamic<T>* a_new_parent, Tree_Dynamic::Node_Dynamic<T>* a_new_child)
{
    if (are_trees_separate(a_new_parent, a_new_child) == false || a_new_child->m_parent == nullptr)
    {
        return false;
    }

    a_new_parent->m_children.push_back(a_new_child);

    auto it = std::find_if(a_new_child->m_parent->m_children.begin(), a_new_child->m_parent->m_children.end(),
                        [&a_new_child](const auto& node_ptr)
                        { return a_new_child == node_ptr; });
    a_new_child->m_parent->m_children.erase(it);

    a_new_child->m_parent = a_new_parent;
    return true;
}

template<typename T>
bool Tree_Dynamic<T>::are_trees_separate(Node_Dynamic<T>* const& a_first, Node_Dynamic<T>* const& a_second)
{
    return a_first->get_root() != a_second->get_root();
}

template<typename T>
typename Tree_Dynamic<T>::template Node_Dynamic<T>* Tree_Dynamic<T>::get_root()
{
    return m_root;
}

template<typename T>
void Tree_Dynamic<T>::print_tree() const
{
    m_root->print_data();
    m_root->print_all_below();
}

template<typename T>
void Tree_Dynamic<T>::tree_test()
{
    Node_Dynamic<T> root;

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
    Tree_Dynamic<int> tree1;
    tree1.m_root->add_new_default_child();
    tree1.m_root->get_child(0)->set_data(-1);
    tree1.m_root->get_child(0)->add_new_default_child();
    tree1.m_root->get_child(0)->get_child(0)->set_data(-3);

    tree1.m_root->add_new_default_child();
    tree1.m_root->get_child(1)->set_data(-2);
    tree1.m_root->get_child(1)->add_new_default_child();
    tree1.m_root->get_child(1)->get_child(0)->set_data(-4);

    std::cout << "Printing tree1 BEFORE move" << std::endl;
    tree1.print_tree();

    Tree_Dynamic<int> tree2;
    tree2.m_root->add_new_default_child();
    tree2.m_root->get_child(0)->set_data(-10);

    std::cout << "Printing tree2 BEFORE move" << std::endl;
    tree2.print_tree();

    Tree_Dynamic::move_subtree(tree2.m_root->get_child(0), tree1.m_root->get_child(0));
    std::cout << "Printing tree1 AFTER move" << std::endl;
    tree1.print_tree();
    std::cout << "Printing tree2 AFTER move" << std::endl;
    tree2.print_tree();
}

template<typename T>
template<typename U>
Tree_Dynamic<T>::Node_Dynamic<U>::Node_Dynamic()
        : Node_Dynamic(nullptr)
{}

template<typename T>
template<typename U>
void Tree_Dynamic<T>::Node_Dynamic<U>::set_data(T a_data)
{
    m_data = a_data;
}

template<typename T>
template<typename U>
int Tree_Dynamic<T>::Node_Dynamic<U>::get_children_size()
{
    return m_children.size();
}

template<typename T>
template<typename U>
void Tree_Dynamic<T>::Node_Dynamic<U>::add_new_default_child()
{
    m_children.push_back(new Node_Dynamic(this));
}

template<typename T>
template<typename U>
typename Tree_Dynamic<T>::template Node_Dynamic<U>* Tree_Dynamic<T>::Node_Dynamic<U>::get_child(int a_child_in_vector)
{
    return (a_child_in_vector >= 0 && a_child_in_vector < m_children.size()) ?
           *(m_children.data() + a_child_in_vector) : nullptr;
}

template<typename T>
template<typename U>
typename Tree_Dynamic<T>::template Node_Dynamic<U>* Tree_Dynamic<T>::Node_Dynamic<U>::get_root()
{
    Node_Dynamic* node = this;
    while (node->m_parent) node = node->m_parent;
    return node;

}

template<typename T>
template<typename U>
void Tree_Dynamic<T>::Node_Dynamic<U>::print_data() const
{
    std::cout << " " << m_data << std::endl;
}

template<typename T>
template<typename U>
void Tree_Dynamic<T>::Node_Dynamic<U>::print_all_below() const
{
    std::for_each(m_children.cbegin(), m_children.cend(), [](const auto* it)
    {
        it->print_data();
        it->print_all_below();
    });
}

template<typename T>
template<typename U>
void Tree_Dynamic<T>::Node_Dynamic<U>::print_all_above() const
{
    print_data();

    if (m_parent)
    {
        m_parent->print_all_above();
    }
}

template<typename T>
template<typename U>
Tree_Dynamic<T>::Node_Dynamic<U>::~Node_Dynamic()
{
    for (auto& node: m_children)
    {
        delete node;
    }
}

template<typename T>
template<typename U>
Tree_Dynamic<T>::Node_Dynamic<U>::Node_Dynamic(Tree_Dynamic<T>::Node_Dynamic<U>* const& a_parent)
        : m_data(T()), m_parent(a_parent)
{

}
