#pragma once

#include <src/helpers/Globals.h>
#include <src/helpers/Timer/sque_timer.h>
#include <src/modules/Module.h>
#include <src/modules/ModuleWindow.h>
#include <src/modules/ModuleInput.h>
#include <src/modules/Render/ModuleRenderer3D.h>
#include <src/modules/ModuleCamera3D.h>
#include <src/modules/Camera.h>
#include <src/modules/EngineUI/ModuleEngineUI.h>
#include <src/modules/FileSystem/ModuleFS.h>
#include <src/modules/ECS/ModuleECS.h>

#include<list>
#include<vector>

struct SysInfo
{
	SysInfo() = default;

	char glfwVer[32];
};

class Application
{
public:
	ModuleWindow* window;
	ModuleInput* input;
	ModuleRenderer3D* renderer3D;
	ModuleCamera3D* camera;
	Camera* cam2;
	ModuleEngineUI* engine_ui;
	ModuleFS* fs;
	ModuleECS* ecs; // = &_ecs;

private:
	TSCNS_Timer	ms_timer;
	float	dt;
	std::list<Module*> list_modules;

public:

	Application();
	~Application();
	inline static Application& Get() { return *s_Instance; }
	inline SysInfo& GetSystemInfo() { return m_SysInfo; }
	void GetUrl(const char* url);

	bool Init();

	update_status Update();
	bool CleanUp();

	void Save(JSON_Object* root_node);
	void Load(JSON_Object* root_node);
private:

	void AddModule(Module* mod);
	void PrepareUpdate();
	void FinishUpdate();
	static Application* s_Instance;
	SysInfo m_SysInfo;
};

extern Application* App;