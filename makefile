# ----------------------------
# Makefile Options
# ----------------------------

NAME = MOMENTUM
ICON = icon.png
DESCRIPTION = "default example for momentum TI84+ CE game dev library"
COMPRESSED = NO

CFLAGS = -Wall -Wextra -Oz -O3
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
