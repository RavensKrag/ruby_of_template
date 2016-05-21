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



Dir.chdir "./cpp/oF_Test/" do
	run_i "rake build"
end

# oF stuff
dir_config(
	"OFSketch", # name to use with 'have_library'
	File.expand_path("./cpp/oF_Test/mySketch/src/"), # headers
	File.expand_path("./cpp/oF_Test/mySketch/lib/")  # libs
)

headers = []
libs = "/home/ravenskrag/Experiments/OpenFrameworks/of_v0.9.3_linux64_release/libs/openFrameworksCompiled/lib/linux64/"
dir_config(
	"openFrameworks", # name to use with 'have_library'
	headers, # headers
	File.expand_path(libs)  # libs
)




# C++ stuff
# dir_config(
# 	"OFSketch",
# 	File.expand_path("./cpp/oF_Test/mySketch/lib/"), 
# 	File.expand_path("./cpp/oF_Test/mySketch/lib/")
# )


have_library("stdc++")
have_library('OFSketch')
have_library('openFrameworks')

create_makefile('oni/oni')
