#ifndef _CONST__H_
#define _CONST__H_

enum {
    RESOURCE_RUBY,
    RESOURCE_SAPPHIRE,
    RESOURCE_EMERALD,
    RESOURCE_TOPAZ,
    RESOURCE_DIAMOND,
    RESOURCE_COPPER,
    RESOURCE_IRON,
    RESOURCE_WOOD,
    RESOURCE_ALUMINIUM,

    NUM_RESOURCES,
};

enum {
    ROBOT_TYPE_ROBOT     = 0,
    ROBOT_TYPE_SPIKEBOT  = 1,
    ROBOT_TYPE_COMPANION = 2,
    ROBOT_TYPE_BOMBER    = 3,
    ROBOT_TYPE_LOBBER    = 4,
    ROBOT_TYPE_MINIBOT   = 5,

    NUM_ROBOT_TYPES
};

enum {
    ROBOT_PROPERTY_SPEED          = 0,
    ROBOT_PROPERTY_STATE          = 1,
    ROBOT_PROPERTY_ROAMING        = 2,
    ROBOT_PROPERTY_ATTACK_DELAY   = 3,
    ROBOT_PROPERTY_DIR            = 4,
    ROBOT_PROPERTY_HP             = 5,
    ROBOT_PROPERTY_FACTION        = 6,
    ROBOT_PROPERTY_EQUIPMENT      = 7,
    ROBOT_PROPERTY_FEET           = 8,
    ROBOT_PROPERTY_HEAD           = 9,
    ROBOT_PROPERTY_BACK           = 10,
    ROBOT_PROPERTY_HEAD_EQUIPMENT = 11,
    ROBOT_PROPERTY_FRONT          = 12,
    ROBOT_PROPERTY_BOLT_SET       = 13,

    NUM_ROBOT_PROPERTIES
};

enum {
    EFFECT_TYPE_HEALTH,
    EFFECT_TYPE_SPEED,
    EFFECT_TYPE_JUMP_STRENGTH,
    EFFECT_TYPE_ARMOUR,
    EFFECT_TYPE_CD_REDUCTION,

    NUM_EFFECT_TYPES
};

enum {
    EFFECT_METHOD_ADDITIVE,
    EFFECT_METHOD_MULTIPLICATIVE,

    NUM_EFFECT_METHODS
};

#define ES_LOCKED               (1ULL << 0)  /* saved entity is locked */
#define ES_MOVEABLE             (1ULL << 1)
#define ES_AXIS_ROT             (1ULL << 2)
#define ES_SLEEPING             (1ULL << 3)
#define ES_DISABLE_UNLOADING    (1ULL << 4)

/* Identifying data */
#define IDD_IN_SANDBOX              (1ULL << 0)
#define IDD_IN_ADVENTURE            (1ULL << 1)
#define IDD_IN_MAIN_PUZZLE          (1ULL << 2)
#define IDD_PLAYING_COMMUNITY_LEVEL (1ULL << 3)
#define IDD_IN_MENU                 (1ULL << 4)

#define NUM_LAYERS 3
#define LAYER_DEPTH 1.f

#define TARGET_DIST_SCALE .75f

#define SCORE_XOR 0x8aef12af

enum {
    ENTITY_EVENT_REMOVE,
    ENTITY_EVENT_DEATH,

    ENTITY_EVENT__NUM
};

#define BASE_HIGHSCORE_LEVEL_ID 994991

/* id types */
#define LEVEL_LOCAL   0
#define LEVEL_DB      1
#define LEVEL_MAIN    2
#define LEVEL_SYS     3
#define LEVEL_PARTIAL 4

#define LEVEL_LOCAL_STATE 100
#define LEVEL_DB_STATE    101
#define LEVEL_MAIN_STATE  102

enum {
    HS_VER_DATA_TIMESTAMP = 0,
    HS_VER_DATA_REVISION = 1,
    HS_VER_DATA_TYPE = 2,
    HS_VER_DATA_PRINCIPIA_VERSION = 3,
    HS_VER_DATA_VERSION = 4,
};

#define MAX_CHAINSAW_TIMER 500000

enum {
    SND_WOOD_METAL,
    SND_WOOD_WOOD,
    SND_WOOD_HOLLOWWOOD,
    SND_CLICK,
    SND_DROP_ABSORB,
    SND_ROBOT,
    SND_ROBOT_SHOOT,
    SND_SHOTGUN_SHOOT,
    SND_SHOTGUN_COCK,
    SND_RAILGUN_SHOOT,
    SND_ROBOT_BOMB,
    SND_ROCKET,
    SND_THRUSTER,
    SND_EXPLOSION,
    SND_EXPLOSION_LIGHT,
    SND_SHEET_METAL,
    SND_RUBBER,
    SND_ABSORB,
    SND_EMIT,
    SND_METAL_METAL,
    SND_METAL_METAL2,
    SND_PLAYER_DEATH,
    SND_DING,
    SND_WEIRD,
    SND_DETECT,
    SND_WARNING,
    SND_DRUM1,
    SND_DRUM2,
    SND_BUBBLES,
    SND_ROCKET_LAUNCHER_SHOOT,
    SND_CASH_REGISTER,
    SND_DISCHARGE,
    SND_PLASMA_SHOOT,
    SND_BUSTER_SHOOT,
    SND_BUSTER_SHOOT_MAXCHARGE,
    SND_BUSTER_CHARGE,
    SND_STONE_STONE,
    SND_CHEST_OPEN,
    SND_CHEST_OPEN_RARE,
    SND_MINING_HIT_ORE,
    SND_ZAPPER,
    SND_COMPRESSOR,
    SND_COMPRESSOR_REVERSE,
    SND_SAW,
    SND_CHOP_WOOD,
    SND_SWISH_HAMMER,
    SND_SWISH_BLADE,
    SND_SWISH_SPEAR,
    SND_SWISH_AXE,
    SND_HAPPY,
    SND_TEST,
    SND_WIN,
    SND_MOTOR_STARTSTOP,

    SND__NUM
};

enum {
    PROMPT_RESPONSE_NONE,
    PROMPT_RESPONSE_A,
    PROMPT_RESPONSE_B,
    PROMPT_RESPONSE_C
};

#endif
