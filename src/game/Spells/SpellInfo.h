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

/// Information related to the DBC fields on spells and other misc. properties of spells
 
enum SpellCastFlags
{
    CAST_FLAG_NONE               = 0x00000000,
    CAST_FLAG_PENDING            = 0x00000001,              // aoe combat log?
    CAST_FLAG_UNKNOWN_2          = 0x00000002,
    CAST_FLAG_UNKNOWN_3          = 0x00000004,
    CAST_FLAG_UNKNOWN_4          = 0x00000008,              // ignore AOE visual
    CAST_FLAG_UNKNOWN_5          = 0x00000010,
    CAST_FLAG_AMMO               = 0x00000020,              // Projectiles visual
    CAST_FLAG_UNKNOWN_7          = 0x00000040,
    CAST_FLAG_UNKNOWN_8          = 0x00000080,
    CAST_FLAG_UNKNOWN_9          = 0x00000100,
    CAST_FLAG_UNKNOWN_10         = 0x00000200,
    CAST_FLAG_UNKNOWN_11         = 0x00000400,
    CAST_FLAG_POWER_LEFT_SELF    = 0x00000800,
    CAST_FLAG_UNKNOWN_13         = 0x00001000,
    CAST_FLAG_UNKNOWN_14         = 0x00002000,
    CAST_FLAG_UNKNOWN_15         = 0x00004000,
    CAST_FLAG_UNKNOWN_16         = 0x00008000,
    CAST_FLAG_UNKNOWN_17         = 0x00010000,
    CAST_FLAG_ADJUST_MISSILE     = 0x00020000,
    CAST_FLAG_NO_GCD             = 0x00040000,              // no GCD for spell casts from charm/summon (vehicle spells is an example)
    CAST_FLAG_VISUAL_CHAIN       = 0x00080000,
    CAST_FLAG_UNKNOWN_21         = 0x00100000,
    CAST_FLAG_RUNE_LIST          = 0x00200000,
    CAST_FLAG_UNKNOWN_23         = 0x00400000,
    CAST_FLAG_UNKNOWN_24         = 0x00800000,
    CAST_FLAG_UNKNOWN_25         = 0x01000000,
    CAST_FLAG_UNKNOWN_26         = 0x02000000,
    CAST_FLAG_IMMUNITY           = 0x04000000,
    CAST_FLAG_UNKNOWN_28         = 0x08000000,
    CAST_FLAG_UNKNOWN_29         = 0x10000000,
    CAST_FLAG_UNKNOWN_30         = 0x20000000,
    CAST_FLAG_UNKNOWN_31         = 0x40000000,
    CAST_FLAG_UNKNOWN_32         = 0x80000000
};

enum SpellFlags
{
    SPELL_FLAG_NORMAL       = 0x00,
    SPELL_FLAG_REFLECTED    = 0x01,     // reflected spell
    SPELL_FLAG_REDIRECTED   = 0x02      // redirected spell
};

enum SpellRangeFlag
{
    SPELL_RANGE_DEFAULT             = 0,
    SPELL_RANGE_MELEE               = 1,     //melee
    SPELL_RANGE_RANGED              = 2      //hunter range and ranged weapon
};

enum SpellNotifyPushType
{
    PUSH_IN_FRONT,
    PUSH_IN_FRONT_90,
    PUSH_IN_FRONT_30,
    PUSH_IN_FRONT_15,
    PUSH_IN_BACK,
    PUSH_SELF_CENTER,
    PUSH_DEST_CENTER,
    PUSH_TARGET_CENTER
};

enum SpellState
{
    SPELL_STATE_NULL      = 0,
    SPELL_STATE_PREPARING = 1,
    SPELL_STATE_CASTING   = 2,
    SPELL_STATE_FINISHED  = 3,
    SPELL_STATE_IDLE      = 4,
    SPELL_STATE_DELAYED   = 5
};

enum SpellTargets
{
    SPELL_TARGETS_HOSTILE,
    SPELL_TARGETS_NOT_FRIENDLY,
    SPELL_TARGETS_NOT_HOSTILE,
    SPELL_TARGETS_FRIENDLY,
    SPELL_TARGETS_AOE_DAMAGE,
    SPELL_TARGETS_ALL
};
 
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
    PROC_FLAG_NONE                             = 0x00000000,

    PROC_FLAG_KILLED                           = 0x00000001,   ///< (From source) 00 Killed by aggressor
    PROC_FLAG_KILL                             = 0x00000002,   ///< (From source) 01 Kill target (in most cases need XP/Honor reward, see Unit::IsTriggeredAtSpellProcEvent for additinoal check)

    PROC_FLAG_SUCCESSFUL_MELEE_HIT             = 0x00000004,   ///< (From source) 02 Successful melee auto attack
    PROC_FLAG_TAKEN_MELEE_HIT                  = 0x00000008,   ///< (From source) 03 Taken damage from melee auto attack hit

    PROC_FLAG_SUCCESSFUL_MELEE_SPELL_HIT       = 0x00000010,   ///< (From source) 04 Successful attack by Spell that use melee weapon
    PROC_FLAG_TAKEN_MELEE_SPELL_HIT            = 0x00000020,   ///< (From source) 05 Taken damage by Spell that use melee weapon

    PROC_FLAG_SUCCESSFUL_RANGED_HIT            = 0x00000040,   ///< (From source) 06 Successful Ranged auto attack
    PROC_FLAG_TAKEN_RANGED_HIT                 = 0x00000080,   ///< (From source) 07 Taken damage from ranged auto attack

    PROC_FLAG_SUCCESSFUL_RANGED_SPELL_HIT      = 0x00000100,   ///< (From source) 08 Successful Ranged attack by Spell that use ranged weapon
    PROC_FLAG_TAKEN_RANGED_SPELL_HIT           = 0x00000200,   ///< (From source) 09 Taken damage by Spell that use ranged weapon

    PROC_FLAG_DONE_POS_SPELL_NO_DMG_CLASS      = 0x00000400,   ///< (From source) 10 Successful positive spell that has no damage class
    PROC_FLAG_TAKEN_POS_SPELL_NO_DMG_CLASS     = 0x00000800,   ///< (From source) 11 Taken positive spell with no damage class

    PROC_FLAG_DONE_NEG_SPELL_NO_DMG_CLASS      = 0x00001000,   ///< (From source) 12 Successful negative spell that has no damage class
    PROC_FLAG_TAKEN_NEG_SPELL_NO_DMG_CLASS     = 0x00002000,   ///< (From source) 13 Taken negative spell with no damage class

    PROC_FLAG_DONE_POS_SPELL_MAGIC_DMG_CLASS   = 0x00004000,   ///< (From source) 14 Successful cast positive spell of magic class
    PROC_FLAG_TAKEN_POS_SPELL_MAGIC_DMG_CLASS  = 0x00008000,   ///< (From source) 15 Taken positive spell of magic class

    PROC_FLAG_DONE_NEG_SPELL_MAGIC_DMG_CLASS   = 0x00010000,   ///< (From source) 16 Successful negative spell cast of magic class
    PROC_FLAG_TAKEN_NEG_SPELL_MAGIC_DMG_CLASS  = 0x00020000,   ///< (From source) 17 Taken negative spell of magic class

    PROC_FLAG_ON_DO_PERIODIC                   = 0x00040000,   ///< (From source) 18 Successful do periodic (damage / healing, determined by PROC_EX_PERIODIC_POSITIVE or negative if no procEx)
    PROC_FLAG_ON_TAKE_PERIODIC                 = 0x00080000,   ///< (From source) 19 Taken spell periodic (damage / healing, determined by PROC_EX_PERIODIC_POSITIVE or negative if no procEx)

    PROC_FLAG_TAKEN_ANY_DAMAGE                 = 0x00100000,   ///< (From source) 20 Taken any damage
    PROC_FLAG_ON_TRAP_ACTIVATION               = 0x00200000,   ///< (From source) 21 On trap activation

    PROC_FLAG_SUCCESSFUL_MAINHAND_HIT          = 0x00400000,   ///< (From source) 22 Done main-hand melee attacks (spell and autoattack)
    PROC_FLAG_SUCCESSFUL_OFFHAND_HIT           = 0x00800000,   ///< (From source) 23 Done off-hand melee attacks (spell and autoattack)
    
    PROC_FLAG_DEATH                            = 0x01000000,   /// 24 Died in any way
    
    // Flag Masks
    AUTO_ATTACK_PROC_FLAG_MASK                 = PROC_FLAG_SUCCESSFUL_MELEE_HIT | PROC_FLAG_TAKEN_MELEE_HIT
                                                 | PROC_FLAG_SUCCESSFUL_RANGED_HIT | PROC_FLAG_TAKEN_RANGED_HIT,
                                              
    MELEE_PROC_FLAG_MASK                       = PROC_FLAG_SUCCESSFUL_MELEE_HIT | PROC_FLAG_TAKEN_MELEE_HIT
                                                 | PROC_FLAG_SUCCESSFUL_MELEE_SPELL_HIT | PROC_FLAG_TAKEN_MELEE_SPELL_HIT
                                                 | PROC_FLAG_SUCCESSFUL_MAINHAND_HIT | PROC_FLAG_SUCCESSFUL_OFFHAND_HIT,
                                                 
    RANGED_PROC_FLAG_MASK                      = PROC_FLAG_SUCCESSFUL_RANGED_HIT | PROC_FLAG_TAKEN_RANGED_HIT
                                                 | PROC_FLAG_SUCCESSFUL_RANGED_SPELL_HIT | PROC_FLAG_TAKEN_RANGED_SPELL_HIT,
                                              
    SPELL_PROC_FLAG_MASK                       = PROC_FLAG_SUCCESSFUL_MELEE_SPELL_HIT | PROC_FLAG_TAKEN_MELEE_SPELL_HIT
                                                 | PROC_FLAG_SUCCESSFUL_RANGED_SPELL_HIT | PROC_FLAG_TAKEN_RANGED_SPELL_HIT
                                                 | PROC_FLAG_DONE_POS_SPELL_NO_DMG_CLASS | PROC_FLAG_TAKEN_POS_SPELL_NO_DMG_CLASS
                                                 | PROC_FLAG_DONE_NEG_SPELL_NO_DMG_CLASS | PROC_FLAG_TAKEN_NEG_SPELL_NO_DMG_CLASS
                                                 | PROC_FLAG_DONE_POS_SPELL_MAGIC_DMG_CLASS | PROC_FLAG_TAKEN_POS_SPELL_MAGIC_DMG_CLASS
                                                 | PROC_FLAG_DONE_NEG_SPELL_MAGIC_DMG_CLASS | PROC_FLAG_TAKEN_NEG_SPELL_MAGIC_DMG_CLASS,
                                                 
    SPELL_CAST_PROC_FLAG_MASK                  = SPELL_PROC_FLAG_MASK | PROC_FLAG_ON_TRAP_ACTIVATION | RANGED_PROC_FLAG_MASK,
    
    PERIODIC_PROC_FLAG_MASK                    = PROC_FLAG_ON_DO_PERIODIC | PROC_FLAG_ON_TAKE_PERIODIC,
    
    DONE_HIT_PROC_FLAG_MASK                    = PROC_FLAG_SUCCESSFUL_MELEE_HIT | PROC_FLAG_SUCCESSFUL_RANGED_HIT
                                                 | PROC_FLAG_SUCCESSFUL_MELEE_SPELL_HIT | PROC_FLAG_SUCCESSFUL_RANGED_SPELL_HIT
                                                 | PROC_FLAG_DONE_POS_SPELL_NO_DMG_CLASS | PROC_FLAG_DONE_NEG_SPELL_NO_DMG_CLASS
                                                 | PROC_FLAG_DONE_POS_SPELL_MAGIC_DMG_CLASS | PROC_FLAG_DONE_NEG_SPELL_MAGIC_DMG_CLASS
                                                 | PROC_FLAG_ON_DO_PERIODIC | PROC_FLAG_SUCCESSFUL_MAINHAND_HIT | PROC_FLAG_SUCCESSFUL_OFFHAND_HIT,
                                                 
    TAKEN_HIT_PROC_FLAG_MASK                   = PROC_FLAG_TAKEN_MELEE_HIT | PROC_FLAG_SUCCESSFUL_RANGED_HIT
                                                 | PROC_FLAG_TAKEN_MELEE_SPELL_HIT | PROC_FLAG_TAKEN_RANGED_SPELL_HIT
                                                 | PROC_FLAG_TAKEN_POS_SPELL_NO_DMG_CLASS | PROC_FLAG_TAKEN_NEG_SPELL_NO_DMG_CLASS
                                                 | PROC_FLAG_TAKEN_POS_SPELL_MAGIC_DMG_CLASS | PROC_FLAG_TAKEN_NEG_SPELL_MAGIC_DMG_CLASS
                                                 | PROC_FLAG_ON_TAKE_PERIODIC | PROC_FLAG_TAKEN_ANY_DAMAGE,
                                                 
    REQ_SPELL_PHASE_PROC_FLAG_MASK             = SPELL_PROC_FLAG_MASK & DONE_HIT_PROC_FLAG_MASK
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

#define AURA_SPELL_PROC_EX_MASK \
    (PROC_EX_NORMAL_HIT | PROC_EX_CRITICAL_HIT | PROC_EX_MISS | \
     PROC_EX_RESIST | PROC_EX_DODGE | PROC_EX_PARRY | PROC_EX_BLOCK | \
     PROC_EX_EVADE | PROC_EX_IMMUNE | PROC_EX_DEFLECT | \
     PROC_EX_ABSORB | PROC_EX_REFLECT | PROC_EX_INTERRUPT)
 
 
 
#endif
 