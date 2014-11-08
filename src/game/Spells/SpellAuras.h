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

#ifndef MANGOS_SPELLAURAS_H
#define MANGOS_SPELLAURAS_H

#include "SpellAuraInfo.h"
#include "SpellEntryInfo.h"
#include "SpellInfo.h"
#include "DBCEnums.h"
#include "ObjectGuid.h"
#include "Unit.h"

class Aura;
class AuraEffect;
class Unit;
class SpellInfo;
struct SpellEntry;
struct ProcTriggerSpell;

// update aura target map every 500 ms instead of every update - reduce amount of grid searcher calls
#define UPDATE_TARGET_MAP_INTERVAL 500

class AuraApplication
{
    friend void Unit::_ApplyAura(AuraApplication * aurApp, uint8 effMask);
    friend void Unit::_UnapplyAura(AuraApplicationMap::iterator &i, AuraRemoveMode removeMode);
    friend void Unit::_ApplyAuraEffect(Aura* aura, uint8 effIndex);
    friend void Unit::RemoveAura(AuraApplication * aurApp, AuraRemoveMode mode);
    friend AuraApplication * Unit::_CreateAuraApplication(Aura* aura, uint8 effMask);
    
    private:
        Unit* const m_target;
        Aura* const m_base;
        AuraRemoveMode m_removeMode:8;       // Store info for remove aura reason
        uint8 m_slot;                        // Aura slot on unit
        uint8 m_flags;                       // Aura info flag
        uint8 m_effectsToApply;              // Used only at spell hit to determine which effect should be applied
        bool m_needClientUpdate:1;
        
        explicit AuraApplication(Unit* target, Unit* caster, Aura* base, uint8 effMask);
        void _Remove();
        void _InitFlags(Unit* caster, uint8 effMask);
        void _HandleEffect(uint8 effIndex, bool apply);
        
    public:
        Unit* GetTarget() const { return m_target; }
        Aura* GetBase() const { return m_base; }
        
        uint8 GetSlot() const { return m_slot; }
        uint8 GetFlags() const { return m_flags; }
        uint8 GetEffectMask() const { return m_flags & (AFLAG_EFF_INDEX_0 | AFLAG_EFF_INDEX_1 | AFLAG_EFF_INDEX_2); }
        bool HasEffect(uint8 effect) const { MANGOS_ASSERT(effect < TOTAL_SPELL_EFFECTS); return (m_flags & (1 << effect)) != 0; }
        bool IsPositive() const { return (m_flags & AFLAG_POSITIVE) != 0; }
        bool IsSelfcast() const { return (m_flags & AFLAG_CASTER) != 0; }
        uint8 GetEffectsToApply() const { return m_effectsToApply; }
        
        void SetRemoveMode(AuraRemoveMode mode) { m_removeMode = mode; }
        AuraRemoveMode GetRemoveMode() const { return m_removeMode; }
        
        void SetNeedClientUpdate() { m_needClientUpdate = true; }
        bool IsNeedClientUpdate() const { return m_needClientUpdate; }
        void BuildUpdatePacket(ByteBuffer& data, bool remove) const;
        void ClientUpdate(bool remove = false);
};

class Aura
{
        friend Aura* Unit::_TryStackingOrRefreshingExistingAura(SpellInfo const* newAura, uint8 effMask, Unit* caster, int32 *baseAmount, Item* castItem, ObjectGuid casterGUID);
    public:
        typedef std::map<ObjectGuid, AuraApplication*> ApplicationMap;
        
        static uint8 BuildEffectMaskForOwner(SpellInfo const* spellProto, uint8 avalibleEffectMask, WorldObject* owner);
        static Aura* TryRefreshStackOrCreate(SpellInfo const* spellproto, uint8 tryEffMask, WorldObject* owner, Unit* caster, int32* baseAmount = NULL, Item* castItem = NULL, ObjectGuid casterGUID = ObjectGuid(), bool* refresh = NULL);
        static Aura* TryCreate(SpellInfo const* spellproto, uint8 effMask, WorldObject* owner, Unit* caster, int32 *baseAmount = NULL, Item* castItem = NULL, ObjectGuid casterGUID = ObjectGuid::Empty);
        static Aura* Create(SpellInfo const* spellproto, uint8 effMask, WorldObject* owner, Unit* caster, int32* baseAmount, Item* castItem, ObjectGuid casterGUID);
        explicit Aura(SpellInfo const* spellproto, WorldObject* owner, Unit* caster, Item* castItem, ObjectGuid casterGUID);
        void _InitEffects(uint8 effMask, Unit* caster, int32 *baseAmount);
        virtual ~Aura();
        
        // left off here
        
        // aura handlers
        void HandleNULL(bool, bool)
        {
            // NOT IMPLEMENTED
        }
        void HandleUnused(bool, bool)
        {
            // NOT USED BY ANY SPELL OR USELESS
        }
        void HandleNoImmediateEffect(bool, bool)
        {
            // aura not have immediate effect at add/remove and handled by ID in other code place
        }
        void HandleBindSight(bool Apply, bool Real);
        void HandleModPossess(bool Apply, bool Real);
        void HandlePeriodicDamage(bool Apply, bool Real);
        void HandleAuraDummy(bool Apply, bool Real);
        void HandleAuraPeriodicDummy(bool apply, bool Real);
        void HandleModConfuse(bool Apply, bool Real);
        void HandleModCharm(bool Apply, bool Real);
        void HandleModFear(bool Apply, bool Real);
        void HandlePeriodicHeal(bool Apply, bool Real);
        void HandleModAttackSpeed(bool Apply, bool Real);
        void HandleModMeleeRangedSpeedPct(bool apply, bool Real);
        void HandleModCombatSpeedPct(bool apply, bool Real);
        void HandleModThreat(bool Apply, bool Real);
        void HandleModTaunt(bool Apply, bool Real);
        void HandleFeignDeath(bool Apply, bool Real);
        void HandleAuraModDisarm(bool Apply, bool Real);
        void HandleAuraModStalked(bool Apply, bool Real);
        void HandleAuraWaterWalk(bool Apply, bool Real);
        void HandleAuraFeatherFall(bool Apply, bool Real);
        void HandleAuraHover(bool Apply, bool Real);
        void HandleAddModifier(bool Apply, bool Real);
        void HandleAuraModStun(bool Apply, bool Real);
        void HandleModDamageDone(bool Apply, bool Real);
        void HandleAuraUntrackable(bool Apply, bool Real);
        void HandleAuraEmpathy(bool Apply, bool Real);
        void HandleModOffhandDamagePercent(bool apply, bool Real);
        void HandleAuraModRangedAttackPower(bool Apply, bool Real);
        void HandleAuraModIncreaseEnergyPercent(bool Apply, bool Real);
        void HandleAuraModIncreaseHealthPercent(bool Apply, bool Real);
        void HandleAuraModRegenInterrupt(bool Apply, bool Real);
        void HandleModMeleeSpeedPct(bool Apply, bool Real);
        void HandlePeriodicTriggerSpell(bool Apply, bool Real);
        void HandlePeriodicTriggerSpellWithValue(bool apply, bool Real);
        void HandlePeriodicEnergize(bool Apply, bool Real);
        void HandleAuraModResistanceExclusive(bool Apply, bool Real);
        void HandleAuraSafeFall(bool Apply, bool Real);
        void HandleAuraModPetTalentsPoints(bool Apply, bool Real);
        void HandleModStealth(bool Apply, bool Real);
        void HandleInvisibility(bool Apply, bool Real);
        void HandleInvisibilityDetect(bool Apply, bool Real);
        void HandleAuraModTotalHealthPercentRegen(bool Apply, bool Real);
        void HandleAuraModTotalManaPercentRegen(bool Apply, bool Real);
        void HandleAuraModResistance(bool Apply, bool Real);
        void HandleAuraModRoot(bool Apply, bool Real);
        void HandleAuraModSilence(bool Apply, bool Real);
        void HandleAuraModStat(bool Apply, bool Real);
        void HandleDetectAmore(bool Apply, bool Real);
        void HandleAuraFakeInebriation(bool Apply, bool Real);
        void HandleAuraModIncreaseSpeed(bool Apply, bool Real);
        void HandleAuraModIncreaseMountedSpeed(bool Apply, bool Real);
        void HandleAuraModIncreaseFlightSpeed(bool Apply, bool Real);
        void HandleAuraModDecreaseSpeed(bool Apply, bool Real);
        void HandleAuraModUseNormalSpeed(bool Apply, bool Real);
        void HandleAuraModIncreaseHealth(bool Apply, bool Real);
        void HandleAuraModIncreaseEnergy(bool Apply, bool Real);
        void HandleAuraModShapeshift(bool Apply, bool Real);
        void HandleAuraModEffectImmunity(bool Apply, bool Real);
        void HandleAuraModStateImmunity(bool Apply, bool Real);
        void HandleAuraModSchoolImmunity(bool Apply, bool Real);
        void HandleAuraModDmgImmunity(bool Apply, bool Real);
        void HandleAuraModDispelImmunity(bool Apply, bool Real);
        void HandleAuraProcTriggerSpell(bool Apply, bool Real);
        void HandleAuraTrackCreatures(bool Apply, bool Real);
        void HandleAuraTrackResources(bool Apply, bool Real);
        void HandleAuraModParryPercent(bool Apply, bool Real);
        void HandleAuraModDodgePercent(bool Apply, bool Real);
        void HandleAuraModBlockPercent(bool Apply, bool Real);
        void HandleAuraModCritPercent(bool Apply, bool Real);
        void HandlePeriodicLeech(bool Apply, bool Real);
        void HandleModHitChance(bool Apply, bool Real);
        void HandleModSpellHitChance(bool Apply, bool Real);
        void HandleAuraModScale(bool Apply, bool Real);
        void HandlePeriodicManaLeech(bool Apply, bool Real);
        void HandlePeriodicHealthFunnel(bool apply, bool Real);
        void HandleModCastingSpeed(bool Apply, bool Real);
        void HandleAuraMounted(bool Apply, bool Real);
        void HandleWaterBreathing(bool Apply, bool Real);
        void HandleModBaseResistance(bool Apply, bool Real);
        void HandleModRegen(bool Apply, bool Real);
        void HandleModPowerRegen(bool Apply, bool Real);
        void HandleModPowerRegenPCT(bool Apply, bool Real);
        void HandleChannelDeathItem(bool Apply, bool Real);
        void HandleDamagePercentTaken(bool Apply, bool Real);
        void HandlePeriodicDamagePCT(bool Apply, bool Real);
        void HandleAuraModAttackPower(bool Apply, bool Real);
        void HandleAuraTransform(bool Apply, bool Real);
        void HandleModSpellCritChance(bool Apply, bool Real);
        void HandleAuraModIncreaseSwimSpeed(bool Apply, bool Real);
        void HandleModPowerCostPCT(bool Apply, bool Real);
        void HandleModPowerCost(bool Apply, bool Real);
        void HandleFarSight(bool Apply, bool Real);
        void HandleModPossessPet(bool Apply, bool Real);
        void HandleModMechanicImmunity(bool Apply, bool Real);
        void HandleModMechanicImmunityMask(bool Apply, bool Real);
        void HandleAuraModSkill(bool Apply, bool Real);
        void HandleModDamagePercentDone(bool Apply, bool Real);
        void HandleModPercentStat(bool Apply, bool Real);
        void HandleModResistancePercent(bool Apply, bool Real);
        void HandleAuraModBaseResistancePCT(bool Apply, bool Real);
        void HandleModShieldBlockPCT(bool Apply, bool Real);
        void HandleAuraTrackStealthed(bool Apply, bool Real);
        void HandleModShieldBlock(bool Apply, bool Real);
        void HandleForceReaction(bool Apply, bool Real);
        void HandleAuraModRangedHaste(bool Apply, bool Real);
        void HandleRangedAmmoHaste(bool Apply, bool Real);
        void HandleModHealingDone(bool Apply, bool Real);
        void HandleModTotalPercentStat(bool Apply, bool Real);
        void HandleAuraModTotalThreat(bool Apply, bool Real);
        void HandleModUnattackable(bool Apply, bool Real);
        void HandleAuraModPacify(bool Apply, bool Real);
        void HandleAuraGhost(bool Apply, bool Real);
        void HandleAuraAllowFlight(bool Apply, bool Real);
        void HandleModRating(bool apply, bool Real);
        void HandleModRatingFromStat(bool apply, bool Real);
        void HandleModTargetResistance(bool apply, bool Real);
        void HandleAuraModAttackPowerPercent(bool apply, bool Real);
        void HandleAuraModRangedAttackPowerPercent(bool apply, bool Real);
        void HandleAuraModRangedAttackPowerOfStatPercent(bool apply, bool Real);
        void HandleAuraModAttackPowerOfStatPercent(bool apply, bool Real);
        void HandleAuraModAttackPowerOfArmor(bool apply, bool Real);
        void HandleSpiritOfRedemption(bool apply, bool Real);
        void HandleModManaRegen(bool apply, bool Real);
        void HandleComprehendLanguage(bool apply, bool Real);
        void HandleShieldBlockValue(bool apply, bool Real);
        void HandleModSpellCritChanceShool(bool apply, bool Real);
        void HandleAuraRetainComboPoints(bool apply, bool Real);
        void HandleModSpellDamagePercentFromStat(bool apply, bool Real);
        void HandleModSpellHealingPercentFromStat(bool apply, bool Real);
        void HandleAuraModDispelResist(bool apply, bool Real);
        void HandleAuraControlVehicle(bool apply, bool Real);
        void HandleModSpellDamagePercentFromAttackPower(bool apply, bool Real);
        void HandleModSpellHealingPercentFromAttackPower(bool apply, bool Real);
        void HandleAuraModPacifyAndSilence(bool Apply, bool Real);
        void HandleAuraModIncreaseMaxHealth(bool apply, bool Real);
        void HandleAuraModExpertise(bool apply, bool Real);
        void HandleForceMoveForward(bool apply, bool Real);
        void HandleAuraModResistenceOfStatPercent(bool apply, bool Real);
        void HandleAuraPowerBurn(bool apply, bool Real);
        void HandleSchoolAbsorb(bool apply, bool Real);
        void HandlePreventFleeing(bool apply, bool Real);
        void HandleManaShield(bool apply, bool Real);
        void HandleArenaPreparation(bool apply, bool Real);
        void HandleAuraMirrorImage(bool apply, bool Real);
        void HandleAuraConvertRune(bool apply, bool Real);
        void HandleAuraIncreaseBaseHealthPercent(bool Apply, bool Real);
        void HandleNoReagentUseAura(bool Apply, bool Real);
        void HandlePhase(bool Apply, bool Real);
        void HandleModTargetArmorPct(bool Apply, bool Real);
        void HandleAuraModAllCritChance(bool Apply, bool Real);
        void HandleAuraOpenStable(bool apply, bool Real);
        void HandleAuraAddMechanicAbilities(bool apply, bool Real);
        void HandleAuraStopNaturalManaRegen(bool apply, bool Real);
        void HandleAuraSetVehicleId(bool apply, bool Real);
        void HandleMirrorName(bool apply, bool Real);
        void HandlePreventResurrection(bool apply, bool Real);
        void HandleFactionOverride(bool apply, bool Real);
        void HandleTriggerLinkedAura(bool apply, bool Real);

        virtual ~Aura();

        void SetModifier(AuraType t, int32 a, uint32 pt, int32 miscValue);
        Modifier*       GetModifier()       { return &m_modifier; }
        Modifier const* GetModifier() const { return &m_modifier; }
        int32 GetMiscValue() const { return m_spellAuraHolder->GetSpellProto()->EffectMiscValue[m_effIndex]; }
        int32 GetMiscBValue() const { return m_spellAuraHolder->GetSpellProto()->EffectMiscValueB[m_effIndex]; }

        SpellEntry const* GetSpellProto() const { return GetHolder()->GetSpellProto(); }
        uint32 GetId() const { return GetHolder()->GetSpellProto()->Id; }
        ObjectGuid const& GetCastItemGuid() const { return GetHolder()->GetCastItemGuid(); }
        ObjectGuid const& GetCasterGuid() const { return GetHolder()->GetCasterGuid(); }
        Unit* GetCaster() const { return GetHolder()->GetCaster(); }
        Unit* GetTarget() const { return GetHolder()->GetTarget(); }

        SpellEffectIndex GetEffIndex() const { return m_effIndex; }
        int32 GetBasePoints() const { return m_currentBasePoints; }

        int32 GetAuraMaxDuration() const { return GetHolder()->GetAuraMaxDuration(); }
        int32 GetAuraDuration() const { return GetHolder()->GetAuraDuration(); }
        time_t GetAuraApplyTime() const { return m_applyTime; }
        uint32 GetAuraTicks() const { return m_periodicTick; }
        uint32 GetAuraMaxTicks() const
        {
            int32 maxDuration = GetAuraMaxDuration();
            return maxDuration > 0 && m_modifier.periodictime > 0 ? maxDuration / m_modifier.periodictime : 0;
        }
        uint32 GetStackAmount() const { return GetHolder()->GetStackAmount(); }

        void SetLoadedState(int32 damage, uint32 periodicTime)
        {
            m_modifier.m_amount = damage;
            m_modifier.periodictime = periodicTime;

            if (uint32 maxticks = GetAuraMaxTicks())
                { m_periodicTick = maxticks - GetAuraDuration() / m_modifier.periodictime; }
        }

        bool IsPositive() { return m_positive; }
        bool IsPersistent() const { return m_isPersistent; }
        bool IsAreaAura() const { return m_isAreaAura; }
        bool IsPeriodic() const { return m_isPeriodic; }
        bool IsInUse() const { return m_in_use; }

        void SetInUse(bool state)
        {
            if (state)
                { ++m_in_use; }
            else
            {
                if (m_in_use)
                    { --m_in_use; }
            }
        }
        void ApplyModifier(bool apply, bool Real = false);

        void UpdateAura(uint32 diff) { SetInUse(true); Update(diff); SetInUse(false); }

        void SetRemoveMode(AuraRemoveMode mode) { m_removeMode = mode; }

        virtual Unit* GetTriggerTarget() const { return m_spellAuraHolder->GetTarget(); }

        // add/remove SPELL_AURA_MOD_SHAPESHIFT (36) linked auras
        void HandleShapeshiftBoosts(bool apply);

        void TriggerSpell();
        void TriggerSpellWithValue();

        ClassFamilyMask const& GetAuraSpellClassMask() const { return  m_spellAuraHolder->GetSpellProto()->GetEffectSpellClassMask(m_effIndex); }
        bool isAffectedOnSpell(SpellEntry const* spell) const;
        bool CanProcFrom(SpellEntry const* spell, uint32 procFlag, uint32 EventProcEx, uint32 procEx, bool active, bool useClassMask) const;

        SpellAuraHolder* GetHolder() { return m_spellAuraHolder; }
        SpellAuraHolder const* GetHolder() const { return m_spellAuraHolder; }

        bool IsLastAuraOnHolder();

        bool HasMechanic(uint32 mechanic) const;
    protected:
        Aura(SpellEntry const* spellproto, SpellEffectIndex eff, int32* currentBasePoints, SpellAuraHolder* holder, Unit* target, Unit* caster = NULL, Item* castItem = NULL);

        // must be called only from Aura::UpdateAura
        virtual void Update(uint32 diff);

        // must be called only from Aura*::Update
        void PeriodicTick();
        void PeriodicDummyTick();

        bool IsCritFromAbilityAura(Unit* caster, uint32& damage);
        void ReapplyAffectedPassiveAuras();

        Modifier m_modifier;

        time_t m_applyTime;

        int32 m_currentBasePoints;                          // cache SpellEntry::CalculateSimpleValue and use for set custom base points
        int32 m_periodicTimer;                              // Timer for periodic auras
        uint32 m_periodicTick;                              // Tick count pass (including current if use in tick code) from aura apply, used for some tick count dependent aura effects

        AuraRemoveMode m_removeMode: 8;                     // Store info for know remove aura reason

        SpellEffectIndex m_effIndex : 8;                    // Aura effect index in spell

        bool m_positive: 1;
        bool m_isPeriodic: 1;
        bool m_isAreaAura: 1;
        bool m_isPersistent: 1;

        uint32 m_in_use;                                    // > 0 while in Aura::ApplyModifier call/Aura::Update/etc

        SpellAuraHolder* const m_spellAuraHolder;
    private:
        void ReapplyAffectedPassiveAuras(Unit* target, bool owner_mode);
};

class MANGOS_DLL_SPEC AreaAura : public Aura
{
    public:
        AreaAura(SpellEntry const* spellproto, SpellEffectIndex eff, int32* currentBasePoints, SpellAuraHolder* holder, Unit* target, Unit* caster = NULL, Item* castItem = NULL);
        ~AreaAura();
    protected:
        void Update(uint32 diff) override;
    private:
        float m_radius;
        AreaAuraType m_areaAuraType;
};

class MANGOS_DLL_SPEC PersistentAreaAura : public Aura
{
    public:
        PersistentAreaAura(SpellEntry const* spellproto, SpellEffectIndex eff, int32* currentBasePoints, SpellAuraHolder* holder, Unit* target, Unit* caster = NULL, Item* castItem = NULL);
        ~PersistentAreaAura();
    protected:
        void Update(uint32 diff) override;
};

class MANGOS_DLL_SPEC SingleEnemyTargetAura : public Aura
{
        friend Aura* CreateAura(SpellEntry const* spellproto, SpellEffectIndex eff, int32* currentBasePoints, SpellAuraHolder* holder, Unit* target, Unit* caster, Item* castItem);

    public:
        ~SingleEnemyTargetAura();
        Unit* GetTriggerTarget() const override;

    protected:
        SingleEnemyTargetAura(SpellEntry const* spellproto, SpellEffectIndex eff, int32* currentBasePoints, SpellAuraHolder* holder, Unit* target, Unit* caster  = NULL, Item* castItem = NULL);
        ObjectGuid m_castersTargetGuid;
};

Aura* CreateAura(SpellEntry const* spellproto, SpellEffectIndex eff, int32* currentBasePoints, SpellAuraHolder* holder, Unit* target, Unit* caster = NULL, Item* castItem = NULL);
SpellAuraHolder* CreateSpellAuraHolder(SpellEntry const* spellproto, Unit* target, WorldObject* caster, Item* castItem = NULL);
#endif
