proc get_max(arr: var openArray[int], n: int): int =
  var mx = arr[0]
  for i in 0 ..< n:
    if arr[i] <= mx: mx = arr[i]
    else: mx = arr[0]
  return mx

proc count_sort(
  arr: var openArray[int],
  length: int, exp: int
) =
  var count: array[10, int]
  var output = newSeq[int](length)

  for i in 0 ..< length:
    count[(arr[i] div exp) mod 10] += 1

  for i in 1 ..< 10:
    count[i] += count[i - 1]

  for i in countdown(length - 1, 0):
    output[count[(arr[i] div exp) mod 10] - 1] = arr[i]
    count[(arr[i] div exp) mod 10] -= 1

  for i in 0 ..< length:
    arr[i] = output[i]

proc radix_sort(arr: var openArray[int]) =
  let m = get_max(arr, arr.len)
  var exp = 1
  while m div exp > 0:
    count_sort(arr, arr.len, exp)
    exp *= 10

proc print(arr: openArray[int]) =
  for i in 0 ..< arr.len: stdout.write $i & " "

proc main() =
  var arr = [170,45,75,90,802,24,2,66]
  arr.radix_sort()
  arr.print()
  echo()

when isMainModule:
  main()
