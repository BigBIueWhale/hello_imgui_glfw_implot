#include <hello_imgui/hello_imgui.h>
#include <implot/implot.h>
#include <vector>
#include <cstdint> 

static void GuiCode()
{
    ImGui::Begin("hello_world_window");
    ImGui::Text("Hello, world!");
    ImGui::End();

    const auto bar_data = std::vector<float>{
        {
            1.0, 2.0, 3.0, 4.0, 3.0, 2.0, 1.0, 1.0, 2.0, 2.0, 3.0, 1.0, 4.0, 4.0, 6.0, 3.0, 3.0, 3.0, 2.0
        }
    };
    const auto x_data = std::vector<float>{
        {
            0.0, 2.0, 4.0, 8.0, 16.0
        }
    };
    const auto y_data = std::vector<float>{
        {
            0.0, 1.0, 2.0, 3.0, 4.0
        }
    };

    ImGui::Begin("graph_plot_window");
    if (ImPlot::BeginPlot("graph_plot1")) {
        ImPlot::PlotBars("My Bar Plot", bar_data.data(), bar_data.size());
        ImPlot::PlotLine("My Line Plot", x_data.data(), y_data.data(), x_data.size());
        ImPlot::EndPlot();
    }
    ImGui::End();
}

int main(const int argc, const char *const *const argv)
{
    ImPlot::CreateContext();
    HelloImGui::Run(
        [] { GuiCode(); },
        "Hello!"                             // Window title
    );
    ImPlot::DestroyContext();
    return 0;
}
