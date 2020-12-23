//
//  Wall.cpp
//  Wall
//
//  for csgo wall hack
//  special edition
//
//  Created by sheep on 16/5/14.
//  Copyright © 2016年 nadp. All rights reserved.
//
//  Edited by Fricker95 on 1/1/20.

#include "Wall.hpp"

Wall::Wall(double refreshRate, double maxFlash, bool noTeammates, bool noUtils)
{
	this->refreshRate 	= refreshRate;
	this->maxFlash 		= maxFlash;
	this->noTeammates 	= noTeammates;
	this->noUtils		= noUtils;
	
	stop.store(false);
	
	g_cProc 			= new Process;
	mem 				= new MemMngr(g_cProc);
	off 				= new sOffsets;
	
	glow 				= new sGlowDefinitionObject_t;
	entity 				= new sClientEntityList_t;
	resource 			= new sPlayerResourceObject_t;
	
	g_cProc->mainPid() 	= g_cProc->get("csgo_osx64");
	
	if (g_cProc->mainPid() != -1){
		printf("Found CSGO's PID\t\t= %s\n", cT::print(std::to_string(g_cProc->mainPid()).c_str(), cT::fG::green, cT::sT::bold).c_str());
	} else {
		printf("%s\n", cT::print("Error: Can't find CSGO's PID", cT::fG::red, cT::sT::bold).c_str());
		deinit();
		exit(0);
	}
	
	g_cProc->mainTask() = g_cProc->task(g_cProc->mainPid());
	
	if (g_cProc->mainTask()){
		g_cProc->getModule(g_cProc->mainTask(), &engine_moduleStartAddress, &engine_moduleLength, "/engine.dylib");
		
		if (engine_moduleStartAddress != 0x0) {
			printf("Found the %s address\t= %s0x%llx%s ... %s0x%llx%s\n", cT::print("engine.dylib", cT::fG::yellow).c_str(),  cT::getColor(cT::fG::green).c_str(),
				   engine_moduleStartAddress,
				   cT::getStyle(cT::sT::bold).c_str(),
				   cT::getColor(cT::fG::green).c_str(),
				   engine_moduleStartAddress +
				   engine_moduleLength,
				   cT::getStyle(cT::sT::bold).c_str());
		} else {
			printf("%s\n", cT::print("Error: Failed to get the engine.dylib address", cT::fG::red, cT::sT::bold).c_str());
			deinit();
			exit(0);
		}
		
		g_cProc->getModule(g_cProc->mainTask(), &client_moduleStartAddress, &client_moduleLength, "/client.dylib");
		
		if (client_moduleStartAddress != 0x0) {
			printf("Found the %s address\t= %s0x%llx%s ... %s0x%llx%s\n", cT::print("client.dylib", cT::fG::yellow).c_str(),
				   cT::getColor(cT::fG::green).c_str(),
				   client_moduleStartAddress,
				   cT::getStyle(cT::sT::bold).c_str(),
				   cT::getColor(cT::fG::green).c_str(),
				   client_moduleStartAddress +
				   client_moduleLength,
				   cT::getStyle(cT::sT::bold).c_str());
		} else {
			printf("%s\n", cT::print("Error: Failed to get the client.dylib address", cT::fG::red, cT::sT::bold).c_str());
			deinit();
			exit(0);
		}
	} else {
		printf("%s\n", cT::print("Error: Failed to find main task", cT::fG::red, cT::sT::bold).c_str());
		deinit();
		exit(0);
	}
	
	engineScanner = new Scanner(engine_moduleStartAddress, engine_moduleLength, mem);
	clientScanner = new Scanner(client_moduleStartAddress, client_moduleLength, mem);
	
	getEnginePointers();
	
	if (off->engine.m_dwCEngineClient != 0x0)
		printf("Engine Client\t\t\t= %s0x%llx%s\n", cT::getColor(cT::fG::green).c_str(), off->engine.m_dwCEngineClient, cT::getStyle(cT::sT::bold).c_str());
	
	getClientPointers();
	
	if (off->client.m_dwLocalPlayer != 0x0) {
		printf("Local Player\t\t\t= %s0x%llx%s\n", cT::getColor(cT::fG::green).c_str(), off->client.m_dwLocalPlayer, cT::getStyle(cT::sT::bold).c_str());
	}
	
	if (off->client.m_dwEntityList != 0x0) {
		printf("Entity List\t\t\t= %s0x%llx%s\n", cT::getColor(cT::fG::green).c_str(), off->client.m_dwEntityList, cT::getStyle(cT::sT::bold).c_str());
	}
	
	if (off->client.m_dwGlowManager != 0x0) {
		printf("Glow Manager\t\t\t= %s0x%llx%s\n", cT::getColor(cT::fG::green).c_str(), off->client.m_dwGlowManager, cT::getStyle(cT::sT::bold).c_str());
	}
}

Wall::~Wall()
{
	deinit();
}

void Wall::deinit()
{
	stop.store(true);
	if (g_cProc)
		delete g_cProc;
	if (mem)
		delete mem;
	if (off)
		delete off;
	if (engineScanner)
		delete engineScanner;
	if (clientScanner)
		delete clientScanner;
	if (glow)
		delete glow;
	if (entity)
		delete entity;
	if (resource)
		delete resource;
}

void Wall::run(bool getOff)
{
	std::thread s_thread(&Wall::stopThread, this);
	s_thread.detach();
	
	while (g_cProc->mainPid() != -1 && !stop.load()) {
		if (off->engine.m_dwCEngineClientBase != 0x0) {
			if (mem->read<int>(off->engine.m_dwCEngineClientBase + off->engine.m_dwIsInGame) == 6) {
				off->client.m_dwLocalPlayerBase = mem->read<uint64_t>(off->client.m_dwLocalPlayer);
				off->client.m_dwGlowObjectLoopStartBase = mem->read<uint64_t>(off->client.m_dwGlowManager);
				if (off->client.m_dwLocalPlayerBase != 0x0 && off->client.m_dwGlowObjectLoopStartBase != 0x0) {
					if (getOff) {
						getOffsets();
						deinit();
						stop.store(true);
						exit(0);
					}
					applyGlow();
				} else {
					getClientPointers();
				}
			}
		} else {
			getEnginePointers();
			off->engine.m_dwCEngineClientBase = mem->read<uint64_t>(off->engine.m_dwCEngineClient);
		}
		g_cProc->mainPid() = g_cProc->get("csgo_osx64");
		usleep(refreshRate); // 800
	}
	stop.store(true);
	std::system("clear");
}

void Wall::applyGlow()
{
	entity_ptr = off->client.m_dwEntityList;
	base_ptr = off->client.m_dwLocalPlayerBase;
	
	int glowListMaxIndex = mem->read<int>(off->client.m_dwGlowManager + off->client.m_dwGlowListMaxSize);
	
	int health;
	int team;
	int i_teamNum = mem->read<int>(off->client.m_dwLocalPlayerBase + off->client.m_iTeam);
	
	bool cmp = false;
	
	while (entity_ptr != 0x0) {
		*entity = mem->read<sClientEntityList_t>(entity_ptr);
		entityList.emplace_back(*entity);
		if (entityList.size() > MAX_ENTITIES) {
			entityList.clear();
			return;
		}
		
//		printf("%s -> 0x%llx\n", entity->entityClass().c_str(), entity->m_hEntity);
		
		if (entity->entityType() == sOffsets::resource) {
			resource->m_hEntity = entity->m_hEntity;
		}
		
		entity_ptr = entity->m_pNext;
	}
	
	for (int i = 0; i < glowListMaxIndex; ++i) {

		glow_ptr = off->client.m_dwGlowObjectLoopStartBase + (off->client.m_dwGlowStructSize * i);
		*glow = mem->read<sGlowDefinitionObject_t>(glow_ptr);

		if (glow->isValidGlowEntity()) {
			
			auto ent = std::find(entityList.begin(), entityList.end(), *glow);
			if(ent != entityList.end()) {
				
//				printf("%s -> 0x%llx\n", glow->entityClass().c_str(), glow->m_hEntity);
				
				if (!glow->isDormant() && !glow->lifeState()) {
					
					switch (glow->entityType()) {
						case sOffsets::player:
							if (glow->isValidGlowEntity(base_ptr)) {
								if (maxFlash != -1) {
									if (glow->flashMaxAlpha() > maxFlash) {
										glow->setFlashMaxAlpha(maxFlash);
									}
								}
								break;
							}

							team = glow->team();

							if (noTeammates && team == i_teamNum) {
								break;
							}

							health = glow->health();
							health += (health == 0 ? 100 : health);

							cmp = team != i_teamNum;

							// Glow Colors
							glow->m_vGlowColor = {
								float((100 - health)/100.0),
								cmp ? float((health)/100.0) : 0.0f,
								cmp ? 0.0f : float((health)/100.0)
							};
							glow->m_flGlowAlpha = 0.5f;

							// Enables Glow
							glow->m_bRenderWhenOccluded = true;
							glow->m_bRenderWhenUnoccluded = false;

							// Write to Memory
							mem->write<sGlowDefinitionObject_t>(off->client.m_dwGlowObjectLoopStartBase + (off->client.m_dwGlowStructSize * i), *glow);
							break;
						case sOffsets::hostage:
							// Glow Colors
							glow->m_vGlowColor = {1.0f, 1.0f, 1.0f};
							glow->m_flGlowAlpha = 0.8f;

							// Enables Glow
							glow->m_bRenderWhenOccluded = !noUtils;
							glow->m_bRenderWhenUnoccluded = false;

							// Write to Memory
							mem->write<sGlowDefinitionObject_t>(off->client.m_dwGlowObjectLoopStartBase + (off->client.m_dwGlowStructSize * i), *glow);
							break;
						case sOffsets::chicken:
							// Glow Colors
							glow->m_vGlowColor = {1.0f, 1.0f, 0.5f};
							glow->m_flGlowAlpha = 0.8f;

							// Enables Glow
							glow->m_bRenderWhenOccluded = !noUtils;
							glow->m_bRenderWhenUnoccluded = false;

							// Write to Memory
							mem->write<sGlowDefinitionObject_t>(off->client.m_dwGlowObjectLoopStartBase + (off->client.m_dwGlowStructSize * i), *glow);
							break;
						case sOffsets::C4:
							// Glow Colors
							glow->m_vGlowColor = {0.0f, 1.0f, 0.0f};
							glow->m_flGlowAlpha = 0.8f;

							// Enables Glow
							glow->m_bRenderWhenOccluded = !noUtils;
							glow->m_bRenderWhenUnoccluded = false;

							// Write to Memory
							mem->write<sGlowDefinitionObject_t>(off->client.m_dwGlowObjectLoopStartBase + (off->client.m_dwGlowStructSize * i), *glow);
							break;
						case sOffsets::plantedC4:
							// Glow Colors
							glow->m_vGlowColor = {1.0f, 0.0f, 0.0f};
							glow->m_flGlowAlpha = 1.0f;

							// Enables Glow
							glow->m_bRenderWhenOccluded = !noUtils;
							glow->m_bRenderWhenUnoccluded = false;

							// Write to Memory
							mem->write<sGlowDefinitionObject_t>(off->client.m_dwGlowObjectLoopStartBase + (off->client.m_dwGlowStructSize * i), *glow);
							break;
						case sOffsets::weapon:
							// Glow Colors
							glow->m_vGlowColor = {1.0f, 1.0f, 1.0f};
							glow->m_flGlowAlpha = 0.8f;

							// Enables Glow
							glow->m_bRenderWhenOccluded = !noUtils;
							glow->m_bRenderWhenUnoccluded = false;

							// Write to Memory
							mem->write<sGlowDefinitionObject_t>(off->client.m_dwGlowObjectLoopStartBase + (off->client.m_dwGlowStructSize * i), *glow);
							break;
						case sOffsets::kit:
							// Glow Colors
							glow->m_vGlowColor = {1.0f, 0.0f, 1.0f};
							glow->m_flGlowAlpha = 0.8f;
							
							// Enables Glow
							glow->m_bRenderWhenOccluded = !noUtils;
							glow->m_bRenderWhenUnoccluded = false;
							
							// Write to Memory
							mem->write<sGlowDefinitionObject_t>(off->client.m_dwGlowObjectLoopStartBase + (off->client.m_dwGlowStructSize * i), *glow);
							break;
						case sOffsets::utility:
							// Glow Colors
							glow->m_vGlowColor = {1.0f, 1.0f, 1.0f};
							glow->m_flGlowAlpha = 0.8f;

							// Enables Glow
							glow->m_bRenderWhenOccluded = !noUtils;
							glow->m_bRenderWhenUnoccluded = false;

							// Write to Memory
							mem->write<sGlowDefinitionObject_t>(off->client.m_dwGlowObjectLoopStartBase + (off->client.m_dwGlowStructSize * i), *glow);
							break;
						case sOffsets::props:
							break;
						case sOffsets::resource:
							break;
						case sOffsets::team:
							break;
						case sOffsets::other:
							break;
					}
				}
			}
		}
	}
	
//	stop.store(true);
	
	entityList.clear();
}

void Wall::getOffsets()
{
	//
	// ** SHOULD NOT BE RUN ON VAC SERVERS **
	//
	// attempts to get the new glow index offset.
	//
	// - launch csgo with flag: -insecure
	// - launch game with bots.
	// - in terminal:
	// - sudo ./Wall -o
	//
	
	uint64_t entityPointer;
	
	bool isValid = false;
	std::vector<int> glowIndexes;
	
	for (int i = 0; i < 64; ++i) {
		for (int j = 0; j < mem->read<int>(off->engine.m_dwCEngineClientBase + off->engine.m_iGetMaxClients); ++j){
			entityPointer = mem->read<uint64_t>(off->client.m_dwEntityList + (off->client.m_dwEntityStructSize * j));
			
			if (entityPointer <= 0x0)
				continue;
			
			if (!mem->read<bool>(entityPointer + off->client.m_bDormant) && !mem->read<bool>(entityPointer + off->client.m_bLifeState))
				glowIndexes.emplace_back(mem->read<int>(entityPointer + off->client.m_iGlowIndex + i));
		}
		
		for (int j = 1; j < glowIndexes.size(); ++j)
			isValid = (glowIndexes[j] > 1 && glowIndexes[j] < 60 ? true : false);
		
		glowIndexes.clear();
		
		if (isValid) {
			printf("\nuint64_t %s\t\t= %s0x%llx%s\n", cT::print("m_iGlowIndex", cT::fG::yellow).c_str(), cT::getColor(cT::fG::green).c_str(), off->client.m_iGlowIndex + i, cT::getStyle(cT::sT::bold).c_str());
			printf("uint64_t %s\t\t= %s0x%llx%s\n", cT::print("m_flFlashMaxAlpha", cT::fG::yellow).c_str(), cT::getColor(cT::fG::green).c_str(), off->client.m_flFlashMaxAlpha + i, cT::getStyle(cT::sT::bold).c_str());
			printf("uint64_t %s\t= %s0x%llx%s\n\n", cT::print("m_flFlashDuration", cT::fG::yellow).c_str(), cT::getColor(cT::fG::green).c_str(), off->client.m_flFlashDuration + i, cT::getStyle(cT::sT::bold).c_str());
			printf("uint64_t %s\t\t= %s0x%llx%s\n\n", cT::print("m_iShotFired", cT::fG::yellow).c_str(), cT::getColor(cT::fG::green).c_str(), off->client.m_iShotFired + i, cT::getStyle(cT::sT::bold).c_str());
			return;
		}
		usleep(refreshRate);
	}
	
	if (!isValid) {
		printf("%s\n", cT::print("Error: Could not find new Offsets\nRetry using the last known Offsets", cT::fG::red, cT::sT::bold).c_str());
		return;
	}
}

void Wall::getEnginePointers()
{
	off->engine.m_dwCEngineClient = engine_moduleStartAddress + engineScanner->getPointer(
																						  (Byte*)"\x55\x48\x89\xE5\x48\x8B\x00\x00\x00\x00\x00\x48\x83\x00\x00\x5D\xC3\x66\x66\x66\x66\x66\x66\x2E\x0F\x1F\x84\x00\x00\x00\x00\x00",
																						  "xxxxxx?????xx??xxxxxxxxxxxxxxxxx",
																						  0x7
																						  ) + 0x4;
}

void Wall::getClientPointers()
{
	off->client.m_dwLocalPlayer = client_moduleStartAddress + clientScanner->getPointer(
																						(Byte*)"\x89\xD6\x41\x89\x00\x49\x89\x00\x48\x8B\x1D\x00\x00\x00\x00\x48\x85\xDB\x74\x00",
																						"xxxx?xx?xxx????xxxx?",
																						0xB
																						) + 0x4;
	
	off->client.m_dwEntityList = client_moduleStartAddress + clientScanner->getPointer(
																					   (Byte*)"\x48\x8D\x1D\x00\x00\x00\x00\x48\x89\xDF\xE8\x00\x00\x00\x00\x48\x8D\x3D\x00\x00\x00\x00\x48\x8D\x15\x00\x00\x00\x00\x48\x89\xDE",
																					   "xxx????xxxx????xxx????xxx????xxx",
																					   0x3
																					   ) + 0x2C;
	
	off->client.m_dwGlowManager = client_moduleStartAddress + clientScanner->getPointer(
																						(Byte*)"\x48\x8D\x3D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x85\xC0\x0F\x84\x00\x00\x00\x00\x48\xC7\x05\x00\x00\x00\x00\x00\x00\x00\x00\x48\x8D\x35\x00\x00\x00\x00",
																						"xxx????x????xxxx????xxx????xxxxxxx????",
																						0x22
																						) + 0x4;
	
	/*
	 off->client. m_dwRadarBase = client_moduleStartAddress + clientScanner->getPointer(
	 (Byte*)"\x55\x48\x89\xE5\x41\x57\x41\x56\x41\x55\x41\x54\x53\x50\x49\x89\xFD\x49\x8B\x7D\x00\x48\x85\xFF\x74\x56\x41\x8B\x75\x00\xE8\x6D\x00\x00\x00\x41\x88\xC6\x45\x84\xF6\x75\x45\x41\x80\xF6\x00\x45\x8B\x65\x00\x45\x85\xE4\x7E\x3B\x31\xDB\x4C\x8D\x3D\x00\x00\x00\x00\x66\x66\x66\x66\x66\x66\x2E\x0F\x1F\x84\x00\x00\x00\x00\x00",
	 "xxxxxxxxxxxxxxxxxxxx?xxxxxxxx?xxxxxxxxxxxxxxxx?xxx?xxxxxxxxxx????xxxxxxxxxxxxxxx",
	 0x3D
	 ) + 0x3C;
	 
	 printf("Radar Base: 0x%llx\n", off->client.m_dwRadarBase);
	 */
	/*
	 off->client. m_dwPlayerResource = client_moduleStartAddress + clientScanner->getPointer(
	 (Byte*)"\x55\x48\x89\xE5\x41\x57\x41\x56\x41\x55\x41\x54\x53\x48\x83\xEC\x00\x48\x89\xF3\x48\x8D\x7D\xB0\xBE\x00\x00\x00\x00\xE8\xAE\x2F\xDC\xFF\x4C\x8B\x75\xD0\x48\x8B\x03\x48\x8B\x80\x00\x00\x00\x00\x48\x89\xDF\xFF\xD0\x41\x80\x4E\x00\x00\x49\x89\x46\x00\x48\x8D\x1D\x00\x00\x00\x00\x48\x8B\x3B\x48\x8B\x07\x48\x8B\x80\x00\x00\x00\x00\xFF\xD0\x4C\x8D\x25\x00\x00\x00\x00",
	 "xxxxxxxxxxxxxxxx?xxxxxxxx????xxxxxxxxxxxxxxx????xxxxxxxx??xxx?xxx????xxxxxxxxx????xxxxx????",
	 0x57
	 ) + 0x4;
	 
	 printf("Player Resource: 0x%llx\n", off->client.m_dwPlayerResource);
	 */
}

void Wall::stopThread()
{
	std::string str;
	while (!stop.load()) {
		std::cin >> str;
		if (str == "q" || str == "quit" || str == "stop" || str == "exit") {
			stop.store(true);
		}
		usleep(refreshRate);
	}
}

std::atomic<bool> Wall::stop{false};

Process* Wall::g_cProc = new Process;

MemMngr* Wall::mem = new MemMngr(g_cProc);

sOffsets* Wall::off = new sOffsets;

std::string Wall::sBaseEntityObject_t::entityClass()
{
	uint64_t vtable = mem->read<uint64_t>(m_hEntity + 0x8);
	uint64_t fn = mem->read<uint64_t>(vtable - 0x8);
	uint64_t cls = mem->read<uint64_t>(fn + 0x8);
	return mem->readString(cls);
}

double Wall::sBaseEntityObject_t::flashMaxAlpha()
{
	return mem->read<double>(m_hEntity + off->client.m_flFlashMaxAlpha);
}

float Wall::sBaseEntityObject_t::flashDuration()
{
	return mem->read<float>(m_hEntity + off->client.m_flFlashDuration);
}

int Wall::sBaseEntityObject_t::health()
{
	return mem->read<int>(m_hEntity + off->client.m_iHealth);
}

int Wall::sBaseEntityObject_t::team()
{
	return mem->read<int>(m_hEntity + off->client.m_iTeam);
}

int Wall::sBaseEntityObject_t::glowIndex()
{
	return mem->read<int>(m_hEntity + off->client.m_iGlowIndex);
}

int Wall::sBaseEntityObject_t::shotsFired()
{
	return mem->read<int>(m_hEntity + off->client.m_iShotFired);
}

int Wall::sBaseEntityObject_t::spottedBy()
{
	return mem->read<int>(m_hEntity + off->client.m_bSpottedBy);
}

sOffsets::EntityType Wall::sBaseEntityObject_t::entityType()
{
	return off->getEntityType(entityClass());
}

Byte Wall::sBaseEntityObject_t::EFlags()
{
	return mem->read<Byte>(m_hEntity + off->client.m_iEFlags);
}

bool Wall::sBaseEntityObject_t::isDormant()
{
	return mem->read<bool>(m_hEntity + off->client.m_bDormant);
}

bool Wall::sBaseEntityObject_t::lifeState()
{
	return mem->read<bool>(m_hEntity + off->client.m_bLifeState);
}

bool Wall::sBaseEntityObject_t::spotted()
{
	return mem->read<bool>(m_hEntity + off->client.m_bSpotted);
}

bool Wall::sBaseEntityObject_t::hasMovedSinceSpawn()
{
	return mem->read<bool>(m_hEntity + off->client.m_bHasMovedSinceSpawn);
}

bool Wall::sBaseEntityObject_t::isJumping()
{
	return EFlags() & FL_ONGROUND;
}

bool Wall::sBaseEntityObject_t::isCrouching()
{
	return EFlags() & FL_DUCKING;
}

bool Wall::sBaseEntityObject_t::isWeapon()
{
	return entityType() == sOffsets::weapon;
}

bool Wall::sBaseEntityObject_t::isBomb()
{
	return entityType() == sOffsets::C4 || entityType() == sOffsets::plantedC4;
}

bool Wall::sBaseEntityObject_t::isChicken()
{
	return entityType() == sOffsets::chicken;
}

bool Wall::sBaseEntityObject_t::isPlayer()
{
	return entityType() == sOffsets::player;
}

bool Wall::sBaseEntityObject_t::isValidGlowEntity()
{
	return m_hEntity != 0x0;
}

bool Wall::sBaseEntityObject_t::isValidGlowEntity(uint64_t ptr)
{
	return m_hEntity != 0x0 && m_hEntity == ptr;
}

void Wall::sBaseEntityObject_t::setFlashMaxAlpha(double x)
{
	mem->write<double>(m_hEntity + off->client.m_flFlashMaxAlpha, x);
}

void Wall::sBaseEntityObject_t::print()
{
	printf("0x%llx\n", m_hEntity);
}

void Wall::sGlowDefinitionObject_t::print()
{
	printf("0x%llx\n", m_hEntity);
	printf("red = %f\n", m_vGlowColor.r);
	printf("green = %f\n", m_vGlowColor.g);
	printf("blue = %f\n", m_vGlowColor.b);
	printf("alpha = %f\n", m_flGlowAlpha);
	printf("%s\n", unk1);
	printf("%i\n", m_bRenderWhenOccluded);
	printf("%i\n", m_bRenderWhenUnoccluded);
	printf("%i\n", FullBloom);
	printf("%s\n", unk2);
	printf("\n");
}

bool Wall::sGlowDefinitionObject_t::operator == (const sGlowDefinitionObject_t& rhs)
{
	return m_hEntity == rhs.m_hEntity;
}

bool Wall::sGlowDefinitionObject_t::operator == (const sClientEntityList_t& rhs)
{
	return m_hEntity == rhs.m_hEntity;
}


void Wall::sClientEntityList_t::print()
{
	printf("0x%llx\n", m_hEntity);
	printf("%s\n", m_SerialNum);
	printf("0x%llx\n", m_pPrevious);
	printf("0x%llx\n", m_pNext);
	printf("\n");
}

bool Wall::sClientEntityList_t::operator == (const sClientEntityList_t& rhs)
{
	return m_hEntity == rhs.m_hEntity;
}

bool Wall::sClientEntityList_t::operator == (const sGlowDefinitionObject_t& rhs)
{
	return m_hEntity == rhs.m_hEntity;
}



std::string Wall::sPlayerResourceObject_t::clan(int index)
{
	return mem->readString(m_hEntity + off->client.m_szClan + (index * sizeof(32)));
}

int Wall::sPlayerResourceObject_t::kills(int index)
{
	return mem->read<int>(m_hEntity + off->client.m_iKills + (index * sizeof(int)));
}

int Wall::sPlayerResourceObject_t::assists(int index)
{
	return mem->read<int>(m_hEntity + off->client.m_iAssists + (index * sizeof(int)));
}

int Wall::sPlayerResourceObject_t::deaths(int index)
{
	return mem->read<int>(m_hEntity + off->client.m_iDeaths + (index * sizeof(int)));
}

int Wall::sPlayerResourceObject_t::team2(int index)
{
	return mem->read<int>(m_hEntity + off->client.m_iTeam2 + (index * sizeof(int)));
}

int Wall::sPlayerResourceObject_t::health2(int index)
{
	return mem->read<int>(m_hEntity + off->client.m_iHealth2 + (index * sizeof(int)));
}

int Wall::sPlayerResourceObject_t::MVPs(int index)
{
	return mem->read<int>(m_hEntity + off->client.m_iMVPs + (index * sizeof(int)));
}

int Wall::sPlayerResourceObject_t::armor(int index)
{
	return mem->read<int>(m_hEntity + off->client.m_iArmor + (index * sizeof(int)));
}

int Wall::sPlayerResourceObject_t::score(int index)
{
	return mem->read<int>(m_hEntity + off->client.m_iScore + (index * sizeof(int)));
}

int Wall::sPlayerResourceObject_t::competitiveRanking(int index)
{
	return mem->read<int>(m_hEntity + off->client.m_iCompetitiveRanking + (index * sizeof(int)));
}

int Wall::sPlayerResourceObject_t::competitiveWins(int index)
{
	return mem->read<int>(m_hEntity + off->client.m_iCompetitiveWins + (index * sizeof(int)));
}

int Wall::sPlayerResourceObject_t::totalCashSpent(int index)
{
	return mem->read<int>(m_hEntity + off->client.m_iTotalCashSpent + (index * sizeof(int)));
}

int Wall::sPlayerResourceObject_t::cashSpentThisRound(int index)
{
	return mem->read<int>(m_hEntity + off->client.m_iCashSpentThisRound + (index * sizeof(int)));
}

bool Wall::sPlayerResourceObject_t::connected(int index)
{
	return mem->read<bool>(m_hEntity + off->client.m_bConnected + (index * sizeof(bool)));
}

bool Wall::sPlayerResourceObject_t::hasDefuser(int index)
{
	return mem->read<bool>(m_hEntity + off->client.m_bHasDefuser + (index * sizeof(bool)));
}

bool Wall::sPlayerResourceObject_t::hasHelmet(int index)
{
	return mem->read<bool>(m_hEntity + off->client.m_bHasHelmet + (index * sizeof(bool)));
}

void Wall::sPlayerResourceObject_t::print()
{
	int num_alive = mem->read<int>(off->client.m_dwEntityList - off->client.m_iNumPlayersAlive);
	for (int i = 0; i < num_alive; ++i) {
		printf("index = %i\n", i);
		printf("m_hEntity = 0x%llx\n", m_hEntity);
		printf("m_iKills = %i\n", kills(i));
		printf("m_iAssists = %i\n", assists(i));
		printf("m_iDeaths = %i\n", deaths(i));
		printf("m_iTeam2 = %i\n", team2(i));
		printf("m_bConnected = %i\n", connected(i));
		printf("m_iHealth2 = %i\n", health2(i));
		printf("m_iMVPs = %i\n", MVPs(i));
		printf("m_bHasDefuser = %i\n", hasDefuser(i));
		printf("m_bHasHelmet = %i\n", hasHelmet(i));
		printf("m_iArmor = %i\n", armor(i));
		printf("m_iScore = %i\n", score(i));
		printf("m_iCompetitiveRanking = %i\n", competitiveRanking(i));
		printf("m_iCompetitiveWins = %i\n", competitiveWins(i));
		printf("\n");
	}
}
