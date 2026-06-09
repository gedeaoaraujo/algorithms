proc partition(
  arr: var seq[int],
  low: int,
  high: int
): int =
  let p = arr[low]
  var i = low
  var j = high

  while i < j:
    while arr[i] <= p and i <= (high - 1): i += 1
    while arr[j] > p and j >= (low + 1): j -= 1
    if i < j: swap(arr[i], arr[j])

  swap(arr[low], arr[j])
  return j

proc quick_sort(
  arr: var seq[int],
  low: int,
  high: int
) =
  if low < high:
    let pi = partition(arr, low, high)
    quick_sort(arr, low, pi - 1)
    quick_sort(arr, pi + 1, high)

proc main() =
  var arr = @[4,2,7,5,3,1]
  let length = arr.len() - 1

  quick_sort(arr, 0, length)
  for item in arr: stdout.write $item & " "

  echo()

when isMainModule:
  main()
