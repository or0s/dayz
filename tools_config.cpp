////////////////////////////////////////////////////////////////////
//DeRap: gear_tools\config.bin
//Produced from mikero's Dos Tools Dll version 6.44
//'now' is Thu Dec 27 16:34:11 2018 : 'file' last modified on Tue Dec 18 09:22:50 2018
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
	class DZ_Gear_Tools
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Melee"};
	};
};
class CfgRecipes
{
	class WriteLetter
	{
		name = "Write on %TOOL2";
		tools[] = {"PenBase","Consumable_Paper"};
		condition = "(strlen (_tool2 getVariable ['message',''])) < 1000";
		action = "makeNote = [_tool1,_tool2];(owner _owner) publicVariableClient 'makeNote';diag_log 'Making a note'";
	};
	class DisassembleTrumpet
	{
		name = "Disassemble %MATERIAL1";
		material[] = {"Trumpet"};
		results[] = {"TrumpetParts"};
		condition = "";
		action = "if(!isNull (_material1 itemInSlot 'suppressorImpro')) then {_supr = ['Att_Suppressor_Improvised',_owner] call player_addInventory;_supr setDamage (damage (_material1 itemInSlot 'suppressorImpro'));}; 	if(!isNull (_material1 itemInSlot 'weaponOpticsHunting')) then {_optics = ['Att_Optic_Hunting',_owner] call player_addInventory;_optics setDamage (damage (_material1 itemInSlot 'weaponOpticsHunting'));};	if(!isNull (_material1 itemInSlot 'magazine')) then {_count = magazineAmmo (_material1 itemInSlot 'magazine');	_ammo = ['Ammo_22',_owner] call player_addInventory;_ammo setVariable['quantity', _count];};_result1 setDamage (damage _material1);	[_owner,format['I have disassembled %1.',displayName _result1],'colorAction'] call fnc_playerMessage;";
	};
	class AssembleTrumpet
	{
		name = "Assemble %MATERIAL1";
		material[] = {"TrumpetParts"};
		results[] = {"Trumpet"};
		condition = "(damage _material1) < 1";
		action = "_result1 setDamage (damage _material1);[_owner,format['I have assembled %1.',displayName _result1],'colorAction'] call fnc_playerMessage;";
	};
	class Sawoffshotgun
	{
		name = "Saw off %MATERIAL1 with %TOOL1";
		material[] = {"ShotgunIzh43"};
		tools[] = {"Tool_Hacksaw"};
		results[] = {"ShotgunIzh43_Sawedoff"};
		condition = "(isNull (_material1 itemInSlot 'magazine'))";
		action = "[_owner,format['I have crafted %1.',displayName _result1],'colorAction'] call fnc_playerMessage; _result1 setDamage (damage _material1);";
	};
	class SawOffMosin
	{
		name = "Saw off %MATERIAL1 with %TOOL1";
		material[] = {"Mosin9130"};
		tools[] = {"Tool_Hacksaw"};
		results[] = {"Mosin9130_Sawedoff"};
		condition = "(isNull (_material1 itemInSlot 'weaponMuzzleMosin')) AND (isNull (_material1 itemInSlot 'weaponBayonetMosin')) AND (isNull (_material1 itemInSlot 'weaponOpticsMosin')) AND (isNull (_material1 itemInSlot 'weaponBipod')) AND (isNull (_material1 itemInSlot 'weaponWrap')) AND (isNull (_material1 itemInSlot 'suppressorImpro'))";
		action = "_result1 setDamage (damage _material1);[_owner,format['I have crafted %1.',displayName _result1],'colorAction'] call fnc_playerMessage;if (!isNull (_material1 itemInSlot 'magazine')) exitWith {_count = magazineAmmo (_material1 itemInSlot 'magazine');_class = typeOf (_material1 itemInSlot 'magazine');_ammo = _result1 createInInventory _class;_ammo setVariable['quantity', _count];};";
	};
	class SawOffMosin_paintedBlack
	{
		name = "Saw off %MATERIAL1 with %TOOL1";
		material[] = {"Mosin9130_Black"};
		tools[] = {"Tool_Hacksaw"};
		results[] = {"Mosin9130_Sawedoff_Black"};
		condition = "(isNull (_material1 itemInSlot 'weaponMuzzleMosin')) AND (isNull (_material1 itemInSlot 'weaponBayonetMosin')) AND (isNull (_material1 itemInSlot 'weaponOpticsMosin')) AND (isNull (_material1 itemInSlot 'weaponBipod')) AND (isNull (_material1 itemInSlot 'weaponWrap')) AND (isNull (_material1 itemInSlot 'suppressorImpro'))";
		action = "_result1 setDamage (damage _material1);[_owner,format['I have crafted %1.',displayName _result1],'colorAction'] call fnc_playerMessage;if (!isNull (_material1 itemInSlot 'magazine')) exitWith {_count = magazineAmmo (_material1 itemInSlot 'magazine');_class = typeOf (_material1 itemInSlot 'magazine');_ammo = _result1 createInInventory _class;_ammo setVariable['quantity', _count];};";
	};
	class SawOffMosin_paintedGreen
	{
		name = "Saw off %MATERIAL1 with %TOOL1";
		material[] = {"Mosin9130_Green"};
		tools[] = {"Tool_Hacksaw"};
		results[] = {"Mosin9130_Sawedoff_Green"};
		condition = "(isNull (_material1 itemInSlot 'weaponMuzzleMosin')) AND (isNull (_material1 itemInSlot 'weaponBayonetMosin')) AND (isNull (_material1 itemInSlot 'weaponOpticsMosin')) AND (isNull (_material1 itemInSlot 'weaponBipod')) AND (isNull (_material1 itemInSlot 'weaponWrap')) AND (isNull (_material1 itemInSlot 'suppressorImpro'))";
		action = "_result1 setDamage (damage _material1);[_owner,format['I have crafted %1.',displayName _result1],'colorAction'] call fnc_playerMessage;if (!isNull (_material1 itemInSlot 'magazine')) exitWith {_count = magazineAmmo (_material1 itemInSlot 'magazine');_class = typeOf (_material1 itemInSlot 'magazine');_ammo = _result1 createInInventory _class;_ammo setVariable['quantity', _count];};";
	};
	class SawOffMosin_paintedCamo1
	{
		name = "Saw off %MATERIAL1 with %TOOL1";
		material[] = {"Mosin9130_Green_Black"};
		tools[] = {"Tool_Hacksaw"};
		results[] = {"Mosin9130_Sawedoff_Green_Black"};
		condition = "(isNull (_material1 itemInSlot 'weaponMuzzleMosin')) AND (isNull (_material1 itemInSlot 'weaponBayonetMosin')) AND (isNull (_material1 itemInSlot 'weaponOpticsMosin')) AND (isNull (_material1 itemInSlot 'weaponBipod')) AND (isNull (_material1 itemInSlot 'weaponWrap')) AND (isNull (_material1 itemInSlot 'suppressorImpro'))";
		action = "_result1 setDamage (damage _material1);[_owner,format['I have crafted %1.',displayName _result1],'colorAction'] call fnc_playerMessage;if (!isNull (_material1 itemInSlot 'magazine')) exitWith {_count = magazineAmmo (_material1 itemInSlot 'magazine');_class = typeOf (_material1 itemInSlot 'magazine');_ammo = _result1 createInInventory _class;_ammo setVariable['quantity', _count];};";
	};
	class SawOffMosin_paintedCamo2
	{
		name = "Saw off %MATERIAL1 with %TOOL1";
		material[] = {"Mosin9130_Black_Green"};
		tools[] = {"Tool_Hacksaw"};
		results[] = {"Mosin9130_Sawedoff_Black_Green"};
		condition = "(isNull (_material1 itemInSlot 'weaponMuzzleMosin')) AND (isNull (_material1 itemInSlot 'weaponBayonetMosin')) AND (isNull (_material1 itemInSlot 'weaponOpticsMosin')) AND (isNull (_material1 itemInSlot 'weaponBipod')) AND (isNull (_material1 itemInSlot 'weaponWrap')) AND (isNull (_material1 itemInSlot 'suppressorImpro'))";
		action = "_result1 setDamage (damage _material1);[_owner,format['I have crafted %1.',displayName _result1],'colorAction'] call fnc_playerMessage;if (!isNull (_material1 itemInSlot 'magazine')) exitWith {_count = magazineAmmo (_material1 itemInSlot 'magazine');_class = typeOf (_material1 itemInSlot 'magazine');_ammo = _result1 createInInventory _class;_ammo setVariable['quantity', _count];};";
	};
	class SawOffIzh18
	{
		name = "Saw off %MATERIAL1 with %TOOL1";
		material[] = {"izh18"};
		tools[] = {"Tool_Hacksaw"};
		results[] = {"izh18_Sawedoff"};
		condition = "(isNull (_material1 itemInSlot 'weaponMuzzleMosin')) AND (isNull (_material1 itemInSlot 'weaponBayonetMosin')) AND (isNull (_material1 itemInSlot 'weaponOpticsMosin')) AND (isNull (_material1 itemInSlot 'weaponBipod')) AND (isNull (_material1 itemInSlot 'weaponWrap')) AND (isNull (_material1 itemInSlot 'suppressorImpro'))";
		action = "_result1 setDamage (damage _material1);[_owner,format['I have crafted %1.',displayName _result1],'colorAction'] call fnc_playerMessage;if (!isNull (_material1 itemInSlot 'magazine')) exitWith {_count = magazineAmmo (_material1 itemInSlot 'magazine');_class = typeOf (_material1 itemInSlot 'magazine');_ammo = _result1 createInInventory _class;_ammo setVariable['quantity', _count];};";
	};
	class CleanRifle
	{
		name = "Clean %TOOL1 with %TOOL2";
		tools[] = {"DefaultWeapon","Tool_WeaponCleaningKit"};
		playerAction = "PlayerCraft";
		action = "'cfgWeapons' call player_mendItem;";
	};
	class PatchHats
	{
		name = "Patch %TOOL1 with %TOOL2";
		tools[] = {"HeadgearBase","Tool_SewingKit"};
		playerAction = "PlayerCraft";
		action = "'cfgVehicles' call player_mendItem;";
	};
	class PatchBandanas
	{
		name = "Patch %TOOL1 with %TOOL2";
		tools[] = {"Consumable_BandanaBase","Tool_SewingKit"};
		playerAction = "PlayerCraft";
		action = "'cfgVehicles' call player_mendItem;";
	};
	class PatchTops
	{
		name = "Patch %TOOL1 with %TOOL2";
		tools[] = {"ClothingTopwearBase","Tool_SewingKit"};
		playerAction = "PlayerCraft";
		action = "'cfgVehicles' call player_mendItem;";
	};
	class PatchVests
	{
		name = "Patch %TOOL1 with %TOOL2";
		tools[] = {"VestBase","Tool_SewingKit"};
		playerAction = "PlayerCraft";
		action = "'cfgVehicles' call player_mendItem;";
	};
	class PatchGloves
	{
		name = "Patch %TOOL1 with %TOOL2";
		tools[] = {"GlovesBase","Tool_SewingKit"};
		playerAction = "PlayerCraft";
		action = "'cfgVehicles' call player_mendItem;";
	};
	class PatchPants
	{
		name = "Patch %TOOL1 with %TOOL2";
		tools[] = {"BottomwearBase","Tool_SewingKit"};
		playerAction = "PlayerCraft";
		action = "'cfgVehicles' call player_mendItem;";
	};
	class PatchMasks
	{
		name = "Patch %TOOL1 with %TOOL2";
		tools[] = {"MaskBase","Tool_SewingKit"};
		playerAction = "PlayerCraft";
		action = "'cfgVehicles' call player_mendItem;";
	};
	class PatchShoes
	{
		name = "Patch %TOOL1 with %TOOL2";
		tools[] = {"FootwearBase","Tool_SewingKit"};
		playerAction = "PlayerCraft";
		action = "'cfgVehicles' call player_mendItem;";
	};
	class PatchBag
	{
		name = "Patch %TOOL1 with %TOOL2";
		tools[] = {"BagBase","Tool_LeatherSewingKit"};
		playerAction = "PlayerCraft";
		action = "'cfgVehicles' call player_mendItem;";
	};
	class PatchPouches
	{
		name = "Patch %TOOL1 with %TOOL2";
		tools[] = {"Container_CarrierPouches","Tool_SewingKit"};
		playerAction = "PlayerCraft";
		action = "'cfgVehicles' call player_mendItem;";
	};
	class PatchWaterPouch
	{
		name = "Patch %TOOL1 with %TOOL2";
		tools[] = {"Drink_WaterPouchBase","Tool_SewingKit"};
		playerAction = "PlayerCraft";
		action = "'cfgVehicles' call player_mendItem;";
	};
	class PatchTentMedium
	{
		name = "Patch %TOOL1 with %TOOL2";
		tools[] = {"TentMedium_Packed","Tool_LeatherSewingKit"};
		playerAction = "PlayerCraft";
		action = "'cfgVehicles' call player_mendItem;";
	};
	class PatchBandageBase
	{
		name = "Patch %TOOL1 with %TOOL2";
		tools[] = {"Medical_BandageBase","Tool_SewingKit"};
		playerAction = "PlayerCraft";
		action = "'cfgVehicles' call player_mendItem;";
	};
	class PatchBurlapSack
	{
		name = "Patch %TOOL1 with %TOOL2";
		tools[] = {"Crafting_BurlapSack","Tool_SewingKit"};
		playerAction = "PlayerCraft";
		action = "'cfgVehicles' call player_mendItem;";
	};
	class PatchPeltbase
	{
		name = "Patch %TOOL1 with %TOOL2";
		tools[] = {"Consumable_PeltBase","Tool_LeatherSewingKit"};
		playerAction = "PlayerCraft";
		action = "'cfgVehicles' call player_mendItem;";
	};
	class PatchTannedLeatherbase
	{
		name = "Patch %TOOL1 with %TOOL2";
		tools[] = {"Consumable_TannedLeather_Base","Tool_LeatherSewingKit"};
		playerAction = "PlayerCraft";
		action = "'cfgVehicles' call player_mendItem;";
	};
	class SewHat_Leather_Natural
	{
		name = "Sew Natural Leather Hat from 1 %TOOL2";
		tools[] = {"Tool_LeatherSewingKit","Consumable_TannedLeather"};
		condition = "quantity _tool2 >= parseNumber "" 1"" ";
		action = "_needQuantity = parseNumber "" 1""; [_needQuantity,""Hat_Leather_Natural""] call player_sewLeatherClothing; ";
	};
	class SewBHHat_Leather_Natural: SewHat_Leather_Natural
	{
		tools[] = {"Consumable_BoneHook","Consumable_TannedLeather"};
	};
	class SewPants_LeatherPants_Natural
	{
		name = "Sew Natural Leather Pants from 3 %TOOL2";
		tools[] = {"Tool_LeatherSewingKit","Consumable_TannedLeather"};
		condition = "quantity _tool2 >= parseNumber "" 3"" ";
		action = "_needQuantity = parseNumber "" 3""; [_needQuantity,""Pants_LeatherPants_Natural""] call player_sewLeatherClothing; ";
	};
	class SewBHPants_LeatherPants_Natural: SewPants_LeatherPants_Natural
	{
		tools[] = {"Consumable_BoneHook","Consumable_TannedLeather"};
	};
	class SewShoes_LeatherMoccasins_Natural
	{
		name = "Sew Natural Leather Moccasins from 2 %TOOL2";
		tools[] = {"Tool_LeatherSewingKit","Consumable_TannedLeather"};
		condition = "quantity _tool2 >= parseNumber "" 2"" ";
		action = "_needQuantity = parseNumber "" 2""; [_needQuantity,""Shoes_LeatherMoccasins_Natural""] call player_sewLeatherClothing; ";
	};
	class SewBHShoes_LeatherMoccasins_Natural: SewShoes_LeatherMoccasins_Natural
	{
		tools[] = {"Consumable_BoneHook","Consumable_TannedLeather"};
	};
	class SewVest_LeatherStorage_Natural
	{
		name = "Sew Natural Leather Storage Vest from 4 %TOOL2";
		tools[] = {"Tool_LeatherSewingKit","Consumable_TannedLeather"};
		condition = "quantity _tool2 >= parseNumber "" 4"" ";
		action = "_needQuantity = parseNumber "" 4""; [_needQuantity,""Vest_LeatherStorage_Natural""] call player_sewLeatherClothing; ";
	};
	class SewBHVest_LeatherStorage_Natural: SewVest_LeatherStorage_Natural
	{
		tools[] = {"Consumable_BoneHook","Consumable_TannedLeather"};
	};
	class SewBag_LeatherSack_Natural
	{
		name = "Sew Natural Leather Sack from 5 %TOOL2";
		tools[] = {"Tool_LeatherSewingKit","Consumable_TannedLeather"};
		condition = "quantity _tool2 >= parseNumber "" 5"" ";
		action = "_needQuantity = parseNumber "" 5""; [_needQuantity,""Bag_LeatherSack_Natural""] call player_sewLeatherClothing; ";
	};
	class SewBHBag_LeatherSack_Natural: SewBag_LeatherSack_Natural
	{
		tools[] = {"Consumable_BoneHook","Consumable_TannedLeather"};
	};
	class SewTop_LeatherJacket_Natural
	{
		name = "Sew Natural Leather Jacket from 5 %TOOL2";
		tools[] = {"Tool_LeatherSewingKit","Consumable_TannedLeather"};
		condition = "quantity _tool2 >= parseNumber "" 5"" ";
		action = "_needQuantity = parseNumber "" 5""; [_needQuantity,""Top_LeatherJacket_Natural""] call player_sewLeatherClothing; ";
	};
	class SewBHTop_LeatherJacket_Natural: SewTop_LeatherJacket_Natural
	{
		tools[] = {"Consumable_BoneHook","Consumable_TannedLeather"};
	};
	class SewDrink_WaterPouch_Natural
	{
		name = "Sew Natural Water Pouch from 1 %TOOL2";
		tools[] = {"Tool_LeatherSewingKit","Consumable_TannedLeather"};
		condition = "quantity _tool2 >= parseNumber "" 1"" ";
		action = "_needQuantity = parseNumber "" 1""; [_needQuantity,""Drink_WaterPouch_Natural""] call player_sewLeatherClothing; ";
	};
	class SewBHDrink_WaterPouch_Natural: SewDrink_WaterPouch_Natural
	{
		tools[] = {"Consumable_BoneHook","Consumable_TannedLeather"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Switchable_Base;
	class EnergyItem_Base;
	class Powered_Base;
	class FishingRod_Base;
	class Flashlight: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Flashlight0";
		descriptionShort = "$STR_CfgVehicles_Flashlight1";
		model = "\DZ\gear\tools\flashlight.p3d";
		rotationFlags = 34;
		SingleUseActions[] = {509,510};
		itemSize[] = {3,1};
		weight = 210;
		animClass = "Pistol";
		hiddenSelections[] = {"zbytek","reflector","glass","reflector_far"};
		hiddenSelectionsTextures[] = {"dz\gear\tools\data\flashlight_old_co.paa","dz\gear\tools\data\flashlight_old_co.paa","dz\gear\tools\data\flashlight_glass.paa","dz\gear\tools\data\flashlight_old_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\flashlight_old.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\flashlight_old_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\flashlight_old_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.8;
			};
		};
		attachments[] = {"BatteryD"};
		repairableWithKits[] = {5,7};
		repairCosts[] = {30.0,25.0};
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOffWhenInCargo = 1;
			energyUsagePerSecond = 0.01;
			plugType = 1;
			attachmentAction = 1;
		};
		class Reflectors
		{
			class Beam
			{
				color[] = {1.0,0.85,0.75,1.0};
				brightness = 6.0;
				radius = 30;
				angle = 120;
				angleInnerRatio = 0.25;
				dayLight = 1;
				flareAngleBias = 40.0;
				position = "beamStart";
				direction = "beamEnd";
				hitpoint = "bulb";
				selection = "bulb";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Attack_flashlight_Light1
				{
					soundSet = "Char_Attack_pipemetal_light1_SoundSet";
					id = 806;
				};
				class Attack_flashlight_Light2
				{
					soundSet = "Char_Attack_pipemetal_light2_SoundSet";
					id = 807;
				};
				class Attack_flashlight_Heavy1
				{
					soundSet = "Char_Attack_pipemetal_heavy1_SoundSet";
					id = 808;
				};
				class Attack_flashlight_Heavy2
				{
					soundSet = "Char_Attack_pipemetal_heavy2_SoundSet";
					id = 809;
				};
			};
		};
	};
	class NightLightPrototype: Inventory_Base
	{
		scope = 2;
		displayName = "Night light prototype";
		descriptionShort = "Switch this ON or OFF to activate subtle blue light around your camera. Visible only at night and at close range to help you navigate through tight spaces in complete darkness without propper light source.";
		model = "\DZ\gear\tools\flashlight.p3d";
		rotationFlags = 34;
		SingleUseActions[] = {509,510};
		itemSize[] = {1,1};
		weight = 1;
		animClass = "Pistol";
		class EnergyManager
		{
			energyAtSpawn = 9999;
			energyUsagePerSecond = 0.01;
		};
	};
	class Pen_ColorBase: Inventory_Base
	{
		displayName = "$STR_CfgVehicles_Pen_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_Pen_ColorBase1";
		model = "\dz\gear\tools\Pen.p3d";
		ContinuousActions[] = {220};
		animClass = "Knife";
		itemSize[] = {1,1};
		rotationFlags = 17;
		autoQuickbar = 1;
		weight = 12;
		lootTag[] = {"Work","Office","Civilian"};
		writingColor = "#000000";
		absorbency = 0.1;
		fragility = 0.01;
		lootCategory = "Tools";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\flashlight_old.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\flashlight_old_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\flashlight_old_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.8;
			};
		};
	};
	class Pen_Black: Pen_ColorBase
	{
		scope = 2;
		writingColor = "#000000";
	};
	class Pen_Red: Pen_ColorBase
	{
		scope = 2;
		writingColor = "#B40404";
	};
	class Pen_Green: Pen_ColorBase
	{
		scope = 2;
		writingColor = "#088A08";
	};
	class Pen_Blue: Pen_ColorBase
	{
		scope = 2;
		writingColor = "#0431B4";
	};
	class CanOpener: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CanOpener0";
		descriptionShort = "$STR_CfgVehicles_CanOpener1";
		model = "\dz\gear\tools\CanOpener.p3d";
		animClass = "Knife";
		rotationFlags = 12;
		autoQuickbar = 1;
		isMeleeWeapon = 1;
		itemSize[] = {1,2};
		fragility = 0.01;
		openItemSpillRange[] = {0,0};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\Loot_CanOpener.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\Loot_CanOpener_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\Loot_CanOpener_destruct.rvmat"}}};
				};
			};
		};
	};
	class Heatpack: EnergyItem_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Heatpack0";
		descriptionShort = "$STR_CfgVehicles_Heatpack1";
		model = "\DZ\gear\tools\Heatpack.p3d";
		animClass = "Knife";
		SingleUseActions[] = {539};
		rotationFlags = 17;
		itemSize[] = {2,2};
		varEnergyInit = 1000;
		varEnergyMin = 0;
		varEnergyMax = 1000;
		varTemperatureMax = 60;
		weight = 150;
		fragility = 0.01;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\heat_pack.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\heat_pack_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\heat_pack_destruct.rvmat"}}};
				};
			};
		};
		class EnergyManager
		{
			energyAtSpawn = 1200;
			energyUsagePerSecond = 1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "pickUpBloodBag_SoundSet";
					id = 797;
				};
			};
		};
	};
	class MessTin: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_MessTin0";
		descriptionShort = "$STR_CfgVehicles_MessTin1";
		model = "\dz\gear\tools\Mess_tin.p3d";
		animClass = "Knife";
		weight = 170;
		itemSize[] = {4,3};
		fragility = 0.01;
		lootCategory = "Tools";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\Loot_MessTin.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\Loot_MessTin_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\Loot_MessTin_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.8;
			};
		};
	};
	class Pliers: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Pliers0";
		descriptionShort = "$STR_CfgVehicles_Pliers1";
		model = "\dz\gear\tools\Pliers.p3d";
		animClass = "Knife";
		RestrainUnlockType = 1;
		SingleUseActions[] = {533};
		ContinuousActions[] = {193,195,146,118,119};
		build_action_type = 1;
		dismantle_action_type = 1;
		rotationFlags = 17;
		weight = 240;
		fragility = 0.01;
		itemSize[] = {1,3};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\pliers.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\pliers_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\pliers_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleePliers";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleePliers_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleePliers_Heavy";
				range = 2.8;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "pickUpPliers_SoundSet";
					id = 797;
				};
			};
		};
	};
	class Lockpick: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Lockpick0";
		descriptionShort = "$STR_CfgVehicles_Lockpick1";
		model = "\dz\gear\tools\Lockpick.p3d";
		animClass = "Knife";
		RestrainUnlockType = 0;
		ContinuousActions[] = {146,210,211};
		rotationFlags = 17;
		isLockpick = 1;
		itemSize[] = {1,2};
		weight = 190;
		armor = 2;
		fragility = 0.01;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\Lockpick.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\Lockpick_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\Lockpick_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.8;
			};
		};
	};
	class WeaponCleaningKit: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_WeaponCleaningKit0";
		descriptionShort = "$STR_CfgVehicles_WeaponCleaningKit1";
		model = "\dz\gear\tools\cleaning_kit_wood.p3d";
		animClass = "Knife";
		rotationFlags = 17;
		stackedUnit = "percentage";
		quantityBar = 1;
		varQuantityInit = 100.0;
		varQuantityMin = 0.0;
		varQuantityMax = 100.0;
		weight = 780;
		itemSize[] = {2,3};
		fragility = 0.01;
		repairKitType = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\cleaning_kit_wood.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\cleaning_kit_wood_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\cleaning_kit_wood_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.8;
			};
		};
	};
	class SewingKit: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SewingKit0";
		descriptionShort = "$STR_CfgVehicles_SewingKit1";
		model = "\dz\gear\tools\sewing_kit.p3d";
		animClass = "Knife";
		ContinuousActions[] = {150,149};
		rotationFlags = 17;
		stackedUnit = "percentage";
		quantityBar = 1;
		varQuantityInit = 100.0;
		varQuantityMin = 0.0;
		varQuantityMax = 100.0;
		itemSize[] = {1,2};
		weight = 210;
		fragility = 0.01;
		repairKitType = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\sewing_kit.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\sewing_kit_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\sewing_kit_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class KnifeWhoosh1
				{
					soundSet = "StitchUpSelf_SoundSet";
					id = 201;
				};
			};
		};
	};
	class LeatherSewingKit: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_LeatherSewingKit0";
		descriptionShort = "$STR_CfgVehicles_LeatherSewingKit1";
		model = "\dz\gear\tools\leather_sewing_kit.p3d";
		animClass = "Knife";
		ContinuousActions[] = {150,149};
		rotationFlags = 17;
		stackedUnit = "percentage";
		quantityBar = 1;
		varQuantityInit = 100.0;
		varQuantityMin = 0.0;
		varQuantityMax = 100.0;
		weight = 1200;
		itemSize[] = {2,3};
		fragility = 0.01;
		repairKitType = 3;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\leather_sewing_kit.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\leather_sewing_kit_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\leather_sewing_kit_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class KnifeWhoosh1
				{
					soundSet = "StitchUpSelf_SoundSet";
					id = 201;
				};
			};
		};
	};
	class Handcuffs: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Handcuffs0";
		descriptionShort = "$STR_CfgVehicles_Handcuffs1";
		model = "\dz\gear\tools\Handcuffs.p3d";
		animClass = "Knife";
		ContinuousActions[] = {109,117};
		itemSize[] = {2,1};
		rotationFlags = 17;
		weight = 380;
		fragility = 0.01;
		OnRestrainChange = "HandcuffsLocked";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\Handcuff.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\Handcuff_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\Handcuff_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.8;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class handcuff_open
				{
					soundSet = "handcuff_open_SoundSet";
					id = 202;
				};
				class handcuff_struggle
				{
					soundSet = "handcuff_struggle_SoundSet";
					id = 203;
				};
			};
		};
	};
	class HandcuffsLocked: Inventory_Base
	{
		scope = 1;
		displayName = "$STR_CfgVehicles_HandcuffsLocked0";
		model = "\dz\gear\tools\Handcuffs_locked.p3d";
		animClass = "Knife";
		itemSize[] = {2,1};
		rotationFlags = 17;
		weight = 380;
		fragility = 0.01;
		OnRestrainChange = "Handcuffs";
		CanBeUnrestrainedBy[] = {"HandcuffKeys","3","Hacksaw","15","Pliers","25","Lockpick","10"};
		ContinuousActions[] = {116};
		StruggleLength = 20;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\Handcuff.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\Handcuff_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\Handcuff_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.8;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class handcuff_open
				{
					soundSet = "handcuff_open_SoundSet";
					id = 202;
				};
				class handcuff_struggle
				{
					soundSet = "handcuff_struggle_SoundSet";
					id = 203;
				};
			};
		};
	};
	class HandcuffKeys: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_HandcuffKeys0";
		descriptionShort = "$STR_CfgVehicles_HandcuffKeys1";
		model = "\dz\gear\tools\Handcuff_Keys.p3d";
		animClass = "Knife";
		ContinuousActions[] = {146};
		rotationFlags = 17;
		RestrainUnlockType = 0;
		weight = 4;
		itemSize[] = {1,1};
		fragility = 0.01;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\Handcuff_Key.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\Handcuff_Key_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\Handcuff_Key_destruct.rvmat"}}};
				};
			};
		};
	};
	class Cassette: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Cassette0";
		descriptionShort = "$STR_CfgVehicles_Cassette1";
		model = "\dz\gear\tools\cassette.p3d";
		rotationFlags = 17;
		weight = 80;
		absorbency = 0.5;
		itemSize[] = {2,1};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\cassette.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\cassette_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\cassette_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.8;
			};
		};
	};
	class Shovel: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Shovel0";
		descriptionShort = "$STR_CfgVehicles_Shovel1";
		model = "\dz\gear\tools\Shovel.p3d";
		rotationFlags = 17;
		autoQuickbar = 1;
		weight = 5500;
		itemSize[] = {2,8};
		fragility = 0.008;
		itemBehaviour = 2;
		inventorySlot = "Melee";
		suicideAnim = "pitchfork";
		SingleUseActions[] = {533,560,527};
		ContinuousActions[] = {193,195,184,104,158,156,163,198};
		build_action_type = 4;
		dismantle_action_type = 4;
		openItemSpillRange[] = {30,60};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\shovel.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\shovel_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\shovel_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeShovel";
				range = 1.8;
			};
			class Heavy
			{
				ammo = "MeleeShovel_Heavy";
				range = 1.8;
			};
			class Sprint
			{
				ammo = "MeleeShovel_Heavy";
				range = 3.7;
			};
		};
		class Horticulture
		{
			ToolAnim = "DIGGINGSHOVEL";
			DiggingTimeToComplete = 4.5;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpShovel_Light
				{
					soundSet = "pickUpShovelLight_SoundSet";
					id = 796;
				};
				class pickUpShovel
				{
					soundSet = "pickUpShovel_SoundSet";
					id = 797;
				};
			};
		};
	};
	class FieldShovel: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_FieldShovel0";
		descriptionShort = "$STR_CfgVehicles_FieldShovel1";
		model = "\dz\gear\tools\CSLA_Field_Shovel.p3d";
		rotationFlags = 17;
		autoQuickbar = 1;
		suicideAnim = "woodaxe";
		weight = 5500;
		itemSize[] = {2,5};
		fragility = 0.008;
		SingleUseActions[] = {533,527};
		ContinuousActions[] = {193,195,184,104,158,156,163,198};
		build_action_type = 4;
		dismantle_action_type = 4;
		openItemSpillRange[] = {30,60};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\CSLA_Field_Shovel.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\CSLA_Field_Shovel_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\CSLA_Field_Shovel_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeFieldShovel";
				range = 1.4;
			};
			class Heavy
			{
				ammo = "MeleeFieldShovel_Heavy";
				range = 1.4;
			};
			class Sprint
			{
				ammo = "MeleeFieldShovel_Heavy";
				range = 3.3;
			};
		};
		class Horticulture
		{
			ToolAnim = "DIGGINGSHOVEL";
			DiggingTimeToComplete = 5.0;
		};
	};
	class Crowbar: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Crowbar0";
		descriptionShort = "$STR_CfgVehicles_Crowbar1";
		model = "\dz\gear\tools\Crowbar.p3d";
		rotationFlags = 12;
		repairableWithKits[] = {5,4};
		repairCosts[] = {30.0,25.0};
		ContinuousActions[] = {195};
		build_action_type = 0;
		dismantle_action_type = 10;
		autoQuickbar = 1;
		weight = 4400;
		itemSize[] = {1,6};
		fragility = 0.001;
		itemBehaviour = 1;
		openItemSpillRange[] = {20,50};
		inventorySlot = "Melee";
		suicideAnim = "woodaxe";
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\Crowbar.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\Crowbar_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\Crowbar_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeCrowbar";
				range = 1.8;
			};
			class Heavy
			{
				ammo = "MeleeCrowbar_Heavy";
				range = 1.8;
			};
			class Sprint
			{
				ammo = "MeleeCrowbar_Heavy";
				range = 4.1;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpShovel_Light
				{
					soundSet = "pickUpShovelLight_SoundSet";
					id = 796;
				};
				class pickUpShovel
				{
					soundSet = "pickUpShovel_SoundSet";
					id = 797;
				};
				class Crowbar_loop
				{
					soundSet = "Crowbar_loop_SoundSet";
					id = 1119;
				};
				class Crowbar_end
				{
					soundSet = "Crowbar_end_SoundSet";
					id = 1120;
				};
			};
		};
	};
	class FireExtinguisher: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_FireExtinguisher0";
		descriptionShort = "$STR_CfgVehicles_FireExtinguisher1";
		model = "\dz\gear\tools\FireExtinguisher.p3d";
		SingleUseActions[] = {560};
		ContinuousActions[] = {217};
		rotationFlags = "17+								2";
		autoQuickbar = 1;
		weight = 7700;
		itemSize[] = {3,8};
		fragility = 0.001;
		itemBehaviour = 2;
		inventorySlot = "Melee";
		quantityBar = 1;
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		varQuantityInit = 6000.0;
		varQuantityMin = 0.0;
		varQuantityMax = 6000.0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\fire_extinguisher.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\fire_extinguisher_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\fire_extinguisher_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeFireExtinguisher";
				range = 1.4;
			};
			class Heavy
			{
				ammo = "MeleeFireExtinguisher_Heavy";
				range = 1.4;
			};
			class Sprint
			{
				ammo = "MeleeFireExtinguisher_Heavy";
				range = 3.3;
			};
		};
	};
	class Hammer: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Hammer0";
		descriptionShort = "$STR_CfgVehicles_Hammer1";
		model = "\dz\gear\tools\Hammer.p3d";
		SingleUseActions[] = {533};
		ContinuousActions[] = {168,193};
		build_action_type = 10;
		dismantle_action_type = 0;
		rotationFlags = 17;
		autoQuickbar = 1;
		weight = 940;
		itemSize[] = {2,3};
		fragility = 0.008;
		openItemSpillRange[] = {20,50};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\Hammer.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\Hammer_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\Hammer_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeHammer";
				range = 1.1;
			};
			class Heavy
			{
				ammo = "MeleeHammer_Heavy";
				range = 1.1;
			};
			class Sprint
			{
				ammo = "MeleeHammer_Heavy";
				range = 3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class WoodHammer_SoundSet
				{
					soundSet = "WoodHammer_SoundSet";
					id = 1116;
				};
			};
		};
	};
	class MeatTenderizer: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_MeatTenderizer0";
		descriptionShort = "$STR_CfgVehicles_MeatTenderizer1";
		model = "\dz\gear\tools\Meat_Tenderizer.p3d";
		rotationFlags = 17;
		SingleUseActions[] = {533};
		ContinuousActions[] = {193};
		build_action_type = 10;
		dismantle_action_type = 0;
		autoQuickbar = 1;
		weight = 350;
		itemSize[] = {2,3};
		fragility = 0.008;
		openItemSpillRange[] = {30,60};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\Meat_Tenderizer.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\Meat_Tenderizer_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\Meat_Tenderizer_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeMeatTenderizer";
				range = 1.2;
			};
			class Heavy
			{
				ammo = "MeleeMeatTenderizer_Heavy";
				range = 1.2;
			};
			class Sprint
			{
				ammo = "MeleeMeatTenderizer_Heavy";
				range = 3.3;
			};
		};
	};
	class Wrench: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Wrench0";
		descriptionShort = "$STR_CfgVehicles_Wrench1";
		model = "\dz\gear\tools\Wrench.p3d";
		rotationFlags = 17;
		autoQuickbar = 1;
		weight = 340;
		itemSize[] = {1,3};
		fragility = 0.001;
		openItemSpillRange[] = {20,40};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\wrench.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\wrench_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\wrench_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeWrench";
				range = 1.6;
			};
			class Heavy
			{
				ammo = "MeleeWrench_Heavy";
				range = 1.6;
			};
			class Sprint
			{
				ammo = "MeleeWrench_Heavy";
				range = 4.1;
			};
		};
	};
	class LugWrench: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_LugWrench0";
		descriptionShort = "$STR_CfgVehicles_LugWrench1";
		model = "\dz\gear\tools\Lug_wrench.p3d";
		rotationFlags = 17;
		autoQuickbar = 1;
		weight = 1600;
		itemSize[] = {1,5};
		fragility = 0.001;
		openItemSpillRange[] = {30,60};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\Lug_Wrench.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\Lug_Wrench_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\Lug_Wrench_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeWrench";
				range = 1.7;
			};
			class Heavy
			{
				ammo = "MeleeWrench_Heavy";
				range = 1.7;
			};
			class Sprint
			{
				ammo = "MeleeWrench_Heavy";
				range = 4.1;
			};
		};
	};
	class Pipe: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Pipe0";
		descriptionShort = "$STR_CfgVehicles_Pipe1";
		model = "\dz\gear\tools\metal_pipe.p3d";
		rotationFlags = 12;
		autoQuickbar = 1;
		isMeleeWeapon = 1;
		weight = 3200;
		itemSize[] = {1,6};
		fragility = 0.001;
		itemBehaviour = 1;
		inventorySlot = "Melee";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\metal_pipe.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\metal_pipe_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\metal_pipe_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeWrench";
				range = 1.7;
			};
			class Heavy
			{
				ammo = "MeleeWrench_Heavy";
				range = 1.7;
			};
			class Sprint
			{
				ammo = "MeleeWrench_Heavy";
				range = 4.1;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Attack_pipemetalhollow_Light1
				{
					soundSet = "Char_Attack_pipemetalhollow_light1_SoundSet";
					id = 811;
				};
				class Attack_pipemetalhollow_Light2
				{
					soundSet = "Char_Attack_pipemetalhollow_light2_SoundSet";
					id = 812;
				};
				class Attack_pipemetalhollow_Heavy1
				{
					soundSet = "Char_Attack_pipemetalhollow_heavy1_SoundSet";
					id = 813;
				};
				class Attack_pipemetalhollow_Heavy2
				{
					soundSet = "Char_Attack_pipemetalhollow_heavy2_SoundSet";
					id = 814;
				};
			};
		};
	};
	class Screwdriver: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Screwdriver0";
		descriptionShort = "$STR_CfgVehicles_Screwdriver1";
		model = "\dz\gear\tools\Screwdriver.p3d";
		animClass = "Knife";
		repairableWithKits[] = {5,4};
		repairCosts[] = {30.0,25.0};
		ContinuousActions[] = {146};
		rotationFlags = 17;
		autoQuickbar = 1;
		suicideAnim = "onehanded";
		RestrainUnlockType = 1;
		weight = 310;
		itemSize[] = {1,3};
		fragility = 0.008;
		openItemSpillRange[] = {20,40};
		action = "GestureMeleeBayonetStab";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\screwdriver.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\screwdriver_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\screwdriver_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeScrewdriver";
				range = 1.1;
			};
			class Heavy
			{
				ammo = "MeleeScrewdriver_Heavy";
				range = 1.1;
			};
			class Sprint
			{
				ammo = "MeleeScrewdriver_Heavy";
				range = 3.3;
			};
		};
	};
	class Sickle: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Sickle0";
		descriptionShort = "$STR_CfgVehicles_Sickle1";
		model = "\dz\gear\tools\sickle.p3d";
		repairableWithKits[] = {5,4};
		repairCosts[] = {30.0,25.0};
		ContinuousActions[] = {146,167};
		rotationFlags = 17;
		autoQuickbar = 1;
		suicideAnim = "woodaxe";
		canSkinBodies = 1;
		RestrainUnlockType = 1;
		weight = 550;
		itemSize[] = {4,3};
		openItemSpillRange[] = {10,30};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\sickle.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\sickle_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\sickle_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeSickle";
				range = 1.3;
			};
			class Heavy
			{
				ammo = "MeleeSickle_Heavy";
				range = 1.3;
			};
			class Sprint
			{
				ammo = "MeleeSickle_Heavy";
				range = 3.3;
			};
		};
	};
	class Hacksaw: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Hacksaw0";
		descriptionShort = "$STR_CfgVehicles_Hacksaw1";
		model = "\dz\gear\tools\hacksaw.p3d";
		action = "GestureMeleeBayonetStab";
		repairableWithKits[] = {5,4};
		repairCosts[] = {30.0,25.0};
		ContinuousActions[] = {146,167,183,110,209};
		itemInfo[] = {"Knife"};
		rotationFlags = 17;
		autoQuickbar = 1;
		RestrainUnlockType = 1;
		canSkinBodies = 1;
		weight = 800;
		itemSize[] = {4,2};
		fragility = 0.08;
		openItemSpillRange[] = {10,40};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\hacksaw.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\hacksaw_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\hacksaw_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeHacksaw";
				range = 1.2;
			};
			class Heavy
			{
				ammo = "MeleeHacksaw_Heavy";
				range = 1.2;
			};
			class Sprint
			{
				ammo = "MeleeHacksaw_Heavy";
				range = 3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class ChoppingTree
				{
					soundSet = "ChoppingTree_SoundSet";
					id = 415;
				};
				class animalSkinning_in
				{
					soundSet = "animalSkinning_in_SoundSet";
					id = 516;
				};
				class animalSkinning
				{
					soundSet = "animalSkinning_SoundSet";
					id = 517;
				};
				class animalSkinning_out
				{
					soundSet = "animalSkinning_out_SoundSet";
					id = 518;
				};
			};
		};
	};
	class KitchenKnife: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_KitchenKnife0";
		descriptionShort = "$STR_CfgVehicles_KitchenKnife1";
		model = "\dz\gear\tools\kitchenknife.p3d";
		animClass = "Knife";
		repairableWithKits[] = {5,4};
		repairCosts[] = {30.0,25.0};
		ContinuousActions[] = {178,146,154,167,197,177,199,153};
		itemInfo[] = {"Knife"};
		RestrainUnlockType = 1;
		rotationFlags = 17;
		autoQuickbar = 1;
		isMeleeWeapon = 1;
		suicideAnim = "onehanded";
		canSkinBodies = 1;
		weight = 170;
		itemSize[] = {1,3};
		openItemSpillRange[] = {0,20};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\hacksaw.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\hacksaw_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\hacksaw_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeKnife";
				range = 1.2;
			};
			class Heavy
			{
				ammo = "MeleeKnife_Heavy";
				range = 1.2;
			};
			class Sprint
			{
				ammo = "MeleeKnife_Heavy";
				range = 3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class ChoppingTree
				{
					soundSet = "ChoppingTree_SoundSet";
					id = 415;
				};
				class animalSkinning_in
				{
					soundSet = "animalSkinning_in_SoundSet";
					id = 516;
				};
				class animalSkinning
				{
					soundSet = "animalSkinning_SoundSet";
					id = 517;
				};
				class animalSkinning_out
				{
					soundSet = "animalSkinning_out_SoundSet";
					id = 518;
				};
			};
		};
	};
	class SteakKnife: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SteakKnife0";
		descriptionShort = "$STR_CfgVehicles_SteakKnife1";
		model = "\dz\gear\tools\steak_knife.p3d";
		animClass = "Knife";
		repairableWithKits[] = {5,4};
		repairCosts[] = {30.0,25.0};
		ContinuousActions[] = {178,146,154,167,197,177,199,153};
		itemInfo[] = {"Knife"};
		RestrainUnlockType = 1;
		rotationFlags = 17;
		autoQuickbar = 1;
		isMeleeWeapon = 1;
		suicideAnim = "onehanded";
		canSkinBodies = 1;
		weight = 90;
		itemSize[] = {1,2};
		openItemSpillRange[] = {0,20};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\small_steak_knife.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\small_steak_knife_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\small_steak_knife_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeKnife";
				range = 1.1;
			};
			class Heavy
			{
				ammo = "MeleeKnife_Heavy";
				range = 1.1;
			};
			class Sprint
			{
				ammo = "MeleeKnife_Heavy";
				range = 3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class ChoppingTree
				{
					soundSet = "ChoppingTree_SoundSet";
					id = 415;
				};
				class animalSkinning_in
				{
					soundSet = "animalSkinning_in_SoundSet";
					id = 516;
				};
				class animalSkinning
				{
					soundSet = "animalSkinning_SoundSet";
					id = 517;
				};
				class animalSkinning_out
				{
					soundSet = "animalSkinning_out_SoundSet";
					id = 518;
				};
			};
		};
	};
	class HayHook: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_HayHook0";
		descriptionShort = "$STR_CfgVehicles_HayHook1";
		model = "\dz\gear\tools\Hay_Hook.p3d";
		animClass = "Knife";
		repairableWithKits[] = {5,4};
		repairCosts[] = {30.0,25.0};
		ContinuousActions[] = {146,154};
		RestrainUnlockType = 1;
		rotationFlags = 1;
		autoQuickbar = 1;
		suicideAnim = "onehanded";
		canSkinBodies = 1;
		weight = 250;
		itemSize[] = {3,2};
		openItemSpillRange[] = {10,30};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\Hay_Hook.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\Hay_Hook_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\Hay_Hook_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeSickle";
				range = 1.2;
			};
			class Heavy
			{
				ammo = "MeleeSickle_Heavy";
				range = 1.2;
			};
			class Sprint
			{
				ammo = "MeleeSickle_Heavy";
				range = 3.3;
			};
		};
	};
	class StoneKnife: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_StoneKnife0";
		descriptionShort = "$STR_CfgVehicles_StoneKnife1";
		model = "\dz\gear\consumables\Stone_slice.p3d";
		ContinuousActions[] = {146,154,167,197};
		itemInfo[] = {"Knife"};
		repairableWithKits[] = {5,4};
		repairCosts[] = {30.0,25.0};
		rotationFlags = 17;
		RestrainUnlockType = 1;
		autoQuickbar = 1;
		suicideAnim = "onehanded";
		canSkinBodies = 1;
		weight = 260;
		itemSize[] = {1,2};
		openItemSpillRange[] = {10,30};
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\stone.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\stone_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\stone_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeStoneKnife";
				range = 1.1;
			};
			class Heavy
			{
				ammo = "MeleeStoneKnife_Heavy";
				range = 1.1;
			};
			class Sprint
			{
				ammo = "MeleeStoneKnife_Heavy";
				range = 3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class ChoppingTree
				{
					soundSet = "ChoppingTree_SoundSet";
					id = 415;
				};
				class animalSkinning_in
				{
					soundSet = "animalSkinning_in_SoundSet";
					id = 516;
				};
				class animalSkinning
				{
					soundSet = "animalSkinning_SoundSet";
					id = 517;
				};
				class animalSkinning_out
				{
					soundSet = "animalSkinning_out_SoundSet";
					id = 518;
				};
			};
		};
	};
	class Mace: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Mace0";
		descriptionShort = "$STR_CfgVehicles_Mace1";
		model = "\dz\gear\tools\Flanged_Mace.p3d";
		rotationFlags = 17;
		weight = 4100;
		itemSize[] = {2,4};
		fragility = 0.01;
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\Flanged_Mace.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\Flanged_Mace_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\Flanged_Mace_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeMeatTenderizer";
				range = 1.4;
			};
			class Heavy
			{
				ammo = "MeleeMeatTenderizer_Heavy";
				range = 1.4;
			};
			class Sprint
			{
				ammo = "MeleeMeatTenderizer_Heavy";
				range = 3.7;
			};
		};
	};
	class FarmingHoe: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_FarmingHoe0";
		descriptionShort = "$STR_CfgVehicles_FarmingHoe1";
		model = "\dz\gear\tools\Farming_Hoe.p3d";
		rotationFlags = 12;
		autoQuickbar = 1;
		weight = 5600;
		itemSize[] = {2,8};
		openItemSpillRange[] = {35,55};
		SingleUseActions[] = {560,527};
		ContinuousActions[] = {104,158,198};
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\Farming_Hoe.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\Farming_Hoe_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\Farming_Hoe_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeFarmingHoe";
				range = 1.5;
			};
			class Heavy
			{
				ammo = "MeleeFarmingHoe_Heavy";
				range = 1.5;
			};
			class Sprint
			{
				ammo = "MeleeFarmingHoe_Heavy";
				range = 4.1;
			};
		};
		class Horticulture
		{
			ToolAnim = "DIGGINGHOE";
			DiggingTimeToComplete = 4.0;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpShovel_Light
				{
					soundSet = "pickUpShovelLight_SoundSet";
					id = 796;
				};
				class pickUpShovel
				{
					soundSet = "pickUpShovel_SoundSet";
					id = 797;
				};
			};
		};
	};
	class ImprovisedFishingRod: FishingRod_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ImprovisedFishingRod0";
		descriptionShort = "$STR_CfgVehicles_ImprovisedFishingRod1";
		model = "\dz\gear\tools\ImprovisedFishingRod.p3d";
		rotationFlags = 17;
		autoQuickbar = 1;
		weight = 670;
		itemSize[] = {2,9};
		itemBehaviour = 2;
		absorbency = 0.8;
		lootCategory = "Crafted";
		attachments[] = {"bait"};
		energyResources[] = {{"power",0.1}};
		inventorySlot = "Melee";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\crafting\data\wooden_stick.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\crafting\data\wooden_stick_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\crafting\data\wooden_stick_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Fishing_in_SoundSet
				{
					soundSet = "Fishing_in_SoundSet";
					id = 201;
				};
				class Fishing_check_SoundSet
				{
					soundSet = "Fishing_check_SoundSet";
					id = 202;
				};
				class Fishing_cancel_SoundSet
				{
					soundSet = "Fishing_cancel_SoundSet";
					id = 203;
				};
				class FishingRod_extend_SoundSet
				{
					soundSet = "FishingRod_extend_SoundSet";
					id = 204;
				};
				class FishingRod_retract_SoundSet
				{
					soundSet = "FishingRod_retract_SoundSet";
					id = 205;
				};
				class Fishing_puddle_SoundSet
				{
					soundSet = "Fishing_puddle_SoundSet";
					id = 206;
				};
				class Fishing_splash_SoundSet
				{
					soundSet = "Fishing_splash_SoundSet";
					id = 207;
				};
				class Fishing_splash_small_SoundSet
				{
					soundSet = "Fishing_splash_small_SoundSet";
					id = 208;
				};
				class Fish_struggling_SoundSet
				{
					soundSet = "Fish_struggling_SoundSet";
					id = 209;
				};
			};
		};
	};
	class ObsoleteFishingRod: FishingRod_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ObsoleteFishingRod0";
		descriptionShort = "$STR_CfgVehicles_ObsoleteFishingRod1";
		model = "\dz\gear\crafting\Wooden_stick.p3d";
		rotationFlags = 17;
		autoQuickbar = 1;
		weight = 510;
		itemSize[] = {2,9};
		itemBehaviour = 2;
		absorbency = 0.8;
		lootCategory = "Crafted";
		attachments[] = {"bait"};
		energyResources[] = {{"power",0.15}};
		inventorySlot = "Melee";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\crafting\data\wooden_stick.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\crafting\data\wooden_stick_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\crafting\data\wooden_stick_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Fishing_in_SoundSet
				{
					soundSet = "Fishing_in_SoundSet";
					id = 201;
				};
				class Fishing_check_SoundSet
				{
					soundSet = "Fishing_check_SoundSet";
					id = 202;
				};
				class Fishing_cancel_SoundSet
				{
					soundSet = "Fishing_cancel_SoundSet";
					id = 203;
				};
				class FishingRod_extend_SoundSet
				{
					soundSet = "FishingRod_extend_SoundSet";
					id = 204;
				};
				class FishingRod_retract_SoundSet
				{
					soundSet = "FishingRod_retract_SoundSet";
					id = 205;
				};
				class Fishing_puddle_SoundSet
				{
					soundSet = "Fishing_puddle_SoundSet";
					id = 206;
				};
				class Fishing_splash_SoundSet
				{
					soundSet = "Fishing_splash_SoundSet";
					id = 207;
				};
				class Fishing_splash_small_SoundSet
				{
					soundSet = "Fishing_splash_small_SoundSet";
					id = 208;
				};
				class Fish_struggling_SoundSet
				{
					soundSet = "Fish_struggling_SoundSet";
					id = 209;
				};
			};
		};
	};
	class FishingRod: FishingRod_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_FishingRod0";
		descriptionShort = "$STR_CfgVehicles_FishingRod1";
		model = "\dz\gear\tools\fishing_rod.p3d";
		rotationFlags = 12;
		autoQuickbar = 1;
		weight = 910;
		itemSize[] = {2,5};
		absorbency = 0;
		attachments[] = {"bait"};
		energyResources[] = {{"power",0.15}};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\fishing_rod.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\fishing_rod_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\fishing_rod_destruct.rvmat"}}};
				};
			};
		};
		class AnimationSources
		{
			class CloseRod
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.001;
			};
			class OpenRod
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.001;
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeWoodBlunt";
				range = 1.8;
			};
			class Heavy
			{
				ammo = "MeleeWoodBlunt_Heavy";
				range = 1.8;
			};
			class Sprint
			{
				ammo = "MeleeWoodBlunt_Heavy";
				range = 3.7;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Fishing_in_SoundSet
				{
					soundSet = "Fishing_in_SoundSet";
					id = 201;
				};
				class Fishing_check_SoundSet
				{
					soundSet = "Fishing_check_SoundSet";
					id = 202;
				};
				class Fishing_cancel_SoundSet
				{
					soundSet = "Fishing_cancel_SoundSet";
					id = 203;
				};
				class FishingRod_extend_SoundSet
				{
					soundSet = "FishingRod_extend_SoundSet";
					id = 204;
				};
				class FishingRod_retract_SoundSet
				{
					soundSet = "FishingRod_retract_SoundSet";
					id = 205;
				};
				class Fishing_puddle_SoundSet
				{
					soundSet = "Fishing_puddle_SoundSet";
					id = 206;
				};
				class Fishing_splash_SoundSet
				{
					soundSet = "Fishing_splash_SoundSet";
					id = 207;
				};
				class Fishing_splash_small_SoundSet
				{
					soundSet = "Fishing_splash_small_SoundSet";
					id = 208;
				};
				class Fish_struggling_SoundSet
				{
					soundSet = "Fish_struggling_SoundSet";
					id = 209;
				};
			};
		};
	};
	class SledgeHammer: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SledgeHammer0";
		descriptionShort = "$STR_CfgVehicles_SledgeHammer1";
		model = "\dz\gear\tools\Sledge_Hammer.p3d";
		SingleUseActions[] = {560};
		ContinuousActions[] = {168,209};
		itemInfo[] = {"SledgeHammer"};
		rotationFlags = 12;
		autoQuickbar = 1;
		weight = 5000;
		itemSize[] = {2,6};
		itemBehaviour = 2;
		openItemSpillRange[] = {30,50};
		inventorySlot = "Melee";
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\Sledge_Hammer.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\Sledge_Hammer_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\Sledge_Hammer_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeSledgeHammer";
				range = 1.8;
			};
			class Heavy
			{
				ammo = "MeleeSledgeHammer_Heavy";
				range = 1.8;
			};
			class Sprint
			{
				ammo = "MeleeSledgeHammer_Heavy";
				range = 3.7;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpShovel_Light
				{
					soundSet = "pickUpShovelLight_SoundSet";
					id = 796;
				};
				class pickUpShovel
				{
					soundSet = "pickUpShovel_SoundSet";
					id = 797;
				};
				class SledgeWoodHammer_loop
				{
					soundSet = "SledgeWoodHammer_loop_SoundSet";
					id = 1117;
				};
				class SledgeWoodHammer_end
				{
					soundSet = "SledgeWoodHammer_end_SoundSet";
					id = 1118;
				};
			};
		};
	};
	class Iceaxe: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Iceaxe0";
		descriptionShort = "$STR_CfgVehicles_Iceaxe1";
		model = "\dz\gear\tools\Ice_Axe.p3d";
		rotationFlags = 17;
		repairableWithKits[] = {5,4};
		repairCosts[] = {30.0,25.0};
		autoQuickbar = 1;
		suicideAnim = "woodaxe";
		weight = 425;
		itemSize[] = {2,5};
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"dz\weapons\melee\blade\data\Pickaxe_co.paa"};
		SingleUseActions[] = {533,527};
		ContinuousActions[] = {104,158,168,198,193,195};
		build_action_type = 4;
		dismantle_action_type = 14;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\IceAxe.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\IceAxe_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\IceAxe_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeSickle";
				range = 1.4;
			};
			class Heavy
			{
				ammo = "MeleeSickle_Heavy";
				range = 1.4;
			};
			class Sprint
			{
				ammo = "MeleeSickle_Heavy";
				range = 3.3;
			};
		};
		class Horticulture
		{
			ToolAnim = "defaultSingle";
			DiggingTimeToComplete = 6.0;
		};
	};
	class Broom: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Broom0";
		descriptionShort = "$STR_CfgVehicles_Broom1";
		model = "\dz\gear\tools\broom.p3d";
		SingleUseActions[] = {560};
		rotationFlags = 12;
		autoQuickbar = 1;
		weight = 3900;
		itemSize[] = {2,10};
		openItemSpillRange[] = {40,70};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\broom.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\broom_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\broom_destruct.rvmat"}}};
				};
			};
		};
	};
	class Paddle: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Paddle0";
		descriptionShort = "$STR_CfgVehicles_Paddle1";
		model = "\dz\gear\tools\canoe_paddle.p3d";
		rotationFlags = 12;
		SingleUseActions[] = {560};
		autoQuickbar = 1;
		weight = 800;
		itemSize[] = {2,10};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\Old_Canoe_Paddle.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\Old_Canoe_Paddle_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\Old_Canoe_Paddle_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeWoodBlunt";
				range = 1.6;
			};
			class Heavy
			{
				ammo = "MeleeWoodBlunt_Heavy";
				range = 1.6;
			};
			class Sprint
			{
				ammo = "MeleeWoodBlunt_Heavy";
				range = 3.7;
			};
		};
	};
	class ElectronicRepairKit: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ElectronicRepairKit0";
		descriptionShort = "$STR_CfgVehicles_ElectronicRepairKit1";
		model = "\dz\gear\tools\electronicCase.p3d";
		animClass = "Knife";
		rotationFlags = 17;
		stackedUnit = "percentage";
		quantityBar = 1;
		varQuantityInit = 100.0;
		varQuantityMin = 0.0;
		varQuantityMax = 100.0;
		weight = 1000;
		itemSize[] = {2,3};
		repairKitType = 7;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\electronicCase.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\electronicCase_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\electronicCase_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class KnifeWhoosh1
				{
					soundSet = "StitchUpSelf_SoundSet";
					id = 201;
				};
			};
		};
	};
	class EpoxyPutty: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_EpoxyPutty0";
		descriptionShort = "$STR_CfgVehicles_EpoxyPutty1";
		model = "\dz\gear\tools\epoxy_putty.p3d";
		animClass = "Knife";
		rotationFlags = 17;
		stackedUnit = "percentage";
		quantityBar = 1;
		varQuantityInit = 100.0;
		varQuantityMin = 0.0;
		varQuantityMax = 100.0;
		weight = 200;
		itemSize[] = {1,2};
		repairKitType = 8;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\epoxy_putty.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\epoxy_putty_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\epoxy_putty_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class KnifeWhoosh1
				{
					soundSet = "StitchUpSelf_SoundSet";
					id = 201;
				};
			};
		};
	};
	class Whetstone: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Whetstone0";
		descriptionShort = "$STR_CfgVehicles_Whetstone1";
		model = "\dz\gear\tools\whetstone.p3d";
		animClass = "Knife";
		rotationFlags = 17;
		stackedUnit = "percentage";
		quantityBar = 1;
		varQuantityInit = 100.0;
		varQuantityMin = 0.0;
		varQuantityMax = 100.0;
		weight = 200;
		itemSize[] = {1,2};
		repairKitType = 4;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\gear\tools\data\whetstone.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\tools\data\whetstone_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\tools\data\whetstone_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class KnifeWhoosh1
				{
					soundSet = "StitchUpSelf_SoundSet";
					id = 201;
				};
			};
		};
	};
	class DoorTestCamera: Inventory_Base
	{
		scope = 2;
		displayName = "DoorTestCamera";
		descriptionShort = "DoorTestCamera";
		model = "\dz\gear\tools\DoorCheck120x220-1cm.p3d";
		animClass = "Knife";
		ContinuousActions[] = {150,149};
		quantityBar = 1;
		itemSize[] = {2,1};
		weight = 210;
		fragility = 0.01;
		lootCategory = "Tools";
		lootTag[] = {"Civilian"};
	};
};
