/* See LICENSE file for copyright and license details. */

#ifndef XF86LaunchA
#define XF86LaunchA 0x1008ff4a
#endif

#ifndef XF86LaunchB
#define XF86LaunchB 0x1008ff4b
#endif


/* appearance */
static const char font[]            = "-*-terminus-medium-r-*-*-12-*-*-*-*-*-*-*";
static const char normbordercolor[] = "#444444";
static const char normbgcolor[]     = "#222222";
static const char normfgcolor[]     = "#bbbbbb";
static const char selbordercolor[]  = "#5B009C"; /* #"#005577"; */
static const char selbgcolor[]      = "#5B009C"; /* #"#005577"; */
static const char selfgcolor[]      = "#eeeeee";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "browser", "mail", "3", "4", "5", "6", "7", "music", "skype" };

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            True,        -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       False,       -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",      tile },    /* first entry is default */
	{ "[F]",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "x-terminal-emulator", NULL };
#define KEYCMD(KEY,ARG) \
  static const char *KEY[] = { "/home/guillermo/bin/keypress", ARG, NULL };
//static const char *vol_down[]  = { "/home/guillermo/bin/keypress" , "vol_down" };

KEYCMD( audio_lower_volume  , "audio_lower_volume" )
KEYCMD( audio_raise_volume  , "audio_raise_volume" )
KEYCMD( audio_mute  , "audio_mute" )
KEYCMD( audio_play          , "audio_play"         )
KEYCMD( audio_stop          , "audio_stop"         )
KEYCMD( audio_prev          , "audio_prev"         )
KEYCMD( audio_next          , "audio_next"         )
KEYCMD( mon_brightness_up   , "mon_brightness_up"  )
KEYCMD( mon_brightness_down , "mon_brightness_down" )
KEYCMD( kbd_brightness_up   , "kbd_brightness_up"  )
KEYCMD( kbd_brightness_down , "kbd_brightness_down" )
KEYCMD( launch_a , "launch_a" )
KEYCMD( launch_b , "launch_b" )

static Key keys[] = {
	/* modifier,                     key,        function,        argument */
	{ MODKEY                      , XK_p                    , spawn         , {.v = dmenucmd } }         ,
	{ MODKEY|ShiftMask            , XK_Return               , spawn         , {.v = termcmd } }          ,
	{ 0                           , XF86XK_AudioLowerVolume , spawn         , {.v = audio_lower_volume }},
	{ 0                           , XF86XK_AudioRaiseVolume , spawn         , {.v = audio_raise_volume }},
	{ 0                           , XF86XK_AudioMute        , spawn         , {.v = audio_mute         }},
	{ 0                           , XF86XK_AudioPlay        , spawn         , {.v = audio_play         }},
	{ 0                           , XF86XK_AudioStop        , spawn         , {.v = audio_stop         }},
	{ 0                           , XF86XK_AudioPrev        , spawn         , {.v = audio_prev         }},
	{ 0                           , XF86XK_AudioNext        , spawn         , {.v = audio_next         }},
	{ 0                           , XF86XK_MonBrightnessUp  , spawn         , {.v = mon_brightness_up  }},
	{ 0                           , XF86XK_MonBrightnessDown, spawn         , {.v = mon_brightness_down}},
	{ 0                           , XF86XK_KbdBrightnessUp  , spawn         , {.v = kbd_brightness_up  }},
	{ 0                           , XF86XK_KbdBrightnessDown, spawn         , {.v = kbd_brightness_down}},
	{ 0                           , XF86LaunchA             , spawn         , {.v = launch_a }  }        ,
	{ 0                           , XF86LaunchB             , spawn         , {.v = launch_b }  }        ,
	{ MODKEY                      , XK_b                    , togglebar     , {0} }                      ,
	{ MODKEY                      , XK_j                    , focusstack    , {.i = +1 } }               ,
	{ MODKEY                      , XK_k                    , focusstack    , {.i = -1 } }               ,
	{ MODKEY                      , XK_i                    , incnmaster    , {.i = +1 } }               ,
	{ MODKEY                      , XK_d                    , incnmaster    , {.i = -1 } }               ,
	{ MODKEY                      , XK_h                    , setmfact      , {.f = -0.05} }             ,
	{ MODKEY                      , XK_l                    , setmfact      , {.f = +0.05} }             ,
	{ MODKEY                      , XK_Return               , zoom          , {0} }                      ,
	{ MODKEY                      , XK_Tab                  , view          , {0} }                      ,
	{ MODKEY|ShiftMask            , XK_c                    , killclient    , {0} }                      ,
	{ MODKEY                      , XK_t                    , setlayout     , {.v = &layouts[0]} }       ,
	{ MODKEY                      , XK_f                    , setlayout     , {.v = &layouts[1]} }       ,
	{ MODKEY                      , XK_m                    , setlayout     , {.v = &layouts[2]} }       ,
	{ MODKEY                      , XK_space                , setlayout     , {0} }                      ,
	{ MODKEY|ShiftMask            , XK_space                , togglefloating, {0} }                      ,
	{ MODKEY                      , XK_0                    , view          , {.ui = ~0 } }              ,
	{ MODKEY|ShiftMask            , XK_0                    , tag           , {.ui = ~0 } }              ,
	{ MODKEY                      , XK_comma                , focusmon      , {.i = -1 } }               ,
	{ MODKEY                      , XK_period               , focusmon      , {.i = +1 } }               ,
	{ MODKEY|ShiftMask            , XK_comma                , tagmon        , {.i = -1 } }               ,
	{ MODKEY|ShiftMask            , XK_period               , tagmon        , {.i = +1 } }               ,
	TAGKEYS( XK_1 , 0)
	TAGKEYS( XK_2 , 1)
	TAGKEYS( XK_3 , 2)
	TAGKEYS( XK_4 , 3)
	TAGKEYS( XK_5 , 4)
	TAGKEYS( XK_6 , 5)
	TAGKEYS( XK_7 , 6)
	TAGKEYS( XK_8 , 7)
	TAGKEYS( XK_9 , 8)
	{ MODKEY|ShiftMask            , XK_q                    , quit          , {0} }                      ,
	{ MODKEY|ShiftMask|ControlMask, XK_q                    , restart       , {0} }                      ,
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

