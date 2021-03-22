# Dictionary-using-BST

### Implement Dictionary Using Binary Search Tree

    Dictionary can be implemented using binary search tree.  A binary search tree is a binary tree such that each node 
    stores a key of a dictionary.Key 'k' of a node is always greater than the keys present in its left sub tree.
    Similarly, key 'k' of a node is always lesser than the keys present in its right sub tree.
    


Example:

                                       well
                                    /       \
                                  bus       xmas
                                 /    \          \
                               air   aero      zebra
                               

In the above example, keys present at the left sub-tree of the root node are lesser than the key of the root node.  And also, the keys present at the right sub-tree are greater than the key of the root node.

### Insertion in BST:

    To insert an element in a binary search tree,
    - check whether the root is present or not.  If root is absent, then the new node is the root.
    - If root node is present, check whether the key in new node is greater than or lesser than the key in root node.
    - If key in new node is less than the key in root, then traverse the left sub-tree recursively until we reach the leaf node.
    - Then, insert the new node to the left(newnode < leaf)/right(newnode > leaf) of the leaf.
    - If the key in new node is greater than the key in root, then traverse the right sub-tree recursively until we reach the leaf node.
    - Then, insert the new node to the left(newnode < leaf)/right of the leaf

#### Function:

        InsertionInBST(T, newnode)
        y<-NULL           
        x <- root[T]
        while x != NULL
             y<-x
             if  key[z] < key
                  then x <- left[x]
                  else  x <- right[x]
        parent[newnode] <- y
        if y == NULL
           then root[T] <- newnode
        else if key[newnode] < key[y]
            then left[y] <- newnode
            else right[y] <- newnode

Insert "yell" to the below binary search tree.

                          workload
                            /     \
                          bus    xmas
                         /   \     \
                       air   aero     zebra


                          workload
                         /       \
                      bus         xmas
                      /   \        /   \
                   air   aero    yell  zebra
                   
### Deletion in BST:

        To delete a node from binary search tree, we have three different cases.
        Node X has no children
        Node X has one child
        Node X has two children

Case 1:
If X has no children

                          workload
                         /       \
                        bus      xmas
                      /   \        /  \
                   air   aero    yell zebra

Delete "zebra" from above binary search tree.

                          workload
                         /       \
                      bus        xmas
                      /  \        /   
                   air   aero    yell

Case 2:
If X has only one child, then delete x and point the parent of x to the child of x.

                          workload
                         /      \
                      bus        xmas
                      /  \        /   
                   air   aero    yell

Delete "xmas" from the above binary search tree.

                          workload
                         /      \
                      bus       yell
                      /  \       
                   air   aero

Case 3:
If X has two children, then find its successor 'S'.  Remove 'S' from the binary search tree.  And replace X with 'S'

                          workload
                         /      \
                      bus       xmas
                      /  \      /   \
                   air   aero  yell  zebra

Remove "workload" from the above binary search tree.  The successor for "workload"(smallest element in the right subtree of "workload") is "yell".  Remove it and replace "workload with "yell".

                              yell
                            /     \
                        bus      xmas
                       /   \         \
                    air   aero      zebra
