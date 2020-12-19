//
//  Offsets.hpp
//  Wall
//
//  Created by Fricker95 on 1/1/20.
//  Copyright © 2020 Fricker95. All rights reserved.
//

#ifndef OFFSETS_HPP
#define OFFSETS_HPP

struct sOffsets {
public:
	struct sClient {
		uint64_t m_dwGlowManager;
		uint64_t m_dwGlowObjectLoopStartBase;
		uint64_t m_dwEntityList;
		uint64_t m_dwLocalPlayer;
		uint64_t m_dwLocalPlayerBase;
		uint64_t m_dwPlayerResource;
		uint64_t m_dwPlayerResourceBase;
		uint64_t m_dwRadarManager;
		uint64_t m_dwRadarBase;
		
		uint64_t m_dwGlowListMaxSize					= 0x8;
		uint64_t m_dwGlowListSize 						= 0x10;
		uint64_t m_dwEntityStructSize					= 0x20;
		uint64_t m_dwGlowStructSize						= 0x40;
		// uint64_t m_dwGlowColorStruct					= 0x8;
		// uint64_t m_dwGlowEnable						= 0x28;
		uint64_t m_bDormant								= 0x125;
		uint64_t m_iTeam								= 0x12C;
		uint64_t m_iHealth								= 0x138;
		uint64_t m_iFlag								= 0x13C;
		uint64_t m_bLifeState							= 0x297;
		uint64_t m_bSpotted								= 0xECD;
		uint64_t m_bSpottedByMask						= 0xF10;
		uint64_t m_iShotFired							= 0xACC0;
		uint64_t m_dFlashAlpha							= 0xAD4C; // 0xAD2C
		uint64_t m_fFlashDuration						= 0xAD50; // 0xAD30
		uint64_t m_iGlowIndex							= 0xAD68; // 0xAD48 // 0xAD2C
		
		// m_dwEntityList - ...
//		uint64_t m_iMaxPlayers							= 0xDC00;
//		uint64_t m_iNumPlayersAlive						= 0xDBF8;
		/*
		 // radar base needs new sig
		 uint64_t m_dwRadarStructBase            		= 0x108;
		 uint64_t m_dwRadarDistance              		= 0x370;
		 uint64_t m_dwRadarArray                 		= 0x1E4;
		 uint64_t m_iRadarHealth                 		= 0x168;
		 uint64_t m_szRadarName                  		= 0x16C;
		*/
		/*
		// player resource needs new sig
		uint64_t m_iKills                              = 0x1288;
		uint64_t m_iAssists                            = 0x138C;
		uint64_t m_iDeaths                             = 0x1490;
		uint64_t m_iTeam2                              = 0x15C8;
		uint64_t m_iHealth2                            = 0x1814;
		uint64_t m_bHasDefuser                         = 0x1E51;
		uint64_t m_bConnected                          = 0x1594;
		uint64_t m_bHasHelmet                          = 0x1E92;
		uint64_t m_iArmor                              = 0x1ED8;
		uint64_t m_iCompetitiveRanking                 = 0x20E0;
		uint64_t m_iCompetitiveWins                    = 0x21E4;
		*/
	} client;
	
	struct sEngine {
		uint64_t m_dwCEngineClient;
		uint64_t m_dwCEngineClientBase;
		//uint64_t m_szGameDirectory;
		uint64_t m_dwIsInGame                           = 0x1a8; // 0x198
		//uint64_t m_dwFullUpdate                         = 0x204;
		//uint64_t m_iLocalPlayer                         = 0x210;
		//uint64_t m_szMapFile                            = 0x218;
		uint64_t m_szMapName                            = 0x32C; // 0x31C
		uint64_t m_iGetMaxClients                      	= 0x428; // 0x3A0;
		//uint64_t m_setViewAngle                         = 0x8E20;
	} engine;
	
	const char* ranks[19] = {
		"Unranked",
		"Silver I",
		"Silver II",
		"Silver III",
		"Silver IV",
		"Silver Elite",
		"Silver Elite Master",
		"Gold Nova I",
		"Gold Nova II",
		"Gold Nova III",
		"Gold Nova Master",
		"Master Guardian I",
		"Master Guardian II",
		"Master Guardian Elite",
		"Distinguished Master Guardian",
		"Legendary Eagle",
		"Legendary Eagle Master",
		"Supreme Master First Class",
		"The Global Elite"
	};
	
	enum EntityType {
		player,
		hostage,
		chicken,
		C4,
		plantedC4,
		weapon,
		utility,
		props,
		other
	} entityType;
	
	const char* playerClass[1] = {
		"10C_CSPlayer"
	};
	
	const char* hostageClass[1] = {
		"10C_CHostage"
	};
	
	const char* chickenClass[1] = {
		"10C_CChicken"
	};
	
	const char* C4Class[1] = {
		"4C_C4"
	};
	
	const char* plantedC4Class[1] = {
		"11C_PlantedC4"
	};
	
	const char* weaponClass[40] = {
		"6C_AK47",
		"11C_WeaponAug",
		"11C_WeaponAWP",
		"13C_WeaponBizon",
		"13C_WeaponFamas",
		"17C_WeaponFiveSeven",
		"13C_WeaponG3SG1",
		"13C_WeaponGalil",
		"15C_WeaponGalilAR",
		"13C_WeaponGlock",
		"15C_WeaponHKP2000",
		"12C_WeaponM4A1",
		"13C_WeaponMAC10",
		"12C_WeaponMag7",
		"15C_WeaponMP5Navy",
		"11C_WeaponMP7",
		"11C_WeaponMP9",
		"13C_WeaponNegev",
		"12C_WeaponP228",
		"12C_WeaponP250",
		"11C_WeaponP90",
		"8C_SCAR17",
		"14C_WeaponSCAR20",
		"13C_WeaponScout",
		"13C_WeaponSG550",
		"13C_WeaponSG556",
		"13C_WeaponSSG08",
		"12C_WeaponTec9",
		"11C_WeaponTMP",
		"13C_WeaponUMP45",
		"12C_WeaponM249",
		"11C_WeaponUSP",
		"8C_DEagle",
		"13C_WeaponElite",
		"7C_Knife",
		"9C_KnifeGG",
		"12C_WeaponNOVA",
		"16C_WeaponSawedoff",
		"13C_WeaponTaser",
		"14C_WeaponXM1014"
	};
	
	const char* utilityClass[7] = {
		"11C_Flashbang",
		"11C_HEGrenade",
		"14C_DecoyGrenade",
		"16C_MolotovGrenade",
		"19C_IncendiaryGrenade",
		"15C_SensorGrenade",
		"14C_SmokeGrenade"
	};
	
	const char* dynamicProsClass[2] = {
		"11C_CSRagdoll",
		"13C_DynamicProp"
	};
};

#endif /*OFFSETS_HPP*/

