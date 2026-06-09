import strformat

func loopSearch(arr: openArray[int], key: int): int =
  for i in 0 ..< arr.len():
    if arr[i] == key: return i

  return -1

func recursiveSearch(
  arr: openArray[int], 
  key: int, index: int
): int =
  if index <= 0: return -1
  let target = index - 1
  if arr[target] == key: return target
  return recursiveSearch(arr, key, target)

proc main() =
  let key = 80
  let arr = [10, 50, 30, 70, 80, 60, 20, 90, 40]
  # let i = loopSearch(arr, key)
  let i = recursiveSearch(arr, key, arr.len())

  if i == -1: echo "Key not found"
  else: echo &"Key Found at index: {i}"

when isMainModule:
  main()
