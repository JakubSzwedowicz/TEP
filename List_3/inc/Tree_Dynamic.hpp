//
// Created by JakubSzwedowicz on 18.11.2021.
//

#ifndef LIST_3_TREE_DYNAMIC_HPP
#define LIST_3_TREE_DYNAMIC_HPP

#include <vector>


template<typename T = int>
class Tree_Dynamic
{
private:
    template<typename>
    class Node_Dynamic;

public:
    Tree_Dynamic();

    Tree_Dynamic(const Tree_Dynamic&) = delete;

    Tree_Dynamic(Tree_Dynamic&&) = delete;

    Tree_Dynamic operator=(const Tree_Dynamic&) = delete;

    Tree_Dynamic operator=(Tree_Dynamic&&) = delete;

    ~Tree_Dynamic();

    static bool move_subtree(Tree_Dynamic::Node_Dynamic<T>* a_new_parent, Tree_Dynamic::Node_Dynamic<T>* a_new_child);

    static bool are_trees_separate(Node_Dynamic<T>* const& a_first, Node_Dynamic<T>* const& a_second);

    Node_Dynamic<T>* get_root();

    void print_tree() const;

    static void tree_test();


private:
    Node_Dynamic<T>* m_root;

    template<typename>
    class Node_Dynamic
    {
    public:
        Node_Dynamic();

        Node_Dynamic(const Node_Dynamic&) = delete;

        Node_Dynamic(Node_Dynamic&&) = delete;

        Node_Dynamic operator=(const Node_Dynamic&) = delete;

        Node_Dynamic operator=(Node_Dynamic&&) = delete;

        ~Node_Dynamic();

        void set_data(T a_data);

        int get_children_size();

        void add_new_default_child();

        Node_Dynamic* get_child(int a_child_in_vector);

        Node_Dynamic* get_root();

        inline void print_data() const;

        void print_all_below() const;

        void print_all_above() const;

        friend class Tree_Dynamic;

    private:
        T m_data;
        Node_Dynamic* m_parent;
        std::vector<Node_Dynamic*> m_children;

        Node_Dynamic(Node_Dynamic* const& a_parent);

    };
};


#endif //LIST_3_TREE_DYNAMIC_HPP
