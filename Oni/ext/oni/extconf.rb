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


# need to include C++ standard lib before looking for Boost
have_library("stdc++")


# oF stuff
dir_config(
	"OFSketch", # name to use with 'have_library'
	File.expand_path("./cpp/oF_Test/mySketch/src/"), # headers
	File.expand_path("./cpp/oF_Test/mySketch/lib/")  # libs
	
	# File.expand_path("./cpp/oF_Test/mySketch/obj/linux64/Release/src/")
)

# headers = []
# libs = "/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release/libs/openFrameworksCompiled/lib/linux64/"
# dir_config(
# 	"openFrameworks", # name to use with 'have_library'
# 	headers, # headers
# 	File.expand_path(libs)  # libs
# )



OF_ROOT = "/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release/"

deps = %w[fmodex  FreeImage  freetype]
deps.each do |dependency_name|
	
	headers = File.join(OF_ROOT, "libs/#{dependency_name}/include")
	libs    = File.join(OF_ROOT, "libs/#{dependency_name}/lib/linux64")
	
	# adding linux64 to the end allows for some dependencies to be found, such as tess2.
	# but the specific version of tess2 which is distributed with openframeworks is not compatable with shared libs
		# /usr/bin/ld: /home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release/libs/tess2/lib/linux64/libtess2.a(tess.o): relocation R_X86_64_32 against `.data' can not be used when making a shared object; recompile with -fPIC

	
	puts "headers: #{headers}"
	puts "libs:    #{libs}"
	
	dir_config(
		dependency_name, # name to use with 'have_library'
		headers, libs
	)
	
	have_library(dependency_name)
end


# --- glfw is slightly different than expected: package has a version number, but the path does not
dependency_name = "glfw"
glfw_version    = "3"

headers = File.join(OF_ROOT, "libs/#{dependency_name}/include")
libs    = File.join(OF_ROOT, "libs/#{dependency_name}/lib/linux64")

# adding linux64 to the end allows for some dependencies to be found, such as tess2.
# but the specific version of tess2 which is distributed with openframeworks is not compatable with shared libs
	# /usr/bin/ld: /home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release/libs/tess2/lib/linux64/libtess2.a(tess.o): relocation R_X86_64_32 against `.data' can not be used when making a shared object; recompile with -fPIC


puts "headers: #{headers}"
puts "libs:    #{libs}"

# oF-provided static library
dir_config(
	"glfw#{glfw_version}", # name to use with 'have_library'
	headers, libs
)

# Mesa must be linked before glfw3
# %w[X11 Xrandr Xi Xxf86vm gl].each do |lib|
%w[X11 Xrandr Xi Xxf86vm Xcursor Xinerama].each do |lib|
	# src: http://stackoverflow.com/questions/21685903/glfw3-undefined-reference-to-xrr
	# have_library(lib)
end
# have_library("Xxf86vm") # Mesa3D - system library, needed to resolve symbols in glfw3
# have_library("glfw3")   # oF version
	# Even with oF-provided version, system still segfaults.
	# But this segfault actually provides a decent stack trace
	
	# Same segfault regaurdless of which of the two library lists from that stackexchange thread I end up using.



# system library.
# have_library("glfw") # undefined symbol:  glfwSetErrorCallback (seems to be using glfw2)
have_library("glfw") # after installing libglfw3-dev, this works, but then the program segfaults

# ravenskrag@ravensnest:~/Experiments/RubyCPP/Oni$ dpkg --get-selections | grep libglfw
# libglfw-dev:amd64				install
# libglfw2:amd64					install





# from oF sketch standalone C++ execution:
# checking pkg-config libraries:   cairo zlib gstreamer-app-1.0 gstreamer-1.0 gstreamer-video-1.0 gstreamer-base-1.0 libudev freetype2 fontconfig sndfile openal openssl libpulse-simple alsa gl glu glew gtk+-3.0 libmpg123 

# puts "----"
# %w[
# 	cairo zlib gstreamer-app-1.0 gstreamer-1.0 gstreamer-video-1.0 gstreamer-base-1.0 libudev freetype2 fontconfig sndfile openal openssl libpulse-simple alsa gl glu glew gtk+-3.0 libmpg123
# ].each do |lib|
# 	have_library(lib)
# end
# puts "----"





# ---



# category_list = %w[Crypto Data DataSQLite Foundation JSON MongoDB Net NetSSL Util XML Zip]
category_list = %w[Util Net XML Crypto Data DataSQLite JSON MongoDB NetSSL Zip Foundation]
	# order changes linking order, which matters
	# src: http://stackoverflow.com/questions/15701796/poco-c-static-linking-problems-with-undefined-references-to-symbols
	# (that's for static linking tho)
category_list.each do |category|
	# find_library("Poco#{category}", 'main')
	
	
	# each sub-library need to be specified separately, otherwise extconf gets confused
	# extconf only wants to look for one .a file at a time, base on the name given in 'dir_config()'
	
	dependency_name = "Poco#{category}"
	
	category_dir = 
		if category.include? "Data"
			"Data"
		else
			category
		end
	
	poco_root = File.expand_path("../of_v0.9.3_libs/custom/poco/poco-1.7.4-all/", OF_ROOT)
	headers = File.expand_path("./#{category_dir}/include/Poco/#{category_dir}/", poco_root)
	libs    = File.expand_path("./lib/Linux/x86_64/", poco_root)
	
	# p libs
	dir_config(
			dependency_name, # name to use with 'have_library'
			headers, libs
		)
	
	have_library(dependency_name)
end

# TODO: may need to tell the linker where the dynamic libraries are going to be
# otherwise, you need to either put the dynamic libraries in the same directory as the executable
# or edit LD_LIBRARY_PATH, or similar.
# 
# set rpath option to tell the linker @ link time where things will be
# $LDFLAGS << " -Wl,-rpath,#{libs}"
# 
# src: http://stackoverflow.com/questions/9251554/c-ruby-extension-with-external-libraries





# === link up dependencies that were custom compiled with -fPIC

dir_config(
	"tess2", # name to use with 'have_library'
	File.expand_path("../of_v0.9.3_libs/custom/tess2/Include/", OF_ROOT),
	File.expand_path("../of_v0.9.3_libs/custom/tess2/Build/",   OF_ROOT)
)

have_library("tess2")


dir_config(
	"kiss", # name to use with 'have_library'
	File.expand_path("../of_v0.9.3_libs/custom/kiss/include/", OF_ROOT),
	File.expand_path("../of_v0.9.3_libs/custom/kiss/lib/",     OF_ROOT)
)

have_library("kiss")

# ========================




# --- resolving other symbols (this section comes before oF core)

# have_library("glew")
# have_library("glew32")
# have_library("glewmx")
have_library("GLEW")





# from /home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release/scripts/linux/ubuntu/install_dependencies.sh
	# PACKAGES="curl libjack-jackd2-0 libjack-jackd2-dev freeglut3-dev libasound2-dev libxmu-dev libxxf86vm-dev g++${CXX_VER} libgl1-mesa-dev${XTAG} libglu1-mesa-dev libraw1394-dev libudev-dev libdrm-dev libglew-dev libopenal-dev libsndfile-dev libfreeimage-dev libcairo2-dev libfreetype6-dev libssl-dev libpulse-dev libusb-1.0-0-dev libgtk${GTK_VERSION}-dev  libopencv-dev libassimp-dev librtaudio-dev libboost-filesystem${BOOST_VER}-dev libgstreamer${GSTREAMER_VERSION}-dev libgstreamer-plugins-base${GSTREAMER_VERSION}-dev  ${GSTREAMER_FFMPEG} gstreamer${GSTREAMER_VERSION}-pulseaudio gstreamer${GSTREAMER_VERSION}-x gstreamer${GSTREAMER_VERSION}-plugins-bad gstreamer${GSTREAMER_VERSION}-alsa gstreamer${GSTREAMER_VERSION}-plugins-base gstreamer${GSTREAMER_VERSION}-plugins-good"


# libgstreamer1.0-dev
gstreamer_version = "1.0"
have_library("gstreamer-#{gstreamer_version}")       # this works 
have_library("gstreamer-#{gstreamer_version}-libav") # this doesn't





# ---






utf8cpp_root = File.expand_path("./libs/utf8cpp/include/utf8", OF_ROOT) # boost provided by oF

dir_config(
	"utf8cpp", # name to use with 'have_library'
	utf8cpp_root, # headers
)
p Dir.glob("#{utf8cpp_root}/**/*")

have_library("utf8cpp_utf8")





# boost_root = "/usr/include/boost"                                    # system boost
boost_root = File.expand_path("./libs/boost/include/boost", OF_ROOT) # boost provided by oF

dir_config(
	"boost", # name to use with 'have_library'
	boost_root, # headers
)
p Dir.glob("#{boost_root}/system/**/*")

have_library("boost")
have_library("boost_filesystem")
have_library("boost_system")




# ravenskrag@ravensnest:~/Experiments/RubyCPP/Oni$ dpkg --get-selections | grep libboost

# libboost-date-time1.58.0:amd64			install
# libboost-filesystem-dev:amd64			install
# libboost-filesystem1.58-dev:amd64		install
# libboost-filesystem1.58.0:amd64			install
# libboost-filesystem1.58.0:i386			install
# libboost-iostreams1.58.0:amd64			install
# libboost-python1.58.0				install
# libboost-system1.58-dev:amd64			install
# libboost-system1.58.0:amd64			install
# libboost-system1.58.0:i386			install
# libboost1.58-dev:amd64				install


# boost_ver = "1.58.0"
# have_library("boost-system-#{boost_ver}")
# have_library("boost-filesystem-#{boost_ver}")



# Boost::System and Boost::Filesystem are header only libs
# src: http://stackoverflow.com/questions/7894451/require-boostdynamic-bitset-in-extconf-rb
# src: http://www.boost.org/doc/libs/1_57_0/more/getting_started/unix-variants.html#header-only-libraries


# but manually passing header paths to find_header() or have_header() fails for some of Boost, and I'm not sure why.



# checking for /usr/include/boost/system/windows_error.hpp... yes
# checking for /usr/include/boost/system/api_config.hpp... yes
# checking for /usr/include/boost/system/cygwin_error.hpp... yes
# checking for /usr/include/boost/system/config.hpp... yes
# checking for /usr/include/boost/system/detail/local_free_on_destruction.hpp... yes
# checking for /usr/include/boost/system/system_error.hpp... no
# checking for /usr/include/boost/system/linux_error.hpp... no
# checking for /usr/include/boost/system/error_code.hpp... no
# checking for /usr/include/boost/filesystem/path_traits.hpp... no
# checking for /usr/include/boost/filesystem/operations.hpp... no
# checking for /usr/include/boost/filesystem/fstream.hpp... no
# checking for /usr/include/boost/filesystem/config.hpp... yes
# checking for /usr/include/boost/filesystem/exception.hpp... yes
# checking for /usr/include/boost/filesystem/detail/utf8_codecvt_facet.hpp... no
# checking for /usr/include/boost/filesystem/convenience.hpp... no
# checking for /usr/include/boost/filesystem/path.hpp... no


# checking for OF_ROOT/libs/boost/include/boost/system/system_error.hpp... no
# checking for OF_ROOT/libs/boost/include/boost/system/config.hpp... yes
# checking for OF_ROOT/libs/boost/include/boost/system/detail/local_free_on_destruction.hpp... yes
# checking for OF_ROOT/libs/boost/include/boost/system/error_code.hpp... no
# checking for OF_ROOT/libs/boost/include/boost/system/api_config.hpp... yes
# checking for OF_ROOT/libs/boost/include/boost/filesystem/operations.hpp... no
# checking for OF_ROOT/libs/boost/include/boost/filesystem/config.hpp... yes
# checking for OF_ROOT/libs/boost/include/boost/filesystem/path.hpp... no
# checking for OF_ROOT/libs/boost/include/boost/filesystem/detail/utf8_codecvt_facet.hpp... no
# checking for OF_ROOT/libs/boost/include/boost/filesystem/path_traits.hpp... no
# checking for OF_ROOT/libs/boost/include/boost/filesystem/exception.hpp... yes
# checking for OF_ROOT/libs/boost/include/boost/filesystem/fstream.hpp... no
# checking for OF_ROOT/libs/boost/include/boost/filesystem/convenience.hpp... no







dependency_name = "openFrameworks"
headers = "#{OF_ROOT}/libs/openFrameworks/"
libs    = "#{OF_ROOT}/libs/openFrameworksCompiled/lib/linux64"

dir_config(
	dependency_name, # name to use with 'have_library'
	headers, libs
)

have_library(dependency_name)
# have_func(name, header_name)













# C++ stuff
# dir_config(
# 	"OFSketch",
# 	File.expand_path("./cpp/oF_Test/mySketch/lib/"), 
# 	File.expand_path("./cpp/oF_Test/mySketch/lib/")
# )



# have_library('openFrameworks')
have_library('OFSketch')

create_makefile('oni/oni')
