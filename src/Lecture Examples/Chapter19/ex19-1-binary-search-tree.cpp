#include <iostream>

using namespace std ;

// Definition of the node class
class node
{
public:
    int data ;
    node* left ;
    node* right ;

    // Constructor
    node(int value = 0, node* leftNode = nullptr, node* rightNode = nullptr)
    {
        data = value ;
        left = leftNode ;
        right = rightNode ;
    }
} ;

// Definition of the Binary Search Tree class
class BinarySearchTree
{
public:
    // Default constructor
    BinarySearchTree()
    {
        root = nullptr ;
    }

    // Copy constructor
    BinarySearchTree(const BinarySearchTree& otherTree)
    {
        if (otherTree.root == nullptr)
            root = nullptr ;
        else
            copyTree(root, otherTree.root) ;
    }

    // Destructor
    ~BinarySearchTree()
    {
        destroy(root) ;
    }

    // Overload the assignment operator
    const BinarySearchTree& operator=(const BinarySearchTree& otherTree)
    {
        if (this != &otherTree)
        {
            if (root != nullptr)
                destroy(root) ;

            if (otherTree.root == nullptr)
                root = nullptr ;
            else
                copyTree(root, otherTree.root) ;
        }
        return *this ;
    }

    // Function to determine whether the binary tree is empty.
    bool isEmpty() const
    {
        return (root == nullptr) ;
    }

    // Function to determine the height of a binary tree.
    int treeHeight() const
    {
        return height(root) ;
    }

    // Function to determine the number of nodes in a binary tree.
    int treeNodeCount() const
    {
        return nodeCount(root) ;
    }

    // Function to determine the number of leaves in a binary tree.
    int treeLeavesCount() const
    {
        return leavesCount(root) ;
    }

    // Function to destroy the binary tree.
    void destroyTree()
    {
        destroy(root) ;
    }
    /*
    Purpose: Deletes all nodes in the tree to free memory.
    Logic:
    - Recursively destroy the left subtree, the right subtree, and then delete the current node.
    Time Complexity: O(n).
    Example:
    For:
      50
     /  \
    30   70
   / \
  20 40

    All nodes are deleted one by one.
    */

    // Function to insert a new item into the binary search tree.
    void insert(const int& insertItem)
    {
        root = insert(root, insertItem) ;
    }

    // Function to search for an item in the binary search tree.
    bool search(const int& searchItem) const
    {
        return search(root, searchItem) ;
    }

    // Function to delete a node from the binary search tree.
    void deleteNode(const int& deleteItem)
    {
        root = deleteNode(root, deleteItem) ;
    }

    // Function to print the tree in inorder traversal.
    void inorderTraversal() const
    {
        inorder(root) ;
        cout << endl ;
    }

    // Function to print the tree in preorder traversal.
    void preorderTraversal() const
    {
        preorder(root) ;
        cout << endl ;
    }

    // Function to print the tree in postorder traversal.
    void postorderTraversal() const
    {
        postorder(root) ;
        cout << endl ;
    }

private:
    node* root ;

    // Makes a copy of the binary tree to which otherTreeRoot points.
    void copyTree(node*& copiedTreeRoot, node* otherTreeRoot)
    {
        if (otherTreeRoot == nullptr)
            copiedTreeRoot = nullptr ;
        else
        {
            copiedTreeRoot = new node(otherTreeRoot->data) ;
            copyTree(copiedTreeRoot->left, otherTreeRoot->left) ;
            copyTree(copiedTreeRoot->right, otherTreeRoot->right) ;
        }
    }

    // Helper function to insert an item into the binary search tree.
    node* insert(node* p, const int& insertItem)
    {
        if (p == nullptr) // If the tree is empty or we find a position, create a new node
            return new node(insertItem) ;

        if (insertItem < p->data) // Insert into the left subtree
            p->left = insert(p->left, insertItem) ;
        else if (insertItem > p->data) // Insert into the right subtree
            p->right = insert(p->right, insertItem) ;

        return p ; // Return the unchanged pointer
    }
    /*
    Purpose: Adds a new node to the binary search tree (BST) while maintaining the BST property.
    Logic:
    - If the tree is empty (root == nullptr), the new node becomes the root.
    - Recursively traverse the tree:
        - If the insertItem is smaller than the current node's data, move to the left subtree.
        - If it's larger, move to the right subtree.
    - Insert the new node when an empty spot (nullptr) is found.
    
    Time Complexity:
    - Best case: O(logn) (balanced tree).
    - Worst case: O(n) (skewed tree).
    
    Example:
        Inserting 40 into
      50
     /  \
    30   70
   /
  20

    Result in:
      50
     /  \
    30   70
   / \
  20  40
    */

    // Helper function to search for an item in the binary search tree.
    bool search(node* p, const int& searchItem) const
    {
        if (p == nullptr)
            return false ;
        if (p->data == searchItem)
            return true ;
        if (searchItem < p->data)
            return search(p->left, searchItem) ;
        else
            return search(p->right, searchItem) ;
    }
    /*
    Purpose: Determines if a value exists in the tree.
    Logic:
    - Start from the root:
        - If the current node is nullptr, the value is not found.
        - If the searchItem matches the current node’s data, return true.
        - If searchItem is smaller, search the left subtree.
        - If searchItem is larger, search the right subtree.
    
    Time Complexity:
    - Best case: O(logn).
    - Worst case: O(n).
    
    Example:
    Searching for 40 in:
      50
     /  \
    30   70
   / \
  20  40
    Returns true.
    */

    // Helper function to delete a node from the binary search tree.
    node* deleteNode(node* p, const int& deleteItem)
    {
        if (p == nullptr)
            return nullptr ;

        if (deleteItem < p->data)
            p->left = deleteNode(p->left, deleteItem) ;
        else if (deleteItem > p->data)
            p->right = deleteNode(p->right, deleteItem) ;
        else
        {
            // Node with one child or no child
            if (p->left == nullptr)
            {
                node* temp = p->right ;
                delete p ;
                return temp ;
            }
            else if (p->right == nullptr)
            {
                node* temp = p->left ;
                delete p ;
                return temp ;
            }

            // Node with two children
            node* temp = findMin(p->right) ;
            p->data = temp->data ;
            p->right = deleteNode(p->right, temp->data) ;
        }
        return p ;
    }
    /*
    Purpose: Removes a node from the tree while maintaining the BST property.
    Logic:
    - Recursively find the node to delete:
        - If deleteItem is smaller, move to the left subtree.
        - If deleteItem is larger, move to the right subtree.
    - Handle three cases:
        - Node has no children: Simply delete it.
        - Node has one child: Replace it with its child.
        - Node has two children:
            - Find the minimum value in the right subtree (findMin).
            - Replace the current node's data with the successor's data.
            - Recursively delete the successor.
    
    Time Complexity:
    - Best case: O(logn).
    - Worst case: O(n).
    
    Example:
    Deleting 50 from:
      50
     /  \
    30   70
   / \   / \
  20 40 60 80

    Results in:
      60
     /  \
    30   70
   / \     \
  20 40     80
  

    */
    // Helper function to find the minimum value node in the tree.
    node* findMin(node* p) const
    {
        while (p->left != nullptr)
            p = p->left ;
        return p ;
    }
    /*
    Purpose: Finds the smallest value in the subtree rooted at p.
    Logic:
    - Traverse the left subtree until the leftmost node is reached.
    Time Complexity:
    - Best case: O(1).
    - Worst case: O(h), where h is the height of the tree.
    Example:
    For:
      50
     /  \
    30   70
   / \
  20 40

    findMin(root) returns the node with data = 20.
    */
    // Helper function for inorder traversal.
    void inorder(node* p) const
    {
        if (p != nullptr)
        {
            inorder(p->left) ;
            cout << p->data << " " ;
            inorder(p->right) ;
        }
    }
    /*
    Purpose: Traverses the tree in in-order sequence (Left → Node → Right).
    Logic:
    - Recursively visit the left subtree, print the current node’s data, and then visit the right subtree.
    Output: Values are printed in ascending order for a BST.
    Time Complexity: O(n), where n is the number of nodes.
    Example:
    For:
      50
     /  \
    30   70
   / \
  20 40

    Output: 20 30 40 50 70.
    */

    // Helper function for preorder traversal.
    void preorder(node* p) const
    {
        if (p != nullptr)
        {
            cout << p->data << " " ;
            preorder(p->left) ;
            preorder(p->right) ;
        }
    }
    /*
    Purpose: Traverses the tree in pre-order sequence (Node → Left → Right).
    Logic:
    - Print the current node’s data, then recursively visit the left subtree and the right subtree.
    Output: Displays the tree's structure.
    Time Complexity: O(n).
    Example:
    For:
      50
     /  \
    30   70
   / \
  20 40

    Output: 50 30 20 40 70.
    */

    // Helper function for postorder traversal.
    void postorder(node* p) const
    {
        if (p != nullptr)
        {
            postorder(p->left) ;
            postorder(p->right) ;
            cout << p->data << " " ;
        }
    }
    /*
    Purpose: Traverses the tree in post-order sequence (Left → Right → Node).
    Logic:
    Recursively visit the left subtree and the right subtree, then print the current node’s data.
    Output: Useful for deleting the tree.
    Time Complexity: O(n).
    Example:
    For:
      50
     /  \
    30   70
   / \
  20 40

    Output: 20 40 30 70 50.
    */

    // Function to destroy the binary tree to which p points.
    void destroy(node*& p)
    {
        if (p != nullptr)
        {
            destroy(p->left) ;
            destroy(p->right) ;
            delete p ;
            p = nullptr ;
        }
    }

    // Function to determine the height of the binary tree to which p points.
    int height(node* p) const
    {
        if (p == nullptr)
            return 0 ;
        else
            return 1 + max(height(p->left), height(p->right)) ;
    }

    // Function to determine the larger of x and y.
    int max(int x, int y) const
    {
        return (x >= y) ? x : y ;
    }

    // Function to determine the number of nodes in the binary tree.
    int nodeCount(node* p) const
    {
        if (p == nullptr)
            return 0 ;
        else
            return 1 + nodeCount(p->left) + nodeCount(p->right) ;
    }

    // Function to determine the number of leaves in the binary tree.
    int leavesCount(node* p) const
    {
        if (p == nullptr)
            return 0 ;
        else if (p->left == nullptr && p->right == nullptr)
            return 1 ;
        else
            return leavesCount(p->left) + leavesCount(p->right) ;
    }
} ;

int main()
{
    BinarySearchTree tree ;

    tree.insert(50) ;
    tree.insert(30) ;
    tree.insert(70) ;
    tree.insert(20) ;
    tree.insert(40) ;
    tree.insert(60) ;
    tree.insert(80) ;

    cout << "Inorder traversal: " ;
    tree.inorderTraversal() ;

    cout << "Preorder traversal: " ;
    tree.preorderTraversal() ;

    cout << "Postorder traversal: " ;
    tree.postorderTraversal() ;

    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << endl ;
    cout << "Search 90: " << (tree.search(90) ? "Found" : "Not Found") << endl ;

    tree.deleteNode(50) ;
    cout << "Inorder traversal after deleting 50: " ;
    tree.inorderTraversal() ;

    return 0 ;
}

/*
I would like to add display() function to print this binary search tree like pretty printer.

Lv0: 50
Lv1: 30(50) 70(50)
Lv2: 20(30) 40(30) 60(70) 80(70)

The numbers in paranthesis is the parent node.
*/
