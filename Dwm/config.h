/* |  _ \| |__ (_) | \ \      / /_ _ _   _ _ __   ___( )___ */
/* | |_) | '_ \| | |  \ \ /\ / / _` | | | | '_ \ / _ \// __| */
/* |  __/| | | | | |   \ V  V / (_| | |_| | | | |  __/ \__ \ */
/* |_|   |_| |_|_|_|    \_/\_/ \__,_|\__, |_| |_|\___| |___/ */
 /*                                  |___/ */
 /* ______        ____  __ */
/* |  _ \ \      / /  \/  | */
/* | | | \ \ /\ / /| |\/| | */
/* | |_| |\ V  V / | |  | | */
/* |____/  \_/\_/  |_|  |_| */

/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar & 1 = top bar */
static const int user_bh            = 25;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const char *fonts[]          = { "UbuntuMono Nerd Font:size=11" };
static const char dmenufont[]       = "UbuntuMono Nerd Font:size=11";
// background color
static const char col_gray1[]       = "#222222";
// color of the border of the inactive window
static const char col_gray2[]       = "#444444";
// font color
static const char col_gray3[]       = "#bbbbbb";
// current tag and current window font color
static const char col_gray4[]       = "#eeeeee";
// bottom bar second color (blue) and active window border color
static const char col_cyan[]        = "#d60909";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
	[SchemeStatus]  = { col_gray3, col_gray1,  "#031f4d"  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsSel]  = { col_gray4, col_cyan,  "#000000"  }, // Tagbar left selected {text,background,not used but cannot be empty}
    [SchemeTagsNorm]  = { col_gray3, col_gray1,  "#000000"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
    [SchemeInfoSel]  = { col_gray4, col_cyan,  "#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
    [SchemeInfoNorm]  = { col_gray3, col_gray1,  "#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};

/* tagging */

/* numbered tags */
/* static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" }; */

/* Tags with fontawesome icons (do not forget installing font awesome) */
static const char *tags[] = { " ", " ", " ", " ", " ", " ", " ", " ", " "  };

/* My old qtile tags */
/* static const char *tags[] = {"Term", "Web", "Mail", "Media", "Extra"}; */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Firefox",  NULL,       NULL,       2		,       0,           -1 },
	{ "Gimp",     NULL,       NULL,       4,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
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
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *browsercmd[]  = { "brave-bin", NULL };
static const char *mailcmd[]  = { "thunderbird-bin", NULL };
static const char *lockscreen[] = { "i3lock", NULL };
static const char *screenshot[] = { "scrot", NULL };
static const char *libreoffice[] = { "libreoffice", NULL };
static const char *sound[] = { "pavucontrol", NULL };
static const char *anki[] = { "anki", NULL };
static const char *zeal[] = { "zeal", NULL };

/* other apps Id like to bind to a key */
/* + obs */
/* + kdenlive */

#include "movestack.c"
#include <X11/XF86keysym.h> //lets you use the dedicated brightness keys on your laptop

static Key keys[] = {
	/* MODIFIER                     KEY        FUNCTION        ARGUMENT */

	/* dmenu and term */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,             			XK_Return, spawn,          {.v = termcmd } },

	/* something */
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },

	{ MODKEY|ControlMask,          	XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,             			XK_w,      killclient,     {0} },

	/* modkey + shift + letter */
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_u,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,             XK_o,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

	/* modkey + shit/control + space */
	{ MODKEY|ControlMask,           XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },

	/* CUSTOM BINDINGS */
	{ MODKEY,             			XK_b, 		spawn,         {.v = browsercmd} },
	{ MODKEY,             			XK_t, 		spawn,         {.v = mailcmd} },
	{ MODKEY,             			XK_o, 		spawn,         {.v = libreoffice} },
	{ MODKEY,             			XK_a, 		spawn,         {.v = anki} },
	{ MODKEY,             			XK_s, 		spawn,         {.v = sound} },
	{ MODKEY,             			XK_z, 		spawn,         {.v = zeal} },
	{ MODKEY|ShiftMask,             XK_space, 	spawn,         {.v = lockscreen} },
	{ MODKEY|ShiftMask,             XK_s, 		spawn,         {.v = screenshot} },
	{ MODKEY,             			XK_p, 		spawn,         SHCMD("st -e mocp -T /usr/share/moc/themes/yellow_red_theme") },
	{ MODKEY,             			XK_v, 		spawn,         SHCMD("st -e vifm") },
	{ MODKEY,             			XK_n, 		spawn,         SHCMD("st -e newsboat -r") },
	{ MODKEY,             			XK_c, 		spawn,         SHCMD("st -e calcurse") },
	{ MODKEY,             			XK_g, 		spawn,         SHCMD("/home/philwayne/Dotfiles/.local/scripts/game_launcher.sh") },
	{ MODKEY,             			XK_u, 		spawn,         SHCMD("/home/philwayne/Dotfiles/.local/scripts/device-manager.sh") },

	/* Exit dwm */
	{ MODKEY|ControlMask,             XK_q,      quit,           {0} },

	/* Manage sound with alsa and brightness with xbacklight */
	{ 0, XF86XK_MonBrightnessUp,	spawn,		SHCMD("xbacklight -inc 15") },
	{ 0, XF86XK_MonBrightnessDown,	spawn,		SHCMD("xbacklight -dec 15") },
	{ 0, XF86XK_AudioMute,			spawn,		SHCMD("amixer sset Master toggle") },
	{ 0, XF86XK_AudioRaiseVolume,	spawn,		SHCMD("amixer sset Master 10%+") },
	{ 0, XF86XK_AudioLowerVolume,	spawn,		SHCMD("amixer sset Master 10%-") },

	/* END CUSTOM BINDINGS */

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
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
