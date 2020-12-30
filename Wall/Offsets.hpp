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
		uint64_t m_bSpotted								= 0xECD;
		uint64_t m_bSpottedBy							= 0xF10;
		uint64_t m_dwBoneMatrix							= 0x2C80;
		uint64_t m_hMyWeapons							= 0x3538;
		uint64_t m_hActiveWeapon						= 0x3638;
//		uint64_t m_hLocalPlayer							= 0x3700;
//		uint64_t m_hViewModelIndex						= 0x3AE4;
		uint64_t m_iEquipped 							= 0x3AD8;
		uint64_t m_hOwner 								= 0x3AB0;
		uint64_t m_bHasMovedSinceSpawn					= 0x4245;
		uint64_t m_iShotFired							= 0xACC0;
		uint64_t m_flFlashMaxAlpha						= 0xAD4C; // 0xAD2C
		uint64_t m_flFlashDuration						= 0xAD50; // 0xAD30
		uint64_t m_iGlowIndex							= 0xAD68; // 0xAD48 // 0xAD2C
//		uint64_t m_dwCrosshairID               		 	= 0xBC08;
		
//		uint64_t m_iClip1 								= 0x3AE4;
		uint64_t m_bInReload 							= 0x3B29;
		uint64_t m_iState 								= 0x3B34;
		
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

//		uint64_t m_iCompetitiveRanking                 	= 0x20E0;
//		uint64_t m_iCompetitiveWins                    	= 0x21E4;
		
		uint64_t m_iCompetitiveRanking                 	= 0x98E8;
		uint64_t m_iCompetitiveWins                    	= 0x99EC;

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


struct sOffsets2 {
	
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
	};
	
	struct sClient {
		uint64_t m_dwLocalPlayer;
		uint64_t m_dwEntityList;
		uint64_t m_dwGlowManager;
		uint64_t m_dwPlayerResource;
		uint64_t m_dwRadarManager;
		
		struct {
			uint64_t m_vecMins = 0x10;
			uint64_t m_vecMaxs = 0x1c;
			uint64_t m_nSolidType = 0x2a;
			uint64_t m_usSolidFlags = 0x28;
			uint64_t m_nSurroundType = 0x32;
			uint64_t m_triggerBloat = 0x2b;
			uint64_t m_vecSpecifiedSurroundingMins = 0x34;
			uint64_t m_vecSpecifiedSurroundingMaxs = 0x40;
		} DT_CollisionProperty;
		
		struct {
			uint64_t m_flAnimTime = 0x298;
			uint64_t m_flSimulationTime = 0x2a0;
			uint64_t m_cellbits = 0xac;
			uint64_t m_cellX = 0xb4;
			uint64_t m_cellY = 0xb8;
			uint64_t m_cellZ = 0xbc;
			uint64_t m_vecOrigin = 0x170;
			uint64_t m_angRotation = 0x164;
			uint64_t m_nModelIndex = 0x290;
			uint64_t m_fEffects = 0x128;
			uint64_t m_nRenderMode = 0x293;
			uint64_t m_nRenderFX = 0x292;
			uint64_t m_clrRender = 0xa8;
			uint64_t m_iTeamNum = 0x12c;
			uint64_t m_iPendingTeamNum = 0x130;
			uint64_t m_CollisionGroup = 0x548;
			uint64_t m_flElasticity = 0x354;
			uint64_t m_flShadowCastDistance = 0x420;
			uint64_t m_hOwnerEntity = 0x184;
			uint64_t m_hEffectEntity = 0xf28;
			uint64_t m_iParentAttachment = 0x340;
			uint64_t m_iName = 0x18c;
			uint64_t m_Collision = 0x378;
			uint64_t m_iTextureFrameIndex = 0xf1c;
			uint64_t m_bSimulatedEveryTick = 0xeca;
			uint64_t m_bAnimatedEveryTick = 0xecb;
			uint64_t m_bAlternateSorting = 0xecc;
			uint64_t m_bSpotted = 0xecd;
			uint64_t m_bSpottedBy = 0xece;
			uint64_t m_bSpottedByMask = 0xf10;
			uint64_t m_bIsAutoaimTarget = 0x90;
			uint64_t m_fadeMinDist = 0x348;
			uint64_t m_fadeMaxDist = 0x34c;
			uint64_t m_flFadeScale = 0x350;
			uint64_t m_nMinCPULevel = 0xf18;
			uint64_t m_nMaxCPULevel = 0xf19;
			uint64_t m_nMinGPULevel = 0xf1a;
			uint64_t m_nMaxGPULevel = 0xf1b;
			uint64_t m_flUseLookAtAngle = 0x318;
			uint64_t m_flLastMadeNoiseTime = 0x40;
			uint64_t m_flMaxFallVelocity = 0x114;
			uint64_t m_bEligibleForScreenHighlight = 0xf49;
		} DT_BaseEntity;
		
		struct {
			uint64_t m_chAreaBits = 0x8;
			uint64_t m_chAreaPortalBits = 0x28;
			uint64_t m_iHideHUD = 0x4c;
			uint64_t m_flFOVRate = 0x48;
			uint64_t m_bDucked = 0x8c;
			uint64_t m_bDucking = 0x8d;
			uint64_t m_flLastDuckTime = 0x90;
			uint64_t m_bInDuckJump = 0x94;
			uint64_t m_nDuckTimeMsecs = 0x50;
			uint64_t m_nDuckJumpTimeMsecs = 0x54;
			uint64_t m_nJumpTimeMsecs = 0x58;
			uint64_t m_flFallVelocity = 0x5c;
			uint64_t m_viewPunchAngle = 0x68;
			uint64_t m_aimPunchAngle = 0x74;
			uint64_t m_aimPunchAngleVel = 0x80;
			uint64_t m_bDrawViewmodel = 0x95;
			uint64_t m_bWearingSuit = 0x96;
			uint64_t m_bPoisoned = 0x97;
			uint64_t m_flStepSize = 0x64;
			uint64_t m_bAllowAutoMovement = 0x98;
		} DT_Local;
		
		struct {
			uint64_t m_Local = 0x3700;
			uint64_t m_vecViewOffset = 0x140;
			uint64_t m_flFriction = 0x17c;
			uint64_t m_fOnTarget = 0x3b0c;
			uint64_t m_nTickBase = 0x3c50;
			uint64_t m_nNextThinkTick = 0x134;
			uint64_t m_hLastWeapon = 0x3ad0;
			uint64_t m_vecVelocity = 0x14c;
			uint64_t m_vecBaseVelocity = 0x158;
			uint64_t m_hConstraintEntity = 0x3b30;
			uint64_t m_vecConstraintCenter = 0x3b34;
			uint64_t m_flConstraintRadius = 0x3b40;
			uint64_t m_flConstraintWidth = 0x3b44;
			uint64_t m_flConstraintSpeedFactor = 0x3b48;
			uint64_t m_bConstraintPastRadius = 0x3b4c;
			uint64_t m_flDeathTime = 0x3bbc;
			uint64_t m_flNextDecalTime = 0x3bc0;
			uint64_t m_fForceTeam = 0x3bc4;
			uint64_t m_flLaggedMovementValue = 0x3dd0;
			uint64_t m_hTonemapController = 0x3988;
		} DT_LocalPlayerExclusive;
		
		struct {
			uint64_t m_iFOV = 0x39a8;
			uint64_t m_iFOVStart = 0x39ac;
			uint64_t m_flFOVTime = 0x39cc;
			uint64_t m_iDefaultFOV = 0x3b14;
			uint64_t m_hZoomOwner = 0x3a10;
			uint64_t m_afPhysicsFlags = 0x3ac8;
			uint64_t m_hVehicle = 0x3acc;
			uint64_t m_hUseEntity = 0x3b10;
			uint64_t m_hGroundEntity = 0x188;
			uint64_t m_iHealth = 0x138;
			uint64_t m_lifeState = 0x297;
			uint64_t m_iAmmo = 0x34b8;
			uint64_t m_iBonusProgress = 0x3a04;
			uint64_t m_iBonusChallenge = 0x3a08;
			uint64_t m_flMaxspeed = 0x3a0c;
			uint64_t m_fFlags = 0x13c;
			uint64_t m_iObserverMode = 0x3b70;
			uint64_t m_bActiveCameraMan = 0x3b74;
			uint64_t m_bCameraManXRay = 0x3b75;
			uint64_t m_bCameraManOverview = 0x3b76;
			uint64_t m_bCameraManScoreBoard = 0x3b77;
			uint64_t m_uCameraManGraphs = 0x3b78;
			uint64_t m_iDeathPostEffect = 0x3b6c;
			uint64_t m_hObserverTarget = 0x3b84;
			uint64_t m_hViewModel = 0x3ad4;
			uint64_t m_iCoachingTeam = 0x368c;
			uint64_t m_szLastPlaceName = 0x3df0;
			uint64_t m_vecLadderNormal = 0x39f4;
			uint64_t m_ladderSurfaceProps = 0x39c4;
			uint64_t m_ubEFNoInterpParity = 0x3e18;
			uint64_t m_hPostProcessCtrl = 0x4030;
			uint64_t m_hColorCorrectionCtrl = 0x4034;
			uint64_t m_vphysicsCollisionState = 0x3a30;
			uint64_t m_hViewEntity = 0x3b28;
			uint64_t m_bShouldDrawPlayerWhileUsingViewEntity = 0x3b2c;
			uint64_t m_flDuckAmount = 0x36f0;
			uint64_t m_flDuckSpeed = 0x36f4;
			uint64_t m_nWaterLevel = 0x296;
		} DT_BasePlayer;
		
		struct {
			uint64_t m_flexWeight = 0x30e8;
			uint64_t m_blinktoggle = 0x32b0;
			uint64_t m_viewtarget = 0x3094;
		} DT_BaseFlex;
		
		struct {
			uint64_t m_flNextAttack = 0x34b0;
			uint64_t m_hMyWeapons = 0x3538;
			uint64_t m_LastHitGroup = 0x34b4;
			uint64_t m_hActiveWeapon = 0x3638;
			uint64_t m_flTimeOfLastInjury = 0x363c;
			uint64_t m_nRelativeDirectionOfLastInjury = 0x3640;
			uint64_t m_hMyWearables = 0x3644;
		} DT_BaseCombatCharacter;
		
		struct  {
			uint64_t m_modelIndex = 0xf68;
			uint64_t m_solidIndex = 0xf6c;
		} DT_BoneFollower;
		
		struct {
			uint64_t m_nSequence = 0x2ef8;
			uint64_t m_nForceBone = 0x2c54;
			uint64_t m_vecForce = 0x2c48;
			uint64_t m_nSkin = 0xfd8;
			uint64_t m_nBody = 0xfdc;
			uint64_t m_nHitboxSet = 0xfa8;
			uint64_t m_flModelScale = 0x2d40;
			uint64_t m_flPoseParameter = 0x2d78;
			uint64_t m_flPlaybackRate = 0xfd4;
			uint64_t m_flEncodedController = 0x1010;
			uint64_t m_bClientSideAnimation = 0x2ed8;
			uint64_t m_bClientSideFrameReset = 0x2c9c;
			uint64_t m_bClientSideRagdoll = 0x2b1;
			uint64_t m_nNewSequenceParity = 0x1000;
			uint64_t m_nResetEventsParity = 0x1004;
			uint64_t m_nMuzzleFlashParity = 0x1020;
			uint64_t m_hLightingOrigin = 0x2fc8;
			uint64_t m_flCycle = 0xfd0;
			uint64_t m_flFrozen = 0x2ce0;
			uint64_t m_ScaleType = 0x2d44;
			uint64_t m_bSuppressAnimSounds = 0x2fce;
			uint64_t m_nHighlightColorR = 0xff4;
			uint64_t m_nHighlightColorG = 0xff8;
			uint64_t m_nHighlightColorB = 0xffc;
		} DT_BaseAnimating;
		
		struct {
			uint64_t m_nModelIndex = 0x290;
			uint64_t m_hWeapon = 0x3070;
			uint64_t m_nSkin = 0xfd8;
			uint64_t m_nBody = 0xfdc;
			uint64_t m_nSequence = 0x2ef8;
			uint64_t m_nViewModelIndex = 0x3068;
			uint64_t m_flPlaybackRate = 0xfd4;
			uint64_t m_fEffects = 0x128;
			uint64_t m_nAnimationParity = 0x306c;
			uint64_t m_hOwner = 0x3074;
			uint64_t m_nNewSequenceParity = 0x1000;
			uint64_t m_nResetEventsParity = 0x1004;
			uint64_t m_nMuzzleFlashParity = 0x1020;
			uint64_t m_bShouldIgnoreOffsetAndAccuracy = 0x302c;
		} DT_BaseViewModel;
		
		struct  {
			uint64_t m_flDamage = 0x3030;
			uint64_t m_DmgRadius = 0x301c;
			uint64_t m_bIsLive = 0x3019;
			uint64_t m_hThrower = 0x3040;
			uint64_t m_vecVelocity = 0x14c;
			uint64_t m_fFlags = 0x13c;
		} DT_BaseGrenade;
		
		struct {
			uint64_t m_iPrimaryAmmoType = 0x3adc;
			uint64_t m_iSecondaryAmmoType = 0x3ae0;
			uint64_t m_nViewModelIndex = 0x3ab4;
			uint64_t m_bFlipViewModel = 0x3b48;
			uint64_t m_iWeaponOrigin = 0x3b4c;
			uint64_t m_iWeaponModule = 0x3acc;
			uint64_t m_flNextPrimaryAttack = 0x3ab8;
			uint64_t m_flNextSecondaryAttack = 0x3abc;
			uint64_t m_nNextThinkTick = 0x134;
			uint64_t m_flTimeWeaponIdle = 0x3af4;
			uint64_t m_iViewModelIndex = 0x3ac0;
			uint64_t m_iWorldModelIndex = 0x3ac4;
			uint64_t m_iWorldDroppedModelIndex = 0x3ac8;
			uint64_t m_iState = 0x3ad8;
			uint64_t m_hOwner = 0x3ab0;
			uint64_t m_iClip1 = 0x3ae4;
			uint64_t m_iClip2 = 0x3ae8;
			uint64_t m_iPrimaryReserveAmmoCount = 0x3aec;
			uint64_t m_iSecondaryReserveAmmoCount = 0x3af0;
			uint64_t m_hWeaponWorldModel = 0x3ad4;
			uint64_t m_iNumEmptyAttacks = 0x3ad0;
		} DT_BaseCombatWeapon;
		
		struct {
			uint64_t m_nModelIndex = 0x290;
			uint64_t m_nBody = 0xfdc;
			uint64_t m_fEffects = 0x128;
			uint64_t m_hCombatWeaponParent = 0x3094;
		} DT_BaseWeaponWorldModel;
		
		struct {
			uint64_t m_qPreferredPlayerCarryAngles = 0x3020;
			uint64_t m_bClientPhysics = 0x302c;
		} DT_BreakableProp;
		
		struct {
			uint64_t m_bShouldGlow = 0x3ab0;
		} DT_Item;
		
		struct {
			uint64_t m_iPing = 0x11c4;
			uint64_t m_iKills = 0x12c8;
			uint64_t m_iAssists = 0x13cc;
			uint64_t m_iDeaths = 0x14d0;
			uint64_t m_bConnected = 0x1180;
			uint64_t m_iTeam = 0x15d4;
			uint64_t m_iPendingTeam = 0x16d8;
			uint64_t m_bAlive = 0x17dc;
			uint64_t m_iHealth = 0x1820;
			uint64_t m_iCoachingTeam = 0x1924;
		} DT_PlayerResource;
		
		struct {
			uint64_t m_bUseHitboxesForRenderBox = 0x3034;
			uint64_t m_flGlowMaxDist = 0x3054;
			uint64_t m_bShouldGlow = 0x3058;
			uint64_t m_clrGlow = 0x3059;
			uint64_t m_nGlowStyle = 0x3060;
		} DT_DynamicProp;
		
		struct  {
			uint64_t m_iTeamNum = 0x1104;
			uint64_t m_bSurrendered = 0x1108;
			uint64_t m_scoreTotal = 0x10dc;
			uint64_t m_scoreFirstHalf = 0x10e0;
			uint64_t m_scoreSecondHalf = 0x10e4;
			uint64_t m_scoreOvertime = 0x10e8;
			uint64_t m_iClanID = 0x10f4;
			uint64_t m_szTeamname = 0xf88;
			uint64_t m_szClanTeamname = 0xfa8;
			uint64_t m_szTeamFlagImage = 0xfc8;
			uint64_t m_szTeamLogoImage = 0xfd0;
			uint64_t m_szTeamMatchStat = 0xfd8;
			uint64_t m_nGGLeaderEntIndex_CT = 0x10ec;
			uint64_t m_nGGLeaderEntIndex_T = 0x10f0;
			uint64_t m_numMapVictories = 0x110c;
		} DT_Team;
		
		struct {
			uint64_t m_hOuter = 0x2c;
			uint64_t m_ProviderType = 0x34;
			uint64_t m_iReapplyProvisionParity = 0x28;
			uint64_t m_Item = 0x60;
			uint64_t m_iItemDefinitionIndex = 0x282;
			uint64_t m_iEntityLevel = 0x288;
			uint64_t m_iItemIDHigh = 0x298;
			uint64_t m_iItemIDLow = 0x29c;
			uint64_t m_iAccountID = 0x2a0;
			uint64_t m_iEntityQuality = 0x284;
			uint64_t m_bInitialized = 0x2b0;
			uint64_t m_szCustomName = 0x358;
			uint64_t m_NetworkedDynamicAttributesForDemos = 0x328;
		} DT_AttributeContainer;
		
		struct {
			uint64_t m_AttributeManager = 0x34d0;
			uint64_t m_OriginalOwnerXuidLow = 0x3a20;
			uint64_t m_OriginalOwnerXuidHigh = 0x3a24;
			uint64_t m_nFallbackPaintKit = 0x3a28;
			uint64_t m_nFallbackSeed = 0x3a2c;
			uint64_t m_flFallbackWear = 0x3a30;
			uint64_t m_nFallbackStatTrak = 0x3a34;
		} DT_EconEntity;
		
		struct {
			uint64_t m_vInitialVelocity = 0x3068;
			uint64_t m_nBounces = 0x3074;
			uint64_t m_nExplodeEffectIndex = 0x3078;
			uint64_t m_nExplodeEffectTickBegin = 0x307c;
			uint64_t m_vecExplodeEffectOrigin = 0x3080;
		} DT_BaseCSGrenadeProjectile;
		
		struct {
			uint64_t m_isRescued = 0x3678;
			uint64_t m_jumpedThisFrame = 0x3679;
			uint64_t m_iHealth = 0x138;
			uint64_t m_iMaxHealth = 0x365c;
			uint64_t m_lifeState = 0x297;
			uint64_t m_fFlags = 0x13c;
			uint64_t m_nHostageState = 0x367c;
			uint64_t m_flRescueStartTime = 0x3680;
			uint64_t m_flGrabSuccessTime = 0x3684;
			uint64_t m_flDropStartTime = 0x3688;
			uint64_t m_vel = 0x366c;
			uint64_t m_leader = 0x3668;
		} DT_CHostage;
		
		struct {
			uint64_t m_hPlayer = 0xf80;
			uint64_t m_hPingedEntity = 0xf84;
			uint64_t m_iType = 0xf88;
			uint64_t m_bUrgent = 0xf90;
		} DT_PlayerPing;
		
		struct {
			uint64_t m_vecOrigin = 0x170;
			uint64_t m_vecRagdollOrigin = 0x30b0;
			uint64_t m_hPlayer = 0x3094;
			uint64_t m_nModelIndex = 0x290;
			uint64_t m_nForceBone = 0x2c54;
			uint64_t m_vecForce = 0x2c48;
			uint64_t m_vecRagdollVelocity = 0x30a4;
			uint64_t m_iDeathPose = 0x30bc;
			uint64_t m_iDeathFrame = 0x30c0;
			uint64_t m_iTeamNum = 0x12c;
			uint64_t m_bClientSideAnimation = 0x2ed8;
			uint64_t m_flDeathYaw = 0x30c4;
			uint64_t m_flAbsYaw = 0x30c8;
		} DT_CSRagdoll;
		
		struct {
			uint64_t m_vecOrigin = 0x170;
			uint64_t m_flStamina = 0xacb8;
			uint64_t m_iDirection = 0xacbc;
			uint64_t m_iShotsFired = 0xacc0;
			uint64_t m_nNumFastDucks = 0xacc4;
			uint64_t m_bDuckOverride = 0xacc8;
			uint64_t m_flVelocityModifier = 0xaccc;
			uint64_t m_bPlayerDominated = 0xbe28;
			uint64_t m_bPlayerDominatingMe = 0xbe69;
			uint64_t m_iWeaponPurchasesThisRound = 0xbeac;
			uint64_t m_unActiveQuestId = 0xbc6c;
			uint64_t m_nQuestProgressReason = 0xbc70;
			uint64_t m_iWeaponPurchasesThisMatch = 0xb3ac;
			uint64_t m_EquippedLoadoutItemDefIndices = 0xbb90;
			uint64_t m_iAddonBits = 0xaca4;
			uint64_t m_iPrimaryAddon = 0xaca8;
			uint64_t m_iSecondaryAddon = 0xacac;
			uint64_t m_iThrowGrenadeCounter = 0x426c;
			uint64_t m_bWaitForNoAttack = 0x4270;
			uint64_t m_bIsRespawningForDMBonus = 0x4271;
			uint64_t m_iPlayerState = 0x422c;
			uint64_t m_iAccount = 0xbca8;
			uint64_t m_iStartAccount = 0xacd4;
			uint64_t m_totalHitsOnServer = 0xacd8;
			uint64_t m_bInBombZone = 0x4268;
			uint64_t m_bInBuyZone = 0x4269;
			uint64_t m_bInNoDefuseArea = 0x426a;
			uint64_t m_bKilledByTaser = 0x4281;
			uint64_t m_iMoveState = 0x4284;
			uint64_t m_iClass = 0xbcb8;
			uint64_t m_ArmorValue = 0xbcbc;
			uint64_t m_angEyeAngles = 0xbcc0;
			uint64_t m_bHasDefuser = 0xbccc;
			uint64_t m_bNightVisionOn = 0xacc9;
			uint64_t m_bHasNightVision = 0xacca;
			uint64_t m_bInHostageRescueZone = 0xbccd;
			uint64_t m_bIsDefusing = 0x4230;
			uint64_t m_bIsGrabbingHostage = 0x4231;
			uint64_t m_iBlockingUseActionInProgress = 0x4234;
			uint64_t m_bIsScoped = 0x4228;
			uint64_t m_bIsWalking = 0x4229;
			uint64_t m_nIsAutoMounting = 0x43a0;
			uint64_t m_bResumeZoom = 0x422a;
			uint64_t m_fImmuneToGunGameDamageTime = 0x423c;
			uint64_t m_bGunGameImmunity = 0x4244;
			uint64_t m_bHasMovedSinceSpawn = 0x4245;
			uint64_t m_bMadeFinalGunGameProgressiveKill = 0x4246;
			uint64_t m_iGunGameProgressiveWeaponIndex = 0x4248;
			uint64_t m_iNumGunGameTRKillPoints = 0x424c;
			uint64_t m_iNumGunGameKillsWithCurrentWeapon = 0x4250;
			uint64_t m_iNumRoundKills = 0x4254;
			uint64_t m_fMolotovUseTime = 0x4260;
			uint64_t m_fMolotovDamageTime = 0x4264;
			uint64_t m_szArmsModel = 0x428b;
			uint64_t m_hCarriedHostage = 0xad28;
			uint64_t m_hCarriedHostageProp = 0xad2c;
			uint64_t m_bIsRescuing = 0x4238;
			uint64_t m_flGroundAccelLinearFracLastTime = 0xacd0;
			uint64_t m_bCanMoveDuringFreezePeriod = 0x4288;
			uint64_t m_isCurrentGunGameLeader = 0x4289;
			uint64_t m_isCurrentGunGameTeamLeader = 0x428a;
			uint64_t m_flGuardianTooFarDistFrac = 0x4274;
			uint64_t m_flDetectedByEnemySensorTime = 0x4278;
			uint64_t m_bIsPlayerGhost = 0x439d;
			uint64_t m_iMatchStats_Kills = 0xad94;
			uint64_t m_iMatchStats_Damage = 0xae0c;
			uint64_t m_iMatchStats_EquipmentValue = 0xae84;
			uint64_t m_iMatchStats_MoneySaved = 0xaefc;
			uint64_t m_iMatchStats_KillReward = 0xaf74;
			uint64_t m_iMatchStats_LiveTime = 0xafec;
			uint64_t m_iMatchStats_Deaths = 0xb064;
			uint64_t m_iMatchStats_Assists = 0xb0dc;
			uint64_t m_iMatchStats_HeadShotKills = 0xb154;
			uint64_t m_iMatchStats_Objective = 0xb1cc;
			uint64_t m_iMatchStats_CashEarned = 0xb244;
			uint64_t m_iMatchStats_UtilityDamage = 0xb2bc;
			uint64_t m_iMatchStats_EnemiesFlashed = 0xb334;
			uint64_t m_rank = 0xbc7c;
			uint64_t m_passiveItems = 0xbc94;
			uint64_t m_bHasParachute = 0xbc94;
			uint64_t m_unMusicID = 0xbc98;
			uint64_t m_bHasHelmet = 0xbcb0;
			uint64_t m_bHasHeavyArmor = 0xbcb1;
			uint64_t m_nHeavyAssaultSuitCooldownRemaining = 0xbcb4;
			uint64_t m_flFlashDuration = 0xad50;
			uint64_t m_flFlashMaxAlpha = 0xad4c;
			uint64_t m_iProgressBarDuration = 0xacb0;
			uint64_t m_flProgressBarStartTime = 0xacb4;
			uint64_t m_hRagdoll = 0xad1c;
			uint64_t m_hPlayerPing = 0xad20;
			uint64_t m_cycleLatch = 0xbe20;
			uint64_t m_unCurrentEquipmentValue = 0xbc74;
			uint64_t m_unRoundStartEquipmentValue = 0xbc76;
			uint64_t m_unFreezetimeEndEquipmentValue = 0xbc78;
			uint64_t m_bIsControllingBot = 0xc38d;
			uint64_t m_bHasControlledBotThisRound = 0xc39c;
			uint64_t m_bCanControlObservedBot = 0xc38e;
			uint64_t m_iControlledBotEntIndex = 0xc390;
			uint64_t m_vecAutomoveTargetEnd = 0x43b0;
			uint64_t m_flAutoMoveStartTime = 0x43c0;
			uint64_t m_flAutoMoveTargetTime = 0x43c4;
			uint64_t m_bIsAssassinationTarget = 0xc38c;
			uint64_t m_bHud_MiniScoreHidden = 0xbcee;
			uint64_t m_bHud_RadarHidden = 0xbcef;
			uint64_t m_nLastKillerIndex = 0xbcf0;
			uint64_t m_nLastConcurrentKilled = 0xbcf4;
			uint64_t m_nDeathCamMusic = 0xbcf8;
			uint64_t m_bIsHoldingLookAtWeapon = 0xc2b5;
			uint64_t m_bIsLookingAtWeapon = 0xc2b4;
			uint64_t m_iNumRoundKillsHeadshots = 0x4258;
			uint64_t m_unTotalRoundDamageDealt = 0x425c;
			uint64_t m_flLowerBodyYawTarget = 0x4398;
			uint64_t m_bStrafing = 0x439c;
			uint64_t m_flThirdpersonRecoil = 0xc32c;
			uint64_t m_bHideTargetID = 0xc330;
			uint64_t m_bIsSpawnRappelling = 0xacdd;
			uint64_t m_vecSpawnRappellingRopeOrigin = 0xace0;
			uint64_t m_nSurvivalTeam = 0xacf0;
			uint64_t m_hSurvivalAssassinationTarget = 0xacf4;
			uint64_t m_flHealthShotBoostExpirationTime = 0xacf8;
			uint64_t m_flLastExoJumpTime = 0x43c8;
			uint64_t m_vecPlayerPatchEconIndices = 0xc304;
		} DT_CSPlayer;
		
		struct {
			uint64_t m_iPlayerC4 = 0x1cf4;
			uint64_t m_iPlayerVIP = 0x1cf8;
			uint64_t m_bHostageAlive = 0x1d14;
			uint64_t m_isHostageFollowingSomeone = 0x1d20;
			uint64_t m_iHostageEntityIDs = 0x1d2c;
			uint64_t m_bombsiteCenterA = 0x1cfc;
			uint64_t m_bombsiteCenterB = 0x1d08;
			uint64_t m_hostageRescueX = 0x1d5c;
			uint64_t m_hostageRescueY = 0x1d6c;
			uint64_t m_hostageRescueZ = 0x1d7c;
			uint64_t m_iMVPs = 0x1d8c;
			uint64_t m_iArmor = 0x1f14;
			uint64_t m_bHasHelmet = 0x1ed1;
			uint64_t m_bHasDefuser = 0x1e90;
			uint64_t m_iScore = 0x2018;
			uint64_t m_iCompetitiveRanking = 0x211c;
			uint64_t m_iCompetitiveWins = 0x2220;
			uint64_t m_iCompetitiveRankType = 0x2324;
			uint64_t m_iCompTeammateColor = 0x2368;
			uint64_t m_iLifetimeStart = 0x246c;
			uint64_t m_iLifetimeEnd = 0x2570;
			uint64_t m_bControllingBot = 0x2674;
			uint64_t m_iControlledPlayer = 0x26b8;
			uint64_t m_iControlledByPlayer = 0x27bc;
			uint64_t m_iBotDifficulty = 0x4940;
			uint64_t m_szClan = 0x4a44;
			uint64_t m_nCharacterDefIndex = 0x4e54;
			uint64_t m_iTotalCashSpent = 0x4f58;
			uint64_t m_iGunGameLevel = 0x505c;
			uint64_t m_iCashSpentThisRound = 0x5160;
			uint64_t m_nEndMatchNextMapVotes = 0x7120;
			uint64_t m_bEndMatchNextMapAllVoted = 0x7224;
			uint64_t m_nActiveCoinRank = 0x5264;
			uint64_t m_nMusicID = 0x5368;
			uint64_t m_nPersonaDataPublicLevel = 0x546c;
			uint64_t m_nPersonaDataPublicCommendsLeader = 0x5570;
			uint64_t m_nPersonaDataPublicCommendsTeacher = 0x5674;
			uint64_t m_nPersonaDataPublicCommendsFriendly = 0x5778;
			uint64_t m_bHasCommunicationAbuseMute = 0x587c;
			uint64_t m_szCrosshairCodes = 0x58bd;
			uint64_t m_iMatchStats_Kills_Total = 0x61a0;
			uint64_t m_iMatchStats_5k_Total = 0x66b4;
			uint64_t m_iMatchStats_4k_Total = 0x65b0;
			uint64_t m_iMatchStats_3k_Total = 0x64ac;
			uint64_t m_iMatchStats_Damage_Total = 0x67b8;
			uint64_t m_iMatchStats_EquipmentValue_Total = 0x68bc;
			uint64_t m_iMatchStats_KillReward_Total = 0x69c0;
			uint64_t m_iMatchStats_LiveTime_Total = 0x6ac4;
			uint64_t m_iMatchStats_Deaths_Total = 0x63a8;
			uint64_t m_iMatchStats_Assists_Total = 0x62a4;
			uint64_t m_iMatchStats_HeadShotKills_Total = 0x6bc8;
			uint64_t m_iMatchStats_Objective_Total = 0x6ccc;
			uint64_t m_iMatchStats_CashEarned_Total = 0x6dd0;
			uint64_t m_iMatchStats_UtilityDamage_Total = 0x6ed4;
			uint64_t m_iMatchStats_EnemiesFlashed_Total = 0x6fd8;
		} DT_CSPlayerResource;
		
		struct {
			uint64_t m_bBombTicking = 0x3018;
			uint64_t m_nBombSite = 0x301c;
			uint64_t m_flC4Blow = 0x3028;
			uint64_t m_flTimerLength = 0x302c;
			uint64_t m_flDefuseLength = 0x3040;
			uint64_t m_flDefuseCountDown = 0x3044;
			uint64_t m_bBombDefused = 0x3048;
			uint64_t m_hBombDefuser = 0x304c;
		} DT_PlantedC4;
		
		struct  {
			uint64_t m_bRedraw = 0x3c74;
			uint64_t m_bIsHeldByPlayer = 0x3c75;
			uint64_t m_bPinPulled = 0x3c76;
			uint64_t m_fThrowTime = 0x3c78;
			uint64_t m_bLoopingSoundPlaying = 0x3c7c;
			uint64_t m_flThrowStrength = 0x3c80;
		} DT_BaseCSGrenade;
		
		struct {
			uint64_t m_bStartedArming = 0x3c94;
			uint64_t m_bBombPlacedAnimation = 0x3c9c;
			uint64_t m_fArmedTime = 0x3c98;
			uint64_t m_bShowC4LED = 0x3c9d;
			uint64_t m_bIsPlantingViaUse = 0x3c9e;
		} DT_WeaponC4;
		
		struct {
			uint64_t m_weaponMode = 0x3bac;
			uint64_t m_fAccuracyPenalty = 0x3bc4;
			uint64_t m_fLastShotTime = 0x3c50;
			uint64_t m_iRecoilIndex = 0x3bd4;
			uint64_t m_flRecoilIndex = 0x3bd8;
			uint64_t m_hPrevOwner = 0x3c1c;
			uint64_t m_bBurstMode = 0x3bdc;
			uint64_t m_flPostponeFireReadyTime = 0x3be0;
			uint64_t m_bReloadVisuallyComplete = 0x3be4;
			uint64_t m_bSilencerOn = 0x3be5;
			uint64_t m_flDoneSwitchingSilencer = 0x3be8;
			uint64_t m_iOriginalTeamNumber = 0x3bf0;
			uint64_t m_iIronSightMode = 0x3c70;
		} DT_WeaponCSBase;
		
		struct {

			uint64_t m_zoomLevel = 0x3c74;
			uint64_t m_iBurstShotsRemaining = 0x3c78;
		} DT_WeaponCSBaseGun;
		
		struct {
			uint64_t m_flThrowAt = 0x3c74;
		} DT_WeaponMelee;
		
		struct {
			uint64_t m_bShouldExplode = 0x3068;
			uint64_t m_weaponThatThrewMe = 0x306c;
			uint64_t m_nParentBoneIndex = 0x3070;
			uint64_t m_vecParentBonePos = 0x3074;
		} DT_BreachChargeProjectile;
		
		struct  {
			uint64_t m_nParentBoneIndex = 0x306c;
			uint64_t m_vecParentBonePos = 0x3070;
			uint64_t m_bArmed = 0x307c;
		} DT_BumpMineProjectile;
		
		struct {
			uint64_t m_jumpedThisFrame = 0x306c;
			uint64_t m_leader = 0x3070;
		} DT_CChicken;
		
		struct {
			uint64_t m_lifeState = 0x297;
			uint64_t m_bPerformAvoidance = 0x3660;
			uint64_t m_bIsMoving = 0x3661;
			uint64_t m_bFadeCorpse = 0x3662;
			uint64_t m_iDeathPose = 0x3650;
			uint64_t m_iDeathFrame = 0x3654;
			uint64_t m_iSpeedModRadius = 0x3658;
			uint64_t m_iSpeedModSpeed = 0x365c;
			uint64_t m_bSpeedModActive = 0x3663;
			uint64_t m_bImportanRagdoll = 0x3664;
			uint64_t m_flTimePingEffect = 0x364c;
		} DT_AI_BaseNPC;
	};
	
	enum TeamNumID: int
	{
		TEAM_UNASSIGNED,
		TEAM_SPECTATOR,
		TEAM_TERRORIST,
		TEAM_COUNTER_TERRORIST,
	};
	
	enum ItemDefinitionIndex: int
	{
		WEAPON_DEAGLE = 1,
		WEAPON_ELITE = 2,
		WEAPON_FIVESEVEN = 3,
		WEAPON_GLOCK = 4,
		WEAPON_AK47 = 7,
		WEAPON_AUG = 8,
		WEAPON_AWP = 9,
		WEAPON_FAMAS = 10,
		WEAPON_G3SG1 = 11,
		WEAPON_GALILAR = 13,
		WEAPON_M249 = 14,
		WEAPON_M4A1 = 16,
		WEAPON_MAC10 = 17,
		WEAPON_P90 = 19,
		WEAPON_UMP45 = 24,
		WEAPON_XM1014 = 25,
		WEAPON_BIZON = 26,
		WEAPON_MAG7 = 27,
		WEAPON_NEGEV = 28,
		WEAPON_SAWEDOFF = 29,
		WEAPON_TEC9 = 30,
		WEAPON_TASER = 31,
		WEAPON_HKP2000 = 32,
		WEAPON_MP7 = 33,
		WEAPON_MP9 = 34,
		WEAPON_NOVA = 35,
		WEAPON_P250 = 36,
		WEAPON_SCAR20 = 38,
		WEAPON_SG556 = 39,
		WEAPON_SSG08 = 40,
		WEAPON_KNIFE = 42,
		WEAPON_FLASHBANG = 43,
		WEAPON_HEGRENADE = 44,
		WEAPON_SMOKEGRENADE = 45,
		WEAPON_MOLOTOV = 46,
		WEAPON_DECOY = 47,
		WEAPON_INCGRENADE = 48,
		WEAPON_C4 = 49,
		WEAPON_KNIFE_T = 59,
		WEAPON_M4A1_SILENCER = 60,
		WEAPON_USP_SILENCER = 61,
		WEAPON_CZ75A = 63,
		WEAPON_REVOLVER = 64,
		WEAPON_KNIFE_BAYONET = 500,
		WEAPON_KNIFE_FLIP = 505,
		WEAPON_KNIFE_GUT = 506,
		WEAPON_KNIFE_KARAMBIT = 507,
		WEAPON_KNIFE_M9_BAYONET = 508,
		WEAPON_KNIFE_TACTICAL = 509,
		WEAPON_KNIFE_FALCHION = 512,
		WEAPON_KNIFE_SURVIVAL_BOWIE = 514,
		WEAPON_KNIFE_BUTTERFLY = 515,
		WEAPON_KNIFE_PUSH = 516
	};
	
	enum EClassIds: int
	{
		CAI_BaseNPC = 0,
		CAK47,
		CBaseAnimating,
		CBaseAnimatingOverlay,
		CBaseAttributableItem,
		CBaseButton,
		CBaseCombatCharacter,
		CBaseCombatWeapon,
		CBaseCSGrenade,
		CBaseCSGrenadeProjectile,
		CBaseDoor,
		CBaseEntity,
		CBaseFlex,
		CBaseGrenade,
		CBaseParticleEntity,
		CBasePlayer,
		CBasePropDoor,
		CBaseTeamObjectiveResource,
		CBaseTempEntity,
		CBaseToggle,
		CBaseTrigger,
		CBaseViewModel,
		CBaseVPhysicsTrigger,
		CBaseWeaponWorldModel,
		CBeam,
		CBeamSpotlight,
		CBoneFollower,
		CBreakableProp,
		CBreakableSurface,
		CC4,
		CCascadeLight,
		CChicken,
		CColorCorrection,
		CColorCorrectionVolume,
		CCSGameRulesProxy,
		CCSPlayer,
		CCSPlayerResource,
		CCSRagdoll,
		CCSTeam,
		CDEagle,
		CDecoyGrenade,
		CDecoyProjectile,
		CDynamicLight,
		CDynamicProp,
		CEconEntity,
		CEconWearable,
		CEmbers,
		CEntityDissolve,
		CEntityFlame,
		CEntityFreezing,
		CEntityParticleTrail,
		CEnvAmbientLight,
		CEnvDetailController,
		CEnvDOFController,
		CEnvParticleScript,
		CEnvProjectedTexture,
		CEnvQuadraticBeam,
		CEnvScreenEffect,
		CEnvScreenOverlay,
		CEnvTonemapController,
		CEnvWind,
		CFEPlayerDecal,
		CFireCrackerBlast,
		CFireSmoke,
		CFireTrail,
		CFish,
		CFlashbang,
		CFogController,
		CFootstepControl,
		CFunc_Dust,
		CFunc_LOD,
		CFuncAreaPortalWindow,
		CFuncBrush,
		CFuncConveyor,
		CFuncLadder,
		CFuncMonitor,
		CFuncMoveLinear,
		CFuncOccluder,
		CFuncReflectiveGlass,
		CFuncRotating,
		CFuncSmokeVolume,
		CFuncTrackTrain,
		CGameRulesProxy,
		CHandleTest,
		CHEGrenade,
		CHostage,
		CHostageCarriableProp,
		CIncendiaryGrenade,
		CInferno,
		CInfoLadderDismount,
		CInfoOverlayAccessor,
		CItem_Healthshot,
		CKnife,
		CKnifeGG,
		CLightGlow,
		CMaterialModifyControl,
		CMolotovGrenade,
		CMolotovProjectile,
		CMovieDisplay,
		CParticleFire,
		CParticlePerformanceMonitor,
		CParticleSystem,
		CPhysBox,
		CPhysBoxMultiplayer,
		CPhysicsProp,
		CPhysicsPropMultiplayer,
		CPhysMagnet,
		CPlantedC4,
		CPlasma,
		CPlayerResource,
		CPointCamera,
		CPointCommentaryNode,
		CPoseController,
		CPostProcessController,
		CPrecipitation,
		CPrecipitationBlocker,
		CPredictedViewModel,
		CProp_Hallucination,
		CPropDoorRotating,
		CPropJeep,
		CPropVehicleDriveable,
		CRagdollManager,
		CRagdollProp,
		CRagdollPropAttached,
		CRopeKeyframe,
		CSCAR17,
		CSceneEntity,
		CSensorGrenade,
		CSensorGrenadeProjectile,
		CShadowControl,
		CSlideshowDisplay,
		CSmokeGrenade,
		CSmokeGrenadeProjectile,
		CSmokeStack,
		CSpatialEntity,
		CSpotlightEnd,
		CSprite,
		CSpriteOriented,
		CSpriteTrail,
		CStatueProp,
		CSteamJet,
		CSun,
		CSunlightShadowControl,
		CTeam,
		CTeamplayRoundBasedRulesProxy,
		CTEArmorRicochet,
		CTEBaseBeam,
		CTEBeamEntPoint,
		CTEBeamEnts,
		CTEBeamFollow,
		CTEBeamLaser,
		CTEBeamPoints,
		CTEBeamRing,
		CTEBeamRingPoint,
		CTEBeamSpline,
		CTEBloodSprite,
		CTEBloodStream,
		CTEBreakModel,
		CTEBSPDecal,
		CTEBubbles,
		CTEBubbleTrail,
		CTEClientProjectile,
		CTEDecal,
		CTEDust,
		CTEDynamicLight,
		CTEEffectDispatch,
		CTEEnergySplash,
		CTEExplosion,
		CTEFireBullets,
		CTEFizz,
		CTEFootprintDecal,
		CTEFoundryHelpers,
		CTEGaussExplosion,
		CTEGlowSprite,
		CTEImpact,
		CTEKillPlayerAttachments,
		CTELargeFunnel,
		CTEMetalSparks,
		CTEMuzzleFlash,
		CTEParticleSystem,
		CTEPhysicsProp,
		CTEPlantBomb,
		CTEPlayerAnimEvent,
		CTEPlayerDecal,
		CTEProjectedDecal,
		CTERadioIcon,
		CTEShatterSurface,
		CTEShowLine,
		CTesla,
		CTESmoke,
		CTESparks,
		CTESprite,
		CTESpriteSpray,
		CTest_ProxyToggle_Networkable,
		CTestTraceline,
		CTEWorldDecal,
		CTriggerPlayerMovement,
		CTriggerSoundOperator,
		CVGuiScreen,
		CVoteController,
		CWaterBullet,
		CWaterLODControl,
		CWeaponAug,
		CWeaponAWP,
		CWeaponBaseItem,
		CWeaponBizon,
		CWeaponCSBase,
		CWeaponCSBaseGun,
		CWeaponCycler,
		CWeaponElite,
		CWeaponFamas,
		CWeaponFiveSeven,
		CWeaponG3SG1,
		CWeaponGalil,
		CWeaponGalilAR,
		CWeaponGlock,
		CWeaponHKP2000,
		CWeaponM249,
		CWeaponM3,
		CWeaponM4A1,
		CWeaponMAC10,
		CWeaponMag7,
		CWeaponMP5Navy,
		CWeaponMP7,
		CWeaponMP9,
		CWeaponNegev,
		CWeaponNOVA,
		CWeaponP228,
		CWeaponP250,
		CWeaponP90,
		CWeaponSawedoff,
		CWeaponSCAR20,
		CWeaponScout,
		CWeaponSG550,
		CWeaponSG552,
		CWeaponSG556,
		CWeaponSSG08,
		CWeaponTaser,
		CWeaponTec9,
		CWeaponTMP,
		CWeaponUMP45,
		CWeaponUSP,
		CWeaponXM1014,
		CWorld,
		DustTrail,
		MovieExplosion,
		ParticleSmokeGrenade,
		RocketTrail,
		SmokeTrail,
		SporeExplosion,
		SporeTrail
	};
	
	enum Bone: int
	{
		BONE_PELVIS = 0,
		LEAN_ROOT,
		CAM_DRIVER,
		BONE_HIP,
		BONE_LOWER_SPINAL_COLUMN,
		BONE_MIDDLE_SPINAL_COLUMN,
		BONE_UPPER_SPINAL_COLUMN,
		BONE_NECK,
		BONE_HEAD,
	};
	
	enum Hitbox: int
	{
		HITBOX_HEAD = 0,
		HITBOX_NECK,
		HITBOX_PELVIS,
		HITBOX_SPINE,
		HITBOX_LEGS,
		HITBOX_ARMS,
	};
	
	enum HitGroups: int
	{
		HITGROUP_GENERIC = 0,
		HITGROUP_HEAD,
		HITGROUP_CHEST,
		HITGROUP_STOMACH,
		HITGROUP_LEFTARM,
		HITGROUP_RIGHTARM,
		HITGROUP_LEFTLEG,
		HITGROUP_RIGHTLEG,
		HITGROUP_GEAR
	};
};

// class C_BasePlayer : public C_BaseCombatCharacter, public CGameEventListener
// class C_BaseCombatCharacter : public C_BaseFlex
// class C_BaseFlex : public C_BaseAnimatingOverlay, public IHasLocalToGlobalFlexSettings
// class C_BaseAnimatingOverlay : public C_BaseAnimating
// class C_BaseAnimating : public C_BaseEntity, private IModelLoadCallback

// class CBaseGrenadeProjectile : public CBaseGrenade
// class CBaseGrenade : public CBaseProjectile
