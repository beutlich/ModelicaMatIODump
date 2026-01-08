#include <array>
#include "ModelicaStandardTables.h"

constexpr const int smooth_linear = 1;
constexpr const int smooth_akima = 2;
constexpr const int smooth_constant = 3;
constexpr const int smooth_fritsch_butland = 4;
constexpr const int smooth_steffen = 5;
constexpr const int smooth_makima = 6;
constexpr const int smooth_cubic = 7;

constexpr const int extrapol_hold = 1;
constexpr const int extrapol_last_two = 2;
constexpr const int extrapol_periodic = 3;
constexpr const int extrapol_error = 4;

constexpr const int time_events_always = 1;
constexpr const int time_events_at_jumps = 2;
constexpr const int time_events_none = 3;

constexpr const int verbose_off = 0;
constexpr const int verbose_on = 1;

constexpr const char delimiter_comma[] = ",";
constexpr const char no_name[] = "";

int main(int argc, char *argv[])
{
	if (argc < 3) {
		return EXIT_FAILURE;
	}

	double dummy = 0.0;
	constexpr const auto cols = std::array<int, 1>{2};
	void *table = ModelicaStandardTables_CombiTimeTable_init2(
		argv[1], argv[2], &dummy, 0, 0, 0.0, cols.data(), cols.size(),
		smooth_linear, extrapol_error, 0.0, time_events_always, verbose_off);
	ModelicaStandardTables_CombiTimeTable_print(table);
	ModelicaStandardTables_CombiTimeTable_close(table);
	return EXIT_SUCCESS;
}
