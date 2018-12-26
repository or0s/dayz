////////////////////////////////////////////////////////////////////
//DeRap: characters_glasses\config.bin
//Produced from mikero's Dos Tools Dll version 6.44
//'now' is Wed Dec 26 16:08:41 2018 : 'file' last modified on Wed Dec 19 09:19:35 2018
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
	class DZ_Characters_Glasses
	{
		units[] = {"SunGlasses"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters"};
	};
};
class CfgVehicles
{
	class Clothing_Base;
	class Clothing: Clothing_Base{};
	class SportGlasses_ColorBase: Clothing
	{
		scope = 0;
		displayName = "$STR_CfgVehicles_SportGlasses0";
		descriptionShort = "$STR_CfgVehicles_SportGlasses1";
		model = "\DZ\characters\glasses\sport_glasses_g.p3d";
		vehicleClass = "Clothing";
		simulation = "clothing";
		inventorySlot = "Eyewear";
		itemInfo[] = {"Clothing","Eyewear"};
		rotationFlags = 1;
		itemSize[] = {3,1};
		weight = 20;
		lootCategory = "Eyewear";
		lootTag[] = {"Civilian"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\glasses\data\joeyx.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\glasses\data\joeyx_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\glasses\data\joeyx_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\glasses\sport_glasses.p3d";
			female = "\DZ\characters\glasses\sport_glasses.p3d";
		};
	};
	class SportGlasses_Black: SportGlasses_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\characters\glasses\data\joeyx_black_ca.paa","\dz\characters\glasses\data\joeyx_black_ca.paa","\dz\characters\glasses\data\joeyx_black_ca.paa"};
	};
	class SportGlasses_Blue: SportGlasses_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\characters\glasses\data\joeyx_blue_ca.paa","\dz\characters\glasses\data\joeyx_blue_ca.paa","\dz\characters\glasses\data\joeyx_blue_ca.paa"};
	};
	class SportGlasses_Green: SportGlasses_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\characters\glasses\data\joeyx_green_ca.paa","\dz\characters\glasses\data\joeyx_green_ca.paa","\dz\characters\glasses\data\joeyx_green_ca.paa"};
	};
	class SportGlasses_Orange: SportGlasses_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\characters\glasses\data\joeyx_yellowred_ca.paa","\dz\characters\glasses\data\joeyx_yellowred_ca.paa","\dz\characters\glasses\data\joeyx_yellowred_ca.paa"};
	};
	class AviatorGlasses: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AviatorGlasses0";
		descriptionShort = "$STR_CfgVehicles_AviatorGlasses1";
		model = "\DZ\characters\glasses\aviator_glasses_g.p3d";
		vehicleClass = "Clothing";
		simulation = "clothing";
		inventorySlot = "Eyewear";
		itemInfo[] = {"Clothing","Eyewear"};
		rotationFlags = 1;
		weight = 36;
		itemSize[] = {2,1};
		lootTag[] = {"Military_west","Military_east","Civilian"};
		lootCategory = "Eyewear";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\glasses\data\goggles2_metal.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\glasses\data\goggles2_metal_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\glasses\data\goggles2_metal_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\glasses\aviator_glasses.p3d";
			female = "\DZ\characters\glasses\aviator_glasses.p3d";
		};
	};
	class DesignerGlasses: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_DesignerGlasses0";
		descriptionShort = "$STR_CfgVehicles_DesignerGlasses1";
		model = "\DZ\characters\glasses\sunglasses_designer_g.p3d";
		vehicleClass = "Clothing";
		simulation = "clothing";
		inventorySlot = "Eyewear";
		itemInfo[] = {"Clothing","Eyewear"};
		rotationFlags = 1;
		weight = 40;
		itemSize[] = {2,1};
		lootTag[] = {"Civilian"};
		lootCategory = "Eyewear";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\glasses\data\sunglass_designer.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\glasses\data\sunglass_designer_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\glasses\data\sunglass_designer_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\glasses\sunglasses_designer.p3d";
			female = "\DZ\characters\glasses\sunglasses_designer.p3d";
		};
	};
	class ThickFramesGlasses: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ThickFramesGlasses0";
		descriptionShort = "$STR_CfgVehicles_ThickFramesGlasses1";
		model = "\DZ\characters\glasses\glasses_thick_frame_g.p3d";
		vehicleClass = "Clothing";
		simulation = "clothing";
		inventorySlot = "Eyewear";
		itemInfo[] = {"Clothing","Eyewear"};
		rotationFlags = 1;
		weight = 50;
		itemSize[] = {2,1};
		lootTag[] = {"Civilian"};
		lootCategory = "Eyewear";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\glasses\data\ThickFrameGlasses.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\glasses\data\ThickFrameGlasses_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\glasses\data\ThickFrameGlasses_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\glasses\glasses_thick_frame.p3d";
			female = "\DZ\characters\glasses\glasses_thick_frame.p3d";
		};
	};
	class ThinFramesGlasses: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ThinFramesGlasses0";
		descriptionShort = "$STR_CfgVehicles_ThinFramesGlasses1";
		model = "\DZ\characters\glasses\glasses_thin_frame_g.p3d";
		vehicleClass = "Clothing";
		simulation = "clothing";
		inventorySlot = "Eyewear";
		itemInfo[] = {"Clothing","Eyewear"};
		rotationFlags = 1;
		weight = 30;
		itemSize[] = {2,1};
		lootTag[] = {"Civilian"};
		lootCategory = "Eyewear";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\glasses\data\ThinFrameGlasses.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\glasses\data\ThinFrameGlasses_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\glasses\data\ThinFrameGlasses_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\glasses\glasses_thin_frame.p3d";
			female = "\DZ\characters\glasses\glasses_thin_frame.p3d";
		};
	};
	class TacticalGoggles: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_TacticalGoggles0";
		descriptionShort = "$STR_CfgVehicles_TacticalGoggles1";
		model = "\DZ\characters\glasses\TacGoggles_g.p3d";
		vehicleClass = "Clothing";
		simulation = "clothing";
		inventorySlot = "Eyewear";
		itemInfo[] = {"Clothing","Eyewear"};
		rotationFlags = 1;
		itemSize[] = {2,1};
		weight = 100;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\glasses\data\TacGoggles.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\glasses\data\TacGoggles_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\glasses\data\TacGoggles_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\glasses\TacGoggles.p3d";
			female = "\DZ\characters\glasses\TacGoggles.p3d";
		};
	};
	class NVGHeadstrap: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_NVGHeadstrap0";
		descriptionShort = "$STR_CfgVehicles_NVGHeadstrap1";
		model = "\DZ\characters\glasses\NVG_Headstrap_g.p3d";
		vehicleClass = "Clothing";
		simulation = "clothing";
		inventorySlot = "Eyewear";
		itemInfo[] = {"Clothing","Eyewear"};
		rotationFlags = 1;
		itemSize[] = {3,3};
		weight = 450;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\glasses\data\NVG_Headstrap.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\glasses\data\NVG_Headstrap_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\glasses\data\NVG_Headstrap_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\glasses\NVG_Headstrap.p3d";
			female = "\DZ\characters\glasses\NVG_Headstrap.p3d";
		};
	};
};
