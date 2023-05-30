//====================================================================================================
/**
 *  Copyright (c) 2022 Frostwave.gg
 *
 *  This software is provided 'as-is', without any express or implied warranty.
 *  In no event will the authors be held liable for any damages arising from the use of this software.
 *
 *  Permission is granted, free of charge, to anyone to use this software for non-commercial non-military purposes, and to alter it and redistribute it freely,
 *  subject to the following restrictions:
 *      1. The origin of the software must not be misrepresented; you must not claim that you wrote the original software.
 *      2. The acknowledgement of the use of this software must be present and clearly visible in the product documentation and the product itself.
 *      3. This notice must not be removed from any source distribution.
 *
 *  Permission is denied for any military purpose without explicit cooperation agreement between the third party and Frostwave.gg.
 *  For military use, contact Frostwave.gg.
 *  (Heads up, Frostwave.gg does not support military use of its software, therefore rates may be astronomical)
 *
 *  Permission is denied to anyone to use this software, alter it or redistribute it for commercial, or commercial-related purposes,
 *  without permission of Frostwave.gg or its subsidiaries. This includes any and all products and activity with potential monetary gain,
 *  including but not limited to commercial or advertisement products, products containing advertisement, training software and in-house simulation software.
 *  Requirements for commercial use are following:
 *      1. The origin of the software must not be misrepresented; you must not claim that you wrote the original software.
 *      2. Frostwave.gg is eligible for 7.5% of the first 100,000 USD of the products profit, and 15% of all profit after.
 *      3. This notice must not be removed from any source distribution.
 *      4. A formal business agreement from Frostwave.gg or its subsidiaries must be acquired for any commercial use.
 *      5. The acknowledgement of the use of this software must be present and clearly visible in the product documentation.
 *
 *  Open-source commercial products may be eligible to a reduced owed profit percentage - contact Frostwave.gg for further information.
 *
 */
//====================================================================================================
#include "Class.hpp"
#include "Hypershock/Core/Object/Object.hpp"
//====================================================================================================
namespace Hypershock
{
    //====================================================================================================
    uint32 Class::s_LastAssignedId = 0;
    //====================================================================================================
    /*static*/
    Class* Class::New() noexcept
    {
        Class* newClass = new Class();

        newClass->SetId(++s_LastAssignedId);

        return newClass;
    }
    //====================================================================================================
    bool Class::IsA(const WeakPtr<Class>& other) const noexcept
    {
        if (!other.IsValid())
        {
            return false;
        }

        Class* mutableThis = const_cast<Class*>(this);

        return HasCastFlags(other) || other->HasCastFlags(mutableThis);
    }
    //====================================================================================================
    bool Class::IsA(const WeakPtr<Object>& object) const noexcept
    {
        if (!object.IsValid())
        {
            return false;
        }

        return IsA(object->GetStaticClass());
    }
    //====================================================================================================
    bool Class::HasCastFlags(const WeakPtr<Class>& other) const noexcept
    {
        if (!other.IsValid())
        {
            return false;
        }

        for (uint32 id : m_CastFlags)
        {
            if (other->m_Id == id)
            {
                return true;
            }
        }

        return false;
    }
    //====================================================================================================
    bool Class::HasCastFlags(const WeakPtr<Object>& object) const noexcept
    {
        if (!object.IsValid())
        {
            return false;
        }

        return HasCastFlags(object->GetStaticClass());
    }
    //====================================================================================================
}
//====================================================================================================