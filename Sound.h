#ifndef SOUND_CLASS_H
#define SOUND_CLASS_H

#include <irrKlang/irrKlang.h>
#pragma comment(lib, "irrKlang.lib")

namespace GOAT_ENGINE {
	class Sound {
	protected:
		irrklang::ISoundEngine* engine;
	public:
		Sound();
		void play(const char* file, float volume, bool loop);
	};
}
#endif