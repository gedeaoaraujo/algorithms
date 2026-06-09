type Node = ref object
  data: int
  head: Node
  next: Node

proc newStack(): Node =
  Node(data: -1)

proc newNode(data: int): Node =
  Node(data: data)

proc isEmpty(node: Node): bool =
  return node.head.isNil

proc push(stack: var Node, data: int) =
  let node = newNode(data)
  node.next = stack.head
  stack.head = node
  echo "Push: " & $data

proc pop(stack: var Node) =
  if (stack.head == nil):
    echo "Trying to pop from empty"
    return

  let temp = stack.head
  stack.head = temp.next
  echo "Pop: " & $temp.data

proc peek(stack: Node) =
  if (stack.isEmpty):
    echo "Stack Overflow"
    return

  let data = stack.head.data
  echo "Peek: " & $data

proc toStr(stack: Node) =
  var tmp = stack.head
  while (not tmp.isNil):
    stdout.write $tmp.data & " -> "
    tmp = tmp.next

proc main() =
  var stack = newStack()
  for i in 1..5: stack.push(i)

  echo()
  for _ in 0..2: stack.pop()

  echo()
  for _ in 0..1: stack.peek()

  echo()
  stack.toStr()
  echo()

when isMainModule:
  main()
