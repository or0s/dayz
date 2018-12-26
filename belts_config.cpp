////////////////////////////////////////////////////////////////////
//DeRap: characters_belts\config.bin
//Produced from mikero's Dos Tools Dll version 6.44
//'now' is Wed Dec 26 20:29:08 2018 : 'file' last modified on Tue Oct 23 16:02:36 2018
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
	class DZ_Characters_Belts
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters"};
	};
};
class CfgVehicles
{
	class Clothing_Base;
	class Clothing: Clothing_Base{};
	class LeatherBelt_ColorBase: Clothing
	{
		scope = 0;
		displayName = "$STR_CfgVehicles_LeatherBelt_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_LeatherBelt_ColorBase1";
		model = "\DZ\characters\belts\belt_leather_g.p3d";
		attachments[] = {"Pistol","Knife"};
		vehicleClass = "Clothing";
		simulation = "clothing";
		inventorySlot = "Hips";
		itemInfo[] = {"Clothing","Hips"};
		itemSize[] = {2,1};
		weight = 20;
		lootCategory = "Crafted";
		lootTag[] = {"Civilian"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\belts\data\belt_leather_beige.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\belts\data\belt_leather_beige_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\belts\data\belt_leather_beige_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\belts\belt_leather_m.p3d";
			female = "\DZ\characters\belts\belt_leather_f.p3d";
		};
	};
	class LeatherBelt_Beige: LeatherBelt_ColorBase
	{
		scope = 1;
		hiddenSelectionsTextures[] = {"\dz\characters\belts\data\belt_leather_co.paa","\dz\characters\belts\data\belt_leather_co.paa","\dz\characters\belts\data\belt_leather_co.paa"};
		hiddenSelectionsMaterials[] = {"DZ\characters\belts\data\belt_leather_beige.rvmat","DZ\characters\belts\data\belt_leather_beige.rvmat","DZ\characters\belts\data\belt_leather_beige.rvmat"};
	};
};
