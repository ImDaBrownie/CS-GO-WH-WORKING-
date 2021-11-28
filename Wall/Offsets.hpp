//
//  Offsets.hpp
//  Wall
//
//  Created by Fricker95 on 1/1/20.
//  Copyright © 2020 Fricker95. All rights reserved.
//

#ifndef OFFSETS_HPP
#define OFFSETS_HPP

#define FL_ONGROUND				(1<<0)
#define FL_DUCKING				(1<<1)
#define FL_WATERJUMP			(1<<2)
#define FL_ONTRAIN				(1<<3)
#define FL_INRAIN				(1<<4)
#define FL_FROZEN				(1<<5)
#define FL_ATCONTROLS			(1<<6)
#define FL_CLIENT				(1<<7)	// IsPlayer
#define FL_FAKECLIENT			(1<<8)
#define FL_INWATER				(1<<9)

#include <stdio.h>
#include <stdlib.h>
#include <string>

struct sOffsets {
public:
	struct sClient {
		uint64_t m_dwGlowManager;
//		uint64_t m_dwGlowObjectLoopStartBase;
		uint64_t m_dwEntityList;
		uint64_t m_dwLocalPlayer;
//		uint64_t m_dwLocalPlayerBase;
		uint64_t m_dwPlayerResource;					//0x164AAE8
//		uint64_t m_dwPlayerResourceBase;
		uint64_t m_dwRadarManager;
		uint64_t m_dwRadarBase;
		
		uint64_t m_dwGlowListMaxSize					= 0x8;
		uint64_t m_dwGlowListSize 						= 0x10;
		uint64_t m_dwWeaponListSize 					= 0x10;
//		uint64_t m_dwEntityStructSize					= 0x20;
//		uint64_t m_dwGlowStructSize						= 0x40;
		// uint64_t m_dwGlowColorStruct					= 0x8;
		// uint64_t m_dwGlowEnable						= 0x28;
		uint64_t m_iID 									= 0x94;
		uint64_t m_bDormant								= 0x125;
		uint64_t m_iTeam								= 0x12C;
		uint64_t m_iHealth								= 0x138;
		uint64_t m_iEFlags								= 0x13C;
		uint64_t m_vecViewOffset						= 0x148;
		uint64_t m_vecAbsVelocity						= 0x14C;
		uint64_t m_angAbsRotation						= 0x164;
		uint64_t m_vecAbsOrigin							= 0x170;
		uint64_t m_hOwnerEntity 						= 0x184;
		uint64_t m_hEntityID 							= 0x2C4;
		uint64_t m_bLifeState							= 0x297;
		uint64_t m_iC4State 							= 0x3F8;
		uint64_t m_bSpotted								= 0xECD;
		uint64_t m_bSpottedBy							= 0xF10;
		uint64_t m_dwBoneMatrix							= 0x2C80;
		uint64_t m_hMyWeapons							= 0x3538;
		uint64_t m_hActiveWeapon						= 0x3638;
//		uint64_t m_hLocalPlayer							= 0x3700;
//		uint64_t m_hViewModelIndex						= 0x3AE4;
		uint64_t m_iEquipped 							= 0x3AD8;
		uint64_t m_bHasMovedSinceSpawn					= 0x4245;
		uint64_t m_iShotFired							= 0x10D00; // 0xACC0;
		uint64_t m_flFlashMaxAlpha						= 0x10D8C; // 0xAD4C; // 0xAD2C
		uint64_t m_flFlashDuration						= 0x10D90; // 0xAD50; // 0xAD30
		uint64_t m_iGlowIndex							= 0xAD68; // 0xAD48 // 0xAD2C
		uint64_t m_dwCrosshairID               		 	= 0x11D88; // 0xBC08;
		uint64_t m_iItemDefinitionIndex 				= 0x37BA;
		uint64_t m_iItemIDHigh 							= 0x37D0;
		uint64_t m_iAccountID 							= 0x37D8;
		uint64_t m_OriginalOwnerXuidHigh 				= 0x3A2C;
		uint64_t m_OriginalOwnerXuidLow 				= 0x3A28;
		uint64_t m_iEntityQuality 						= 0x37BC;
		uint64_t m_szCustomName 						= 0x3890;
		uint64_t m_nFallbackPaintKit 					= 0x3A30;
		uint64_t m_nFallbackSeed 						= 0x3A34;
		uint64_t m_flFallbackWear 						= 0x3A38;
		uint64_t m_nFallbackStatTrak 					= 0x3A3C;
		uint64_t m_nModelIndex 							= 0x290;
		uint64_t m_hWeapon 								= 0x3078; // 0x3538;
		uint64_t m_fAccuracyPenalty 					= 0x3BCC;
		uint64_t m_bStartedArming						= 0x3C9C;
		uint64_t m_flNextPrimaryAttack 					= 0x3AC0;
		uint64_t m_hOwner 								= 0x307C; // 0x3AB8; // 0x3AB0;
		uint64_t m_iClip1 								= 0x3AEC; // 0x3AE4;
		uint64_t m_bShouldGlow 							= 0x3060;
		
		// m_dwEntityList - ...
//		uint64_t m_iMaxPlayers							= 0xDC00;
		uint64_t m_iNumPlayersAlive						= 0xDBF8;
		/*
		 // radar base needs new sig
		 uint64_t m_dwRadarStructBase            		= 0x108;
		 uint64_t m_dwRadarDistance              		= 0x370;
		 uint64_t m_dwRadarArray                 		= 0x1E4;
		 uint64_t m_iRadarHealth                 		= 0x168;
		 uint64_t m_szRadarName                  		= 0x16C;
		*/
		
//		 0x44 -> Entity List
		uint64_t m_iPing 								= 0x11c4;
		uint64_t m_iKills 								= 0x12c8;
		uint64_t m_iAssists 							= 0x13cc;
		uint64_t m_iDeaths 								= 0x14d0;
		uint64_t m_bConnected 							= 0x1180;
		uint64_t m_iTeam2 								= 0x15d4;
		uint64_t m_iPendingTeam 						= 0x16d8;
		uint64_t m_bAlive 								= 0x17dc;
		uint64_t m_iHealth2 							= 0x1820;
		uint64_t m_iCoachingTeam 						= 0x1924;
		uint64_t m_iMVPs 								= 0x1d8c;
		uint64_t m_iArmor 								= 0x1f14;
		uint64_t m_bHasHelmet 							= 0x1ed1;
		uint64_t m_bHasDefuser 							= 0x1e90;
		uint64_t m_iScore 								= 0x2018;
		uint64_t m_iCompetitiveRanking 					= 0x211c;
		uint64_t m_iCompetitiveWins 					= 0x2220;

//		m_iCompTeammateColor
//		m_bControllingBot
//		m_iControlledPlayer
//		m_iControlledByPlayer
//		m_iBotDifficulty
		uint64_t m_szClan								= 0x4A54;
		uint64_t m_iTotalCashSpent						= 0x4F5C;
		uint64_t m_iCashSpentThisRound					= 0x5164;
//		m_nEndMatchNextMapVotes
//		m_bEndMatchNextMapAllVoted
//		m_nActiveCoinRank
//		m_nMusicID
//		m_nPersonaDataPublicLevel
//		m_nPersonaDataPublicCommendsLeader
//		m_nPersonaDataPublicCommendsTeacher
//		m_nPersonaDataPublicCommendsFriendly
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
	
	const char* TeamNames[4] = {
		"UNASSIGNED",
		"SPECTATOR",
		"TERRORIST",
		"CT"
	};
	
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
	
	const char* entityClass[63] {
		// player
		"C_CSPlayer",
		// hostage
		"C_CHostage",
		// chicken
		"C_CChicken",
		// C4
		"C_C4",
		// plantedC4
		"C_PlantedC4",
		// weapon
		"C_AK47",
		"C_WeaponAug",
		"C_WeaponAWP",
		"C_WeaponBizon",
		"C_WeaponFamas",
		"C_WeaponFiveSeven",
		"C_WeaponG3SG1",
		"C_WeaponGalil",
		"C_WeaponGalilAR",
		"C_WeaponGlock",
		"C_WeaponHKP2000",
		"C_WeaponM4A1",
		"C_WeaponMAC10",
		"C_WeaponMag7",
		"C_WeaponMP5Navy",
		"C_WeaponMP7",
		"C_WeaponMP9",
		"C_WeaponNegev",
		"C_WeaponP228",
		"C_WeaponP250",
		"C_WeaponP90",
		"C_SCAR17",
		"C_WeaponSCAR20",
		"C_WeaponScout",
		"C_WeaponSG550",
		"C_WeaponSG556",
		"C_WeaponSSG08",
		"C_WeaponTec9",
		"C_WeaponTMP",
		"C_WeaponUMP45",
		"C_WeaponM249",
		"C_WeaponUSP",
		"C_DEagle",
		"C_WeaponElite",
		"C_Knife",
		"C_KnifeGG",
		"C_WeaponNOVA",
		"C_WeaponSawedoff",
		"C_WeaponTaser",
		"C_WeaponXM1014",
		// kit
		"C_EconEntity",
		// grenade
		"C_Flashbang",
		"C_HEGrenade",
		"C_DecoyGrenade",
		"C_MolotovGrenade",
		"C_IncendiaryGrenade",
		"C_SensorGrenade",
		"C_SmokeGrenade",
		// grenade projectiles
		"C_BaseCSGrenadeProjectile",
		"C_DecoyProjectile",
		"C_MolotovProjectile",
		"C_SensorGrenadeProjectile",
		"C_SmokeGrenadeProjectile",
		// props
		"C_CSRagdoll",
		"C_DynamicProp",
		// resources
		"C_PlayerResource",
		"C_CS_PlayerResource",
		// team
		"C_CSTeam"
	};
	
	enum EntityType {
		player 		= 0,
		hostage 	= 1,
		chicken 	= 2,
		C4 			= 3,
		plantedC4 	= 4,
		weapon 		= 5,
		kit 		= 45,
		grenade 	= 46,
		projectile 	= 53,
		props 		= 58,
		resource 	= 60,
		team 		= 62,
		other		= -1
	};
	
	
	inline sOffsets::EntityType getEntityType(std::string clsName)
	{
		auto begin = std::begin(entityClass);
		auto end = std::end(entityClass);
		auto it = std::find(begin, end, clsName);
		
		bool cmp = (it == end);
		int index = (int)(it - begin);
		
		int len = sizeof(entityClass) / sizeof(const char*);
		
		return EntityType(  (int)other 			* cmp
						  + (int)player 		* (index == (int)player)
						  + (int)hostage 		* (index == (int)hostage)
						  + (int)chicken 		* (index == (int)chicken)
						  + (int)C4 			* (index == (int)C4)
						  + (int)plantedC4 		* (index == (int)plantedC4)
						  + (int)weapon 		* (index >= (int)weapon && index < (int)kit)
						  + (int)kit 			* (index >= (int)kit && index < (int)grenade)
						  + (int)grenade 		* (index >= (int)grenade && index < (int)projectile)
						  + (int)projectile 	* (index >= (int)projectile && index < (int)props)
						  + (int)props 			* (index >= (int)props && index < (int)resource)
						  + (int)resource		* (index >= (int)resource && index < (int)team)
						  + (int)team 			* (index >= (int)team && index < len)
		);
	}
	
};

#endif /*OFFSETS_HPP*/



