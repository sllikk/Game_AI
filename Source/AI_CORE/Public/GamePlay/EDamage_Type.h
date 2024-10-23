#pragma once

#include "CoreMinimal.h"
#include "EDamage_Type.generated.h"

UENUM()
enum class EDamageType : uint64
{
	DMG_GENERIC         = 0x1,          /**< Non-specific damage. */
	DMG_CRUSH           = 0x2,          /**< Being crushed by something heavy. */
	DMG_BULLET          = 0x4,          /**< Shot by a gun. */
	DMG_SLASH           = 0x8,          /**< Cutting, from swords or knives. */
	DMG_BURN            = 0x10,         /**< Short flame, or on-fire type damage. */
	DMG_VEHICLE         = 0x20,         /**< Vehicle ramming into you at speed. */
	DMG_FALL            = 0x40,         /**< Fall damage. */
	DMG_EXPLODE         = 0x80,         /**< Fire explosion damage. */
	DMG_ELECTRO         = 0x100,        /**< Electric shock damage. */
	DMG_ENERGYBEAM      = 0x200,        /**< Energy beam damage. */
	DMG_DROWN           = 0x400,        /**< Drown damage, gets restored over time. */
	DMG_PARALYZE        = 0x800,        /**< Paralysis damage. */
	DMG_NERVEGAS        = 0x1000,       /**< Toxins to the nerve, special effect? */
	DMG_POISON          = 0x2000,       /**< Poisonous damage. Similar to nerves? */
	DMG_RADIATION       = 0x4000,       /**< Radiation damage. Geiger counter go brr. */
	DMG_DROWNRECOVER    = 0x8000,       /**< Health increase from drown recovery. */
	DMG_CHEMICAL        = 0x10000,      /**< Chemical damage. */
	DMG_SLOWBURN        = 0x20000,      /**< Slow burning, just like burning but different rate. */
	DMG_SKIP_ARMOR      = 0x40000,      /**< This damage will skip armor checks entirely. */
	DMG_SKIP_RAGDOLL    = 0x80000       /**< This damage will not affect ragdolls. */
};

