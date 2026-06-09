import strformat

proc towerOfHanoi(
  diskNumber: int,
  fromRod: char,
  toRod: char,
  auxRod: char
) =
  if diskNumber == 1:
    echo &"Move disk 1 from {fromRod} to rod {toRod}"
    return

  towerOfHanoi(diskNumber-1, fromRod, auxRod, toRod)
  echo &"Move disk {diskNumber} from rod {fromRod} to rod {toRod}"
  towerOfHanoi(diskNumber-1, auxRod, toRod, fromRod)

proc main() =
  let diskNumber = 4
  towerOfHanoi(diskNumber, 'A', 'C', 'B')
  echo()

when isMainModule:
  main()
