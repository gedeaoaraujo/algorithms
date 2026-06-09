proc bubbleSort(arr: var openArray[int]) =
  for i in 0 ..< arr.len():
    var swapped = false

    for j in 0 ..< ((arr.len()-1) - i):
      if arr[j] > arr[j + 1]:
        swap(arr[j], arr[j + 1])
        swapped = true

    if not swapped: break

proc main() =
  var arr = [6, 0, 3, 5, 7, 9, 2, 1, 4, 8]
  bubbleSort(arr)

  for i in 0 ..< arr.len():
    stdout.write $arr[i] & " "

  echo()

when isMainModule:
  main()
