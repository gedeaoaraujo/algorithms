import sugar

proc merge(
  arr: var openArray[int],
  left: int, mid: int, right: int
) =
  let n1 = mid - left + 1
  let n2 = right - mid

  let leftArr = collect:
    for i in 0 ..< n1: arr[left + i]

  let rightArr = collect:
    for j in 0 ..< n2: arr[mid + 1 + j]

  var i, j = 0
  var k = left

  while i < n1 and j < n2:
    if leftArr[i] <= rightArr[j]:
      arr[k] = leftArr[i]; i += 1 
    else:
      arr[k] = rightArr[j]; j += 1
    k += 1

  while i < n1:
    arr[k] = leftArr[i]
    i += 1; k += 1

  while j < n2:
    arr[k] = rightArr[j]
    j += 1; k += 1

proc mergeSort(arr: var openArray[int], left: int, right: int) =
  if left >= right: return
  let mid = left + int((right-left) / 2)
  mergeSort(arr, left, mid)
  mergeSort(arr, mid + 1, right)
  merge(arr, left, mid, right)

proc main() =
  var arr = [12,11,13,5,6,7]
  mergeSort(arr, 0, arr.len - 1)

  for i in 0 ..< arr.len:
    stdout.write $arr[i] & " "

  echo()

when isMainModule:
  main()
