/**
 * MaNGOS is a full featured server for World of Warcraft, supporting
 * the following clients: 1.12.x, 2.4.3, 3.3.5a, 4.3.4a and 5.4.8
 *
 * Copyright (C) 2005-2014  MaNGOS project <http://getmangos.eu>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * World of Warcraft, and all World of Warcraft or Warcraft art, images,
 * and lore are copyrighted by Blizzard Entertainment, Inc.
 */
 
 #ifndef MANGOS_H_SPELLINFO
 #define MANGOS_H_SPELLINFO
 
 /// Information related to the DBC fields on spells
 
 // only used in code
enum SpellCategories
{
    SPELLCATEGORY_HEALTH_MANA_POTIONS = 4,
    SPELLCATEGORY_DEVOUR_MAGIC        = 12,
    SPELLCATEGORY_JUDGEMENT           = 1210,               // Judgement (seal trigger)
};

/**
 * Spell clasification (Taken from comments)
 * \todo Properly document this
 */
enum SpellSpecific
{
    SPELL_NORMAL            = 0,
    SPELL_SEAL              = 1,
    SPELL_BLESSING          = 2,
    SPELL_AURA              = 3,
    SPELL_STING             = 4,
    SPELL_CURSE             = 5,
    SPELL_ASPECT            = 6,
    SPELL_TRACKER           = 7,
    SPELL_WARLOCK_ARMOR     = 8,
    SPELL_MAGE_ARMOR        = 9,
    SPELL_ELEMENTAL_SHIELD  = 10,
    SPELL_MAGE_POLYMORPH    = 11,
    SPELL_POSITIVE_SHOUT    = 12,
    SPELL_JUDGEMENT         = 13,
    SPELL_BATTLE_ELIXIR     = 14,
    SPELL_GUARDIAN_ELIXIR   = 15,
    SPELL_FLASK_ELIXIR      = 16,
    SPELL_PRESENCE          = 17,
    SPELL_HAND              = 18,
    SPELL_WELL_FED          = 19,
    SPELL_FOOD              = 20,
    SPELL_DRINK             = 21,
    SPELL_FOOD_AND_DRINK    = 22,
    SPELL_UA_IMMOLATE       = 23,                           // Unstable Affliction and Immolate
};
 
 /**
 * Spell proc event related declarations (accessed using SpellMgr functions) (Taken from comments)
 */
enum ProcFlags
{
    PROC_FLAG_NONE                          = 0x00000000,

    PROC_FLAG_KILLED                        = 0x00000001,   ///< (From source) 00 Killed by aggressor
    PROC_FLAG_KILL                          = 0x00000002,   ///< (From source) 01 Kill target (in most cases need XP/Honor reward, see Unit::IsTriggeredAtSpellProcEvent for additinoal check)

    PROC_FLAG_SUCCESSFUL_MELEE_HIT          = 0x00000004,   ///< (From source) 02 Successful melee auto attack
    PROC_FLAG_TAKEN_MELEE_HIT               = 0x00000008,   ///< (From source) 03 Taken damage from melee auto attack hit

    PROC_FLAG_SUCCESSFUL_MELEE_SPELL_HIT    = 0x00000010,   ///< (From source) 04 Successful attack by Spell that use melee weapon
    PROC_FLAG_TAKEN_MELEE_SPELL_HIT         = 0x00000020,   ///< (From source) 05 Taken damage by Spell that use melee weapon

    PROC_FLAG_SUCCESSFUL_RANGED_HIT         = 0x00000040,   ///< (From source) 06 Successful Ranged auto attack
    PROC_FLAG_TAKEN_RANGED_HIT              = 0x00000080,   ///< (From source) 07 Taken damage from ranged auto attack

    PROC_FLAG_SUCCESSFUL_RANGED_SPELL_HIT   = 0x00000100,   ///< (From source) 08 Successful Ranged attack by Spell that use ranged weapon
    PROC_FLAG_TAKEN_RANGED_SPELL_HIT        = 0x00000200,   ///< (From source) 09 Taken damage by Spell that use ranged weapon

    PROC_FLAG_SUCCESSFUL_POSITIVE_AOE_HIT   = 0x00000400,   ///< (From source) 10 Successful AoE (not 100% shure unused)
    PROC_FLAG_TAKEN_POSITIVE_AOE            = 0x00000800,   ///< (From source) 11 Taken AoE      (not 100% shure unused)

    PROC_FLAG_SUCCESSFUL_AOE_SPELL_HIT      = 0x00001000,   ///< (From source) 12 Successful AoE damage spell hit (not 100% shure unused)
    PROC_FLAG_TAKEN_AOE_SPELL_HIT           = 0x00002000,   ///< (From source) 13 Taken AoE damage spell hit      (not 100% shure unused)

    PROC_FLAG_SUCCESSFUL_POSITIVE_SPELL     = 0x00004000,   ///< (From source) 14 Successful cast positive spell (by default only on healing)
    PROC_FLAG_TAKEN_POSITIVE_SPELL          = 0x00008000,   ///< (From source) 15 Taken positive spell hit (by default only on healing)

    PROC_FLAG_SUCCESSFUL_NEGATIVE_SPELL_HIT = 0x00010000,   ///< (From source) 16 Successful negative spell cast (by default only on damage)
    PROC_FLAG_TAKEN_NEGATIVE_SPELL_HIT      = 0x00020000,   ///< (From source) 17 Taken negative spell (by default only on damage)

    PROC_FLAG_ON_DO_PERIODIC                = 0x00040000,   ///< (From source) 18 Successful do periodic (damage / healing, determined by PROC_EX_PERIODIC_POSITIVE or negative if no procEx)
    PROC_FLAG_ON_TAKE_PERIODIC              = 0x00080000,   ///< (From source) 19 Taken spell periodic (damage / healing, determined by PROC_EX_PERIODIC_POSITIVE or negative if no procEx)

    PROC_FLAG_TAKEN_ANY_DAMAGE              = 0x00100000,   ///< (From source) 20 Taken any damage
    PROC_FLAG_ON_TRAP_ACTIVATION            = 0x00200000,   ///< (From source) 21 On trap activation

    PROC_FLAG_TAKEN_OFFHAND_HIT             = 0x00400000,   ///< (From source) 22 Taken off-hand melee attacks(not used)
    PROC_FLAG_SUCCESSFUL_OFFHAND_HIT        = 0x00800000    ///< (From source) 23 Successful off-hand melee attacks
};

/// Proc flags for a melee based trigger
#define MELEE_BASED_TRIGGER_MASK (PROC_FLAG_SUCCESSFUL_MELEE_HIT        | \
                                  PROC_FLAG_TAKEN_MELEE_HIT             | \
                                  PROC_FLAG_SUCCESSFUL_MELEE_SPELL_HIT  | \
                                  PROC_FLAG_TAKEN_MELEE_SPELL_HIT       | \
                                  PROC_FLAG_SUCCESSFUL_RANGED_HIT       | \
                                  PROC_FLAG_TAKEN_RANGED_HIT            | \
                                  PROC_FLAG_SUCCESSFUL_RANGED_SPELL_HIT | \
                                  PROC_FLAG_TAKEN_RANGED_SPELL_HIT)

/**
 * Proc flags mask for a negative trigger
 * \todo What is negative in this case?
 */
#define NEGATIVE_TRIGGER_MASK (MELEE_BASED_TRIGGER_MASK                | \
                               PROC_FLAG_SUCCESSFUL_AOE_SPELL_HIT      | \
                               PROC_FLAG_TAKEN_AOE_SPELL_HIT           | \
                               PROC_FLAG_SUCCESSFUL_NEGATIVE_SPELL_HIT | \
                               PROC_FLAG_TAKEN_NEGATIVE_SPELL_HIT)

#define SPELL_CAST_TRIGGER_MASK (PROC_FLAG_SUCCESSFUL_MELEE_SPELL_HIT    | \
                                 PROC_FLAG_SUCCESSFUL_RANGED_HIT         | \
                                 PROC_FLAG_SUCCESSFUL_RANGED_SPELL_HIT   | \
                                 PROC_FLAG_SUCCESSFUL_POSITIVE_AOE_HIT   | \
                                 PROC_FLAG_SUCCESSFUL_AOE_SPELL_HIT      | \
                                 PROC_FLAG_SUCCESSFUL_POSITIVE_SPELL     | \
                                 PROC_FLAG_SUCCESSFUL_NEGATIVE_SPELL_HIT)
                                 
enum ProcFlagsEx
{
    /// If none can trigger on Hit/Crit only (passive spells MUST defined by SpellFamily flag)
    PROC_EX_NONE                = 0x0000000,
    /// If set only from normal hit (only damage spells)
    PROC_EX_NORMAL_HIT          = 0x0000001,
    PROC_EX_CRITICAL_HIT        = 0x0000002,
    PROC_EX_MISS                = 0x0000004,
    PROC_EX_RESIST              = 0x0000008,
    PROC_EX_DODGE               = 0x0000010,
    PROC_EX_PARRY               = 0x0000020,
    PROC_EX_BLOCK               = 0x0000040,
    PROC_EX_EVADE               = 0x0000080,
    PROC_EX_IMMUNE              = 0x0000100,
    PROC_EX_DEFLECT             = 0x0000200,
    PROC_EX_ABSORB              = 0x0000400,
    PROC_EX_REFLECT             = 0x0000800,
    /// Melee hit result can be Interrupt (not used)
    PROC_EX_INTERRUPT           = 0x0001000,
    PROC_EX_FULL_BLOCK          = 0x0002000,                // block al attack damage
    PROC_EX_RESERVED2           = 0x0004000,
    PROC_EX_RESERVED3           = 0x0008000,
    /// If set trigger always ( no matter another flags) used for drop charges
    PROC_EX_EX_TRIGGER_ALWAYS   = 0x0010000,
    /// If set trigger always but only one time (not used)
    PROC_EX_EX_ONE_TIME_TRIGGER = 0x0020000,
    /// For periodic heal
    PROC_EX_PERIODIC_POSITIVE   = 0x0040000,
    PROC_EX_CAST_END            = 0x0080000                 // procs on end of cast
};

 
 #endif
 