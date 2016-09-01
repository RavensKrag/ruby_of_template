require 'mkmf-rice'
require 'fileutils'
require 'open3'

require 'yaml'

path_to_file = File.absolute_path(File.dirname(__FILE__))
gem_root = File.expand_path('../../', path_to_file)

require File.expand_path('./build_libs/common', gem_root)
# ^ this file declares GEM_ROOT constant, other constants, and a some functions




# C deps must be listed before the C++ core is loaded, and C++ deps must be listed after



# === C libraries (mostly oF dependencies)


# --- glfw is slightly different than expected: package has a version number, but the path does not
dependency_name = "glfw"
glfw_version    = "3"

headers = File.expand_path("../of_v0.9.3_libs/custom/#{dependency_name}/include/#{dependency_name.upcase}", OF_ROOT)
libs    = File.expand_path("../of_v0.9.3_libs/custom/#{dependency_name}/lib/linux64", OF_ROOT)

# adding linux64 to the end allows for some dependencies to be found, such as tess2.
# but the specific version of tess2 which is distributed with openframeworks is not compatable with shared libs
	# /usr/bin/ld: /home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release/libs/tess2/lib/linux64/libtess2.a(tess.o): relocation R_X86_64_32 against `.data' can not be used when making a shared object; recompile with -fPIC


# puts "headers: #{headers}"
# puts "libs:    #{libs}"

# oF-provided static library (custom version compiled with -fPIC)
dir_config(
	"glfw3", # name to use with 'have_library'
	headers, libs
)

have_library("glfw3")   # oF version

# NOTE: may fail to build correctly is glfw3 from the ubuntu repo is installed? not clear
# TODO: try building against GLFW3 in ubuntu repo




# all_poco_categories = %w[Foundation XML JSON Util Net Crypto NetSSL_OpenSSL Data Data/SQLite Data/ODBC Data/MySQL MongoDB Zip PageCompiler PageCompiler/File2Page]
	# src: /home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_libs/custom/poco/poco-1.7.4-all/Makefile

category_list = %w[Foundation XML JSON Util Net Crypto NetSSL Data DataSQLite MongoDB Zip]
	# order changes linking order, which matters
	# src: http://stackoverflow.com/questions/15701796/poco-c-static-linking-problems-with-undefined-references-to-symbols
	# (that's for static linking tho)
	
	# "There are no OpenSSL related linker errors. The linker is single pass, so it does not revisit past libraries. That means -lPocoUtil must follow -lPocoNetSSL because PocoNetSSL uses symbols from PocoUtil."
	# src: http://stackoverflow.com/questions/38822925/errors-while-statically-compiling-poco-with-ssl-in-gcc
	
category_list.each do |category|
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
	
	headers = File.expand_path("./#{category_dir}/include/", poco_root)
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
dependency_name = "tess2" # Name to use with 'have_library'. Also the name of the lib file

dir_config(
	dependency_name, 
	File.expand_path("../of_v0.9.3_libs/custom/tess2/Include/", OF_ROOT),
	File.expand_path("../of_v0.9.3_libs/custom/tess2/Build/",   OF_ROOT)
)

have_library(dependency_name)





dependency_name = "kissfft"

headers = [
	File.expand_path("../of_v0.9.3_libs/custom/kiss/", OF_ROOT),
	File.expand_path("../of_v0.9.3_libs/custom/kiss/tools/", OF_ROOT),
]
libs    = File.expand_path("../of_v0.9.3_libs/custom/kiss/",     OF_ROOT)

dir_config(
	dependency_name,
	headers, libs
)

have_library(dependency_name)

# 	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_libs/custom/kiss/
# 	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_libs/custom/kiss/tools/

# /home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_libs/custom/kiss/libkissfft.a

# ========================






# === C++ libraries, and various flags
have_library("stdc++")







dependency_name = "fmodex"

headers = File.expand_path("./libs/fmodex/include",      OF_ROOT)
libs    = File.expand_path("./libs/fmodex/lib/linux64/", OF_ROOT)

dir_config(
	dependency_name,
	headers, libs
)

have_library(dependency_name)


# 	-I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/fmodex/include


# -L/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/fmodex/lib/linux64/
# -lfmodex






dependency_name = "utf8cpp"

headers = [
	File.expand_path("./libs/utf8cpp/include", OF_ROOT),
	File.expand_path("./libs/utf8cpp/include/utf8", OF_ROOT),
]
libs = "" # this is a header-only library

dir_config(
	dependency_name,
	headers, libs
)

puts "adding #{dependency_name} to include path..."

# have_header(File.expand_path("./libs/utf8cpp/include/utf8.h", OF_ROOT))
# this line fails, but the directory configuration is actually working fine
# would be nice to get this to work too...

have_header('utf8.h')
have_header('utf8/core.h')



# -I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/utf8cpp/include
# -I/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/utf8cpp/include/utf8















# === Set extra flags based on data from oF build system

filepath = File.expand_path("./oF_build_variables.yaml", GEM_ROOT)
of_build_variables = YAML.load_file(filepath)
# p of_build_variables

# TODO: centralize setting of build variables. Some duplication between extconf.rb and rakefile.




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





# NOTE: there is also OPTIMIZATION_CFLAGS and OPTIMIZATION_LDFLAGS, but those are not used here
optimization_flags = of_build_variables['PLATFORM_OPTIMIZATION_CFLAGS_RELEASE'].join(' ')
cxx_flags          = of_build_variables['CFLAGS']
                     	.reject{ |flag|
                     		["-fPIC", "-Wall"].include? flag
                 		}
                     	.join(' ')

$CXXFLAGS += " " + [
		optimization_flags,
		cxx_flags,
	].join(' ')





c_flags = 
	of_build_variables['PROJECT_INCLUDE_CFLAGS'] # includes files for core, addons, everything
	.reject{ |flag|
		# reject these libraries, because they have already been specified in extconf.rb above
		%w[
			fmodex
			glfw
			kiss
			poco
			tess2
			utf8cpp
		].any?{ |keyword|
			flag.include? keyword
		}
	}
	.reject{ |flag|
		# bunch of local paths in here, not sure if they are relevant at the Ruby level?
		# gonna get rid of them for now
		%w[-I./ -I/. -I.].any?{ |fragment|
			flag.include? fragment
		}
	}
	.join(' ')
# p c_flags


$CPPFLAGS += " " + c_flags









of_build_variables['OF_PROJECT_ADDONS_OBJS']



of_build_variables['OF_PROJECT_OBJS']

of_build_variables['OBJS_WITHOUT_EXTERNAL']
of_build_variables['OBJS_WITH_PREFIX']

# these last two are the same thing.
# they seem to intend to give full paths for the files specified in OF_PROJECT_OBJS
# but there is some sort of bug.
# 
# ex) 
# 	obj/linux64/Release/src/main.o
# 	obj/linux64/Release//home/ravenskrag/Experiments/RubyCPP/Oni/ext/oni/cpp/oF_Test/mySketch/src/main.o
# 
# notice how the second line puts the root of the path at an odd position...
# (luckly I already had code to expand these local paths)




of_project_objs = 
	of_build_variables['OF_PROJECT_OBJS']
	.collect{ |line|
		File.expand_path("./ext/oni/cpp/oF_Test/mySketch/#{line}", GEM_ROOT)
	}.join(' ')


of_project_addon_objs = of_build_variables['OF_PROJECT_ADDONS_OBJS'].join(' ')













# libopenFrameworks.a
of_project_libs = of_build_variables['TARGET_LIBS'].join(' ')



# basic linker flags
ld_flags = 
	of_build_variables['ALL_LDFLAGS']
	.reject{ |flag|
		flag.include? "fmodex" # already specified in extconf.rb
	}
	.reject{ |flag|
		flag.include? '-rpath'
	}
ld_flags.unshift "-Wl,-rpath=./libs:./bin/libs:#{DYNAMIC_LIB_PATH}" # add to front
ld_flags = ld_flags.join(' ')

# NOTE: may need to modify -rpath in the future
# NOTE: specify directories for dynamic libraries relative to the root directory of this project, and then expand them into full paths before adding to -rpath. This means the gem will be able to find the dynamic libraries regaurdless of where the Ruby code is being called from.


# more linker flags
of_core_libs_dynamic_flags = 
	of_build_variables['OF_CORE_LIBS']
	.reject{ |flag|
		# remove the core dependencies, because extconf.rb specifies special versions.
		flag.include? "/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs"
	}
	.join(' ')





# optimization_ld_flags
of_project_objs
of_project_addon_objs
# target_libs
of_project_libs
ld_flags
# of_core_libs # spltting this up into dynamic lib flags and .a files
# of_core_libs_dot_a = "
# 	/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release//libs/kiss/lib/linux64/libkiss.a
# "
of_core_libs_dynamic_flags

more_linker_flags = 
	[
		of_project_objs,
		of_project_addon_objs,
		of_project_libs,
		ld_flags,
		# of_core_libs, # split into the following two categories:
		# of_core_libs_dot_a,
		of_core_libs_dynamic_flags, # these flags are very important
	]
	.collect{  |string_blob|  string_blob.split.join(' ') }
	.join('   ')

$LDFLAGS += " " + more_linker_flags







# === Copy over dynamic libraries to the correct location

# -rpath flag specifies where to look for dynamic libraries
# (the system also has some paths that it checks for, but these are the "local dlls", basically)

# NOTE: DYNAMIC_LIB_PATH has been passed to -rpath

src = File.expand_path("./libs/fmodex/lib/linux64/libfmodex.so", OF_ROOT)
dest = DYNAMIC_LIB_PATH
FileUtils.copy(src, dest)

# TODO: make sure that the 'bin/libs' directory exists before copying. (Maybe fileutils will handle automatically? maybe not)













File.open("./extconf_variables.rb", "w") do |f|
	# p global_variables
	f.puts global_variables.inspect
	
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
		f.puts name
		f.puts "   #{var.inspect}"
	end
end



create_makefile('oni/oni', 'cpp/lib')
