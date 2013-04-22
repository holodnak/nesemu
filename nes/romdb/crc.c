#include "crc.h"

rom_crc_t rom_crcs[] = {
	//konami classics
	{"Contra (KC)",								0x7708B286,0x00000000,"NES-UNROM",ROM_NOCHR},
	{"Castlevania II - Simon's Quest (KC)",0x9667CC88,0x1AFB99EB,"?",0},
	{"Super C (KC)",								0x603DA36D,0x153295C1,"NES-TLROM",0},
	{"Castlevania III - Dracula's Curse (KC)",0x40DBC815,0x1B448E0A,"?",0},
	{"Castlevania (KC)",							0xACEC652E,0x00000000,"NES-UNROM",ROM_NOCHR},
	{"Jackal (KC)",								0x718EB40A,0x00000000,"NES-UNROM",ROM_NOCHR},

	//gamecube
	{"Excitebike (GC)",				0x1FC03F23,0xE5F72401,"NES-NROM-128",0},
	{"Mario Bros. (GC)",				0xB792AE19,0x10F77435,"NES-NROM-256",0},
	{"Donkey Kong Jr. (GC)",		0x7114FC58,0x852778AB,"NES-NROM-256",0},
	{"Donkey Kong (GC)",				0x25F7EE6B,0xA21D7C2E,"NES-NROM-256",0},
	{"Golf (GC)",						0xF9622BFA,0xFF6FC790,"NES-NROM-128",SPRITE0_HACK},
	{"Pinball (GC)",					0x07639BAD,0xF2A53B3D,"NES-NROM-128",0},
	{"Legend of Zelda, The (GC)",	0x46E0D37D,0x00000000,"NES-SLROM",ROM_NOCHR},
	{"Tennis (GC)",					0x0012A6A2,0x3A34C45B,"NES-NROM-256",0},
	{"Punch-Out!! (GC)",				0xC032E5B0,0x45D0C815,"NES-PNROM",0},
	{"Soccer (GC)",					0x32E37DCB,0x307B19AB,"NES-NROM-256",0},

	{"Study and Game 32-in-1 (Ch)",						0xABB2F974,0x00000000,"STUDY-GAME-32IN1",ROM_NOCHR},

	//vrc2 games
	{"Contra (J)",												0x919AC0FE,0xC6172032,"KONAMI-VRC-2b",0},
	{"Ganbare Goemon 2 (J)",								0x112140A4,0xB0C3CE2D,"KONAMI-VRC-2b",0},

	//vrc4 games
	{"Wai Wai World 2 - SOS!! Paseri Jou (J)",		0xB201B522,0x75754679,"KONAMI-VRC-4a",0},
	{"Wai Wai World 2 - SOS!! Paseri Jou (J) [T+Eng1.01_Vice]",0xA254AA36,0x2FE36E59,"KONAMI-VRC-4a",0},
	{"Ganbare Goemon Gaiden 2 - Tenka no Zaihou (J)",0x7CC4778C,0xD6E82485,"KONAMI-VRC-4c",0},
	{"Teenage Mutant Hero Turtles 2 (J)",				0x5F82CB7D,0x4AA9B12A,"KONAMI-VRC-4d",0},
	{"Teenage Mutant Ninja Turtles (J)",				0xEA74C587,0xE1D75471,"KONAMI-VRC-4d",0},
	{"Akumajou Special - Boku Dracula Kun (J)",		0x93794634,0xC5D1196E,"KONAMI-VRC-4e",0},
	{"Parodius da! (J)",										0xE4CEEAD1,0x54DA5DC8,"KONAMI-VRC-4e",ROM_WRAM8K},

	//vrc6 games
	{"Mouryou Senki Madara (J)",							0x836CC1AB,0x8F895BD9,"KONAMI-VRC-6b",0},

	//translations
	{"Egypt (J) [T+Eng1.00_Dodgy]",								0x0F8FFE45,0x936F087D,"NES-CNROM",0},
	{"Final Fantasy III (J) [T-Eng][af]",						0x0C77DFF7,0x00000000,"NES-TNROM",ROM_NOCHR},
	{"Final Fantasy III (J) [T-Eng][ae]",						0xFDE2AEFC,0x00000000,"NES-TNROM",ROM_NOCHR},
	{"Final Fantasy III (J) [T+Eng0.1_toma]",					0x847084B9,0x00000000,"NES-TNROM",ROM_NOCHR},
	{"Final Fantasy III (J) [T+Eng3.1_AkIlLa]",				0xB52067FB,0x00000000,"NES-TNROM",ROM_NOCHR},
	{"Final Fantasy II (J) [T+Eng0.36_Toma&AlanMidas]",	0x1F53391E,0x00000000,"?",ROM_NOCHR},
	{"Final Fantasy II (J) [T+Eng1.03PasoFami_Demiforce]",0x775C8BE7,0x00000000,"?",ROM_NOCHR},
	{"Final Fantasy I & II (J) [o1][T+Eng1.00_Demiforce]",0x7531D99D,0x00000000,"?",ROM_NOCHR},
	{"Final Fantasy I & II (J) [T+Eng1.00_Demiforce]",		0x7531D99D,0x00000000,"?",ROM_NOCHR},
	{"Ganbare Goemon! - Karakuri Douchuu (J) [hFFE][T-Eng]",0x011BAEEE,0x00000000,"?",ROM_NOCHR},
	{"Ganbare Goemon! - Karakuri Douchuu (J) [T-Eng1.00]",0x664026BA,0xDC752E45,"?",0},
	{"Ganbare Goemon! - Karakuri Douchuu (J) [T-Eng1.01]",0xB9E44C8A,0xDC752E45,"?",0},
	{"Getsufuu Maden (J) [T-Eng1.0]",							0xF3E394D1,0xB1B9D143,"?",0},
	{"Gryzor (J) [T-Eng1.0] [a1] [o1]",							0x3078CDA9,0xB25030F8,"?",0},
	{"Gryzor (J) [T-Eng1.0] [o1]",								0x8A093F62,0xBDE7F40B,"?",0},
	{"Heisei Tensai Bakabon (J) [T+Eng_kingmike]",			0xABCE0B65,0xD1338C2B,"?",0},
	{"Hello Kitty no Ohanabatake (J) [T-Eng1.0][o1]",		0x72820B72,0xA64323C0,"NES-CNROM",0},
	{"Hello Kitty World (J) [T-Eng1.0][o1]",					0xE214B790,0x00000000,"NES-UNROM",ROM_NOCHR},
	{"Herakles no Eikou 2 - Titan no Metsubou (J) [T+Eng1.31_Toma]",0xAB8DE091,0x00000000,"?",ROM_NOCHR},
	{"Herakles no Eikou 2 - Titan no Metsubou (J) [T-Eng0.13_Toma]",0x0DEB3B1E,0x00000000,"?",ROM_NOCHR},
	{"Herakles no Eikou 2 - Titan no Metsubou (J) [T-Eng_SpoonyBard]",0xF7537E2D,0x00000000,"?",ROM_NOCHR},
	{"Hyaku no Sekai no Monogatari - The Tales on a Watery Wilderness (J) [T-Eng]",0x302B255F,0x8F49226D,"?",0},
	{"Kaiketsu Yanchamaru 2 - Karakuri Land (J) [T-Eng1.01]",0x4E890104,0xF4AAC1D4,"?",0},
	{"Kaiketsu Yanchamaru 2 - Karakuri Land (J) [T-Eng]",0x396D0776,0x6A82C342,"?",0},
	{"Kouryuu Densetsu Villgust Gaiden (J) [T-Eng_Tarzanh]",0x67F4C084,0xECF6C800,"NES-TSROM",0},
	{"Majou Densetsu 2 - Daimashikyou Galious (J) [T-Eng0.10]",0x1F15A173,0x00000000,"NES-UNROM",ROM_NOCHR},
	{"Mini Putt (J) [T-Eng1.0]",									0x06E97649,0xE3029559,"?",0},
	{"Sanrio Carnival 2 (J) [T-Eng1.0]",						0x36817139,0xEF5088D2,"NES-CNROM",0},
	{"Venus Senki (J) [T-Eng2.1][o1]",							0x5174DD11,0x9A9FFB53,"?",0},
	{"Venus Senki (J) [T-Eng2.0][o1]",							0x5174DD11,0xDBE606A4,"?",0},
	{"TwinBee 3 - Poko Poko Dai Maou (J) [T-Eng1.02][o1]",0x29068417,0x1B9737DC,"?",0},
	{"Takahashi Meijin no Boukenjima 2 (J) [T-Eng]",		0x6FA0E650,0x1B9A7EBD,"NES-TSROM",0},
	{"Time Zone (J) [T-Eng_1.2]",									0x0D825D30,0x982AC326,"NES-TSROM",0},
	{"Wanpaku Kokkun no Gourmet World (J) [T-Eng]",			0x5BFD6499,0x3B05E6B2,"NES-TSROM",0},

	//pd roms
	{"CMC Wavy Demo by Chris Covell (PD)",				0xD3A265FF,0x23D8BB8A,"NES-UOROM",0},
	{"2009",														0x15BB820D,0x23034483,"NES-UOROM",0},

	//asia games
	{"Magic Jewelry (As)",									0x56A54EAE,0x6E7932E3,"NES-UOROM",0},

	{"Bing Kuang Ji Dan Zi - Flighty Chicken (As)",	0xCBE38E68,0x1E0BC7F3,"?",0},
	{"Doctor PC Jr. - Xue Si Dian Nao (As) [a1]",	0x70FA0766,0x00000000,"?",ROM_NOCHR},
	{"Zhan Guo Qun Xiong Zhuan (As)",					0xA03E75F0,0x8BB5E3FA,"?",0},

	//japan games
	{"Erika to Satoru no Yume Bouken (J)",				0x5F162195,0xB268DC01,"NAMCO-106",0},
	{"Esper Bouken Tai (J)",								0x7B0A41B9,0x00000000,"NES-UOROM",ROM_NOCHR},
	{"Esper Bouken Tai (J) [a1]",							0x02B0B405,0x00000000,"NES-UOROM",ROM_NOCHR},
	{"Rockman 6 - Shijou Saidai no Tatakai!! (J)",	0x2D664D99,0x00000000,"NES-TGROM",ROM_NOCHR},
	{"Rockman 5 - Blues no Wana! (J)",					0x05CF9EB0,0x482C358D,"NES-TLROM",0},
	{"Rambo (J)",												0x35EFFD0E,0x00000000,"NES-UNROM",ROM_NOCHR},
	{"Rampart (J)",											0x3ECDB1F7,0x00000000,"NES-UNROM",ROM_NOCHR},
	{"Summer Carnival '92 - Recca (J)",					0x126EA4A0,0x825CD716,"NES-TLROM",0},
	{"Sukeban Deka 3 (J)",									0x28C11D24,0x00000000,"NES-UNROM",ROM_NOCHR},
	{"Sukeban Deka 3 (J) [a1]",							0x02863604,0x00000000,"NES-UNROM",ROM_NOCHR},

	{"Moero!! Juudou Warriors (J)",						0xAA6E1A35,0x6BD848F1,"?",0},
	{"Moero!! Pro Soccer (J)",								0x309D222B,0xA9144689,"?",0},
	{"Spy Vs Spy (J)",										0xB36457C7,0x883790C8,"?",0},

	{"Tiles of Fate (U)",									0x6679648A,0xDE7F6C61,"AVE-NINA-03",0},
	{"Menace Beach (U)",										0x33D0282F,0x03C705C8,"COLORDREAMS-74*377",0},

	{"Klash Ball (U)",										0xF4DFDB14,0x00000000,"NES-UNROM",ROM_NOCHR},
	{"King's Quest V (U)",									0x8871B5C4,0x5B49294C,"NES-TSROM",0},
	{"Roger Clemens MVP Baseball (U)",					0x804A0570,0xE68FCEC3,"NES-TLROM",0},
	{"John Elway's Quarterback (U)",						0xD7C4816B,0xDA2CF1B0,"NES-CNROM",0},
	{"Fantasy Zone (U)",										0x3D96A1D8,0xA105673E,"NES-TBROM",0},
	{"Mutant Virus, The (U)",								0xA139009C,0xE54C2149,"NES-SLROM",0},
	{"Rocketeer, The (U)",									0x1D6DECCC,0x00000000,"NES-SGROM",ROM_NOCHR},
	{"Championship Bowling (U)",							0x03840EC5,0xCC20A4A6,"NES-CNROM",0},
	{"T&C 2 - Thrilla's Surfari (U)",					0xCA026F1F,0x1553B349,"NES-TLROM",0},
	{"Mega Man 6 (U)",										0x988798A8,0x00000000,"NES-TGROM",ROM_NOCHR},
	{"Ikari III - The Rescue (U)",						0x12F405CF,0x24E6BE19,"NES-SLROM",0},
	{"Where's Waldo (U)",									0x2735AF2E,0x8D5038BF,"NES-TLROM",0},
	{"Lone Ranger, The (U)",								0x0A866C94,0x97B9C0AC,"NES-TLROM",0},
	{"Tetris (U)",												0x943DFBBE,0x251AF21C,"NES-SEROM",0},
	{"Orb 3D (U)",												0x84B930A9,0x321F0492,"NES-SCROM",0},
	{"Solstice (U) [a1]",									0x95AD6D57,0x00000000,"NES-ANROM",ROM_NOCHR},
	{"Super Dodge Ball (U)",								0xF51E2FFE,0xD80AB9CA,"NES-SLROM",0},
	{"Peter Pan & The Pirates (U)",						0x84D51076,0xF39E8BE2,"NES-SFROM",0},
	{"Ninja Crusaders (U)",									0x3D1C4894,0x00000000,"NES-TGROM",ROM_NOCHR},
	{"Kung Fu (U) [a1]",										0x9C715918,0x430B49A4,"NES-NROM-256",0},

	{"WWF Wrestlemania (U)",								0x37138039,0x00000000,"NES-ANROM",ROM_NOCHR},
	{"Rampart (U)",											0x26AD7CEF,0x94A07125,"NES-TLROM",0},
	{"Ski or Die (U)",										0xB330ED11,0xF67B4EE3,"NES-SLROM",0},
	{"Target Renegade (U)",									0x9731A9A3,0xF0DD96D1,"NES-SLROM",0},
	{"Power Blade 2 (U)",									0x1BEBF407,0x96ADC4A9,"NES-TLROM",0},
	{"Jeopardy! (U)",											0xD5C71458,0x00000000,"NES-ANROM",ROM_NOCHR},
	{"Vindicators (U)",										0x6E72B8FF,0xBAD32854,"NES-TBROM",0},
	{"Smash T.V. (U)",										0x2989EAD6,0x6FAE4C9D,"NES-TLROM",0},
	{"Track & Field 2 (U)",									0x4C25D4F5,0x8F0A4755,"NES-SLROM",0},
	{"Marvel's X-Men (U)",									0x2D41EF92,0x00000000,"NES-UNROM",ROM_NOCHR},

	//usa games
	{"10-Yard Fight (U)",									0xDF58FC5A,0x2B8336EE,"NES-NROM-256",0},
	{"1942 (JU)",												0xC4E8C04A,0x03379B76,"NES-NROM-256",0},
	{"1943 (U)",												0x12C6D5C7,0x00000000,"NES-UNROM",ROM_NOCHR},
	{"3-D Battles of World Runner, The (U)",			0xE6A477B2,0x00000000,"NES-UNROM",ROM_NOCHR},
	{"720 (U)",													0x49F745E0,0x00000000,"NES-SGROM",ROM_NOCHR},
	{"8 Eyes (U)",												0xCB475567,0xDF52CED7,"NES-TLROM",0},
	{"Addams Family - Pugleys Scavenger Hunt (U)",	0x0E2AE6E1,0x60D7B56F,"NES-SKROM",SPRITE0_HACK},
	{"Adventures of Lolo (U)",								0x7F7156A7,0x9494D0A3,"NES-SEROM",0},
	{"Alien 3 (U)",											0xA67EA466,0xD87D47F4,"NES-TLROM",0},
	{"Balloon Fight (JU)",									0x575ED2FE,0xC642A1DF,"NES-NROM-128",0},
	{"Baseball (UE)",											0x39D1FA03,0xCDE71B82,"NES-NROM-128",0},
	{"Battle Tank (U)",										0x554B51D8,0xDA22F981,"NES-CNROM",SPRITE0_HACK},
	{"Battle Toads (U)",										0x279710DC,0x00000000,"NES-AOROM",ROM_NOCHR | SPRITE0_HACK},
	{"Battletoads & Double Dragon (U)",					0xCEB65B06,0x00000000,"NES-AOROM",ROM_NOCHR | SPRITE0_HACK},
	{"Bill Elliott's NASCAR Challenge (U)",			0x7062F3FA,0x15B6EB07,"NES-TLROM",0},
	{"Bubble Bath Babes (UE)",								0x71547D94,0x7505B144,"NES-CNROM",0},
	{"Bugs Bunny Birthday Bash (Prototype) (U)",		0x4D3AA180,0x4C6297DD,"NES-TLROM",0},
	{"Burai Fighter (U)",									0x7826FD3E,0x99D58BC3,"NES-TEROM",0},
	{"Cabal (U) [a1]",										0x8E838BC3,0x00000000,"NES-ANROM",ROM_NOCHR},
	{"Caltron 6-in-1 (U)",									0xCC8D1412,0x5A5C3E73,"MLT-CALTRON6IN1",0},
	{"Castlevania (U) (PRG0)",								0x0AC1AA8F,0x00000000,"NES-UNROM",ROM_NOCHR},
	{"Challenge of the Dragon (U)",						0xCA114AAC,0x1C56855F,"COLORDREAMS-74*377",0},
	{"Championship Pool (U)",								0xCDC641FC,0x00000000,"NES-UNROM",ROM_NOCHR | SPRITE0_HACK},
	{"Chip 'n Dale Rescue Rangers (U)",					0x02931525,0x218D4224,"?",0},
	{"Clash At Demonhead (U)",								0x2FA2DF5F,0xFA8AEF06,"?",0},
	{"Clu Clu Land (JU)",									0x23A60A62,0xA63B8B98,"NES-NROM-128",0},
	{"Cobra Triangle (U)",									0xC8AD4F32,0x00000000,"NES-AOROM",ROM_NOCHR | SPRITE0_HACK},
	{"Color a Dinosaur (U)",								0x0123BFFE,0x00000000,"NES-UNROM",ROM_NOCHR},
	{"Conan (U)",												0xC6000085,0x00000000,"NES-UNROM",ROM_NOCHR},
	{"Conflict (U)",											0xEDEA9AC6,0x03ECBB63,"NES-SKROM",0},
	{"Conquest of the Crystal Palace (U)",				0xEC1C5AD5,0x785BB456,"NES-TLROM",0},
	{"Contra (U)",												0xF6035030,0x00000000,"NES-UNROM",ROM_NOCHR},
	{"Contra Force (U)",										0x1FF7FC0D,0x7FF2A7F8,"NES-TLROM",0},
	{"Cool World (U)",										0xBDD55EA1,0x59FEC08B,"NES-SLROM",0},
	{"Cowboy Kid (U)",										0xED55073F,0x8E7E135C,"NES-TLROM",0},
	{"Crash'n The Boys Street Challenge (U)",			0x2D84F5B3,0x51E533EA,"NES-TLROM",0},
	{"Crystal Mines (U)",									0x01EE0720,0x6D0528B0,"COLORDREAMS-74*377",0},
	{"Crystalis (Prototype) (U) [a1]",					0x156C75FF,0x864F0C1B,"NES-TSROM",0},
	{"Crystalis (Prototype) (U)",							0x156C75FF,0x107AF778,"NES-TSROM",0},
	{"Crystalis (U) [a1]",									0x630BE870,0x4ADF7B9D,"NES-TSROM",0},
	{"Crystalis (U) [a2]",									0x630BE870,0xC554FC4D,"NES-TSROM",0},
	{"Crystalis (U)",											0x630BE870,0x864F0C1B,"NES-TSROM",0},
	{"Cyberball (U)",											0x95AF291F,0xB7968ACF,"NES-TLROM",0},
	{"Cybernoid - The Fighting Machine (U)",			0x34D5FC6E,0x89E13D77,"NES-CNROM",0},
	{"Donkey Kong (JU)",										0xF56A5B10,0xA21D7C2E,"NES-NROM-128",0},
	{"Donkey Kong 3 (JUE)",									0x5EF4F30C,0x85D06C57,"NES-NROM-128",0},
	{"Donkey Kong Jr. (JU)",								0xCF6C88B6,0x852778AB,"NES-NROM-128",0},
	{"Dr Mario (JU)",											0xCB02A930,0x064D4AB3,"NES-SEROM",0},
	{"Dr Mario (JU) [a1]",									0xCB02A930,0x72FDC89C,"NES-SEROM",0},
	{"Dragon Warrior II (U)",								0x8C5A784E,0x00000000,"NES-SNROM",ROM_NOCHR},
	{"Duck Hunt (JUE)",										0x90CA616D,0x4E049E03,"NES-NROM-128",0},
	{"Earth Bound (Prototype) (U)",						0xF85BBF3E,0x53C29598,"NES-TSROM",0},
	{"Earth Bound Zero (Neo Demiforce v1.01 Hack-1) (U)",0xCC710D52,0x27E407AF,"NES-TSROM",0},
	{"Earth Bound Zero (Neo Demiforce v1.01 Hack-2) (U)",0xC31F5585,0xA6CEA124,"NES-TSROM",0},
	{"Elevator Action (U)",									0x0F6C01E3,0xD61F3210,"NES-NROM-256",0},
	{"Eliminator Boat Duel (U)",							0x9BF99C3A,0x3EC62C43,"NES-SLROM",0},
	{"Evert & Lendl Top Player's Tennis (U)",			0xDD564975,0xDB2AF89D,"NES-SLROM",0},
	{"Exodus (U) (V4.0)",									0x3CED963A,0xAB344905,"COLORDREAMS-74*377",0},
	{"Excitebike (JU)",										0x3A94FA0B,0xE5F72401,"NES-NROM-128",0},
	{"Fantastic Adventures of Dizzy (Aladdin) (UE)",0xF732C8FD,0x00000000,"CAMERICA-BF9093",ROM_NOCHR},
	{"Faxanadu (U)",											0x57DD23D1,0x00000000,"NES-SGROM",ROM_NOCHR},
	{"Ferrari - Grand Prix Challenge (U)",				0xB051C0E1,0x13D6708E,"NES-SLROM",0},
//	{"Game Genie (Unl)",										0x02B26E69,0xE698CC99,"NES-UOROM",ROM_NOCHR},
	{"Gauntlet (Unl) (U)",									0xB19C48A5,0x1EEFF226,"NES-TFROM",0},
	{"Golf (JU)",												0x9C7E6421,0x7DFA75A8,"NES-NROM-128",0},
	{"Gumshoe (UE)",											0x7B5BD2DE,0xDC371E9E,"NES-GNROM",0},
	{"Gyromite (JUE)",										0x21B099F3,0xD0135A78,"NES-NROM-256",0},
//	{"Micro Machines (Aladdin) (UE)",					0x24BA12DD,0x00000000,"CAMERICA-ALGN",ROM_NOCHR | SPRITE0_HACK},
//	{"High Speed (U)",										0x1255036F,0x028F3D82,"NES-TQROM",0},
	{"Hogan's Alley (JU)",									0x8963AE6E,0x5DF42FC4,"NES-NROM-128",0},
	{"Hot Slot (UE)",											0xA0DAD6E4,0x756E634F,"NES-CNROM",0},
	{"Ice Climber (JE)",										0xD548307F,0xFD98F4D3,"NES-NROM-128",0},
	{"Jimmy Connor's Tennis (U)",							0x00E95D86,0x00000000,"NES-UNROM",ROM_NOCHR | SPRITE0_HACK},
	{"Joypad Test Cartridge (U)",							0x9219765F,0xBD3A18B2,"NES-UOROM",0},
	{"Kid Icarus (UE)",										0xD770C1A9,0x00000000,"NES-SNROM",ROM_NOCHR},
	{"Kung Fu (U)",											0x0516375E,0x430B49A4,"NES-NROM-256",SPRITE0_HACK},
	{"Legend of Zelda, The (U) (PRG 0)",				0x3FE272FB,0x00000000,"NES-SNROM",ROM_NOCHR},
	{"Legend of Zelda, The (U) (PRG 1)",				0xEAF7ED72,0x00000000,"NES-SNROM",ROM_NOCHR},
	{"Lifeforce (U)",											0xC4BC85A2,0x00000000,"KONAMI-UNROM",ROM_NOCHR},
	{"Low G Man (U)",											0x41243492,0x0C1BFD4E,"NES-TLROM",0},
	{"Lunar Pool (U)",										0x9BA20DAD,0xA139062A,"NES-UOROM",0},
	{"M.U.L.E. (U)",											0x0939852F,0x00000000,"NES-SNROM",ROM_NOCHR},
	{"M.U.S.C.L.E. (U)",										0x092B5371,0x028F365D,"NES-UOROM",0},
	{"Mach Rider (JU)",										0xAF2BBCBC,0x33A2B41A,"NES-NROM-256",0},
	{"Mach Rider (JU) [a1]",								0x3ACD4BF1,0x33A2B41A,"NES-NROM-256",0},
	{"Mad Max (U) [!]",										0x06A4345C,0xF361003A,"NES-TLROM",0},
	{"Mafat Conspiracy - Golgo 13 (U)",					0x05DE5AFD,0x68CA71F9,"NES-TLROM",0},
	{"Magic Darts (U)",										0xC8A10B71,0x06E760D1,"NES-SLRROM",0},
	{"Marble Madness (U)",									0x09874777,0x00000000,"NES-ANROM",ROM_NOCHR | SPRITE0_HACK},
	{"Mike Tyson's Punch-Out!! (U) (PRG 0)",			0x8DB6D11F,0x570B48EA,"NES-PNROM",0},
	{"Mike Tyson's Punch-Out!! (U) (PRG 1)",			0xF1D861EF,0x570B48EA,"NES-PNROM",0},
	{"Ms Pac-Man (U)",										0x4B2DCE64,0x1F20FAD0,"NES-UOROM",0},
	{"NES Play Action Football (U)",						0x17F72EC8,0x6E8CAE8D,"NES-TLROM",0},
	{"Punch-Out!! (U)",										0xC032E5B0,0x421DC9A4,"NES-PNROM",0},
	{"Rad Racer (U)",											0x8B9D3E9C,0x00000000,"NES-SGROM",ROM_NOCHR},
	{"Rad Racer 2 (U)",										0xAB90E397,0x07DF55D8,"NES-TBROM",SPRITE0_HACK},
	{"R.C. Pro-Am 2 (U)",									0x9EDD2159,0x00000000,"NES-AOROM",SPRITE0_HACK},
	{"Star Tropics (U)",										0xBEB88304,0x42236F71,"NES-HKROM",0},
	{"Super C (U)",											0xC7FBECC3,0x153295C1,"NES-TLROM",0},
	{"Super Glove Ball (U)",								0xEFCF375D,0x00000000,"NES-UNROM",ROM_NOCHR},
	{"Super Mario Bros - Duck Hunt (U)",				0x81069812,0x7ECDA8B3,"NES-MHROM",0},
	{"Super Mario Bros - Duck Hunt - Track Meet (U)",0xD4F018F5,0x3FA21A12,"NES-SFROM",0},
	{"Super Mario Bros (JU) (PRG 0)",					0x5CF548D3,0x867B51AD,"NES-NROM-256",0},
	{"Super Mario Bros (JU) (PRG 1)",					0x0B97B2AF,0x867B51AD,"NES-NROM-256",0},
	{"Super Mario Bros 2 (U) (PRG 0)",					0x07854B3F,0xF2BA1170,"NES-TLROM",0},
	{"Super Mario Bros 2 (U) (PRG 1)",					0x9ED99198,0xF2BA1170,"NES-TLROM",0},
	{"Super Mario Bros 3 (U) (PRG 0)",					0xC78D17D3,0xC2928C49,"NES-TLROM",0},
	{"Super Mario Bros 3 (U) (PRG 1)",					0xA0ED7D20,0xC2928C49,"NES-TLROM",0},
	{"Super Mario Bros 3 (U) (PRG 1) [a1]",			0xA8C5051A,0xC1C7C10A,"NES-TLROM",0},
	{"Super Mario Bros 3 (U) (PRG 1) [a2]",			0x86DBD1BE,0x00BAECA2,"NES-TLROM",0},
	{"Super Mario Bros 3 (U) (PRG 1) [a3]",			0x4B7DBC74,0xC2928C49,"NES-TLROM",0},
	{"Super Pitfall (U)",									0x979C5314,0x00000000,"NES-UNROM",ROM_NOCHR},
	{"Tetris (Unl) (U)",										0xA520F44C,0x68F18CBE,"NES-CNROM",0},
	{"Videomation (U)",										0x5E66EAEA,0x00000000,"NES-CPROM",ROM_NOCHR},
//	{"Wizards and Warriors (U)",							0x505F9715,0x00000000,"NES-ANROM",ROM_NOCHR | SPRITE0_HACK},
	{"Xenophobe (U)",											0x9ECA0941,0xAA00B5FA,"NES-SFROM",0},
	{"Xevious (U)",											0x18D5AF7A,0x668B4EE6,"NES-UOROM",0},
	{"Xexyz (U)",												0x8E504A98,0xF2050258,"NES-SLROM",0},
	{"Yo! Noid (U)",											0x4AFFEEE7,0x868F7343,"NES-SLROM",0},
	{"Yoshi (U)",												0xFE5F17F0,0xF68E9595,"NES-SKROM",0},
	{"Yoshi's Cookie (U)",									0x1CBA7EB4,0x19A70DDA,"NES-TFROM",0},
	{"Young Indiana Jones Chronicles, The (U)",		0x1E0A01EA,0x39930DCB,"NES-TLROM",0},
	{"Zanac (U)",												0xE292AA10,0x00000000,"NES-UNROM",ROM_NOCHR},
	{"Zelda 2 - The Adventure of Link (U)",			0xEE8C9971,0x9C41CE57,"NES-SKROM",SPRITE0_HACK},
	{"Zen Intergalactic Ninja (U)",						0x58A407BB,0x589EBFDC,"NES-TLROM",0},
	{"Zoda's Revenge - Star Tropics II (U)",			0x80FB117E,0x0CA74E1A,"NES-HKROM",0},
	{"Zombie Nation (U)",									0x407793C0,0xBB0AD971,"NES-TLROM",0},

	//unlicensed
	{"Magic Dragon (Unl)",									0xAAB15466,0x4937921D,"?",0},
//	{"Fire Hawk (Unl) [!].nes",							0x1BC686A8,0x00000000,"?",ROM_NOCHR | SPRITE0_HACK},

	//end
	{0,0,0,0,0}
};
