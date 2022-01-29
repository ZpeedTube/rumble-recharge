#include "pch.h"
#include "RumbleRecharge.h"

// Plugin Settings Window code here
std::string RumbleRecharge::GetPluginName() {
	return "Rumble Recharge";
}

void RumbleRecharge::SetImGuiContext(uintptr_t ctx) {
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));

}

// Render the plugin settings here
// This will show up in bakkesmod when the plugin is loaded at
//  f2 -> plugins -> RumbleRecharge
void RumbleRecharge::RenderSettings() {
	ImGui::TextUnformatted("Rumble Recharge plugin settings"); 

	CVarWrapper rumbleRechargeOn = cvarManager->getCvar("rumble_recharge_on");
	if (!rumbleRechargeOn) { return; }

	bool enabled = rumbleRechargeOn.getBoolValue();
	if (ImGui::Checkbox("Enable plugin", &enabled)) {
		rumbleRechargeOn.setValue(enabled);
	}

	if (ImGui::IsItemHovered()) {
		ImGui::SetTooltip("Enable Rumble Recharge mode");
	}
}

