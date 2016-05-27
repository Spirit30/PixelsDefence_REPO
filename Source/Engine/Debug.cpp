#include "Debug.h"

void Debug::Log(const char * text){

	fprintf(stderr, text);
}
