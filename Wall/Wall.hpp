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

#define MAX_ENTITIES 	0X4000
#define MAX_PLAYERS 	0X40

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
	struct sBaseEntityObject_t;
	struct sClientEntityList_t;
	struct sGlowDefinitionObject_t;
	struct sPlayerResourceObject_t;
	
	std::vector<sClientEntityList_t> entityList;

	Scanner* engineScanner 				= nullptr;
	Scanner* clientScanner 				= nullptr;
	
	sGlowDefinitionObject_t* glow 		= nullptr;
	sClientEntityList_t* entity 		= nullptr;
	sPlayerResourceObject_t* resource	= nullptr;
	
	uint64_t glow_ptr;
	uint64_t entity_ptr;
	uint64_t resources_ptr;
	uint64_t base_ptr;
	
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
	explicit Wall(double refreshRate = 1000.0f, double maxFlash = 100.0f, bool noTeammates = false, bool noUtils = false);
	~Wall();
	
	void 		run(bool getOff = false);

private:
	void 		deinit();
	
	void		applyGlow();

	void 		getOffsets();
	void 		getEnginePointers();
	void 		getClientPointers();
	
	void 		stopThread();
};

struct Wall::sBaseEntityObject_t {
	uint64_t 	m_hEntity;
	
	std::string entityClass();
	
	double		flashMaxAlpha();
	float		flashDuration();
	
	int 		health();
	int 		team();
	int 		glowIndex();
	int 		shotsFired();
	int 		spottedBy();
	
	sOffsets::EntityType entityType();
	
	Byte		EFlags();
	
	bool		isDormant();
	bool 		lifeState();
	bool 		spotted();
	bool 		hasMovedSinceSpawn();
	bool 		isJumping();
	bool 		isCrouching();
	bool		isWeapon();
	bool		isBomb();
	bool		isChicken();
	bool		isPlayer();
	
	bool 		isValidGlowEntity();
	bool 		isValidGlowEntity(uint64_t ptr);
	
	void 		setFlashMaxAlpha(double x);
	
	void 		print();
};

struct Wall::sGlowDefinitionObject_t: public sBaseEntityObject_t {
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
	
	bool 		operator == (const sGlowDefinitionObject_t& rhs);
	bool 		operator == (const sClientEntityList_t& rhs);
	
	void 		print();
};

struct Wall::sClientEntityList_t: public sBaseEntityObject_t {
	char 		m_SerialNum[0x8];
	uint64_t 	m_pPrevious;
	uint64_t 	m_pNext;
	
	bool 		operator == (const sClientEntityList_t& rhs);
	bool 		operator == (const sGlowDefinitionObject_t& rhs);
	
	void 		print();
};

struct Wall::sPlayerResourceObject_t: public sBaseEntityObject_t {
	std::string clan(int index);
	
	int 		kills(int index);
	int		 	assists(int index);
	int		 	deaths(int index);
	int		 	team2(int index);
	int	 		health2(int index);
	int 		MVPs(int index);
	int			armor(int index);
	int 		score(int index);
	int 		competitiveRanking(int index);
	int			competitiveWins(int index);
	int 		totalCashSpent(int index);
	int 		cashSpentThisRound(int index);
	
	bool 		connected(int index);
	bool		hasDefuser(int index);
	bool 		hasHelmet(int index);
	
	void 		print();
};

#endif /* WALL_HPP */
