#include "Sound.h"

GOAT_ENGINE::Sound::Sound(): engine(irrklang::createIrrKlangDevice()) {
}

void GOAT_ENGINE::Sound::play(const char* file, float volume, bool loop) {
	this->engine->play2D(file, loop);

}

