/* See LICENSE file for copyright and license details. */
/* appearance */
static const unsigned int borderpx = 2;   /* border pixel of windows */
static const unsigned int snap     = 32;  /* snap pixel */
static const unsigned int gappx    = 6;   /* pixel gap between clients */
static const int showbar           = 1;   /* 0 means no bar */
static const int topbar            = 0;   /* 0 means bottom bar */
static const int horizpadbar       = 7;   /* horizontal padding for statusbar */
static const int vertpadbar        = 7;   /* vertical padding for statusbar */
static const char *fonts[]     = {"JetBrainsMono-Regular.ttf:size=11:antialias=true:autohint=true",
                                  "Hack:size=11:antialias=true:autohint=true",
                                  "JoyPixels:size=11:antialias=true:autohint=true"
						     	};
static const char col_1[]  = "#1e1f29"; /* background color of bar */
static const char col_2[]  = "#282c34"; /* border color unfocused windows */
static const char col_3[]  = "#ffffff";
static const char col_4[]  = "#9755b3"; /* border color focused windows and tags */
/* bar opacity 
 * 0xff is no transparency.
 * 0xee adds wee bit of transparency.
 * Play with the value to get desired transparency.
 */
static const unsigned int baralpha    = 0xee; 
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]        = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_3, col_1, col_2 },
	[SchemeSel]  = { col_3, col_4,  col_4 },
};
static const unsigned int alphas[][3] = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
/* static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" }; */
static const char *tags[] = { "WEB", "SYS", "MUS", "MOV", "FILE", "TXT", "7", "8", "9" };


static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#include "layouts.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "HHH",      grid },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define CMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* KEYBIND DEFINITIONS */

static char dmenumon[2] = "0";
static const char *dmenucmd[]   = { "dmenu_run", "-c", "-bw", "2", "-l", "20", "-g", "4", "-p", "Run: ", NULL };
static const char *termcmd[]    = { "st", NULL };
static const char *quitcmd[]	= { "kill", "dwm", NULL};
static const char *discordcmd[]	= { "discord", NULL};
static const char *filecmd[]    = { "nautilus", NULL };
static const char *bravecmd[]	= { "brave-beta", NULL };
static const char *spotcmd[]    = { "spotify", NULL };
static const char *pamaccmd[]   = { "pamac-manager", NULL};
static const char *updatecmd[]	= { "st", "-e", "yay", "-Syyu", NULL};
static const char *startcmd[]   = { "st", "-e", "./.local/bin/startup.sh", NULL };
static const char *confcmd[]    = { "st", "-e", "nvim /home/sean/.config/dwm/config.h", NULL};
static const char *volup[]	= { "amixer set Master 7%+", NULL};
static const char *voldo[]	= { "amixer set Master 7%-", NULL};
static const char *briup[]	= { "xbacklight +10", NULL};
static const char *brido[]	= { "xbacklight -10", NULL};

/*ImpPPpi */

/* KEYBIND MAPPINGS */

static Key keys[] = {
	/* modifier             key        function        argument */
	{ MODKEY,		XK_d, 	   spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,	XK_e,	   spawn,	   {.v = quitcmd} },
	{ MODKEY|ShiftMask,	XK_d,	   spawn,	   {.v = discordcmd} },
	{ MODKEY|ShiftMask,     XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,	XK_s,	   spawn,	   {.v = spotcmd } },
	{ MODKEY|ShiftMask,	XK_b,	   spawn, 	   {.v = bravecmd } },
	{ MODKEY,		XK_e,	   spawn,	   {.v = filecmd } },
	{ MODKEY|ShiftMask,	XK_v,	   spawn, 	   {.v = confcmd } },
	{ MODKEY|ShiftMask,	XK_x,	   spawn,	   {.v = startcmd } },
	{ MODKEY|ShiftMask, 	XK_u,	   spawn, 	   {.v = updatecmd } },
	{ MODKEY,		XK_u,	   spawn,	   {.v = pamaccmd } },
	{ MODKEY,		XC_sb_up_arrow,		spawn,	   {.v = volup } },
	{ MODKEY,		XC_sb_down_arrow,	spawn,	   {.v = voldo } },
	{ MODKEY,		XC_sb_left_arrow,	spawn,	   {.v = briup } },
	{ MODKEY,		XC_sb_right_arrow,	spawn, 	   {.v = brido } },
	{ MODKEY,               XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask,     XK_j,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,     XK_k,      rotatestack,    {.i = -1 } },
	{ MODKEY,               XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,               XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,               XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,               XK_o,      incnmaster,     {.i = -1 } },
	{ MODKEY,               XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,               XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,		XK_Return, zoom,           {0} },
	{ MODKEY,               XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,     XK_q,      killclient,     {0} },

    /* Layout manipulation */
	{ MODKEY,               XK_r,    cyclelayout,    {.i = -1 } },
	{ MODKEY|ShiftMask,     XK_r,    cyclelayout,    {.i = +1 } },
	{ MODKEY,               XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,     XK_space,  togglefloating, {0} },

    /* Switch to specific layouts */
	{ MODKEY,               XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,               XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,               XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,               XK_g,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,               XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,     XK_0,      tag,            {.ui = ~0 } },

    /* Switching between monitors */
	{ MODKEY,               XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,               XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,     XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,     XK_period, tagmon,         {.i = +1 } },
	
	
    /* Dmenu scripts launched with ALT + CTRL + KEY */

	TAGKEYS(                  XK_1,          0)
	TAGKEYS(                  XK_2,          1)
	TAGKEYS(                  XK_3,          2)
	TAGKEYS(                  XK_4,          3)
	TAGKEYS(                  XK_5,          4)
	TAGKEYS(                  XK_6,          5)
	TAGKEYS(                  XK_7,          6)
	TAGKEYS(                  XK_8,          7)
	TAGKEYS(                  XK_9,          8)
};
/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click           event mask   button          function        argument */
	{ ClkLtSymbol,     0,           Button1,        setlayout,      {0} },
	{ ClkLtSymbol,     0,           Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,     0,           Button2,        zoom,           {0} },
	{ ClkStatusText,   0,           Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,    MODKEY,      Button1,        movemouse,      {0} },
	{ ClkClientWin,    MODKEY,      Button2,        togglefloating, {0} },
	{ ClkClientWin,    MODKEY,      Button3,        resizemouse,    {0} },
	{ ClkTagBar,       0,           Button1,        view,           {0} },
	{ ClkTagBar,       0,           Button3,        toggleview,     {0} },
	{ ClkTagBar,       MODKEY,      Button1,        tag,            {0} },
	{ ClkTagBar,       MODKEY,      Button3,        toggletag,      {0} },
};


