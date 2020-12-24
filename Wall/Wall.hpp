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

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <atomic>
#include <thread>

class Wall {
	struct sBaseEntity_t;
	struct sBasePlayer_t;
	struct sEntityList_t;
	struct sGlowDefinitionObject_t;
	struct sGlowManager_t;
	struct sPlayerResource_t;
	
	std::vector<sEntityList_t> entities;

	Scanner* engineScanner 				= nullptr;
	Scanner* clientScanner 				= nullptr;
	
	sBasePlayer_t* localPlayer			= nullptr;
	sEntityList_t* entityList 			= nullptr;
	sGlowManager_t* glowManager 		= nullptr;
	sPlayerResource_t* playerResource	= nullptr;
	
	sGlowDefinitionObject_t* glow 		= nullptr;
	
	
	mach_vm_address_t engine_moduleStartAddress;
	off_t engine_moduleLength 			= 0;
	
	mach_vm_address_t client_moduleStartAddress;
	off_t client_moduleLength 			= 0;
	
	double refreshRate 					= 10000.0f;
	double maxFlash 					= 100.0f;
	bool noTeammates 					= false;
	bool noUtils 						= false;
	
	static Process* g_cProc;
	static MemMngr* mem;
	static sOffsets* off;
	
	static std::atomic<bool> stop;
	
public:
	explicit Wall(double refreshRate = 10000.0f, double maxFlash = 100.0f, bool noTeammates = false, bool noUtils = false);
	~Wall();
	
	void 		Run();

private:
	void 		Deinit();
	
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
	
	int 		SpottedBy();
	
	sOffsets::EntityType Type();
	
	Byte		EFlags();
	
	bool		IsDormant();
	bool 		LifeState();
	bool 		Spotted();
	bool		IsWeapon();
	bool		IsBomb();
	bool		IsChicken();
	bool		IsPlayer();
	
	bool 		IsValid();
	bool 		IsValid(uint64_t ptr);
	
	bool 		operator == (const sBaseEntity_t& rhs);
	
	void 		Print();
};

struct Wall::sBasePlayer_t: public sBaseEntity_t {
	double		FlashMaxAlpha();
	float		FlashDuration();
	
	int 		Health();
	int 		Team();
	int 		GlowIndex();
	int 		ShotsFired();
	
	bool 		HasMovedSinceSpawn();
	bool 		IsJumping();
	bool 		IsCrouching();
	
	void 		SetFlashMaxAlpha(double x);
	
	void 		Print();
	
};

struct Wall::sEntityList_t: public sBaseEntity_t {
	char 		m_SerialNum[0x8];
	uint64_t 	m_pPrevious;
	uint64_t 	m_pNext;
	
	void 		Print();
};

struct Wall::sGlowDefinitionObject_t: public sBaseEntity_t {
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

struct Wall::sGlowManager_t: public sBaseEntity_t {
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

struct Wall::sPlayerResource_t: public sBaseEntity_t {
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

#endif /* WALL_HPP */
