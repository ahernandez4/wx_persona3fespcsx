#ifndef P3FMEM_H
#define P3FMEM_H
#if defined(_WIN32)
#include <Windows.h>
#include <tchar.h>
#endif
#ifdef __linux__
#include <stdint.h>
#include <fcntl.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <unistd.h>
#define LONG int32_t
#define DWORD uint32_t
#endif
class P3fMem
{
private:

	DWORD pcsxpid;
	
public:
	
	//static constant variables
	//Main Character
	static const LONG Mc_Level = 0x2083622A;
	static const LONG Mc_Current_HP = 0x2083622C;
	static const LONG Mc_Current_MP = 0x2083622E;
	static const LONG Mc_Equipped_Persona = 0x20836BA8;
	static const LONG Mc_Mood = 0x2083626C;
	static const LONG Mc_Academics = 0x20836260;
	static const LONG Mc_Charm = 0x20836262;
	static const LONG Mc_Courage = 0x20836264;
	static const LONG Mc_Money = 0x2083A6DC;

	//Persona 1
	static const LONG Persona1_Modifer = 0x20836BAE;
	static const LONG Persona1_Level = 0x20836BB0;
	static const LONG Persona1_Str = 0x20836BC8;
	static const LONG Persona1_Mag = 0x20836BC9;
	static const LONG Persona1_En = 0x20836BCA;
	static const LONG Persona1_Ag = 0x20836BCB;
	static const LONG Persona1_Luc = 0x20836BCC;
	static const LONG Persona1_Magic1 = 0x20836BB8;
	static const LONG Persona1_Magic2 = 0x20836BBA;
	static const LONG Persona1_Magic3 = 0x20836BBC;
	static const LONG Persona1_Magic4 = 0x20836BBE;
	static const LONG Persona1_Magic5 = 0x20836BC0;
	static const LONG Persona1_Magic6 = 0x20836BC2;
	static const LONG Persona1_Magic7 = 0x20836BC4;
	static const LONG Persona1_Magic8 = 0x20836BC6;

	//items
	//static const LONG Medicine = 0x010C2D92; //210c2d92 found it
	static const LONG Medicine = 0x210C2D92;
	static const LONG Medical_Powder = 0x010C2D94;
	static const LONG Bead = 0x210C2D96;
	static const LONG Snuff_Soul = 0x210C2D98;
	static const LONG Chewing_Soul = 0x210C2D9A;
	static const LONG Precious_Egg = 0x210C2D9C;
	static const LONG Soma = 0x210C2D9E;
	static const LONG Dis_Poison = 0x210C2DA0;
	static const LONG Revival_Bead = 0x210C2DA2;
	static const LONG Balm_of_Life = 0x210C2DA4;
	static const LONG Me_Patra_Gem = 0x210C2DA6;
	static const LONG Muscle_Drink = 0x210C2DA8;
	static const LONG Odd_Morsel = 0x210C2DAA;
	static const LONG Rancid_Gravy = 0x210C2DAC;
	static const LONG Powerful_Drug = 0x210C2DAE;
	static const LONG Umugi_Water = 0x210C2DB0;
	static const LONG Amrita_Water = 0x210C2DB2;
	static const LONG Nihil_Longsword = 0x210C2DB4;
	static const LONG Dis_Rage = 0x210C2DB6;
	static const LONG Dis_Charm = 0x210C2DB8;
	static const LONG Treasure_Box_Cash = 0x210C2DBA;
	static const LONG Purifying_Rice = 0x210C2DBC;
	static const LONG Curse_Paper = 0x210C2DBE;
	static const LONG Fierce_Sutra = 0x210C2DC0;
	static const LONG Agility_Sutra = 0x210C2DC2;
	static const LONG Protection_Sutra = 0x210C2DC4;
	static const LONG Flame_Magatama = 0x210C2DC6;
	static const LONG Gale_Magatama = 0x210C2DC8;
	static const LONG Frigid_Magatama = 0x210C2DCA;
	static const LONG Shock_Magatama = 0x210C2DCC;
	//static const LONG 0x401F = 0x210C2DCE;
	static const LONG Patra_Gem = 0x210C2DD0;
	static const LONG Traesto_Gem = 0x210C2DD2;
	static const LONG Bead_Chain = 0x210C2DD4;
	static const LONG Magic_Mirror = 0x210C2DD6;
	static const LONG Attack_Mirror = 0x210C2DD8;
	static const LONG Dekaja_Gem = 0x210C2DDA;
	static const LONG Dekunda_Gem = 0x210C2DDC;
	static const LONG Homunculus = 0x210C2DDE;
	static const LONG Plume_of_Dusk = 0x210C2DE0;
	static const LONG Agilao_Gem = 0x210C2DE2;
	static const LONG Maragi_Gem = 0x210C2DE4;
	static const LONG Bufula_Gem = 0x210C2DE6;
	static const LONG Mabufu_Gem = 0x210C2DE8;
	static const LONG Garula_Gem = 0x210C2DEA;
	static const LONG Magaru_Gem = 0x210C2DEC;
	static const LONG Zionga_Gem = 0x210C2DEE;
	static const LONG Mazio_Gem = 0x210C2DF0;
	static const LONG Megido_Gem = 0x210C2DF2;
	static const LONG Trafuri_Gem = 0x210C2DF4;
	//static const LONG 0x4033 = 0x210C2DF6;
	static const LONG Sword_of_Page = 0x210C2DF8;
	static const LONG Sword_of_Knight = 0x210C2DFA;
	static const LONG Sword_of_Queen = 0x210C2DFC;
	static const LONG Sword_of_King = 0x210C2DFE;
	static const LONG Cup_of_Page = 0x210C2E00;
	static const LONG Cup_of_Knight = 0x210C2E02;
	static const LONG Cup_of_Queen = 0x210C2E04;
	static const LONG Cup_of_King = 0x210C2E06;
	static const LONG Wand_of_Page = 0x210C2E08;
	static const LONG Wand_of_Knight = 0x210C2E0A;
	static const LONG Wand_of_Queen = 0x210C2E0C;
	static const LONG Wand_of_King = 0x210C2E0E;
	static const LONG Coin_of_Page = 0x210C2E10;
	static const LONG Coin_of_Knight = 0x210C2E12;
	static const LONG Coin_of_Queen = 0x210C2E14;
	static const LONG Coin_of_King = 0x210C2E16;
	//static const LONG 0x4044 = 0x210C2E18;
	static const LONG Nihil_Sword = 0x210C2E1A;
	static const LONG Nihil_Gloves = 0x210C2E1C;
	static const LONG Nihil_Spear = 0x210C2E1E;
	static const LONG Nihil_Bow = 0x210C2E20;
	static const LONG Nihil_Axe = 0x210C2E22;
	static const LONG Nihil_Knife = 0x210C2E24;
	static const LONG Nihil_Gun = 0x210C2E26;
	//static const LONG 0x404C = 0x210C2E28;
	//static const LONG 0x404D = 0x210C2E2A;
	//static const LONG 0x404E = 0x210C2E2C;
	//static const LONG 0x404F = 0x210C2E2E;
	static const LONG Rose_Bouquet = 0x210C2E30;
	static const LONG Red_Pine_Bonsai = 0x210C2E32;
	static const LONG Mini_Cactus = 0x210C2E34;
	static const LONG Glass_Vase = 0x210C2E36;
	static const LONG Perfume = 0x210C2E38;
	static const LONG Brand_Purse = 0x210C2E3A;
	static const LONG Brand_Watch = 0x210C2E3C;
	static const LONG Brand_Bag = 0x210C2E3E;
	static const LONG Teddy_Bear = 0x210C2E40;
	static const LONG Japanese_Doll = 0x210C2E42;
	static const LONG Kaleidoscope = 0x210C2E44;
	static const LONG Goggle_eyed_Idol = 0x210C2E46;
	static const LONG Jack_Frost_Doll = 0x210C2E48;
	static const LONG Book_Cover = 0x210C2E4A;
	static const LONG Lucky_Charm = 0x210C2E4C;
	static const LONG Ganesha_Bank = 0x210C2E4E;
	static const LONG Amethyst = 0x210C2E50;
	static const LONG Aquamarine = 0x210C2E52;
	static const LONG Emerald = 0x210C2E54;
	static const LONG Onyx = 0x210C2E56;
	static const LONG Opal = 0x210C2E58;
	static const LONG Garnet = 0x210C2E5A;
	static const LONG Sapphire = 0x210C2E5C;
	static const LONG Diamond = 0x210C2E5E;
	static const LONG Turquoise = 0x210C2E60;
	static const LONG Topaz = 0x210C2E62;
	static const LONG Pearl = 0x210C2E64;
	static const LONG Ruby = 0x210C2E66;
	static const LONG Weird_Takoyaki = 0x210C2E68;
	static const LONG Wild_Burger = 0x210C2E6A;
	static const LONG Instant_Ramen = 0x210C2E6C;
	static const LONG Side_Dish = 0x210C2E6E;
	static const LONG Dr_Salt = 0x210C2E70;
	static const LONG Mad_Bull = 0x210C2E72;
	static const LONG SoBay = 0x210C2E74;
	static const LONG Moonkist = 0x210C2E76;
	static const LONG Cielo_Mist = 0x210C2E78;
	static const LONG Nestea = 0x210C2E7A;
	static const LONG BauerBar = 0x210C2E7C;
	static const LONG Cylon_Tea = 0x210C2E7E;
	static const LONG OneUP = 0x210C2E80;
	static const LONG Starvicks = 0x210C2E82;
	static const LONG Aguafeena = 0x210C2E84;
	static const LONG Durian_Soda = 0x210C2E86;
	static const LONG Fountain_Dew = 0x210C2E88;
	static const LONG Jumbo_Juice = 0x210C2E8A;
	static const LONG V6 = 0x210C2E8C;
	static const LONG Special_Drink = 0x210C2E8E;
	static const LONG Beetle_Shell = 0x210C2E90;
	static const LONG Old_Lantern = 0x210C2E92;
	static const LONG Yakisoba_Bread = 0x210C2E94;
	static const LONG Apple_Strudel = 0x210C2E96;
	static const LONG Cutlet_Sandwich = 0x210C2E98;
	static const LONG Melon_Bread = 0x210C2E9A;
	static const LONG Crab_Bread = 0x210C2E9C;
	static const LONG Fried_Bread = 0x210C2E9E;
	static const LONG Coffee_Jelly = 0x210C2EA0;
	static const LONG Chocolate_Cake = 0x210C2EA2;
	static const LONG Fuuka_s_Cookie	= 0x210C2EA4;
	static const LONG Champagne = 0x210C2EA6;
	static const LONG Medicated_Patch = 0x210C2EA8;
	static const LONG Handmade_Keychain = 0x210C2EAA;
	//static const LONG 0x408E = 0x210C2EAC;
	//static const LONG 0x408F = 0x210C2EAE;
	static const LONG Wealth_Coin = 0x210C2EB0;
	static const LONG Treasure_Coin = 0x210C2EB2;
	static const LONG Supreme_Coin = 0x210C2EB4;
	static const LONG Opulent_Coin = 0x210C2EB6;
	static const LONG Luxury_Coin = 0x210C2EB8;
	static const LONG Glorious_Coin = 0x210C2EBA;
	static const LONG Megidolaon_Gem = 0x210C2EBC;
	static const LONG Oden_Juice = 0x210C2EBE;
	static const LONG Super_Cat_Food = 0x210C2EC0;
	static const LONG Red_Quillon = 0x210C2EC2;
	static const LONG White_Quillon = 0x210C2EC4;
	static const LONG Black_Quillon = 0x210C2EC6;
	//static const LONG 0x409C = 0x210C2EC8;
	//static const LONG 0x409D = 0x210C2ECA;
	static const LONG Lead_Medal = 0x210C2ECC;
	static const LONG Steel_Medal = 0x210C2ECE;
	static const LONG Bronze_Medal = 0x210C2ED0;
	static const LONG Silver_Medal = 0x210C2ED2;
	static const LONG Gold_Medal = 0x210C2ED4;
	static const LONG Anatomical_Model = 0x210C2ED6;
	static const LONG Gekkoukan_Boogie = 0x210C2ED8;
	static const LONG Queen_Elizabeth = 0x210C2EDA;
	static const LONG Mahjong_Tile = 0x210C2EDC;
	static const LONG Inari_Sushi = 0x210C2EDE;
	static const LONG Platinum_Medal = 0x210C2EE0;
	static const LONG Bronze_Figurine = 0x210C2EE2;
	static const LONG Snake_Scale = 0x210C2EE4;
	static const LONG Relic_Fragment = 0x210C2EE6;
	static const LONG Greasy_Gear = 0x210C2EE8;
	static const LONG Tiara_s_Hair	= 0x210C2EEA;
	static const LONG Knight_s_Reins	= 0x210C2EEC;
	static const LONG Empress_s_Mirror	= 0x210C2EEE;
	static const LONG Gold_Handguard = 0x210C2EF0;
	static const LONG Gold_Ring = 0x210C2EF2;
	static const LONG Red_Armor_Plate = 0x210C2EF4;
	static const LONG Pink_Feather = 0x210C2EF6;
	static const LONG Moon_Tablet = 0x210C2EF8;
	static const LONG Sand_of_Time = 0x210C2EFA;
	static const LONG Rainbow_Hair = 0x210C2EFC;
	static const LONG Bloody_Button = 0x210C2EFE;
	static const LONG Shadow_Shard = 0x210C2F00;
	static const LONG Shadow_Crystal = 0x210C2F02;
	static const LONG Empress_s_Mask	= 0x210C2F04;
	static const LONG Vibrant_Cloth = 0x210C2F06;
	static const LONG Beetle_Horn = 0x210C2F08;
	static const LONG Golden_Beard = 0x210C2F0A;
	static const LONG Massive_Wheel = 0x210C2F0C;
	static const LONG Dense_Rock = 0x210C2F0E;
	static const LONG Broken_Heart = 0x210C2F10;
	static const LONG Fine_Statuette = 0x210C2F12;
	static const LONG Nama_yatsuhashi = 0x210C2F14;
	static const LONG Pickled_Turnip = 0x210C2F16;
	static const LONG Konpeito = 0x210C2F18;
	static const LONG Mibu_Cracker = 0x210C2F1A;
	static const LONG Diet_Food = 0x210C2F1C;
	static const LONG Super_Diet_Food = 0x210C2F1E;
	static const LONG Veggie_Supplement = 0x210C2F20;
	static const LONG Health_Supplement = 0x210C2F22;
	static const LONG Mega_Protein = 0x210C2F24;
	static const LONG Sappy_Jelly = 0x210C2F26;
	static const LONG Mind_Supplement = 0x210C2F28;
	static const LONG Copper_Doorknob = 0x210C2F2A;
	static const LONG Silver_Glasses = 0x210C2F2C;
	static const LONG Golden_Pacifier = 0x210C2F2E;
	static const LONG Platinum_Noseplug = 0x210C2F30;
	static const LONG Diamond_Pickler = 0x210C2F32;
	static const LONG Steel_Right_Arm = 0x210C2F34;
	static const LONG Broken_Wheel = 0x210C2F36;
	static const LONG Shining_Beard = 0x210C2F38;
	static const LONG Ebon_Heart = 0x210C2F3A;
	static const LONG Fire_Element = 0x210C2F3C;
	static const LONG Thunder_Element = 0x210C2F3E;
	static const LONG Ice_Element = 0x210C2F40;
	static const LONG Throne_of_Ruin = 0x210C2F42;
	static const LONG Burning_Grail = 0x210C2F44;
	static const LONG Scarlet_Choker = 0x210C2F46;
	static const LONG Infernal_Armor = 0x210C2F48;
	static const LONG Bloody_Horse = 0x210C2F4A;
	static const LONG All_Seeing_Eye = 0x210C2F4C;
	
	bool SetPcsx2();
	void WriteValue(LONG pokeAddress, int value, int bytesize);
	int SetItemAmount(LONG itemname, int amount);
	int SetMainCharacterLevel(int value);
	int SetMainCharacterHP(int value);
	int SetMainCharacterMP(int value);
	int SetMainCharacterMood(int value);
	int SetMainCharacterAcademics(int value);
	int SetMainCharacterCharm(int value);
	int SetMainCharacterCourage(int value);
	int SetMainCharacterMoney(int value);
	int SetDesiredPersona(int personaSlot, int value);
	int SetPersonaLevel(int personaSlot, int value);
	int SetPersonaSt(int personaSlot, int value);
	int SetPersonaMa(int personaSlot, int value);
	int SetPersonaEn(int personaSlot, int value);
	int SetPersonaAg(int personaSlot, int value);
	int SetPersonaLu(int personaSot, int value);
	int SetPersonaMagic1(int personaSlot, int value);
	int SetPersonaMagic2(int personaSlot, int value);
	int SetPersonaMagic3(int personaSlot, int value);
	int SetPersonaMagic4(int personaSlot, int value);
	int SetPersonaMagic5(int personaSlot, int value);
	int SetPersonaMagic6(int personaSlot, int value);
	int SetPersonaMagic7(int personaSlot, int value);
	int SetPersonaMagic8(int personaSlot, int value);
};

#endif