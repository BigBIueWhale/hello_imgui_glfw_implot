#include "hello_imgui/hello_imgui.h"

static void GuiCode()
{
    ImGui::Begin("hello_world");
    ImGui::Text("Hello, world!");
    ImGui::End();
}

int main(const int argc, const char *const *const argv)
{
    HelloImGui::Run(
        [] { GuiCode(); },
        "Hello!"                             // Window title
    );
    return 0;
}
