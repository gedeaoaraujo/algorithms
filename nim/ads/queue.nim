const ARRAY_SIZE = 5

type Queue = object
  items: array[ARRAY_SIZE, int]
  front: int
  rear: int

proc newQueue(): Queue = 
  Queue(front: -1, rear: 0)

proc isEmpty(queue: Queue): bool =
  queue.front == (queue.rear - 1)

proc isFull(queue: Queue): bool =
  queue.rear == ARRAY_SIZE

proc enqueue(queue: var Queue, value: int) = 
  if (queue.isFull()):
    echo "Queue is full"
    return

  queue.items[queue.rear] = value
  queue.rear += 1
  echo "Enqueue: " & $value

proc dequeue(queue: var Queue) =
  if (queue.isEmpty()):
    echo "Queue is empty"
    return

  queue.front += 1

proc peek(queue: var Queue) =
  if (queue.isEmpty()):
    echo "Queue is empty"

  queue.front += 1
  echo "Picked: " & $queue.items[queue.front]

proc print(queue: Queue) =
  if (queue.isEmpty()):
    echo "Queue is empty"
    return

  echo "Current Queue: "
  for i in queue.front+1 ..< queue.rear:
    echo queue.items[i]
  echo()

proc main() =
  var q = newQueue()
  q.enqueue(10)
  q.enqueue(20)
  q.enqueue(30)
  q.enqueue(40)
  q.enqueue(50)
  q.enqueue(60)
  # q.print()

  echo()
  q.peek()
  q.peek()
  q.peek()
  # q.dequeue()

  echo()
  q.print()

when isMainModule:
  main()
