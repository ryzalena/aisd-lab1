
#include <iostream>
#include "Tree.h"
using namespace std;


Tree::Tree()
{
    root = nullptr;
}


void Tree::recursion_destructor(Node* obj)
{
    if (obj->_left)
        recursion_destructor(obj->_left);
    if (obj->_right)
        recursion_destructor(obj->_right);
    delete obj;
    obj = nullptr;
}


Tree:: ~Tree()
{
    if (root)
        recursion_destructor(root);
}


void Tree::recursion_copy(const Node* obj)
{
    insert(obj->_data);
    if (obj->_left)
        recursion_copy(obj->_left);
    if (obj->_right)
        recursion_copy(obj->_right);
}


Tree::Tree(const Tree& obj)
{
    recursion_destructor(root);
    recursion_copy(obj.root);
}


void Tree::recursion_print(const Node* obj, int level)
{
    if (obj)
    {
        recursion_print(obj->_right, level + 1);
        for (int i = 0; i < level; i++)
            cout << "   ";
        cout << obj->_data << endl;
        recursion_print(obj->_left, level + 1);
    }
}


void Tree::print()
{
    recursion_print(root);
}


bool Tree::insert(int key) 
{
    if (!root)
    {
        root = new Node(key);
        return true;
    }
    Node* tmp = root;
    while (tmp)
    {
        if (tmp->_data == key)
        {
            return true;
        }


        if (tmp->_data < key)
        {
            if (tmp->_right)
                tmp = tmp->_right;
            else
            {
                tmp->_right = new Node(key, tmp);
                return true;
            }
        }
        else
        {
            if (tmp->_left)
                tmp = tmp->_left;
            else
            {
                tmp->_left = new Node(key, tmp);
                return true;
            }

        }
    }
    return false;
}

Node* Tree::search(int key)
{
    if (!root) return nullptr;
    Node* tmp = root;

    while (tmp)
    {
        if (tmp->_data == key)
            return tmp;

        else
        {
            if (tmp->_data < key)
                tmp = tmp->_right;
            else
            {
                if (tmp->_data > key)
                    tmp = tmp->_left;
            }
        }
    }
    return nullptr;
}


bool Tree::contains(int key)
{
    if (search(key))
        return true;
    return false;
}


Node* Tree::delete_node(int key, Node* node)
{
    if (!node) return NULL;
    else if (key < node->_data) node->_left = delete_node(key, node->_left);
    else if (key > node->_data) node->_right = delete_node(key, node->_right);

    else
    {
        Node* tmp_node = node;
        if (!node->_left || !node->_right)
        {
            node = (!node->_right) ? node->_left : node->_right;
            delete tmp_node;
        }
        else
        {
            tmp_node = node->_left;
            while (tmp_node->_right) tmp_node = tmp_node->_right;
            node->_data = tmp_node->_data;
            node->_left = delete_node(node->_data, node->_left);
        }
    }

    return node;
}

bool Tree::erase(int key)
{
    if (!contains(key)) return false;
    root = delete_node(key, root);
    return true;
}

Tree& Tree:: operator=(const Tree& obj)
{
    recursion_copy(obj.root);
    return (*this);
}