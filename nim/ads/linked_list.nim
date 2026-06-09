import strformat

type Node = ref object
  data: int
  next: Node

func newNode(data: int): Node =
  Node(data: data)

proc insertFront(head: var Node, data: int) =
  let node = newNode(data)
  node.next = head
  head = node

proc insertEnd(head: var Node, data: int) =
  let node = newNode(data)
  if head.isNil():
    head = node
    return

  var temp = head
  while not temp.next.isNil():
    temp = temp.next

  temp.next = node

proc inserAt(head: var Node, data: int, position: int) =
  let node = newNode(data)
  if position == 0: insertFront(head, data)

  var temp = head
  for i in 0 ..< position: temp = temp.next

  if temp.isNil():
    echo "Position out of range"
    return

  node.next = temp.next
  temp.next = node

proc deleteFirst(head: var Node) =
  if head.isNil():
    echo "List is empty"
    return

  let temp = head
  head = temp.next

proc deleteLast(head: var Node) =
  if head.isNil():
    echo "List is empty"
    return

  var temp = head
  if temp.next.isNil():
    head = nil
    return

  while temp.next.next != nil:
    temp = temp.next

  temp.next = nil

proc deleteAt(head: var Node, position: int) = 
  if head.isNil():
    echo "List is empty"
    return

  var temp = head
  if position == 0:
    deleteFirst(head)
    return

  for i in 0 ..< position:
    temp = temp.next

  let next = temp.next.next
  temp.next = next

proc print(head: var Node) =
  var temp = head
  stdout.write "|"
  while temp != nil:
    stdout.write &" {temp.data} |"
    temp = temp.next
  echo()

proc main() =
  var node = newNode(0)
  node.print()

  node.insertFront(1)
  node.print()

  node.insertEnd(2)
  node.print()

  node.inserAt(3, 1)

  echo()
  node.print()
  echo()

  node.deleteAt(1)
  node.print()

  node.deleteLast()
  node.print()

  node.deleteFirst()
  node.print()

when isMainModule:
  main()
