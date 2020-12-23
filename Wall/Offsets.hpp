//
//  Offsets.hpp
//  Wall
//
//  Created by Fricker95 on 1/1/20.
//  Copyright © 2020 Fricker95. All rights reserved.
//

#ifndef OFFSETS_HPP
#define OFFSETS_HPP

#define FL_ONGROUND 	(1<<0)
#define FL_DUCKING 		(1<<1)

#include <string>

struct sOffsets {
public:
	struct sClient {
		uint64_t m_dwGlowManager;
		uint64_t m_dwGlowObjectLoopStartBase;
		uint64_t m_dwEntityList;
		uint64_t m_dwLocalPlayer;
		uint64_t m_dwLocalPlayerBase;
		uint64_t m_dwPlayerResource;					//0x164AAE8
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
		uint64_t m_iEFlags								= 0x13C;
		uint64_t m_vecViewOffset						= 0x148;
		uint64_t m_vecAbsVelocity						= 0x14C;
		uint64_t m_angAbsRotation						= 0x164;
		uint64_t m_vecAbsOrigin							= 0x170;
		uint64_t m_bLifeState							= 0x297;
		uint64_t m_bSpotted								= 0xECD;
		uint64_t m_bSpottedBy							= 0xF10;
		uint64_t m_dwBoneMatrix							= 0x2C80;
		uint64_t m_hMyWeapons							= 0x3538;
		uint64_t m_hActiveWeapon						= 0x3638;
//		uint64_t m_hLocalPlayer							= 0x3700;
//		uint64_t m_hViewModelIndex						= 0x3AE4;
		uint64_t m_bHasMovedSinceSpawn					= 0x4245;
		uint64_t m_iShotFired							= 0xACC0;
		uint64_t m_flFlashMaxAlpha						= 0xAD4C; // 0xAD2C
		uint64_t m_flFlashDuration						= 0xAD50; // 0xAD30
		uint64_t m_iGlowIndex							= 0xAD68; // 0xAD48 // 0xAD2C
//		uint64_t m_dwCrosshairID               		 	= 0xBC08;
		
		// m_dwEntityList - ...
		uint64_t m_iMaxPlayers							= 0xDC00;
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
		uint64_t m_iKills                              	= 0x12CC;
		uint64_t m_iAssists                            	= 0x13D0;
		uint64_t m_iDeaths                             	= 0x14D4;
		uint64_t m_iTeam2                              	= 0x15D8;
		uint64_t m_bConnected                          	= 0x17DD;
		uint64_t m_iHealth2                            	= 0x1824;
		uint64_t m_iMVPs								= 0x1D90;
		uint64_t m_bHasDefuser                         	= 0x1E91;
		uint64_t m_bHasHelmet                          	= 0x1ED2;
		uint64_t m_iArmor                              	= 0x1F18;
		uint64_t m_iScore								= 0x201C;
//		uint64_t m_iCompetitiveRanking                 	= 0x2124;
//		uint64_t m_iCompetitiveWins                    	= 0x2228;
		uint64_t m_iCompetitiveRanking                 	= 0x20E0;
		uint64_t m_iCompetitiveWins                    	= 0x21E4;
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
	
	const char* entityClass[57] {
		// player
		"10C_CSPlayer",
		// hostage
		"10C_CHostage",
		// chicken
		"10C_CChicken",
		// C4
		"4C_C4",
		// plantedC4
		"11C_PlantedC4",
		// weapon
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
		"14C_WeaponXM1014",
		// utility
		"11C_Flashbang",
		"11C_HEGrenade",
		"14C_DecoyGrenade",
		"16C_MolotovGrenade",
		"19C_IncendiaryGrenade",
		"15C_SensorGrenade",
		"14C_SmokeGrenade",
		// props
		"11C_CSRagdoll",
		"13C_DynamicProp",
		// resources
		"16C_PlayerResource",
		"19C_CS_PlayerResource",
		// team
		"8C_CSTeam"
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
		resource,
		team,
		other = -1
	};
	
	
	inline sOffsets::EntityType getEntityType(std::string clsName)
	{
		auto begin = std::begin(entityClass);
		auto end = std::end(entityClass);
		auto it = std::find(begin, end, clsName);
		
		bool cmp = (it == end);
		int index = (int)(it - begin);
		
		return EntityType(  (int)other 			* cmp
						  + (int)player 		* (index == 0)
						  + (int)hostage 		* (index == 1)
						  + (int)chicken 		* (index == 2)
						  + (int)C4 			* (index == 3)
						  + (int)plantedC4 		* (index == 4)
						  + (int)weapon 		* (index > 4 && index < 46)
						  + (int)utility 		* (index > 45 && index < 52)
						  + (int)props 			* (index > 51 && index < 54)
						  + (int)resource		* (index > 53 && index < 56)
						  + (int)team 			* (index > 55 && index < 57)
		);
	}
	
};

#endif /*OFFSETS_HPP*/

/*
 CCSTeam
 DT_CSTeam
 CPlantedC4
 DT_PlantedC4
 m_bBombTicking
 m_flC4Blow
 m_flTimerLength
 m_flDefuseLength
 m_flDefuseCountDown
 m_bBombDefused
 m_hBombDefuser
 */

/*
 DT_CSLocalPlayerExclusive
 m_vecOrigin[2]
 m_flVelocityModifier
 m_bPlayerDominated
 m_bPlayerDominated[0]
 m_bPlayerDominatingMe
 m_bPlayerDominatingMe[0]
 m_iWeaponPurchasesThisRound
 m_iWeaponPurchasesThisRound[0]
 m_nQuestProgressReason
 */

/*
 DT_CSNonLocalPlayerExclusive
 CCSPlayer
 DT_CSPlayer
 cslocaldata
 csnonlocaldata
 m_angEyeAngles[0]
 m_angEyeAngles[1]
 m_iAddonBits
 m_iPrimaryAddon
 m_iSecondaryAddon
 m_iThrowGrenadeCounter
 m_bWaitForNoAttack
 m_bIsRespawningForDMBonus
 m_iPlayerState
 m_iAccount
 m_iStartAccount
 m_totalHitsOnServer
 m_bInBombZone
 m_bInBuyZone
 m_bInNoDefuseArea
 m_bKilledByTaser
 m_iMoveState
 m_iClass
 m_ArmorValue
 m_angEyeAngles
 m_bHasDefuser
 m_bNightVisionOn
 m_bHasNightVision
 m_bInHostageRescueZone
 m_bIsDefusing
 m_bIsGrabbingHostage
 m_fImmuneToGunGameDamageTime
 m_bGunGameImmunity
 m_bHasMovedSinceSpawn
 m_bMadeFinalGunGameProgressiveKill
 m_iGunGameProgressiveWeaponIndex
 m_iNumGunGameTRKillPoints
 m_iNumGunGameKillsWithCurrentWeapon
 m_iNumRoundKills
 m_fMolotovUseTime
 m_fMolotovDamageTime
 m_szArmsModel
 m_hCarriedHostage
 m_hCarriedHostageProp
 m_bIsRescuing
 m_flGroundAccelLinearFracLastTime
 m_bCanMoveDuringFreezePeriod
 m_isCurrentGunGameLeader
 m_isCurrentGunGameTeamLeader
 m_flGuardianTooFarDistFrac
 m_flDetectedByEnemySensorTime
 m_iMatchStats_Kills
 m_iMatchStats_Kills[0]
 m_iMatchStats_Damage
 m_iMatchStats_Damage[0]
 m_iMatchStats_EquipmentValue
 m_iMatchStats_EquipmentValue[0]
 m_iMatchStats_MoneySaved
 m_iMatchStats_MoneySaved[0]
 m_iMatchStats_KillReward
 m_iMatchStats_KillReward[0]
 m_iMatchStats_LiveTime
 m_iMatchStats_LiveTime[0]
 m_iMatchStats_Deaths
 m_iMatchStats_Deaths[0]
 m_iMatchStats_Assists
 m_iMatchStats_Assists[0]
 m_iMatchStats_HeadShotKills
 m_iMatchStats_HeadShotKills[0]
 m_iMatchStats_Objective
 m_iMatchStats_Objective[0]
 m_iMatchStats_CashEarned
 m_iMatchStats_CashEarned[0]
 m_iMatchStats_UtilityDamage
 m_iMatchStats_UtilityDamage[0]
 m_iMatchStats_EnemiesFlashed
 m_iMatchStats_EnemiesFlashed[0]
 m_rank
 m_rank[0]
 m_unMusicID
 m_bHasHelmet
 m_bHasHeavyArmor
 m_flFlashDuration
 m_flFlashMaxAlpha
 m_iProgressBarDuration
 m_flProgressBarStartTime
 m_hRagdoll
 m_cycleLatch
 m_unCurrentEquipmentValue
 m_unRoundStartEquipmentValue
 m_unFreezetimeEndEquipmentValue
 m_bIsControllingBot
 m_bHasControlledBotThisRound
 m_bCanControlObservedBot
 m_iControlledBotEntIndex
 m_bIsAssassinationTarget
 m_bHud_MiniScoreHidden
 m_bHud_RadarHidden
 m_nLastKillerIndex
 m_nLastConcurrentKilled
 m_nDeathCamMusic
 m_bIsHoldingLookAtWeapon
 m_bIsLookingAtWeapon
 m_iNumRoundKillsHeadshots
 m_flLowerBodyYawTarget
 m_bStrafing
 */

/*
 CCSRagdoll
 DT_CSRagdoll
 m_vecRagdollOrigin
 m_nForceBone
 m_vecForce
 m_vecRagdollVelocity
 m_iDeathPose
 m_iDeathFrame
 m_iTeamNum
 m_bClientSideAnimation
 m_flDeathYaw
 */

/*
 CTEPlayerAnimEvent
 DT_TEPlayerAnimEvent
 m_iEvent
 m_nData
 C_CSPlayer
 m_flStamina
 m_iShotsFired
 m_iDirection
 m_bIsScoped
 m_bIsWalking
 m_bResumeZoom
 m_nNumFastDucks
 m_bDuckOverride
 */

/*
 CHostageCarriableProp
 DT_HostageCarriableProp
 death1
 CHostage
 DT_CHostage
 m_isRescued
 m_jumpedThisFrame
 m_iHealth
 m_iMaxHealth
 m_lifeState
 m_nHostageState
 m_flRescueStartTime
 m_flGrabSuccessTime
 m_flDropStartTime
 m_vel
 m_leader
 */

/*
 DT_BCCLocalPlayerExclusive
 DT_BCCNonLocalPlayerExclusive
 m_hMyWeapons
 m_hMyWeapons[0]
 DT_BaseCombatCharacter
 bcc_localdata
 bcc_nonlocaldata
 m_LastHitGroup
 m_hActiveWeapon
 m_flTimeOfLastInjury
 m_nRelativeDirectionOfLastInjury
 C_BaseCombatCharacter
 m_iAmmo
 */

/*
 DT_BaseEntity
 AnimTimeMustBeFirst
 m_flSimulationTime
 m_cellbits
 m_cellX
 m_cellY
 m_cellZ
 m_angRotation
 m_iPendingTeamNum
 m_CollisionGroup
 m_flElasticity
 m_flShadowCastDistance
 m_hOwnerEntity
 m_hEffectEntity
 m_iParentAttachment
 m_iName
 movetype
 movecollide
 m_Collision
 m_iTextureFrameIndex
 m_bSimulatedEveryTick
 m_bAnimatedEveryTick
 m_bAlternateSorting
 m_bSpotted
 m_bSpottedBy
 m_bSpottedBy[0]
 m_bSpottedByMask
 m_bSpottedByMask[0]
 m_bIsAutoaimTarget
 m_fadeMinDist
 m_fadeMaxDist
 m_flFadeScale
 m_nMaxCPULevel
 m_nMaxGPULevel
 m_flUseLookAtAngle
 m_MoveType
 m_MoveCollide
 m_vecAbsVelocity
 m_vecViewOffset
 m_flFriction
 m_hNetworkMoveParent
 m_vecNetworkOrigin
 m_angNetworkAngles
 m_vecAbsOrigin
 m_angAbsRotation
 m_hGroundEntity
 m_nWaterLevel
 m_nWaterType
 m_vecAngVelocity
 m_vecBaseVelocity
 m_iEFlags
 m_flGravity
 m_flProxyRandomValue
 m_bEverHadPredictionErrorsForThisCommand
 */
