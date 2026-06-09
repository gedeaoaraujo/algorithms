type BTreeNode = ref object
  key: int
  left: BTreeNode
  right: BTreeNode

proc searchNode(root: BTreeNode, target: int): BTreeNode =
  if (root.isNil() or root.key == target): 
    return root
  if (root.key < target):
    return searchNode(root.right, target)
  return searchNode(root.left, target)

proc insertNode(node: BTreeNode, value: int): BTreeNode =
  if (node.isNil()):
    return BTreeNode(key: value)
  if (value < node.key):
    node.left = insertNode(node.left, value)
  if (value > node.key):
    node.right = insertNode(node.right, value)
  return node

proc postOrder(root: BTreeNode)  = 
  if (root.isNil()): return
  postOrder(root.left)
  postOrder(root.right)
  stdout.write $root.key & " "

proc inOrder(root: BTreeNode) =
  if (root.isNil()): return
  inOrder(root.left)
  stdout.write $root.key & " "
  inOrder(root.right)

proc preOrder(root: BTreeNode) = 
  if (root.isNil()): return
  stdout.write $root.key & " "
  preOrder(root.left)
  preOrder(root.right)

proc findMin(root: BTreeNode): BTreeNode =
  if (root.isNil()): 
    return nil
  if (not root.left.isNil()):
    return findMin(root.left)
  return root

proc delete(root: BTreeNode, x: int): BTreeNode =
  if (root.isNil()):
    return nil
  if (x > root.key):
    root.right = delete(root.right, x)
    return root

  if (x < root.key):
    root.left = delete(root.left, x)
    return root

  if (root.left.isNil() and root.right.isNil()):
    return nil

  if (root.left.isNil() or root.right.isNil()):
    return if (root.left.isNil()): root.right 
      else: root.left

  let temp = findMin(root.right)
  root.key = temp.key
  root.right = delete(root.right, temp.key)
  return root

proc main() =
  let root = BTreeNode(key: 10)
  discard root.insertNode(20)
  discard root.insertNode(30)
  discard root.insertNode(40)

  echo()
  if (not root.searchNode(10).isNil()):
    echo "10 found"
  else:
    echo "10 not found"

  echo()
  root.postOrder()

  echo()
  root.preOrder()

  echo()
  root.inOrder()

  discard root.delete(20)
  discard root.delete(30)
  discard root.delete(40)

  echo "\n\nAfter Delete:"
  root.inOrder()
  echo()

main()
