#include <stdio.h>
#include <string.h>
#include "sed_operation.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
printf("Недостаточно аргументов\n");
return 1;
    }

const char *input_file = argv[1];

if (strcmp(argv[2], "-r") == 0) {
replace_text(input_file, argv[3], argv[4]);
    } else if (strcmp(argv[2], "-d") == 0) {
delete_lines(input_file, argv[3]);
    } else if (strcmp(argv[2], "-i") == 0 && strcmp(argv[3], "-f") == 0) {
insert_text(input_file, argv[4], 1);
    } else if (strcmp(argv[2], "-i") == 0 && strcmp(argv[3], "-b") == 0) {
insert_text(input_file, argv[4], 0);
    } else {
printf("Неверные аргументы\n");
return 1;
    }

return 0;
}
