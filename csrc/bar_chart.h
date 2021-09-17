#ifndef BAR_CHART_H
#define BAR_CHART_H

#define MAX_BARS ((WIDTH - MAX_NAME_LENGTH) / 3)
#define BARBLOCK '#'
#define BARBLOCK_HALF '='
#define BARBLOCK_QUARTER '.'

/* TYPES */
typedef struct BarChart Bar;

/* FUNCTION PROTOTYPES */
int get_number (Bar *series);
char *get_name (Bar *series);
void set_number (Bar *series, int number);
void set_name (Bar *series, char *name);
void print_bar(Bar *series, char *chart, int x_offset, float scale);
Bar *new_bar (int number, char *name);
#endif
