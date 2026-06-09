proc heapify(arr: var openArray[int], size: int, i: int) =
  var maximum = i
  let leftIndex = 2 * i + 1
  let rightIndex = 2 * i + 2

  if leftIndex < size and arr[leftIndex] > arr[maximum]:
    maximum = leftIndex

  if rightIndex < size and arr[rightIndex] > arr[maximum]:
    maximum = rightIndex

  if maximum != i:
    swap(arr[i], arr[maximum])
    heapify(arr, size, maximum)

proc heapSort(arr: var openArray[int], size: int) =
  for i in countdown(int(size/2)-1, 0):
    heapify(arr, size, i)

  for i in countdown(size-1, 0):
    swap(arr[0], arr[i])
    heapify(arr, i, 0)

proc main() =
  var arr = [9,20,7,18,5,15,3,2]

  echo "Original Array: "
  for i in 0 ..< arr.len(): stdout.write $arr[i] & " "

  echo()
  heapSort(arr, arr.len())
  
  echo "Array after performing heap sort: "
  for i in 0 ..< arr.len(): stdout.write $arr[i] & " "
  echo()

when isMainModule:
  main()
