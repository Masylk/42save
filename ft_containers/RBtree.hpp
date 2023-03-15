#ifndef RBTREE_HPP
# define RBTREE_HPP

#include "less.hpp"
#include "tree_node.hpp"
#include "map_iterator.hpp"

namespace ft
{
	template<typename T, typename Compare = ft::less<T>,
		typename Node = ft::tree_node<T>,
		typename allocator = std::allocator<Node> >
    class RBtree
    {
        private:
            Node    *root;
        public:
            RBtree()
            {
                root = NULL;
            }

            ~RBtree()
            {
                delete_tree();
            }

            void    print_node(Node *node)
            {
                std::cout <<  "value : " node->value;
                std::cout << " colour : " << node->black << std::endl
                << std::endl;
            }

            void    aff_tree(Node *node)
            {
                if (node)
                {
                    aff_tree(node->right);
                    aff_tree(node->left);
                    print_node(node);
                }
            }
            
            void printHelper(Node *root, std::string indent, bool last) {
                // print the tree structure on the screen
                if (root != NULL) {
                cout<<indent;
                if (last) {
                    cout<<"R----";
                    indent += "     ";
                } else {
                    cout<<"L----";
                    indent += "|    ";
                }
                    
                string sColor = !(root->black)?"RED":"BLACK";
                cout<<root->value<<"("<<sColor<<")"<<endl;
                printHelper(root->left, indent, false);
                printHelper(root->right, indent, true);
                }
                // cout<<root->left->data<<endl;
	        }



            void    insertFix(Node *node)
            {
                while (!node->parent->black)
                {
                    if (node->parent == (node->parent->parent)->left)
                    {
                        if (!node->parent->parent->right->black)
                        {
                            node->parent->parent->right->black = 1;
                            node->parent->parent->left->black = 1;
                            node->parent->parent->black = 0;
                            node = node->parent->parent;
                        }
                        else if (node == (node->parent)->right)
                        {
                            node = node->parent;
                            left_rotate(node);
                        }
                        node->parent->black = 1;
                        node->parent->parent = 0;
                        right_rotate(node->parent->parent);
                    }
                    else
                    {
                        if (!node->parent->parent->left->black)
                        {
                            node->parent->parent->left->black = 1;
                            node->parent->parent->right->black = 1;
                            node->parent->parent->black = 1;
                        }
                        else if (node == (node->parent)->left)
                        {
                            node = node->parent;
                            right_rotate(node);
                        }
                        node->parent->black = 1;
                        node->parent->parent->black = 0;
                        left_rotate(node->parent->parent);
                    }
                    if (node == root)
                        break ;
                }
                root->black = 1;
            }

            void    insert(Node *node)
            {
                node->right = NULL;
                node->left = NULL;
                node->black = 0;
                //if tree is empty isert node as root
                if (!root)
                {
                    root = node;
                    root->black = 1;
                    return ;
                }
                Node    *cursor = root;
                while (cursor)
                {
                    //if newNode is greater than currNode go right
                    if (node->value > root->value)
                    {
                        if (!cursor->right)
                        {
                            cursor->right = node;
                            node->parent = cursor->right;
                            break ;
                        }
                        cursor = cursor->right;
                    }
                    //else go left
                    else
                    {
                        if (!cursor->left)
                        {
                            cursor->left = node;
                            node->parent = cursor->left;
                            break ;
                        }
                        cursor = cursor->left;
                    }
                }
                insertFix(node);
            }
            
            void    transplant(Node *x, Node *y)
            {
                if (!x->parent)
                    root = y;
                else if (x == x->parent->left)
                    x->parent->left = y;
                else
                    x->parent->right = y;
                y->parent = x->parent;
            }

            Node    *minimum(Node *node)
            {
                while (node->left)
                    node = node->left;
                return node;
            }

            Node    *maximum(Node *node)
            {
                while (node->right)
                    node = node->right;
                return node;
            }

            Node    *successor(Node *x)
            {
                if (x->right)
                    return minimum(x->right);
                Node    *y = x->parent;

                while (y && x == y->right)
                {
                    x = y;
                    y = y->parent;
                }
                return y;
            }

            Node    *predecessor(Node *x)
            {
                if (x->left)
                    return maximum(x->left);
                Node    *y = x->parent;

                while (y && x == y->left)
                {
                    x = y;
                    y = y->parent;
                }
                return y;
            }

            void    fixDelete(Node *node)
            {
                //TODO : see the algorithm on : https://www.programiz.com/dsa/red-black-tree
                Node    *w;

                while (node != root && node->black)
                {
                    if (node == node->parent->left)
                    {
                        w = node->parent->right;
                        if (!w->black)
                        {
                            w->black = 1;
                            node->parent->black = 0;
                            left_rotate(node->parent);
                            w = node->parent->right;
                        }
                        if (w->left->black && w->right->black)
                        {
                            w->black = 0;
                            node = node->parent;
                        }
                        else 
                        {
                            if (w->right->black)
                            {
                                w->left->black = 1;
                                w->black = 0;
                                right_rotate(w);
                                w = node->parent->right
                            }

                            w->black = node->parent->black;
                            node->parent->black = 1;
                            w->right->black = 1;
                            left_rotate(node->parent);
                            node = root;
                        }
                    }
                    else
                    {
                        w = node->parent->left
                        if (!w->black)
                        {
                            w->black = 1;
                            node->parent->black = 0;
                            right_rotate(node->parent);
                            w = node->parent->left;
                        }
                        if (w->left->black && w->right->black)
                        {
                            w->black = 0;
                            node = node->parent;
                        }
                        else 
                        {
                            if (w->left->black)
                            {
                                w->right->black = 1;
                                w->black = 0;
                                left_rotate(w);
                                w = node->parent->left
                            }

                            w->black = node->parent->black;
                            node->parent->black = 1;
                            w->left->black = 1;
                            right_rotate(node->parent);
                            node = root;
                        }
                    }
                }
                node->black = 1;
            }

            void    deleteNode(Node *node)
            {
                bool    originalColor = node->black;
                int     key = node->value;
                Node    *x, y;
                //cursor
                Node    *z = NULL;

                while (node)
                {
                    if (node->value == key)
                        z = node;
                    if (node->value <= key)
                        node = node->right;
                    else
                        node = node->left;
                }
                if (!z)
                {
                    std::cout << "Key not found for deletion" << std::endl;
                    return ;
                }
                if (!z->left)
                {
                    x = z->right;
                    transplant(z, z->right);
                }
                else if (!z->right)
                {
                    x = z->left;
                    transplant(z, z->left);
                }
                else
                {
                    y = minimum(z->right);
                    originalColor = y->black;
                    x = y->right;
                    if (y->parent == z)
                        x->parent = y;
                    else
                    {
                        transplant(y, y->right);
                        y->right = z->right;
                        y->right->parent = y;
                    }
                    transplant(z, y);
                    y->left = z->left;
                    y->left->parent = y;
                    y->black = z->black;
                }
                delete z;
                if (originalColor)
                    fix_delete(x);
            }

            void    recolor(Node *node)
            {

            }

            void    left_rotate(Node *node)
            {
                Node    *y;

                //right subtree
                y = node->right;

                node->right = y->left;
                if (y->left)
                    y->left->parent = node;
                y->parent = node->parent;
                if (node->parent == NULL)
                    root = y;
                else if (node == (node->parent)->left)
                    node->parent->left = y;
                else
                    node->parent->right = y;
                y->left = node;
                node->parent = y;
            }

            void    right_rotate(Node *node)
            {
                Node    *x;
                
                //left subtree
                x = node->left;

                node->left = x->right;
                if (x->right)
                    x->right->parent = node;
                x->parent = node->parent;
                if (node->parent == NULL)
                    root = x;
                else if (node == (node->parent)->right)
                    node->parent->right = x;
                else
                    node->parent->left = x;
                x->right = node;
                node->parent = x;
            }

            Node searchNode(int key) 
            {
                Node node = root;
                while (node != null) {
                    if (key == node.data) {
                        return node;
                    } else if (key < node.data) {
                    node = node.left;
                    } else {
                        node = node.right;
                    }
                }
                return null;
            }

            void    fix_delete(Node *node)
            {

            }

            void    fix_insert(Node *node)
            {

            }

            void    delete_tree()
            {

            }
    };
};

#endif
