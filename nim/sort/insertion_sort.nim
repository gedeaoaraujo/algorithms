proc insertionSort(arr: var openArray[int], length: int) =
  for i in 0 ..< length:
    let key = arr[i]
    var j = i - 1

    while j >= 0 and arr[j] > key:
      arr[j + 1] = arr[j]
      j = j - 1

    arr[j + 1] = key

proc main() =
  var arr = [2,12,4,11,8,13,5,6]
  let length = arr.len()

  echo "Unsorted array: "
  for i in 0 ..< length: stdout.write $arr[i] & " "
  echo()

  arr.insertionSort(length)

  echo "Sorted array"
  for i in 0 ..< length: stdout.write $arr[i] & " "
  echo()

when isMainModule:
  main()
