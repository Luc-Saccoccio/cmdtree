/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

enum position {
	POSITION_TOP,
	POSITION_LEFT,
	POSITION_RIGHT,
	POSITION_BOTTOM
};

static int xpad = 6;
static int ypad = 0;

static enum position position = POSITION_TOP;


static const char *separator = " → ";

/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"monospace:size=11"
};

static struct scheme schemes[SchemeLast] = {
	[SchemeNorm]  = { .bg = "#222222",
			  .bind = "#ffc978",
			  .arrow = "#888",
			  .prefix = "",
			  .name = "#bbbbbb"
	                },

	[SchemePrefix] = { .bg = "#222222",
			   .bind = "#eeeeee",
			   .arrow = "#888",
			   .prefix = "",
			   .name = "#c678dd"
	                 },
};

static struct command email_commands[] = {
	DEFCMD("c", "count", "unread")
	DEFCMD("f", "fetch", "mailsync")
};

static struct command launchers_commands[] = {
	DEFCMD("c", "calc", "rofi -show calc -modi calc -no-show-match -no-sort -lines 2")
	DEFCMD("n", "networkmanager", "networkmanager_dmenu")
	DEFCMD("r", "rofi", "rofi -show drun -columns 2 -show-icons")
	DEFCMD("t", "theme", "rofi-theme-selector")
};

static struct command music_commands[] = {
	DEFCMD("c", "cover", "mpd_cover")
	DEFCMD("n", "next", "mpc next")
	DEFCMD("p", "previous", "mpc prev")
	DEFCMD("s", "stop", "mpc stop")
	DEFCMD("t", "play/pause", "mpc toggle")
};

static struct command notify_commands[] = {
	DEFCMD("c", "close all", "dunstctl close-all")
	DEFCMD("C", "close last", "dunstctl close")
	DEFCMD("n", "open last", "dunstctl history-pop")
	DEFCMD("N", "open last 5", "dunstctl history-pop;dunstctl history-pop;dunstctl history-pop;dunstctl history-pop;dunstctl history-pop")
};

static struct command term_commands[] = {
	DEFCMD("a", "alacritty", "alacritty")
	DEFCMD("d", "draw", "draw_term")
	DEFCMD("f", "floating", "st -c floating")
	DEFCMD("s", "st", "st")
};

static struct command wal_commands[] = {
	DEFCMD("d", "dmenu", "walc -d")
	DEFCMD("l", "live", "livewalc")
	DEFCMD("n", "nsxiv", "walc -s")
	DEFCMD("r", "random", "random-wall")
};

static struct command commands[] = {
	DEFPREFIX("e", "email", email_commands)
	DEFPREFIX("l", "launchers", launchers_commands)
	DEFPREFIX("m", "music", music_commands)
	DEFPREFIX("n", "notifications", notify_commands)
	DEFPREFIX("t", "terminals", term_commands)
	DEFPREFIX("w", "wallpaper", wal_commands)
	DEFCMD("b", "boomer", "boomer &>/dev/null")
	DEFCMD("c", "colorpicker", "n colorpicker -od")
	DEFCMD("r", "ruler", "n xmeasure)")
	DEFCMD("z", "lock", "lock")
};
