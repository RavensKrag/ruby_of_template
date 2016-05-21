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

# C++ stuff
# dir_config(
# 	"OFSketch",
# 	File.expand_path("./cpp/oF_Test/mySketch/lib/"), 
# 	File.expand_path("./cpp/oF_Test/mySketch/lib/")
# )



have_library('OFSketch')

create_makefile('oni/oni')
