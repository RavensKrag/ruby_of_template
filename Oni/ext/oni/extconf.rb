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

deps = %w[boost  fmodex  FreeImage  freetype  glfw  kiss  openFrameworks  openFrameworksCompiled  poco  tess2  utf8cpp]
deps.each do |dependency_name|
	
	headers = File.join(OF_ROOT, "libs/#{dependency_name}/include")
	libs    = File.join(OF_ROOT, "libs/#{dependency_name}/lib")
	
	puts "headers: #{headers}"
	puts "libs:    #{libs}"
	
	dir_config(
		dependency_name, # name to use with 'have_library'
		headers, libs
	)
	
	have_library(dependency_name)
end


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
