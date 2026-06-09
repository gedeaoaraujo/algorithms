proc insertionSort(arr: var openArray[int]) =
  for i in 0 ..< arr.len:
    let key = arr[i]
    var j = i - 1

    while j >= 0 and arr[j] > key:
      arr[j + 1] = arr[j]
      j = j - 1

    arr[j + 1] = key

proc main() =
  var arr = [2,12,4,11,8,13,5,6]

  echo "Unsorted array: "
  for i in 0 ..< arr.len:
    stdout.write $arr[i] & " "
  echo()

  arr.insertionSort()

  echo "Sorted array"
  for i in 0 ..< arr.len:
    stdout.write $arr[i] & " "
  echo()

when isMainModule:
  main()
