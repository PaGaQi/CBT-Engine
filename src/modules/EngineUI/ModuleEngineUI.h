#pragma once
#include <src/modules/Module.h>
#include <src/helpers/Globals.h>
#include "DearImGUI/imgui.h"
#include <libs/SDL/include/SDL.h>
#include <vector>

class UI_Item;

class ModuleEngineUI : public Module
{
public:
	ModuleEngineUI(bool start_updated);
	~ModuleEngineUI();

	bool IsStaticModule() { return true; }

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	bool GetEvent(SDL_Event* e);

	void EngineUI_RegisterItem(UI_Item* item);
	void EngineUI_RequireUpdate(bool window_state)
	{
		require_update = require_update || !window_state;
	}

private:
	std::vector<UI_Item*> items;
	std::vector<uint32_t> active_items;
	bool require_update = false;

private:

	

	void EngineUI_UpdateActives();
};

extern ModuleEngineUI e_engine_ui;

