#ifndef SED_OPERATIONS_H
#define SED_OPERATIONS_H

void replace_text(const char *input_file, const char *old_text, const char *new_text);
void delete_lines(const char *input_file, const char *regex_str);
void insert_text(const char *input_file, const char *insert_text, int at_start);

#endif
