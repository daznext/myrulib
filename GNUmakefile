# =========================================================================
#     This makefile was generated by
#     Bakefile 0.2.6 (http://www.bakefile.org)
#     Do not modify, all changes will be overwritten!
# =========================================================================



# -------------------------------------------------------------------------
# These are configurable options:
# -------------------------------------------------------------------------

#  
AR ?= ar

#  
RANLIB ?= ranlib

# C compiler 
CC = gcc

# C++ compiler 
CXX = `$(WX_CONFIG) --cxx`

# Standard flags for CC 
CFLAGS ?= 

# Standard flags for C++ 
CXXFLAGS ?= 

# Standard preprocessor flags (common for CC and CXX) 
CPPFLAGS ?= 

# Standard linker flags 
LDFLAGS ?= 

# Location and arguments of wx-config script 
WX_CONFIG ?= wx-config

# Port of the wx library to build against [gtk1,gtk2,msw,x11,motif,mgl,mac,dfb]
WX_PORT ?= gtk2

# Use DLL build of wx library to use? [0,1]
WX_SHARED ?= 0

# Compile Unicode build of wxWidgets? [0,1]
WX_UNICODE ?= 1

# Use debug build of wxWidgets (define __WXDEBUG__)? [0,1]
WX_DEBUG ?= 0

# Version of the wx library to build against. 
WX_VERSION ?= 2.8



# -------------------------------------------------------------------------
# Do not modify the rest of this file!
# -------------------------------------------------------------------------

### Variables: ###

CPPDEPS = -MT$@ -MF`echo $@ | sed -e 's,\.o$$,.d,'` -MD -MP
WX_VERSION_MAJOR = $(shell echo $(WX_VERSION) | cut -c1,1)
WX_VERSION_MINOR = $(shell echo $(WX_VERSION) | cut -c2,2)
WX_CONFIG_FLAGS = $(WX_CONFIG_DEBUG_FLAG) $(WX_CONFIG_UNICODE_FLAG) \
	$(WX_CONFIG_SHARED_FLAG) --toolkit=$(WX_PORT) \
	--version=$(WX_VERSION_MAJOR).$(WX_VERSION_MINOR)
EXPAT_STATIC_CFLAGS = -DHAVE_EXPAT_CONFIG_H -IExpat `$(WX_CONFIG) --cflags \
	$(WX_CONFIG_FLAGS)` $(CPPFLAGS) $(CFLAGS)
EXPAT_STATIC_OBJECTS =  \
	build/expat_static_xmlparse.o \
	build/expat_static_xmlrole.o \
	build/expat_static_xmltok.o \
	build/expat_static_xmltok_impl.o \
	build/expat_static_xmltok_ns.o
SQLITE3_STATIC_CFLAGS = `$(WX_CONFIG) --cflags $(WX_CONFIG_FLAGS)` $(CPPFLAGS) \
	$(CFLAGS)
SQLITE3_STATIC_OBJECTS =  \
	build/sqlite3_static_sqlite3.o
WXSQLITE3_STATIC_CXXFLAGS = -ISQLite3 -IWxSQLite3 -IWxSQLite3 `$(WX_CONFIG) \
	--cxxflags $(WX_CONFIG_FLAGS)` $(CPPFLAGS) $(CXXFLAGS)
WXSQLITE3_STATIC_OBJECTS =  \
	build/wxsqlite3_static_wxsqlite3.o
MYRULIB_CFLAGS = -DDONT_USE_DATABASE_LAYER_EXCEPTIONS -DXML_STATIC -IWxSQLite3 \
	-IExpat -ISQLite3 -O2 `$(WX_CONFIG) --cflags $(WX_CONFIG_FLAGS)` $(CPPFLAGS) \
	$(CFLAGS)
MYRULIB_CXXFLAGS = -DDONT_USE_DATABASE_LAYER_EXCEPTIONS -DXML_STATIC \
	-IWxSQLite3 -IExpat -ISQLite3 -O2 `$(WX_CONFIG) --cxxflags $(WX_CONFIG_FLAGS)` \
	$(CPPFLAGS) $(CXXFLAGS)
MYRULIB_OBJECTS =  \
	build/myrulib_BaseThread.o \
	build/myrulib_BookExtractInfo.o \
	build/myrulib_BookListCtrl.o \
	build/myrulib_BooksPanel.o \
	build/myrulib_ExpThread.o \
	build/myrulib_ExternalDlg.o \
	build/myrulib_FbAuthorList.o \
	build/myrulib_FbConst.o \
	build/myrulib_FbDatabase.o \
	build/myrulib_FbFrameAuthor.o \
	build/myrulib_FbFrameBase.o \
	build/myrulib_FbFrameSearch.o \
	build/myrulib_FbFrameFavorites.o \
	build/myrulib_FbGenres.o \
	build/myrulib_FbLogStream.o \
	build/myrulib_FbManager.o \
	build/myrulib_FbParams.o \
	build/myrulib_ImpContext.o \
	build/myrulib_ImpThread.o \
	build/myrulib_InfoCash.o \
	build/myrulib_InfoThread.o \
	build/myrulib_LimitedTextCtrl.o \
	build/myrulib_MyRuLibApp.o \
	build/myrulib_MyRuLibMain.o \
	build/myrulib_ParseCtx.o \
	build/myrulib_ProgressBar.o \
	build/myrulib_SettingsDlg.o \
	build/myrulib_TitleThread.o \
	build/myrulib_VacuumThread.o \
	build/myrulib_ZipReader.o \
	build/myrulib_sha1.o \
	build/myrulib_base64.o \
	build/myrulib_treelistctrl.o

### Conditionally set variables: ###

ifeq ($(WX_DEBUG),0)
WX_CONFIG_DEBUG_FLAG = --debug=no
endif
ifeq ($(WX_DEBUG),1)
WX_CONFIG_DEBUG_FLAG = --debug=yes
endif
ifeq ($(WX_UNICODE),0)
WX_CONFIG_UNICODE_FLAG = --unicode=no
endif
ifeq ($(WX_UNICODE),1)
WX_CONFIG_UNICODE_FLAG = --unicode=yes
endif
ifeq ($(WX_SHARED),0)
WX_CONFIG_SHARED_FLAG = --static=yes
endif
ifeq ($(WX_SHARED),1)
WX_CONFIG_SHARED_FLAG = --static=no
endif


all: build
build:
	@mkdir -p build

### Targets: ###

all: test_for_selected_wxbuild build/libexpat_static.a build/libsqlite3_static.a build/libwxsqlite3_static.a build/myrulib

install: 

uninstall: 

clean: 
	rm -f build/*.o
	rm -f build/*.d
	rm -f build/libexpat_static.a
	rm -f build/libsqlite3_static.a
	rm -f build/libwxsqlite3_static.a
	rm -f build/myrulib

test_for_selected_wxbuild: 
	@$(WX_CONFIG) $(WX_CONFIG_FLAGS)

build/libexpat_static.a: $(EXPAT_STATIC_OBJECTS)
	rm -f $@
	$(AR) rcu $@ $(EXPAT_STATIC_OBJECTS)
	$(RANLIB) $@

build/libsqlite3_static.a: $(SQLITE3_STATIC_OBJECTS)
	rm -f $@
	$(AR) rcu $@ $(SQLITE3_STATIC_OBJECTS)
	$(RANLIB) $@

build/libwxsqlite3_static.a: $(WXSQLITE3_STATIC_OBJECTS)
	rm -f $@
	$(AR) rcu $@ $(WXSQLITE3_STATIC_OBJECTS)
	$(RANLIB) $@

build/myrulib: $(MYRULIB_OBJECTS) build/libwxsqlite3_static.a build/libexpat_static.a build/libsqlite3_static.a
	$(CXX) -o $@ $(MYRULIB_OBJECTS)     $(LDFLAGS)  build/libwxsqlite3_static.a build/libexpat_static.a build/libsqlite3_static.a `$(WX_CONFIG) $(WX_CONFIG_FLAGS) --libs aui,xrc,html,core,base`
	strip ./build/myrulib

build/expat_static_xmlparse.o: ./Expat/xmlparse.c
	$(CC) -c -o $@ $(EXPAT_STATIC_CFLAGS) $(CPPDEPS) $<

build/expat_static_xmlrole.o: ./Expat/xmlrole.c
	$(CC) -c -o $@ $(EXPAT_STATIC_CFLAGS) $(CPPDEPS) $<

build/expat_static_xmltok.o: ./Expat/xmltok.c
	$(CC) -c -o $@ $(EXPAT_STATIC_CFLAGS) $(CPPDEPS) $<

build/expat_static_xmltok_impl.o: ./Expat/xmltok_impl.c
	$(CC) -c -o $@ $(EXPAT_STATIC_CFLAGS) $(CPPDEPS) $<

build/expat_static_xmltok_ns.o: ./Expat/xmltok_ns.c
	$(CC) -c -o $@ $(EXPAT_STATIC_CFLAGS) $(CPPDEPS) $<

build/sqlite3_static_sqlite3.o: ./SQLite3/sqlite3.c
	$(CC) -c -o $@ $(SQLITE3_STATIC_CFLAGS) $(CPPDEPS) $<

build/wxsqlite3_static_wxsqlite3.o: ./WxSQLite3/wxsqlite3.cpp
	$(CXX) -c -o $@ $(WXSQLITE3_STATIC_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_BaseThread.o: ./MyRuLib/BaseThread.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_BookExtractInfo.o: ./MyRuLib/BookExtractInfo.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_BookListCtrl.o: ./MyRuLib/BookListCtrl.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_BooksPanel.o: ./MyRuLib/BooksPanel.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_ExpThread.o: ./MyRuLib/ExpThread.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_ExternalDlg.o: ./MyRuLib/ExternalDlg.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_FbAuthorList.o: ./MyRuLib/FbAuthorList.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_FbConst.o: ./MyRuLib/FbConst.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_FbDatabase.o: ./MyRuLib/FbDatabase.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_FbFrameAuthor.o: ./MyRuLib/FbFrameAuthor.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_FbFrameBase.o: ./MyRuLib/FbFrameBase.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_FbFrameSearch.o: ./MyRuLib/FbFrameSearch.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_FbFrameFavorites.o: ./MyRuLib/FbFrameFavorites.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_FbGenres.o: ./MyRuLib/FbGenres.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_FbLogStream.o: ./MyRuLib/FbLogStream.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_FbManager.o: ./MyRuLib/FbManager.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_FbParams.o: ./MyRuLib/FbParams.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_ImpContext.o: ./MyRuLib/ImpContext.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_ImpThread.o: ./MyRuLib/ImpThread.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_InfoCash.o: ./MyRuLib/InfoCash.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_InfoThread.o: ./MyRuLib/InfoThread.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_LimitedTextCtrl.o: ./MyRuLib/LimitedTextCtrl.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_MyRuLibApp.o: ./MyRuLib/MyRuLibApp.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_MyRuLibMain.o: ./MyRuLib/MyRuLibMain.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_ParseCtx.o: ./MyRuLib/ParseCtx.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_ProgressBar.o: ./MyRuLib/ProgressBar.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_SettingsDlg.o: ./MyRuLib/SettingsDlg.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_TitleThread.o: ./MyRuLib/TitleThread.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_VacuumThread.o: ./MyRuLib/VacuumThread.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_ZipReader.o: ./MyRuLib/ZipReader.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_sha1.o: ./MyRuLib/sha1/sha1.c
	$(CC) -c -o $@ $(MYRULIB_CFLAGS) $(CPPDEPS) $<

build/myrulib_base64.o: ./MyRuLib/wx/base64.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/myrulib_treelistctrl.o: ./MyRuLib/wx/treelistctrl.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

.PHONY: all install uninstall clean


# Dependencies tracking:
-include build/*.d
