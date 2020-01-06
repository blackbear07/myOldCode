#pragma once
#include <iostream>
#include "Memory.h"
#include "Offsets.h"
#include <clocale>


Memory mem;
PModule bClient;
PModule bEngine;
Offsets offsets;

class Hack
{
	
	public:static bool Start()
	{
		while (!mem.Attach("csgo.exe", PROCESS_ALL_ACCESS))
		{
			return false;
		}
		bClient = mem.GetModule("client_panorama.dll");
		bEngine = mem.GetModule("Engine.dll");
		return true;
	}
		

	static void DrawEntity(int ClowIndex, int red, int green, int blue)
	{
		DWORD GlowObhect = mem.Read<DWORD>(bClient.dwBase + offsets.dwGlowObjectManager);
		mem.Write<float>(GlowObhect + (ClowIndex * 0x38) + 0x4, red / 100.f);
		mem.Write<float>(GlowObhect + (ClowIndex * 0x38) + 0x8, green / 100.f);
		mem.Write<float>(GlowObhect + (ClowIndex * 0x38) + 0xC, blue / 100.f);
		mem.Write<float>(GlowObhect + (ClowIndex * 0x38) + 0x10, 255 / 100.f);
		mem.Write<bool>(GlowObhect + (ClowIndex * 0x38) + 0x24, true);
		mem.Write<bool>(GlowObhect + (ClowIndex * 0x38) + 0x25, false);
	}
	public:static void ShowWallHaks()
	{
		DWORD LocalPlayer = mem.Read<DWORD>(bClient.dwBase + offsets.dwLocalPlayer);
		DWORD localHealt = mem.Read<DWORD>(LocalPlayer + offsets.m_iHealth);
		DWORD PlayerTeam = mem.Read<DWORD>(LocalPlayer + offsets.m_iTeamNum);
		DWORD Healt = mem.Read<DWORD>(localHealt + offsets.dwLocalPlayer);
		for (int i = 0; i < 64; i++)
		{
			DWORD EntityList = mem.Read<DWORD>(bClient.dwBase + offsets.dwEntityList + i * 0x10);
			DWORD EntityTeam = mem.Read<DWORD>(EntityList + offsets.m_iTeamNum);
			DWORD HealtList = mem.Read<DWORD>(bClient.dwBase + offsets.dwEntityList + i * 0x10);
			DWORD HealtEntityTeam = mem.Read<DWORD>(HealtList + offsets.m_iHealth);

			if (EntityTeam != 0 && EntityTeam != PlayerTeam)
			{
				DWORD GlowIndex = mem.Read<DWORD>(EntityList + offsets.m_iGlowIndex);
				DrawEntity(GlowIndex, (200 - HealtEntityTeam * 2), (HealtEntityTeam * 2) - 25, 0);
			}
			if (EntityTeam != 0 && EntityTeam == PlayerTeam)
			{
				DWORD GlowIndex = mem.Read<DWORD>(EntityList + offsets.m_iGlowIndex);
				DrawEntity(GlowIndex, 0, 0, 255);
			}
		}
	}
	public:static void ShowBunnyHop()
	{
		DWORD LocalPlayer = mem.Read<DWORD>(bClient.dwBase + offsets.dwLocalPlayer);
		int CanJump = mem.Read<DWORD>(LocalPlayer + offsets.m_fFlags);
		if (GetAsyncKeyState(32) && CanJump == 257) {
			mem.Write<int>(bClient.dwBase + offsets.dwForceJump, 5);
			Sleep(25);
			mem.Write<int>(bClient.dwBase + offsets.dwForceJump, 4);
		}
	}
	public:static void ShowTriggerBot()
	{
		DWORD LocalPlayer = mem.Read<DWORD>(bClient.dwBase + offsets.dwLocalPlayer);
		DWORD LocalHealt = mem.Read<DWORD>(LocalPlayer + offsets.m_iHealth);

		if (!LocalHealt) return;

		DWORD TeanNum = mem.Read<DWORD>(LocalPlayer + offsets.m_iTeamNum);

		DWORD CrossHaiId = mem.Read<DWORD>(LocalPlayer + offsets.m_iCrosshairId);

		if (!CrossHaiId || CrossHaiId > 64) return;

		DWORD entityBase = mem.Read<DWORD>(bClient.dwBase + offsets.dwEntityList + (CrossHaiId - 1) * 0x10);

		if (!entityBase) return;

		DWORD entityHealt = mem.Read<DWORD>(entityBase + offsets.m_iHealth);
		DWORD entityTeam = mem.Read<DWORD>(entityBase + offsets.m_iTeamNum);

		if (!entityHealt || entityTeam == TeanNum) return;

		Sleep(3);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	}

	/*Vector getBonePos(int pTargetIn, int bone) 
	{
		const int matrix = mem.Read<int>(pTargetIn + offsets.m_dwBoneMatrix);
		return Vector(
			mem.Read<float>(matrix + 0x30 * bone + 0xC),
			mem.Read<float>(matrix + 0x30 * bone + 0x1C),
			mem.Read<float>(matrix + 0x30 * bone + 0x2C)
		);
	}

	void setViewAngele(DWORD EngineBase, Vector angle)
	{
		ClampAngles(angle);
		NormalizeAngles(angle);

		mem.Write(EngineBase + offsets.dwClientState_ViewAngles, angle);
	}

	Vector AngelToTarget(int pLocal, int pTargetIn, int boneIndex) 
	{
		const Vector position = mem.Read<Vector>(pLocal + offsets.m_vecOrigin);
		const Vector vecView = mem.Read<Vector>(pLocal + offsets.m_vecViewOffset);

		const Vector myView = position + vecView;
		const Vector aimView = getBonePos(pTargetIn , boneIndex);

		Vector dst = CalcAngle(myView , aimView).ToVector();

		NormalizeAngles(dst);
		return dst;
		
	}

	int getTarget(int pLocal, int clientState) {
		int currentTarget = -1;
		float misDist = 360.f;

		Vector _viweAngels = mem.Read<Vector>(clientState + offsets.dwClientState_ViewAngles);

		const int playerTeam = mem.Read<int>(pLocal + offsets.m_iTeamNum);

		for (int i = 0; i <= 64; i++) 
		{
			const int target = mem.Read<int>(bClient.dwBase + offsets.dwEntityList + i * 0x10);
			if (!target || target < 0)
				continue;

			const int targetHealt = mem.Read<int>(target + offsets.m_iHealth);
			if (!targetHealt || targetHealt < 0)
				continue;

			const int targetTeam = mem.Read<int>(target + offsets.m_iTeamNum);

			if (!targetTeam || targetTeam == playerTeam)
				continue;

			const bool targetDormant = mem.Read<bool>(target + offsets.m_bDormant);
			if (targetDormant) 
				continue;

			Vector angeleTotaget = AngelToTarget(pLocal,target,8);
			float fov = GetFov(_viweAngels.ToQAngle(), angeleTotaget.ToQAngle());
			if(fov < misDist && fov <= 360) {
				misDist = fov;
				currentTarget = target;

			}
		}
		return currentTarget;
	}

	public: void ShowAimBot()
	{
		int pLocal = mem.Read<int>(bClient.dwBase + offsets.dwLocalPlayer);
		int pEngine = mem.Read<int>(bEngine.dwBase + offsets.dwClientState);
		int target = getTarget(pLocal, pEngine);
		setViewAngele(pEngine,AngelToTarget(pLocal,target,8));
		
	}*/
};
