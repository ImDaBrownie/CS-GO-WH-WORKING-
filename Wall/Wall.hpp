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

#include "Scanner.hpp"
#include "Objects.hpp"
#include "Offsets.hpp"
#include "ColorText.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <atomic>
#include <thread>

class Wall {
	std::vector<EntityObjectDefinition_t> entityList;
	
	Process* g_cProc 					= nullptr;
	MemMngr* mem 						= nullptr;
	sOffsets* off 						= nullptr;
	Scanner* engineScanner 				= nullptr;
	Scanner* clientScanner 				= nullptr;

	GlowObjectDefinition_t* glow 		= nullptr;
	EntityObjectDefinition_t* entity 	= nullptr;
	
	uint64_t glow_ptr;
	uint64_t entity_ptr;
	uint64_t base_ptr;
	
	mach_vm_address_t engine_moduleStartAddress;
	off_t engine_moduleLength 			= 0;
	
	mach_vm_address_t client_moduleStartAddress;
	off_t client_moduleLength 			= 0;
	
	double refreshRate 					= 1000.0f;
	double maxFlash 					= 100.0f;
	bool noTeammates 					= false;
	bool noUtils 						= false;
	
	static std::atomic<bool> stop;
	
public:
	explicit Wall(double refreshRate = 1000.0f, double maxFlash = 100.0f, bool noTeammates = false, bool noUtils = false);
	~Wall();
	
	void run(bool getOff = false);

private:
	void deinit();
	void applyGlow();
	void getOffsets();
	void getEnginePointers();
	void getClientPointers();
	void stopThread();
};

#endif /* WALL_HPP */
