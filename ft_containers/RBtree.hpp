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
            
            void    fixDelete(Node *node)
            {

            }

            void    delete(Node *node)
            {

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
