#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define NELEM(x)			(sizeof(x)/sizeof((x)[0]))

# define FLAG_MAX			2
# define LAST				ID_HIHUMI

#define CHECK_PASS			0
#define CHECK_DUPLICATED	1
#define FLAGID(ID)			(1ULL << ((ID) & 0b111111))

#define OFF(x)				(offlen[(x)].off)
#define LEN(x)				(offlen[(x)].len)

#define OFF_NULL			0
#define OFF_NA				0
#define OFF_NE				2
#define OFF_NO				3
#define OFF_RE				6
#define OFF_RU				8
#define OFF_MA				9
#define OFF_ME				14
#define OFF_MO				16
#define OFF_MU				19
#define OFF_MI				20
#define OFF_SA				30
#define OFF_SE				35
#define OFF_SU				38
#define OFF_SHI				40
#define OFF_A				44
#define OFF_E				54
#define OFF_WA				55
#define OFF_YO				56
#define OFF_U				57
#define OFF_YU				60
#define OFF_I				63
#define OFF_JU				69
#define OFF_JUN				70
#define OFF_CHE				71
#define OFF_TSU				72
#define OFF_CHI				75
#define OFF_KA				79
#define OFF_KAN				85
#define OFF_KO				86
#define OFF_KI				91
#define OFF_TO				95
#define OFF_PI				97
#define OFF_HA				98
#define OFF_HO				104
#define OFF_HU				105
#define OFF_HI				107

#define LEN_NULL			0
#define LEN_NA				(OFF_NE - OFF_NA)
#define LEN_NE				(OFF_NO - OFF_NE)
#define LEN_NO				(OFF_RE - OFF_NO)
#define LEN_RE				(OFF_RU - OFF_RE)
#define LEN_RU				(OFF_MA - OFF_RU)
#define LEN_MA				(OFF_ME - OFF_MA)
#define LEN_ME				(OFF_MO - OFF_ME)
#define LEN_MO				(OFF_MU - OFF_MO)
#define LEN_MU				(OFF_MI - OFF_MU)
#define LEN_MI				(OFF_SA - OFF_MI)
#define LEN_SA				(OFF_SE - OFF_SA)
#define LEN_SE				(OFF_SU - OFF_SE)
#define LEN_SU				(OFF_SHI - OFF_SU)
#define LEN_SHI				(OFF_A - OFF_SHI)
#define LEN_A				(OFF_E - OFF_A)
#define LEN_E				(OFF_WA - OFF_E)
#define LEN_WA				(OFF_YO - OFF_WA)
#define LEN_YO				(OFF_U - OFF_YO)
#define LEN_U				(OFF_YU - OFF_U)
#define LEN_YU				(OFF_I - OFF_YU)
#define LEN_I				(OFF_JU - OFF_I)
#define LEN_JU				(OFF_JUN - OFF_JU)
#define LEN_JUN				(OFF_CHE - OFF_JUN)
#define LEN_CHE				(OFF_TSU - OFF_CHE)
#define LEN_TSU				(OFF_CHI - OFF_TSU)
#define LEN_CHI				(OFF_KA - OFF_CHI)
#define LEN_KA				(OFF_KAN - OFF_KA)
#define LEN_KAN				(OFF_KO - OFF_KAN)
#define LEN_KO				(OFF_KI - OFF_KO)
#define LEN_KI				(OFF_TO - OFF_KI)
#define LEN_TO				(OFF_PI - OFF_TO)
#define LEN_PI				(OFF_HA - OFF_PI)
#define LEN_HA				(OFF_HO - OFF_HA)
#define LEN_HO				(OFF_HU - OFF_HO)
#define LEN_HU				(OFF_HI - OFF_HU)
#define LEN_HI				6

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

enum {
	//0~63
	ID_NAGISA, ID_NATSU, ID_NERU, ID_NONOMI, ID_NODOKA, ID_NOA, ID_REISA,
	ID_REIJO, ID_RUMI, ID_MARIANGRY, ID_MARINA, ID_MASYRO, ID_MAKOTO, ID_MAKI,
	ID_MEGU, ID_MERU, ID_MOMOI, ID_MOMIJI, ID_MOE, ID_MUTSUKI, ID_MINA,
	ID_MINEISMINE, ID_MINORI, ID_MIDORI, ID_MIMORI, ID_MISAKI, ID_MIYAKO,
	ID_MIYU, ID_MICHIRU, ID_MISONO, ID_SAYA, ID_SAORI, ID_SATSUKI, ID_SAKURAKO,
	ID_SAKI, ID_SENA, ID_SERINA, ID_SERIKA, ID_SUMIRE, ID_HARUHI, ID_SHIGURE,
	ID_SYROKO, ID_SHIMIKO, ID_SHIZUKO, ID_ARU, ID_ARISU, ID_ASUNA, ID_AYANE,
	ID_AIRI, ID_AZ_USA, ID_ATSUKO, ID_AKANE, ID_AKARI, ID_AKO, ID_EIMI, ID_WAKAMO,
	ID_YOSHI, ID_UMIKA, ID_UI, ID_UTAHAHA, ID_YUUKA, ID_USE, ID_YUKARI, ID_IROHA,

	//64~
	ID_IBUKI, ID_IORI, ID_IZUNA, ID_IZUMI, ID_ICHIKA, ID_JURI, ID_JUNKO,
	ID_CHERRYNO, ID_TSU3UGI, ID_TSUBAKI, ID_TSUKUYO, ID_CHINATSU, ID_CHISE,
	ID_CHIAKI, ID_CHIHIRO, ID_KARIN, ID_KASUMI, ID_KACDC, ID_KAYOKO, ID_KAZ_USA,
	ID_KAHO, ID_KANNA, ID_KOYUKI, ID_KOKONUT, ID_KOTAMA, ID_KOTLIN, ID_KOHARU,
	ID_KIRARA, ID_KIRINO, ID_KISAKI, ID_KICKYOU, ID_TOMOE, ID_TOKKI, ID_PINA,
	ID_HANAE, ID_HANAKO, ID_HARE, ID_HARUNA, ID_HARUKA, ID_HASUMI, ID_HOSHINO,
	ID_HuwuKI, ID_HuwuKA, ID_HINA, ID_HINATA, ID_HIMARI, ID_HIBIKI, ID_HIYORI,
	ID_HIHUMI,
};

enum {
	END_A, END_DE, END_E, END_GI, END_GU, END_HA, END_HO, END_I, END_JI, END_JO,
	END_KA, END_KI, END_KO, END_KYO, END_MA, END_MI, END_MO, END_NA, END_NE,
	END_NO, END_RA, END_RE, END_RI, END_RIN, END_RO, END_RU, END_SA, END_SE,
	END_SU, END_TA, END_TO, END_TSU, END_YA, END_YO, END_YU, END_ZU,
};


static const int chain_list[] = {
	[ID_NAGISA] = 		END_SA,		/* 000 OFF_NA */
	[ID_NATSU] = 		END_TSU,	/* 001 */
	[ID_NERU] = 		END_RU,		/* 002 OFF_NE */
	[ID_NONOMI] = 		END_MI,		/* 003 OFF_NO */
	[ID_NODOKA] = 		END_KA,		/* 004 */
	[ID_NOA] = 			END_A,		/* 005 */
	[ID_REISA] = 		END_SA,		/* 006 OFF_RE */
	[ID_REIJO] = 		END_JO,		/* 007 */
	[ID_RUMI] = 		END_MI,		/* 008 OFF_RU */
	[ID_MARIANGRY] = 	END_RI,		/* 009 OFF_MA */
	[ID_MARINA] = 		END_NA,		/* 010 */
	[ID_MASYRO] = 		END_RO,		/* 011 */
	[ID_MAKOTO] = 		END_TO,		/* 012 */
	[ID_MAKI] = 		END_KI,		/* 013 */
	[ID_MEGU] = 		END_GU,		/* 014 OFF_ME */
	[ID_MERU] = 		END_RU,		/* 015 */
	[ID_MOMOI] = 		END_I,		/* 016 OFF_MO */
	[ID_MOMIJI] = 		END_JI,		/* 017 */
	[ID_MOE] = 			END_E,		/* 018 */
	[ID_MUTSUKI] = 		END_KI,		/* 019 OFF_MU */
	[ID_MINA] = 		END_NA,		/* 020 OFF_MI */
	[ID_MINEISMINE] = 	END_NE,		/* 021 */
	[ID_MINORI] = 		END_RI,		/* 022 */
	[ID_MIDORI] = 		END_RI,		/* 023 */
	[ID_MIMORI] = 		END_RI,		/* 024 */
	[ID_MISAKI] = 		END_KI,		/* 025 */
	[ID_MIYAKO] = 		END_KO,		/* 026 */
	[ID_MIYU] = 		END_YU,		/* 027 */
	[ID_MICHIRU] = 		END_RU,		/* 028 */
	[ID_MISONO] = 		END_KA,		/* 029 */
	[ID_SAYA] = 		END_YA,		/* 030 OFF_SA */
	[ID_SAORI] = 		END_RI,		/* 031 */
	[ID_SATSUKI] = 		END_KI,		/* 032 */
	[ID_SAKURAKO] = 	END_KO,		/* 033 */
	[ID_SAKI] = 		END_KI,		/* 034 */
	[ID_SENA] = 		END_NA,		/* 035 OFF_SE */
	[ID_SERINA] = 		END_NA,		/* 036 */
	[ID_SERIKA] = 		END_KA,		/* 037 */
	[ID_SUMIRE] = 		END_RE,		/* 038 OFF_SU */
	[ID_HARUHI] = 		END_MI,		/* 039 */
	[ID_SHIGURE] = 		END_RE,		/* 040 OFF_SHI */
	[ID_SYROKO] = 		END_KO,		/* 041 */
	[ID_SHIMIKO] = 		END_KO,		/* 042 */
	[ID_SHIZUKO] = 		END_KO,		/* 043 */
	[ID_ARU] = 			END_RU,		/* 044 OFF_A */
	[ID_ARISU] = 		END_SU,		/* 045 */
	[ID_ASUNA] = 		END_NA,		/* 046 */
	[ID_AYANE] = 		END_NE,		/* 047 */
	[ID_AIRI] = 		END_RI,		/* 048 */
	[ID_AZ_USA] = 		END_SA,		/* 049 */
	[ID_ATSUKO] = 		END_KO,		/* 050 */
	[ID_AKANE] = 		END_NE,		/* 051 */
	[ID_AKARI] = 		END_RI,		/* 052 */
	[ID_AKO] = 			END_KO,		/* 053 */
	[ID_EIMI] = 		END_MI,		/* 054 OFF_E */
	[ID_WAKAMO] = 		END_MO,		/* 055 OFF_WA */
	[ID_YOSHI] = 		END_MI,		/* 056 OFF_YO */
	[ID_UMIKA] = 		END_KA,		/* 057 OFF_U */
	[ID_UI] = 			END_I,		/* 058 */
	[ID_UTAHAHA] = 		END_HA,		/* 059 */
	[ID_YUUKA] = 		END_KA,		/* 060 OFF_YU */
	[ID_USE] = 			END_ZU,		/* 061 */
	[ID_YUKARI] = 		END_RI,		/* 062 */
	[ID_IROHA] = 		END_HA,		/* 063 OFF_I */
	[ID_IBUKI] = 		END_KI,		/* 064 */
	[ID_IORI] = 		END_RI,		/* 065 */
	[ID_IZUNA] = 		END_NA,		/* 066 */
	[ID_IZUMI] = 		END_MI,		/* 067 */
	[ID_ICHIKA] = 		END_KA,		/* 068 */
	[ID_JURI] = 		END_RI,		/* 069 OFF_JU */
	[ID_JUNKO] = 		END_KO,		/* 070 OFF_JUN */
	[ID_CHERRYNO] = 	END_NO,		/* 071 OFF_CHE */
	[ID_TSU3UGI] = 		END_GI,		/* 072 OFF_TSU */
	[ID_TSUBAKI] = 		END_KI,		/* 073 */
	[ID_TSUKUYO] = 		END_YO,		/* 074 */
	[ID_CHINATSU] = 	END_TSU,	/* 075 OFF_CHI */
	[ID_CHISE] = 		END_SE,		/* 076 */
	[ID_CHIAKI] = 		END_KI,		/* 077 */
	[ID_CHIHIRO] = 		END_RO,		/* 078 */
	[ID_KARIN] = 		END_RIN,	/* 079 OFF_KA */
	[ID_KASUMI] = 		END_MI,		/* 080 */
	[ID_KACDC] = 		END_DE,		/* 081 */
	[ID_KAYOKO] = 		END_KO,		/* 082 */
	[ID_KAZ_USA] = 		END_SA,		/* 083 */
	[ID_KAHO] = 		END_HO,		/* 084 */
	[ID_KANNA] = 		END_NA,		/* 085 OFF_KAN */
	[ID_KOYUKI] = 		END_KI,		/* 086 OFF_KO */
	[ID_KOKONUT] = 		END_NA,		/* 087 */
	[ID_KOTAMA] = 		END_MA,		/* 088 */
	[ID_KOTLIN] = 		END_RI,		/* 089 */
	[ID_KOHARU] = 		END_RU,		/* 090 */
	[ID_KIRARA] = 		END_RA,		/* 091 OFF_KI */
	[ID_KIRINO] = 		END_NO,		/* 092 */
	[ID_KISAKI] = 		END_KI,		/* 093 */
	[ID_KICKYOU] = 		END_KYO,	/* 094 */
	[ID_TOMOE] = 		END_E,		/* 095 OFF_TO */
	[ID_TOKKI] = 		END_KI,		/* 096 */
	[ID_PINA] = 		END_NA,		/* 097 OFF_PI */
	[ID_HANAE] = 		END_E,		/* 098 OFF_HA */
	[ID_HANAKO] = 		END_KO,		/* 099 */
	[ID_HARE] = 		END_RE,		/* 100 */
	[ID_HARUNA] = 		END_NA,		/* 101 */
	[ID_HARUKA] = 		END_KA,		/* 102 */
	[ID_HASUMI] = 		END_MI,		/* 103 */
	[ID_HOSHINO] = 		END_NO,		/* 104 OFF_HO */
	[ID_HuwuKI] = 		END_KI,		/* 105 OFF_HU */
	[ID_HuwuKA] = 		END_KA,		/* 106 */
	[ID_HINA] = 		END_NA,		/* 107 OFF_HI */
	[ID_HINATA] = 		END_TA,		/* 108 */
	[ID_HIMARI] = 		END_RI,		/* 109 */
	[ID_HIBIKI] = 		END_KI,		/* 110 */
	[ID_HIYORI] = 		END_RI,		/* 111 */
	[ID_HIHUMI] = 		END_MI,		/* 112 */
};

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
	[END_MI] =	{ OFF_MI,	LEN_MI },
	[END_MO] =	{ OFF_MO,	LEN_MO },
	[END_NA] =	{ OFF_NA,	LEN_NA },
	[END_NE] =	{ OFF_NE,	LEN_NE },
	[END_NO] =	{ OFF_NO,	LEN_NO },
	[END_RE] =	{ OFF_RE,	LEN_RE },
	[END_RU] =	{ OFF_RU,	LEN_RU },
	[END_SA] =	{ OFF_SA,	LEN_SA },
	[END_SE] =	{ OFF_SE,	LEN_SE },
	[END_SU] =	{ OFF_SU,	LEN_SU },
	[END_TO] =	{ OFF_TO,	LEN_TO },
	[END_TSU] =	{ OFF_TSU,	LEN_TSU },
	[END_YO] =	{ OFF_YO,	LEN_YO },
	[END_YU] =	{ OFF_YU,	LEN_YU },

	[END_RIN] =	{ OFF_NULL,	LEN_NULL },
	[END_RI] =	{ OFF_NULL,	LEN_NULL },
	[END_TA] =	{ OFF_NULL,	LEN_NULL },
	[END_YA] =	{ OFF_NULL,	LEN_NULL },
	[END_DE] =	{ OFF_NULL, LEN_NULL },
	[END_GI] =	{ OFF_NULL, LEN_NULL },
	[END_GU] =	{ OFF_NULL, LEN_NULL },
	[END_JI] =	{ OFF_NULL, LEN_NULL },
	[END_JO] =	{ OFF_NULL, LEN_NULL },
	[END_KYO] =	{ OFF_NULL, LEN_NULL },
	[END_RO] =	{ OFF_NULL, LEN_NULL },
	[END_ZU] =	{ OFF_NULL, LEN_NULL },
};

static const char *name_list[] = {
	[ID_NAGISA] =		"나기사",
	[ID_NATSU] =		"나츠",
	[ID_NERU] =			"네루",
	[ID_NONOMI] =		"노노미",
	[ID_NODOKA] =		"노도카",
	[ID_NOA] =			"노아",
	[ID_REISA] =		"레이사",
	[ID_REIJO] =		"레이조",
	[ID_RUMI] =			"루미",
	[ID_MARIANGRY]= 	"마리",
	[ID_MARINA] =		"마리나",
	[ID_MASYRO] =		"마시로",
	[ID_MAKOTO] =		"마코토",
	[ID_MAKI] =			"마키",
	[ID_MEGU] =			"메구",
	[ID_MERU] =			"메루",
	[ID_MOMOI] =		"모모이",
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
	[ID_SUMIRE] =		"스미레",
	[ID_HARUHI] =		"스즈미",
	[ID_SHIGURE] =		"시구레",
	[ID_SYROKO] =		"시로코",
	[ID_SHIMIKO] =		"시미코",
	[ID_SHIZUKO] =		"시즈코",
	[ID_ARU] =			"아루",
	[ID_ARISU] =		"아리스",
	[ID_ASUNA] =		"아스나",
	[ID_AYANE] =		"아야네",
	[ID_AIRI] =			"아이리",
	[ID_AZ_USA] =		"아즈사",
	[ID_ATSUKO] =		"아츠코",
	[ID_AKANE] =		"아카네",
	[ID_AKARI] =		"아카리",
	[ID_AKO] =			"아코",
	[ID_EIMI] =			"에이미",
	[ID_WAKAMO] =		"와카모",
	[ID_YOSHI] =		"요시미",
	[ID_UMIKA] =		"우미카",
	[ID_UI] =			"우이",
	[ID_UTAHAHA] =		"우타하",
	[ID_YUUKA] =		"유우카",
	[ID_USE] =			"유즈",
	[ID_YUKARI] =		"유카리",
	[ID_IROHA] =		"이로하",
	[ID_IBUKI] =		"이부키",
	[ID_IORI] =			"이오리",
	[ID_IZUNA] =		"이즈나",
	[ID_IZUMI] =		"이즈미",
	[ID_ICHIKA] =		"이치카",
	[ID_JURI] =			"주리",
	[ID_JUNKO] =		"준코",
	[ID_CHERRYNO] =		"체리노",
	[ID_TSU3UGI] =		"츠루기",
	[ID_TSUBAKI] =		"츠바키",
	[ID_TSUKUYO] =		"츠쿠요",
	[ID_CHINATSU] =		"치나츠",
	[ID_CHISE] =		"치세",
	[ID_CHIAKI] =		"치아키",
	[ID_CHIHIRO] =		"치히로",
	[ID_KARIN] =		"카린",
	[ID_KASUMI] =		"카스미",
	[ID_KACDC] =		"카에데",
	[ID_KAYOKO] =		"카요코",
	[ID_KAZ_USA] =		"카즈사",
	[ID_KAHO] =			"카호",
	[ID_KANNA] =		"칸나",
	[ID_KOYUKI] =		"코유키",
	[ID_KOKONUT] =		"코코나",
	[ID_KOTAMA] =		"코타마",
	[ID_KOTLIN] =		"코토리",
	[ID_KOHARU] =		"코하루",
	[ID_KIRARA] =		"키라라",
	[ID_KIRINO] =		"키리노",
	[ID_KISAKI] =		"키사키",
	[ID_KICKYOU] =		"키쿄",
	[ID_TOMOE] =		"토모에",
	[ID_TOKKI] =		"토키",
	[ID_PINA] =			"피나",
	[ID_HANAE] =		"하나에",
	[ID_HANAKO] =		"하나코",
	[ID_HARE] =			"하레",
	[ID_HARUNA] =		"하루나",
	[ID_HARUKA] =		"하루카",
	[ID_HASUMI] =		"하스미",
	[ID_HOSHINO] =		"호시노",
	[ID_HuwuKI] =		"후부키",
	[ID_HuwuKA] =		"후우카",
	[ID_HINA] =			"히나",
	[ID_HINATA] =		"히나타",
	[ID_HIMARI] =		"히마리",
	[ID_HIBIKI] =		"히비키",
	[ID_HIYORI] =		"히요리",
	[ID_HIHUMI] =		"히후미",
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
	//flag_new[2] = flag_old[2];

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


int main(int argc, char *argv[])
{
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

	puts("#######결과######");
	node_print(res);
	node_delcsc(res);

	return 0;
}
