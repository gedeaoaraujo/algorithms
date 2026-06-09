const ARRAY_SIZE = 10

type Stack = object
  top: int
  arr: array[ARRAY_SIZE, int]

proc newStack(): Stack =
  Stack(top: -1)

proc isEmpty(stack: Stack): bool =
  stack.top == -1

proc isFull(stack: Stack): bool =
  stack.top == (ARRAY_SIZE - 1)

proc push(stack: var Stack, value: int) =
  if (stack.isFull()):
    echo "Stack Overflow"
    return

  let topp = stack.top + 1
  stack.top += 1
  stack.arr[topp] = value
  echo "Pushed " & $value & " onto the stack"

proc pop(stack: var Stack) =
  if (stack.isEmpty()):
    echo "Stack Overflow"
    return

  let popped = stack.arr[stack.top]
  echo "Popped " & $popped & " from the stack"
  stack.top -= 1

proc peek(stack: var Stack): int =
  if (stack.isEmpty()):
    echo "Stack is empty"
    return

  let popped = stack.arr[stack.top]
  echo "Peeked " & $popped & " from the stack"
  stack.arr[stack.top]

proc print(stack: Stack) =
  for i in countdown(stack.top, 0):
    echo stack.arr[i]

proc main() =
  var stack = newStack()
  stack.push(10)
  stack.push(20)
  stack.push(30)
  stack.push(40)
  stack.push(50)
  stack.push(60)
  stack.push(70)
  stack.push(80)
  stack.push(90)

  echo()
  stack.pop()
  stack.pop()
  stack.pop()
 
  echo()
  discard stack.peek()
  discard stack.peek()
  discard stack.peek()

  echo()
  stack.print()
  echo()

when isMainModule:
  main()
