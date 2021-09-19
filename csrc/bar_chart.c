#include <string.h>
#include <stdlib.h>

#include "constants.h"
#include "bar_chart.h"
#include "utils.h"

/* TYPES */
struct BarChart {
	float number;
	char name[MAX_NAME_LENGTH];
};

/* FUNCTION DEFINITIONS */

void
print_bar(Bar *series, char *chart, int x_offset, float scale)
{
	float diff;
	int y_offset = 1;
	float diff_margin = 1.0;
	int plotted_number = 0;
	int height = HEIGHT - 1;
	char barblock = BARBLOCK;
	int name_len = strlen(bar_get_name(series));
	float scaled_height = height - (bar_get_number(series) * scale);

	x_offset = (x_offset < 1) ? 1 : x_offset;
	x_offset += name_len / 2;

	int i = y_offset;
	for (; i<height; ++i) {
		diff = (float) i - scaled_height;

		/* print number on top of bar */
		if (-diff_margin <= diff && diff <= diff_margin && !plotted_number) {
			char *str = float2str(bar_get_number(series));
			strncpy(&chart[i * WIDTH + x_offset - strlen(str)/2], str, strlen(str));
			plotted_number = 1;
			free(str);
		} else {
			chart[i * WIDTH + x_offset] = (i > scaled_height) ?
				barblock : BLANK;
		}
	}

	strncpy(&chart[i * WIDTH + x_offset - name_len/2], bar_get_name(series), name_len);
}

float
bar_get_number (Bar *series)
{
	return series->number;
}

char *
bar_get_name (Bar *series)
{
	return series->name;
}

void
bar_set_number (Bar *series, float number)
{
	series->number = number;
}

void
bar_set_name (Bar *series, char *name)
{
	int len = (strlen(name) > MAX_NAME_LENGTH) ?
		MAX_NAME_LENGTH : strlen(name);
	strncpy(series->name, name, len);
}

struct BarChart *
new_bar (float number, char *name)
{
	int len = (strlen(name) > MAX_NAME_LENGTH) ?
		MAX_NAME_LENGTH : strlen(name);

	Bar *b = malloc(sizeof(Bar));
	b->number = number;
	strncpy(b->name, name, len);
	return b;
}
