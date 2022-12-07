#pragma once
#include "../../ui_item.h"
#include "../../ModuleEngineUI.h"
#include <src/modules/Render/RendererTypes.h>

class SceneView : UI_Item {
	GPUFBO fb;
public:
	SceneView() : UI_Item("Scene View") {};
	void Start();
	void Update();

	void CleanUp();

public:
	enum View
	{
		Scene,
		Game,
	};
	View engineView = Game;
};