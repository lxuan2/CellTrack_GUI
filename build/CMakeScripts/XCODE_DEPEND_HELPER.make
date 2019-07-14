# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.cell.Debug:
/Users/xuanli/Desktop/cell/build/Debug/cell:\
	/Applications/Qt/5.13.0/clang_64/lib/QtMultimediaWidgets.framework/QtMultimediaWidgets\
	/Applications/Qt/5.13.0/clang_64/lib/QtWidgets.framework/QtWidgets\
	/Applications/Qt/5.13.0/clang_64/lib/QtMultimedia.framework/QtMultimedia\
	/Applications/Qt/5.13.0/clang_64/lib/QtGui.framework/QtGui\
	/Applications/Qt/5.13.0/clang_64/lib/QtNetwork.framework/QtNetwork\
	/Applications/Qt/5.13.0/clang_64/lib/QtCore.framework/QtCore
	/bin/rm -f /Users/xuanli/Desktop/cell/build/Debug/cell


PostBuild.cell.Release:
/Users/xuanli/Desktop/cell/build/Release/cell:\
	/Applications/Qt/5.13.0/clang_64/lib/QtMultimediaWidgets.framework/QtMultimediaWidgets\
	/Applications/Qt/5.13.0/clang_64/lib/QtWidgets.framework/QtWidgets\
	/Applications/Qt/5.13.0/clang_64/lib/QtMultimedia.framework/QtMultimedia\
	/Applications/Qt/5.13.0/clang_64/lib/QtGui.framework/QtGui\
	/Applications/Qt/5.13.0/clang_64/lib/QtNetwork.framework/QtNetwork\
	/Applications/Qt/5.13.0/clang_64/lib/QtCore.framework/QtCore
	/bin/rm -f /Users/xuanli/Desktop/cell/build/Release/cell


PostBuild.cell.MinSizeRel:
/Users/xuanli/Desktop/cell/build/MinSizeRel/cell:\
	/Applications/Qt/5.13.0/clang_64/lib/QtMultimediaWidgets.framework/QtMultimediaWidgets\
	/Applications/Qt/5.13.0/clang_64/lib/QtWidgets.framework/QtWidgets\
	/Applications/Qt/5.13.0/clang_64/lib/QtMultimedia.framework/QtMultimedia\
	/Applications/Qt/5.13.0/clang_64/lib/QtGui.framework/QtGui\
	/Applications/Qt/5.13.0/clang_64/lib/QtNetwork.framework/QtNetwork\
	/Applications/Qt/5.13.0/clang_64/lib/QtCore.framework/QtCore
	/bin/rm -f /Users/xuanli/Desktop/cell/build/MinSizeRel/cell


PostBuild.cell.RelWithDebInfo:
/Users/xuanli/Desktop/cell/build/RelWithDebInfo/cell:\
	/Applications/Qt/5.13.0/clang_64/lib/QtMultimediaWidgets.framework/QtMultimediaWidgets\
	/Applications/Qt/5.13.0/clang_64/lib/QtWidgets.framework/QtWidgets\
	/Applications/Qt/5.13.0/clang_64/lib/QtMultimedia.framework/QtMultimedia\
	/Applications/Qt/5.13.0/clang_64/lib/QtGui.framework/QtGui\
	/Applications/Qt/5.13.0/clang_64/lib/QtNetwork.framework/QtNetwork\
	/Applications/Qt/5.13.0/clang_64/lib/QtCore.framework/QtCore
	/bin/rm -f /Users/xuanli/Desktop/cell/build/RelWithDebInfo/cell




# For each target create a dummy ruleso the target does not have to exist
/Applications/Qt/5.13.0/clang_64/lib/QtCore.framework/QtCore:
/Applications/Qt/5.13.0/clang_64/lib/QtGui.framework/QtGui:
/Applications/Qt/5.13.0/clang_64/lib/QtMultimedia.framework/QtMultimedia:
/Applications/Qt/5.13.0/clang_64/lib/QtMultimediaWidgets.framework/QtMultimediaWidgets:
/Applications/Qt/5.13.0/clang_64/lib/QtNetwork.framework/QtNetwork:
/Applications/Qt/5.13.0/clang_64/lib/QtWidgets.framework/QtWidgets:
