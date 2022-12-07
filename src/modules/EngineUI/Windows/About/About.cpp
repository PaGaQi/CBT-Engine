#include "About.h"
#include <src/Application.h>

void About::UpdateRMMenu() {
	rm_menu.CheckToOpen();
}

void About::Update() 
{
    SysInfo& info = Application::Get().GetSystemInfo();

    ImGui::Begin("CBTEngine", &active);
    ImGui::BulletText("CBT Engine");
    ImGui::Separator();

    ImGui::Text("CREATED BY:");
    if (ImGui::Button("Pau Garcia"))
        Application::Get().GetUrl("https://github.com/PaGaQi");
    if (ImGui::Button("Jose Antonio Atencia"))
        Application::Get().GetUrl("https://github.com/JedTyde");
    ImGui::Separator();

    ImGui::Text("LIBRARIES USED:");
    ImGui::BulletText("Assimp 3.1.1");
    ImGui::BulletText("GLAD 2.0.0");
    ImGui::BulletText("GLFW 3.4");
    ImGui::BulletText("SDL 2.0.6");
    ImGui::BulletText("SDL Mixer 2.0.0");
    ImGui::BulletText("ImGui 1.5.1");
    ImGui::BulletText("GLM 0.9.9.8");
    ImGui::BulletText("OpenGL 3.1");
    ImGui::BulletText("Rapidjson 1.1.0");
    ImGui::BulletText("Spdlog v1.10.0");
    ImGui::BulletText("Stb Image v2.27");

    ImGui::Separator();

    ImGui::Text("MIT LICENSE:");
    ImGui::Text("");
    ImGui::Text("Copyright(c) 2022 JedTyde and PaGaQi\n");

    ImGui::Text("Permission is hereby granted, free of charge, to any person obtaining a copy");
    ImGui::Text(" of this software and associated documentation files (the 'Software'), to deal");
    ImGui::Text("in the Software without restriction, including without limitation the rights");
    ImGui::Text("to use, copy, modify, merge, publish, distribute, sublicense, and /or sell");
    ImGui::Text("copies of the Software, and to permit persons to whom the Software is");
    ImGui::Text("furnished to do so, subject to the following conditions :");

    ImGui::Text("The above copyright noticeand this permission notice shall be included in all");
    ImGui::Text("copies or substantial portions of the Software.");

    ImGui::Text("THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR");
    ImGui::Text("IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,");
    ImGui::Text("FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE");
    ImGui::Text("AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER");
    ImGui::Text("LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,");
    ImGui::Text("OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE");
    ImGui::Text("SOFTWARE.");

    ImGui::Separator();
    ImGui::End();
}