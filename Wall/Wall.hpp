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
#include "Offsets.hpp"
#include "ColorText.hpp"

#include <iostream>
#include <vector>
#include <atomic>
#include <thread>

class Wall {
public:
	struct GlowObjectDefinition_t {
	public:
		struct Vector {
			float r;
			float g;
			float b;
		};
	public:
		uint64_t m_hEntity;
		Vector m_vGlowColor;
		float m_flGlowAlpha;
		char unk1[0x10];
		bool m_bRenderWhenOccluded;
		bool m_bRenderWhenUnoccluded;
		bool FullBloom;
		char unk2[0x15];
		
		bool isValidGlowEntity();
		bool isValidGlowEntity(uint64_t ptr);
	};
private:
	Process* g_cProc = nullptr;
	MemMngr* mem = nullptr;
	sOffsets* off = nullptr;
	Scanner* engineScanner = nullptr;
	Scanner* clientScanner = nullptr;
	GlowObjectDefinition_t* glow = nullptr;
	
	uint64_t glowPointer;
	uint64_t entityPointer;
	
	mach_vm_address_t engine_moduleStartAddress;
	off_t engine_moduleLength = 0;
	
	mach_vm_address_t client_moduleStartAddress;
	off_t client_moduleLength = 0;
	
	double refreshRate = 1000.0f;
	double maxFlash = 100.0f;
	bool noTeammates = false;
	
	static std::atomic<bool> stop;
	
public:
	explicit Wall(double refreshRate = 1000.0f, double maxFlash = 100.0f, bool noTeammates = false);
	~Wall();
	
	void run(bool getOff = false);

private:
	void deinit();
	void applyEntityGlow(int iTeamNum);
	void getOffsets();
	void getEnginePointers();
	void getClientPointers();
	void stopThread();
};

#endif /* WALL_HPP */
