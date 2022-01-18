//#include "pch.h"
//#include "RumbleRecharge.h"
//#include "bakkesmod\wrappers\Engine\"

 //Plugin Settings Window code here
//std::string RumbleRecharge::GetPluginName() {
//	return "Rumble Recharge";
//}
//
//void RumbleRecharge::SetImGuiContext(uintptr_t ctx) {
//	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
//}
//
//// Render the plugin settings here
//// This will show up in bakkesmod when the plugin is loaded at
////  f2 -> plugins -> RumbleRecharge
//void RumbleRecharge::RenderSettings() {
//	ImGui::TextUnformatted("RumbleRecharge plugin settings");
//}
//
//
//
//// Do ImGui rendering here
//void RumbleRecharge::Render()
//{
//	if (!ImGui::Begin(menuTitle_.c_str(), &isWindowOpen_, ImGuiWindowFlags_None))
//	{
//		// Early out if the window is collapsed, as an optimization.
//		ImGui::End();
//		return;
//	}
//
//	ImGui::End();
//
//	if (!isWindowOpen_)
//	{
//		cvarManager->executeCommand("togglemenu " + GetMenuName());
//	}
//}
//
//// Name of the menu that is used to toggle the window.
//std::string RumbleRecharge::GetMenuName()
//{
//	return "Rumble Recharge";
//}
//
//// Title to give the menu
//std::string RumbleRecharge::GetMenuTitle()
//{
//	return menuTitle_;
//}
//
//// Don't call this yourself, BM will call this function with a pointer to the current ImGui context
////void RumbleRecharge::SetImGuiContext(uintptr_t ctx)
////{
////	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
////}
//
//// Should events such as mouse clicks/key inputs be blocked so they won't reach the game
//bool RumbleRecharge::ShouldBlockInput()
//{
//	return ImGui::GetIO().WantCaptureMouse || ImGui::GetIO().WantCaptureKeyboard;
//}
//
//// Return true if window should be interactive
//bool RumbleRecharge::IsActiveOverlay()
//{
//	return true;
//}
//
//// Called when window is opened
//void RumbleRecharge::OnOpen()
//{
//	isWindowOpen_ = true;
//}
//
//// Called when window is closed
//void RumbleRecharge::OnClose()
//{
//	isWindowOpen_ = false;
//}
//
