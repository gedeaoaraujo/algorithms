import strformat

proc loopSearch(
  arr: openArray[int],
  startArr: var int,
  endArr: var int,
  key: int
): int =
  while startArr <= endArr:
    let mid: int = startArr + int((endArr - startArr) / 2)

    if arr[mid] == key: return

    if arr[mid] < key:
      startArr = mid + 1
    else:
      endArr = mid - 1

  return -1

proc recursiveSearch(
  arr: openArray[int],
  startArr: int,
  endArr: int,
  value: int
): int =
  if endArr < startArr:
    echo "Index out of range"
    return -1

  let mid = startArr + int((endArr - startArr) / 2)
  if arr[mid] == value: return mid

  if arr[mid] > value:
    return recursiveSearch(arr, startArr, mid - 1, value)

  return recursiveSearch(arr, mid + 1, endArr, value)

proc main() =
  let value = 23
  let arr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
  let size = arr.len() - 1
  # let resultz = loopSearch(arr, size, key)
  let resultz = recursiveSearch(arr, 0, size, value)

  if resultz == -1:
    echo "Element is not present in array"
  else:
    echo &"Element is present at index {resultz}"

when isMainModule:
  main()
