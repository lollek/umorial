#ifndef __MORIA_PLAYER_HH__
#define __MORIA_PLAYER_HH__

#include <string>

class Player
{
  public:

    /* Create a clean character */
    Player();

    /* Generate stats for the player
     * This function expects race and gender to be set */
    void generate();

    /* Forbid copying */
    Player(const Player&) = delete;
    void operator=(const Player&) = delete;

    /* Getters */
    int getRace() const;         /* Race as number, see Tables.hh */
    bool getSex() const;         /* True if male */
    int getAge() const;          /* Age of character */
    int getWeight() const;       /* Weight of character */
    int getHeight() const;       /* Height of character */
    int getSocialClass() const;  /* Class, 0 - 100 */
    int getGold() const;
    int getLevel() const;
    int getXP() const;
    int getMaxXP() const;
    int getXPToLevel() const;

    /* Stats in raw form, i.e. 0 - 118 */
    int getStr() const;
    int getDex() const;
    int getCon() const;
    int getWis() const;
    int getInt() const;
    int getCha() const;

    int getDisarm() const;        /* % to disarm */
    int getSearchChance() const;  /* chance in search, old: srh */
    int getSearchFreq() const;    /* Frenq of search, old: fos */
    int getStealth() const;       /* Stealth factor, old: stl */
    int getBaseToHit() const;     /* Base to hit, old: bth */
    int getBowToHit() const;      /* Base to hit w/ bow, old: bthb */
    int getSave() const;          /* Saving throw */
    int getHitDie() const;        /* Hit die */
    int getInfra() const;         /* See warm creatures  */
    int getXPFactor() const;      /* Experience factor, old: expfact */
    int getPlusToHit() const;     /* Plusses to hit, old: ptohit */
    int getPlusToDmg() const;     /* Plusses to dmg, old: ptodam */
    int getPlusToAC() const;      /* Magic AC, old: ptoac */
    int getPlusToHP() const;      /* Plusses to HP */
    int getAC() const;            /* AC + Magic AC, old: dis_ac */
    int getHP() const;
    int getMaxHP() const;         /* Max hitpoints, old: mhp */
    std::string getBackground() const; /* A 0-240 letter background info */

    /* Some of the above, in a %6d-string format */
    std::string getStrString() const; /* Get stat in written form */
    std::string getDexString() const;
    std::string getConString() const;
    std::string getWisString() const;
    std::string getIntString() const;
    std::string getChaString() const;

    /* Mods */
    void modifyGold(int gold);

    void modifyStr(int mod);
    void modifyDex(int mod);
    void modifyCon(int mod);
    void modifyWis(int mod);
    void modifyInt(int mod);
    void modifyCha(int mod);

    /* Setters */
    void setRace(int race);
    void setSex(int sex);
    void setJob(int job);

  private:

    std::string formatInt(int val) const;
    std::string getStatString(int stat) const;
    void modifyStat(int *stat, int mod);

    /* Old type: char[] */
    std::string name; /* Name of character */

    /* Old type: int8u */
    bool gender;      /* Gender of character */

    /* Old type: int32 */
    int gold;         /* Gold of character, old: au */
    int max_exp;      /* Max experience */
    int exp;          /* Current experience */

    /* Old type: int16u */
    int exp_frac;      /* Current xp fraction * 2^16 */
    int age;           /* Age of character */
    int height;        /* Height of character, old: ht */
    int weight;        /* Weight of character, old: wt */
    int level;         /* Character level, old: lev */
    int max_dlevel;    /* max dungeon level explored, old: max_dlv */

    /* Old type: int16 */
    int mana;          /* Mana points */
    int ac;            /* Total AC, old: pac */
    int social_class;  /* Social class, old: sc */

    /* Old type: int8u */
    int job;           /* Class, old: pclass */
    int race;          /* Race, old: prace */

    /* Old type: int16 */
    int current_mana;  /* Current mana points, old: cmana */
    int current_hp;    /* Current hit points, old: chp */

    /* Old type: int16u */
    int current_mfrac; /* Current mana fraction, old: cmana_frac */
    int current_hfrac; /* Current hp fraction, old: chp_frac */

    /* Old type char[4][60] */
    std::string history; /* History record */

    /* (this will probably cause a lot of headache)
     *    Stats   Old Stats
     * 0   STR       STR
     * 1   DEX       INT
     * 2   CON       WIS
     * 3   WIS       DEX
     * 4   INT       CON
     * 5   CHA       CHA
     */
    /* Old type int8u[6] */
    int max_stat[6];   /* What is restored */
    int cur_stat[6];   /* What is natural */
    int use_stat[6];   /* What is used */

    /* Old type int16[6] */
    int mod_stat[6];   /* What is modified */

    /* Old type int32u */
    unsigned flag_status; /* Status of player */

    /* Old type int16 */
    int flag_rest;               /* Rest counter>       */
    int flag_blind;              /* Blindness counter   */
    int flag_paralysis;          /* Paralysis counter   */
    int flag_confused;           /* Confusion counter   */
    int flag_food;               /* Food counter>       */
    int flag_food_digested;      /* Food per round      */
    int flag_protection;         /* Protection fr. evil */
    int flag_speed;              /* Cur speed adjust    */
    int flag_fast;               /* Temp speed change   */
    int flag_slow;               /* Temp speed change   */
    int flag_afraid;             /* Fear>>.......       */
    int flag_poisoned;           /* Poisoned>....       */
    int flag_image;              /* Hallucinate>.       */
    int flag_protevil;           /* Protect VS evil     */
    int flag_invuln;             /* Increases AC>       */
    int flag_hero;               /* Heroism>.....       */
    int flag_shero;              /* Super Heroism       */
    int flag_blessed;            /* Blessed>.....       */
    int flag_resist_heat;        /* Timed heat resist   */
    int flag_resist_cold;        /* Timed cold resist   */
    int flag_detect_inv;         /* Timed see invisible */
    int flag_word_recall;        /* Timed teleport level*/
    int flag_tim_infra;          /* Timed infra vision  */

    /* Old type int8u */
    int flag_see_inv;            /* Can see invisible   */
    int flag_teleport;           /* Random teleportation*/
    int flag_free_act;           /* Never paralyzed     */
    int flag_slow_digest;        /* Lower food needs    */
    int flag_aggravate;          /* Aggravate monsters  */
    int flag_fire_resist;        /* Resistance to fire  */
    int flag_cold_resist;        /* Resistance to cold  */
    int flag_acid_resist;        /* Resistance to acid  */
    int flag_regenerate;         /* Regenerate hit pts  */
    int flag_lght_resist;        /* Resistance to light */
    int flag_ffall;              /* No damage falling   */
    int flag_sustain_str;        /* Keep strength       */
    int flag_sustain_dex;        /* Keep dexterity      */
    int flag_sustain_con;        /* Keep constitution   */
    int flag_sustain_wis;        /* Keep wisdom>.       */
    int flag_sustain_int;        /* Keep intelligence   */
    int flag_sustain_chr;        /* Keep charisma       */
    int flag_confuse_monster;    /* Glowing hands.    */
    int flag_new_spells;         /* Number of spells can learn. */
};

#endif //__MORIA_PLAYER_HH__
