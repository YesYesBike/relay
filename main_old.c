#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define NELEM(x)			(sizeof(x)/sizeof((x)[0]))

#ifndef TEST
# define FLAG_MAX			3
# define LAST	ID_HIHUMI
#else
# define FLAG_MAX			2
# define LAST	ID_TSUKUYO
#endif /* TEST */

#define CHECK_PASS			0
#define CHECK_DUPLICATED	1
#define FLAGID(ID)			(1ULL << ((ID) & 0b111111))

#define OFF(x)				(offlen[(x)].off)
#define LEN(x)				(offlen[(x)].len)

#define OFF_NULL			0
#define OFF_NA				0
#define OFF_NE				3
#define OFF_NO				4
#define OFF_NI				8
#define OFF_RA				10
#define OFF_RE				11
#define OFF_RU				13
#define OFF_RI				14
#define OFF_RIN				15
#define OFF_MA				16
#define OFF_ME				21
#define OFF_MO				23
#define OFF_MU				27
#define OFF_MI				28
#define OFF_SA				38
#define OFF_SE				43
#define OFF_SO				47
#define OFF_SHU				48
#define OFF_SU				49
#define OFF_SHI				53
#define OFF_A				57
#define OFF_YA				73
#define OFF_E				74
#define OFF_O				76
#define OFF_WA				77
#define OFF_YO				78
#define OFF_U				79
#define OFF_YU				82
#define OFF_I				87
#define OFF_JU				93
#define OFF_JUN				94
#define OFF_CHE				95
#define OFF_TSU				96

#ifndef TEST
# define OFF_CHI			100
# define OFF_KA				104
# define OFF_KAN			113
# define OFF_KO				114
# define OFF_KU				121
# define OFF_KI				123
# define OFF_TA				127
# define OFF_TO				128
# define OFF_PU				130
# define OFF_PI				131
# define OFF_HA				132
# define OFF_HO				139
# define OFF_HU				140
# define OFF_HI				142
#else
#endif /* TEST */


#define LEN_NULL			0
#define LEN_NA				(OFF_NE - OFF_NA)
#define LEN_NE				(OFF_NO - OFF_NE)
#define LEN_NO				(OFF_NI - OFF_NO)
#define LEN_NI				(OFF_RA - OFF_NI)
#define LEN_RA				(OFF_RE - OFF_RA)
#define LEN_RE				(OFF_RU - OFF_RE)
#define LEN_RU				(OFF_RI - OFF_RU)
#define LEN_RI				(OFF_RIN - OFF_RI)
#define LEN_RIN				(OFF_MA - OFF_RIN)
#define LEN_MA				(OFF_ME - OFF_MA)
#define LEN_ME				(OFF_MO - OFF_ME)
#define LEN_MO				(OFF_MU - OFF_MO)
#define LEN_MU				(OFF_MI - OFF_MU)
#define LEN_MI				(OFF_SA - OFF_MI)
#define LEN_SA				(OFF_SE - OFF_SA)
#define LEN_SE				(OFF_SO - OFF_SE)
#define LEN_SO				(OFF_SHU - OFF_SO)
#define LEN_SHU				(OFF_SU - OFF_SHU)
#define LEN_SU				(OFF_SHI - OFF_SU)

#define LEN_SHI				(OFF_A - OFF_SHI)
#define LEN_A				(OFF_YA - OFF_A)
#define LEN_YA				(OFF_E - OFF_YA)
#define LEN_E				(OFF_O - OFF_E)
#define LEN_O				(OFF_WA - OFF_O)
#define LEN_WA				(OFF_YO - OFF_WA)
#define LEN_YO				(OFF_U - OFF_YO)
#define LEN_U				(OFF_YU - OFF_U)
#define LEN_YU				(OFF_I - OFF_YU)
#define LEN_I				(OFF_JU - OFF_I)
#define LEN_JU				(OFF_JUN - OFF_JU)
#define LEN_JUN				(OFF_CHE - OFF_JUN)
#define LEN_CHE				(OFF_TSU - OFF_CHE)

#ifndef TEST
# define LEN_TSU			(OFF_CHI - OFF_TSU)
#else
# define LEN_TSU			4
#endif /* TEST */

#ifndef TEST
# define LEN_CHI			(OFF_KA - OFF_CHI)
# define LEN_KA				(OFF_KAN - OFF_KA)
# define LEN_KAN			(OFF_KO - OFF_KAN)
# define LEN_KO				(OFF_KU - OFF_KO)
# define LEN_KU				(OFF_KI - OFF_KU)
# define LEN_KI				(OFF_TA - OFF_KI)
# define LEN_TA				(OFF_TO - OFF_TA)
# define LEN_TO				(OFF_PU - OFF_TO)
# define LEN_PU				(OFF_PI - OFF_PU)
# define LEN_PI				(OFF_HA - OFF_PI)
# define LEN_HA				(OFF_HO - OFF_HA)
# define LEN_HO				(OFF_HU - OFF_HO)
# define LEN_HU				(OFF_HI - OFF_HU)
# define LEN_HI				7
#endif /* TEST */


typedef uint32_t		u32;
typedef uint64_t		u64;

typedef struct {
	const int			off;
	const int			len;
} bgn_t;

typedef struct node_t {
	struct node_t		*next;
	int					id;
} node_t;

typedef struct {
	node_t				*head;
	node_t				*tail;
} list_t;

#ifndef TEST
enum {
	//0~63
	ID_NAGUSA, ID_NAGISA, ID_NATSU, ID_NERU, ID_NONOMI, ID_NODOKA, ID_NOA,
	ID_NOZOMI, ID_NIYA, ID_NIKO, ID_LOVE, ID_REISA, ID_REIJO, ID_RUMI, ID_RIO,
	ID_RIN, ID_MARIANGRY, ID_MARINA, ID_MASYRO, ID_MAKOTO, ID_MAKI, ID_MEGU,
	ID_MERU, ID_MOMOI, ID_MOMOKA, ID_MOMIJI, ID_MOE, ID_MUTSUKI, ID_MINA, ID_MINEISMINE,
	ID_MINORI, ID_MIDORI, ID_MIMORI, ID_MISAKI, ID_MIYAKO, ID_MIYU, ID_MICHIRU,
	ID_MISONO, ID_SAYA, ID_SAORI, ID_SATSUKI, ID_SAKURAKO, ID_SAKI, ID_SENA,
	ID_SERINA, ID_SERIKA, ID_____, ID_GODUNG, ID_SHURO, ID_SUMOMO, ID_SUMIRE,
	ID_SUOU, ID_HARUHI, ID_SHIGURE, ID_SYROKO, ID_SHIMIKO, ID_SHIZUKO, ID_ARONA,
	ID_ARU, ID_ARISU, ID_ASUNA, ID_AYANE, ID_AYAME, ID_AOI,

	//64~127
	ID_AYuwu, ID_AIRI, ID_AZ_USA, ID_ATSUKO, ID_AKANE, ID_AKARI, ID_ALKEMIST, ID_AKO,
	ID_AKIRA, ID_YAKUMO, ID_ERIKA, ID_EIMI, ID_OTTOOGI, ID_WAKAMO, ID_YOSHI,
	ID_UMIKA, ID_UI, ID_UTAHAHA, ID_YUME, ID_YUUKA, ID_USE, ID_YUKARI, ID_YUKINO,
	ID_IROHA, ID_IBUKI, ID_IORI, ID_IZUNA, ID_IZUMI, ID_ICHIKA, ID_JURI, ID_JUNKO,
	ID_CHERRYNO, ID_TSURUGI, ID_TSuwuGI, ID_TSUBAKI, ID_TSUKUYO, ID_CHINATSU,
	ID_CHISE, ID_CHIAKI, ID_CHIHIRO, ID_KAGUYA, ID_KARIN, ID_KASUMI, ID_KAYA,
	ID_KACDC, ID_KAYOKO, ID_KAI, ID_KAZUSA, ID_KAHO, ID_KANNA, ID_KONOKA,
	ID_KOYUKI, ID_KOKONUT, ID_KKRIKO, ID_KOTAMA, ID_KOTLIN, ID_KOHARU, ID_KURUMI,
	ID_KZNOHA, ID_KIRARA, ID_KIRINO, ID_KISAKI, ID_KICKYOU, ID_TAKANE,

	//128~
	ID_TOMOE, ID_TOKKI, ID_PLANA, ID_PINA, ID_HANAE, ID_HANAKO, ID_HARE, ID_HARUNA,
	ID_HARUKA, ID_HASUMI, ID_HAINEKEN, ID_HOSHINO, ID_HuwuKI, ID_HuwuKA, ID_HINA,
	ID_HINATA, ID_HIMARI, ID_HIBIKI, ID_HIYORI, ID_HIKARI, ID_HIHUMI, ID_END
};
#else
enum {
	ID_NAGUSA, ID_NAGISA, ID_NATSU, ID_NERU, ID_NONOMI, ID_NODOKA, ID_NOA,
	ID_NOZOMI, ID_NIYA, ID_NIKO, ID_LOVE, ID_REISA, ID_REIJO, ID_RUMI, ID_RIO,
	ID_RIN, ID_MARIANGRY, ID_MARINA, ID_MASYRO, ID_MAKOTO, ID_MAKI, ID_MEGU,
	ID_MERU, ID_MOMOI, ID_MOMOKA, ID_MOMIJI, ID_MOE, ID_MUTSUKI, ID_MINA, ID_MINEISMINE,
	ID_MINORI, ID_MIDORI, ID_MIMORI, ID_MISAKI, ID_MIYAKO, ID_MIYU, ID_MICHIRU,
	ID_MISONO, ID_SAYA, ID_SAORI, ID_SATSUKI, ID_SAKURAKO, ID_SAKI, ID_SENA,
	ID_SERINA, ID_SERIKA, ID_____, ID_GODUNG, ID_SHURO, ID_SUMOMO, ID_SUMIRE,
	ID_SUOU, ID_HARUHI, ID_SHIGURE, ID_SYROKO, ID_SHIMIKO, ID_SHIZUKO, ID_ARONA,
	ID_ARU, ID_ARISU, ID_ASUNA, ID_AYANE, ID_AYAME, ID_AOI,

	ID_AYuwu, ID_AIRI, ID_AZ_USA, ID_ATSUKO, ID_AKANE, ID_AKARI, ID_ALKEMIST, ID_AKO,
	ID_AKIRA, ID_YAKUMO, ID_ERIKA, ID_EIMI, ID_OTTOOGI, ID_WAKAMO, ID_YOSHI,
	ID_UMIKA, ID_UI, ID_UTAHAHA, ID_YUME, ID_YUUKA, ID_USE, ID_YUKARI, ID_YUKINO,
	ID_IROHA, ID_IBUKI, ID_IORI, ID_IZUNA, ID_IZUMI, ID_ICHIKA, ID_JURI, ID_JUNKO,
	ID_CHERRYNO, ID_TSURUGI, ID_TSuwuGI, ID_TSUBAKI, ID_TSUKUYO, ID_CHINATSU
};
#endif /* TEST */

#ifndef TEST
enum {
	END_A, END_BU, END_DE, END_E, END_GE, END_GI, END_GU, END_HA, END_HO,
	END_I, END_JI, END_JO, END_KA, END_KI, END_KO, END_KYO, END_MA, END_ME,
	END_MI, END_MO, END_MU, END_NA, END_NE, END_NO, END_O, END_RA, END_RE,
	END_RI, END_RIN, END_RO, END_RU, END_SA, END_SE, END_SU, END_TA, END_TO,
	END_TSU, END_U, END_YA, END_YO, END_YU, END_ZU,
};
#else
enum {
	END_A, END_BU, END_E, END_GI, END_GU, END_HA, END_I, END_JI, END_JO,
	END_KA, END_KI, END_KO, END_ME, END_MI, END_MO, END_MU, END_NA, END_NE,
	END_NO, END_O, END_RA, END_RE, END_RI, END_RIN, END_RO, END_RU, END_SA,
	END_SU, END_TO, END_TSU, END_U, END_YA, END_YO, END_YU, END_ZU,
};
#endif /* TEST */


static const int chain_list[] = {
	[ID_NAGUSA] = 		END_SA,		/* 000 OFF_NA */
	[ID_NAGISA] = 		END_SA,		/* 001 */
	[ID_NATSU] = 		END_TSU,	/* 002 */
	[ID_NERU] = 		END_RU,		/* 003 OFF_NE */
	[ID_NONOMI] = 		END_MI,		/* 004 OFF_NO */
	[ID_NODOKA] = 		END_KA,		/* 005 */
	[ID_NOA] = 			END_A,		/* 006 */
	[ID_NOZOMI] = 		END_MI,		/* 007 */
	[ID_NIYA] = 		END_YA,		/* 008 OFF_NI */
	[ID_NIKO] = 		END_KO,		/* 009 */
	[ID_LOVE] = 		END_BU,		/* 010 OFF_RA */
	[ID_REISA] = 		END_SA,		/* 011 OFF_RE */
	[ID_REIJO] = 		END_JO,		/* 012 */
	[ID_RUMI] = 		END_MI,		/* 013 OFF_RU */
	[ID_RIO] = 			END_O,		/* 014 OFF_RI */
	[ID_RIN] = 			END_RIN,	/* 015 OFF_RIN */
	[ID_MARIANGRY] = 	END_RI,		/* 016 OFF_MA */
	[ID_MARINA] = 		END_NA,		/* 017 */
	[ID_MASYRO] = 		END_RO,		/* 018 */
	[ID_MAKOTO] = 		END_TO,		/* 019 */
	[ID_MAKI] = 		END_KI,		/* 020 */
	[ID_MEGU] = 		END_GU,		/* 021 OFF_ME */
	[ID_MERU] = 		END_RU,		/* 022 */
	[ID_MOMOI] = 		END_I,		/* 023 OFF_MO */
	[ID_MOMOKA] = 		END_KA,		/* 024 */
	[ID_MOMIJI] = 		END_JI,		/* 025 */
	[ID_MOE] = 			END_E,		/* 026 */
	[ID_MUTSUKI] = 		END_KI,		/* 027 OFF_MU */
	[ID_MINA] = 		END_NA,		/* 028 OFF_MI */
	[ID_MINEISMINE] = 	END_NE,		/* 029 */
	[ID_MINORI] = 		END_RI,		/* 030 */
	[ID_MIDORI] = 		END_RI,		/* 031 */
	[ID_MIMORI] = 		END_RI,		/* 032 */
	[ID_MISAKI] = 		END_KI,		/* 033 */
	[ID_MIYAKO] = 		END_KO,		/* 034 */
	[ID_MIYU] = 		END_YU,		/* 035 */
	[ID_MICHIRU] = 		END_RU,		/* 036 */
	[ID_MISONO] = 		END_KA,		/* 037 */
	[ID_SAYA] = 		END_YA,		/* 038 OFF_SA */
	[ID_SAORI] = 		END_RI,		/* 039 */
	[ID_SATSUKI] = 		END_KI,		/* 040 */
	[ID_SAKURAKO] = 	END_KO,		/* 041 */
	[ID_SAKI] = 		END_KI,		/* 042 */
	[ID_SENA] = 		END_NA,		/* 043 OFF_SE */
	[ID_SERINA] = 		END_NA,		/* 044 */
	[ID_SERIKA] = 		END_KA,		/* 045 */
	[ID_____] = 		END_A,		/* 046 */
	[ID_GODUNG] = 		END_RA,		/* 047 OFF_SO */
	[ID_SHURO] = 		END_RO,		/* 048 OFF_SHU */
	[ID_SUMOMO] = 		END_MO,		/* 049 OFF_SU */
	[ID_SUMIRE] = 		END_RE,		/* 050 */
	[ID_SUOU] = 		END_U,		/* 051 */
	[ID_HARUHI] = 		END_MI,		/* 052 */
	[ID_SHIGURE] = 		END_RE,		/* 053 OFF_SHI */
	[ID_SYROKO] = 		END_KO,		/* 054 */
	[ID_SHIMIKO] = 		END_KO,		/* 055 */
	[ID_SHIZUKO] = 		END_KO,		/* 056 */
	[ID_ARONA] = 		END_NA,		/* 057 OFF_A */
	[ID_ARU] = 			END_RU,		/* 058 */
	[ID_ARISU] = 		END_SU,		/* 059 */
	[ID_ASUNA] = 		END_NA,		/* 060 */
	[ID_AYANE] = 		END_NE,		/* 061 */
	[ID_AYAME] = 		END_ME,		/* 062 */
	[ID_AOI] = 			END_I,		/* 063 */
	[ID_AYuwu] = 		END_MU,		/* 064 */
	[ID_AIRI] = 		END_RI,		/* 065 */
	[ID_AZ_USA] = 		END_SA,		/* 066 */
	[ID_ATSUKO] = 		END_KO,		/* 067 */
	[ID_AKANE] = 		END_NE,		/* 068 */
	[ID_AKARI] = 		END_RI,		/* 069 */
	[ID_ALKEMIST] = 	END_MI,		/* 070 */
	[ID_AKO] = 			END_KO,		/* 071 */
	[ID_AKIRA] = 		END_RA,		/* 072 */
	[ID_YAKUMO] = 		END_MO,		/* 073 OFF_YA */
	[ID_ERIKA] = 		END_KA,		/* 074 OFF_E */
	[ID_EIMI] = 		END_MI,		/* 075 */
	[ID_OTTOOGI] = 		END_GI,		/* 076 OFF_O */
	[ID_WAKAMO] = 		END_MO,		/* 077 OFF_WA */
	[ID_YOSHI] = 		END_MI,		/* 078 OFF_YO */
	[ID_UMIKA] = 		END_KA,		/* 079 OFF_U */
	[ID_UI] = 			END_I,		/* 080 */
	[ID_UTAHAHA] = 		END_HA,		/* 081 */
	[ID_YUME] = 		END_ME,		/* 082 OFF_YU */
	[ID_YUUKA] = 		END_KA,		/* 083 */
	[ID_USE] = 			END_ZU,		/* 084 */
	[ID_YUKARI] = 		END_RI,		/* 085 */
	[ID_YUKINO] = 		END_NO,		/* 086 */
	[ID_IROHA] = 		END_HA,		/* 087 OFF_I */
	[ID_IBUKI] = 		END_KI,		/* 088 */
	[ID_IORI] = 		END_RI,		/* 089 */
	[ID_IZUNA] = 		END_NA,		/* 090 */
	[ID_IZUMI] = 		END_MI,		/* 091 */
	[ID_ICHIKA] = 		END_KA,		/* 092 */
	[ID_JURI] = 		END_RI,		/* 093 OFF_JU */
	[ID_JUNKO] = 		END_KO,		/* 094 OFF_JUN */
	[ID_CHERRYNO] = 	END_NO,		/* 095 OFF_CHE */
	[ID_TSURUGI] = 		END_GI,		/* 096 OFF_TSU */
	[ID_TSuwuGI] = 		END_GI,		/* 097 */
	[ID_TSUBAKI] = 		END_KI,		/* 098 */
	[ID_TSUKUYO] = 		END_YO,		/* 099 */
#ifndef TEST
	[ID_CHINATSU] = 	END_TSU,	/* 100 OFF_CHI */
	[ID_CHISE] = 		END_SE,		/* 101 */
	[ID_CHIAKI] = 		END_KI,		/* 102 */
	[ID_CHIHIRO] = 		END_RO,		/* 103 */
	[ID_KAGUYA] = 		END_YA,		/* 104 OFF_KA */
	[ID_KARIN] = 		END_RIN,	/* 105 */
	[ID_KASUMI] = 		END_MI,		/* 106 */
	[ID_KAYA] = 		END_YA,		/* 107 */
	[ID_KACDC] = 		END_DE,		/* 108 */
	[ID_KAYOKO] = 		END_KO,		/* 109 */
	[ID_KAI] = 			END_I,		/* 110 */
	[ID_KAZUSA] = 		END_SA,		/* 111 */
	[ID_KAHO] = 		END_HO,		/* 112 */
	[ID_KANNA] = 		END_NA,		/* 113 OFF_KAN */
	[ID_KONOKA] = 		END_KA,		/* 114 OFF_KO */
	[ID_KOYUKI] = 		END_KI,		/* 115 */
	[ID_KOKONUT] = 		END_NA,		/* 116 */
	[ID_KKRIKO] = 		END_KO,		/* 117 */
	[ID_KOTAMA] = 		END_MA,		/* 118 */
	[ID_KOTLIN] = 		END_RI,		/* 119 */
	[ID_KOHARU] = 		END_RU,		/* 120 */
	[ID_KURUMI] = 		END_MI,		/* 121 OFF_KU */
	[ID_KZNOHA] = 		END_HA,		/* 122 */
	[ID_KIRARA] = 		END_RA,		/* 123 OFF_KI */
	[ID_KIRINO] = 		END_NO,		/* 124 */
	[ID_KISAKI] = 		END_KI,		/* 125 */
	[ID_KICKYOU] = 		END_KYO,	/* 126 */
	[ID_TAKANE] = 		END_NE,		/* 127 OFF_TA */
	[ID_TOMOE] = 		END_E,		/* 128 OFF_TO */
	[ID_TOKKI] = 		END_KI,		/* 129 */
	[ID_PLANA] = 		END_NA,		/* 130 OFF_PU */
	[ID_PINA] = 		END_NA,		/* 131 OFF_PI */
	[ID_HANAE] = 		END_E,		/* 132 OFF_HA */
	[ID_HANAKO] = 		END_KO,		/* 133 */
	[ID_HARE] = 		END_RE,		/* 134 */
	[ID_HARUNA] = 		END_NA,		/* 135 */
	[ID_HARUKA] = 		END_KA,		/* 136 */
	[ID_HASUMI] = 		END_MI,		/* 137 */
	[ID_HAINEKEN] = 	END_NE,		/* 138 */
	[ID_HOSHINO] = 		END_NO,		/* 139 OFF_HO */
	[ID_HuwuKI] = 		END_KI,		/* 140 OFF_HU */
	[ID_HuwuKA] = 		END_KA,		/* 141 */
	[ID_HINA] = 		END_NA,		/* 142 OFF_HI */
	[ID_HINATA] = 		END_TA,		/* 143 */
	[ID_HIMARI] = 		END_RI,		/* 144 */
	[ID_HIBIKI] = 		END_KI,		/* 145 */
	[ID_HIYORI] = 		END_RI,		/* 146 */
	[ID_HIKARI] = 		END_RI,		/* 147 */
	[ID_HIHUMI] = 		END_MI,		/* 148 */
#endif /* TEST */
};

#ifndef TEST
const bgn_t offlen[] = {
	[END_A] =	{ OFF_A,	LEN_A },
	[END_E] =	{ OFF_E,	LEN_E },
	[END_HA] =	{ OFF_HA,	LEN_HA },
	[END_HO] =	{ OFF_HO,	LEN_HO },
	[END_I] =	{ OFF_I,	LEN_I },
	[END_KA] =	{ OFF_KA,	LEN_KA },
	[END_KI] =	{ OFF_KI,	LEN_KI },
	[END_KO] =	{ OFF_KO,	LEN_KO },
	[END_MA] =	{ OFF_MA,	LEN_MA },
	[END_ME] =	{ OFF_ME,	LEN_ME },
	[END_MI] =	{ OFF_MI,	LEN_MI },
	[END_MO] =	{ OFF_MO,	LEN_MO },
	[END_MU] =	{ OFF_MU,	LEN_MU },
	[END_NA] =	{ OFF_NA,	LEN_NA },
	[END_NE] =	{ OFF_NE,	LEN_NE },
	[END_NO] =	{ OFF_NO,	LEN_NO },
	[END_O] =	{ OFF_O,	LEN_O },
	[END_RA] =	{ OFF_RA,	LEN_RA },
	[END_RE] =	{ OFF_RE,	LEN_RE },
	[END_RIN] =	{ OFF_RIN,	LEN_RIN },
	[END_RI] =	{ OFF_RI,	LEN_RI },
	[END_RU] =	{ OFF_RU,	LEN_RU },
	[END_SA] =	{ OFF_SA,	LEN_SA },
	[END_SE] =	{ OFF_SE,	LEN_SE },
	[END_SU] =	{ OFF_SU,	LEN_SU },
	[END_TA] =	{ OFF_TA,	LEN_TA },
	[END_TO] =	{ OFF_TO,	LEN_TO },
	[END_TSU] =	{ OFF_TSU,	LEN_TSU },
	[END_U] =	{ OFF_U,	LEN_U },
	[END_YA] =	{ OFF_YA,	LEN_YA },
	[END_YO] =	{ OFF_YO,	LEN_YO },
	[END_YU] =	{ OFF_YU,	LEN_YU },

	[END_BU] =	{ OFF_NULL, LEN_NULL },
	[END_DE] =	{ OFF_NULL, LEN_NULL },
	[END_GE] =	{ OFF_NULL, LEN_NULL },
	[END_GI] =	{ OFF_NULL, LEN_NULL },
	[END_GU] =	{ OFF_NULL, LEN_NULL },
	[END_JI] =	{ OFF_NULL, LEN_NULL },
	[END_JO] =	{ OFF_NULL, LEN_NULL },
	[END_KYO] =	{ OFF_NULL, LEN_NULL },
	[END_RO] =	{ OFF_NULL, LEN_NULL },
	[END_ZU] =	{ OFF_NULL, LEN_NULL },
};
#else
const bgn_t offlen[] = {
	[END_A] =	{ OFF_A,	LEN_A },
	[END_E] =	{ OFF_E,	LEN_E },
	[END_HA] =	{ OFF_NULL,	LEN_NULL },
	[END_I] =	{ OFF_I,	LEN_I },
	[END_KA] =	{ OFF_NULL,	LEN_NULL },
	[END_KI] =	{ OFF_NULL,	LEN_NULL },
	[END_KO] =	{ OFF_NULL,	LEN_NULL },
	[END_ME] =	{ OFF_ME,	LEN_ME },
	[END_MI] =	{ OFF_MI,	LEN_MI },
	[END_MO] =	{ OFF_MO,	LEN_MO },
	[END_MU] =	{ OFF_MU,	LEN_MU },
	[END_NA] =	{ OFF_NA,	LEN_NA },
	[END_NE] =	{ OFF_NE,	LEN_NE },
	[END_NO] =	{ OFF_NO,	LEN_NO },
	[END_O] =	{ OFF_O,	LEN_O },
	[END_RA] =	{ OFF_RA,	LEN_RA },
	[END_RE] =	{ OFF_RE,	LEN_RE },
	[END_RIN] =	{ OFF_RIN,	LEN_RIN },
	[END_RI] =	{ OFF_RI,	LEN_RI },
	[END_RU] =	{ OFF_RU,	LEN_RU },
	[END_SA] =	{ OFF_SA,	LEN_SA },
	[END_SU] =	{ OFF_SU,	LEN_SU },
	[END_TO] =	{ OFF_NULL,	LEN_NULL },
	[END_TSU] =	{ OFF_TSU,	LEN_TSU },
	[END_U] =	{ OFF_U,	LEN_U },
	[END_YA] =	{ OFF_YA,	LEN_YA },
	[END_YO] =	{ OFF_YO,	LEN_YO },
	[END_YU] =	{ OFF_YU,	LEN_YU },

	[END_BU] =	{ OFF_NULL, LEN_NULL },
	[END_GI] =	{ OFF_NULL, LEN_NULL },
	[END_GU] =	{ OFF_NULL, LEN_NULL },
	[END_JI] =	{ OFF_NULL, LEN_NULL },
	[END_JO] =	{ OFF_NULL, LEN_NULL },
	[END_RO] =	{ OFF_NULL, LEN_NULL },
	[END_ZU] =	{ OFF_NULL, LEN_NULL },
};
#endif /* TEST */

static const char *name_list[] = {
	[ID_NAGUSA] =		"나구사",
	[ID_NAGISA] =		"나기사",
	[ID_NATSU] =		"나츠",
	[ID_NERU] =			"네루",
	[ID_NONOMI] =		"노노미",
	[ID_NODOKA] =		"노도카",
	[ID_NOA] =			"노아",
	[ID_NOZOMI] =		"노조미",
	[ID_NIYA] =			"니야",
	[ID_NIKO] =			"니코",
	[ID_LOVE] =			"라브",
	[ID_REISA] =		"레이사",
	[ID_REIJO] =		"레이조",
	[ID_RUMI] =			"루미",
	[ID_RIO] =			"리오",
	[ID_RIN] =			"린",
	[ID_MARIANGRY]= 	"마리",
	[ID_MARINA] =		"마리나",
	[ID_MASYRO] =		"마시로",
	[ID_MAKOTO] =		"마코토",
	[ID_MAKI] =			"마키",
	[ID_MEGU] =			"메구",
	[ID_MERU] =			"메루",
	[ID_MOMOI] =		"모모이",
	[ID_MOMOKA] =		"모모카",
	[ID_MOMIJI] =		"모미지",
	[ID_MOE] =			"모에",
	[ID_MUTSUKI] =		"무츠키",
	[ID_MINA] =			"미나",
	[ID_MINEISMINE]=	"미네",
	[ID_MINORI] =		"미노리",
	[ID_MIDORI] =		"미도리",
	[ID_MIMORI] =		"미모리",
	[ID_MISAKI] =		"미사키",
	[ID_MIYAKO] =		"미야코",
	[ID_MIYU] =			"미유",
	[ID_MICHIRU] =		"미치루",
	[ID_MISONO] =		"미카",
	[ID_SAYA] =			"사야",
	[ID_SAORI] =		"사오리",
	[ID_SATSUKI] =		"사츠키",
	[ID_SAKURAKO] =		"사쿠라코",
	[ID_SAKI] =			"사키",
	[ID_SENA] =			"세나",
	[ID_SERINA] =		"세리나",
	[ID_SERIKA] =		"세리카",
	[ID_____] =			"세이아",
	[ID_GODUNG] =		"소라",
	[ID_SHURO] =		"슈로",
	[ID_SUMOMO] =		"스모모",
	[ID_SUMIRE] =		"스미레",
	[ID_SUOU] =			"스오우",
	[ID_HARUHI] =		"스즈미",
	[ID_SHIGURE] =		"시구레",
	[ID_SYROKO] =		"시로코",
	[ID_SHIMIKO] =		"시미코",
	[ID_SHIZUKO] =		"시즈코",
	[ID_ARONA] =		"아로나",
	[ID_ARU] =			"아루",
	[ID_ARISU] =		"아리스",
	[ID_ASUNA] =		"아스나",
	[ID_AYANE] =		"아야네",
	[ID_AYAME] =		"아야메",
	[ID_AOI] =			"아오이",
	[ID_AYuwu] =		"아유무",
	[ID_AIRI] =			"아이리",
	[ID_AZ_USA] =		"아즈사",
	[ID_ATSUKO] =		"아츠코",
	[ID_AKANE] =		"아카네",
	[ID_AKARI] =		"아카리",
	[ID_ALKEMIST] =		"아케미",
	[ID_AKO] =			"아코",
	[ID_AKIRA] =		"아키라",
	[ID_YAKUMO] =		"야쿠모",
	[ID_ERIKA] =		"에리카",
	[ID_EIMI] =			"에이미",
	[ID_OTTOOGI] =		"오토기",
	[ID_WAKAMO] =		"와카모",
	[ID_YOSHI] =		"요시미",
	[ID_UMIKA] =		"우미카",
	[ID_UI] =			"우이",
	[ID_UTAHAHA] =		"우타하",
	[ID_YUME] =			"유메",
	[ID_YUUKA] =		"유우카",
	[ID_USE] =			"유즈",
	[ID_YUKARI] =		"유카리",
	[ID_YUKINO] =		"유키노",
	[ID_IROHA] =		"이로하",
	[ID_IBUKI] =		"이부키",
	[ID_IORI] =			"이오리",
	[ID_IZUNA] =		"이즈나",
	[ID_IZUMI] =		"이즈미",
	[ID_ICHIKA] =		"이치카",
	[ID_JURI] =			"주리",
	[ID_JUNKO] =		"준코",
	[ID_CHERRYNO] =		"체리노",
	[ID_TSURUGI] =		"츠루기",
	[ID_TSuwuGI] =		"츠무기",
	[ID_TSUBAKI] =		"츠바키",
	[ID_TSUKUYO] =		"츠쿠요",
#ifndef TEST
	[ID_CHINATSU] =		"치나츠",
	[ID_CHISE] =		"치세",
	[ID_CHIAKI] =		"치아키",
	[ID_CHIHIRO] =		"치히로",
	[ID_KAGUYA] =		"카구야",
	[ID_KARIN] =		"카린",
	[ID_KASUMI] =		"카스미",
	[ID_KAYA] =			"카야",
	[ID_KACDC] =		"카에데",
	[ID_KAYOKO] =		"카요코",
	[ID_KAI] =			"카이",
	[ID_KAZUSA] =		"카즈사",
	[ID_KAHO] =			"카호",
	[ID_KANNA] =		"칸나",
	[ID_KONOKA] =		"코노카",
	[ID_KOYUKI] =		"코유키",
	[ID_KOKONUT] =		"코코나",
	[ID_KKRIKO] =		"코쿠리코",
	[ID_KOTAMA] =		"코타마",
	[ID_KOTLIN] =		"코토리",
	[ID_KOHARU] =		"코하루",
	[ID_KURUMI] =		"쿠루미",
	[ID_KZNOHA] =		"쿠즈노하",
	[ID_KIRARA] =		"키라라",
	[ID_KIRINO] =		"키리노",
	[ID_KISAKI] =		"키사키",
	[ID_KICKYOU] =		"키쿄",
	[ID_TAKANE] =		"타카네",
	[ID_TOMOE] =		"토모에",
	[ID_TOKKI] =		"토키",
	[ID_PLANA] =		"프라나",
	[ID_PINA] =			"피나",
	[ID_HANAE] =		"하나에",
	[ID_HANAKO] =		"하나코",
	[ID_HARE] =			"하레",
	[ID_HARUNA] =		"하루나",
	[ID_HARUKA] =		"하루카",
	[ID_HASUMI] =		"하스미",
	[ID_HAINEKEN] =		"하이네",
	[ID_HOSHINO] =		"호시노",
	[ID_HuwuKI] =		"후부키",
	[ID_HuwuKA] =		"후우카",
	[ID_HINA] =			"히나",
	[ID_HINATA] =		"히나타",
	[ID_HIMARI] =		"히마리",
	[ID_HIBIKI] =		"히비키",
	[ID_HIYORI] =		"히요리",
	[ID_HIKARI] =		"히카리",
	[ID_HIHUMI] =		"히후미",
#endif /* TEST */
};


static inline node_t *node_new(const int id)
{
	node_t *ret = malloc(sizeof(node_t));
	ret->id = id;
	return ret;
}

static inline void node_delcsc(node_t *node)
{
	node_t *rp = node;

	while (rp != NULL) {
		node_t *next = rp->next;
		rp->next = NULL;
		free(rp);
		rp = next;
	}
}

static inline int flag_chk(int id, const u64 flag_old[], u64 flag_new[])
{
	u64 chk;
	u64 flag = FLAGID(id);

	id >>= 6;				//HASKELLLLLLLLLL
	chk = flag_old[id];

	if ((flag & chk) == flag)
		return CHECK_DUPLICATED;

	flag_new[0] = flag_old[0];
	flag_new[1] = flag_old[1];
#ifndef TEST
	flag_new[2] = flag_old[2];
#endif /* TEST */

	flag_new[id] |= flag;

	return CHECK_PASS;
}

static node_t *longest(const int id, const u64 flag[], int *cnt)
{
	node_t *ret, *sub = NULL;
	u64 flag_new[FLAG_MAX];
	int cnt_local = 0;
	int end_ch = chain_list[id];

	if (flag_chk(id, flag, flag_new) == CHECK_DUPLICATED)
		return NULL;

	for (int i = 0; i < LEN(end_ch); i++) {
		int id_next = OFF(end_ch) + i;
		int cnt_tmp;
		node_t *tmp;

		tmp = longest(id_next, flag_new, &cnt_tmp);
		if (tmp == NULL)
			continue;

		if (cnt_tmp > cnt_local) {
			cnt_local = cnt_tmp;
			node_delcsc(sub);
			sub = tmp;
		} else {
			node_delcsc(tmp);
		}
	}

	ret = node_new(id);
	ret->next = sub;
	*cnt = cnt_local + 1;

	return ret;
}

static void node_print(node_t *node)
{
	int cnt = 0;

	while (node != NULL) {
		printf("%s->", name_list[node->id]);
		if (cnt++ % 10 == 9)
			puts("");

		node = node->next;
	}

	printf("total: %d\n", cnt);
}

static void usage(void)
{
	puts("사용법: ./a.out 줄_번호");
	exit(EXIT_FAILURE);
}


int main(int argc, char *argv[])
{
	int arg;

	if (argc > 2)
		usage();

	if (argv[1] != NULL)
		arg = strtol(argv[1], NULL, 10);
	else
		goto WHOLE;

	if (arg == 0)
		usage();

	int cnt;
	u64 flag_init[FLAG_MAX] = {};

	node_t *node = longest(arg - 1, flag_init, &cnt);

	node_print(node);
	node_delcsc(node);

	return 0;


WHOLE:
	node_t *res = NULL;
	int cnt_max = 0;

	for (int i = 0; i <= LAST; i++) {
		int cnt;
		u64 flag_init[FLAG_MAX] = {};

		node_t *node = longest(i, flag_init, &cnt);
		node_print(node);

		if (cnt > cnt_max) {
			node_delcsc(res);
			res = node;
			cnt_max = cnt;
		} else {
			node_delcsc(node);
		}
	}

	printf("#######결과######\n");
	node_print(res);
	node_delcsc(res);

	return 0;
}
