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


# need to include C++ standard lib before looking for Boost
have_library("stdc++")


























dependency_name = "openFrameworks"
headers = "#{OF_ROOT}/libs/openFrameworks/"
libs    = "#{OF_ROOT}/libs/openFrameworksCompiled/lib/linux64"

dir_config(
	dependency_name, # name to use with 'have_library'
	headers, libs
)

have_library(dependency_name)
# have_func(name, header_name)



dependency_name = "OFSketch"
headers = File.expand_path("ext/oni/cpp/oF_Test/mySketch/src/", REPO_ROOT)
libs    = File.expand_path("ext/oni/cpp/oF_Test/mySketch/lib/", REPO_ROOT)

dir_config(
	dependency_name, # name to use with 'have_library'
	headers, libs
)

# /home/ravenskrag/Experiments/RubyCPP/Oni/ext/oni/cpp/oF_Test/mySketch/lib/

have_library(dependency_name)





create_makefile('oni/oni')
