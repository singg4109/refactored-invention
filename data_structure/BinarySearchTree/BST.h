/*

Author: cschuiaa
Code description: A binary search tree using a unique integer (key) to store the element (class object)
Reference: COMP2012 Lecture notes

*/

template <typename T>
class BST
{
    private:
        struct BSTnode
        {
            T data;
            int key;
            BST left;
            BST right;

            // constructor
            BSTnode(const T& data, int key):data(data), key(key){}
            BSTnode(const BSTnode& other): data(other.data), key(other.key), left(other.left), right(other.right){}
            // destructor
            ~BSTnode(){}
        };

        BSTnode* root = nullptr;
    public:
        // constructor
        BST();
        BST(BST&& other);
        BST(const BST& other);
        // destructor
        ~BST();

        // member function
        bool is_empty() const;
        bool contains(int key) const;
        const T* get(int key) const;
        const T& find_max(int& x = dummy) const;
        const T& find_min(int& x = dummy) const;
        bool insert(const T& data, int key);
        bool remove(int key);
        
        void print(int depth = 0) const;
        void travel_in_order();
        void travel_post_order();
        void travel_pre_order();
       
        static int dummy;
};

template <typename T>
int BST<T>::dummy = 0;

