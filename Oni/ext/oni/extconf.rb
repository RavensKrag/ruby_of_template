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

deps = %w[boost  fmodex  FreeImage  freetype  glfw  utf8cpp]
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



dependency_name = "openFrameworks"
headers = "#{OF_ROOT}/libs/openFrameworks/"
libs    = "#{OF_ROOT}/libs/openFrameworksCompiled/lib/linux64"

dir_config(
	dependency_name, # name to use with 'have_library'
	headers, libs
)

have_library(dependency_name)
# have_func(name, header_name)





# dir_config(
# 	"boost", # name to use with 'have_library'
# 	Dir.glob(File.join(OF_ROOT, "libs/#{"boost"}/include/**/*.h")), # headers
# 	Dir.glob(File.join(OF_ROOT, "libs/#{"boost"}/lib/**/*{.a,.o}")) # libs
# )






# C++ stuff
# dir_config(
# 	"OFSketch",
# 	File.expand_path("./cpp/oF_Test/mySketch/lib/"), 
# 	File.expand_path("./cpp/oF_Test/mySketch/lib/")
# )


have_library("stdc++")
# have_library('openFrameworks')
have_library('OFSketch')

create_makefile('oni/oni')
