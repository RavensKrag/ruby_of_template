# Attempt to load a config.make file.
# If none is found, project defaults in config.project.make will be used.
ifneq ($(wildcard config.make),)
	include config.make
endif

# make sure the the OF_ROOT location is defined
ifndef OF_ROOT
    OF_ROOT=$(realpath ../../OpenFrameworks/of_v0.9.3_linux64_release)
endif

# call the project makefile!
include $(OF_ROOT)/libs/openFrameworksCompiled/project/makefileCommon/compile.project.mk





# ============================
# === custom make commands ===
# ============================

TARGET_NAME = Release
# need to set TARGET_NAME before loading the config,
# because the config assumes this var is defined already
# (not sure why this variable ends up blank by this time, but w/e)
include $(OF_ROOT)/libs/openFrameworksCompiled/project/makefileCommon/config.project.mk


# run this task to make sure the variables work
variable_test:
	@echo "=================="
	@echo "project objs"
	@echo $(OF_PROJECT_OBJS)
	@echo "ad-on objs"
	@echo $(OF_PROJECT_ADDONS_OBJS)
	@echo "core libs"
	@echo $(OF_CORE_LIBS)
	@echo "platform"
	@echo $(PLATFORM_LIB_SUBPATH)
	@echo "target name"
	@echo $(TARGET_NAME)
	@echo "ad-ons path"
	@echo $(OF_ADDONS_PATH)
	@echo "ad-on libs"
	@echo $(PROJECT_ADDONS_LIBS) # it might be ok if this is blank
	
	@echo "OF_PROJECT_OBJ_OUTPUT_PATH"
	@echo $(OF_PROJECT_OBJ_OUTPUT_PATH)
	@echo "=================="

# create static library
static_lib: lib/libOFSketch.a
	
lib/libOFSketch.a:
	@mkdir -p lib
	ar rcs $@ $(OF_PROJECT_OBJS) $(OF_PROJECT_ADDONS_OBJS)

clean_static_lib:
	@rm -f lib/libOFSketch.a




# this doesn't seem to work. might have to do this in a rakefile, because that's something I actually understand, lol.
# these variables are coming up empty, and I'm not sure why.



# I think it's because 'include' is not a preprocessor directive-type thing
# it actually just jumps over to a separate file, and runs that.
# src: https://www.gnu.org/software/make/manual/html_node/Include.html
# "When make processes an include directive, it suspends reading of the containing makefile and reads from each listed file in turn. When that is finished, make resumes reading the makefile in which the directive appears."


# instructions on how to show the symbols in a .a for C++ library
# http://stackoverflow.com/questions/3757108/contents-of-a-static-library





# ar: obj/linux64//src/launcher.o: No such file or directory
# getting paths that look like that, which means that something is missing...
# (this is TARGET_NAME)

# more broken paths...
# ar: /home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64//ofxAssimpModelLoader/src/ofxAssimpMeshHelper.o: No such file or directory
# (set TARGET_NAME before the other import)






# NOTE: this generates a proper-looking .a now, but if you turn the TARGET_NAME and include lines on, then the main project will not build, and you will not get the .o objects you need to build the .a
# that's a fail....
# either need to move this step to some other file, 




# oh wait no, just put the variable set / config import
# under the section for the static lib, and then it works just fine.

# ???

# I thought that's what I saw?
# oh well...



# NOTE: the symlink directory hack setup is currently dropping the .o files that are specific to this project, OF_PROJECT_OBJS

# WARNING: 'core libs' includes linker flags, as well as .a files. that might not be what you want.



# ============================
