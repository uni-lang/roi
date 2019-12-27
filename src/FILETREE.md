# ROI FILETREE
Welcome to ROI repository, here you can find the primordial version of the
interpreter. This file is intended to specify the file and folders structure.

- src: source codes
-- src/headers: .h files
-- src/assets: images, texts, and other aesthetic files  


# Dependencies
Only files ended with 'handler.h' can call external depencies such as stdio,
stdlib etc.

# Coding standards
ROI follows the [GNU Coding Standards](https://www.gnu.org/prep/standards/standards.html).

## Naming convention
Names ended with '_t' relates to structs.
Some function names follows the precedence like OOP: <class>[_<subclass>]_<method's name>.
Examples:
* A funtion to alloc nodes.
```node_alloc()```
* A function to traverse through a tree structure using postorder.
```tree_postorder_rec()```
And so on..