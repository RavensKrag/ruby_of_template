require 'mkmf-rice'
require 'fileutils'
require 'open3'

# NOTE: loads the instructions from extconf.rb, but runs Rake to build oF libraries

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

puts File.expand_path("./../..")
Dir.chdir "./../.." do
	run_i "rake build_core"
end


PATH_TO_FILE = File.absolute_path(File.dirname(__FILE__))
require File.expand_path('./extconf.rb', PATH_TO_FILE)
