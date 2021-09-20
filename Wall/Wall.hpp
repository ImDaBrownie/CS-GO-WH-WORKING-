//
//  Wall.hpp
//  Wall
//
//  for csgo wall hack
//  special edition
//
//  Created by sheep on 16/5/14.
//  Copyright © 2016年 nadp. All rights reserved.
//
//  Edited by Fricker95 on 1/1/20.

#ifndef WALL_HPP
#define WALL_HPP

#define MAX_ENTITIES 			0x4000
#define MAX_PLAYERS 			0x40

#define MAX_CLANTAG_LENGTH		0xF

#include "Scanner.hpp"
#include "MemMngr.hpp"
#include "Offsets.hpp"
#include "ColorText.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <atomic>
#include <thread>

class Wall {
	struct sBaseEntity_t;
	struct sBasePlayer_t;
	struct sBaseCombatWeapon_t;
	struct sBaseCSGrenadeProjectile_t;
	struct sBasePlantedC4_t;
	struct sEntityList_t;
	struct sGlowDefinitionObject_t;
	struct sGlowManager_t;
	struct sPlayerResource_t;

	class C_RadarBase;
	class C_RadarManager;
	class C_RadarObject;
	class C_RadarStruct;
	
	std::vector<sEntityList_t> entities;
	
	Scanner* engineScanner 				= nullptr;
	Scanner* clientScanner 				= nullptr;
	
	sBasePlayer_t* localPlayer			= nullptr;
	sEntityList_t* entityList 			= nullptr;
	sGlowManager_t* glowManager 		= nullptr;
	C_RadarManager* radarManager 		= nullptr;
	sPlayerResource_t* playerResource	= nullptr;
	
	sBasePlayer_t* player 				= nullptr;
	sGlowDefinitionObject_t* glow 		= nullptr;
	sBaseCombatWeapon_t* weapon 		= nullptr;
	sBaseCSGrenadeProjectile_t* proj	= nullptr;
	
	mach_vm_address_t engine_moduleStartAddress;
	off_t engine_moduleLength 			= 0;
	
	mach_vm_address_t client_moduleStartAddress;
	off_t client_moduleLength 			= 0;
	
	double refreshRate 					= 10000.0f;
	double maxFlash 					= -1.0f;
	double glowAlpha 					= 0.5f;
	bool noRanks 						= false;
	bool noTeammates 					= true;
	bool noUtils 						= true;
	bool spotted 						= false;
	
	static Process* g_cProc;
	static MemMngr* mem;
	static sOffsets* off;
	
	static std::atomic<bool> stop;
	static std::atomic<bool> revealRank;
	
public:
	explicit Wall(double refreshRate, double maxFlash, double glowAlpha, bool noTeammates, bool noUtils, bool noRanks, bool spotted);
	~Wall();
	
	void 		Run();

private:
	void 		Deinit();
	
	void 		ParseEntityList();
	void		ApplyGlow();
	
	bool 		EngineCheck();
	bool 		ClientCheck();
		
	void 		GetEnginePointers();
	void 		GetClientPointers();
	
	void 		StopThread();
};

struct Wall::sBaseEntity_t {
	uint64_t 	m_hBase;

	std::string EntityClass();

	sOffsets::EntityType Type();

	Byte		EFlags();

	int 		ID();
	int 		Team();
	int 		SpottedBy();

	bool 		Spotted();
	bool		IsDormant();
	bool 		LifeState();
	bool		IsWeapon();
	bool		IsBomb();
	bool		IsChicken();
	bool		IsPlayer();

	bool 		IsValid();
	bool 		IsValid(uint64_t ptr);

	bool 		operator == (const sBaseEntity_t& rhs);

	void 		SetSpotted(bool x);
	void 		Print();
};

struct Wall::sBasePlayer_t: public Wall::sBaseEntity_t {
	double		FlashMaxAlpha();
	float		FlashDuration();

	int 		Health();
	int 		GlowIndex();
	int 		ShotsFired();

	bool 		HasMovedSinceSpawn();
	bool 		IsJumping();
	bool 		IsCrouching();

	void 		GetAllWeapons(uint64_t* weaponArray);
	uint64_t 	GetActiveWeapon();

	void 		SetFlashMaxAlpha(double x);

	void 		Print();

};

struct Wall::sBaseCombatWeapon_t: public Wall::sBaseEntity_t {
	int 		State();	
	void 		Print();
};

struct Wall::sBaseCSGrenadeProjectile_t: public Wall::sBaseCombatWeapon_t {
	int 		ExplodeEffectIndex();
	int 		ExplodeEffectTickBegin();
};

struct Wall::sBasePlantedC4_t: public Wall::sBaseEntity_t {
	int			State();
};

struct Wall::sEntityList_t: public Wall::sBaseEntity_t {
	char 		m_SerialNum[0x8];
	uint64_t 	m_pPrevious;
	uint64_t 	m_pNext;

	void 		Print();
};

struct Wall::sGlowDefinitionObject_t: public Wall::sBaseEntity_t {
	struct Vector {
		float r;
		float g;
		float b;
	};

	Vector 		m_vGlowColor;
	float 		m_flGlowAlpha;
	char 		unk1[0x10];
	bool 		m_bRenderWhenOccluded;
	bool 		m_bRenderWhenUnoccluded;
	bool 		FullBloom;
	char 		unk2[0x15];

	void 		Print();
};

struct Wall::sGlowManager_t: public Wall::sBaseEntity_t {
	int			m_iGlowListMaxSize;
	char 		unk1[0x4]; // padding
	int			m_iGlowListSize;
	char 		unk2[0x4]; // padding

	sGlowDefinitionObject_t Get(int index);

	int			Capacity();
	int 		Size();

	void 		Write(Wall::sGlowDefinitionObject_t* glowObject, int index);

	void 		Print();
};

struct Wall::sPlayerResource_t: public Wall::sBaseEntity_t {
	std::string Clan(int index);

	int 		Kills(int index);
	int		 	Assists(int index);
	int		 	Deaths(int index);
	int		 	Team2(int index);
	int	 		Health2(int index);
	int 		MVPs(int index);
	int			Armor(int index);
	int 		Score(int index);
	int 		CompetitiveRanking(int index);
	int			CompetitiveWins(int index);
	int 		TotalCashSpent(int index);
	int 		CashSpentThisRound(int index);

	bool 		Connected(int index);
	bool		HasDefuser(int index);
	bool 		HasHelmet(int index);

	void 		Print();
};

class Wall::C_RadarObject {
	char					unk[0x170];
	int 					m_iRadarHealth;
	char		 			m_szRadarName[0x8C];
public:
	C_RadarObject();
	
	int 					GetRadarHealth();
	std::string 			GetRadarName();
};

class Wall::C_RadarBase {
	char 					unk1[0x370]; // 0x370
	C_RadarObject 			m_dwRadarArray[0x40];
public:
	C_RadarBase();
	
	C_RadarObject 			GetRadarObject(int index);
};

class Wall::C_RadarStruct {
	char 					unk[0xF0]; // 0xF0
	uint64_t 				m_dwRadarBase;
public:
	C_RadarStruct();
	
	C_RadarBase 			GetRadarBase();
};

class Wall::C_RadarManager: public sBaseEntity_t {
public:
	C_RadarManager();
	
	C_RadarStruct 			GetRadarStruct();
};

#endif /* WALL_HPP */
