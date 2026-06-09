proc selection_sort(arr: var seq[int]) =
  for i in 0 ..< arr.len:
    var min_idx = i
    for j in i+1 ..< arr.len:
      if arr[j] < arr[min_idx]: min_idx = j
    var temp = arr[min_idx]
    arr[min_idx] = arr[i]
    arr[i] = temp

proc main() =
  var arr = @[64, 25, 12, 22, 11]
  
  echo "Unsorted array: "
  for i in 0 ..< arr.len:
    stdout.write $arr[i] & " "
  echo()

  arr.selection_sort()

  echo "Sorted array: "
  for i in 0 ..< arr.len:
    stdout.write $arr[i] & " "

  echo()

when isMainModule:
  main()
