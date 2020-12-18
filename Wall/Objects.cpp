//
//  Objects.cpp
//  Wall
//
//  Created by Fricker95 on 12/18/20.
//  Copyright © 2020 nadp. All rights reserved.
//

#include "Objects.hpp"

bool GlowObjectDefinition_t::isValidGlowEntity()
{
	return m_hEntity != 0x0;
}

bool GlowObjectDefinition_t::isValidGlowEntity(uint64_t ptr)
{
	return m_hEntity != 0x0 && m_hEntity == ptr;
}

void GlowObjectDefinition_t::print()
{
	printf("0x%llx\n", m_hEntity);
	std::cout << m_vGlowColor.r << std::endl;
	std::cout << m_vGlowColor.g << std::endl;
	std::cout << m_vGlowColor.b << std::endl;
	std::cout << m_flGlowAlpha << std::endl;
	std::cout << unk1 << std::endl;
	std::cout << m_bRenderWhenOccluded << std::endl;
	std::cout << m_bRenderWhenUnoccluded << std::endl;
	std::cout << FullBloom << std::endl;
	std::cout << unk2 << std::endl;
}

bool GlowObjectDefinition_t::operator == (const GlowObjectDefinition_t& rhs)
{
	return m_hEntity == rhs.m_hEntity;
}

bool GlowObjectDefinition_t::operator == (const EntityObjectDefinition_t& rhs)
{
	return m_hEntity == rhs.m_hEntity;
}

void EntityObjectDefinition_t::print()
{
	printf("0x%llx\n", m_hEntity);
	std::cout << m_SerialNum << std::endl;
	printf("0x%llx\n", m_pPrevious);
	printf("0x%llx\n", m_pNext);
}

bool EntityObjectDefinition_t::operator == (const EntityObjectDefinition_t& rhs)
{
	return m_hEntity == rhs.m_hEntity;
}

bool EntityObjectDefinition_t::operator == (const GlowObjectDefinition_t& rhs)
{
	return m_hEntity == rhs.m_hEntity;
}
