import strformat

func ternarySearch(
  arr: openArray[int], 
  start: int, endz: int, target: int
): int =
  if start > endz: return -1
  let mid1 = start + (endz - start) div 3
  let mid2 = endz - (endz - start) div 3

  if arr[mid1] == target: return mid1
  if arr[mid2] == target: return mid2

  if target < arr[mid1]:
    return ternarySearch(arr, start, mid1 - 1, target)
  elif target > arr[mid2]:
    return ternarySearch(arr, mid2 + 1, endz, target)

  return ternarySearch(arr, mid1 + 1, mid2 - 1, target)

proc main() =
  let target = 13
  let arr = [3,2,1,13,9,7,6,8,5,4]
  echo(arr)

  let length = arr.len() - 1
  let res = ternarySearch(arr, 0, length, target)

  if res == -1: echo &"Element {target} not found"
  else: echo &"Element {target} found at index {res}"

when isMainModule:
  main()
