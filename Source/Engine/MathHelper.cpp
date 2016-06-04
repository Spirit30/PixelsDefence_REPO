#include "MathHelper.h"

int MathHelper::Clip(const double & n, const double & lower, const double & upper) {

	return max(lower, min(n, upper));
}
