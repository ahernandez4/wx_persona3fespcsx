#ifndef WX_PERSONA3FESPCSX2_H
#define WX_PERSONA3FESPCSX2_H

#include <wx/wxprec.h>
#include <wx/wx.h>
#include <wx/xrc/xmlres.h>
#include <wx/spinctrl.h>
#include <wx/choice.h>
#include "P3fMem.h"
#include <wx/dataview.h>
class MyApp : public wxApp {
public:
	virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
	MyFrame();
	void CleanUp();
private:
	//void OnHello(wxCommandEvent &event);
	void OnExit(wxCommandEvent &event);
	void OnChangeHPSpinCtrl(wxSpinEvent &event);
	void OnChangeLevelSpinCtrl(wxSpinEvent &event);
	void OnChangeMPSpinCtrl(wxSpinEvent &event);
	void OnChangeMoneySpinCtrl(wxSpinEvent &event);
	void OnChangeAcademicsSpinCtrl(wxSpinEvent &event);
	void OnChangeCharmSpingCtrl(wxSpinEvent &event);
	void OnChangeCourageSpinCtrl(wxSpinEvent &event);
	void OnChangeMoodChoice(wxCommandEvent &event);
	void OnValueChange(wxDataViewEvent & event);
	void OnStartEdit(wxDataViewEvent &event);
	void OnChangePersonaStSpinCtrl(wxSpinEvent &event);
	void OnChangePersonaMaSpinCtrl(wxSpinEvent &event);
	void OnChangePersonaEnSpinCtrl(wxSpinEvent &event);
	void OnChangePersonaAgSpinCtrl(wxSpinEvent &event);
	void OnChangePersonaLuSpinCtrl(wxSpinEvent &event);
	void OnChangePersonaLevelSpinCtrl(wxSpinEvent &event);
	void OnChangeMagicSlot1Choice(wxCommandEvent &event);
	void OnChangeMagicSlot2Choice(wxCommandEvent &event);
	void OnChangeMagicSlot3Choice(wxCommandEvent &event);
	void OnChangeMagicSlot4Choice(wxCommandEvent &event);
	void OnChangeMagicSlot5Choice(wxCommandEvent &event);
	void OnChangeMagicSlot6Choice(wxCommandEvent &event);
	void OnChangeMagicSlot7Choice(wxCommandEvent &event);
	void OnChangeMagicSlot8Choice(wxCommandEvent &event);
	void OnChagePersonaModifierChoice(wxCommandEvent &event);
	
	//void OnAbout(wxCommandEvent &event);
	//constants 
	const char *choices[624] = { "Slash Attack", "Agi", "Agilao", "Agidyne",
			"Maragi", "Maragion", "Maragidyne", "Maralagidyne", "0x008", "Ragnarok", "Garu", "Garula", "Garudyne", "Magaru", "Magarula",
			"Magarudyne", "0x010", "0x011", "Panta Rhei", "Bufu", "Bufula", "Bufudyne", "Mabufu", "Mabufula", "Mabufudyne", "0x019",
			"0x01A", "Niflheim", "Zio", "Zionga", "Ziodyne", "Mazio", "Mazionga", "Maziodyne", "0x022", "0x023", "Thunder Reign",
			"Megido", "Megidola", "Megidolaon", "Last Resort", "0x029", "0x02A", "Black Viper", "Morning Star", "Hama", "Mahama",
			"Hamaon", "Mahamaon", "0x031", "Samsara", "Mudo", "Mamudo", "Mudoon", "Mamudoon", "0x037", "Die for Me!", "Marin Karin",
			"Sexy Dance", "Bewilder", "Eerie Sound", "Pulinpa", "Tentarafoo", "Evil Touch", "Evil Smile", "Ghastly Wai", "Provoke",
			"Infuriate", "Poisma", "Poison Mist", "Virus Breath", "0x047", "0x048", "Foul Breath", "Stagnant Air", "Life Drain",
			"Spirit Drain", "0x04D", "0x04E", "0x04F", "Maragidyne", "Magarudyne", "Mabufudyne", "Maziodyne", "Megidolaon", "Mahamaon",
			"Mamudoon", "Sexy Dance", "Eerie Sound", "Tentarafoo", "Evil Smile", "Poison Mist", "Holy Arrow", "Life Drain", "Spirit Drain",
			"0x05F", "Death", "Yel", "Yel", "Death", "Death", "Death", "Moonless Gown", "Moonless Gown", "Summon", "Slash Attack",
			"Pierce Attack", "Strike Attack", "Yel", "Pierce Attack", "Fire Attack", "Almighty Attack", "Bash", "Assault Dive",
			"Kill Rush", "Swift Strike", "Sonic Punch", "Heat Wave", "Gigantic Fist", "Akasha Arts", "God\'s Hand", "Cleave", "Fatal End",
			"Getsu-ei", "Zan-ei", "Mighty Swing", "Double Fangs", "Blade of Fury", "Deathbound", "Tempest Slash", "Heaven\'s Blade",
			"Pralaya", "Power Slash", "Gale Slash", "Brave Blade", "Herculean Strike", "Vicious Strike", "Single Shot", "Twin Shot",
			"Holy Arrow", "Torrent Shot", "Arrow Rain", "Myriad Arrows", "Primal Force", "Vorpal Blade", "Weary Thrust", "Cruel Attack",
			"Vile Assault", "Poison Arrow", "Weary Thrust", "Vorpal Blade", "0x097", "0x098", "0x099", "0x09A", "0x09B", "0x09C",
			"0x09D", "0x09E", "0x09F", "+charm(low)", "+charm(med)", "+charm(high)", "+distress(low)", "+distress(med)", "+distress(high)",
			"+panic(low)", "+panic(med)", "+panic(high)", "+fear(low)", "+fear(med)", "+fear(high)", "+rage(low)", "+rage(med)",
			"+rage(high)", "+poison(low)", "0x0B0", "0x0B1", "0x0B2", "0x0B3", "0x0B4", "0x0B5", "0x0B6", "0x0B7", "0x0B8", "0x0B9",
			"0x0BA", "0x0BB", "0x0BC", "0x0BD", "0x0BE", "0x0BF", "Dia", "Diarama", "Diarahan", "Media", "Mediarama", "Mediarahan",
			"Salvation", "Patra", "Me Patra", "Re Patra", "Posumudi", "Amrita", "Recarm", "Samarecarm", "Tarunda", "Matarunda",
			"Sukunda", "Masukunda", "Rakunda", "Marakunda", "Dekunda", "0x0D5", "Tarukaja", "Matarukaja", "Sukukaja", "Masukukaja",
			"Rakukaja", "Marakukaja", "Power Charge", "Mind Charge", "0x0DE", "Dekaja", "Tetrakarn", "Makarakarn", "Rebellion",
			"Revolution", "0x0E4", "Fire Break", "Ice Break", "Wind Break", "Elec Break", "Traesto", "Trafuri", "Healing Wave",
			"Recarmdra", "Charmdi", "Enradi", "0x0EF", "0x0F0", "0x0F1", "0x0F2", "0x0F3", "0x0F4", "0x0F5", "0x0F6", "0x0F7",
			"0x0F8", "0x0F9", "0x0FA", "0x0FB", "0x0FC", "0x0FD", "0x0FE", "0x0FF", "Summer Dream", "Summer Dream", "Summer Dream",
			"Summer Dream", "Summer Dream", "Summer Dream", "Summer Dream", "Summer Dream", "Summer Dream", "Summer Dream", "Summer Dream",
			"Summer Dream", "Summer Dream", "Summer Dream", "Summer Dream", "Summer Dream", "Jack Brothers", "Ardhanari", "Trickster",
			"Infinity", "Valhalla", "Summer Dream", "Armageddon", "Cadenza", "Scarlet Havoc", "Frolic", "Dreamfest", "King and I",
			"Best Friends", "Shadow Hound", "Thunder Cal", "Last Judge", "Raktapaksha", "Justice", "Trickster", "0x123", "0x124",
			"Primal Darkness", "Dark Embrace", "Primal Darkness", "Primal Darkness", "0x129", "0x12A", "0x12B", "0x12C", "0x12D",
			"0x12E", "0x12F", "Pierce Attack", "Fire Attack", "Summon", "Summon", "Armed&Ready", "Sacrifice", "Arcana Shift", "Arcana Shift",
			"Arcana Shift", "Arcana Shift", "Arcana Shift", "Arcana Shift", "Arcana Shift", "Arcana Shift", "Arcana Shift", "Night Queen",
			"All-Out 2", "All-Out 3", "All-Out 4", "Plume of Dusk", "Analyze", "Oracle", "Full Analysis", "Oracle", "Oracle", "Oracle",
			"Oracle", "Oracle", "All-Out 2", "All-Out 3", "All-Out 4", "Support Scan", "Third Eye", "Mind DJ", "DJ Queen", "Escape Route",
			"Healing Wave", "Summon", "Orgia Mode", "Great Sea", "0x158", "0x159", "Ice Attack", "Wind Attack", "Elec Attack",
			"Fire Attack", "Pierce Attack", "Strike Attack", "Summon", "Summon", "Summon", "Prophecy of Ruin", "Heartbreaker", "Unite",
			"Separate", "Pierce Attack", "Pierce Attack", "Samarecarm", "Samarecarm", "Charge", "Giga Spark", "Wheel of Fortune",
			"Wheel of Fortune", "Wheel of Fortune", "Paradigm Shift", "Wheel of Fortune", "Wheel of Fortune", "E Attack Up", "P Attack Up",
			"E Attack Down", "P Attack Down", "E Defense Up", "P Defense Up", "E Defense Down", "P Defense Down", "E Panic", "P Panic",
			"E Rage", "P Rage", "E Distress", "P Distress", "E Fear", "P Fear", "E Damage Low", "P Damage Low", "E Damage Mid",
			"P Damage Mid", "E Damage High", "P Damage High", "E Hea", "P Hea", "Almighty Attack", "Arcana Shift", "Arcana Shift",
			"Arcana Shift", "Arcana Shift", "Band Aid", "Medicine", "Bead", "Snuff Sou", "Chewing Sou", "Precious Egg", "Soma",
			"0x197", "0x198", "0x199", "0x19A", "Muscle Drink", "Odd Morse", "Rancid Gravy", "Powerful Drug", "Cold Medicine",
			"Energy Drink", "0x1A1", "0x1A2", "0x1A3", "0x1A4", "0x1A5", "0x1A6", "0x1A7", "0x1A8", "0x1A9", "0x1AA", "0x1AB",
			"0x1AC", "0x1AD", "0x1AE", "0x1AF", "0x1B0", "0x1B1", "0x1B2", "0x1B3", "0x1B4", "0x1B5", "Homunculus", "Plume of Dusk",
			"0x1B8", "0x1B9", "0x1BA", "0x1BB", "0x1BC", "0x1BD", "0x1BE", "0x1BF", "0x1C0", "0x1C1", "0x1C2", "0x1C3", "0x1C4",
			"0x1C5", "0x1C6", "0x1C7", "0x1C8", "0x1C9", "0x1CA", "0x1CB", "0x1CC", "0x1CD", "0x1CE", "0x1CF", "Resist Slash",
			"Null Slash", "Repel Slash", "Absorb Slash", "Resist Strike", "Null Strike", "Repel Strike", "Absorb Strike", "Resist Pierce",
			"Null Pierce", "Repel Pierce", "Absorb Pierce", "Resist Fire", "Null Fire", "Repel Fire", "Absorb Fire", "Resist Ice",
			"Null Ice", "Repel Ice", "Absorb Ice", "Resist Elec", "Null Elec", "Repel Elec", "Absorb Elec", "Resist Wind", "Null Wind",
			"Repel Wind", "Absorb Wind", "Resist Light", "Null Light", "Repel Light", "Resist Dark", "Null Dark", "Repel Dark", "Null Charm",
			"Null Distress", "Null Panic", "Null Fear", "Null Rage", "Null Freeze", "Null Shock", "Null Poison", "Unshaken Wil",
			"Masakados", "Dodge Slash", "Evade Slash", "Dodge Strike", "Evade Strike", "Dodge Pierce", "Evade Pierce", "Dodge Fire",
			"Evade Fire", "Dodge Ice", "Evade Ice", "Dodge Wind", "Evade Wind", "Dodge Elec", "Evade Elec", "Stamina Up 1", "Stamina Up 2",
			"Stamina Up 3", "0x20D", "Premonition", "Angelic Grace", "Fire Boost", "Fire Amp", "Ice Boost", "Ice Amp", "Elec Boost",
			"Elec Amp", "Wind Boost", "Wind Amp", "Fast Retreat", "HP Up 1", "HP Up 2", "HP Up 3", "SP Up 1", "SP Up 2", "SP Up 3",
			"Raging Tiger", "Counter", "Counterstrike", "High Counter", "Regenerate 1", "Regenerate 2", "Regenerate 3", "Invigorate 1",
			"Invigorate 2", "Invigorate 3", "Growth 1", "Growth 2", "Growth 3", "0x22C", "Auto-Tarukaja", "Auto-Rakukaja", "Auto-Sukukaja",
			"Alertness", "Sharp Student", "Apt Pupi", "Ali Dance", "Firm Stance", "Spell Master", "Arms Master", "HP Up", "SP Up",
			"0x239", "Divine Grace", "Endure", "Enduring Sou", "Heavy Master", "Magic Skill Up", "Phys Skill Up", "0x240", "0x240",
			"0x240", "0x243", "Rosary", "Prayer Beads", "Spear Master", "Bow Master", "1hSwd Master", "2hSwd Master", "Fist Master",
			"Survive Light", "Survive Dark", "Auto-Maraku", "Auto-Mataru", "Auto-Masuku", "Charm Boost", "Poison Boost", "Distress Boost",
			"Panic Boost", "Fear Boost", "Rage Boost", "Ailment Boost", "Hama Boost", "Mudo Boost", "Endure Light", "Endure Dark",
			"0x25B", "0x25C", "Cool Breeze", "Victory Cry", "Spring of Life", "Spring of Life", "For Debug", "Fast-Hea", "Insta-Hea",
			"Resist Charm", "Resist Distress", "Resist Panic", "Resist Fear", "Resist Rage", "Resist Freeze", "Resist Shock", "Resist Poison",
			"HP Up High", "SP Up High", "0x26E", "0x26F" };
	const char *inventoryItems[222] = {
			"Medicine",
			"Medical Powder",
			"Bead",
			"Snuff Soul",
			"Chewing Soul",
			"Precious Egg",
			"Soma",
			"Dis-Poison",
			"Revival Bead",
			"Balm of Life",
			"Me Patra Gem",
			"Muscle Drink",
			"Odd Morsel",
			"Rancid Gravy",
			"Powerful Drug",
			"Umugi Water",
			"Amrita Water",
			"Nihil Longsword",
			"Dis-Rage",
			"Dis-Charm",
			"Treasure Box Cash",
			"Purifying Rice",
			"Curse Paper",
			"Fierce Sutra",
			"Agility Sutra",
			"Protection Sutra",
			"Flame Magatama",
			"Gale Magatama",
			"Frigid Magatama",
			"Shock Magatama",
			"0x401F",
			"Patra Gem",
			"Traesto Gem",
			"Bead Chain",
			"Magic Mirror",
			"Attack Mirror",
			"Dekaja Gem",
			"Dekunda Gem",
			"Homunculus",
			"Plume of Dusk",
			"Agilao Gem",
			"Maragi Gem",
			"Bufula Gem",
			"Mabufu Gem",
			"Garula Gem",
			"Magaru Gem",
			"Zionga Gem",
			"Mazio Gem",
			"Megido Gem",
			"Trafuri Gem",
			"0x4033",
			"Sword of Page",
			"Sword of Knight",
			"Sword of Queen",
			"Sword of King",
			"Cup of Page",
			"Cup of Knight",
			"Cup of Queen",
			"Cup of King",
			"Wand of Page",
			"Wand of Knight",
			"Wand of Queen",
			"Wand of King",
			"Coin of Page",
			"Coin of Knight",
			"Coin of Queen",
			"Coin of King",
			"0x4044",
			"Nihil Sword",
			"Nihil Gloves",
			"Nihil Spear",
			"Nihil Bow",
			"Nihil Axe",
			"Nihil Knife",
			"Nihil Gun",
			"0x404C",
			"0x404D",
			"0x404E",
			"0x404F",
			"Rose Bouquet",
			"Red Pine Bonsai",
			"Mini Cactus",
			"Glass Vase",
			"Perfume",
			"Brand Purse",
			"Brand Watch",
			"Brand Bag",
			"Teddy Bear",
			"Japanese Doll",
			"Kaleidoscope",
			"Goggle-eyed Idol",
			"Jack Frost Doll",
			"Book Cover",
			"Lucky Charm",
			"Ganesha Bank",
			"Amethyst",
			"Aquamarine",
			"Emerald",
			"Onyx",
			"Opal",
			"Garnet",
			"Sapphire",
			"Diamond",
			"Turquoise",
			"Topaz",
			"Pearl",
			"Ruby",
			"Weird Takoyaki",
			"Wild Burger",
			"Instant Ramen",
			"Side Dish",
			"Dr. Salt",
			"Mad Bull",
			"SoBay",
			"Moonkist",
			"Cielo Mist",
			"Nestea",
			"BauerBar",
			"Cylon Tea",
			"1UP",
			"Starvicks",
			"Aguafeena",
			"Durian Soda",
			"Fountain Dew",
			"Jumbo Juice",
			"V6",
			"Special Drink",
			"Beetle Shell",
			"Old Lantern",
			"Yakisoba Bread",
			"Apple Strudel",
			"Cutlet Sandwich",
			"Melon Bread",
			"Crab Bread",
			"Fried Bread",
			"Coffee Jelly",
			"Chocolate Cake",
			"Fuuka's Cookie",
			"Champagne",
			"Medicated Patch",
			"Handmade Keychain",
			"0x408E",
			"0x408F",
			"Wealth Coin",
			"Treasure Coin",
			"Supreme Coin",
			"Opulent Coin",
			"Luxury Coin",
			"Glorious Coin",
			"Megidolaon Gem",
			"Oden Juice",
			"Super Cat Food",
			"Red Quillon",
			"White Quillon",
			"Black Quillon",
			"0x409C",
			"0x409D",
			"Lead Medal",
			"Steel Medal",
			"Bronze Medal",
			"Silver Medal",
			"Gold Medal",
			"Anatomical Model",
			"Gekkoukan Boogie",
			"Queen Elizabeth",
			"Mahjong Tile",
			"Inari Sushi",
			"Platinum Medal",
			"Bronze Figurine",
			"Snake Scale",
			"Relic Fragment",
			"Greasy Gear",
			"Tiara's Hair",
			"Knight's Reins",
			"Empress's Mirror",
			"Gold Handguard",
			"Gold Ring",
			"Red Armor Plate",
			"Pink Feather",
			"Moon Tablet",
			"Sand of Time",
			"Rainbow Hair",
			"Bloody Button",
			"Shadow Shard",
			"Shadow Crystal",
			"Empress's Mask",
			"Vibrant Cloth",
			"Beetle Horn",
			"Golden Beard",
			"Massive Wheel",
			"Dense Rock",
			"Broken Heart",
			"Fine Statuette",
			"Nama-yatsuhashi",
			"Pickled Turnip",
			"Konpeito",
			"Mibu Cracker",
			"Diet Food",
			"Super Diet Food",
			"Veggie Supplement",
			"Health Supplement",
			"Mega Protein",
			"Sappy Jelly",
			"Mind Supplement",
			"Copper Doorknob",
			"Silver Glasses",
			"Golden Pacifier",
			"Platinum Noseplug",
			"Diamond Pickler",
			"Steel Right Arm",
			"Broken Wheel",
			"Shining Beard",
			"Ebon Heart",
			"Fire Element",
			"Thunder Element",
			"Ice Element",
			"Throne of Ruin",
			"Burning Grail",
			"Scarlet Choker",
			"Infernal Armor",
			"Bloody Horse",
			"All-Seeing Eye",

	};
	const char *personas[191] = { "0x000", "Orpheus", "Susano-o", "Flauros",
			"Loki", "Nekomata", "Pyro Jack", "Jack Frost", "Scathach", "Rangda", "Nata Taishi", "Cu Chulainn", "Ose", "Kusi Mitama",
			"Apsaras", "Laksmi", "Parvati", "Kikuri-Hime", "Sati", "Sarasvati", "Unicorn", "Cybele", "Skadi", "Hariti", "Kali",
			"Ganga", "Taraka", "Lamia", "Odin", "King Frost", "Okuninushi", "Kingu", "Raja Naga", "Forneus", "Kohryu", "Mithra",
			"Daisoujou", "Ananta", "Omoikane", "Principality", "Raphae", "Titania", "Oberon", "Narcissus", "Queen Mab", "Leanan Sidhe",
			"Pixie", "Urie", "Surt", "Throne", "Ares", "Titan", "Chimera", "Ara Mitama", "Valkyrie", "Melchizedek", "Dominion",
			"Siegfried", "Virtue", "Power", "Archange", "Ange", "Alilat", "Arahabaki", "Nebiros", "Decarabia", "Kurama Tengu",
			"Yomotsu Shikome", "Naga", "Norn", "Atropos", "Orobas", "Lachesis", "Saki Mitama", "Eligor", "Clotho", "Fortuna", "Thor",
			"Bishamonten", "Take-Mikazuchi", "Jikokuten", "Hanuman", "Koumokuten", "Zouchouten", "Attis", "Vasuki", "Orthrus", "Take-Minakata",
			"Ubelluris", "Inugami", "Thanatos", "Alice", "Seth", "Mot", "Samae", "Vetala", "Loa", "Pale Rider", "Michae", "Byakko",
			"Suzaku", "Seiryu", "Nigi Mitama", "Genbu", "Beelzebub", "Mother Harlot", "Abaddon", "Lilith", "Incubus", "Succubus",
			"Lilim", "Chi You", "Shiva", "Masakado", "Seiten Taisei", "Yamano-orochi", "Oumitsunu", "Hele", "Sandalphon", "Black Frost",
			"Garuda", "Kaiwan", "Ganesha", "Nandi", "Chernobog", "Sionysus", "Narasimha", "Girimehkala", "Gurr", "Legion", "Berith",
			"Saturnus", "Vishnu", "Barong", "Jatayu", "Horus", "Quetzalcoat", "Yatagarasu", "Messiah", "Asura", "Metatron", "Satan",
			"Gabrie", "Hokuto Seikun", "Trumpeter", "Anubis", "Slime", "Hua Po", "High Pixie", "Yaksini", "Shiisaa", "Thoth",
			"Alp", "Mothman", "Kumbhanda", "Empusa", "Rakshasa", "Hecatoncheires", "Hell Biker", "Ghou", "Yurlungur", "Pazuzu",
			"Mara", "Kartikeya", "Baal Zebu", "Suparna", "Lucifer", "Nidhoggr", "Atavaka", "Orpheus Telos", "Universe", "Io",
			"Isis", "Palladion", "Athena", " Penthesilea", "Artemisia", "Hermes", "Trismegistus", "Lucia", "Juno", "Polydeusces",
			"Caesar", "Nemesis", "Kala-Nemi", "Castor", "Cerbeus", "Hypnos", "Moros", "Medea", "Psyche" };
	const long ID_DVCLIST = 12789;
	//wxwindow derived classes // do not delete their memory 
	wxDataViewListCtrl *listViewDvc;
	wxChoice *magicChoiceSlot1;
	wxChoice *magicChoiceSlot2;
	wxChoice *magicChoiceSlot3;
	wxChoice *magicChoiceSlot4;
	wxChoice *magicChoiceSlot5;
	wxChoice *magicChoiceSlot6;
	wxChoice *magicChoiceSlot7;
	wxChoice *magicChoiceSlot8;
	wxSizer *panel8Sizer;
	wxPanel *wxPanel8;
	wxChoice *slotChoice;
	wxChoice *personaModifierChoice;

	//some variables
	wxString prevalue;
	wxArrayString magicChoices;
	wxArrayString personaChoices;
	
};
#endif