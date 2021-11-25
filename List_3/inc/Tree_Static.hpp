//
// Created by JakubSzwedowicz on 18.11.2021.
//

#ifndef LIST_3_TREE_STATIC_HPP
#define LIST_3_TREE_STATIC_HPP

#include <vector>

template<typename T = int>
class Tree_Static
{
private:
    template<typename>
    class Node_Static;

public:
    Tree_Static();

    static bool move_subtree(Node_Static<T>* a_new_parent, Node_Static<T>* a_new_child);

    static bool are_trees_separate(Node_Static<T>* const& a_first, Node_Static<T>* const& a_second);

    Node_Static<T>* get_root();

    void print_tree() const;

    static void tree_test();

private:
    Node_Static<T> m_root;

    template<typename>
    class Node_Static
    {
    public:
        Node_Static();

        bool erase_child(Node_Static* const& a_child);

        void set_data(T a_data);

        int get_children_size();

        void add_new_default_child();

        Node_Static* get_child(int a_child_in_vector);

        Node_Static* get_root();

        inline void print_data() const;

        void print_all_below() const;

        void print_all_above() const;

        friend class Tree_Static;

    private:
        T m_data;
        Node_Static* m_parent;
        std::vector<Node_Static> m_children;

        Node_Static(Node_Static* const& a_parent);

    };
};


#endif //LIST_3_TREE_STATIC_HPP
