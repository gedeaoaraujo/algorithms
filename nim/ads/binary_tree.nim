type Node = ref object
  data: int
  left: Node
  right: Node

func newNode(data: int): Node =
  Node(data: data)

proc insert(root: var Node, data: int) =
  var node = newNode(data)
  var rear = -1
  var front = -1
  var temp = Node()
  var queue: array[100, Node]
  rear += 1
  queue[rear] = root

  while front != rear:
    front += 1
    temp = queue[front]

    if temp.left == nil:
      temp.left = node
      return

    rear += 1
    queue[rear] = temp.left

    if temp.right == nil:
      temp.right = node
      return

    rear += 1
    queue[rear] = temp.right

func deepestRightNode(root: Node): Node =
  var temp = Node()
  var queue: array[100, Node]

  var rear = -1
  var front = -1

  rear += 1
  queue[rear] = root

  while front != rear:
    front += 1
    temp = queue[front]

    if temp.left != nil:
      rear += 1
      queue[rear] = temp.left

    if temp.right != nil:
      rear += 1
      queue[rear] = temp.right

  return temp

proc delDeepestRightNode(root: Node, dNode: Node) =
  var temp: Node
  var queue: array[100, Node]

  var rear = -1
  var front = -1

  rear += 1
  queue[rear] = root

  while front != rear:
    front += 1
    temp = queue[front]

    if temp == dNode:
      temp = nil
      return

    if temp.right != nil:
      if temp.right == dNode:
        temp.right = nil
        return
      else:
        rear += 1
        queue[rear] = temp.right

    if temp.left != nil:
      if temp.left == dNode:
        temp.left = nil
        return
      else:
        rear += 1
        queue[rear] = temp.left

proc deleteNode(root: var Node, data: int) =
  if root.isNil():
    echo "Tree is empty"
    return
  
  if root.left.isNil() and root.right.isNil():
    if root.data == data:
      root = nil
      return
    else:
      echo "Node not found."
      return

  var temp: Node
  var queue: array[100, Node]

  var rear = -1
  var front = -1
  
  rear += 1
  queue[rear] = root
  var keyNode: Node

  while front != rear:
    front += 1
    temp = queue[front]

    if temp.data == data:
      keyNode = temp

    if temp.left != nil:
      rear += 1
      queue[rear] = temp.left

    if temp.right != nil:
      rear += 1
      queue[rear] = temp.right

    if keyNode != nil:
      let deepest = root.deepestRightNode()
      keyNode.data = deepest.data
      root.delDeepestRightNode(deepest)
    else:
      echo "Node not found."

func searchNode(root: Node, data: int): Node =
  if root == nil: return nil
  var temp = Node();
  var queue: array[100, Node]

  var rear = -1;
  var front = -1;

  rear += 1
  queue[rear] = root;

  while front != rear:
    front += 1
    temp = queue[front]

    if temp.data == data:
      return temp

    if temp.left != nil:
      rear += 1
      queue[rear] = temp.left

    if temp.right != nil:
      rear += 1
      queue[rear] = temp.right
  
  return nil

proc inorderTraversal(root: Node) =
  if root.isNil(): return
  inorderTraversal(root.left)
  stdout.write $root.data & " "
  inorderTraversal(root.right)

proc main() =
  var root = newNode(10)

  # Inseting
  root.insert(20)
  root.insert(30)
  root.insert(40)
  root.insert(50)

  # Inorder traversal
  echo "Inorder traversal of the given Binary Search Tree is: "
  root.inorderTraversal()
  echo()

  # Deleting a node
  var value = 50
  root.deleteNode(value)
  echo "After deletion of: " & $value
  root.inorderTraversal()
  echo()

  # Inserting a new node
  value = 60
  root.insert(value)
  echo "After insertion of: " & $value
  root.inorderTraversal()
  echo()

  # Searching for a node
  value = 10
  let search_result = root.searchNode(value)
  if search_result != nil:
    echo "Node " & $value & " found in the BST."
  else:
    echo "Node " & $value & " not found in the BST."

when isMainModule:
  main()
