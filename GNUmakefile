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
WX_PORT ?= 

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
SQLITE_CFLAGS = `$(WX_CONFIG) --cflags $(WX_CONFIG_FLAGS)` $(CPPFLAGS) $(CFLAGS)
SQLITE_OBJECTS =  \
	build/SQLite_sqlite3.o
EXPAT_CFLAGS = -DHAVE_EXPAT_CONFIG_H -IExpat `$(WX_CONFIG) --cflags \
	$(WX_CONFIG_FLAGS)` $(CPPFLAGS) $(CFLAGS)
EXPAT_OBJECTS =  \
	build/Expat_xmlparse.o \
	build/Expat_xmlrole.o \
	build/Expat_xmltok.o \
	build/Expat_xmltok_impl.o \
	build/Expat_xmltok_ns.o
DATABASELAYER_CXXFLAGS = -ISQLite `$(WX_CONFIG) --cxxflags $(WX_CONFIG_FLAGS)` \
	$(CPPFLAGS) $(CXXFLAGS)
DATABASELAYER_OBJECTS =  \
	build/DatabaseLayer_DatabaseErrorReporter.o \
	build/DatabaseLayer_DatabaseLayer.o \
	build/DatabaseLayer_DatabaseQueryParser.o \
	build/DatabaseLayer_DatabaseResultSet.o \
	build/DatabaseLayer_DatabaseStringConverter.o \
	build/DatabaseLayer_PreparedStatement.o \
	build/DatabaseLayer_SqliteDatabaseLayer.o \
	build/DatabaseLayer_SqlitePreparedStatement.o \
	build/DatabaseLayer_SqliteResultSet.o \
	build/DatabaseLayer_SqliteResultSetMetaData.o
MYRULIB_CFLAGS = -O2 -IExpat -IDatabaseLayer -ISQLite `$(WX_CONFIG) --cflags \
	$(WX_CONFIG_FLAGS)` $(CPPFLAGS) $(CFLAGS)
MYRULIB_CXXFLAGS = -O2 -IExpat -IDatabaseLayer -ISQLite `$(WX_CONFIG) --cxxflags \
	$(WX_CONFIG_FLAGS)` $(CPPFLAGS) $(CXXFLAGS)
MYRULIB_OBJECTS =  \
	build/MyRuLib_BaseThread.o \
	build/MyRuLib_BookListCtrl.o \
	build/MyRuLib_DBCreator.o \
	build/MyRuLib_ExpThread.o \
	build/MyRuLib_ExternalDlg.o \
	build/MyRuLib_FbGenres.o \
	build/MyRuLib_FbManager.o \
	build/MyRuLib_FbParams.o \
	build/MyRuLib_ImpContext.o \
	build/MyRuLib_ImpThread.o \
	build/MyRuLib_InfoCash.o \
	build/MyRuLib_InfoThread.o \
	build/MyRuLib_MyRuLibApp.o \
	build/MyRuLib_MyRuLibMain.o \
	build/MyRuLib_ParseCtx.o \
	build/MyRuLib_ProgressBar.o \
	build/MyRuLib_SettingsDlg.o \
	build/MyRuLib_TitleThread.o \
	build/MyRuLib_ZipReader.o \
	build/MyRuLib_Archives.o \
	build/MyRuLib_Authors.o \
	build/MyRuLib_Books.o \
	build/MyRuLib_Bookseq.o \
	build/MyRuLib_Params.o \
	build/MyRuLib_Sequences.o \
	build/MyRuLib_wxActiveRecord.o \
	build/MyRuLib_ZipBooks.o \
	build/MyRuLib_ZipFiles.o \
	build/MyRuLib_sha1.o \
	build/MyRuLib_base64.o \
	build/MyRuLib_treelistctrl.o

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

all: test_for_selected_wxbuild build/libSQLite.a build/libExpat.a build/libDatabaseLayer.a build/MyRuLib

install: 

uninstall: 

clean: 
	rm -f build/*.o
	rm -f build/*.d
	rm -f build/libSQLite.a
	rm -f build/libExpat.a
	rm -f build/libDatabaseLayer.a
	rm -f build/MyRuLib

test_for_selected_wxbuild: 
	@$(WX_CONFIG) $(WX_CONFIG_FLAGS)

build/libSQLite.a: $(SQLITE_OBJECTS)
	rm -f $@
	$(AR) rcu $@ $(SQLITE_OBJECTS)
	$(RANLIB) $@

build/libExpat.a: $(EXPAT_OBJECTS)
	rm -f $@
	$(AR) rcu $@ $(EXPAT_OBJECTS)
	$(RANLIB) $@

build/libDatabaseLayer.a: $(DATABASELAYER_OBJECTS)
	rm -f $@
	$(AR) rcu $@ $(DATABASELAYER_OBJECTS)
	$(RANLIB) $@

build/MyRuLib: $(MYRULIB_OBJECTS) build/libExpat.a build/libDatabaseLayer.a build/libSQLite.a
	$(CXX) -o $@ $(MYRULIB_OBJECTS)   $(LDFLAGS)  build/libExpat.a build/libDatabaseLayer.a build/libSQLite.a `$(WX_CONFIG) $(WX_CONFIG_FLAGS) --libs aui,xrc,html,core,base`

build/SQLite_sqlite3.o: ./SQLite/sqlite3.c
	$(CC) -c -o $@ $(SQLITE_CFLAGS) $(CPPDEPS) $<

build/Expat_xmlparse.o: ./Expat/xmlparse.c
	$(CC) -c -o $@ $(EXPAT_CFLAGS) $(CPPDEPS) $<

build/Expat_xmlrole.o: ./Expat/xmlrole.c
	$(CC) -c -o $@ $(EXPAT_CFLAGS) $(CPPDEPS) $<

build/Expat_xmltok.o: ./Expat/xmltok.c
	$(CC) -c -o $@ $(EXPAT_CFLAGS) $(CPPDEPS) $<

build/Expat_xmltok_impl.o: ./Expat/xmltok_impl.c
	$(CC) -c -o $@ $(EXPAT_CFLAGS) $(CPPDEPS) $<

build/Expat_xmltok_ns.o: ./Expat/xmltok_ns.c
	$(CC) -c -o $@ $(EXPAT_CFLAGS) $(CPPDEPS) $<

build/DatabaseLayer_DatabaseErrorReporter.o: ./DatabaseLayer/DatabaseErrorReporter.cpp
	$(CXX) -c -o $@ $(DATABASELAYER_CXXFLAGS) $(CPPDEPS) $<

build/DatabaseLayer_DatabaseLayer.o: ./DatabaseLayer/DatabaseLayer.cpp
	$(CXX) -c -o $@ $(DATABASELAYER_CXXFLAGS) $(CPPDEPS) $<

build/DatabaseLayer_DatabaseQueryParser.o: ./DatabaseLayer/DatabaseQueryParser.cpp
	$(CXX) -c -o $@ $(DATABASELAYER_CXXFLAGS) $(CPPDEPS) $<

build/DatabaseLayer_DatabaseResultSet.o: ./DatabaseLayer/DatabaseResultSet.cpp
	$(CXX) -c -o $@ $(DATABASELAYER_CXXFLAGS) $(CPPDEPS) $<

build/DatabaseLayer_DatabaseStringConverter.o: ./DatabaseLayer/DatabaseStringConverter.cpp
	$(CXX) -c -o $@ $(DATABASELAYER_CXXFLAGS) $(CPPDEPS) $<

build/DatabaseLayer_PreparedStatement.o: ./DatabaseLayer/PreparedStatement.cpp
	$(CXX) -c -o $@ $(DATABASELAYER_CXXFLAGS) $(CPPDEPS) $<

build/DatabaseLayer_SqliteDatabaseLayer.o: ./DatabaseLayer/SqliteDatabaseLayer.cpp
	$(CXX) -c -o $@ $(DATABASELAYER_CXXFLAGS) $(CPPDEPS) $<

build/DatabaseLayer_SqlitePreparedStatement.o: ./DatabaseLayer/SqlitePreparedStatement.cpp
	$(CXX) -c -o $@ $(DATABASELAYER_CXXFLAGS) $(CPPDEPS) $<

build/DatabaseLayer_SqliteResultSet.o: ./DatabaseLayer/SqliteResultSet.cpp
	$(CXX) -c -o $@ $(DATABASELAYER_CXXFLAGS) $(CPPDEPS) $<

build/DatabaseLayer_SqliteResultSetMetaData.o: ./DatabaseLayer/SqliteResultSetMetaData.cpp
	$(CXX) -c -o $@ $(DATABASELAYER_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_BaseThread.o: ./MyRuLib/BaseThread.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_BookListCtrl.o: ./MyRuLib/BookListCtrl.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_DBCreator.o: ./MyRuLib/DBCreator.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_ExpThread.o: ./MyRuLib/ExpThread.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_ExternalDlg.o: ./MyRuLib/ExternalDlg.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_FbGenres.o: ./MyRuLib/FbGenres.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_FbManager.o: ./MyRuLib/FbManager.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_FbParams.o: ./MyRuLib/FbParams.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_ImpContext.o: ./MyRuLib/ImpContext.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_ImpThread.o: ./MyRuLib/ImpThread.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_InfoCash.o: ./MyRuLib/InfoCash.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_InfoThread.o: ./MyRuLib/InfoThread.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_MyRuLibApp.o: ./MyRuLib/MyRuLibApp.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_MyRuLibMain.o: ./MyRuLib/MyRuLibMain.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_ParseCtx.o: ./MyRuLib/ParseCtx.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_ProgressBar.o: ./MyRuLib/ProgressBar.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_SettingsDlg.o: ./MyRuLib/SettingsDlg.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_TitleThread.o: ./MyRuLib/TitleThread.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_ZipReader.o: ./MyRuLib/ZipReader.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_Archives.o: ./MyRuLib/db/Archives.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_Authors.o: ./MyRuLib/db/Authors.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_Books.o: ./MyRuLib/db/Books.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_Bookseq.o: ./MyRuLib/db/Bookseq.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_Params.o: ./MyRuLib/db/Params.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_Sequences.o: ./MyRuLib/db/Sequences.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_wxActiveRecord.o: ./MyRuLib/db/wxActiveRecord.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_ZipBooks.o: ./MyRuLib/db/ZipBooks.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_ZipFiles.o: ./MyRuLib/db/ZipFiles.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_sha1.o: ./MyRuLib/sha1/sha1.c
	$(CC) -c -o $@ $(MYRULIB_CFLAGS) $(CPPDEPS) $<

build/MyRuLib_base64.o: ./MyRuLib/wx/base64.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

build/MyRuLib_treelistctrl.o: ./MyRuLib/wx/treelistctrl.cpp
	$(CXX) -c -o $@ $(MYRULIB_CXXFLAGS) $(CPPDEPS) $<

.PHONY: all install uninstall clean


# Dependencies tracking:
-include build/*.d
