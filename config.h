/** modifiers **/
#define MOD             Mod1Mask    /* ALT key */
#define SHIFT           ShiftMask   /* Shift key */

/** generic settings **/
#define MASTER_SIZE     0.52
#define SHOW_PANEL      False
#define TOP_PANEL       False
#define PANEL_HEIGHT    10
#define DEFAULT_MODE    TILE      /* initial layout/mode: TILE BSTACK FLOAT */
#define ATTACH_ASIDE    False     /* False means new window is master */
#define FOLLOW_WINDOW   True      /* follow the window when moved to a different desktop */
#define FOLLOW_MOUSE    True      /* focus the window the mouse just entered */
#define CLICK_TO_FOCUS  True      /* focus an unfocused window when clicked  */
#define FOCUS_BUTTON    Button3   /* mouse button to be used along with CLICK_TO_FOCUS */
#define BORDER_WIDTH    3         /* window border width */
#define FOCUS           "#bdae93" /* focused window border color    */
#define UNFOCUS         "#504945" /* unfocused window border color  */
#define MINWSZ          50        /* minimum window size in pixels  */
#define DEFAULT_DESKTOP 0         /* the desktop to focus initially */
#define DESKTOPS        4         /* number of desktops - edit DESKTOPCHANGE keys to suit */

/**
 * open applications to specified desktop with specified mode.
 * if desktop is negative, then current is assumed
 */
static const AppRule rules[] = { \
    /*  class      desktop  follow  float */
	 { "Firefox",   0,       True,   True  },
	 { "StatusBar", 0,       True,   True },
};

/* helper for spawning shell commands */
#define SHCMD(cmd)     {.com = (const char*[]){"/bin/sh", "-c", cmd, NULL}}
#define CMD(cmd)       {.com = (const char*[]){cmd, NULL}}
#define SOUNDCMD(cmd)  {.com = (const char*[]){"amixer", "set", "Master", cmd, NULL}}
#define BRIGHTCMD(cmd) {.com = (const char*[]){"xsct", "3000", cmd, NULL}}

#define DESKTOPCHANGE(K,N) \
    {  MOD,             K,             change_desktop,    {.i = N}}, \
    {  MOD|ShiftMask,   K,             client_to_desktop, {.i = N}},

/* keyboard shortcuts */
static Key keys[] = {
    /* modifier         key            function           argument */
	 {  MOD,           XK_i,          spawn,             CMD("/home/lang/.status")},
    {  MOD,           XK_t,          spawn,             CMD("st")},
    {  MOD,           XK_r,          spawn,             CMD("dmenu_run")},

	 {  0,             XK_F2,         spawn,             SOUNDCMD("5%-")},
	 {  0,             XK_F3,         spawn,             SOUNDCMD("5%+")},
	 {  0,             XK_F4,         spawn,             SOUNDCMD("0%")},
	 {  0,             XK_F5,         spawn,             BRIGHTCMD("0.0")},
	 {  0,             XK_F6,         spawn,             BRIGHTCMD("0.3")},
	 {  0,             XK_F7,         spawn,             BRIGHTCMD("0.6")},
	 {  0,             XK_F8,         spawn,             BRIGHTCMD("1.0")},

	 {  MOD,           XK_x,          rotate_filled,     {NULL}},
    {  MOD,           XK_w,          killclient,        {NULL}},
	 {  MOD,           XK_c,          centerwindow,      {NULL}},
    {  MOD,           XK_f,          next_win,          {NULL}},
    {  MOD,           XK_a,          prev_win,          {NULL}},
    {  MOD,           XK_s,          resize_master,     {.i = -10}}, /* decrease size in px */
    {  MOD,           XK_d,          resize_master,     {.i = +10}}, /* increase size in px */
    {  MOD,           XK_e,          swap_master,       {NULL}},
    {  MOD|SHIFT,     XK_b,          switch_mode,       {.i = BSTACK}},
    {  MOD|SHIFT,     XK_f,          switch_mode,       {.i = FLOAT}},
	 {  MOD,           XK_p,          focusurgent,       {NULL}},
    {  MOD|SHIFT,     XK_q,          quit,              {.i = 0}}, /* quit with exit value 0 */
    {  MOD,           XK_j,          moveresize,        {.v = (int []){   0,  25,   0,   0 }}}, /* move down  */
    {  MOD,           XK_k,          moveresize,        {.v = (int []){   0, -25,   0,   0 }}}, /* move up    */
    {  MOD,           XK_l,          moveresize,        {.v = (int []){  25,   0,   0,   0 }}}, /* move right */
    {  MOD,           XK_h,          moveresize,        {.v = (int []){ -25,   0,   0,   0 }}}, /* move left  */
    {  MOD|SHIFT,     XK_j,          moveresize,        {.v = (int []){   0,   0,   0,  25 }}}, /* height grow   */
    {  MOD|SHIFT,     XK_k,          moveresize,        {.v = (int []){   0,   0,   0, -25 }}}, /* height shrink */
    {  MOD|SHIFT,     XK_l,          moveresize,        {.v = (int []){   0,   0,  25,   0 }}}, /* width grow    */
    {  MOD|SHIFT,     XK_h,          moveresize,        {.v = (int []){   0,   0, -25,   0 }}}, /* width shrink  */
       DESKTOPCHANGE( XK_1,                              0)
       DESKTOPCHANGE( XK_2,                              1)
       DESKTOPCHANGE( XK_3,                              2)
       DESKTOPCHANGE( XK_4,                              3)
};

/* mouse shortcuts */
static Button buttons[] = {
    {  MOD,             Button1,       mousemotion,       {.i = MOVE}},
    {  MOD,             Button3,       mousemotion,       {.i = RESIZE}},
};
