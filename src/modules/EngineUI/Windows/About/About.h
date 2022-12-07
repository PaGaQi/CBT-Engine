#pragma once

#include "../../ui_item.h"
#include "../../ModuleEngineUI.h"
#include <src/modules/ECS/ModuleECS.h>

struct About : public UI_Item {
	std::string entity_id_str;
	Entity* entity = nullptr;

	About() : UI_Item("About") {};

	RMPopupMenu rm_menu;
	void UpdateRMMenu();

	void Update();
};