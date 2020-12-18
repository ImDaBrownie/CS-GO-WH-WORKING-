//
//  Objects.hpp
//  Wall
//
//  Created by Nicolas Fricker on 12/18/20.
//  Copyright © 2020 nadp. All rights reserved.
//

#ifndef Objects_hpp
#define Objects_hpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct EntityObjectDefinition_t;
struct GlowObjectDefinition_t;

struct GlowObjectDefinition_t {
public:
	struct Vector {
		float r;
		float g;
		float b;
	};
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
	void print();
	
	bool operator == (const GlowObjectDefinition_t& rhs);
	bool operator == (const EntityObjectDefinition_t& rhs);
};

struct EntityObjectDefinition_t {
public:
	uint64_t m_hEntity;
	char m_SerialNum[0x8];
	uint64_t m_pPrevious;
	uint64_t m_pNext;
	
	void print();
	
	bool operator == (const EntityObjectDefinition_t& rhs);
	bool operator == (const GlowObjectDefinition_t& rhs);
};

struct PlayerEntityList {
public:
	EntityObjectDefinition_t array[0x40];
};

#endif /* Objects_hpp */
