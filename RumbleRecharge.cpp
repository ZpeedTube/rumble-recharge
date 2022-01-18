#include "pch.h"
#include "RumbleRecharge.h"
#include "bakkesmod/wrappers/GameObject/CarWrapper.h"


BAKKESMOD_PLUGIN(RumbleRecharge, "Rumble Recharge - Game mode", plugin_version, PLUGINTYPE_THREADED)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

void RumbleRecharge::onLoad()
{
	_globalCvarManager = cvarManager;
	cvarManager->log("*** Rumble Recharge loaded ***");
	cvarManager->registerCvar("rumble_recharge_on", "0", "turn plugin on/off", true, true, 0, true, 1, false).addOnValueChanged(std::bind(&RumbleRecharge::OnChangeActive, this, std::placeholders::_1, std::placeholders::_2));

}

void RumbleRecharge::onUnload()
{
}


void RumbleRecharge::OnChangeActive(std::string oldValue, CVarWrapper cvar)
{
	if (oldValue.compare("0") == 0 && cvar.getBoolValue())
	{
		cvarManager->log(" enabled");
		gameWrapper->HookEvent("Function TAGame.Car_TA.SetVehicleInput", bind(&RumbleRecharge::ApplyCarMovement, this, std::placeholders::_1));
	}
	else if (oldValue.compare("1") == 0 && !cvar.getBoolValue())
	{
		cvarManager->log(" disabled");
		gameWrapper->UnhookEvent("Function TAGame.Car_TA.SetVehicleInput");
	}
}


void RumbleRecharge::ApplyCarMovement(std::string eventName)
{
	if (!gameWrapper->IsInGame())
		return;
	auto server = gameWrapper->GetGameEventAsServer();

	auto cars = server.GetCars();

	for(CarWrapper car : cars)
	{
		auto pickup = car.GetAttachedPickup();
		if (!pickup)
		{
			car.Stop();
		}
	}
}
