import strformat

func sentinelLinearSearch(
  arr: var openArray[int],
  length: int,
  target: int
): int =
  let last = arr[length]
  arr[length] = target

  var index = 0
  while not (arr[index] == target): index += 1

  arr[length] = last

  if index < length or arr[length] == target: 
    return index

  return -1

proc main() =
  let target = 4
  var arr = [3,5,1,8,2,6,4,8,7]
  echo(arr)

  let length = arr.len() - 1
  let res = sentinelLinearSearch(arr, length, target)

  if res == -1:
    echo &"Element {target} not found"
  else:
    echo &"Element {target} found at index {res}"

when isMainModule:
  main()
