////////////////////////////////////////////////////////////////////
//DeRap: characters_masks\config.bin
//Produced from mikero's Dos Tools Dll version 6.44
//'now' is Wed Dec 26 20:29:23 2018 : 'file' last modified on Thu Dec 20 15:34:30 2018
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
	class DZ_Characters_Masks
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
	class GasMask: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_GasMask0";
		descriptionShort = "$STR_CfgVehicles_GasMask1";
		model = "\DZ\characters\masks\GasMask_g.p3d";
		inventorySlot = "Mask";
		itemInfo[] = {"Clothing","Mask"};
		rotationFlags = 2;
		weight = 730;
		itemSize[] = {3,4};
		heatIsolation = 0.5;
		visibilityModifier = 0.9;
		noHelmet = 1;
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\dz\characters\masks\data\GasMask_co.paa","\dz\characters\masks\data\GasMask_co.paa","\dz\characters\masks\data\GasMask_co.paa"};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\GasMask_m.p3d";
			female = "\DZ\characters\masks\GasMask_f.p3d";
		};
	};
	class BandanaMask_ColorBase: Clothing
	{
		displayName = "$STR_cfgvehicles_bandana_colorbase0";
		descriptionShort = "$STR_cfgvehicles_bandana_colorbase1";
		model = "\DZ\characters\masks\BandanaFace_g.p3d";
		ContinuousActions[] = {190};
		inventorySlot[] = {"Headgear","Mask"};
		itemInfo[] = {"Clothing","Mask"};
		weight = 510;
		itemSize[] = {2,1};
		ragQuantity = 1;
		absorbency = 0.9;
		heatIsolation = 0.3;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class Damage
		{
			tex[] = {};
			mat[] = {"DZ\characters\headgear\data\BandanaF.rvmat","DZ\characters\headgear\data\BandanaF_damage.rvmat","DZ\characters\headgear\data\BandanaF_destruct.rvmat"};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\BandanaFace_m.p3d";
			female = "\DZ\characters\masks\BandanaFace_f.p3d";
		};
	};
	class BandanaMask_RedPattern: BandanaMask_ColorBase
	{
		scope = 2;
		color = "redpattern";
		ChangeIntoOnDetach = "Bandana_Redpattern";
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\BandanaF_redpattern_co.paa","DZ\characters\headgear\data\BandanaF_redpattern_co.paa","DZ\characters\headgear\data\BandanaF_redpattern_co.paa"};
	};
	class BandanaMask_BlackPattern: BandanaMask_ColorBase
	{
		scope = 2;
		color = "blackpattern";
		ChangeIntoOnDetach = "Bandana_Blackpattern";
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\BandanaF_blackpattern_co.paa","DZ\characters\headgear\data\BandanaF_blackpattern_co.paa","DZ\characters\headgear\data\BandanaF_blackpattern_co.paa"};
	};
	class BandanaMask_PolkaPattern: BandanaMask_ColorBase
	{
		scope = 2;
		color = "polkapattern";
		ChangeIntoOnDetach = "Bandana_Polkapattern";
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\BandanaF_karkulka_co.paa","DZ\characters\headgear\data\BandanaF_karkulka_co.paa","DZ\characters\headgear\data\BandanaF_karkulka_co.paa"};
	};
	class BandanaMask_GreenPattern: BandanaMask_ColorBase
	{
		scope = 2;
		color = "greenpattern";
		ChangeIntoOnDetach = "Bandana_Greenpattern";
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\BandanaFHG_olive_co.paa","DZ\characters\headgear\data\BandanaFHG_olive_co.paa","DZ\characters\headgear\data\BandanaFHG_olive_co.paa"};
	};
	class BandanaMask_CamoPattern: BandanaMask_ColorBase
	{
		scope = 2;
		color = "camopattern";
		ChangeIntoOnDetach = "Bandana_Camopattern";
		visibilityModifier = 0.8;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\BandanaFHG_TTsKO_co.paa","DZ\characters\headgear\data\BandanaFHG_TTsKO_co.paa","DZ\characters\headgear\data\BandanaFHG_TTsKO_co.paa"};
	};
	class NioshFaceMask: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_NioshFaceMask0";
		descriptionShort = "$STR_CfgVehicles_NioshFaceMask1";
		model = "\DZ\characters\masks\NioshFaceMask_g.p3d";
		inventorySlot = "Mask";
		itemInfo[] = {"Clothing","Mask"};
		rotationFlags = 16;
		weight = 340;
		itemSize[] = {2,2};
		absorbency = 0.9;
		heatIsolation = 0.4;
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\DZ\characters\masks\data\NioshFaceMask_co.paa","\DZ\characters\masks\data\NioshFaceMask_co.paa","\DZ\characters\masks\data\NioshFaceMask_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\masks\data\NioshFaceMask.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\masks\data\NioshFaceMask_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\masks\data\NioshFaceMask_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\NioshFaceMask_m.p3d";
			female = "\DZ\characters\masks\NioshFaceMask_f.p3d";
		};
	};
	class BalaclavaMask_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_BalaclavaMask_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_BalaclavaMask_ColorBase1";
		model = "\DZ\characters\masks\Balaclava_g.p3d";
		ContinuousActions[] = {190};
		inventorySlot = "Mask";
		itemInfo[] = {"Clothing","Mask"};
		rotationFlags = 1;
		weight = 130;
		itemSize[] = {3,2};
		ragQuantity = 1;
		absorbency = 0.9;
		heatIsolation = 0.8;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\Balaclava_m.p3d";
			female = "\DZ\characters\masks\Balaclava_f.p3d";
		};
	};
	class BalaclavaMask_Black: BalaclavaMask_ColorBase
	{
		scope = 2;
		color = "black";
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\DZ\characters\masks\data\Balaclava_black_co.paa","\DZ\characters\masks\data\Balaclava_black_co.paa","\DZ\characters\masks\data\Balaclava_black_co.paa"};
	};
	class BalaclavaMask_Blackskull: BalaclavaMask_ColorBase
	{
		scope = 2;
		color = "blackskull";
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\DZ\characters\masks\data\Balaclava_blackskull_co.paa","\DZ\characters\masks\data\Balaclava_blackskull_co.paa","\DZ\characters\masks\data\Balaclava_blackskull_co.paa"};
	};
	class BalaclavaMask_Beige: BalaclavaMask_ColorBase
	{
		scope = 2;
		color = "beige";
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\DZ\characters\masks\data\Balaclava_beige_co.paa","\DZ\characters\masks\data\Balaclava_beige_co.paa","\DZ\characters\masks\data\Balaclava_beige_co.paa"};
	};
	class BalaclavaMask_Blue: BalaclavaMask_ColorBase
	{
		scope = 2;
		color = "blue";
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\DZ\characters\masks\data\Balaclava_blue_co.paa","\DZ\characters\masks\data\Balaclava_blue_co.paa","\DZ\characters\masks\data\Balaclava_blue_co.paa"};
	};
	class BalaclavaMask_Green: BalaclavaMask_ColorBase
	{
		scope = 2;
		color = "green";
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\DZ\characters\masks\data\Balaclava_green_co.paa","\DZ\characters\masks\data\Balaclava_green_co.paa","\DZ\characters\masks\data\Balaclava_green_co.paa"};
	};
	class BalaclavaMask_Pink: BalaclavaMask_ColorBase
	{
		scope = 2;
		color = "pink";
		hiddenSelectionsTextures[] = {"\DZ\characters\masks\data\Balaclava_pink_co.paa","\DZ\characters\masks\data\Balaclava_pink_co.paa","\DZ\characters\masks\data\Balaclava_pink_co.paa"};
	};
	class BalaclavaMask_White: BalaclavaMask_ColorBase
	{
		scope = 2;
		color = "white";
		hiddenSelectionsTextures[] = {"\DZ\characters\masks\data\Balaclava_white_co.paa","\DZ\characters\masks\data\Balaclava_white_co.paa","\DZ\characters\masks\data\Balaclava_white_co.paa"};
	};
	class GP5GasMask: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_GP5GasMask0";
		descriptionShort = "$STR_CfgVehicles_GP5GasMask1";
		model = "\DZ\characters\masks\GP5GasMask_g.p3d";
		inventorySlot = "Mask";
		itemInfo[] = {"Clothing","Mask"};
		rotationFlags = 1;
		weight = 1090;
		itemSize[] = {3,3};
		absorbency = 0;
		heatIsolation = 0.6;
		visibilityModifier = 0.95;
		noHelmet = 1;
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\dz\characters\masks\data\GP5GasMask_white_co.paa","\dz\characters\masks\data\GP5GasMask_white_co.paa","\dz\characters\masks\data\GP5GasMask_white_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\masks\data\GP5GasMask.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\masks\data\GP5GasMask_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\masks\data\GP5GasMask_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\GP5GasMask_m.p3d";
			female = "\DZ\characters\masks\GP5GasMask_f.p3d";
		};
	};
	class Balaclava3Holes_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_Balaclava3Holes_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_Balaclava3Holes_ColorBase1";
		model = "\DZ\characters\masks\Balaclava_3holes_g.p3d";
		ContinuousActions[] = {190};
		inventorySlot = "Mask";
		itemInfo[] = {"Clothing","Mask"};
		rotationFlags = 17;
		weight = 300;
		itemSize[] = {3,2};
		ragQuantity = 2;
		absorbency = 0.85;
		heatIsolation = 0.8;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\masks\data\Balaclava_3holes.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\masks\data\Balaclava_3holes_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\masks\data\Balaclava_3holes_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\Balaclava_3holes_m.p3d";
			female = "\DZ\characters\masks\Balaclava_3holes_f.p3d";
		};
	};
	class Balaclava3Holes_Beige: Balaclava3Holes_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\masks\data\Balaklava_3holes_beige_co.paa","DZ\characters\masks\data\Balaklava_3holes_beige_co.paa","DZ\characters\masks\data\Balaklava_3holes_beige_co.paa"};
	};
	class Balaclava3Holes_Blue: Balaclava3Holes_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\masks\data\Balaklava_3holes_blue_co.paa","DZ\characters\masks\data\Balaklava_3holes_blue_co.paa","DZ\characters\masks\data\Balaklava_3holes_blue_co.paa"};
	};
	class Balaclava3Holes_Black: Balaclava3Holes_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\masks\data\Balaklava_3holes_co.paa","DZ\characters\masks\data\Balaklava_3holes_co.paa","DZ\characters\masks\data\Balaklava_3holes_co.paa"};
	};
	class Balaclava3Holes_Green: Balaclava3Holes_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\masks\data\Balaklava_3holes_green_co.paa","DZ\characters\masks\data\Balaklava_3holes_green_co.paa","DZ\characters\masks\data\Balaklava_3holes_green_co.paa"};
	};
	class SantasBeard: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SantasBeard0";
		descriptionShort = "$STR_CfgVehicles_SantasBeard1";
		model = "\DZ\characters\masks\SantasBeard_g.p3d";
		ContinuousActions[] = {190};
		inventorySlot = "Mask";
		itemInfo[] = {"Clothing","Mask"};
		weight = 220;
		itemSize[] = {3,1};
		ragQuantity = 1;
		absorbency = 0.98;
		heatIsolation = 0.25;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"dz\characters\masks\data\santasbeard_co.paa","dz\characters\masks\data\santasbeard_co.paa","dz\characters\masks\data\santasbeard_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\masks\data\SantasBeard.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\masks\data\SantasBeard_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\masks\data\SantasBeard_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\SantasBeard_m.p3d";
			female = "\DZ\characters\masks\SantasBeard_f.p3d";
		};
	};
	class MouthRag: Clothing
	{
		scope = 2;
		displayName = "$STR_cfgvehicles_rag0";
		descriptionShort = "$STR_cfgvehicles_rag1";
		model = "\DZ\gear\consumables\Rags.p3d";
		inventorySlot = "Mask";
		ChangeIntoOnDetach = "Rag";
		itemInfo[] = {"Clothing","Mask"};
		weight = 150;
		itemSize[] = {1,2};
		ragQuantity = 1;
		absorbency = 0.98;
		heatIsolation = 0;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		hiddenSelections[] = {"camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"DZ\characters\masks\data\mouth_rags_CO.paa","DZ\characters\masks\data\mouth_rags_CO.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\masks\data\mouth_rags.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\masks\data\mouth_rags_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\masks\data\mouth_rags_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\mouth_rags.p3d";
			female = "\DZ\characters\masks\mouth_rags.p3d";
		};
	};
	class SurgicalMask: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SurgicalMask0";
		descriptionShort = "$STR_CfgVehicles_SurgicalMask1";
		model = "\DZ\characters\masks\Surgical_mask_g.p3d";
		inventorySlot = "Mask";
		itemInfo[] = {"Clothing","Mask"};
		rotationFlags = 16;
		weight = 340;
		itemSize[] = {3,1};
		absorbency = 0.9;
		heatIsolation = 0.15;
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\DZ\characters\masks\data\surgical_mask_ground_co.paa","\DZ\characters\masks\data\surgical_mask_co.paa","\DZ\characters\masks\data\surgical_mask_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\masks\data\Surgical_mask.rvmat","DZ\characters\masks\data\Surgical_mask_ground.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\masks\data\Surgical_mask_damage.rvmat","DZ\characters\masks\data\Surgical_mask_ground_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\masks\data\Surgical_mask_destruct.rvmat","DZ\characters\masks\data\Surgical_mask_ground_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\Surgical_mask_m.p3d";
			female = "\DZ\characters\masks\Surgical_mask_f.p3d";
		};
	};
	class HockeyMask: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_HockeyMask0";
		descriptionShort = "$STR_CfgVehicles_HockeyMask1";
		model = "\DZ\characters\masks\VintageHockeyMask_g.p3d";
		inventorySlot = "Mask";
		itemInfo[] = {"Clothing","Mask"};
		weight = 555;
		itemSize[] = {3,2};
		heatIsolation = 0.25;
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\DZ\characters\masks\data\Vinitagehockeym_CO.paa","\DZ\characters\masks\data\Vinitagehockeym_CO.paa","\DZ\characters\masks\data\Vinitagehockeym_CO.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\masks\Data\Vintagehockeym.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\masks\Data\Vintagehockeym_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\masks\Data\Vintagehockeym_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					Health = 1;
					Blood = 1;
					Shock = 1;
				};
				class Melee
				{
					Health = 0.85;
					Blood = 0.8;
					Shock = 0.8;
				};
				class Infected
				{
					Health = 0.85;
					Blood = 0.8;
					Shock = 0.8;
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\VintageHockeyMask_m.p3d";
			female = "\DZ\characters\masks\VintageHockeyMask_f.p3d";
		};
	};
};
