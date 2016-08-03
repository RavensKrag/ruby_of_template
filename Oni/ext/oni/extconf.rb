require 'mkmf-rice'
require 'fileutils'
require 'open3'

# interactive command-line program execution
def run_i(cmd_string)
	stdin, stdout_and_stderr, wait_thr = Open3.popen2e cmd_string
	
	output = nil
	begin
		output = stdout_and_stderr.gets
		puts output
	end while output
	
	stdin.close
	stdout_and_stderr.close
end

PATH_TO_FILE = File.absolute_path(File.dirname(__FILE__))

OF_ROOT = "/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release/"
REPO_ROOT = File.expand_path('../../', PATH_TO_FILE)



# need to include C++ standard lib before looking for C++ libraries.
# might as well just include this first
have_library("stdc++")

$CPPFLAGS
# => "-I/home/ravenskrag/Experiments/RubyCPP/Oni/ext/oni/cpp/oF_Test/mySketch/src -I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/openFrameworks/  $(DEFS) $(cppflags)  -I/home/ravenskrag/.rvm/gems/ruby-2.1.1/gems/rice-2.1.0/ruby/lib/include"
$LDFLAGS
# => "-L. -fstack-protector -rdynamic -Wl,-export-dynamic  -L/home/ravenskrag/.rvm/gems/ruby-2.1.1/gems/rice-2.1.0/ruby/lib/lib -lrice"






# $(OPTIMIZATION_CFLAGS) $(CFLAGS) $(CXXFLAGS) $(OF_CORE_INCLUDES_CFLAGS)

	# "-O3 -DNDEBUG -march=native -mtune=native -Wall -std=c++14 -DGCC_HAS_REGEX -DOF_USING_GTK -DOF_USING_GTK -DOF_USING_MPG123 -fPIC  -D_REENTRANT -pthread"

$LIBS
   # => "-lpthread -ldl -lcrypt -lm   -lc"
$LIBRUBYARG
   # => "-Wl,-R -Wl,/home/ravenskrag/.rvm/rubies/ruby-2.1.1/lib -L/home/ravenskrag/.rvm/rubies/ruby-2.1.1/lib -lruby"
$LIBRUBYARG_STATIC
   # => "-Wl,-R -Wl,/home/ravenskrag/.rvm/rubies/ruby-2.1.1/lib -L/home/ravenskrag/.rvm/rubies/ruby-2.1.1/lib -lruby-static"
$CXXFLAGS
   # => " -Wall -g"
$LDSHARED_CXX
   # => "g++ -shared"

optimization_flags = "-O3 -DNDEBUG -march=native -mtune=native"
cxx_flags = "-std=c++14 -DGCC_HAS_REGEX -DOF_USING_GTK -DOF_USING_GTK -DOF_USING_MPG123"
other_compile_flags = "-D_REENTRANT -pthread" # not sure where these come from

$CXXFLAGS += " " + [
		optimization_flags,
		cxx_flags,
		other_compile_flags
	].join(' ')




c_flags = "
	-I/usr/include/gstreamer-1.0
	-I/usr/lib/x86_64-linux-gnu/gstreamer-1.0/include
	-I/usr/include/AL
	-I/usr/include/alsa
	-I/usr/include/libdrm
	-I/usr/include/gtk-3.0
	-I/usr/include/at-spi2-atk/2.0
	-I/usr/include/at-spi-2.0
	-I/usr/include/dbus-1.0
	-I/usr/lib/x86_64-linux-gnu/dbus-1.0/include
	-I/usr/include/gtk-3.0
	-I/usr/include/gio-unix-2.0/
	-I/usr/include/mirclient
	-I/usr/include/mircommon
	-I/usr/include/mircookie
	-I/usr/include/cairo
	-I/usr/include/pango-1.0
	-I/usr/include/harfbuzz
	-I/usr/include/pango-1.0
	-I/usr/include/atk-1.0
	-I/usr/include/cairo
	-I/usr/include/pixman-1
	-I/usr/include/freetype2
	-I/usr/include/libpng12
	-I/usr/include/gdk-pixbuf-2.0
	-I/usr/include/libpng12
	-I/usr/include/glib-2.0
	-I/usr/lib/x86_64-linux-gnu/glib-2.0/include
	-I/usr/include/assimp
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/fmodex/include
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/glfw/include
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/glfw/include/GLFW
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/kiss/include
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/poco/include
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/tess2/include
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/utf8cpp/include
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/utf8cpp/include/utf8
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/openFrameworks
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/openFrameworks/math
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/openFrameworks/sound
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/openFrameworks/video
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/openFrameworks/communication
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/openFrameworks/app
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/openFrameworks/utils
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/openFrameworks/events
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/openFrameworks/3d
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/openFrameworks/types
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/openFrameworks/graphics
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/openFrameworks/gl -D_REENTRANT -pthread
"

addon_c_flags = "
	-I/usr/include/gstreamer-1.0
	-I/usr/lib/x86_64-linux-gnu/gstreamer-1.0/include
	-I/usr/include/AL
	-I/usr/include/alsa
	-I/usr/include/libdrm
	-I/usr/include/gtk-3.0
	-I/usr/include/at-spi2-atk/2.0
	-I/usr/include/at-spi-2.0
	-I/usr/include/dbus-1.0
	-I/usr/lib/x86_64-linux-gnu/dbus-1.0/include
	-I/usr/include/gtk-3.0
	-I/usr/include/gio-unix-2.0/
	-I/usr/include/mirclient
	-I/usr/include/mircommon
	-I/usr/include/mircookie
	-I/usr/include/cairo
	-I/usr/include/pango-1.0
	-I/usr/include/harfbuzz
	-I/usr/include/pango-1.0
	-I/usr/include/atk-1.0
	-I/usr/include/cairo
	-I/usr/include/pixman-1
	-I/usr/include/freetype2
	-I/usr/include/libpng12
	-I/usr/include/gdk-pixbuf-2.0
	-I/usr/include/libpng12
	-I/usr/include/glib-2.0
	-I/usr/lib/x86_64-linux-gnu/glib-2.0/include
	-I/usr/include/assimp
"


other = "
	-I/home/ravenskrag/Experiments/RubyCPP/Oni/ext/oni/cpp/oF_Test/mySketch/notes
	-I/home/ravenskrag/Experiments/RubyCPP/Oni/ext/oni/cpp/oF_Test/mySketch/lib
	-I/home/ravenskrag/Experiments/RubyCPP/Oni/ext/oni/cpp/oF_Test/mySketch/src

	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release/addons/ofxAssimpModelLoader/src
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release/addons/ofxAssimpModelLoader/libs
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release/addons/ofxAssimpModelLoader/libs/assimp
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release/addons/ofxGui/src
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release/addons/ofxNetwork/src
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release/addons/ofxOsc/src
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release/addons/ofxOsc/libs
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release/addons/ofxOsc/libs/oscpack
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release/addons/ofxOsc/libs/oscpack/src
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release/addons/ofxOsc/libs/oscpack/src/ip
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release/addons/ofxOsc/libs/oscpack/src/ip/posix
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release/addons/ofxOsc/libs/oscpack/src/ip/win32
	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release/addons/ofxOsc/libs/oscpack/src/osc
"


more_flags = 
	[c_flags, addon_c_flags, other]
		.collect{  |string_blob|  string_blob.split.join(' ') }
		.join('   ')

$CPPFLAGS += " " + more_flags







of_project_objs = %w[
	obj/linux64/Release/src/launcher.o
	obj/linux64/Release/src/main.o
	obj/linux64/Release/src/ofApp.o
].collect{ |line|
	"/home/ravenskrag/Experiments/RubyCPP/Oni/ext/oni/cpp/oF_Test/mySketch/#{line}"
}.join(' ')

of_project_addon_objs = "
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxAssimpModelLoader/src/ofxAssimpMeshHelper.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxAssimpModelLoader/src/ofxAssimpModelLoader.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxAssimpModelLoader/src/ofxAssimpAnimation.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxAssimpModelLoader/src/ofxAssimpTexture.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxGui/src/ofxToggle.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxGui/src/ofxSliderGroup.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxGui/src/ofxLabel.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxGui/src/ofxSlider.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxGui/src/ofxGuiGroup.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxGui/src/ofxButton.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxGui/src/ofxPanel.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxGui/src/ofxBaseGui.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxNetwork/src/ofxTCPServer.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxNetwork/src/ofxTCPClient.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxNetwork/src/ofxUDPManager.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxNetwork/src/ofxTCPManager.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxOsc/src/ofxOscMessage.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxOsc/src/ofxOscParameterSync.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxOsc/src/ofxOscBundle.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxOsc/src/ofxOscSender.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxOsc/src/ofxOscReceiver.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxOsc/libs/oscpack/src/ip/posix/NetworkingUtils.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxOsc/libs/oscpack/src/ip/posix/UdpSocket.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxOsc/libs/oscpack/src/ip/IpEndpointName.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxOsc/libs/oscpack/src/osc/OscTypes.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxOsc/libs/oscpack/src/osc/OscPrintReceivedElements.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxOsc/libs/oscpack/src/osc/OscReceivedElements.o
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//addons/obj/linux64/Release/ofxOsc/libs/oscpack/src/osc/OscOutboundPacketStream.o
"

of_project_libs = "
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/openFrameworksCompiled/lib/linux64/libopenFrameworks.a
"

ld_flags = "
	-Wl,-rpath=./libs:./bin/libs -Wl,--as-needed -Wl,--gc-sections

	-L/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/fmodex/lib/linux64/

	-lfmodex
"

of_core_libs = "
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/glfw/lib/linux64/libglfw3.a
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/kiss/lib/linux64/libkiss.a
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/tess2/lib/linux64/libtess2.a
	 /home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/poco/lib/linux64/libPocoNetSSL.a
	 /home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/poco/lib/linux64/libPocoNet.a
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/poco/lib/linux64/libPocoCrypto.a
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/poco/lib/linux64/libPocoUtil.a
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/poco/lib/linux64/libPocoJSON.a
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/poco/lib/linux64/libPocoXML.a
	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/poco/lib/linux64/libPocoFoundation.a

	-lz -lgstapp-1.0 -lgstvideo-1.0 -lgstbase-1.0 -lgstreamer-1.0 -ludev -lfontconfig -lfreetype -lsndfile -lopenal -lssl -lcrypto -lpulse-simple -lpulse -lasound -lGLEW -lGLU -lGL -lgtk-3 -lgdk-3 -lpangocairo-1.0 -lpango-1.0 -latk-1.0 -lcairo-gobject -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0 -lmpg123 -lassimp -lglut -lX11 -lXrandr -lXxf86vm -lXi -lXcursor -ldl -lpthread -lfreeimage -lrtaudio -lboost_filesystem -lboost_system
"





# optimization_ld_flags
of_project_objs
of_project_addon_objs
# target_libs
of_project_libs
ld_flags
of_core_libs


more_linker_flags = 
	[
		of_project_objs,
		of_project_addon_objs,
		of_project_libs,
		ld_flags,
		of_core_libs,
	]
	.collect{  |string_blob|  string_blob.split.join(' ') }
	.join('   ')

$LDFLAGS += " " + more_linker_flags















p global_variables
# => [:$;, :$-F, :$@, :$!, :$SAFE, :$~, :$&, :$`, :$', :$+, :$=, :$KCODE, :$-K, :$,, :$/, :$-0, :$\, :$_, :$stdin, :$stdout, :$stderr, :$>, :$<, :$., :$FILENAME, :$-i, :$*, :$?, :$$, :$:, :$-I, :$LOAD_PATH, :$", :$LOADED_FEATURES, :$VERBOSE, :$-v, :$-w, :$-W, :$DEBUG, :$-d, :$0, :$PROGRAM_NAME, :$CXX, :$LIBS, :$LIBRUBYARG, :$LIBRUBYARG_STATIC, :$RICE_CPPFLAGS, :$RICE_LDFLAGS, :$RICE_PREFIX, :$RICE_USING_MINGW32, :$DEFLIBPATH, :$CPPFLAGS, :$LDFLAGS, :$CXXFLAGS, :$LDSHARED_CXX, :$OBJEXT, :$DLDFLAGS, :$LIBPATH, :$static, :$config_h, :$default_static, :$configure_args, :$libdir, :$rubylibdir, :$archdir, :$-p, :$-l, :$-a, :$sitedir, :$sitelibdir, :$sitearchdir, :$vendordir, :$vendorlibdir, :$vendorarchdir, :$mswin, :$bccwin, :$mingw, :$cygwin, :$netbsd, :$os2, :$beos, :$haiku, :$solaris, :$universal, :$dest_prefix_pattern, :$extout, :$extout_prefix, :$extmk, :$hdrdir, :$topdir, :$top_srcdir, :$arch_hdrdir, :$have_devel, :$INCFLAGS, :$CFLAGS, :$ARCH_FLAG, :$LOCAL_LIBS, :$libs, :$srcdir, :$EXEEXT, :$NONINSTALLFILES, :$defs, :$typeof, :$arg_config, :$extconf_h, :$PKGCONFIG, :$VPATH, :$LIBRUBYARG_SHARED, :$warnflags, :$ruby, :$preload, :$nmake, :$cleanfiles, :$distcleanfiles, :$target, :$LIBEXT, :$objs, :$srcs, :$INSTALLFILES, :$distcleandirs, :$installed_list, :$ignore_error, :$makefile_created, :$enable_shared, :$make, :$curdir, :$fileutils_rb_have_lchmod, :$fileutils_rb_have_lchown, :$1, :$2, :$3, :$4, :$5, :$6, :$7, :$8, :$9]

compiler_variables = 
[
	['$CXX', $CXX],
	['$LIBS', $LIBS],
	['$LIBRUBYARG', $LIBRUBYARG],
	['$LIBRUBYARG_STATIC', $LIBRUBYARG_STATIC],
	['$RICE_CPPFLAGS', $RICE_CPPFLAGS],
	['$RICE_LDFLAGS', $RICE_LDFLAGS],
	['$RICE_PREFIX', $RICE_PREFIX],
	['$RICE_USING_MINGW32', $RICE_USING_MINGW32],
	['$DEFLIBPATH', $DEFLIBPATH],
	['$CPPFLAGS', $CPPFLAGS],
	['$LDFLAGS', $LDFLAGS],
	['$CXXFLAGS', $CXXFLAGS],
	['$LDSHARED_CXX', $LDSHARED_CXX],
	['$OBJEXT', $OBJEXT],
	['$DLDFLAGS', $DLDFLAGS],
	['$LIBPATH', $LIBPATH],
	['$static', $static],
	['$config_h', $config_h],
	['$default_static', $default_static],
	['$configure_args', $configure_args],
	['$libdir', $libdir],
	['$rubylibdir', $rubylibdir],
	['$archdir', $archdir],
	['$defs', $defs],
].to_h

compiler_variables.each do |name, var|
	puts name
	puts "   #{var.inspect}"
end



create_makefile('oni/oni')
