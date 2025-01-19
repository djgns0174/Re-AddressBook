#pragma once
#include "list.h"
#include "UI.h"

class EventHandler {
private:
	UI* ui;

public:
	EventHandler(UI* pui) :ui(pui) {};
	~EventHandler();
	int run();
};