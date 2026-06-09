#include <stdio.h>

void tower_of_hanoi(
  int disk_number,
	char from_rod,
	char to_rod,
	char aux_rod
){
  if (disk_number == 1){
    printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
    return;
  }

  tower_of_hanoi(disk_number-1, from_rod, aux_rod, to_rod);
  printf("\n Move disk %d from rod %c to rod %c", disk_number, from_rod, to_rod);
  tower_of_hanoi(disk_number-1, aux_rod, to_rod, from_rod);
}

int main(){
  int disk_number = 4;
  tower_of_hanoi(disk_number, 'A', 'C', 'B');
  printf("\n");
  return 0;
}
