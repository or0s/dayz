////////////////////////////////////////////////////////////////////
//DeRap: characters_vests\config.bin
//Produced from mikero's Dos Tools Dll version 6.44
//'now' is Wed Dec 26 13:54:12 2018 : 'file' last modified on Thu Dec 20 15:56:15 2018
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//(12 Enums)
enum {
	destructengine = 2,
	destructdefault = 6,
	destructwreck = 7,
	destructtree = 3,
	destructtent = 4,
	stabilizedinaxisx = 1,
	stabilizedinaxisy = 2,
	destructno = 0,
	stabilizedinaxesboth = 3,
	stabilizedinaxesnone = 0,
	destructman = 5,
	destructbuilding = 1
};

class CfgPatches
{
	class DZ_Characters_Vests
	{
		units[] = {"TacticalVest","UKAssVest"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters"};
	};
};
class CfgVehicles
{
	class Clothing_Base;
	class Clothing: Clothing_Base{};
	class PlateCarrierVest: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PlateCarrierBlank0";
		descriptionShort = "$STR_CfgVehicles_PlateCarrierBlank1";
		model = "\DZ\characters\vests\plate_carrier_g.p3d";
		inventorySlot = "Vest";
		itemInfo[] = {"Clothing","Vest"};
		attachments[] = {"VestHolster","VestPouch"};
		weight = 12000;
		itemSize[] = {4,4};
		absorbency = 0.1;
		heatIsolation = 0.1;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		class ClothingTypes
		{
			male = "\DZ\characters\vests\plate_carrier_m.p3d";
			female = "\DZ\characters\vests\plate_carrier_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\vests\Data\BallisticVest.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\vests\Data\BallisticVest_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\vests\Data\BallisticVest_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					Health = 0.4;
					Blood = 0.4;
					Shock = 0.5;
				};
				class Melee
				{
					Health = 0.7;
					Blood = 0.6;
					Shock = 0.8;
				};
				class Infected
				{
					Health = 0.7;
					Blood = 0.6;
					Shock = 0.8;
				};
			};
		};
	};
	class SmershVest: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SmershVest0";
		descriptionShort = "$STR_CfgVehicles_SmershVest1";
		model = "\DZ\characters\vests\smersh_light_g.p3d";
		attachments[] = {"VestBackpack"};
		inventorySlot = "Vest";
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Vest"};
		weight = 220;
		itemSize[] = {3,3};
		itemsCargoSize[] = {6,5};
		quickBarBonus = 3;
		absorbency = 0.3;
		heatIsolation = 0.2;
		visibilityModifier = 0.7;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\dz\characters\vests\data\smersh_co.paa","\dz\characters\vests\data\smersh_co.paa","\dz\characters\vests\data\smersh_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\vests\Data\Smersh.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\vests\Data\Smersh_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\vests\Data\Smersh_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					Health = 0.9;
					Blood = 1.0;
					Shock = 1.0;
				};
				class Melee
				{
					Health = 0.9;
					Blood = 0.95;
					Shock = 0.95;
				};
				class Infected
				{
					Health = 0.9;
					Blood = 0.95;
					Shock = 0.95;
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\vests\smersh_light_m.p3d";
			female = "\DZ\characters\vests\smersh_light_f.p3d";
		};
	};
	class PressVest_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_PressVest_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_PressVest_ColorBase1";
		model = "\DZ\characters\vests\pressVest_g.p3d";
		inventorySlot = "Vest";
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Vest"};
		weight = 7000;
		itemSize[] = {3,2};
		itemsCargoSize[] = {6,4};
		quickBarBonus = 2;
		absorbency = 0.1;
		heatIsolation = 0.2;
		visibilityModifier = 0.95;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class ClothingTypes
		{
			male = "\DZ\characters\vests\pressVest_m.p3d";
			female = "\DZ\characters\vests\pressVest_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					healthLevels[] = {{1.0,{"DZ\characters\vests\Data\PressVest.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\vests\Data\PressVest_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\vests\Data\PressVest_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					Health = 0.7;
					Blood = 0.7;
					Shock = 0.7;
				};
				class Melee
				{
					Health = 0.8;
					Blood = 0.9;
					Shock = 0.9;
				};
				class Infected
				{
					Health = 0.8;
					Blood = 0.9;
					Shock = 0.9;
				};
			};
		};
	};
	class PressVest_Blue: PressVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\dz\characters\vests\data\PressVest_Blue_co.paa","\dz\characters\vests\data\PressVest_Blue_co.paa","\dz\characters\vests\data\PressVest_Blue_co.paa"};
	};
	class PressVest_LightBlue: PressVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\dz\characters\vests\data\PressVest_LightBlue_co.paa","\dz\characters\vests\data\PressVest_LightBlue_co.paa","\dz\characters\vests\data\PressVest_LightBlue_co.paa"};
	};
	class UKAssVest_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_UKAssVest_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_UKAssVest_ColorBase1";
		model = "\DZ\characters\vests\UKAssVest_g.p3d";
		inventorySlot = "Vest";
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Vest"};
		weight = 1900;
		itemSize[] = {3,3};
		itemsCargoSize[] = {6,5};
		quickBarBonus = 3;
		absorbency = 0.3;
		heatIsolation = 0.2;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class ClothingTypes
		{
			male = "\DZ\characters\vests\UKAssVest_m.p3d";
			female = "\DZ\characters\vests\UKAssVest_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					healthLevels[] = {{1.0,{"DZ\characters\vests\Data\UKAssVest.rvmat","DZ\characters\vests\Data\UKAssVest_ground.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\vests\Data\UKAssVest_damage.rvmat","DZ\characters\vests\Data\UKAssVest_ground_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\vests\Data\UKAssVest_destruct.rvmat","DZ\characters\vests\Data\UKAssVest_ground_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					Health = 0.9;
					Blood = 0.9;
					Shock = 1;
				};
				class Melee
				{
					Health = 0.85;
					Blood = 0.95;
					Shock = 1;
				};
				class Infected
				{
					Health = 0.85;
					Blood = 0.95;
					Shock = 1;
				};
			};
		};
	};
	class UKAssVest_Black: UKAssVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"\dz\characters\vests\data\UKAssVest_ground_black_co.paa","\dz\characters\vests\data\UKAssVest_black_co.paa","\dz\characters\vests\data\UKAssVest_black_co.paa"};
	};
	class UKAssVest_Camo: UKAssVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.5;
		hiddenSelectionsTextures[] = {"\dz\characters\vests\data\UKAssVest_ground_camo_co.paa","\dz\characters\vests\data\UKAssVest_camo_co.paa","\dz\characters\vests\data\UKAssVest_camo_co.paa"};
	};
	class UKAssVest_Khaki: UKAssVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.5;
		hiddenSelectionsTextures[] = {"\dz\characters\vests\data\UKAssVest_ground_Khaki_co.paa","\dz\characters\vests\data\UKAssVest_Khaki_co.paa","\dz\characters\vests\data\UKAssVest_Khaki_co.paa"};
	};
	class UKAssVest_Olive: UKAssVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.6;
		hiddenSelectionsTextures[] = {"\dz\characters\vests\data\UKAssVest_ground_Olive_co.paa","\dz\characters\vests\data\UKAssVest_Olive_co.paa","\dz\characters\vests\data\UKAssVest_Olive_co.paa"};
	};
	class PoliceVest: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PoliceVest0";
		descriptionShort = "$STR_CfgVehicles_PoliceVest1";
		model = "\DZ\characters\vests\policeVest_g.p3d";
		inventorySlot = "Vest";
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Vest"};
		weight = 3500;
		itemSize[] = {3,2};
		absorbency = 0.1;
		heatIsolation = 0.2;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\dz\characters\vests\data\policevest_co.paa","\dz\characters\vests\data\policevest_co.paa","\dz\characters\vests\data\policevest_co.paa"};
		class ClothingTypes
		{
			male = "\DZ\characters\vests\policeVest_m.p3d";
			female = "\DZ\characters\vests\policeVest_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					healthLevels[] = {{1.0,{"DZ\characters\vests\Data\PoliceVest.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\vests\Data\PoliceVest_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\vests\Data\PoliceVest_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					Health = 0.8;
					Blood = 0.7;
					Shock = 0.8;
				};
				class Melee
				{
					Health = 0.3;
					Blood = 0.3;
					Shock = 0.5;
				};
				class Infected
				{
					Health = 0.3;
					Blood = 0.3;
					Shock = 0.5;
				};
			};
		};
	};
	class PlateCarrierHolster: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CarrierHolsterSolo0";
		descriptionShort = "$STR_CfgVehicles_CarrierHolsterSolo1";
		model = "\DZ\characters\vests\plate_carrier_holster_g.p3d";
		inventorySlot = "VestHolster";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Vest"};
		weight = 110;
		itemSize[] = {3,2};
		attachments[] = {"Pistol"};
		absorbency = 0.1;
		heatIsolation = 0.1;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\vests\data\ballisticvest.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\vests\data\ballisticvest_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\vests\data\ballisticvest_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\vests\chest_holster_m.p3d";
			female = "\DZ\characters\vests\chest_holster_f.p3d";
		};
	};
	class ChestHolster: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ChestHolster0";
		descriptionShort = "$STR_CfgVehicles_ChestHolster1";
		model = "\DZ\characters\vests\chest_holster_g.p3d";
		inventorySlot = "Vest";
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Vest"};
		attachments[] = {"Pistol"};
		weight = 310;
		itemSize[] = {3,2};
		absorbency = 0.1;
		heatIsolation = 0.1;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		class ClothingTypes
		{
			male = "\DZ\characters\vests\chest_holster_m.p3d";
			female = "\DZ\characters\vests\chest_holster_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					healthLevels[] = {{1.0,{"DZ\characters\vests\data\chest_holster.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\vests\data\chest_holster_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\vests\data\chest_holster_destruct.rvmat"}}};
				};
			};
		};
	};
	class HighCapacityVest_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_HighCapacityVest_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_HighCapacityVest_ColorBase1";
		model = "\DZ\characters\vests\tacticalvest2_g.p3d";
		inventorySlot = "Vest";
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Vest"};
		weight = 2400;
		itemSize[] = {4,3};
		itemsCargoSize[] = {7,5};
		quickBarBonus = 3;
		absorbency = 0.1;
		heatIsolation = 0.25;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class ClothingTypes
		{
			male = "\DZ\characters\vests\tacticalvest2_m.p3d";
			female = "\DZ\characters\vests\tacticalvest2_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					healthLevels[] = {{1.0,{"DZ\characters\vests\Data\TacticalVest2.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\vests\Data\TacticalVest2_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\vests\Data\TacticalVest2_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					Health = 0.9;
					Blood = 0.9;
					Shock = 1;
				};
				class Melee
				{
					Health = 0.8;
					Blood = 0.9;
					Shock = 0.9;
				};
				class Infected
				{
					Health = 0.8;
					Blood = 0.9;
					Shock = 0.9;
				};
			};
		};
	};
	class HighCapacityVest_Black: HighCapacityVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"\dz\characters\vests\data\tacticalvest2_black_co.paa","\dz\characters\vests\data\tacticalvest2_black_co.paa","\dz\characters\vests\data\tacticalvest2_black_co.paa"};
	};
	class HighCapacityVest_Olive: HighCapacityVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.6;
		hiddenSelectionsTextures[] = {"\dz\characters\vests\data\tacticalvest2_olive_co.paa","\dz\characters\vests\data\tacticalvest2_olive_co.paa","\dz\characters\vests\data\tacticalvest2_olive_co.paa"};
	};
	class LeatherStorageVest_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_LeatherStorageVest_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_LeatherStorageVest_ColorBase1";
		model = "\DZ\characters\vests\Vest_LeatherStorage_g.p3d";
		inventorySlot = "Vest";
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Vest"};
		weight = 2800;
		itemSize[] = {4,3};
		itemsCargoSize[] = {7,5};
		quickBarBonus = 3;
		absorbency = 0.45;
		heatIsolation = 0.35;
		lootCategory = "Crafted";
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					Health = 0.75;
					Blood = 0.65;
					Shock = 0.8;
				};
				class Melee
				{
					Health = 0.7;
					Blood = 0.6;
					Shock = 0.8;
				};
				class Infected
				{
					Health = 0.7;
					Blood = 0.6;
					Shock = 0.8;
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\vests\Vest_LeatherStorage_m.p3d";
			female = "\DZ\characters\vests\Vest_LeatherStorage_f.p3d";
		};
	};
	class LeatherStorageVest_Natural: LeatherStorageVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsMaterials[] = {"DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat","DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat","DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\vests\Data\Vest_LeatherStorage_natural_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\vests\Data\Vest_LeatherStorage_natural_destruct.rvmat"}}};
				};
			};
			class GlobalArmor: GlobalArmor{};
		};
	};
	class LeatherStorageVest_Beige: LeatherStorageVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsMaterials[] = {"DZ\characters\vests\data\Vest_LeatherStorage_beige.rvmat","DZ\characters\vests\data\Vest_LeatherStorage_beige.rvmat","DZ\characters\vests\data\Vest_LeatherStorage_beige.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\vests\Data\Vest_LeatherStorage_beige_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\vests\Data\Vest_LeatherStorage_beige_destruct.rvmat"}}};
				};
			};
			class GlobalArmor: GlobalArmor{};
		};
	};
	class LeatherStorageVest_Brown: LeatherStorageVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsMaterials[] = {"DZ\characters\vests\data\Vest_LeatherStorage_brown.rvmat","DZ\characters\vests\data\Vest_LeatherStorage_brown.rvmat","DZ\characters\vests\data\Vest_LeatherStorage_brown.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\vests\Data\Vest_LeatherStorage_brown_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\vests\Data\Vest_LeatherStorage_brown_destruct.rvmat"}}};
				};
			};
			class GlobalArmor: GlobalArmor{};
		};
	};
	class LeatherStorageVest_Black: LeatherStorageVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsMaterials[] = {"DZ\characters\vests\data\Vest_LeatherStorage_black.rvmat","DZ\characters\vests\data\Vest_LeatherStorage_black.rvmat","DZ\characters\vests\data\Vest_LeatherStorage_black.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\vests\Data\Vest_LeatherStorage_black_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\vests\Data\Vest_LeatherStorage_black_destruct.rvmat"}}};
				};
			};
			class GlobalArmor: GlobalArmor{};
		};
	};
	class HuntingVest: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_HuntingVest0";
		descriptionShort = "$STR_CfgVehicles_HuntingVest1";
		model = "\DZ\characters\vests\hunter_vest_g.p3d";
		inventorySlot = "Vest";
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Vest"};
		weight = 350;
		itemSize[] = {3,2};
		itemsCargoSize[] = {6,4};
		absorbency = 0.6;
		heatIsolation = 0.5;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		class ClothingTypes
		{
			male = "\DZ\characters\vests\hunter_vest_m.p3d";
			female = "\DZ\characters\vests\hunter_vest_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					healthLevels[] = {{1.0,{"DZ\characters\vests\Data\Hunting_vest.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\vests\Data\Hunting_vest_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\vests\Data\Hunting_vest_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					Health = 0.85;
					Blood = 0.85;
					Shock = 0.9;
				};
				class Melee
				{
					Health = 0.9;
					Blood = 0.9;
					Shock = 0.9;
				};
				class Infected
				{
					Health = 0.9;
					Blood = 0.9;
					Shock = 0.9;
				};
			};
		};
	};
	class ReflexVest: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ReflexVest0";
		descriptionShort = "$STR_CfgVehicles_ReflexVest1";
		model = "\DZ\characters\vests\orange_vest_g.p3d";
		inventorySlot = "Vest";
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Vest"};
		weight = 200;
		itemSize[] = {3,2};
		absorbency = 0.9;
		heatIsolation = 0.1;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		class ClothingTypes
		{
			male = "\DZ\characters\vests\orange_vest_m.p3d";
			female = "\DZ\characters\vests\orange_vest_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\vests\Data\orange_vest.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\vests\Data\orange_vest_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\vests\Data\orange_vest_destruct.rvmat"}}};
				};
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxyberetta: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Pistol";
		model = "DZ\characters\proxies\beretta.p3d";
	};
	class Proxyplate_carrier_pouches_g: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "VestPouch";
		model = "DZ\characters\vests\plate_carrier_pouches_g.p3d";
	};
	class Proxyplate_carrier_holster_g: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "VestHolster";
		model = "DZ\characters\vests\plate_carrier_holster_g.p3d";
	};
};
