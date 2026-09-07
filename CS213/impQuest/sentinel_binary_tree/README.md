# Problem: sentinel_binary_tree

Let’s revisit binary trees. A binary tree is usually represented by using `nullptr` for missing children. In this assignment, you will implement a **Binary Search Tree (BST) using a sentinel node instead of `nullptr`**.

The important idea is that the sentinel represents every missing child and also provides a convenient boundary for the tree. This is similar to the idea shown in the lecture:

- A node stores pointers to its `parent`, `left`, and `right` nodes.
- Instead of having missing children represented by `nullptr`, they point to one shared sentinel node.
- The tree object keeps a pointer to its root.
- When the tree is empty, the root is the sentinel.
- The sentinel's pointers must be handled consistently so that tree operations do not need special `nullptr` cases.

Your task is to implement the BST operations while correctly maintaining the sentinel structure.

## The challenge

You are **not** allowed to create a separate sentinel for every missing child.

There must be exactly **one shared sentinel node** for the entire tree.

For a non-sentinel node:

- `left` is either another real node or `sentinel`.
- `right` is either another real node or `sentinel`.
- `parent` points to its real parent, or to `sentinel` when the node is the root.

For the empty tree:

- `root == sentinel`.

The sentinel must never be treated as an ordinary data-containing node.

## Your Task

In `bst.cpp`, implement the body of all specified functions in the `SentinelBST` class.

You must support:

1. `insert`
2. `search`
3. `minimum`
4. `maximum`
5. `successor`
6. `predecessor`
7. `erase`
8. `height`
9. `inorder`
10. `clear`

The implementation must preserve all parent/child/sentinel relationships after every operation.

## Important requirements

### 1. Sentinel usage

Do not use `nullptr` to represent a missing child anywhere in the actual tree structure.

Every missing child must point to the same sentinel.

For example, a leaf node must look conceptually like:

        parent
          |
         10
        /  \
   sentinel sentinel

and not:

        10
       /  \
    nullptr nullptr

### 2. Root

The tree must maintain:

    root->parent == sentinel

for every non-empty tree.

For an empty tree:

    root == sentinel

### 3. Sentinel invariants

The sentinel is a special node and must never be inserted into the BST.

You must ensure that ordinary tree operations do not accidentally modify the sentinel into an ordinary node.

### 4. No recursive search through sentinel

Traversal and recursive operations must stop when they reach the sentinel.

### 5. Complexity

The expected complexity is:

- `search`: O(h)
- `minimum`: O(h)
- `maximum`: O(h)
- `successor`: O(h)
- `predecessor`: O(h)
- `insert`: O(h)
- `erase`: O(h)
- `height`: O(n)
- `inorder`: O(n)
- `clear`: O(n)

where `h` is the height of the BST and `n` is the number of real nodes.

Do not implement an operation by repeatedly traversing the entire tree if an O(h) solution is possible.

## Edge cases

Your implementation must correctly handle:

- inserting into an empty tree
- inserting into a tree containing one node
- inserting duplicate keys
- deleting the root
- deleting a leaf
- deleting a node with only a left child
- deleting a node with only a right child
- deleting a node with two children
- deleting the only node in the tree
- deleting a key that does not exist
- successor of the maximum element
- predecessor of the minimum element
- clearing an already empty tree
- performing operations after the tree has been cleared

### Duplicate keys

For this assignment, **duplicate keys are not inserted**.

If `insert(x)` is called when `x` already exists, the tree remains unchanged.

## Output

The supplied `main.cpp` reads a sequence of commands and prints the requested results.

The exact command format is documented below.

### Input

The first line contains an integer `q`, the number of commands.

Each of the next `q` lines contains one command:

- `I x` — insert key `x`
- `D x` — delete key `x`
- `S x` — search for key `x`
- `MIN` — print minimum key
- `MAX` — print maximum key
- `SUCC x` — print successor of `x`
- `PRED x` — print predecessor of `x`
- `HEIGHT` — print tree height
- `PRINT` — print inorder traversal
- `CLEAR` — remove all nodes

For operations whose requested element does not exist, print:

    NONE

For `PRINT`, print keys in sorted inorder order separated by spaces. Print an empty line for an empty tree.

For `HEIGHT`:

- an empty tree has height `-1`
- a single-node tree has height `0`

### Example

Input:

    13
    I 8
    I 3
    I 10
    I 1
    I 6
    I 14
    S 6
    MIN
    MAX
    SUCC 6
    PRED 6
    HEIGHT
    PRINT

Output:

    FOUND
    1
    14
    8
    3
    2
    1 3 6 8 10 14

## Files to Edit

Only edit:

    bst.cpp

Do not modify:

- `bst.h`
- `main.cpp`
- `Makefile`

Changes to other files will not be considered during evaluation.

## Provided interface

The node and tree structures are supplied in `bst.h`.

You are expected to understand how the sentinel is represented and use it consistently rather than replacing the design with `nullptr`.

## Memory management

Every real node created by `insert` must eventually be released.

`clear()` must delete every real node exactly once.

The sentinel is owned by the tree and must not be deleted as though it were an ordinary BST node.

## General Instructions

- Read all `.h` and `.cpp` files before starting.
- Do not include additional header files.
- Do not modify files other than the specified file.
- Do not replace the sentinel design with `nullptr`.
- Do not create one sentinel per node.
- Keep the implementation efficient.
- Your solution will be tested on both balanced and highly skewed trees.
- Correctness includes maintaining the sentinel and parent-pointer invariants, not merely producing the correct inorder output.
