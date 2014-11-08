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
 
enum SpellCastTargetFlags
{
    CAST_FLAG_NONE               = 0x00000000,
    CAST_FLAG_PENDING            = 0x00000001,              // aoe combat log?
    CAST_FLAG_UNKNOWN_2          = 0x00000002,
    CAST_FLAG_UNKNOWN_3          = 0x00000004,
    CAST_FLAG_UNKNOWN_4          = 0x00000008,              // ignore AOE visual
    CAST_FLAG_UNKNOWN_5          = 0x00000010,
    CAST_FLAG_SOURCE_LOCATION    = 0x00000020,              
    CAST_FLAG_DEST_LOCATION      = 0x00000040,
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

enum SpellEffectHandleMode
{
    SPELL_EFFECT_HANDLE_LAUNCH,
    SPELL_EFFECT_HANDLE_LAUNCH_TARGET,
    SPELL_EFFECT_HANDLE_HIT,
    SPELL_EFFECT_HANDLE_HIT_TARGET
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

enum TriggerCastFlags
{
    TRIGGERED_NONE                                  = 0x00000000,   //! Not triggered
    TRIGGERED_IGNORE_GCD                            = 0x00000001,   //! Will ignore GCD
    TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD          = 0x00000002,   //! Will ignore Spell and Category cooldowns
    TRIGGERED_IGNORE_POWER_AND_REAGENT_COST         = 0x00000004,   //! Will ignore power and reagent cost
    TRIGGERED_IGNORE_CAST_ITEM                      = 0x00000008,   //! Will not take away cast item or update related achievement criteria
    TRIGGERED_IGNORE_AURA_SCALING                   = 0x00000010,   //! Will ignore aura scaling
    TRIGGERED_IGNORE_CAST_IN_PROGRESS               = 0x00000020,   //! Will not check if a current cast is in progress
    TRIGGERED_IGNORE_COMBO_POINTS                   = 0x00000040,   //! Will ignore combo point requirement
    TRIGGERED_CAST_DIRECTLY                         = 0x00000080,   //! In Spell::prepare, will be cast directly without setting containers for executed spell
    TRIGGERED_IGNORE_AURA_INTERRUPT_FLAGS           = 0x00000100,   //! Will ignore interruptible aura's at cast
    TRIGGERED_IGNORE_SET_FACING                     = 0x00000200,   //! Will not adjust facing to target (if any)
    TRIGGERED_IGNORE_SHAPESHIFT                     = 0x00000400,   //! Will ignore shapeshift checks
    TRIGGERED_IGNORE_CASTER_AURASTATE               = 0x00000800,   //! Will ignore caster aura states including combat requirements and death state
    TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE   = 0x00002000,   //! Will ignore mounted/on vehicle restrictions
    TRIGGERED_IGNORE_CASTER_AURAS                   = 0x00010000,   //! Will ignore caster aura restrictions or requirements
    TRIGGERED_DISALLOW_PROC_EVENTS                  = 0x00020000,   //! Disallows proc events from triggered spell (default)
    TRIGGERED_DONT_REPORT_CAST_ERROR                = 0x00040000,   //! Will return SPELL_FAILED_DONT_REPORT in CheckCast functions
    TRIGGERED_IGNORE_EQUIPPED_ITEM_REQUIREMENT      = 0x00080000,   //! Will ignore equipped item requirements
    TRIGGERED_FULL_MASK                             = 0xFFFFFFFF
};

enum SpellTargetSelectionCategories
{
    TARGET_SELECT_CATEGORY_NYI,
    TARGET_SELECT_CATEGORY_DEFAULT,
    TARGET_SELECT_CATEGORY_CHANNEL,
    TARGET_SELECT_CATEGORY_NEARBY,
    TARGET_SELECT_CATEGORY_CONE,
    TARGET_SELECT_CATEGORY_AREA
};

enum SpellTargetReferenceTypes
{
    TARGET_REFERENCE_TYPE_NONE,
    TARGET_REFERENCE_TYPE_CASTER,
    TARGET_REFERENCE_TYPE_TARGET,
    TARGET_REFERENCE_TYPE_LAST,
    TARGET_REFERENCE_TYPE_SRC,
    TARGET_REFERENCE_TYPE_DEST
};

enum SpellTargetObjectTypes
{
    TARGET_OBJECT_TYPE_NONE = 0,
    TARGET_OBJECT_TYPE_SRC,
    TARGET_OBJECT_TYPE_DEST,
    TARGET_OBJECT_TYPE_UNIT,
    TARGET_OBJECT_TYPE_UNIT_AND_DEST,
    TARGET_OBJECT_TYPE_GOBJ,
    TARGET_OBJECT_TYPE_GOBJ_ITEM,
    TARGET_OBJECT_TYPE_ITEM,
    TARGET_OBJECT_TYPE_CORPSE,
    // only for effect target type
    TARGET_OBJECT_TYPE_CORPSE_ENEMY,
    TARGET_OBJECT_TYPE_CORPSE_ALLY
};

enum SpellTargetCheckTypes
{
    TARGET_CHECK_DEFAULT,
    TARGET_CHECK_ENTRY,
    TARGET_CHECK_ENEMY,
    TARGET_CHECK_ALLY,
    TARGET_CHECK_PARTY,
    TARGET_CHECK_RAID,
    TARGET_CHECK_RAID_CLASS,
    TARGET_CHECK_PASSENGER
};

enum SpellTargetDirectionTypes
{
    TARGET_DIR_NONE,
    TARGET_DIR_FRONT,
    TARGET_DIR_BACK,
    TARGET_DIR_RIGHT,
    TARGET_DIR_LEFT,
    TARGET_DIR_FRONT_RIGHT,
    TARGET_DIR_BACK_RIGHT,
    TARGET_DIR_BACK_LEFT,
    TARGET_DIR_FRONT_LEFT,
    TARGET_DIR_RANDOM,
    TARGET_DIR_ENTRY
};

// total spell targets = TARGET_TOTAL

#define AURA_SPELL_PROC_EX_MASK \
    (PROC_EX_NORMAL_HIT | PROC_EX_CRITICAL_HIT | PROC_EX_MISS | \
     PROC_EX_RESIST | PROC_EX_DODGE | PROC_EX_PARRY | PROC_EX_BLOCK | \
     PROC_EX_EVADE | PROC_EX_IMMUNE | PROC_EX_DEFLECT | \
     PROC_EX_ABSORB | PROC_EX_REFLECT | PROC_EX_INTERRUPT)
 
#define SPELL_CHANNEL_UPDATE_INTERVAL (1 * IN_MILLISECONDS)

#define MAPID_INVALID 0xFFFFFFFF
 
#endif
 