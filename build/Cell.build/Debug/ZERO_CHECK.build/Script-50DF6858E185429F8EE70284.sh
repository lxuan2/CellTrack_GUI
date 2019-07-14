#!/bin/sh
make -C /Users/xuanli/Desktop/cell/build -f /Users/xuanli/Desktop/cell/build/CMakeScripts/ZERO_CHECK_cmakeRulesBuildPhase.make$CONFIGURATION OBJDIR=$(basename "$OBJECT_FILE_DIR_normal") all
