////////////////////////////////////////////////////////////////////
//DeRap: gear_camping\config.bin
//Produced from mikero's Dos Tools Dll version 6.44
//'now' is Thu Dec 27 16:33:36 2018 : 'file' last modified on Wed Dec 12 08:27:38 2018
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
	class DZ_Gear_Camping
	{
		units[] = {"TentMedium_Packed","TentMedium_Pitched"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class RecipeToolOnTool;
class CfgRecipes
{
	class CraftFenceBase
	{
		name = "Craft Fence";
		tools[] = {"Consumable_WoodenPlanks"};
		condition = "quantity _tool1 > 2";
		results[] = {"Fence"};
		action = "_tool1 addQuantity -2; if(quantity _tool1 < 1)then{deleteVehicle _tool1};[_owner,format['I have made the %1.',displayName _result1],'colorAction'] call fnc_playerMessage;";
	};
	class CombinePlanks
	{
		name = "Stack planks";
		tools[] = {"Camping_Plank","Camping_Plank"};
		condition = "quantity _tool2 < maxQuantity _tool2";
		action = "call player_combineQuantity;";
	};
	class SplitPlanks
	{
		name = "Split planks";
		tools[] = {"Camping_Plank"};
		condition = "(quantity _tool1) > 1";
		action = "call player_splitQuantity;";
	};
	class CraftCamoNetShelter: RecipeToolOnTool
	{
		name = "Craft Camo net shelter";
		tools[] = {"CamoNet","LongWoodenStick"};
		condition = "damage _tool1 < 1  &&  damage _tool2 < 1";
		results[] = {"CamoNetShelter"};
		action = "_result1 setDamage (damage _tool1 + damage _tool2 )/2;  _tool2 addQuantity -1;  if (quantity _tool2 < 1) then {deleteVehicle _tool2};  deleteVehicle _tool1;  [_owner,format['I have made a Camo net shelter.',displayName _result1],'colorAction'] call fnc_playerMessage;";
	};
	class DecraftCamoNetShelter
	{
		name = "Break down into wooden stick and Camo net";
		condition = "_owner getVariable ['isUsingSomething',0] == 0";
		material[] = {"CamoNetShelter"};
		results[] = {"CamoNet","LongWoodenStick"};
		action = "_result1 setQuantity 2;  _result1 setdamage (damage _material1); _result2 setQuantity 1;  _result2 setdamage (damage _material1); [_owner,format['I have broken down the %1.',displayName _material1],'colorAction'] call fnc_playerMessage";
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class WorldContainer_Base;
	class HouseNoDestruct;
	class Static;
	class MediumTent: Container_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_MediumTent0";
		descriptionShort = "$STR_CfgVehicles_MediumTent1";
		model = "\DZ\gear\camping\MediumTent.p3d";
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		hiddenSelections[] = {"xlights_glass_r","xlights_glass_g","xlights_glass_b","xlights_glass_y"};
		hiddenSelectionsTextures[] = {};
		hiddenSelectionsMaterials[] = {};
		openable = 0;
		carveNavmesh = 1;
		itemSize[] = {8,4};
		itemsCargoSize[] = {10,20};
		itemBehaviour = 2;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		attachments[] = {"CamoNet","Lights"};
		SingleUseActions[] = {527};
		InteractActions[] = {1021,1022};
		ContinuousActions[] = {231};
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\tent_medium_pitched.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\camping\data\tent_medium_pitched_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\camping\data\tent_medium_pitched_destruct.rvmat"}}};
				};
			};
		};
		class PointLights
		{
			class PointLight
			{
				color[] = {1.0,1.0,1.0,0.05};
				ambient[] = {0.01,0.01,0.01,0.01};
				position = "light";
				hitpoint = "bulb";
				selection = "bulb";
				size = 0;
				radius = 5;
				brightness = 0.001;
				dayLight = 1;
				heatHazeRadius = 0.0;
				heatHazePower = 0.0;
				fireEffect = 0;
				fireEffectOctaves = 0;
				fireEffectPersistence = 0;
				fireEffectFract = 0;
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class CamoNet
			{
				name = "$STR_attachment_camonet0";
				description = "";
				attachmentSlots[] = {"CamoNet"};
				icon = "missing";
				view_index = 1;
			};
			class XmasLights
			{
				name = "$STR_attachment_XmasLights0";
				description = "";
				attachmentSlots[] = {"Lights"};
				icon = "missing";
				view_index = 1;
			};
		};
		class AnimationSources
		{
			class Body
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class CamoNet
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Inventory
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class EntranceO
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class EntranceC
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Xlights
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_r
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_g
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_b
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_y
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Cord_folded
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Cord_plugged
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpTentLight_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpTent_SoundSet";
					id = 797;
				};
			};
		};
	};
	class MediumTentPlacing: MediumTent
	{
		model = "\DZ\gear\camping\MediumTentPlacing.p3d";
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\camping\data\tent_medium_pitched_b_co.tga"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\tent_medium_pitched.rvmat"};
		hologramMaterial = "tent_medium";
		hologramMaterialPath = "dz\gear\camping\data";
		class AnimationSources
		{
			class Placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
	class MediumTentClutterCutter: Static
	{
		scope = 1;
		model = "\DZ\gear\camping\MediumTentClutterCutter.p3d";
		displayName = "$STR_CfgVehicles_ClutterCutter6x60";
		icon = "";
		simulation = "thing";
		nameSound = "";
		vehicleClass = "Misc";
		transportFuel = 0;
		mapSize = 0.7;
		accuracy = 0.2;
		cost = 0;
		armor = 200000;
		destrType = "DestructNo";
	};
	class LargeTent: Container_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_LargeTent0";
		descriptionShort = "$STR_CfgVehicles_LargeTent1";
		model = "\DZ\gear\camping\LargeTent.p3d";
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		hiddenSelections[] = {"xlights_glass_r","xlights_glass_g","xlights_glass_b","xlights_glass_y"};
		hiddenSelectionsTextures[] = {};
		hiddenSelectionsMaterials[] = {};
		openable = 0;
		carveNavmesh = 1;
		itemSize[] = {10,4};
		itemsCargoSize[] = {10,40};
		itemBehaviour = 2;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		attachments[] = {"CamoNet","Lights"};
		SingleUseActions[] = {527};
		InteractActions[] = {1021,1022};
		ContinuousActions[] = {231};
		minPlacingDist = 10;
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\large_tent.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\camping\data\large_tent_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\camping\data\large_tent_destruct.rvmat"}}};
				};
			};
		};
		class PointLights
		{
			class PointLight
			{
				color[] = {1.0,1.0,1.0,0.05};
				ambient[] = {0.01,0.01,0.01,0.01};
				position = "light";
				hitpoint = "bulb";
				selection = "bulb";
				size = 0;
				radius = 5;
				brightness = 0.001;
				dayLight = 1;
				heatHazeRadius = 0.0;
				heatHazePower = 0.0;
				fireEffect = 0;
				fireEffectOctaves = 0;
				fireEffectPersistence = 0;
				fireEffectFract = 0;
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class CamoNet
			{
				name = "$STR_attachment_camonet0";
				description = "";
				attachmentSlots[] = {"CamoNet"};
				icon = "missing";
				view_index = 1;
			};
			class XmasLights
			{
				name = "$STR_attachment_XmasLights0";
				description = "";
				attachmentSlots[] = {"Lights"};
				icon = "missing";
				view_index = 1;
			};
		};
		class AnimationSources
		{
			class Body
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class CamoNet
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Inventory
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class EntranceO
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class EntranceC
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window1O
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window2O
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window3O
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window4O
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window5O
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window6O
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window7O
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window1C
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window2C
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window3C
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window4C
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window5C
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window6C
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window7C
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Xlights
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_r
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_g
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_b
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_y
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Cord_folded
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Cord_plugged
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpTentLight_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpTent_SoundSet";
					id = 797;
				};
			};
		};
	};
	class LargeTentPlacing: LargeTent
	{
		model = "\DZ\gear\camping\LargeTentPlacing.p3d";
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\camping\data\large_tent_co.tga"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\large_tent.rvmat"};
		hologramMaterial = "large_tent";
		hologramMaterialPath = "dz\gear\camping\data";
		class AnimationSources
		{
			class Placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
	class LargeTentClutterCutter: Static
	{
		scope = 1;
		model = "\DZ\gear\camping\LargeTentClutterCutter.p3d";
		displayName = "$STR_CfgVehicles_ClutterCutter6x60";
		icon = "";
		simulation = "thing";
		nameSound = "";
		vehicleClass = "Misc";
		transportFuel = 0;
		mapSize = 0.7;
		accuracy = 0.2;
		cost = 0;
		armor = 200000;
		destrType = "DestructNo";
	};
	class CarTent: Container_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CarTent0";
		descriptionShort = "$STR_CfgVehicles_CarTent1";
		model = "\DZ\gear\camping\CarTent.p3d";
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		hiddenSelections[] = {"xlights_glass_r","xlights_glass_g","xlights_glass_b","xlights_glass_y"};
		hiddenSelectionsTextures[] = {};
		hiddenSelectionsMaterials[] = {};
		openable = 0;
		carveNavmesh = 1;
		itemSize[] = {10,5};
		itemsCargoSize[] = {10,50};
		itemBehaviour = 0;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		attachments[] = {"CamoNet","Lights"};
		SingleUseActions[] = {527};
		InteractActions[] = {1021,1022};
		ContinuousActions[] = {231};
		minPlacingDist = 10;
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\car_tent_packed.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\camping\data\car_tent_packed_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\camping\data\car_tent_packed_destruct.rvmat"}}};
				};
			};
		};
		class PointLights
		{
			class PointLight
			{
				color[] = {1.0,1.0,1.0,0.05};
				ambient[] = {0.01,0.01,0.01,0.01};
				position = "light";
				hitpoint = "bulb";
				selection = "bulb";
				size = 0;
				radius = 5;
				brightness = 0.001;
				dayLight = 1;
				heatHazeRadius = 0.0;
				heatHazePower = 0.0;
				fireEffect = 0;
				fireEffectOctaves = 0;
				fireEffectPersistence = 0;
				fireEffectFract = 0;
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class CamoNet
			{
				name = "$STR_attachment_camonet0";
				description = "";
				attachmentSlots[] = {"CamoNet"};
				icon = "missing";
				view_index = 1;
			};
			class XmasLights
			{
				name = "$STR_attachment_XmasLights0";
				description = "";
				attachmentSlots[] = {"Lights"};
				icon = "missing";
				view_index = 1;
			};
		};
		class AnimationSources
		{
			class Body
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class CamoNet
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Inventory
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class EntranceO
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class EntranceC
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Xlights
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_r
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_g
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_b
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_y
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Cord_folded
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Cord_plugged
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpTentLight_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpTent_SoundSet";
					id = 797;
				};
			};
		};
	};
	class CarTentPlacing: CarTent
	{
		model = "\DZ\gear\camping\CarTentPlacing.p3d";
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\camping\data\car_tent_co.tga"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\car_tent.rvmat"};
		hologramMaterial = "car_tent";
		hologramMaterialPath = "dz\gear\camping\data";
		class AnimationSources
		{
			class Placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
	class PartyTent: Container_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PartyTent0";
		descriptionShort = "$STR_CfgVehicles_PartyTent1";
		model = "\DZ\gear\camping\party_tent.p3d";
		overrideDrawArea = "3.0";
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {""};
		hiddenSelectionsMaterials[] = {""};
		hologramMaterial = "party_tent";
		hologramMaterialPath = "dz\gear\camping\data";
		openable = 0;
		carveNavmesh = 1;
		itemSize[] = {9,4};
		itemsCargoSize[] = {10,30};
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		attachments[] = {"CamoNet"};
		SingleUseActions[] = {527};
		InteractActions[] = {1022};
		ContinuousActions[] = {231};
		minPlacingDist = 10;
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\tent_medium_pitched.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\camping\data\tent_medium_pitched_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\camping\data\tent_medium_pitched_destruct.rvmat"}}};
				};
			};
		};
		class AnimationSources
		{
			class camonet
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class inventory
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpTentLight_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpTent_SoundSet";
					id = 797;
				};
			};
		};
	};
	class ImprovisedShelterPitched: WorldContainer_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ImprovisedShelterPitched0";
		descriptionShort = "$STR_CfgVehicles_ImprovisedShelterPitched1";
		model = "\DZ\gear\camping\improvised_tent_01.p3d";
		hiddenSelections[] = {"xlights_glass_r","xlights_glass_g","xlights_glass_b","xlights_glass_y"};
		hiddenSelectionsTextures[] = {};
		hiddenSelectionsMaterials[] = {};
		openable = 0;
		itemSize[] = {2,6};
		itemsCargoSize[] = {3,2};
		lootCategory = "Crafted";
		overrideDrawArea = "3.0";
		carveNavmesh = 1;
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		attachments[] = {"CamoNet","Lights"};
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\car_tent_packed.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\camping\data\car_tent_packed_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\camping\data\car_tent_packed_destruct.rvmat"}}};
				};
			};
		};
		class PointLights
		{
			class PointLight
			{
				color[] = {1.0,1.0,1.0,0.05};
				ambient[] = {0.01,0.01,0.01,0.01};
				position = "light";
				hitpoint = "bulb";
				selection = "bulb";
				size = 0;
				radius = 5;
				brightness = 0.001;
				dayLight = 1;
				heatHazeRadius = 0.0;
				heatHazePower = 0.0;
				fireEffect = 0;
				fireEffectOctaves = 0;
				fireEffectPersistence = 0;
				fireEffectFract = 0;
			};
		};
		class AnimationSources
		{
			class xlights
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class xlights_glass_r
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class xlights_glass_g
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class xlights_glass_b
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class xlights_glass_y
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class cord_folded
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class cord_plugged
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class camonet
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
		};
	};
	class AdvancedImprovisedShelterPitched: WorldContainer_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AdvancedImprovisedShelterPitched0";
		descriptionShort = "$STR_CfgVehicles_AdvancedImprovisedShelterPitched1";
		model = "\DZ\gear\camping\improvised_tent_02.p3d";
		hiddenSelections[] = {"xlights_glass_r","xlights_glass_g","xlights_glass_b","xlights_glass_y"};
		hiddenSelectionsTextures[] = {};
		hiddenSelectionsMaterials[] = {};
		openable = 0;
		itemSize[] = {2,6};
		itemsCargoSize[] = {5,2};
		lootCategory = "Crafted";
		overrideDrawArea = "3.0";
		carveNavmesh = 1;
		physLayer = "item_large";
		placement = "ForceSlopeOnTerrain";
		attachments[] = {"CamoNet","Lights"};
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\car_tent_packed.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\camping\data\car_tent_packed_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\camping\data\car_tent_packed_destruct.rvmat"}}};
				};
			};
		};
		class PointLights
		{
			class PointLight
			{
				color[] = {1.0,1.0,1.0,0.05};
				ambient[] = {0.01,0.01,0.01,0.01};
				position = "light";
				hitpoint = "bulb";
				selection = "bulb";
				size = 0;
				radius = 5;
				brightness = 0.001;
				dayLight = 1;
				heatHazeRadius = 0.0;
				heatHazePower = 0.0;
				fireEffect = 0;
				fireEffectOctaves = 0;
				fireEffectPersistence = 0;
				fireEffectFract = 0;
			};
		};
		class AnimationSources
		{
			class xlights
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class xlights_glass_r
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class xlights_glass_g
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class xlights_glass_b
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class xlights_glass_y
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class cord_folded
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class cord_plugged
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class camonet
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
		};
	};
	class CamoNetShelter: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CamoNetShelter0";
		descriptionShort = "$STR_CfgVehicles_CamoNetShelter1";
		model = "\DZ\gear\camping\camo_net_shelter.p3d";
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		lootCategory = "Crafted";
		weight = 10000;
		itemSize[] = {5,2};
		minPlacingDist = 12;
		carveNavmesh = 1;
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\car_tent.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\camping\data\car_tent_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\camping\data\car_tent_destruct.rvmat"}}};
				};
			};
		};
	};
	class FenceKit: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_FenceKit0";
		descriptionShort = "$STR_CfgVehicles_FenceKit1";
		model = "\DZ\gear\camping\fence_kit.p3d";
		SingleUseActions[] = {527};
		ContinuousActions[] = {231};
		rotationFlags = 17;
		itemSize[] = {1,5};
		weight = 280;
		itemBehaviour = 1;
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Inventory: AnimSourceHidden{};
			class Placing: AnimSourceHidden{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class crafting_1
				{
					soundSet = "FenceKit_crafting_1_SoundSet";
					id = 1111;
				};
				class crafting_2
				{
					soundSet = "FenceKit_crafting_2_SoundSet";
					id = 1112;
				};
				class crafting_3
				{
					soundSet = "FenceKit_crafting_3_SoundSet";
					id = 1113;
				};
				class crafting_4
				{
					soundSet = "FenceKit_crafting_4_SoundSet";
					id = 1114;
				};
				class crafting_5
				{
					soundSet = "FenceKit_crafting_5_SoundSet";
					id = 1115;
				};
			};
		};
	};
	class FenceKitPlacing: FenceKit
	{
		scope = 2;
		model = "\DZ\gear\camping\fence_kit_placing.p3d";
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\consumables\data\pile_of_planks_co.tga"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\fence_pile_of_planks.rvmat"};
		hologramMaterial = "tent_medium";
		hologramMaterialPath = "dz\gear\camping\data";
		slopeLimit = 0.25;
	};
	class WatchtowerKit: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_WatchtowerKit0";
		descriptionShort = "$STR_CfgVehicles_WatchtowerKit1";
		model = "\DZ\gear\camping\watchtower_kit.p3d";
		SingleUseActions[] = {527};
		ContinuousActions[] = {231};
		rotationFlags = 17;
		itemSize[] = {1,5};
		weight = 280;
		itemBehaviour = 1;
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Inventory: AnimSourceHidden{};
			class Placing: AnimSourceHidden{};
		};
	};
	class WatchtowerKitPlacing: WatchtowerKit
	{
		scope = 2;
		model = "\DZ\gear\camping\watchtower_kit_placing.p3d";
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\consumables\data\pile_of_planks_co.tga"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\fence_pile_of_planks.rvmat"};
		hologramMaterial = "tent_medium";
		hologramMaterialPath = "dz\gear\camping\data";
		slopeLimit = 0.25;
	};
	class Fence: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Fence0";
		descriptionShort = "$STR_CfgVehicles_Fence1";
		model = "\DZ\gear\camping\fence.p3d";
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		SingleUseActions[] = {527};
		ContinuousActions[] = {155,239};
		InteractActions[] = {1051};
		armAction = "Disarm";
		handheld = "false";
		lootCategory = "Crafted";
		carveNavmesh = 1;
		weight = 3000;
		itemSize[] = {2,3};
		useEntityHierarchy = "true";
		physLayer = "item_large";
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					Health = 0;
					Blood = 0;
					Shock = 0;
				};
			};
		};
		attachments[] = {"Wall_Barbedwire_1","Wall_Barbedwire_2","Wall_Camonet","Att_CombinationLock","Material_Nails","Material_WoodenPlanks","Material_MetalSheets","Material_WoodenLogs","Material_MetalWire"};
		class GUIInventoryAttachmentsProps
		{
			class Base
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Base";
				description = "";
				attachmentSlots[] = {"Material_WoodenLogs"};
				icon = "missing";
				selection = "wall";
			};
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = {"Wall_Camonet","Wall_Barbedwire_1","Wall_Barbedwire_2","Att_CombinationLock"};
				icon = "missing";
				selection = "wall";
			};
			class Material
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Materials";
				description = "";
				attachmentSlots[] = {"Material_Nails","Material_WoodenPlanks","Material_MetalSheets","Material_MetalWire"};
				icon = "missing";
				selection = "wall";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class AnimRotate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Wall_Interact_Rotate: AnimRotate{};
			class Wall_Barbedwire_Mounted_Rotate: AnimRotate{};
			class Wall_Camonet_Rotate: AnimRotate{};
			class Wall_Gate_Rotate: AnimRotate{};
			class Wall_Base_Down_Rotate: AnimRotate{};
			class Wall_Base_Up_Rotate: AnimRotate{};
			class Wall_Wood_Down_Rotate: AnimRotate{};
			class Wall_Wood_Up_Rotate: AnimRotate{};
			class Wall_Metal_Down_Rotate: AnimRotate{};
			class Wall_Metal_Up_Rotate: AnimRotate{};
			class Material_WoodenLogs: AnimSourceHidden{};
			class Material_MetalWire: AnimSourceHidden{};
			class Wall_Barbedwire_1: AnimSourceHidden{};
			class Wall_Barbedwire_1_Mounted: AnimSourceHidden{};
			class Wall_Barbedwire_2: AnimSourceHidden{};
			class Wall_Barbedwire_2_Mounted: AnimSourceHidden{};
			class Wall_Camonet: AnimSourceHidden{};
			class Deployed: AnimSourceHidden{};
			class Base: AnimSourceHidden{};
			class Wall_Platform: AnimSourceHidden{};
			class Wall_Platform_Stairs_Left: AnimSourceHidden{};
			class Wall_Platform_Stairs_Right: AnimSourceHidden{};
			class Wall_Gate: AnimSourceHidden{};
			class Wall_Base_Down: AnimSourceHidden{};
			class Wall_Base_Up: AnimSourceHidden{};
			class Wall_Metal_Down: AnimSourceHidden{};
			class Wall_Metal_Up: AnimSourceHidden{};
			class Wall_Wood_Down: AnimSourceHidden{};
			class Wall_Wood_Up: AnimSourceHidden{};
		};
		class Construction
		{
			class wall
			{
				class base
				{
					name = "$STR_CfgVehicles_Construction_Part_Base";
					is_base = 1;
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 4;
					dismantle_action_type = 4;
					material_type = 1;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_WoodenLogs";
							quantity = 2;
							lockable = 1;
						};
					};
				};
				class wall_platform
				{
					name = "$STR_CfgVehicles_Construction_Part_Platform";
					required_parts[] = {"base"};
					conflicted_parts[] = {"wall_gate"};
					collision_data[] = {"wall_platform_min","wall_platform_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 3;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 15;
						};
					};
				};
				class wall_platform_stairs_left
				{
					name = "$STR_CfgVehicles_Construction_Part_Platform_Stairs_Left";
					required_parts[] = {"wall_platform"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 3;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 8;
						};
					};
				};
				class wall_platform_stairs_right
				{
					name = "$STR_CfgVehicles_Construction_Part_Platform_Stairs_Right";
					required_parts[] = {"wall_platform"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 3;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 8;
						};
					};
				};
				class wall_gate
				{
					name = "$STR_CfgVehicles_Construction_Part_Gate";
					is_gate = 1;
					required_parts[] = {"base","wall_base_down","wall_base_up"};
					conflicted_parts[] = {"wall_platform"};
					collision_data[] = {};
					build_action_type = 1;
					dismantle_action_type = 1;
					material_type = 5;
					class Materials
					{
						class Material1
						{
							type = "MetalWire";
							slot_name = "Material_MetalWire";
							quantity = -1;
							lockable = 1;
						};
					};
				};
				class wall_base_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Down";
					required_parts[] = {"base"};
					conflicted_parts[] = {};
					collision_data[] = {"wall_down_min","wall_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 8;
						};
					};
				};
				class wall_wood_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Down";
					required_parts[] = {"wall_base_down"};
					conflicted_parts[] = {"wall_metal_down"};
					collision_data[] = {"wall_down_min","wall_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 10;
						};
					};
				};
				class wall_metal_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Down";
					required_parts[] = {"wall_base_down"};
					conflicted_parts[] = {"wall_wood_down"};
					collision_data[] = {"wall_down_min","wall_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 12;
						};
					};
				};
				class wall_base_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Up";
					required_parts[] = {"base"};
					conflicted_parts[] = {};
					collision_data[] = {"wall_up_min","wall_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 8;
						};
					};
				};
				class wall_wood_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Up";
					required_parts[] = {"wall_base_up"};
					conflicted_parts[] = {"wall_metal_up"};
					collision_data[] = {"wall_up_min","wall_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 10;
						};
					};
				};
				class wall_metal_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Up";
					required_parts[] = {"wall_base_up"};
					conflicted_parts[] = {"wall_wood_up"};
					collision_data[] = {"wall_up_min","wall_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 12;
						};
					};
				};
			};
		};
		class PointLights
		{
			class PointLight
			{
				color[] = {1.0,1.0,1.0,0.05};
				ambient[] = {0.01,0.01,0.01,0.01};
				position = "light";
				hitpoint = "bulb";
				selection = "bulb";
				size = 0;
				radius = 5;
				brightness = 0.001;
				dayLight = 1;
				heatHazeRadius = 0.0;
				heatHazePower = 0.0;
				fireEffect = 0;
				fireEffectOctaves = 0;
				fireEffectPersistence = 0;
				fireEffectFract = 0;
			};
		};
	};
	class Watchtower: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Watchtower0";
		descriptionShort = "$STR_CfgVehicles_Watchtower1";
		model = "\DZ\gear\camping\watchtower.p3d";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		SingleUseActions[] = {527};
		ContinuousActions[] = {155,239};
		lootCategory = "Crafted";
		carveNavmesh = 1;
		weight = 60000;
		itemSize[] = {6,6};
		useEntityHierarchy = "true";
		physLayer = "item_large";
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					Health = 0;
					Blood = 0;
					Shock = 0;
				};
			};
		};
		attachments[] = {"Level_1_Wall_1_Barbedwire_1","Level_1_Wall_1_Barbedwire_2","Level_1_Wall_2_Barbedwire_1","Level_1_Wall_2_Barbedwire_2","Level_1_Wall_3_Barbedwire_1","Level_1_Wall_3_Barbedwire_2","Level_1_Wall_1_Camonet","Level_1_Wall_2_Camonet","Level_1_Wall_3_Camonet","Level_2_Wall_1_Camonet","Level_2_Wall_2_Camonet","Level_2_Wall_3_Camonet","Level_3_Wall_1_Camonet","Level_3_Wall_2_Camonet","Level_3_Wall_3_Camonet","Material_L1_WoodenLogs","Material_L2_WoodenLogs","Material_L3_WoodenLogs","Material_L1_Nails","Material_L1W1_Nails","Material_L1W2_Nails","Material_L1W3_Nails","Material_L2_Nails","Material_L2W1_Nails","Material_L2W2_Nails","Material_L2W3_Nails","Material_L3_Nails","Material_L3W1_Nails","Material_L3W2_Nails","Material_L3W3_Nails","Material_L1_WoodenPlanks","Material_L1W1_WoodenPlanks","Material_L1W2_WoodenPlanks","Material_L1W3_WoodenPlanks","Material_L2_WoodenPlanks","Material_L2W1_WoodenPlanks","Material_L2W2_WoodenPlanks","Material_L2W3_WoodenPlanks","Material_L3_WoodenPlanks","Material_L3W1_WoodenPlanks","Material_L3W2_WoodenPlanks","Material_L3W3_WoodenPlanks","Material_L3_MetalSheets","Material_L1W1_MetalSheets","Material_L1W2_MetalSheets","Material_L1W3_MetalSheets","Material_L2W1_MetalSheets","Material_L2W2_MetalSheets","Material_L2W3_MetalSheets","Material_L3W1_MetalSheets","Material_L3W2_MetalSheets","Material_L3W3_MetalSheets"};
		class GUIInventoryAttachmentsProps
		{
			class Level_1
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_1_Base";
				description = "";
				attachmentSlots[] = {"Material_L1_WoodenLogs","Material_L1_Nails","Material_L1_WoodenPlanks"};
				icon = "missing";
				selection = "level_1";
			};
			class Level_1_Wall_1
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_1_Wall_1";
				description = "";
				attachmentSlots[] = {"Material_L1W1_Nails","Material_L1W1_WoodenPlanks","Material_L1W1_MetalSheets","Level_1_Wall_1_Camonet","Level_1_Wall_1_Barbedwire_1","Level_1_Wall_1_Barbedwire_2"};
				icon = "missing";
				selection = "level_1_wall_1";
			};
			class Level_1_Wall_2
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_1_Wall_2";
				description = "";
				attachmentSlots[] = {"Material_L1W2_Nails","Material_L1W2_WoodenPlanks","Material_L1W2_MetalSheets","Level_1_Wall_2_Camonet","Level_1_Wall_2_Barbedwire_1","Level_1_Wall_2_Barbedwire_2"};
				icon = "missing";
				selection = "level_1_wall_2";
			};
			class Level_1_Wall_3
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_1_Wall_3";
				description = "";
				attachmentSlots[] = {"Material_L1W3_Nails","Material_L1W3_WoodenPlanks","Material_L1W3_MetalSheets","Level_1_Wall_3_Camonet","Level_1_Wall_3_Barbedwire_1","Level_1_Wall_3_Barbedwire_2"};
				icon = "missing";
				selection = "level_1_wall_3";
			};
			class Level_2
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_2_Base";
				description = "";
				attachmentSlots[] = {"Material_L2_WoodenLogs","Material_L2_Nails","Material_L2_WoodenPlanks"};
				icon = "missing";
				selection = "level_2";
			};
			class Level_2_Wall_1
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_2_Wall_1";
				description = "";
				attachmentSlots[] = {"Material_L2W1_Nails","Material_L2W1_WoodenPlanks","Material_L2W1_MetalSheets","Level_2_Wall_1_Camonet"};
				icon = "missing";
				selection = "level_2_wall_1";
			};
			class Level_2_Wall_2
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_2_Wall_2";
				description = "";
				attachmentSlots[] = {"Material_L2W2_Nails","Material_L2W2_WoodenPlanks","Material_L2W2_MetalSheets","Level_2_Wall_2_Camonet"};
				icon = "missing";
				selection = "level_2_wall_2";
			};
			class Level_2_Wall_3
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_2_Wall_3";
				description = "";
				attachmentSlots[] = {"Material_L2W3_Nails","Material_L2W3_WoodenPlanks","Material_L2W3_MetalSheets","Level_2_Wall_3_Camonet"};
				icon = "missing";
				selection = "level_2_wall_3";
			};
			class Level_3
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_3_Base";
				description = "";
				attachmentSlots[] = {"Material_L3_WoodenLogs","Material_L3_Nails","Material_L3_WoodenPlanks","Material_L3_MetalSheets"};
				icon = "missing";
				selection = "level_3";
			};
			class Level_3_Wall_1
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_3_Wall_1";
				description = "";
				attachmentSlots[] = {"Material_L3W1_Nails","Material_L3W1_WoodenPlanks","Material_L3W1_MetalSheets","Level_3_Wall_1_Camonet"};
				icon = "missing";
				selection = "level_3_wall_1";
			};
			class Level_3_Wall_2
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_3_Wall_2";
				description = "";
				attachmentSlots[] = {"Material_L3W2_Nails","Material_L3W2_WoodenPlanks","Material_L3W2_MetalSheets","Level_3_Wall_2_Camonet"};
				icon = "missing";
				selection = "level_3_wall_2";
			};
			class Level_3_Wall_3
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_3_Wall_3";
				description = "";
				attachmentSlots[] = {"Material_L3W3_Nails","Material_L3W3_WoodenPlanks","Material_L3W3_MetalSheets","Level_3_Wall_3_Camonet"};
				icon = "missing";
				selection = "level_3_wall_3";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Deployed: AnimSourceHidden{};
			class Level_1_Base: AnimSourceHidden{};
			class Level_1_Stairs: AnimSourceHidden{};
			class Level_1_Roof: AnimSourceHidden{};
			class Material_L1_WoodenLogs: AnimSourceHidden{};
			class Level_1_Wall_1_Barbedwire_1: AnimSourceHidden{};
			class Level_1_Wall_1_Barbedwire_1_Mounted: AnimSourceHidden{};
			class Level_1_Wall_1_Barbedwire_2: AnimSourceHidden{};
			class Level_1_Wall_1_Barbedwire_2_Mounted: AnimSourceHidden{};
			class Level_1_Wall_2_Barbedwire_1: AnimSourceHidden{};
			class Level_1_Wall_2_Barbedwire_1_Mounted: AnimSourceHidden{};
			class Level_1_Wall_2_Barbedwire_2: AnimSourceHidden{};
			class Level_1_Wall_2_Barbedwire_2_Mounted: AnimSourceHidden{};
			class Level_1_Wall_3_Barbedwire_1: AnimSourceHidden{};
			class Level_1_Wall_3_Barbedwire_1_Mounted: AnimSourceHidden{};
			class Level_1_Wall_3_Barbedwire_2: AnimSourceHidden{};
			class Level_1_Wall_3_Barbedwire_2_Mounted: AnimSourceHidden{};
			class Level_1_Wall_1_Camonet: AnimSourceHidden{};
			class Level_1_Wall_2_Camonet: AnimSourceHidden{};
			class Level_1_Wall_3_Camonet: AnimSourceHidden{};
			class Level_1_Wall_1_Base_Down: AnimSourceHidden{};
			class Level_1_Wall_1_Base_Up: AnimSourceHidden{};
			class Level_1_Wall_1_Wood_Down: AnimSourceHidden{};
			class Level_1_Wall_1_Wood_Up: AnimSourceHidden{};
			class Level_1_Wall_1_Metal_Down: AnimSourceHidden{};
			class Level_1_Wall_1_Metal_Up: AnimSourceHidden{};
			class Level_1_Wall_2_Base_Down: AnimSourceHidden{};
			class Level_1_Wall_2_Base_Up: AnimSourceHidden{};
			class Level_1_Wall_2_Wood_Down: AnimSourceHidden{};
			class Level_1_Wall_2_Wood_Up: AnimSourceHidden{};
			class Level_1_Wall_2_Metal_Down: AnimSourceHidden{};
			class Level_1_Wall_2_Metal_Up: AnimSourceHidden{};
			class Level_1_Wall_3_Base_Down: AnimSourceHidden{};
			class Level_1_Wall_3_Base_Up: AnimSourceHidden{};
			class Level_1_Wall_3_Wood_Down: AnimSourceHidden{};
			class Level_1_Wall_3_Wood_Up: AnimSourceHidden{};
			class Level_1_Wall_3_Metal_Down: AnimSourceHidden{};
			class Level_1_Wall_3_Metal_Up: AnimSourceHidden{};
			class Level_2_Base: AnimSourceHidden{};
			class Level_2_Stairs: AnimSourceHidden{};
			class Level_2_Roof: AnimSourceHidden{};
			class Material_L2_WoodenLogs: AnimSourceHidden{};
			class Level_2_Wall_1_Camonet: AnimSourceHidden{};
			class Level_2_Wall_2_Camonet: AnimSourceHidden{};
			class Level_2_Wall_3_Camonet: AnimSourceHidden{};
			class Level_2_Wall_1_Base_Down: AnimSourceHidden{};
			class Level_2_Wall_1_Base_Up: AnimSourceHidden{};
			class Level_2_Wall_1_Wood_Down: AnimSourceHidden{};
			class Level_2_Wall_1_Wood_Up: AnimSourceHidden{};
			class Level_2_Wall_1_Metal_Down: AnimSourceHidden{};
			class Level_2_Wall_1_Metal_Up: AnimSourceHidden{};
			class Level_2_Wall_2_Base_Down: AnimSourceHidden{};
			class Level_2_Wall_2_Base_Up: AnimSourceHidden{};
			class Level_2_Wall_2_Wood_Down: AnimSourceHidden{};
			class Level_2_Wall_2_Wood_Up: AnimSourceHidden{};
			class Level_2_Wall_2_Metal_Down: AnimSourceHidden{};
			class Level_2_Wall_2_Metal_Up: AnimSourceHidden{};
			class Level_2_Wall_3_Base_Down: AnimSourceHidden{};
			class Level_2_Wall_3_Base_Up: AnimSourceHidden{};
			class Level_2_Wall_3_Wood_Down: AnimSourceHidden{};
			class Level_2_Wall_3_Wood_Up: AnimSourceHidden{};
			class Level_2_Wall_3_Metal_Down: AnimSourceHidden{};
			class Level_2_Wall_3_Metal_Up: AnimSourceHidden{};
			class Level_3_Base: AnimSourceHidden{};
			class Level_3_Stairs: AnimSourceHidden{};
			class Level_3_Roof: AnimSourceHidden{};
			class Material_L3_WoodenLogs: AnimSourceHidden{};
			class Level_3_Wall_1_Camonet: AnimSourceHidden{};
			class Level_3_Wall_2_Camonet: AnimSourceHidden{};
			class Level_3_Wall_3_Camonet: AnimSourceHidden{};
			class Level_3_Wall_1_Base_Down: AnimSourceHidden{};
			class Level_3_Wall_1_Base_Up: AnimSourceHidden{};
			class Level_3_Wall_1_Wood_Down: AnimSourceHidden{};
			class Level_3_Wall_1_Wood_Up: AnimSourceHidden{};
			class Level_3_Wall_1_Metal_Down: AnimSourceHidden{};
			class Level_3_Wall_1_Metal_Up: AnimSourceHidden{};
			class Level_3_Wall_2_Base_Down: AnimSourceHidden{};
			class Level_3_Wall_2_Base_Up: AnimSourceHidden{};
			class Level_3_Wall_2_Wood_Down: AnimSourceHidden{};
			class Level_3_Wall_2_Wood_Up: AnimSourceHidden{};
			class Level_3_Wall_2_Metal_Down: AnimSourceHidden{};
			class Level_3_Wall_2_Metal_Up: AnimSourceHidden{};
			class Level_3_Wall_3_Base_Down: AnimSourceHidden{};
			class Level_3_Wall_3_Base_Up: AnimSourceHidden{};
			class Level_3_Wall_3_Wood_Down: AnimSourceHidden{};
			class Level_3_Wall_3_Wood_Up: AnimSourceHidden{};
			class Level_3_Wall_3_Metal_Down: AnimSourceHidden{};
			class Level_3_Wall_3_Metal_Up: AnimSourceHidden{};
		};
		class Construction
		{
			class level_1
			{
				class level_1_base
				{
					name = "$STR_CfgVehicles_Construction_Part_Base";
					is_base = 1;
					platform_support = "level_1";
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {"level_1_stairs_min","level_1_stairs_max"};
					build_action_type = 4;
					dismantle_action_type = 4;
					material_type = 1;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 4;
							lockable = 1;
						};
					};
				};
				class level_1_stairs
				{
					name = "$STR_CfgVehicles_Construction_Part_Stairs";
					required_parts[] = {"level_1_base","level_1_roof"};
					conflicted_parts[] = {};
					collision_data[] = {"level_1_stairs_min","level_1_stairs_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 3;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1_WoodenPlanks";
							quantity = 6;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1_Nails";
							quantity = 18;
						};
					};
				};
				class level_1_roof
				{
					name = "$STR_CfgVehicles_Construction_Part_Roof";
					platform_support = "level_2";
					required_parts[] = {"level_1_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_1_roof_min","level_1_roof_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1_WoodenPlanks";
							quantity = 10;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1_Nails";
							quantity = 20;
						};
					};
				};
			};
			class level_1_wall_1
			{
				class level_1_wall_1_base_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Down";
					required_parts[] = {"level_1_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_1_wall_1_down_min","level_1_wall_1_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W1_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W1_Nails";
							quantity = 8;
						};
					};
				};
				class level_1_wall_1_base_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Up";
					required_parts[] = {"level_1_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_1_wall_1_up_min","level_1_wall_1_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W1_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W1_Nails";
							quantity = 8;
						};
					};
				};
				class level_1_wall_1_wood_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Down";
					required_parts[] = {"level_1_wall_1_base_down"};
					conflicted_parts[] = {"level_1_wall_1_metal_down"};
					collision_data[] = {"level_1_wall_1_down_min","level_1_wall_1_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W1_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W1_Nails";
							quantity = 10;
						};
					};
				};
				class level_1_wall_1_wood_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Up";
					required_parts[] = {"level_1_wall_1_base_up"};
					conflicted_parts[] = {"level_1_wall_1_metal_up"};
					collision_data[] = {"level_1_wall_1_up_min","level_1_wall_1_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W1_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W1_Nails";
							quantity = 10;
						};
					};
				};
				class level_1_wall_1_metal_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Down";
					required_parts[] = {"level_1_wall_1_base_down"};
					conflicted_parts[] = {"level_1_wall_1_wood_down"};
					collision_data[] = {"level_1_wall_1_down_min","level_1_wall_1_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L1W1_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W1_Nails";
							quantity = 12;
						};
					};
				};
				class level_1_wall_1_metal_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Up";
					required_parts[] = {"level_1_wall_1_base_up"};
					conflicted_parts[] = {"level_1_wall_1_wood_up"};
					collision_data[] = {"level_1_wall_1_up_min","level_1_wall_1_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L1W1_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W1_Nails";
							quantity = 12;
						};
					};
				};
			};
			class level_1_wall_2
			{
				class level_1_wall_2_base_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Down";
					required_parts[] = {"level_1_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_1_wall_2_down_min","level_1_wall_2_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W2_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W2_Nails";
							quantity = 8;
						};
					};
				};
				class level_1_wall_2_base_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Up";
					required_parts[] = {"level_1_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_1_wall_2_up_min","level_1_wall_2_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W2_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W2_Nails";
							quantity = 8;
						};
					};
				};
				class level_1_wall_2_wood_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Down";
					required_parts[] = {"level_1_wall_2_base_down"};
					conflicted_parts[] = {"level_1_wall_2_metal_down"};
					collision_data[] = {"level_1_wall_2_down_min","level_1_wall_2_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W2_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W2_Nails";
							quantity = 10;
						};
					};
				};
				class level_1_wall_2_wood_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Up";
					required_parts[] = {"level_1_wall_2_base_up"};
					conflicted_parts[] = {"level_1_wall_2_metal_up"};
					collision_data[] = {"level_1_wall_2_up_min","level_1_wall_2_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W2_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W2_Nails";
							quantity = 10;
						};
					};
				};
				class level_1_wall_2_metal_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Down";
					required_parts[] = {"level_1_wall_2_base_down"};
					conflicted_parts[] = {"level_1_wall_2_wood_down"};
					collision_data[] = {"level_1_wall_3_down_min","level_1_wall_3_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L1W2_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W2_Nails";
							quantity = 12;
						};
					};
				};
				class level_1_wall_2_metal_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Up";
					required_parts[] = {"level_1_wall_2_base_up"};
					conflicted_parts[] = {"level_1_wall_2_wood_up"};
					collision_data[] = {"level_1_wall_2_up_min","level_1_wall_2_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L1W2_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W2_Nails";
							quantity = 12;
						};
					};
				};
			};
			class level_1_wall_3
			{
				class level_1_wall_3_base_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Down";
					required_parts[] = {"level_1_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_1_wall_3_down_min","level_1_wall_3_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W3_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W3_Nails";
							quantity = 8;
						};
					};
				};
				class level_1_wall_3_base_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Up";
					required_parts[] = {"level_1_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_1_wall_3_up_min","level_1_wall_3_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W3_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W3_Nails";
							quantity = 8;
						};
					};
				};
				class level_1_wall_3_wood_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Down";
					required_parts[] = {"level_1_wall_3_base_down"};
					conflicted_parts[] = {"level_1_wall_3_metal_down"};
					collision_data[] = {"level_1_wall_3_down_min","level_1_wall_3_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W3_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W3_Nails";
							quantity = 10;
						};
					};
				};
				class level_1_wall_3_wood_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Up";
					required_parts[] = {"level_1_wall_3_base_up"};
					conflicted_parts[] = {"level_1_wall_3_metal_up"};
					collision_data[] = {"level_1_wall_3_up_min","level_1_wall_3_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W3_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W3_Nails";
							quantity = 10;
						};
					};
				};
				class level_1_wall_3_metal_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Down";
					required_parts[] = {"level_1_wall_3_base_down"};
					conflicted_parts[] = {"level_1_wall_3_wood_down"};
					collision_data[] = {"level_1_wall_3_down_min","level_1_wall_3_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L1W3_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W3_Nails";
							quantity = 12;
						};
					};
				};
				class level_1_wall_3_metal_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Up";
					required_parts[] = {"level_1_wall_3_base_up"};
					conflicted_parts[] = {"level_1_wall_3_wood_up"};
					collision_data[] = {"level_1_wall_3_up_min","level_1_wall_3_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L1W3_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W3_Nails";
							quantity = 12;
						};
					};
				};
			};
			class level_2
			{
				class level_2_base
				{
					name = "$STR_CfgVehicles_Construction_Part_Floor_Base";
					platform_support = "level_2";
					required_parts[] = {"level_1_roof"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 8;
					dismantle_action_type = 8;
					material_type = 1;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L2_WoodenLogs";
							quantity = 4;
							lockable = 1;
						};
					};
				};
				class level_2_stairs
				{
					name = "$STR_CfgVehicles_Construction_Part_Stairs";
					required_parts[] = {"level_2_roof"};
					conflicted_parts[] = {};
					collision_data[] = {"level_2_stairs_min","level_2_stairs_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 3;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2_WoodenPlanks";
							quantity = 6;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2_Nails";
							quantity = 18;
						};
					};
				};
				class level_2_roof
				{
					name = "$STR_CfgVehicles_Construction_Part_Roof";
					platform_support = "level_3";
					required_parts[] = {"level_2_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_2_roof_min","level_2_roof_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2_WoodenPlanks";
							quantity = 10;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2_Nails";
							quantity = 20;
						};
					};
				};
			};
			class level_2_wall_1
			{
				class level_2_wall_1_base_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Down";
					required_parts[] = {"level_2_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_2_wall_1_down_min","level_2_wall_1_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W1_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W1_Nails";
							quantity = 8;
						};
					};
				};
				class level_2_wall_1_base_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Up";
					required_parts[] = {"level_2_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_2_wall_1_up_min","level_2_wall_1_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W1_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W1_Nails";
							quantity = 8;
						};
					};
				};
				class level_2_wall_1_wood_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Down";
					required_parts[] = {"level_2_wall_1_base_down"};
					conflicted_parts[] = {"level_2_wall_1_metal_down"};
					collision_data[] = {"level_2_wall_1_down_min","level_2_wall_1_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W1_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W1_Nails";
							quantity = 10;
						};
					};
				};
				class level_2_wall_1_wood_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Up";
					required_parts[] = {"level_2_wall_1_base_up"};
					conflicted_parts[] = {"level_2_wall_1_metal_up"};
					collision_data[] = {"level_2_wall_1_up_min","level_2_wall_1_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W1_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W1_Nails";
							quantity = 10;
						};
					};
				};
				class level_2_wall_1_metal_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Down";
					required_parts[] = {"level_2_wall_1_base_down"};
					conflicted_parts[] = {"level_2_wall_1_wood_down"};
					collision_data[] = {"level_2_wall_1_down_min","level_2_wall_1_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L2W1_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W1_Nails";
							quantity = 12;
						};
					};
				};
				class level_2_wall_1_metal_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Up";
					required_parts[] = {"level_2_wall_1_base_up"};
					conflicted_parts[] = {"level_2_wall_1_wood_up"};
					collision_data[] = {"level_2_wall_1_up_min","level_2_wall_1_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L2W1_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W1_Nails";
							quantity = 12;
						};
					};
				};
			};
			class level_2_wall_2
			{
				class level_2_wall_2_base_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Down";
					required_parts[] = {"level_2_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_2_wall_2_down_min","level_2_wall_2_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W2_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W2_Nails";
							quantity = 8;
						};
					};
				};
				class level_2_wall_2_base_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Up";
					required_parts[] = {"level_2_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_2_wall_2_up_min","level_2_wall_2_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W2_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W2_Nails";
							quantity = 8;
						};
					};
				};
				class level_2_wall_2_wood_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Down";
					required_parts[] = {"level_2_wall_2_base_down"};
					conflicted_parts[] = {"level_2_wall_2_metal_down"};
					collision_data[] = {"level_2_wall_2_down_min","level_2_wall_2_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W2_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W2_Nails";
							quantity = 10;
						};
					};
				};
				class level_2_wall_2_wood_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Up";
					required_parts[] = {"level_2_wall_2_base_up"};
					conflicted_parts[] = {"level_2_wall_2_metal_up"};
					collision_data[] = {"level_2_wall_2_up_min","level_2_wall_2_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W2_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W2_Nails";
							quantity = 10;
						};
					};
				};
				class level_2_wall_2_metal_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Down";
					required_parts[] = {"level_2_wall_2_base_down"};
					conflicted_parts[] = {"level_2_wall_2_wood_down"};
					collision_data[] = {"level_2_wall_2_down_min","level_2_wall_2_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L2W2_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W2_Nails";
							quantity = 12;
						};
					};
				};
				class level_2_wall_2_metal_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Up";
					required_parts[] = {"level_2_wall_2_base_up"};
					conflicted_parts[] = {"level_2_wall_2_wood_up"};
					collision_data[] = {"level_2_wall_2_up_min","level_2_wall_2_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L2W2_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W2_Nails";
							quantity = 12;
						};
					};
				};
			};
			class level_2_wall_3
			{
				class level_2_wall_3_base_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Down";
					required_parts[] = {"level_2_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_2_wall_3_down_min","level_2_wall_3_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W3_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W3_Nails";
							quantity = 8;
						};
					};
				};
				class level_2_wall_3_base_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Up";
					required_parts[] = {"level_2_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_2_wall_3_up_min","level_2_wall_3_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W3_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W3_Nails";
							quantity = 8;
						};
					};
				};
				class level_2_wall_3_wood_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Down";
					required_parts[] = {"level_2_wall_3_base_down"};
					conflicted_parts[] = {"level_2_wall_3_metal_down"};
					collision_data[] = {"level_2_wall_3_down_min","level_2_wall_3_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W3_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W3_Nails";
							quantity = 10;
						};
					};
				};
				class level_2_wall_3_wood_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Up";
					required_parts[] = {"level_2_wall_3_base_up"};
					conflicted_parts[] = {"level_2_wall_3_metal_up"};
					collision_data[] = {"level_2_wall_3_up_min","level_2_wall_3_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W3_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W3_Nails";
							quantity = 10;
						};
					};
				};
				class level_2_wall_3_metal_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Down";
					required_parts[] = {"level_2_wall_3_base_down"};
					conflicted_parts[] = {"level_2_wall_3_wood_down"};
					collision_data[] = {"level_2_wall_3_down_min","level_2_wall_3_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L2W3_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W3_Nails";
							quantity = 12;
						};
					};
				};
				class level_2_wall_3_metal_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Up";
					required_parts[] = {"level_2_wall_3_base_up"};
					conflicted_parts[] = {"level_2_wall_3_wood_up"};
					collision_data[] = {"level_2_wall_3_up_min","level_2_wall_3_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L2W3_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W3_Nails";
							quantity = 12;
						};
					};
				};
			};
			class level_3
			{
				class level_3_base
				{
					name = "$STR_CfgVehicles_Construction_Part_Floor_Base";
					platform_support = "level_3";
					required_parts[] = {"level_2_roof"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 8;
					dismantle_action_type = 8;
					material_type = 1;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L3_WoodenLogs";
							quantity = 4;
							lockable = 1;
						};
					};
				};
				class level_3_roof
				{
					name = "$STR_CfgVehicles_Construction_Part_Roof";
					required_parts[] = {"level_3_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_3_roof_min","level_3_roof_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3_Nails";
							quantity = 20;
						};
						class Material3
						{
							type = "MetalPlate";
							slot_name = "Material_L3_MetalSheets";
							quantity = 6;
						};
					};
				};
			};
			class level_3_wall_1
			{
				class level_3_wall_1_base_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Down";
					required_parts[] = {"level_3_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_3_wall_1_down_min","level_3_wall_1_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W1_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W1_Nails";
							quantity = 8;
						};
					};
				};
				class level_3_wall_1_base_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Up";
					required_parts[] = {"level_3_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_3_wall_1_up_min","level_3_wall_1_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W1_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W1_Nails";
							quantity = 8;
						};
					};
				};
				class level_3_wall_1_wood_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Down";
					required_parts[] = {"level_3_wall_1_base_down"};
					conflicted_parts[] = {"level_3_wall_1_metal_down"};
					collision_data[] = {"level_3_wall_1_down_min","level_3_wall_1_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W1_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W1_Nails";
							quantity = 10;
						};
					};
				};
				class level_3_wall_1_wood_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Up";
					required_parts[] = {"level_3_wall_1_base_up"};
					conflicted_parts[] = {"level_3_wall_1_metal_up"};
					collision_data[] = {"level_3_wall_1_up_min","level_3_wall_1_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W1_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W1_Nails";
							quantity = 10;
						};
					};
				};
				class level_3_wall_1_metal_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Down";
					required_parts[] = {"level_3_wall_1_base_down"};
					conflicted_parts[] = {"level_3_wall_1_wood_down"};
					collision_data[] = {"level_3_wall_1_down_min","level_3_wall_1_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L3W1_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W1_Nails";
							quantity = 12;
						};
					};
				};
				class level_3_wall_1_metal_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Up";
					required_parts[] = {"level_3_wall_1_base_up"};
					conflicted_parts[] = {"level_3_wall_1_wood_up"};
					collision_data[] = {"level_3_wall_1_up_min","level_3_wall_1_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L3W1_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W1_Nails";
							quantity = 12;
						};
					};
				};
			};
			class level_3_wall_2
			{
				class level_3_wall_2_base_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Down";
					required_parts[] = {"level_3_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_3_wall_2_down_min","level_3_wall_2_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W2_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W2_Nails";
							quantity = 8;
						};
					};
				};
				class level_3_wall_2_base_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Up";
					required_parts[] = {"level_3_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_3_wall_2_up_min","level_3_wall_2_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W2_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W2_Nails";
							quantity = 8;
						};
					};
				};
				class level_3_wall_2_wood_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Down";
					required_parts[] = {"level_3_wall_2_base_down"};
					conflicted_parts[] = {"level_3_wall_2_metal_down"};
					collision_data[] = {"level_3_wall_2_down_min","level_3_wall_2_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W2_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W2_Nails";
							quantity = 10;
						};
					};
				};
				class level_3_wall_2_wood_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Up";
					required_parts[] = {"level_3_wall_2_base_up"};
					conflicted_parts[] = {"level_3_wall_2_metal_up"};
					collision_data[] = {"level_3_wall_2_up_min","level_3_wall_2_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W2_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W2_Nails";
							quantity = 10;
						};
					};
				};
				class level_3_wall_2_metal_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Down";
					required_parts[] = {"level_3_wall_2_base_down"};
					conflicted_parts[] = {"level_3_wall_2_wood_down"};
					collision_data[] = {"level_3_wall_2_down_min","level_3_wall_2_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L3W2_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W2_Nails";
							quantity = 12;
						};
					};
				};
				class level_3_wall_2_metal_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Up";
					required_parts[] = {"level_3_wall_2_base_up"};
					conflicted_parts[] = {"level_3_wall_2_wood_up"};
					collision_data[] = {"level_3_wall_2_up_min","level_3_wall_2_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L3W2_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W2_Nails";
							quantity = 12;
						};
					};
				};
			};
			class level_3_wall_3
			{
				class level_3_wall_3_base_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Down";
					required_parts[] = {"level_3_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_3_wall_3_down_min","level_3_wall_3_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W3_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W3_Nails";
							quantity = 8;
						};
					};
				};
				class level_3_wall_3_base_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Up";
					required_parts[] = {"level_3_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_3_wall_3_up_min","level_3_wall_3_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W3_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W3_Nails";
							quantity = 8;
						};
					};
				};
				class level_3_wall_3_wood_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Down";
					required_parts[] = {"level_3_wall_3_base_down"};
					conflicted_parts[] = {"level_3_wall_3_metal_down"};
					collision_data[] = {"level_3_wall_3_down_min","level_3_wall_3_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W3_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W3_Nails";
							quantity = 10;
						};
					};
				};
				class level_3_wall_3_wood_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Up";
					required_parts[] = {"level_3_wall_3_base_up"};
					conflicted_parts[] = {"level_3_wall_3_metal_up"};
					collision_data[] = {"level_3_wall_3_up_min","level_3_wall_3_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W3_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W3_Nails";
							quantity = 10;
						};
					};
				};
				class level_3_wall_3_metal_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Down";
					required_parts[] = {"level_3_wall_3_base_down"};
					conflicted_parts[] = {"level_3_wall_3_wood_down"};
					collision_data[] = {"level_3_wall_3_down_min","level_3_wall_3_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L3W3_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W3_Nails";
							quantity = 12;
						};
					};
				};
				class level_3_wall_3_metal_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Up";
					required_parts[] = {"level_3_wall_3_base_up"};
					conflicted_parts[] = {"level_3_wall_3_wood_up"};
					collision_data[] = {"level_3_wall_3_up_min","level_3_wall_3_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L3W3_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W3_Nails";
							quantity = 12;
						};
					};
				};
			};
		};
	};
	class BarbedWire: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_BarbedWire0";
		descriptionShort = "$STR_CfgVehicles_BarbedWire1";
		model = "\dz\gear\camping\Barbed_wire.p3d";
		OnRestrainChange = "BarbedWireLocked";
		SingleUseActions[] = {575};
		ContinuousActions[] = {109,117};
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\camping\data\Barbed_wire_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\Barbed_wire.rvmat"};
		hologramMaterial = "Barbed_wire";
		hologramMaterialPath = "dz\gear\camping\data";
		handheld = "true";
		armAction = "Disarm";
		barbedWireShockEnergyConsumption = 3;
		carveNavmesh = 1;
		itemSize[] = {2,4};
		weight = 400;
		inventorySlot[] = {"Wall_Barbedwire_1","Wall_Barbedwire_2","Level_1_Wall_1_Barbedwire_1","Level_1_Wall_1_Barbedwire_2","Level_1_Wall_2_Barbedwire_1","Level_1_Wall_2_Barbedwire_2","Level_1_Wall_3_Barbedwire_1","Level_1_Wall_3_Barbedwire_2"};
		lootTag[] = {"Farm","Work"};
		physLayer = "item_large";
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\Barbed_wire.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\camping\data\Barbed_wire_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\camping\data\Barbed_wire_destruct.rvmat"}}};
				};
			};
		};
		repairableWithKits[] = {5,7};
		repairCosts[] = {30.0,25.0};
		class EnergyManager
		{
			hasIcon = 1;
			switchOnAtSpawn = 1;
			cordLength = 6;
			powerSocketsCount = 2;
			plugType = 6;
			compatiblePlugTypes[] = {6};
			cordTextureFile = "DZ\gear\camping\Data\plug_black_CO.paa";
			energyUsagePerSecond = 0.01;
		};
		class AnimationSources
		{
			class placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class zbytek
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "pickUpBarbedWire_SoundSet";
					id = 797;
				};
			};
		};
	};
	class CombinationLock: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CombinationLock0";
		descriptionShort = "$STR_CfgVehicles_CombinationLock1";
		model = "\DZ\gear\camping\combination_lock.p3d";
		SingleUseActions[] = {575,582};
		ContinuousActions[] = {172};
		inventorySlot = "Att_CombinationLock";
		rotationFlags = 34;
		itemSize[] = {3,3};
		weight = 350;
		class AnimationSources
		{
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Combination_Lock_Item: AnimSourceHidden{};
			class Combination_Lock_Attached: AnimSourceHidden{};
		};
	};
	class BarbedWireLocked: Inventory_Base
	{
		scope = 1;
		displayName = "$STR_CfgVehicles_BarbedWireLocked0";
		model = "\dz\gear\camping\Barbed_wire_tied.p3d";
		OnRestrainChange = "BarbedWire";
		StruggleLength = 20;
		ContinuousActions[] = {116};
		rotationFlags = 17;
		CanBeUnrestrainedBy[] = {"Hacksaw","15","Pliers","25"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\Barbed_wire.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\camping\data\Barbed_wire_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\camping\data\Barbed_wire_destruct.rvmat"}}};
				};
			};
		};
	};
	class CamoNet: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CamoNet0";
		descriptionShort = "$STR_CfgVehicles_CamoNet1";
		model = "\dz\gear\camping\camo_net_p.p3d";
		SingleUseActions[] = {575,578};
		handheld = "true";
		armAction = "Disarm";
		itemSize[] = {7,3};
		weight = 400;
		lootTag[] = {"Police","Military_east"};
		inventorySlot[] = {"CamoNet","Wall_Camonet","Level_1_Wall_1_Camonet","Level_1_Wall_2_Camonet","Level_1_Wall_3_Camonet","Level_2_Wall_1_Camonet","Level_2_Wall_2_Camonet","Level_2_Wall_3_Camonet","Level_3_Wall_1_Camonet","Level_3_Wall_2_Camonet","Level_3_Wall_3_Camonet"};
		physLayer = "item_large";
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\camo_net_p.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\camping\data\camo_net_p_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\camping\data\camo_net_p_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpCourierBag_Light_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpCourierBag_SoundSet";
					id = 797;
				};
			};
		};
	};
	class SeaChest: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SeaChest0";
		descriptionShort = "$STR_CfgVehicles_SeaChest1";
		model = "\DZ\gear\camping\sea_chest.p3d";
		handheld = "true";
		weight = 10000;
		itemSize[] = {10,10};
		carveNavmesh = 1;
		canBeDigged = 1;
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\sea_chest.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\camping\data\sea_chest_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\camping\data\sea_chest_destruct.rvmat"}}};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[] = {10,10};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpSeaChest_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpSeaChest_SoundSet";
					id = 797;
				};
			};
		};
	};
	class UndergroundStash: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_UndergroundStash0";
		model = "\DZ\gear\camping\underground_stash.p3d";
		canBeDigged = 1;
		class Cargo
		{
			itemsCargoSize[] = {20,20};
			openable = 1;
			allowOwnedCargoManipulation = 1;
		};
	};
	class Spotlight: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Spotlight0";
		descriptionShort = "$STR_CfgVehicles_Spotlight1";
		model = "\dz\gear\camping\spotlight.p3d";
		handheld = "true";
		armAction = "Disarm";
		SingleUseActions[] = {560,525,527};
		InteractActions[] = {1013,1014,1015,1016};
		ContinuousActions[] = {231};
		hiddenSelections[] = {"placing","cord_folded","cord_plugged","glass_unfolded"};
		hiddenSelectionsTextures[] = {"dz\gear\camping\data\spotlight_co.paa","dz\gear\camping\data\plug_yellow_co.paa","dz\gear\camping\data\plug_yellow_co.paa","dz\gear\camping\data\spotlight_glass_ca.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\spotlight.rvmat","dz\gear\camping\data\plug.rvmat","dz\gear\camping\data\plug.rvmat","dz\gear\camping\data\spotlight_glass.rvmat"};
		hologramMaterial = "spotlight";
		hologramMaterialPath = "dz\gear\camping\data";
		weight = 1700;
		itemSize[] = {3,7};
		itemBehaviour = 2;
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\spotlight.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\camping\data\spotlight_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\camping\data\spotlight_destruct.rvmat"}}};
				};
			};
		};
		repairableWithKits[] = {5,7};
		repairCosts[] = {30.0,25.0};
		class EnergyManager
		{
			hasIcon = 1;
			energyUsagePerSecond = 0.14;
			cordTextureFile = "DZ\gear\camping\Data\plug_yellow_CO.paa";
			cordLength = 3;
			plugType = 2;
		};
		class Reflectors
		{
			class Beam
			{
				color[] = {0.8,0.9,1.0,1.0};
				brightness = 20.0;
				radius = 60;
				angle = 140;
				angleInnerRatio = 0.25;
				dayLight = 1;
				position = "beamStart";
				direction = "beamTarget";
				hitpoint = "glass_unfolded";
				selection = "glass_unfolded";
			};
		};
		class AnimationSources
		{
			class cord_folded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class cord_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class inventory
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class reflector
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class reflector_folded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class reflector_unfolded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class glass_folded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class glass_unfolded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class spotlight_folded_cord_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class spotlight_folded_cord_folded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpSpotLightLight_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpSpotLight_SoundSet";
					id = 797;
				};
			};
		};
	};
	class XmasLights: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_XmasLights0";
		descriptionShort = "$STR_CfgVehicles_XmasLights1";
		model = "\dz\gear\camping\christmas_lights.p3d";
		SingleUseActions[] = {525,578};
		InteractActions[] = {1013};
		hiddenSelections[] = {"glass_r","glass_g","glass_b","glass_y"};
		hiddenSelectionsTextures[] = {};
		hiddenSelectionsMaterials[] = {};
		lootTag[] = {"Farm","Work"};
		itemSize[] = {1,3};
		weight = 150;
		inventorySlot[] = {"Lights","W_Lights_1_L","W_Lights_1_R","W_Lights_1_F","W_Lights_2_L","W_Lights_2_R","W_Lights_2_F","W_Lights_3_L","W_Lights_3_R","W_Lights_3_F"};
		rotationFlags = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\christmass_ligths.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\camping\data\christmass_ligths_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\camping\data\christmass_ligths_destruct.rvmat"}}};
				};
			};
		};
		repairableWithKits[] = {5,7};
		repairCosts[] = {30.0,25.0};
		class EnergyManager
		{
			hasIcon = 1;
			switchOnAtSpawn = 1;
			energyUsagePerSecond = 0.05;
			cordTextureFile = "DZ\gear\camping\Data\plug_yellow_CO.paa";
			cordLength = 5;
			plugType = 2;
		};
		class AnimationSources
		{
			class glass
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class glass_r
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class glass_g
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class glass_b
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class glass_y
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class christmas_lights
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
		};
	};
	class Refridgerator: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Refridgerator0";
		descriptionShort = "$STR_CfgVehicles_Refridgerator1";
		model = "\DZ\gear\containers\fridge.p3d";
		canBeDigged = 1;
		SingleUseActions[] = {525,527};
		InteractActions[] = {1013,1002,1003,1016};
		ContinuousActions[] = {155};
		weight = 1700;
		itemSize[] = {7,10};
		rotationFlags = 2;
		repairableWithKits[] = {5,7};
		repairCosts[] = {30.0,25.0};
		class EnergyManager
		{
			hasIcon = 1;
			energyUsagePerSecond = 0.1;
			cordTextureFile = "DZ\gear\camping\Data\plug_black_CO.paa";
			plugType = 2;
			cordLength = 5;
		};
		class Cargo
		{
			itemsCargoSize[] = {5,8};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PowerGenerator: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PowerGenerator0";
		descriptionShort = "$STR_CfgVehicles_PowerGenerator1";
		model = "\DZ\gear\camping\power_generator.p3d";
		rotationFlags = 2;
		SingleUseActions[] = {550,527};
		InteractActions[] = {1001,1011,1012};
		ContinuousActions[] = {155};
		weight = 45000;
		itemSize[] = {10,10};
		itemBehaviour = 0;
		attachments[] = {"SparkPlug"};
		fuelTankCapacity = 7000;
		carveNavmesh = 1;
		heavyItem = 1;
		hiddenSelections[] = {"socket_1_plugged","socket_2_plugged","socket_3_plugged","socket_4_plugged","sparkplug_installed","placing"};
		hiddenSelectionsTextures[] = {"dz\gear\camping\data\plug_black_CO.paa","dz\gear\camping\data\plug_yellow_CO.paa","dz\gear\camping\data\plug_white_CO.paa","dz\gear\camping\data\plug_orange_CO.paa","dz\gear\camping\data\power_generator_CO.paa","dz\gear\camping\data\power_generator_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\plug.rvmat","dz\gear\camping\data\plug.rvmat","dz\gear\camping\data\plug.rvmat","dz\gear\camping\data\plug.rvmat","dz\gear\camping\data\power_generator.rvmat","dz\gear\camping\data\power_generator.rvmat"};
		hologramMaterial = "power_generator";
		hologramMaterialPath = "dz\gear\camping\data";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\power_generator.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\camping\data\power_generator_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\camping\data\power_generator_destruct.rvmat"}}};
				};
			};
		};
		repairableWithKits[] = {5,7};
		repairCosts[] = {30.0,25.0};
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOff = 1;
			energyStorageMax = 10000;
			energyUsagePerSecond = 0.28;
			reduceMaxEnergyByDamageCoef = 0.5;
			energyAtSpawn = 5000;
			powerSocketsCount = 4;
			compatiblePlugTypes[] = {2,"PLUG_PAS_TERMINAL",6};
		};
		class AnimationSources
		{
			class socket_1_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class socket_2_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class socket_3_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class socket_4_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class sparkplug
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class fuel_tank
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class sparkplug_installed
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class dial_fuel
			{
				source = "user";
				animPeriod = 1;
				initPhase = 1;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpPowerGenerator_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpPowerGenerator_SoundSet";
					id = 797;
				};
			};
		};
	};
	class CableReel: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CableReel0";
		descriptionShort = "$STR_CfgVehicles_CableReel1";
		model = "\dz\gear\camping\cable_reel.p3d";
		inventorySlot = "CableReel";
		weight = 5000;
		itemSize[] = {3,4};
		itemBehaviour = 2;
		SingleUseActions[] = {560,525,550,527};
		InteractActions[] = {1001,1013,1016};
		ContinuousActions[] = {155};
		rotationFlags = 2;
		hiddenSelections[] = {"socket_1_plugged","cord_plugged","cord_folded","placing"};
		hiddenSelectionsTextures[] = {"dz\gear\camping\data\cable_reel_co.paa","dz\gear\camping\data\cable_reel_co.paa","dz\gear\camping\data\cable_reel_co.paa","dz\gear\camping\data\cable_reel_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\cable_reel.rvmat","dz\gear\camping\data\cable_reel.rvmat","dz\gear\camping\data\cable_reel.rvmat","dz\gear\camping\data\cable_reel.rvmat"};
		hologramMaterial = "cable_reel";
		hologramMaterialPath = "dz\gear\camping\data";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\cable_reel.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\camping\data\cable_reel_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\camping\data\cable_reel_destruct.rvmat"}}};
				};
			};
		};
		repairableWithKits[] = {5,7};
		repairCosts[] = {30.0,25.0};
		class EnergyManager
		{
			switchOnAtSpawn = 1;
			powerSocketsCount = 1;
			cordTextureFile = "DZ\gear\camping\Data\plug_orange_CO.paa";
			isPassiveDevice = 1;
			cordLength = 15;
			plugType = 2;
			compatiblePlugTypes[] = {2,6};
		};
		class AnimationSources
		{
			class cord_folded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class cord_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class socket_1_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpCableReelLight_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpCableReel_SoundSet";
					id = 797;
				};
			};
		};
	};
	class BatteryCharger: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_BatteryCharger0";
		descriptionShort = "$STR_CfgVehicles_BatteryCharger1";
		model = "\dz\gear\camping\battery_charger.p3d";
		attachments[] = {"CarBattery","TruckBattery"};
		weight = 5000;
		itemSize[] = {3,3};
		itemBehaviour = 0;
		rotationFlags = 2;
		hiddenSelections[] = {"light_stand_by","light_charging","light_charged","switch_on","clips_detached","clips_folded","cord_plugged","cord_folded","placing"};
		hiddenSelectionsTextures[] = {"dz\gear\camping\data\battery_charger_co.paa","dz\gear\camping\data\battery_charger_co.paa","dz\gear\camping\data\battery_charger_co.paa","dz\gear\camping\data\battery_charger_co.paa","dz\gear\camping\data\battery_charger_co.paa","dz\gear\camping\data\battery_charger_co.paa","dz\gear\camping\data\battery_charger_co.paa","dz\gear\camping\data\battery_charger_co.paa","dz\gear\camping\data\battery_charger_co.paa","dz\gear\camping\data\battery_charger_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\battery_charger.rvmat","dz\gear\camping\data\battery_charger.rvmat","dz\gear\camping\data\battery_charger.rvmat","dz\gear\camping\data\battery_charger.rvmat","dz\gear\camping\data\battery_charger.rvmat","dz\gear\camping\data\battery_charger.rvmat","dz\gear\camping\data\battery_charger.rvmat","dz\gear\camping\data\battery_charger.rvmat","dz\gear\camping\data\battery_charger.rvmat"};
		hologramMaterial = "battery_charger";
		hologramMaterialPath = "dz\gear\camping\data";
		SingleUseActions[] = {525,527};
		InteractActions[] = {1013,1002,1003};
		ContinuousActions[] = {155};
		ChargeEnergyPerSecond = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\battery_charger.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\camping\data\battery_charger_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\camping\data\battery_charger_destruct.rvmat"}}};
				};
			};
		};
		repairableWithKits[] = {5,7};
		repairCosts[] = {30.0,25.0};
		class EnergyManager
		{
			hasIcon = 1;
			energyUsagePerSecond = 0.01;
			cordTextureFile = "DZ\gear\camping\Data\plug_black_CO.paa";
			cordLength = 3;
			plugType = 2;
			compatiblePlugTypes[] = {4};
			powerSocketsCount = 1;
			attachmentAction = 2;
			wetnessExposure = 0.1;
		};
		class AnimationSources
		{
			class cord_folded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class cord_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class clips_detached
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class clips_folded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class switch_on
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class switch_off
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class clips_car_battery
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class clips_truck_battery
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class light_stand_by
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class light_charging
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class light_charged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
		};
	};
	class HescoBox: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_HescoBox0";
		descriptionShort = "$STR_CfgVehicles_HescoBox1";
		model = "\dz\gear\camping\hbox_base.p3d";
		forceFarBubble = "true";
		weight = 5000;
		itemSize[] = {10,10};
		carveNavmesh = 1;
		itemBehaviour = 0;
		useEntityHierarchy = "true";
		physLayer = "item_large";
		SingleUseActions[] = {527};
		InteractActions[] = {1007};
		ContinuousActions[] = {231};
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\camping\data\hbox_filled_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\hbox_filled.rvmat"};
		hologramMaterial = "hbox_empty";
		hologramMaterialPath = "dz\gear\camping\data";
		rotationFlags = 4;
		class Damage
		{
			tex[] = {};
			mat[] = {"DZ\gear\camping\data\hbox_empty.rvmat","DZ\gear\camping\data\hbox_empty_damage.rvmat","DZ\gear\camping\data\hbox_empty_destruct.rvmat","DZ\gear\camping\data\hbox_filled.rvmat","DZ\gear\camping\data\hbox_filled_damage.rvmat","DZ\gear\camping\data\hbox_filled_destruct.rvmat"};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\hbox_empty.rvmat","DZ\gear\camping\data\hbox_filled.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\camping\data\hbox_empty_damage.rvmat","DZ\gear\camping\data\hbox_filled_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\camping\data\hbox_empty_destruct.rvmat","DZ\gear\camping\data\hbox_filled_destruct.rvmat"}}};
				};
			};
		};
		class AnimationSources
		{
			class inventory
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class filled
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyBaseBuilding: ProxyAttachment
	{
		scope = 2;
	};
	class Proxysingle_plank: ProxyBaseBuilding
	{
		model = "\DZ\gear\consumables\single_plank.p3d";
		inventorySlot[] = {"Material_WoodenPlanks","Material_L1_WoodenPlanks","Material_L1W1_WoodenPlanks","Material_L1W2_WoodenPlanks","Material_L1W3_WoodenPlanks","Material_L2_WoodenPlanks","Material_L2W1_WoodenPlanks","Material_L2W2_WoodenPlanks","Material_L2W3_WoodenPlanks","Material_L3_WoodenPlanks","Material_L3W1_WoodenPlanks","Material_L3W2_WoodenPlanks","Material_L3W3_WoodenPlanks"};
	};
	class ProxySingle_Metal_Sheet: ProxyBaseBuilding
	{
		model = "\DZ\gear\consumables\Single_Metal_Sheet.p3d";
		inventorySlot[] = {"Material_MetalSheets","Material_L3_MetalSheets","Material_L1W1_MetalSheets","Material_L1W2_MetalSheets","Material_L1W3_MetalSheets","Material_L2W1_MetalSheets","Material_L2W2_MetalSheets","Material_L2W3_MetalSheets","Material_L3W1_MetalSheets","Material_L3W2_MetalSheets","Material_L3W3_MetalSheets"};
	};
	class ProxyNails_loose_10: ProxyBaseBuilding
	{
		model = "\DZ\gear\consumables\Nails_loose_10.p3d";
		inventorySlot[] = {"Material_Nails","Material_L1_Nails","Material_L1W1_Nails","Material_L1W2_Nails","Material_L1W3_Nails","Material_L2_Nails","Material_L2W1_Nails","Material_L2W2_Nails","Material_L2W3_Nails","Material_L3_Nails","Material_L3W1_Nails","Material_L3W2_Nails","Material_L3W3_Nails"};
	};
	class Proxycombination_lock: ProxyBaseBuilding
	{
		model = "\DZ\gear\camping\combination_lock.p3d";
		inventorySlot[] = {"Att_CombinationLock"};
		class AnimationSources
		{
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Combination_Lock_Item: AnimSourceHidden{};
			class Combination_Lock_Attached: AnimSourceHidden{};
		};
	};
	class Proxycable_reel
	{
		model = "DZ\gear\camping\cable_reel.p3d";
		inventorySlot = "CableReel";
		scope = 2;
		simulation = "ProxyInventory";
		autocenter = 0;
		animated = 0;
		shadow = 1;
		reversed = 1;
		class AnimationSources
		{
			class cord_folded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class cord_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class socket_1_available
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class socket_1_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class dropped_plug_1
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
};
