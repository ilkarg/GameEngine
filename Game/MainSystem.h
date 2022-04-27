#pragma once

#include "Player.h"
#include "Window.h"

class MainSystem {
public:
	void InitEngine();
	void ExitFromEngine(Window window, Player player);
};