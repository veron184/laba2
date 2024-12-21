#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace_text(const char *filename, const char *old_text, const char *new_text) {
    FILE *file = fopen(filename, "r");
    if (!file) {
perror("Ошибка открытия файла");
return;
    }

char *buffer = NULL;
    size_t size = 0;
    size_t length_old = strlen(old_text);
    size_t length_new = strlen(new_text);


fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET);

buffer = (char *)malloc(fsize + 1);
    fread(buffer, 1, fsize, file);
    buffer[fsize] = '\0';

fclose(file);


char *pos = strstr(buffer, old_text);
    while (pos) {
size_t offset = pos - buffer;
char *new_buffer = (char *)malloc(fsize - length_old + length_new + 1);

strncpy(new_buffer, buffer, offset);
strcpy(new_buffer + offset, new_text);
strcpy(new_buffer + offset + length_new, buffer + offset + length_old);

free(buffer);
buffer = new_buffer;
fsize = fsize - length_old + length_new;
pos = strstr(buffer, old_text);
}

file = fopen(filename, "w");
if (!file) {
perror("Ошибка открытия файла для записи");
free(buffer);
return;
}

fwrite(buffer, 1, fsize, file);
fclose(file);
free(buffer);
}

int main(int argc, char *argv[]) {
if (argc != 4) {
fprintf(stderr, "Использование: %s <файл> <старый текст> <новый текст>\n", argv[0]);
return 1;
}

replace_text(argv[1], argv[2], argv[3]);
return 0;
}
